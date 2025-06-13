#ifndef BOTAO_FECHAR_H
#define BOTAO_FECHAR_H

#include "estruturas.h"
#include "raylib.h"

void UpdateBotaoFechar(EstadoJogo *jogo, Vector2 mousePos, Vector2 position);
void DrawBotaoFechar(const EstadoJogo *jogo, Vector2 position);

#endif