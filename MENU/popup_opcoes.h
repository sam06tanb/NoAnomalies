#ifndef POPUP_OPCOES_H
#define POPUP_OPCOES_H

#include "estruturas.h"
#include "raylib.h"

void UpdatePopupOpcoes(EstadoJogo *jogo, Vector2 mousePos, Music music);

void DrawPopupOpcoes(const EstadoJogo *jogo);

void DrawAnimatedButton(Texture2D texture, Vector2 position, float animatedScale);

#endif