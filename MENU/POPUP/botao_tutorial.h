/**
* @file botao_tutorial.h
 * @brief Declarações das funções para o componente de botão "How to Play".
 */
#ifndef BOTAO_TUTORIAL_H
#define BOTAO_TUTORIAL_H

#include "estruturas.h"
#include "raylib.h"

/**
 * @brief Atualiza a lógica do botão 'How to Play'.
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos Posição virtual do mouse.
 * @param position Posição base do botão.
 */
void UpdateBotaoTutorial(EstadoJogo *jogo, Vector2 mousePos, Vector2 position);

/**
 * @brief Desenha o botão 'How to Play'.
 * @param jogo Ponteiro (const) para o estado do jogo.
 * @param position Posição base do botão.
 */
void DrawBotaoTutorial(const EstadoJogo *jogo, Vector2 position);

#endif //BOTAO_TUTORIAL_H