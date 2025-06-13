#ifndef aplicar_h
#define aplicar_h

#include "raylib.h"
#include "estruturas.h"

void UpdateAplicar(EstadoJogo *jogo, Vector2 mousePos, Vector2 posAplicar);

void DrawAplicar(const EstadoJogo *jogo, Vector2 position);

#endif