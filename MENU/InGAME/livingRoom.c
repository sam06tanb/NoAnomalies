#include "livingRoom.h"
#include <stdio.h>

void UpdateSalaDeEstar(EstadoJogo *jogo, Vector2 mousePos) {
    // Ex: if (passou_10_segundos) { ativar_anomalia_faca_sumiu(jogo); }
    // Ex: if (CheckCollisionPointRec(mousePos, hitbox_panela)) { ... }
}

void DrawSalaDeEstar(const EstadoJogo *jogo) {

    if (jogo->texturaComodoAtual.id > 0) {
        DrawTexture(jogo->texturaComodoAtual, 0, 0, WHITE);
    } else {
        DrawText("ERRO: Textura da cozinha nao carregada!", 400, 500, 40, RED);
    }

    // TODO: No futuro, o desenho de anomalias visíveis na cozinha virá aqui.
    // Ex: if (faca_sumiu_ativa) { /* não desenha a faca */ }
}