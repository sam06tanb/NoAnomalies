/**
 * @file jogo_estado.c
 * @brief Responsável pela inicialização do estado geral do jogo.
 *
 * Este arquivo contém a função `init_estado_jogo`, uma das funções mais importantes
 * do setup inicial. Ela é responsável por configurar todos os campos da struct `EstadoJogo`
 * com seus valores padrão antes que o loop principal do jogo comece.
 * Isso garante que o jogo sempre inicie em um estado conhecido e funcional.
 */

#include "estruturas.h"
#include "defines.h"
#include "menu_screen.h" // Para poder chamar CarregarRecursosMenu
#include <string.h>      // Para usar strcpy

#include "DescCarreg.h"

/**
 * @brief Inicializa todos os campos da struct EstadoJogo com seus valores padrão.
 *
 * Esta função atua como um "reset" para o estado do jogo. Ela é chamada uma única vez
 * no início do programa e tem as seguintes responsabilidades:
 * - Define a tela inicial que o jogador verá (SCREEN_MENU).
 * - Configura as opções padrão do jogo (resoluções disponíveis, volume inicial).
 * - Zera todos os estados interativos (flags de 'hover', visibilidade de pop-ups).
 * - Define a escala inicial para todas as animações de botões.
 * - Prepara os dados do primeiro cômodo do jogo (sem carregar a textura ainda).
 * - Por último, chama a função para carregar na memória todos os recursos da tela inicial.
 *
 * @param pJogo Um ponteiro para a variável global `EstadoJogo`, que será modificada por esta função.
 */
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

    // --- Zera Estados de Hover dos Botões ---
    // Menu Principal
    pJogo->mouseSobreBotaoJogar = false;
    pJogo->mouseSobreBotaoOpcoes = false;
    pJogo->mouseSobreBotaoSair = false;
    // Tela de Jogo
    pJogo->mouseSobreBotaoVoltar = false;
    // Pop-up de Opções
    pJogo->mouseSobreBotaoFechar = false;
    pJogo->mouseSobreBotaoAplicar = false;
    pJogo->mouseSobreBotaoTutorial = false;
    // (Note: mouseSobreBotaoVolume e Resolucao não são necessários pois o slider/setas usam a hitbox da área)

    // --- Zera Escalas Animadas dos Botões ---
    pJogo->animatedEscalaJogar = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaOpcoes = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaSair = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaVoltar = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaAplicar = ESCALA_NORMAL_BOTAO;
    pJogo->animatedEscalaTutorial = ESCALA_NORMAL_BOTAO;

    // --- Configuração do Jogo (Gameplay) ---
    // Prepara os dados do primeiro cômodo que será carregado
    strcpy(pJogo->todos_os_comodos[0].arquivo_imagem_fundo, "../Sprites/comodo1.png");
    pJogo->num_total_comodos = 1;
    pJogo->indice_comodo_atual = 0;

    // Garante que a textura do cômodo comece vazia (só será carregada ao entrar no jogo)
    pJogo->texturaComodoAtual.id = 0;

    // --- Carregamento dos Recursos Iniciais ---
    // Por fim, chama a função para carregar na memória todos os sprites da primeira tela (Menu)
    CarregarRecursosMenu(pJogo);
}