/**
* @file popup_opcoes.h
 * @brief Declarações das funções que gerenciam a tela de pop-up de opções.
 */
#ifndef POPUP_OPCOES_H
#define POPUP_OPCOES_H

#include "estruturas.h"
#include "raylib.h"

/**
 * @brief Atualiza a lógica de todos os componentes dentro do pop-up.
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos A posição virtual do mouse na tela.
 * @param music A música do jogo, para ser controlada pelo slider.
 */
void UpdatePopupOpcoes(EstadoJogo *jogo, Vector2 mousePos, Music music);

/**
 * @brief Desenha todos os componentes do pop-up na tela.
 * @param jogo Ponteiro (const) para o estado do jogo.
 */
void DrawPopupOpcoes(const EstadoJogo *jogo);

#endif //POPUP_OPCOES_H