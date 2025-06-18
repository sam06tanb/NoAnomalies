/**
* @file botao_fechar.h
 * @brief Declarações das funções para o componente de botão "Fechar".
 */
#ifndef BOTAO_FECHAR_H
#define BOTAO_FECHAR_H

#include "estruturas.h"
#include "raylib.h"

/**
 * @brief Atualiza a lógica do botão 'Fechar'.
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos Posição virtual do mouse.
 * @param position Posição base do botão.
 */
void UpdateBotaoFechar(EstadoJogo *jogo, Vector2 mousePos, Vector2 position);

/**
 * @brief Desenha o botão 'Fechar'.
 * @param jogo Ponteiro (const) para o estado do jogo.
 * @param position Posição base do botão.
 */
void DrawBotaoFechar(const EstadoJogo *jogo, Vector2 position);

#endif //BOTAO_FECHAR_H