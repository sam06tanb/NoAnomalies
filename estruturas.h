#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include "raylib.h"

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
    Texture2D botaoOpcoes;
    Texture2D botaoSair;
    Texture2D painelPopupOpcoes;
    Texture2D botaoFecharPopup;

} RecursosMenu;

typedef struct {

    Comodo todos_os_comodos[MAX_COMODOS_NO_JOGO];
    int num_total_comodos, indice_comodo_atual, pontuacao, vidas_restantes;
    float tempo_geral_restante;
    GameScreen screen;
    RecursosMenu menu;

    bool mouseSobreBotaoJogar;
    bool mouseSobreBotaoOpcoes;
    bool mouseSobreBotaoSair;
    bool popupOpcoesVisivel;

    float animatedEscalaJogar;
    float animatedEscalaOpcoes;
    float animatedEscalaSair;

    bool em_menu_principal, jogando, pausado, fim_de_jogo, vitoria;

} EstadoJogo;

void init_estado_jogo(EstadoJogo *pJogo);

#endif