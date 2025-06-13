#ifndef SELETOR_RESOLUCAO_H
#define SELETOR_RESOLUCAO_H

#include "estruturas.h"
#include "raylib.h"

void UpdateSeletorResolucao(EstadoJogo *jogo, Vector2 mousePos, Vector2 painelPos);

void DrawSeletorResolucao(const EstadoJogo *jogo, Vector2 painelPos);

#endif //SELETOR_RESOLUCAO_H