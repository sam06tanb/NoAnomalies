#include "estruturas.h"
#include "raylib.h"

void init_estado_jogo(EstadoJogo *pJogo) {
    pJogo->screen = SCREEN_MENU;

    pJogo->menu.fundo = LoadTexture("../Sprites/fundo.png");
    pJogo->menu.titulo = LoadTexture("../Sprites/titulo.png");
    pJogo->menu.botaoJogar = LoadTexture("../Sprites/BotaoStart.png");
    //pJogo->menu.botaoJogarHover = LoadTexture("../assets/menu/botao_jogar_hover.png");
    pJogo->menu.botaoOpcoes = LoadTexture("../Sprites/BotaoStart.png");
    //pJogo->menu.botaoOpcoesHover = LoadTexture("../assets/menu/botao_opcoes_hover.png");
    pJogo->menu.botaoSair = LoadTexture("../Sprites/BotaoStart.png");
    //pJogo->menu.botaoSairHover = LoadTexture("../assets/menu/botao_sair_hover.png");
}