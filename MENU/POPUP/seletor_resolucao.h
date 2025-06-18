/**
* @file seletor_resolucao.h
 * @brief Declarações das funções para o componente de seletor de resolução.
 */
#ifndef SELETOR_RESOLUCAO_H
#define SELETOR_RESOLUCAO_H

#include "estruturas.h"
#include "raylib.h"

/**
 * @brief Atualiza o estado do seletor de resolução com base nos cliques do mouse nas setas.
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos A posição virtual do mouse na tela.
 * @param painelPos A posição do painel de opções, usada como referência para as posições das setas.
 */
void UpdateSeletorResolucao(EstadoJogo *jogo, Vector2 mousePos, Vector2 painelPos);

/**
 * @brief Desenha os componentes visuais do seletor de resolução.
 * @param jogo Ponteiro (const) para o estado do jogo.
 * @param painelPos A posição do painel de opções, usada como referência para o desenho.
 */
void DrawSeletorResolucao(const EstadoJogo *jogo, Vector2 painelPos);

#endif //SELETOR_RESOLUCAO_H