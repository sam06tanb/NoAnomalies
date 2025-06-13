// seletor_resolucao.c
#include "seletor_resolucao.h"
#include "defines.h"

void UpdateSeletorResolucao(EstadoJogo *jogo, Vector2 mousePos, Vector2 painelPos) {

    float painelLargura = (float)jogo->options.painelPopupOpcoes.width;

    Vector2 posSetaEsquerda = {painelPos.x + 150, painelPos.y + 450};
    Vector2 posSetaDireita = {
        painelPos.x + painelLargura - 150 - jogo->options.setaDireita.width,
        posSetaEsquerda.y
    };

    Rectangle hitboxSetaEsquerda = {
        posSetaEsquerda.x, posSetaEsquerda.y, (float)jogo->options.setaEsquerda.width,
        (float)jogo->options.setaEsquerda.height
    };
    Rectangle hitboxSetaDireita = {
        posSetaDireita.x, posSetaDireita.y, (float)jogo->options.setaDireita.width,
        (float)jogo->options.setaDireita.height
    };

    if (CheckCollisionPointRec(mousePos, hitboxSetaEsquerda)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->indiceResolucoesAtual--;
            if (jogo->indiceResolucoesAtual < 0) {
                jogo->indiceResolucoesAtual = NUM_RESOLUCOES - 1;
            }
        }
    }

    if (CheckCollisionPointRec(mousePos, hitboxSetaDireita)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->indiceResolucoesAtual++;
            if (jogo->indiceResolucoesAtual >= NUM_RESOLUCOES) {
                jogo->indiceResolucoesAtual = 0;
            }
        }
    }
}


void DrawSeletorResolucao(const EstadoJogo *jogo, Vector2 painelPos) {

    Vector2 posSetaEsquerda = {painelPos.x + 150, painelPos.y + 450};
    Vector2 posSetaDireita = {
        painelPos.x + (float)jogo->options.painelPopupOpcoes.width - 150 - (float)jogo->options.setaDireita.width,
        posSetaEsquerda.y
    };

    DrawTextureV(jogo->options.setaEsquerda, posSetaEsquerda, WHITE);
    DrawTextureV(jogo->options.setaDireita, posSetaDireita, WHITE);

    Texture2D spriteResAtual = jogo->options.spritesResolucao[jogo->indiceResolucoesAtual];

    if (spriteResAtual.id > 0) {
        float meioDoEspacoEntreSetas = posSetaEsquerda.x + jogo->options.setaEsquerda.width +
                                       ((posSetaDireita.x - (posSetaEsquerda.x + jogo->options.setaEsquerda.width)) / 2.0f);
        Vector2 posSpriteResolucao = {
            meioDoEspacoEntreSetas - (float) spriteResAtual.width / 2.0f,
            posSetaEsquerda.y - 30 // Ajuste fino da posição Y do texto/sprite
        };
        DrawTextureV(spriteResAtual, posSpriteResolucao, WHITE);
    }
}