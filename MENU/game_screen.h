/**
* @file game_screen.h
 * @brief Declarações das funções que gerenciam a tela de Gameplay.
 */

#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "estruturas.h"

/**
 * @brief Atualiza a lógica da tela de jogo.
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos Posição virtual do mouse.
 */
void UpdateGameScreen(EstadoJogo *jogo, Vector2 mousePos);

/**
 * @brief Desenha a tela de jogo.
 * @param jogo Ponteiro (const) para o estado do jogo.
 */
void DrawGameScreen(const EstadoJogo *jogo);

/**
 * @brief Carrega os recursos necessários para a tela de jogo.
 * @param jogo Ponteiro para o estado geral do jogo.
 */
void CarregarRecursosJogo(EstadoJogo *jogo);

/**
 * @brief Descarrega os recursos da tela de jogo.
 * @param jogo Ponteiro para o estado geral do jogo.
 */
void DescarregarRecursosJogo(EstadoJogo *jogo);

#endif //GAME_SCREEN_H