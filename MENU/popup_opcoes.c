#include "popup_opcoes.h"
#include "slider_volume.h"
#include <stdio.h>
#include "defines.h"
#include "aplicar.h"
#include "seletor_resolucao.h"
#include "botao_tutorial.h"
#include "botao_fechar.h"

void UpdatePopupOpcoes(EstadoJogo *jogo, Vector2 mousePos, Music music) {

    if (jogo->popupOpcoesVisivel) {
        float painelLargura = (float) jogo->options.painelPopupOpcoes.width;
        float painelAltura = (float) jogo->options.painelPopupOpcoes.height;
        Vector2 popupPainelPos = {
            (float) VIRTUAL_SCREEN_WIDTH / 2 - painelLargura / 2,
            (float) VIRTUAL_SCREEN_HEIGHT / 2 - painelAltura / 2
        };

        Vector2 posFechar = { popupPainelPos.x + painelLargura - jogo->options.botaoFecharPopup.width - 10, popupPainelPos.y + 10 };
        Vector2 posSlider = {(float) VIRTUAL_SCREEN_WIDTH / 2 - 200, (float) VIRTUAL_SCREEN_HEIGHT / 2 - 300};
        Vector2 posTutorial = {popupPainelPos.x + 150, popupPainelPos.y + 650};
        Vector2 posAplicar = {1100, 925};

        float comprimentoSlider = 400.0f;
        float alturaSlider = (float) jogo->options.barraFundoEsq.height;
        Rectangle sliderArea = {posSlider.x, posSlider.y, comprimentoSlider, alturaSlider};

        UpdateVolumeSlider(jogo, mousePos, sliderArea, music);
        UpdateSeletorResolucao(jogo, mousePos, popupPainelPos);
        UpdateBotaoTutorial(jogo, mousePos, posTutorial);
        UpdateAplicar(jogo, mousePos, posAplicar);
        UpdateBotaoFechar(jogo, mousePos, posFechar);

    }
}

void DrawPopupOpcoes(const EstadoJogo *jogo) {

    DrawRectangle(0, 0, VIRTUAL_SCREEN_WIDTH, VIRTUAL_SCREEN_HEIGHT, Fade(BLACK, 0.7f));

    Vector2 painelPos = {
        (float) VIRTUAL_SCREEN_WIDTH / 2 - (float) jogo->options.painelPopupOpcoes.width / 2,
        (float) VIRTUAL_SCREEN_HEIGHT / 2 - (float) jogo->options.painelPopupOpcoes.height / 2
    };
    DrawTextureV(jogo->options.painelPopupOpcoes, painelPos, WHITE);

    Vector2 posFechar = {painelPos.x + (float) jogo->options.painelPopupOpcoes.width - (float) jogo->options.botaoFecharPopup.width -20,painelPos.y + 20 };
    Vector2 posSlider = {(float) VIRTUAL_SCREEN_WIDTH / 2 - 200, (float) VIRTUAL_SCREEN_HEIGHT / 2 - 300};
    Vector2 posTutorial = {painelPos.x + 150, painelPos.y + 650};
    Vector2 posAplicar = {1100, 925};

    DrawBotaoFechar(jogo, posFechar);
    DrawVolumeSlider(jogo, posSlider);
    DrawSeletorResolucao(jogo, painelPos);
    DrawBotaoTutorial(jogo, posTutorial);
    DrawAplicar(jogo, posAplicar);
}
