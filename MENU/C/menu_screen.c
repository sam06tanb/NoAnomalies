/**
 * @file menu_screen.c
 * @brief Contém a lógica de Update e Desenho para a tela do Menu Principal.
 *
 * Este arquivo é responsável por gerenciar todas as interações e elementos visuais
 * da tela de menu, incluindo os botões "Jogar", "Opções" e "Sair".
 */

#include "menu_screen.h"
#include "game_screen.h"     // Incluído para poder chamar as funções de carregar/descarregar recursos do jogo
#include "DescCarreg.h"      // Incluído para as suas funções de Carregar/Descarregar
#include "defines.h"
#include "ui_helpers.h"      // Incluído para usar a função DrawAnimatedButton

/**
 * @brief Atualiza o estado de todos os elementos interativos da tela de menu a cada frame.
 *
 * A função segue um padrão repetido para cada botão ("Jogar", "Opções", "Sair"):
 * 1. Calcula a área de clique (hitbox) do botão.
 * 2. Verifica se o mouse está sobre a hitbox para atualizar o estado de 'hover'.
 * 3. Se o mouse estiver sobre o botão, verifica se houve um clique e executa a ação correspondente
 * (mudar de tela, abrir pop-up ou fechar o jogo).
 * 4. Atualiza a variável de escala animada do botão para criar o efeito suave de crescer/encolher.
 *
 * @param jogo Ponteiro para o estado geral do jogo.
 * @param mousePos A posição virtual do mouse na tela.
 * @param posJogar A posição base do botão "Jogar".
 * @param posOpcoes A posição base do botão "Opções".
 * @param posSair A posição base do botão "Sair".
 */
void UpdateMenuScreen(EstadoJogo *jogo, Vector2 mousePos, Vector2 posJogar, Vector2 posOpcoes, Vector2 posSair) {

    // --- Lógica do Botão JOGAR ---
    Rectangle hitboxBotaoJogar = {
        posJogar.x,
        posJogar.y,
        (float)jogo->menu.botaoJogar.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->menu.botaoJogar.height * ESCALA_NORMAL_BOTAO
    };
    if (CheckCollisionPointRec(mousePos, hitboxBotaoJogar)) {
        jogo->mouseSobreBotaoJogar = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            DescarregarRecursosMenu(jogo);
            CarregarRecursosJogo(jogo);
            jogo->screen = SCREEN_GAME;
        }
    } else {
        jogo->mouseSobreBotaoJogar = false;
    }
    float targetEscalaJogar;
    if (jogo->mouseSobreBotaoJogar) { targetEscalaJogar = ESCALA_HOVER_BOTAO; } else { targetEscalaJogar = ESCALA_NORMAL_BOTAO; }
    jogo->animatedEscalaJogar += (targetEscalaJogar - jogo->animatedEscalaJogar) * VELOCIDADE_ANIM_BOTAO;


    // --- Lógica do Botão OPÇÕES ---
    Rectangle hitboxBotaoOpcoes = {posOpcoes.x, posOpcoes.y, (float)jogo->menu.botaoOpcoes.width * ESCALA_NORMAL_BOTAO, (float)jogo->menu.botaoOpcoes.height * ESCALA_NORMAL_BOTAO};
    if (CheckCollisionPointRec(mousePos, hitboxBotaoOpcoes)) {
        jogo->mouseSobreBotaoOpcoes = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->popupOpcoesVisivel = true;
        }
    } else {
        jogo->mouseSobreBotaoOpcoes = false;
    }
    float targetEscalaOpcoes;
    if (jogo->mouseSobreBotaoOpcoes) { targetEscalaOpcoes = ESCALA_HOVER_BOTAO; } else { targetEscalaOpcoes = ESCALA_NORMAL_BOTAO; }
    jogo->animatedEscalaOpcoes += (targetEscalaOpcoes - jogo->animatedEscalaOpcoes) * VELOCIDADE_ANIM_BOTAO;


    // --- Lógica do Botão SAIR ---
    Rectangle hitboxBotaoSair = {posSair.x, posSair.y, (float)jogo->menu.botaoSair.width * ESCALA_NORMAL_BOTAO, (float)jogo->menu.botaoSair.height * ESCALA_NORMAL_BOTAO};
    if (CheckCollisionPointRec(mousePos, hitboxBotaoSair)) {
        jogo->mouseSobreBotaoSair = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            CloseWindow(); // Forma mais limpa de fechar o jogo
        }
    } else {
        jogo->mouseSobreBotaoSair = false;
    }
    float targetEscalaSair;
    if (jogo->mouseSobreBotaoSair) { targetEscalaSair = ESCALA_HOVER_BOTAO; } else { targetEscalaSair = ESCALA_NORMAL_BOTAO; }
    jogo->animatedEscalaSair += (targetEscalaSair - jogo->animatedEscalaSair) * VELOCIDADE_ANIM_BOTAO;
}

void DrawMenuScreen(const EstadoJogo *jogo, Vector2 tituloPos,
                    Vector2 posJogar, Vector2 posOpcoes, Vector2 posSair) {

    // Desenha os elementos estáticos
    DrawTexture(jogo->menu.fundo, 0, 0, WHITE);
    DrawTextureV(jogo->menu.titulo, tituloPos, WHITE);

    // Usa a função auxiliar para desenhar cada botão animado
    DrawAnimatedButton(jogo->menu.botaoJogar, posJogar, jogo->animatedEscalaJogar);
    DrawAnimatedButton(jogo->menu.botaoOpcoes, posOpcoes, jogo->animatedEscalaOpcoes);
    DrawAnimatedButton(jogo->menu.botaoSair, posSair, jogo->animatedEscalaSair);
}