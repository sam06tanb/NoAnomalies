/**
 * @file aplicar.c
 * @brief Contém a lógica e o desenho para o componente de botão "Aplicar".
 *
 * Este módulo gerencia o botão "Aplicar" na tela de opções. Sua principal
 * responsabilidade é pegar as configurações selecionadas pelo jogador (como a resolução)
 * e aplicá-las de fato ao jogo.
 */

#include "aplicar.h"
#include "defines.h"
#include "ui_helpers.h"
#include <stdio.h> // Para a ação placeholder printf

/**
 * @brief Atualiza o estado do botão 'Aplicar' e executa a lógica de mudança de resolução.
 * A Ação de Clique consiste em 5 passos:
 * 1. Pega a resolução selecionada pelo jogador no estado do jogo.
 * 2. Chama `SetWindowSize()` para redimensionar a janela.
 * 3. Calcula a posição central no monitor do usuário.
 * 4. Chama `SetWindowPosition()` para mover a janela recém-redimensionada para o centro.
 * 5. Fecha o pop-up de opções.
 *
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos A posição virtual do mouse na tela.
 * @param posAplicar A posição base (canto superior esquerdo) do botão.
 */
void UpdateAplicar(EstadoJogo *jogo, Vector2 mousePos, Vector2 posAplicar) {
    // Define a área de clique (hitbox) do botão.
    Rectangle hitBoxAplicar = {
        posAplicar.x,
        posAplicar.y,
        (float)jogo->options.botaoAplicar.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->options.botaoAplicar.height * ESCALA_NORMAL_BOTAO
    };

    // Lógica de Hover e Clique.
    if (CheckCollisionPointRec(mousePos, hitBoxAplicar)) {
        jogo->mouseSobreBotaoAplicar = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Aplicando resolucao!\n");

            // 1. Pega a resolução escolhida pelo jogador.
            Vector2 novaResolucao = jogo->resolucoesDisponiveis[jogo->indiceResolucoesAtual];
            int novaLargura = (int)novaResolucao.x;
            int novaAltura = (int)novaResolucao.y;

            // 2. Aplica o novo tamanho à janela.
            SetWindowSize(novaLargura, novaAltura);

            // 3. Calcula a posição central do monitor.
            int larguraMonitor = GetMonitorWidth(0); // 0 = monitor principal
            int alturaMonitor = GetMonitorHeight(0);
            int novoPosX = (larguraMonitor - novaLargura) / 2;
            int novoPosY = (alturaMonitor - novaAltura) / 2;

            // 4. Move a janela para o centro do monitor.
            SetWindowPosition(novoPosX, novoPosY);

            // 5. Fecha o pop-up de opções.
            jogo->popupOpcoesVisivel = false;
        }
    } else {
        jogo->mouseSobreBotaoAplicar = false;
    }

    // Lógica de Animação de Escala.
    float targetEscalaAplicar;
    if (jogo->mouseSobreBotaoAplicar) {
        targetEscalaAplicar = ESCALA_HOVER_BOTAO;
    } else {
        targetEscalaAplicar = ESCALA_NORMAL_BOTAO;
    }
    jogo->animatedEscalaAplicar += (targetEscalaAplicar - jogo->animatedEscalaAplicar) * VELOCIDADE_ANIM_BOTAO;
}

/**
 * @brief Desenha o botão 'Aplicar' na tela.
 *
 * Esta função simplesmente chama a função auxiliar `DrawAnimatedButton` para renderizar
 * o botão, passando os dados específicos dele (textura, posição e escala animada).
 *
 * @param jogo Ponteiro (const) para o estado do jogo.
 * @param position A posição base onde o botão deve ser desenhado.
 */
void DrawAplicar(const EstadoJogo *jogo, Vector2 position) {
    DrawAnimatedButton(jogo->options.botaoAplicar, position, jogo->animatedEscalaAplicar);
}