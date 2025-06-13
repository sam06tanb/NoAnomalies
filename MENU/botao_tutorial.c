#include "botao_tutorial.h"
#include "defines.h"
#include "ui_helpers.h"
#include <stdio.h>

void UpdateBotaoTutorial(EstadoJogo *jogo, Vector2 mousePos, Vector2 position) {

    Rectangle hitboxTutorial = {
        position.x,
        position.y,
        (float)jogo->options.botaoTutorial.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->options.botaoTutorial.height * ESCALA_NORMAL_BOTAO
    };

    if (CheckCollisionPointRec(mousePos, hitboxTutorial)) {
        jogo->mouseSobreBotaoTutorial = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Botao Tutorial clicado!\n"); // Ação placeholder
        }
    } else {
        jogo->mouseSobreBotaoTutorial = false;
    }

    float targetEscalaTutorial;
    if (jogo->mouseSobreBotaoTutorial) {
        targetEscalaTutorial = ESCALA_HOVER_BOTAO;
    } else {
        targetEscalaTutorial = ESCALA_NORMAL_BOTAO;
    }
    jogo->animatedEscalaTutorial += (targetEscalaTutorial - jogo->animatedEscalaTutorial) * VELOCIDADE_ANIM_BOTAO;
}

void DrawBotaoTutorial(const EstadoJogo *jogo, Vector2 position) {

    DrawAnimatedButton(jogo->options.botaoTutorial, position, jogo->animatedEscalaTutorial);

}