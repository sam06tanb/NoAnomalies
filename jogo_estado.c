#include "estruturas.h"
#include "defines.h"
#include "raylib.h"

void init_estado_jogo(EstadoJogo *pJogo) {
    pJogo->screen = SCREEN_MENU;

    pJogo->menu.fundo = LoadTexture("../Sprites/fundo.png");
    pJogo->menu.titulo = LoadTexture("../Sprites/titulo.png");
    pJogo->menu.botaoJogar = LoadTexture("../Sprites/BotaoStart.png");
    pJogo->menu.botaoOpcoes = LoadTexture("../Sprites/options.png");
    pJogo->menu.botaoSair = LoadTexture("../Sprites/exit.png");
    pJogo->menu.painelPopupOpcoes = LoadTexture("../Sprites/optionsMenu.png");
    pJogo->menu.botaoFecharPopup = LoadTexture("../Sprites/x.png");

    pJogo->mouseSobreBotaoJogar = false;
    pJogo->mouseSobreBotaoOpcoes = false;
    pJogo->mouseSobreBotaoSair = false;
    pJogo->popupOpcoesVisivel = false;

    pJogo->animatedEscalaJogar = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaOpcoes = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaSair = ESCALA_NORMAL_BOTAO;
}