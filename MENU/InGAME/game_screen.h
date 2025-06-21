#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "estruturas.h"

void UpdateGameScreen(EstadoJogo *jogo, Vector2 mousePos);
void DrawGameScreen(const EstadoJogo *jogo);
void CarregarRecursosJogo(EstadoJogo *jogo);
void DescarregarRecursosJogo(EstadoJogo *jogo);

#endif