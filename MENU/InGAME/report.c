
#include "raylib.h"
#include "defines.h"
#include "report.h"
#include "ui_helpers.h"
#include <stdio.h>


void UpdateReport(EstadoJogo *jogo, Vector2 mousePos) {

    Vector2 posReport = { 15, 630 };

    Rectangle hitboxReport = {
        posReport.x + 140,
        posReport.y + 30,
        (float)jogo->recursos_jogo.botaoReport.width * 0.6f,
        (float)jogo->recursos_jogo.botaoReport.height * 0.6f
    };

    if (CheckCollisionPointRec(mousePos, hitboxReport)) {
          jogo->mouseSobreBotaoReport = true;
    } else {
          jogo->mouseSobreBotaoReport = false;
    }

    if(jogo->mouseSobreBotaoReport && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        printf("Botao report detected\n");
    }

    float targetEscalaReport;
    if(jogo->mouseSobreBotaoReport) {
       targetEscalaReport = 0.8f;
    } else {
       targetEscalaReport = 0.6f;
    }

    jogo->animatedEscalaReport += (targetEscalaReport - jogo->animatedEscalaReport) * VELOCIDADE_ANIM_BOTAO;
}


void DrawReport(const EstadoJogo *jogo) {

    Vector2 posReport = { 15, 630 };

    DrawAnimatedButton(jogo->recursos_jogo.botaoReport, posReport, jogo->animatedEscalaReport);

}