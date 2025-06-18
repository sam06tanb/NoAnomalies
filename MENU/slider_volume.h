/**
* @file slider_volume.h
 * @brief Declarações das funções para o componente de slider de volume.
 */
#ifndef SLIDER_VOLUME_H
#define SLIDER_VOLUME_H

#include "raylib.h"
#include "estruturas.h"

/**
 * @brief Atualiza o estado do slider de volume baseado na interação do mouse.
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos A posição virtual do mouse na tela.
 * @param sliderArea O retângulo que define a área total e a hitbox do slider.
 * @param music A música que terá seu volume alterado.
 */
void UpdateVolumeSlider(EstadoJogo *jogo, Vector2 mousePos, Rectangle sliderArea, Music music);

/**
 * @brief Desenha o slider de volume na tela usando os sprites customizados.
 * @param jogo Ponteiro (const) para o estado do jogo.
 * @param sliderPos A posição base (canto superior esquerdo) onde o slider deve ser desenhado.
 */
void DrawVolumeSlider(const EstadoJogo *jogo, Vector2 sliderPos);

#endif //SLIDER_VOLUME_H