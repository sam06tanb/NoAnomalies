/**
 * @file botao_fechar.c
 * @brief Contém a lógica e o desenho para o componente de botão "Fechar" [X].
 *
 * Este é um componente simples, usado no pop-up de opções. Sua única função
 * é detectar o clique do mouse e sinalizar que o pop-up deve ser fechado.
 */

#include "botao_fechar.h"

/**
 * @brief Atualiza o estado do botão 'Fechar' a cada frame.
 *
 * Esta função define a área de clique (hitbox) do botão e verifica se o mouse
 * está sobre ele. Se um clique for detectado, ela muda a variável de estado
 * 'popupOpcoesVisivel' para 'false', efetivamente fechando o pop-up.
 * Diferente dos outros botões, este não possui uma lógica de animação de escala.
 *
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos A posição virtual do mouse na tela.
 * @param position A posição base (canto superior esquerdo) do botão.
 */
void UpdateBotaoFechar(EstadoJogo *jogo, Vector2 mousePos, Vector2 position) {

    // Define a hitbox do botão usando sua posição e o tamanho original do sprite.
    Rectangle hitboxBotaoFechar = {
        position.x,
        position.y,
        (float)jogo->options.botaoFecharPopup.width,
        (float)jogo->options.botaoFecharPopup.height
    };

    // Verifica se o mouse está sobre o botão.
    if (CheckCollisionPointRec(mousePos, hitboxBotaoFechar)) {
        jogo->mouseSobreBotaoFechar = true;
        // Se o clique acontecer, seta a visibilidade do pop-up para falso.
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->popupOpcoesVisivel = false;
        }
    } else {
        jogo->mouseSobreBotaoFechar = false;
    }
}

/**
 * @brief Desenha o botão 'Fechar' na tela.
 *
 * A função simplesmente desenha o sprite do botão 'Fechar' na posição especificada.
 * Como este botão não é animado, ela usa a função básica `DrawTextureV` da Raylib.
 *
 * @param jogo Ponteiro (const) para o estado do jogo, para acessar a textura do botão.
 * @param position A posição onde o botão deve ser desenhado.
 */
void DrawBotaoFechar(const EstadoJogo *jogo, Vector2 position) {
    // Só desenha se a textura foi carregada com sucesso.
    if (jogo->options.botaoFecharPopup.id > 0) {
        // Se você quisesse um efeito de hover simples (ex: mudar a cor),
        // a lógica iria aqui, usando 'jogo->mouseSobreBotaoFechar'.
        // Ex: DrawTextureV(..., jogo->mouseSobreBotaoFechar ? GRAY : WHITE);
        DrawTextureV(jogo->options.botaoFecharPopup, position, WHITE);
    }
}