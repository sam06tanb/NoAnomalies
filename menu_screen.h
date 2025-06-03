
#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "raylib.h"
#include "estruturas.h"

void UpdateMenuScreen(EstadoJogo *jogo, Vector2 mousePos,
                      Vector2 posJogar, Vector2 posOpcoes, Vector2 posSair);

void DrawMenuScreen(const EstadoJogo *jogo, Vector2 tituloPos,
                    Vector2 posJogar, Vector2 posOpcoes, Vector2 posSair);

#endif