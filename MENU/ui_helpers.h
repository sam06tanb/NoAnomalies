/**
* @file ui_helpers.h
 * @brief Declarações de funções auxiliares para a UI.
 *
 * Inclua este arquivo em qualquer lugar que precisar usar uma das funções
 * de desenho genéricas, como DrawAnimatedButton.
 */
#ifndef UI_HELPERS_H
#define UI_HELPERS_H

#include "raylib.h"

/**
 * @brief Desenha um botão na tela com uma animação de escala suave que se expande a partir do centro.
 * @param texture A textura (sprite) do botão.
 * @param position A posição base (canto superior esquerdo) do botão em sua escala normal.
 * @param animatedScale A escala animada atual do botão.
 */
void DrawAnimatedButton(Texture2D texture, Vector2 position, float animatedScale);

#endif //UI_HELPERS_H