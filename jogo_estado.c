#include "estruturas.h"
#include "raylib.h"

void init_estado_jogo(EstadoJogo *pJogo) {
    pJogo->screen = SCREEN_MENU;

    pJogo->menu.fundo = LoadTexture("../Sprites/fundo.png");
    pJogo->menu.titulo = LoadTexture("../Sprites/titulo.png");
    pJogo->menu.botaoJogar = LoadTexture("../Sprites/BotaoStart.png");
    pJogo->menu.botaoOpcoes = LoadTexture("../Sprites/options.png");
    pJogo->menu.botaoSair = LoadTexture("../Sprites/exit.png");
}