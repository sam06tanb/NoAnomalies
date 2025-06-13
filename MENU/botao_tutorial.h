#ifndef BOTAO_TUTORIAL_H
#define BOTAO_TUTORIAL_H

#include "estruturas.h"
#include "raylib.h"

void UpdateBotaoTutorial(EstadoJogo *jogo, Vector2 mousePos, Vector2 position);
void DrawBotaoTutorial(const EstadoJogo *jogo, Vector2 position);

#endif