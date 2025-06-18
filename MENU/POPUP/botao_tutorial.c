/**
 * @file botao_tutorial.c
 * @brief Contém a lógica e o desenho para o componente de botão "How to Play".
 *
 * Este módulo é responsável por gerenciar a interatividade e a aparência do botão
 * que, no futuro, poderá abrir uma tela ou pop-up com as instruções do jogo.
 */

#include "botao_tutorial.h"
#include "defines.h"
#include "ui_helpers.h" // Para usar a função genérica DrawAnimatedButton
#include <stdio.h>      // Para a ação placeholder printf

/**
 * @brief Atualiza o estado do botão 'How to Play' a cada frame.
 *
 * Esta função segue o padrão de botão animado:
 * 1. Define a área de clique (hitbox) do botão.
 * 2. Verifica se o mouse está sobre o botão e atualiza o estado de 'hover'.
 * 3. Se houver um clique, executa a ação do botão (atualmente, imprime uma mensagem no console).
 * 4. Atualiza a escala do botão para a animação suave de crescer/encolher.
 *
 * @param jogo Ponteiro para o estado geral do jogo, onde o estado do botão é guardado.
 * @param mousePos A posição virtual do mouse na tela.
 * @param position A posição base (canto superior esquerdo) do botão.
 */
void UpdateBotaoTutorial(EstadoJogo *jogo, Vector2 mousePos, Vector2 position) {

    // Define a área de clique (hitbox) do botão
    Rectangle hitboxTutorial = {
        position.x,
        position.y,
        (float)jogo->options.botaoTutorial.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->options.botaoTutorial.height * ESCALA_NORMAL_BOTAO
    };

    // Lógica de Hover: atualiza o estado se o mouse está sobre o botão
    if (CheckCollisionPointRec(mousePos, hitboxTutorial)) {
        jogo->mouseSobreBotaoTutorial = true;
    } else {
        jogo->mouseSobreBotaoTutorial = false;
    }

    // Lógica de Clique: se o mouse está sobre e o botão é clicado, executa a ação
    if (jogo->mouseSobreBotaoTutorial && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        printf("Botao Tutorial clicado!\n"); // Ação placeholder
    }

    // Lógica de Animação: atualiza a escala para a transição suave
    float targetEscalaTutorial;
    if (jogo->mouseSobreBotaoTutorial) {
        targetEscalaTutorial = ESCALA_HOVER_BOTAO;
    } else {
        targetEscalaTutorial = ESCALA_NORMAL_BOTAO;
    }
    jogo->animatedEscalaTutorial += (targetEscalaTutorial - jogo->animatedEscalaTutorial) * VELOCIDADE_ANIM_BOTAO;
}

/**
 * @brief Desenha o botão 'How to Play' na tela.
 *
 * Esta função é um ótimo exemplo da vantagem de refatorar o código. Em vez de
 * ter toda a lógica de desenho complexa aqui, ela simplesmente chama a função
 * auxiliar 'DrawAnimatedButton', passando os dados específicos deste botão
 * (sua textura, sua posição e sua escala animada atual).
 *
 * @param jogo Ponteiro (const) para o estado do jogo.
 * @param position A posição base onde o botão deve ser desenhado.
 */
void DrawBotaoTutorial(const EstadoJogo *jogo, Vector2 position) {
    // Delega todo o trabalho de desenho para a função ajudante
    DrawAnimatedButton(jogo->options.botaoTutorial, position, jogo->animatedEscalaTutorial);
}