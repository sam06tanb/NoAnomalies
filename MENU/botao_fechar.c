#include "botao_fechar.h"

void UpdateBotaoFechar(EstadoJogo *jogo, Vector2 mousePos, Vector2 position) {

    Rectangle hitboxBotaoFechar = {
        position.x,
        position.y,
        (float)jogo->options.botaoFecharPopup.width,
        (float)jogo->options.botaoFecharPopup.height
    };

    if (CheckCollisionPointRec(mousePos, hitboxBotaoFechar)) {
        jogo->mouseSobreBotaoFechar = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->popupOpcoesVisivel = false;
        }
    } else {
        jogo->mouseSobreBotaoFechar = false;
    }
}

void DrawBotaoFechar(const EstadoJogo *jogo, Vector2 position) {

    if (jogo->options.botaoFecharPopup.id > 0) {
        DrawTextureV(jogo->options.botaoFecharPopup, position, WHITE);
    }
}