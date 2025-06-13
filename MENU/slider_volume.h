#ifndef SLIDER_VOLUME_H
#define SLIDER_VOLUME_H

#include "raylib.h"
#include "estruturas.h"

void UpdateVolumeSlider(EstadoJogo *jogo, Vector2 mousePos, Rectangle sliderArea, Music music);

void DrawVolumeSlider(EstadoJogo *jogo, Vector2 sliderPos);

#endif