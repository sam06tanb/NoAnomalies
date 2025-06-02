#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

#define MAX_ANOMALIAS_POSSIVEIS_POR_COMODO 20
#define MAX_ANOMALIAS_ATIVAS_SIMULTANEAMENTE 5
#define MAX_DESCRICAO_ANOMALIA 100
#define MAX_NOME_SPRITE 50
#define MAX_NOME_COMODO 50
#define MAX_COMODOS_NO_JOGO 10

typedef struct {

    int id, tipo;
    char descricao[MAX_DESCRICAO_ANOMALIA];

    float posX, posY, largura, altura;

    bool ativa_no_momento, reportada_corretamente;

} Anomalia;

typedef struct {

    int id;
    char nome[MAX_NOME_COMODO];
    char arquivo_imagem_fundo[MAX_NOME_SPRITE];

    Anomalia lista_de_todas_anomalias[MAX_ANOMALIAS_POSSIVEIS_POR_COMODO];
    int num_total_anomalias_possiveis;

    int ids_anomalias_ativas_agora[MAX_ANOMALIAS_ATIVAS_SIMULTANEAMENTE];
    int num_anomalias_ativas_agora;

} Comodo;

typedef enum GameScreen {
    SCREEN_MENU,
    SCREEN_GAME,
    SCREEN_OPTIONS,
    SCREEN_SAIR
} GameScreen;

typedef struct {
    Texture2D fundo;
    Texture2D titulo;
    Texture2D botaoJogar;
    Texture2D botaoJogarHover;
    Texture2D botaoOpcoes;
    Texture2D botaoOpcoesHover;
    Texture2D botaoSair;
    Texture2D botaoSairHover;

} RecursosMenu;

typedef struct {

    Comodo todos_os_comodos[MAX_COMODOS_NO_JOGO];
    int num_total_comodos, indice_comodo_atual, pontuacao, vidas_restantes;
    float tempo_geral_restante;
    GameScreen screen;
    RecursosMenu menu;

    bool em_menu_principal, jogando, pausado, fim_de_jogo, vitoria;

} EstadoJogo;

static void init_estado_jogo(EstadoJogo *pJogo) {
    pJogo->screen = SCREEN_MENU;

    pJogo->menu.fundo = LoadTexture("../Sprites/fundo.png");
    pJogo->menu.titulo = LoadTexture("../Sprites/titulo.png");
    //pJogo->menu.botaoJogar = LoadTexture("../Sprites/BotaoStartTesteReal.png");
    //pJogo->menu.botaoJogarHover = LoadTexture("../assets/menu/botao_jogar_hover.png");
    pJogo->menu.botaoOpcoes = LoadTexture("../Sprites/BotaoStartTesteReal.png");
    //pJogo->menu.botaoOpcoesHover = LoadTexture("../assets/menu/botao_opcoes_hover.png");
    //pJogo->menu.botaoSair = LoadTexture("../Sprites/BotaoStartTesteReal.png");
    //pJogo->menu.botaoSairHover = LoadTexture("../assets/menu/botao_sair_hover.png");
}

