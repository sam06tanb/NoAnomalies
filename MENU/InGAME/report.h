#ifndef REPORT_H
#define REPORT_H

#include "estruturas.h"
#include "raylib.h"

void UpdateReport(EstadoJogo *jogo, Vector2 mousePos);

void DrawReport(const EstadoJogo *jogo);

#endif