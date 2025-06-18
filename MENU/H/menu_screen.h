/**
* @file menu_screen.h
 * @brief Declarações das funções que gerenciam a tela de Menu Principal.
 */

#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "estruturas.h"
#include "raylib.h"

/**
 * @brief Atualiza a lógica de todos os elementos da tela de menu.
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos A posição virtual do mouse.
 * @param posJogar A posição do botão Jogar.
 * @param posOpcoes A posição do botão Opções.
 * @param posSair A posição do botão Sair.
 */
void UpdateMenuScreen(EstadoJogo *jogo, Vector2 mousePos, Vector2 posJogar, Vector2 posOpcoes, Vector2 posSair);

/**
 * @brief Desenha todos os elementos visuais da tela de menu.
 * @param jogo Ponteiro (const) para o estado do jogo.
 * @param tituloPos A posição do título.
 * @param posJogar A posição do botão Jogar.
 * @param posOpcoes A posição do botão Opções.
 * @param posSair A posição do botão Sair.
 */
void DrawMenuScreen(const EstadoJogo *jogo, Vector2 tituloPos, Vector2 posJogar, Vector2 posOpcoes, Vector2 posSair);

// As funções de Carregar/Descarregar agora estão no seu arquivo DescCarreg.h/c,
// então os protótipos delas devem estar lá. Se você decidir que elas pertencem
// a este "módulo" de menu, os protótipos viriam para cá.

#endif //MENU_SCREEN_H