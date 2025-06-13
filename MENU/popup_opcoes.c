
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

    Vector2 posAplicar = {1100, 925};
    Rectangle hitBoxAplicar = {
        posAplicar.x,
        posAplicar.y,
        (float)jogo->options.botaoAplicar.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->options.botaoAplicar.height * ESCALA_NORMAL_BOTAO
    };

    if (CheckCollisionPointRec(mousePos, hitBoxAplicar)) {
        jogo->mouseSobreBotaoAplicar = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Aplicando resolucao!\n");

            Vector2 novaResolucao = jogo->resolucoesDisponiveis[jogo->indiceResolucoesAtual];
            int novaLargura = (int)novaResolucao.x;
            int novaAltura = (int)novaResolucao.y;

            SetWindowSize(novaLargura, novaAltura);

            int larguraMonitor = GetMonitorWidth(0);
            int alturaMonitor = GetMonitorHeight(0);

            int novoPosX = (larguraMonitor - novaLargura) / 2;
            int novoPosY = (alturaMonitor - novaAltura) / 2;

            SetWindowPosition(novoPosX, novoPosY);

            jogo->popupOpcoesVisivel = false;
        }
    } else {
        jogo->mouseSobreBotaoAplicar = false;
    }

    float targetEscalaAplicar;
    if (jogo->mouseSobreBotaoAplicar) {
        targetEscalaAplicar = ESCALA_NORMAL_BOTAO;
    } else {
        targetEscalaAplicar = ESCALA_NORMAL_BOTAO;
    }

    jogo->animatedEscalaAplicar += (targetEscalaAplicar - jogo->animatedEscalaAplicar) * VELOCIDADE_ANIM_BOTAO;

    float painelLargura = (float)jogo->options.painelPopupOpcoes.width;
    float painelAltura = (float)jogo->options.painelPopupOpcoes.height;
    Vector2 popupPainelPos = {
        (float)VIRTUAL_SCREEN_WIDTH/ 2 - painelLargura / 2,
        (float)VIRTUAL_SCREEN_HEIGHT / 2 - painelAltura / 2
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
   Vector2 posSetaEsquerda = { popupPainelPos.x + 150, popupPainelPos.y + 450 };
   Vector2 posSetaDireita = { popupPainelPos.x + painelLargura - 150 - jogo->options.setaDireita.width, posSetaEsquerda.y};

   Rectangle hitboxSetaEsquerda = { posSetaEsquerda.x, posSetaEsquerda.y, (float)jogo->options.setaEsquerda.width, (float)jogo->options.setaEsquerda.height};
   Rectangle hitboxSetaDireita = { posSetaDireita.x, posSetaDireita.y, (float)jogo->options.setaDireita.width, (float)jogo->options.setaDireita.height};

    if (CheckCollisionPointRec(mousePos, hitboxSetaEsquerda)) {
        // (Aqui você poderia adicionar um efeito de hover para a seta se quisesse)
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->indiceResolucoesAtual--;
            if (jogo->indiceResolucoesAtual < 0) {
                jogo->indiceResolucoesAtual = NUM_RESOLUCOES - 1;
            }
        }
    }

    if (CheckCollisionPointRec(mousePos, hitboxSetaDireita)) {
        // (Efeito de hover para a seta direita)
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->indiceResolucoesAtual++;
            if (jogo->indiceResolucoesAtual >= NUM_RESOLUCOES) {
                jogo->indiceResolucoesAtual = 0;
            }
        }
    }

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
    DrawRectangle(0, 0, VIRTUAL_SCREEN_WIDTH, VIRTUAL_SCREEN_HEIGHT, Fade(BLACK, 0.7f));

    // --- Desenho do Painel e Botões ---
    Vector2 painelPos = { (float)VIRTUAL_SCREEN_WIDTH/2 - (float)jogo->options.painelPopupOpcoes.width/2, (float)VIRTUAL_SCREEN_HEIGHT/2 - (float)jogo->options.painelPopupOpcoes.height/2 };
    DrawTextureV(jogo->options.painelPopupOpcoes, painelPos, WHITE);

    if (jogo->options.botaoFecharPopup.id > 0) {
        // Botão Fechar
        Vector2 posFechar = { painelPos.x + (float)jogo->options.painelPopupOpcoes.width - (float)jogo->options.botaoFecharPopup.width - 20, painelPos.y + 20 };
        DrawTextureV(jogo->options.botaoFecharPopup, posFechar, WHITE);
    }

    Vector2 posAplicar = {1100, 925};
    DrawAnimatedButton(jogo->options.botaoAplicar, posAplicar, jogo->animatedEscalaAplicar);

    //SETAS E RESOLUCAO
    Vector2 posSetaEsquerda = { painelPos.x + 150, painelPos.y + 450 };
    Vector2 posSetaDireita = { painelPos.x + (float)jogo->options.painelPopupOpcoes.width - 150 - (float)jogo->options.setaDireita.width, posSetaEsquerda.y };

    DrawTextureV(jogo->options.setaEsquerda, posSetaEsquerda, WHITE);
    DrawTextureV(jogo->options.setaDireita, posSetaDireita, WHITE);

    Texture2D spriteResAtual = jogo->options.spritesResolucao[jogo->indiceResolucoesAtual];

    if (spriteResAtual.id > 0) {
        float meioDoEspacoEntreSetas = posSetaEsquerda.x + jogo->options.setaEsquerda.width +
                                       ((posSetaDireita.x - (posSetaEsquerda.x + jogo->options.setaEsquerda.width)) / 2.0f);
        Vector2 posSpriteResolucao = {
            meioDoEspacoEntreSetas - (float)spriteResAtual.width / 2.0f,
            posSetaEsquerda.y - 30
        };
        DrawTextureV(spriteResAtual, posSpriteResolucao, WHITE);
    }

    Vector2 posVolume = { painelPos.x + 150, painelPos.y + 100 };
    Vector2 posTutorial = { painelPos.x + 150, painelPos.y + 700 };
    DrawAnimatedButton(jogo->options.botaoVolume, posVolume, jogo->animatedEscalaVolume);
    DrawAnimatedButton(jogo->options.botaoTutorial, posTutorial, jogo->animatedEscalaTutorial);

}
