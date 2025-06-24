

#include "estruturas.h"
#include "defines.h"
#include "menu_screen.h"
#include <string.h>

#include "DescCarreg.h"
#include "raylib.h"

void init_estado_jogo(EstadoJogo *pJogo) {
    // --- Configuração da Tela Inicial ---
    pJogo->screen = SCREEN_MENU;

    // --- Configuração das Opções ---
    pJogo->resolucoesDisponiveis[0] = (Vector2){1920, 1080};
    pJogo->resolucoesDisponiveis[1] = (Vector2){1600, 900};
    pJogo->resolucoesDisponiveis[2] = (Vector2){1280, 720};
    pJogo->resolucoesDisponiveis[3] = (Vector2){800, 600};
    pJogo->indiceResolucoesAtual = 0; // Começa com a primeira resolução selecionada

    pJogo->volumeAtual = 0.5f; // Começa com 50% de volume
    pJogo->arrastandoSliderVolume = false;
    pJogo->popupOpcoesVisivel = false;


    // Menu Principal
    pJogo->mouseSobreBotaoJogar = false;
    pJogo->mouseSobreBotaoOpcoes = false;
    pJogo->mouseSobreBotaoSair = false;
    pJogo->mouseSobreBotaoVoltar = false;
    pJogo->mouseSobreBotaoFechar = false;
    pJogo->mouseSobreBotaoAplicar = false;
    pJogo->mouseSobreBotaoTutorial = false;



    pJogo->animatedEscalaJogar = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaOpcoes = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaSair = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaVoltar = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaAplicar = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaTutorial = ESCALA_NORMAL_BOTAO;


    //Report(In-game)
    pJogo->painelReporteVisivel = false;
    pJogo->mouseSobreBotaoApareceu = false;

    pJogo->animatedEscalaApareceu = ESCALA_NORMAL_BOTAO;

    // --- Configuração do Jogo (Gameplay) ---
    strcpy(pJogo->todos_os_comodos[0].arquivo_imagem_fundo, "../Sprites/comodo0.png");
    strcpy(pJogo->todos_os_comodos[1].arquivo_imagem_fundo, "../Sprites/comodo1.png");
    pJogo->num_total_comodos = 2;
    pJogo->indice_comodo_atual = 0;

    // Garante que a textura do cômodo comece vazia (só será carregada ao entrar no jogo)
    pJogo->texturaComodoAtual.id = 0;

    CarregarRecursosMenu(pJogo);
}