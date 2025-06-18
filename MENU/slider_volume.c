/**
 * @file slider_volume.c
 * @brief Contém toda a funcionalidade do componente de slider de volume.
 *
 * Este arquivo encapsula a lógica para detectar o clique e o arrastar do mouse no slider,
 * e também a lógica para desenhar todas as partes do slider (fundo, preenchimento e puxador)
 * usando os sprites customizados do jogo.
 */

#include "slider_volume.h"
#include "raymath.h" // Para a função Clamp()
#include "defines.h" // Para as constantes de escala

/**
 * @brief Atualiza o estado do slider de volume baseado na interação do mouse.
 *
 * Esta função é o "cérebro" do slider. Ela tem uma pequena máquina de estados:
 * 1. Se o jogador NÃO está arrastando, ela verifica se um clique do mouse acontece
 * sobre a área do slider para INICIAR o estado de "arrastando".
 * 2. Se o jogador JÁ está arrastando, ela atualiza o volume com base na posição X do mouse
 * e verifica se o botão do mouse foi SOLTO para PARAR o estado de "arrastando".
 * Ao final, ela sempre atualiza o volume da música para dar feedback em tempo real.
 *
 * @param jogo Ponteiro para o estado geral do jogo, onde o volume e o estado de "arrastando" são guardados.
 * @param mousePos A posição virtual do mouse na tela.
 * @param sliderArea O retângulo que define a área total e a hitbox do slider.
 * @param music A música que terá seu volume alterado.
 */
void UpdateVolumeSlider(EstadoJogo *jogo, Vector2 mousePos, Rectangle sliderArea, Music music) {

    // Lógica principal do slider
    if (jogo->arrastandoSliderVolume) {
        // Se já estamos arrastando, checa se o jogador soltou o botão do mouse
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) { // Checa o ato de SOLTAR
            jogo->arrastandoSliderVolume = false;
        }

        // Enquanto estiver arrastando, atualiza o volume
        float mouseRelativoX = mousePos.x - sliderArea.x;
        jogo->volumeAtual = mouseRelativoX / sliderArea.width;
        jogo->volumeAtual = Clamp(jogo->volumeAtual, 0.0f, 1.0f); // Garante que o volume fique entre 0 e 1

    } else if (CheckCollisionPointRec(mousePos, sliderArea)) {
        // Se não estamos arrastando, mas o mouse está sobre a área,
        // checa se o jogador pressionou o botão para COMEÇAR a arrastar
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->arrastandoSliderVolume = true;
            // Também atualiza o volume imediatamente na posição do clique inicial
            float mouseRelativoX = mousePos.x - sliderArea.x;
            jogo->volumeAtual = mouseRelativoX / sliderArea.width;
            jogo->volumeAtual = Clamp(jogo->volumeAtual, 0.0f, 1.0f);
        }
    }

    // Aplica o valor do volume à música a cada frame para feedback instantâneo
    SetMusicVolume(music, jogo->volumeAtual);
}


/**
 * @brief Desenha o slider de volume na tela usando os sprites customizados.
 *
 * A função desenha o slider em camadas, como um pintor:
 * 1. Desenha a barra de fundo usando a técnica 3-slice para poder ter qualquer comprimento.
 * 2. Desenha a barra de preenchimento por cima, usando uma técnica de "recorte" de sprite
 * para mostrar apenas a porcentagem correspondente ao volume atual.
 * 3. Desenha o puxador (a bolinha) por último, na posição exata do final do preenchimento.
 *
 * @param jogo Ponteiro (const) para o estado do jogo, usado para ler o volume atual e pegar as texturas.
 * @param sliderPos A posição base (canto superior esquerdo) onde o slider deve ser desenhado.
 */
void DrawVolumeSlider(const EstadoJogo *jogo, Vector2 sliderPos) {
    // Define a geometria geral do slider
    float comprimentoTotalSlider = 400.0f;
    float alturaSlider = (float)jogo->options.barraFundoEsq.height;

    // --- 1. Desenha a Barra de Fundo (3-Slice) ---
    if (jogo->options.barraFundoEsq.id > 0) {
        DrawTextureV(jogo->options.barraFundoEsq, sliderPos, WHITE);
        Rectangle sourceMeio = {0, 0, (float)jogo->options.barraFundoMeio.width, (float)jogo->options.barraFundoMeio.height};
        Rectangle destMeio = {sliderPos.x + jogo->options.barraFundoEsq.width, sliderPos.y, comprimentoTotalSlider - jogo->options.barraFundoEsq.width - jogo->options.barraFundoDir.width, alturaSlider};
        DrawTexturePro(jogo->options.barraFundoMeio, sourceMeio, destMeio, (Vector2){0,0}, 0.0f, WHITE);
        DrawTextureV(jogo->options.barraFundoDir, (Vector2){sliderPos.x + comprimentoTotalSlider - jogo->options.barraFundoDir.width, sliderPos.y}, WHITE);
    }

    // --- 2. Desenha a Barra de Preenchimento (Técnica de Recorte de Sprite) ---
    if (jogo->options.barraPreenchimentoCompleta.id > 0) {
        Texture2D preenchimento = jogo->options.barraPreenchimentoCompleta;
        // Calcula qual pedaço da largura do sprite original vamos mostrar
        float larguraDoRecorte = (float)preenchimento.width * jogo->volumeAtual;

        // Define o retângulo de origem (o "corte" do sprite) e o de destino (onde desenhar na tela)
        Rectangle sourceRecorte = { 0.0f, 0.0f, larguraDoRecorte, (float)preenchimento.height };
        Rectangle destRec = { sliderPos.x, sliderPos.y, comprimentoTotalSlider * jogo->volumeAtual, alturaSlider };

        // Desenha apenas o pedaço recortado da textura
        DrawTexturePro(preenchimento, sourceRecorte, destRec, (Vector2){0,0}, 0.0f, WHITE);
    }

    // --- 3. Desenha o Puxador por cima de tudo ---
    if (jogo->options.puxadorVolume.id > 0) {
        // Calcula a posição do centro do puxador para que ele fique no final do preenchimento
        Vector2 posPuxador = {
            sliderPos.x + (comprimentoTotalSlider * jogo->volumeAtual) - ((float)jogo->options.puxadorVolume.width / 2.0f),
            sliderPos.y + (alturaSlider / 2.0f) - ((float)jogo->options.puxadorVolume.height / 2.0f)
        };
        DrawTextureV(jogo->options.puxadorVolume, posPuxador, WHITE);
    }
}