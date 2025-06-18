/**
 * @file popup_opcoes.c
 * @brief Orquestrador principal para a tela de Pop-up de Opções.
 *
 * Este arquivo não contém a lógica detalhada de cada botão ou slider. Em vez disso,
 * ele é responsável por:
 * 1. Calcular a posição de cada componente na tela.
 * 2. Chamar as funções de Update de cada componente na ordem correta.
 * 3. Chamar as funções de Draw de cada componente na ordem correta (pintura em camadas).
 * Essencialmente, ele atua como o "gerente" do pop-up.
 */

#include "popup_opcoes.h"
#include "slider_volume.h"
#include "seletor_resolucao.h"
#include "botao_tutorial.h"
#include "botao_fechar.h"
#include "../H/defines.h"
#include "../../cmake-build-debug/_deps/raylib-src/src/raymath.h"
#include <stdio.h>

#include "aplicar.h"

/**
 * @brief Função principal de lógica (Update) para a tela de pop-up de opções.
 *
 * Esta função é chamada a cada frame (quando o pop-up está visível) para atualizar o
 * estado de todos os elementos interativos dentro dele.
 * Primeiro, ela calcula as posições de todos os componentes. Depois, ela "delega" o
 * trabalho, chamando a função de Update específica de cada componente.
 *
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos A posição virtual do mouse na tela.
 * @param music A música do jogo, para ser controlada pelo slider.
 */
void UpdatePopupOpcoes(EstadoJogo *jogo, Vector2 mousePos, Music music) {
    // Este 'if' é uma segurança extra. A lógica no main() já garante que esta
    // função só é chamada quando o pop-up está visível.
    if (jogo->popupOpcoesVisivel) {
        // --- 1. Calcular Posições de Referência ---
        float painelLargura = (float) jogo->options.painelPopupOpcoes.width;
        float painelAltura = (float) jogo->options.painelPopupOpcoes.height;
        Vector2 popupPainelPos = {
            (float) VIRTUAL_SCREEN_WIDTH / 2 - painelLargura / 2,
            (float) VIRTUAL_SCREEN_HEIGHT / 2 - painelAltura / 2
        };

        // Posições de cada componente (ajuste aqui para mudar o layout)
        Vector2 posFechar = { popupPainelPos.x + painelLargura - jogo->options.botaoFecharPopup.width - 10, popupPainelPos.y + 10 };
        Vector2 posSlider = {(float) VIRTUAL_SCREEN_WIDTH / 2 - 200, (float) VIRTUAL_SCREEN_HEIGHT / 2 - 300};
        Vector2 posTutorial = {popupPainelPos.x + 150, popupPainelPos.y + 650};
        Vector2 posAplicar = {1100, 925};

        // Área de clique do slider
        Rectangle sliderArea   = { posSlider.x, posSlider.y, 400, (float)jogo->options.barraFundoEsq.height };


        // --- 2. Delegar a Lógica de Update para Cada Componente ---
        UpdateBotaoFechar(jogo, mousePos, posFechar);
        UpdateVolumeSlider(jogo, mousePos, sliderArea, music);
        UpdateSeletorResolucao(jogo, mousePos, popupPainelPos); // Passa o painel para ele calcular as setas
        UpdateBotaoTutorial(jogo, mousePos, posTutorial);
        UpdateAplicar(jogo, mousePos, posAplicar);
    }
}


/**
 * @brief Função principal de desenho (Draw) para a tela de pop-up de opções.
 *
 * Desenha a tela em camadas para garantir a ordem correta de sobreposição:
 * 1. Fundo escurecido.
 * 2. Painel principal do pop-up.
 * 3. Todos os componentes (botões, slider, etc.) por cima do painel.
 * Assim como na função de Update, ela delega o trabalho de desenho para as funções
 * específicas de cada componente.
 *
 * @param jogo Ponteiro (const) para o estado do jogo, usado para ler os dados a serem desenhados.
 */
void DrawPopupOpcoes(const EstadoJogo *jogo) {
    // --- 1. Desenha a Base ---
    DrawRectangle(0, 0, VIRTUAL_SCREEN_WIDTH, VIRTUAL_SCREEN_HEIGHT, Fade(BLACK, 0.7f));
    Vector2 painelPos = {
        (float) VIRTUAL_SCREEN_WIDTH / 2 - (float) jogo->options.painelPopupOpcoes.width / 2,
        (float) VIRTUAL_SCREEN_HEIGHT / 2 - (float) jogo->options.painelPopupOpcoes.height / 2
    };
    DrawTextureV(jogo->options.painelPopupOpcoes, painelPos, WHITE);

    // --- 2. Posições dos Componentes (devem ser idênticas às de Update) ---
    // Nota: Em um projeto maior, essas posições seriam calculadas uma vez por frame
    // para evitar repetição, mas aqui está claro e funcional.

    Vector2 posFechar = {painelPos.x + (float) jogo->options.painelPopupOpcoes.width - (float) jogo->options.botaoFecharPopup.width -20,painelPos.y + 20 };
    Vector2 posSlider = {(float) VIRTUAL_SCREEN_WIDTH / 2 - 200, (float) VIRTUAL_SCREEN_HEIGHT / 2 - 300};
    Vector2 posTutorial = {painelPos.x + 150, painelPos.y + 650};
    Vector2 posAplicar = {1100, 925};

    // --- 3. Delega o Desenho para Cada Componente ---
    DrawBotaoFechar(jogo, posFechar);
    DrawVolumeSlider(jogo, posSlider);
    DrawSeletorResolucao(jogo, painelPos);
    DrawBotaoTutorial(jogo, posTutorial);
    DrawAplicar(jogo, posAplicar);
}


