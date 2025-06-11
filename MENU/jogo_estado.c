#include "estruturas.h"
#include "defines.h"
#include "raylib.h"

void init_estado_jogo(EstadoJogo *pJogo) {
    pJogo->screen = SCREEN_MENU;

    //MENU PRINCIPAL
    pJogo->menu.fundo = LoadTexture("../Sprites/fundo.png");
    pJogo->menu.titulo = LoadTexture("../Sprites/titulo.png");
    pJogo->menu.botaoJogar = LoadTexture("../Sprites/BotaoStart.png");
    pJogo->menu.botaoOpcoes = LoadTexture("../Sprites/options.png");
    pJogo->menu.botaoSair = LoadTexture("../Sprites/exit.png");

    //OPTIONS
    pJogo->options.painelPopupOpcoes = LoadTexture("../Sprites/FundoOPT.png");
    pJogo->options.botaoFecharPopup = LoadTexture("../Sprites/x.png");
    pJogo->options.botaoResolucao = LoadTexture("../Sprites/resolution.png");
    pJogo->options.botaoTutorial = LoadTexture("../Sprites/resolution.png");
    pJogo->options.botaoVolume = LoadTexture("../Sprites/resolution.png");

    //BOOL HOVER BOTAO MENU
    pJogo->mouseSobreBotaoJogar = false;
    pJogo->mouseSobreBotaoOpcoes = false;
    pJogo->mouseSobreBotaoSair = false;

    //HOVER MENU PRINCIPAL
    pJogo->animatedEscalaJogar = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaOpcoes = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaSair = ESCALA_NORMAL_BOTAO;

    //BOOL OPTIONS

    pJogo->popupOpcoesVisivel = false;
    pJogo->mouseSobreBotaoFechar = false;
    pJogo->mouseSobreBotaoVolume = false;
    pJogo->mouseSobreBotaoResolucao = false;
    pJogo->mouseSobreBotaoTutorial = false;
    pJogo->animatedEscalaFechar = 1.0f;
    pJogo->animatedEscalaVolume = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaResolucao = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaTutorial = ESCALA_NORMAL_BOTAO;


}