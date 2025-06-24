// painel_reporte.c
#include "painel_reporte.h"
#include "defines.h"
#include "ui_helpers.h"
#include <stdio.h>

void UpdatePainelReporte(EstadoJogo *jogo, Vector2 mousePos) {


    Vector2 painelPos = { 615, 25 };

    Vector2 posBotaoIntruso = { painelPos.x + 95, painelPos.y + 100 };
    Vector2 posBotaoMoveu = { painelPos.x + 175, posBotaoIntruso.y + 235 };
    Vector2 posBotaoApareceu = { painelPos.x + 175, posBotaoMoveu.y + 235 };
    Vector2 posBotaoSumiu = { painelPos.x + 175, posBotaoApareceu.y + 235 };

    Rectangle hitboxIntruso = { posBotaoIntruso.x, posBotaoIntruso.y, (float)jogo->recursos_reporte.botaoAnomaliaIntruso.width * ESCALA_NORMAL_BOTAO, (float)jogo->recursos_reporte.botaoAnomaliaIntruso.height * ESCALA_NORMAL_BOTAO };
    if (CheckCollisionPointRec(mousePos, hitboxIntruso)) {
        jogo->mouseSobreBotaoIntruso = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Reportou anomalia do tipo: INTRUSO\n");
            jogo->painelReporteVisivel = false;
        }
    } else {
        jogo->mouseSobreBotaoIntruso = false;
    }
    float targetEscalaIntruso;
    if (jogo->mouseSobreBotaoIntruso) { targetEscalaIntruso = ESCALA_HOVER_BOTAO; } else { targetEscalaIntruso = ESCALA_NORMAL_BOTAO; }
    jogo->animatedEscalaIntruso += (targetEscalaIntruso - jogo->animatedEscalaIntruso) * VELOCIDADE_ANIM_BOTAO;

    // --- Lógica do Botão MOVEU ---
    Rectangle hitboxMoveu = { posBotaoMoveu.x, posBotaoMoveu.y, (float)jogo->recursos_reporte.botaoAnomaliaMoveu.width * ESCALA_NORMAL_BOTAO, (float)jogo->recursos_reporte.botaoAnomaliaMoveu.height * ESCALA_NORMAL_BOTAO };
    if (CheckCollisionPointRec(mousePos, hitboxMoveu)) {
        jogo->mouseSobreBotaoMoveu = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Reportou anomalia do tipo: MOVEU\n");
            jogo->painelReporteVisivel = false;
        }
    } else {
        jogo->mouseSobreBotaoMoveu = false;
    }
    float targetEscalaMoveu;
    if (jogo->mouseSobreBotaoMoveu) { targetEscalaMoveu = ESCALA_HOVER_BOTAO; } else { targetEscalaMoveu = ESCALA_NORMAL_BOTAO; }
    jogo->animatedEscalaMoveu += (targetEscalaMoveu - jogo->animatedEscalaMoveu) * VELOCIDADE_ANIM_BOTAO;

    // --- Lógica do Botão APARECEU ---
    Rectangle hitboxApareceu = { posBotaoApareceu.x, posBotaoApareceu.y, (float)jogo->recursos_reporte.botaoAnomaliaApareceu.width * ESCALA_NORMAL_BOTAO, (float)jogo->recursos_reporte.botaoAnomaliaApareceu.height * ESCALA_NORMAL_BOTAO };
    if (CheckCollisionPointRec(mousePos, hitboxApareceu)) {
        jogo->mouseSobreBotaoApareceu = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Reportou anomalia do tipo: APARECEU\n");
            jogo->painelReporteVisivel = false;
        }
    } else {
        jogo->mouseSobreBotaoApareceu = false;
    }
    float targetEscalaApareceu;
    if (jogo->mouseSobreBotaoApareceu) { targetEscalaApareceu = ESCALA_HOVER_BOTAO; } else { targetEscalaApareceu = ESCALA_NORMAL_BOTAO; }
    jogo->animatedEscalaApareceu += (targetEscalaApareceu - jogo->animatedEscalaApareceu) * VELOCIDADE_ANIM_BOTAO;

    // --- Lógica do Botão SUMIU ---
    Rectangle hitboxSumiu = { posBotaoSumiu.x, posBotaoSumiu.y, (float)jogo->recursos_reporte.botaoAnomaliaSumiu.width * ESCALA_NORMAL_BOTAO, (float)jogo->recursos_reporte.botaoAnomaliaSumiu.height * ESCALA_NORMAL_BOTAO };
    if (CheckCollisionPointRec(mousePos, hitboxSumiu)) {
        jogo->mouseSobreBotaoSumiu = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Reportou anomalia do tipo: SUMIU\n");
            jogo->painelReporteVisivel = false;
        }
    } else {
        jogo->mouseSobreBotaoSumiu = false;
    }
    float targetEscalaSumiu;
    if (jogo->mouseSobreBotaoSumiu) { targetEscalaSumiu = ESCALA_HOVER_BOTAO; } else { targetEscalaSumiu = ESCALA_NORMAL_BOTAO; }
    jogo->animatedEscalaSumiu += (targetEscalaSumiu - jogo->animatedEscalaSumiu) * VELOCIDADE_ANIM_BOTAO;
}


void DrawPainelReporte(const EstadoJogo *jogo) {
    // Posição do painel (deve ser a mesma do Update)
    Vector2 painelPos = { 615, 25 };

    // --- DESENHA A BASE PRIMEIRO ---

    DrawTextureV(jogo->recursos_reporte.painelReporte, painelPos, WHITE);

    // --- DESENHA OS BOTÕES POR CIMA DO PAINEL ---
    Vector2 posBotaoIntruso = { painelPos.x + 95, painelPos.y + 100 };
    Vector2 posBotaoMoveu = { painelPos.x + 175, posBotaoIntruso.y + 235 };
    Vector2 posBotaoApareceu = { painelPos.x + 175, posBotaoMoveu.y + 235 };
    Vector2 posBotaoSumiu = { painelPos.x + 175, posBotaoApareceu.y + 235 };

    // Chama a função ajudante para desenhar cada botão
    DrawAnimatedButton(jogo->recursos_reporte.botaoAnomaliaIntruso, posBotaoIntruso, jogo->animatedEscalaIntruso);
    DrawAnimatedButton(jogo->recursos_reporte.botaoAnomaliaMoveu, posBotaoMoveu, jogo->animatedEscalaMoveu);
    DrawAnimatedButton(jogo->recursos_reporte.botaoAnomaliaApareceu, posBotaoApareceu, jogo->animatedEscalaApareceu);
    DrawAnimatedButton(jogo->recursos_reporte.botaoAnomaliaSumiu, posBotaoSumiu, jogo->animatedEscalaSumiu);
}