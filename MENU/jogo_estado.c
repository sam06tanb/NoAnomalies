#include <stdio.h>

#include "estruturas.h"
#include "defines.h"
#include "raylib.h"
#include <string.h>

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
    pJogo->options.botaoTutorial = LoadTexture("../Sprites/tutorial.png");
    pJogo->options.botaoVolume = LoadTexture("../Sprites/volume.png");
    pJogo->options.botaoAplicar = LoadTexture("../Sprites/botao_aplicar.png");

    //RESOLUCAO
    pJogo->options.setaEsquerda = LoadTexture("../Sprites/seta_esquerda.png");
    pJogo->options.setaDireita = LoadTexture("../Sprites/seta_direita.png");

    char nomeArquivoResolucao[64];
    for (int i = 0; i < NUM_RESOLUCOES; i++) {
        sprintf(nomeArquivoResolucao, "../Sprites/resolucao_%d.png", i);
        pJogo->options.spritesResolucao[i] = LoadTexture(nomeArquivoResolucao);
        if (pJogo->options.spritesResolucao[i].id == 0) {
            printf("AVISO: falha ao carregar sprite de resolucao: %s\n", nomeArquivoResolucao);
        }

        pJogo->resolucoesDisponiveis[0] = (Vector2){1920,1080};
        pJogo->resolucoesDisponiveis[1] = (Vector2){1600,900};
        pJogo->resolucoesDisponiveis[2] = (Vector2){1280,720};
        pJogo->resolucoesDisponiveis[3] = (Vector2){800,600};
        pJogo->indiceResolucoesAtual = 0;
    }

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
    pJogo->mouseSobreBotaoAplicar = false;

    pJogo->animatedEscalaAplicar = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaFechar = 1.0f;
    pJogo->animatedEscalaVolume = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaResolucao = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaTutorial = ESCALA_NORMAL_BOTAO;

    pJogo->num_total_comodos = 1;
    pJogo->indice_comodo_atual = 0;

    strcpy(pJogo->todos_os_comodos[0].arquivo_imagem_fundo, "../Sprites/comodo1.png");

    pJogo->texturaComodoAtual.id = 0;

}