
#include "aplicar.h"
#include "defines.h"
#include "ui_helpers.h"

void UpdateAplicar(EstadoJogo *jogo, Vector2 mousePos, Vector2 posAplicar) {

    Rectangle hitBoxAplicar = {
        posAplicar.x,
        posAplicar.y,
        (float) jogo->options.botaoAplicar.width * ESCALA_NORMAL_BOTAO,
        (float) jogo->options.botaoAplicar.height * ESCALA_NORMAL_BOTAO
    };

    if (CheckCollisionPointRec(mousePos, hitBoxAplicar)) {
        jogo->mouseSobreBotaoAplicar = true;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            Vector2 novaResolucao = jogo->resolucoesDisponiveis[jogo->indiceResolucoesAtual];
            int novaLargura = (int) novaResolucao.x;
            int novaAltura = (int) novaResolucao.y;

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
        targetEscalaAplicar = ESCALA_HOVER_BOTAO;
    } else {
        targetEscalaAplicar = ESCALA_NORMAL_BOTAO;
    }
    jogo->animatedEscalaAplicar += (targetEscalaAplicar - jogo->animatedEscalaAplicar) * VELOCIDADE_ANIM_BOTAO;

  }

void DrawAplicar(const EstadoJogo *jogo, Vector2 position) {

    DrawAnimatedButton(jogo->options.botaoAplicar, position, jogo->animatedEscalaAplicar);

}