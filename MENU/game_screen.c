/**
 * @file game_screen.c
 * @brief Contém toda a lógica e desenho para a tela principal de gameplay.
 *
 * Este módulo é responsável por tudo que acontece quando o jogador está efetivamente
 * jogando: carregar o cômodo, verificar interações, e desenhar a cena do jogo e sua UI.
 */

#include "game_screen.h"
#include "defines.h"
#include "ui_helpers.h"   // Para usar DrawAnimatedButton
#include "menu_screen.h"  // Para poder chamar CarregarRecursosMenu na transição

#include <string.h> // Para strlen
#include <stdio.h>  // Para printf

#include "DescCarreg.h"

/**
 * @brief Carrega todos os recursos (texturas) necessários para a tela de jogo.
 * @param jogo Ponteiro para o estado geral do jogo.
 */
void CarregarRecursosJogo(EstadoJogo *jogo) {
    printf("Carregando recursos do Jogo...\n");
    // Carrega a textura do cômodo atual baseado no índice e no nome do arquivo definidos no estado do jogo.
    if (strlen(jogo->todos_os_comodos[jogo->indice_comodo_atual].arquivo_imagem_fundo) > 0) {
        jogo->texturaComodoAtual = LoadTexture(jogo->todos_os_comodos[jogo->indice_comodo_atual].arquivo_imagem_fundo);
    }
    // Carrega a textura do botão de voltar.
    jogo->recursos_jogo.botaoVoltar = LoadTexture("../Sprites/x.png");
}

/**
 * @brief Descarrega todos os recursos da tela de jogo para liberar memória.
 * @param jogo Ponteiro para o estado geral do jogo.
 */
void DescarregarRecursosJogo(EstadoJogo *jogo) {
    printf("Descarregando recursos do Jogo...\n");
    if (jogo->texturaComodoAtual.id > 0) {
        UnloadTexture(jogo->texturaComodoAtual);
    }
    if (jogo->recursos_jogo.botaoVoltar.id > 0) {
        UnloadTexture(jogo->recursos_jogo.botaoVoltar);
    }
}

/**
 * @brief Atualiza toda a lógica da tela de jogo a cada frame.
 *
 * Como você pediu, aqui está a explicação do botão de voltar:
 * A lógica dele é a mesma dos outros botões que fizemos. Primeiro, definimos sua
 * área de clique (hitbox). Depois, usamos um if/else para verificar se o mouse está
 * sobre essa área, atualizando o estado 'jogo->mouseSobreBotaoVoltar'.
 * Um segundo 'if' verifica se o mouse está sobre o botão E se o botão esquerdo foi
 * pressionado. Se sim, ele executa a importante "lógica de transição de tela":
 * 1. DescarregarRecursosJogo(jogo): Limpa da memória os recursos da tela atual (o jogo).
 * 2. CarregarRecursosMenu(jogo): Carrega na memória os recursos da próxima tela (o menu).
 * 3. jogo->screen = SCREEN_MENU: Finalmente, muda o estado para que o 'main' passe
 * a chamar as funções de update e draw do menu no próximo frame.
 *
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos A posição virtual do mouse na tela.
 */
void UpdateGameScreen(EstadoJogo *jogo, Vector2 mousePos) {

    // Define a posição e a área de clique (hitbox) do botão de voltar
    Vector2 posVoltar = {1870, 20}; // Posição no canto superior direito
    Rectangle hitboxBotaoVoltar = {
        posVoltar.x,
        posVoltar.y,
        (float)jogo->recursos_jogo.botaoVoltar.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->recursos_jogo.botaoVoltar.height * ESCALA_NORMAL_BOTAO
    };

    // Lógica de Hover: atualiza o estado se o mouse está sobre o botão
    if (CheckCollisionPointRec(mousePos, hitboxBotaoVoltar)) {
        jogo->mouseSobreBotaoVoltar = true;
    } else {
        jogo->mouseSobreBotaoVoltar = false;
    }

    // Lógica de Clique: se o mouse está sobre e o botão é clicado, executa a transição
    if (jogo->mouseSobreBotaoVoltar && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        DescarregarRecursosJogo(jogo);
        CarregarRecursosMenu(jogo);
        jogo->screen = SCREEN_MENU;
        // O return aqui é uma boa prática para parar de processar o resto do update desta tela,
        // já que estamos transicionando para outra.
        return;
    }

    // Lógica de Animação: atualiza a escala do botão para a animação suave
    float targetEscalaVoltar;
    if (jogo->mouseSobreBotaoVoltar) {
        targetEscalaVoltar = ESCALA_HOVER_BOTAO;
    } else {
        targetEscalaVoltar = ESCALA_NORMAL_BOTAO;
    }
    jogo->animatedEscalaVoltar += (targetEscalaVoltar - jogo->animatedEscalaVoltar) * VELOCIDADE_ANIM_BOTAO;

    // A LÓGICA DE ANIMAÇÃO DUPLICADA FOI REMOVIDA DAQUI!
}

/**
 * @brief Desenha todos os elementos visuais da tela de jogo.
 * @param jogo Ponteiro (const) para o estado do jogo.
 */
void DrawGameScreen(const EstadoJogo *jogo) {
    // Desenha o fundo da tela (o cômodo atual)
    if (jogo->texturaComodoAtual.id > 0) {
        DrawTexture(jogo->texturaComodoAtual, 0, 0, WHITE);
    }

    // Desenha o botão de voltar animado
    Vector2 posVoltar = { 1870, 20 };
    DrawAnimatedButton(jogo->recursos_jogo.botaoVoltar, posVoltar, jogo->animatedEscalaVoltar);

    // Placeholder para a UI do jogo
    DrawText("Comecou papais", 200, 20, 30, YELLOW);
}