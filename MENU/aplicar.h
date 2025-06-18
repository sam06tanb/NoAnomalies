/**
* @file aplicar.h
 * @brief Declarações das funções para o componente de botão "Aplicar".
 */
#ifndef APLICAR_H
#define APLICAR_H

#include "estruturas.h"
#include "raylib.h"

/**
 * @brief Atualiza a lógica do botão 'Aplicar'.
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos Posição virtual do mouse.
 * @param posAplicar Posição base do botão.
 */
void UpdateAplicar(EstadoJogo *jogo, Vector2 mousePos, Vector2 posAplicar);

/**
 * @brief Desenha o botão 'Aplicar'.
 * @param jogo Ponteiro (const) para o estado do jogo.
 * @param position Posição base do botão.
 */
void DrawAplicar(const EstadoJogo *jogo, Vector2 position);

#endif //APLICAR_H