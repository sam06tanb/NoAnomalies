#include "DescCarreg.h"
#include <stdio.h>

void CarregarRecursosMenu(EstadoJogo *jogo) {
    jogo->recursos_jogo.botaoVoltar = LoadTexture("../Sprites/options.png");
    jogo->menu.fundo = LoadTexture("../Sprites/fundo.png");
    jogo->menu.titulo = LoadTexture("../Sprites/titulo.png");
    jogo->menu.botaoJogar = LoadTexture("../Sprites/BotaoStart.png");
    jogo->menu.botaoOpcoes = LoadTexture("../Sprites/options.png");
    jogo->menu.botaoSair = LoadTexture("../Sprites/exit.png");

    jogo->options.painelPopupOpcoes = LoadTexture("../Sprites/FundoOPT.png");
    jogo->options.botaoFecharPopup = LoadTexture("../Sprites/x.png");
    jogo->options.botaoTutorial = LoadTexture("../Sprites/tutorial.png");
    jogo->options.botaoAplicar = LoadTexture("../Sprites/botao_aplicar.png");

    jogo->options.setaEsquerda = LoadTexture("../Sprites/seta_esquerda.png");
    jogo->options.setaDireita = LoadTexture("../Sprites/seta_direita.png");

    jogo->resolucoesDisponiveis[0] = (Vector2){1920,1080};
    jogo->resolucoesDisponiveis[1] = (Vector2){1600,900};
    jogo->resolucoesDisponiveis[2] = (Vector2){1280,720};
    jogo->resolucoesDisponiveis[3] = (Vector2){800,600};
    jogo->indiceResolucoesAtual = 0;

    char nomeArquivoResolucao[64];
    for (int i = 0; i < NUM_RESOLUCOES; i++) {
        sprintf(nomeArquivoResolucao, "../Sprites/resolucao_%d.png", i);
        jogo->options.spritesResolucao[i] = LoadTexture(nomeArquivoResolucao);
        if (jogo->options.spritesResolucao[i].id == 0) {
            printf("AVISO: falha ao carregar sprite de resolucao: %s\n", nomeArquivoResolucao);
        }
    }

    jogo->options.puxadorVolume = LoadTexture("../Sprites/puxador_volume.png");
    jogo->options.barraFundoEsq = LoadTexture("../Sprites/barra_fundo_esq.png");
    jogo->options.barraFundoMeio = LoadTexture("../Sprites/barra_fundo_meio.png");
    jogo->options.barraFundoDir = LoadTexture("../Sprites/barra_fundo_dir.png");
    jogo->options.barraPreenchimentoCompleta = LoadTexture("../Sprites/barra_Inteira_Preenchida.png");

    //GAME
    jogo->recursos_jogo.botaoReport = LoadTexture("../Sprites/botao_report.png");

}

void DescarregarRecursosMenu(EstadoJogo *jogo) {
    printf("Descarregando recursos do Menu e Opcoes...\n");


    UnloadTexture(jogo->menu.fundo);
    UnloadTexture(jogo->menu.titulo);
    UnloadTexture(jogo->menu.botaoJogar);
    UnloadTexture(jogo->menu.botaoOpcoes);
    UnloadTexture(jogo->menu.botaoSair);

    UnloadTexture(jogo->options.painelPopupOpcoes);
    UnloadTexture(jogo->options.botaoFecharPopup);
    UnloadTexture(jogo->options.botaoTutorial);
    UnloadTexture(jogo->options.botaoAplicar);

    UnloadTexture(jogo->options.setaEsquerda);
    UnloadTexture(jogo->options.setaDireita);

    for (int i = 0; i < NUM_RESOLUCOES; i++) {
        if (jogo->options.spritesResolucao[i].id > 0) {
            UnloadTexture(jogo->options.spritesResolucao[i]);
        }
    }


    UnloadTexture(jogo->options.puxadorVolume);
    UnloadTexture(jogo->options.barraFundoEsq);
    UnloadTexture(jogo->options.barraFundoMeio);
    UnloadTexture(jogo->options.barraFundoDir);
    UnloadTexture(jogo->options.barraPreenchimentoCompleta);
}