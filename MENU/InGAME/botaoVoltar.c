#include "botaoVoltar.h"

#include <DescCarreg.h>

#include "defines.h"
#include "ui_helpers.h"
#include "game_screen.h"
#include "menu_screen.h"


void UpdateBotaoVoltar(EstadoJogo *jogo, Vector2 mousePos) {

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

}

void DrawBotaoVoltar(const EstadoJogo *jogo) {

    Vector2 posVoltar = { 1870, 20 };
    DrawAnimatedButton(jogo->recursos_jogo.botaoVoltar, posVoltar, jogo->animatedEscalaVoltar);

}