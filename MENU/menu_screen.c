#include "menu_screen.h"
#include "defines.h"
#include <stdio.h>

void UpdateMenuScreen(EstadoJogo *jogo, Vector2 mousePos,
                      Vector2 posJogar, Vector2 posOpcoes, Vector2 posSair) {

    //hitbox do botao, pega altura e largura e multiplica pela escala de quando ele nao esta selecionado
    Rectangle hitboxBotaoJogar = {
        posJogar.x,
        posJogar.y,
        (float)jogo->menu.botaoJogar.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->menu.botaoJogar.height * ESCALA_NORMAL_BOTAO
    };

    //usa uma funcao da raylib para ver se o mouse está passando na hitbox do botao se ele estiver, mouseSobreBotaoJogar fica true, e tambem ativa um if
    //que diz que se o botao esquerdo do mouse for pressionado ele entra na tela do jogo
    if (CheckCollisionPointRec(mousePos, hitboxBotaoJogar)) {
        jogo->mouseSobreBotaoJogar = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->screen = SCREEN_GAME;
        }
    } else {
        jogo->mouseSobreBotaoJogar = false;
    }

    //aqui e onde a animacao do botao acontece, se mouseSobreBotaoJogar for true, então ele faz a variavel targetEscalaJogar receber(=) ESCALA_HOVER_BOTAO
    //que e basicamente o tamanho do botao quando voce passa o mouse em cima
    float targetEscalaJogar;
    if (jogo->mouseSobreBotaoJogar) {
        targetEscalaJogar = ESCALA_HOVER_BOTAO; // 1.65f
    } else {
        targetEscalaJogar = ESCALA_NORMAL_BOTAO; // 1.3f
    }

    //aqui ele faz a variavel animatedEscalaJogar, que se refere a animacao do botao jogar, receber e somar(+=) a variavel que foi testada acima(targetEscalaJogar)
    // - animatedEscalaJogar * VELOCIDADE_ANIM_BOTAO(essa variavel e a velocidade da animacao)
    jogo->animatedEscalaJogar += (targetEscalaJogar - jogo->animatedEscalaJogar) * VELOCIDADE_ANIM_BOTAO; // 0.08f

    Rectangle hitboxBotaoOpcoes = {
        posOpcoes.x,
        posOpcoes.y,
        (float)jogo->menu.botaoOpcoes.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->menu.botaoOpcoes.height * ESCALA_NORMAL_BOTAO
    };

    if (CheckCollisionPointRec(mousePos, hitboxBotaoOpcoes)) {
        jogo->mouseSobreBotaoOpcoes = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->popupOpcoesVisivel = true;

            jogo->mouseSobreBotaoJogar = false;
            jogo->mouseSobreBotaoOpcoes = false;
            jogo->mouseSobreBotaoSair = false;
        }
    } else {
        jogo->mouseSobreBotaoOpcoes = false;
    }

    float targetEscalaOpcoes;
    if (jogo->mouseSobreBotaoOpcoes) {
        targetEscalaOpcoes = ESCALA_HOVER_BOTAO;
    } else {
        targetEscalaOpcoes = ESCALA_NORMAL_BOTAO;
    }
    jogo->animatedEscalaOpcoes += (targetEscalaOpcoes - jogo->animatedEscalaOpcoes) * VELOCIDADE_ANIM_BOTAO;

    Rectangle hitboxBotaoSair = {
        posSair.x,
        posSair.y,
        (float)jogo->menu.botaoSair.width * ESCALA_NORMAL_BOTAO,
        (float)jogo->menu.botaoSair.height * ESCALA_NORMAL_BOTAO
    };

    if (CheckCollisionPointRec(mousePos, hitboxBotaoSair)) {
        jogo->mouseSobreBotaoSair = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->screen = SCREEN_SAIR;
        }
    } else {
        jogo->mouseSobreBotaoSair = false;
    }

    float targetEscalaSair;
    if (jogo->mouseSobreBotaoSair) {
        targetEscalaSair = ESCALA_HOVER_BOTAO;
    } else {
        targetEscalaSair = ESCALA_NORMAL_BOTAO;
    }
    jogo->animatedEscalaSair += (targetEscalaSair - jogo->animatedEscalaSair) * VELOCIDADE_ANIM_BOTAO;
}


void DrawMenuScreen(const EstadoJogo *jogo, Vector2 tituloPos,
                    Vector2 posJogar, Vector2 posOpcoes, Vector2 posSair) {

    DrawTexture(jogo->menu.fundo, 0, 0, WHITE);
    DrawTextureV(jogo->menu.titulo, tituloPos, WHITE);

    if (jogo->menu.botaoJogar.id > 0) {
        Rectangle sourceRec = { 0.0f, 0.0f, (float)jogo->menu.botaoJogar.width, (float)jogo->menu.botaoJogar.height };
        Vector2 origin = {0.0f, 0.0f};

        float larguraOriginal = (float)jogo->menu.botaoJogar.width;
        float alturaOriginal = (float)jogo->menu.botaoJogar.height;

        float larguraNormal = larguraOriginal * ESCALA_NORMAL_BOTAO;
        float alturaNormal = alturaOriginal * ESCALA_NORMAL_BOTAO;

        float larguraAnimada = larguraOriginal * jogo->animatedEscalaJogar;
        float alturaAnimada = alturaOriginal * jogo->animatedEscalaJogar;

        float offsetX = (larguraAnimada - larguraNormal) / 2.0f;
        float offsetY = (alturaAnimada - alturaNormal) / 2.0f;

        float posXDest = posJogar.x - offsetX;
        float posYDest = posJogar.y - offsetY;

        Rectangle destRec = { posXDest, posYDest, larguraAnimada, alturaAnimada };
        DrawTexturePro(jogo->menu.botaoJogar, sourceRec, destRec, origin, 0.0f, WHITE);
    }

    if (jogo->menu.botaoOpcoes.id > 0) {
        Rectangle sourceRec = { 0.0f, 0.0f, (float)jogo->menu.botaoOpcoes.width, (float)jogo->menu.botaoOpcoes.height };
        Vector2 origin = {0.0f, 0.0f};

        float larguraOriginal = (float)jogo->menu.botaoOpcoes.width;
        float alturaOriginal = (float)jogo->menu.botaoOpcoes.height;

        float larguraNormal = larguraOriginal * ESCALA_NORMAL_BOTAO;
        float alturaNormal = alturaOriginal * ESCALA_NORMAL_BOTAO;

        float larguraAnimada = larguraOriginal * jogo->animatedEscalaOpcoes;
        float alturaAnimada = alturaOriginal * jogo->animatedEscalaOpcoes;

        float offsetX = (larguraAnimada - larguraNormal) / 2.0f;
        float offsetY = (alturaAnimada - alturaNormal) / 2.0f;

        float posXDest = posOpcoes.x - offsetX;
        float posYDest = posOpcoes.y - offsetY;

        Rectangle destRec = { posXDest, posYDest, larguraAnimada, alturaAnimada };
        DrawTexturePro(jogo->menu.botaoOpcoes, sourceRec, destRec, origin, 0.0f, WHITE);
    }


    if (jogo->menu.botaoSair.id > 0) {
        Rectangle sourceRec = { 0.0f, 0.0f, (float)jogo->menu.botaoSair.width, (float)jogo->menu.botaoSair.height };
        Vector2 origin = {0.0f, 0.0f};

        float larguraOriginal = (float)jogo->menu.botaoSair.width;
        float alturaOriginal = (float)jogo->menu.botaoSair.height;

        float larguraNormal = larguraOriginal * ESCALA_NORMAL_BOTAO;
        float alturaNormal = alturaOriginal * ESCALA_NORMAL_BOTAO;

        float larguraAnimada = larguraOriginal * jogo->animatedEscalaSair;
        float alturaAnimada = alturaOriginal * jogo->animatedEscalaSair;
        float offsetX = (larguraAnimada - larguraNormal) / 2.0f;
        float offsetY = (alturaAnimada - alturaNormal) / 2.0f;

        float posXDest = posSair.x - offsetX;
        float posYDest = posSair.y - offsetY;

        Rectangle destRec = { posXDest, posYDest, larguraAnimada, alturaAnimada };
        DrawTexturePro(jogo->menu.botaoSair, sourceRec, destRec, origin, 0.0f, WHITE);
    }
}