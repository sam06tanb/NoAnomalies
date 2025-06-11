
#include "popup_opcoes.h"

#include <stdio.h>

#include "defines.h"

void DrawAnimatedButton(Texture2D texture, Vector2 position, float animatedScale) {
    if (texture.id <= 0) return;

    float larguraOriginal = (float)texture.width;
    float alturaOriginal = (float)texture.height;
    float larguraNormal = larguraOriginal * ESCALA_NORMAL_BOTAO;
    float alturaNormal = alturaOriginal * ESCALA_NORMAL_BOTAO;
    float larguraAnimada = larguraOriginal * animatedScale;
    float alturaAnimada = alturaOriginal * animatedScale;
    float offsetX = (larguraAnimada - larguraNormal) / 2.0f;
    float offsetY = (alturaAnimada - alturaNormal) / 2.0f;
    float posXDest = position.x - offsetX;
    float posYDest = position.y - offsetY;

    Rectangle sourceRec = {0, 0, larguraOriginal, alturaOriginal};
    Rectangle destRec = {posXDest, posYDest, larguraAnimada, alturaAnimada};
    DrawTexturePro(texture, sourceRec, destRec, (Vector2){0,0}, 0.0f, WHITE);
}

void UpdatePopupOpcoes(EstadoJogo *jogo, Vector2 mousePos) {

if (jogo->popupOpcoesVisivel) {
    float painelLargura = (float)jogo->options.painelPopupOpcoes.width;
    float painelAltura = (float)jogo->options.painelPopupOpcoes.height;
    Vector2 popupPainelPos = {
        (float)GetScreenWidth() / 2 - painelLargura / 2,
        (float)GetScreenHeight() / 2 - painelAltura / 2
    };

    //FECHAR
    Vector2 posFechar = { popupPainelPos.x + painelLargura - jogo->options.botaoFecharPopup.width - 10, popupPainelPos.y + 10 };

    Rectangle hitboxBotaoFechar = {
        posFechar.x,
        posFechar.y,
        (float)jogo->options.botaoFecharPopup.width,
        (float)jogo->options.botaoFecharPopup.height
    };

    if (CheckCollisionPointRec(mousePos, hitboxBotaoFechar)) {
        jogo->mouseSobreBotaoFechar = true;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->popupOpcoesVisivel = false;
        }

    } else {
        jogo ->mouseSobreBotaoFechar = false;
    }

    //BOTAO VOLUME
    Vector2 posVolume = { popupPainelPos.x + 150, popupPainelPos.y + 100 };
    Rectangle hitboxVolume = {
        posVolume.x,
        posVolume.y,
        (float)jogo->options.botaoVolume.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->options.botaoVolume.height * ESCALA_NORMAL_BOTAO
    };

    if (CheckCollisionPointRec(mousePos, hitboxVolume)) {
        jogo->mouseSobreBotaoVolume = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Botao volume clicado!\n");
        }
    } else {
        jogo->mouseSobreBotaoVolume = false;
    }
    float targetEscalaVolume;
    if (jogo->mouseSobreBotaoVolume) { targetEscalaVolume = ESCALA_HOVER_BOTAO; } else { targetEscalaVolume = ESCALA_NORMAL_BOTAO;}
    jogo->animatedEscalaVolume += (targetEscalaVolume - jogo->animatedEscalaVolume) * VELOCIDADE_ANIM_BOTAO;


    //BOTAO RESOLUCAO
    Vector2 posResolucao = { popupPainelPos.x + 150, popupPainelPos.y + 400 };
    Rectangle hitboxResolucao = {
        posResolucao.x,
        posResolucao.y,
        (float)jogo->options.botaoResolucao.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->options.botaoResolucao.height * ESCALA_NORMAL_BOTAO };

    if (CheckCollisionPointRec(mousePos, hitboxResolucao)) {
        jogo->mouseSobreBotaoResolucao = true;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Botao RESOLUCAO clicado!\n"); // Ação placeholder
        }
    } else {
        jogo->mouseSobreBotaoResolucao = false;
    }

    float targetEscalaResolucao;
    if (jogo->mouseSobreBotaoResolucao) { targetEscalaResolucao = ESCALA_HOVER_BOTAO; } else { targetEscalaResolucao = ESCALA_NORMAL_BOTAO; }
    jogo->animatedEscalaResolucao += (targetEscalaResolucao - jogo->animatedEscalaResolucao) * VELOCIDADE_ANIM_BOTAO;

    //BOTAO HOW TO PLAY
    Vector2 posTutorial = { popupPainelPos.x + 150, popupPainelPos.y + 700 };
    Rectangle hitboxTutorial  = {
        posTutorial .x,
        posTutorial .y,
        (float)jogo->options.botaoTutorial.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->options.botaoTutorial.height * ESCALA_NORMAL_BOTAO };

    if (CheckCollisionPointRec(mousePos, hitboxTutorial )) {
        jogo->mouseSobreBotaoTutorial  = true;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Botao Tutorial  clicado!\n");
        }
    } else {
        jogo->mouseSobreBotaoTutorial  = false;
    }

    float targetEscalaTutorial ;
    if (jogo->mouseSobreBotaoTutorial ) { targetEscalaTutorial  = ESCALA_HOVER_BOTAO; } else { targetEscalaTutorial  = ESCALA_NORMAL_BOTAO; }
    jogo->animatedEscalaTutorial  += (targetEscalaTutorial  - jogo->animatedEscalaTutorial ) * VELOCIDADE_ANIM_BOTAO;

   }
}

void DrawPopupOpcoes(const EstadoJogo *jogo) {

    // Escurece a tela de fundo
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.7f));

    // --- Desenho do Painel e Botões ---
    Vector2 painelPos = {
        (float)GetScreenWidth()/2 - (float)jogo->options.painelPopupOpcoes.width/2,
        (float)GetScreenHeight()/2 - (float)jogo->options.painelPopupOpcoes.height/2
    };
    DrawTextureV(jogo->options.painelPopupOpcoes, painelPos, WHITE);


    Vector2 posVolume = { painelPos.x + 150, painelPos.y + 100 };
    Vector2 posResolucao = { painelPos.x + 150, painelPos.y + 400 };
    Vector2 posTutorial = { painelPos.x + 150, painelPos.y + 700 };

    DrawAnimatedButton(jogo->options.botaoVolume, posVolume, jogo->animatedEscalaVolume);
    DrawAnimatedButton(jogo->options.botaoResolucao, posResolucao, jogo->animatedEscalaResolucao);
    DrawAnimatedButton(jogo->options.botaoTutorial, posTutorial, jogo->animatedEscalaTutorial);

    if (jogo->options.botaoFecharPopup.id > 0) {
        // Botão Fechar
        Vector2 posFechar = { painelPos.x + (float)jogo->options.painelPopupOpcoes.width - (float)jogo->options.botaoFecharPopup.width - 20, painelPos.y + 20 };
        DrawTextureV(jogo->options.botaoFecharPopup, posFechar, WHITE);
    }


}
