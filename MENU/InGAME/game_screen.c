#include "game_screen.h"

#include <botaoVoltar.h>
#include <RoomChange.h>
#include <stdio.h>

#include "RoomChange.h"
#include "botaoVoltar.h"
#include "report.h"
#include "menu_screen.h"
#include "defines.h"
#include "ui_helpers.h"
#include <string.h>

void CarregarRecursosJogo(EstadoJogo *jogo) {
    printf("Carregando recursos do Jogo...\n");
    jogo->texturaComodoAtual = LoadTexture(jogo->todos_os_comodos[jogo->indice_comodo_atual].arquivo_imagem_fundo);
    jogo->recursos_jogo.botaoVoltar = LoadTexture("../Sprites/x.png");
    jogo->recursos_jogo.setaEsquerdaJogo = LoadTexture("../Sprites/seta_jogo_esq.png");
    jogo->recursos_jogo.setaDireitaJogo = LoadTexture("../Sprites/seta_jogo_dir.png");
    jogo->recursos_jogo.botaoReport = LoadTexture("../Sprites/botao_report.png");
    jogo->recursos_jogo.spritesNomesComodos[0] = LoadTexture("../Sprites/nome_quarto_0.png");
    jogo->recursos_jogo.spritesNomesComodos[1] = LoadTexture("../Sprites/nome_quarto_1.png");

    char nomeArquivo[64];
    for (int i = 0; i < jogo->num_total_comodos; i++) {
        sprintf(nomeArquivo, "../Sprites/nome_quarto_%d.png", i);
        jogo->recursos_jogo.spritesNomesComodos[i] = LoadTexture(nomeArquivo);
    }
}

void DescarregarRecursosJogo(EstadoJogo *jogo) {
    printf("Descarregando recursos do Jogo...\n");
    if (jogo->texturaComodoAtual.id > 0) UnloadTexture(jogo->texturaComodoAtual);
    if (jogo->recursos_jogo.botaoVoltar.id > 0) UnloadTexture(jogo->recursos_jogo.botaoVoltar);
    if (jogo->recursos_jogo.setaEsquerdaJogo.id > 0) UnloadTexture(jogo->recursos_jogo.setaEsquerdaJogo);
    if (jogo->recursos_jogo.setaDireitaJogo.id > 0) UnloadTexture(jogo->recursos_jogo.setaDireitaJogo);
    if (jogo->recursos_jogo.botaoReport.id > 0) UnloadTexture(jogo->recursos_jogo.botaoReport);


    for (int i = 0; i < jogo->num_total_comodos; i++) {
        if (jogo->recursos_jogo.spritesNomesComodos[i].id > 0) {
            UnloadTexture(jogo->recursos_jogo.spritesNomesComodos[i]);
        }
    }
}

void UpdateGameScreen(EstadoJogo *jogo, Vector2 mousePos) {
    UpdateBotaoVoltar(jogo, mousePos);
    UpdateRoomSelector(jogo, mousePos);
    UpdateReport(jogo, mousePos);
}

void DrawGameScreen(const EstadoJogo *jogo) {

    if (jogo->texturaComodoAtual.id > 0) {
        DrawTexture(jogo->texturaComodoAtual, 0, 0, WHITE);
    } else {
        DrawText("Textura do comodo nao carregada!", 400, 500, 40, RED);
    }

    DrawRoomSelector(jogo);
    DrawBotaoVoltar(jogo);
    DrawReport(jogo);
}