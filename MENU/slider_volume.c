
#include "slider_volume.h"
#include "raymath.h"

void UpdateVolumeSlider(EstadoJogo *jogo, Vector2 mousePos, Rectangle sliderArea, Music music) {

    if (jogo->arrastandoSliderVolume) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->arrastandoSliderVolume = false;
        }

        float mouseRelativoX = mousePos.x - sliderArea.x;
        jogo->volumeAtual = mouseRelativoX / sliderArea.width;
        jogo->volumeAtual = Clamp(jogo->volumeAtual, 0.0f, 1.0f);

    } else if (CheckCollisionPointRec(mousePos, sliderArea)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->arrastandoSliderVolume = true;
            float mouseRelativoX = mousePos.x - sliderArea.x;
            jogo->volumeAtual = mouseRelativoX / sliderArea.width;
            jogo->volumeAtual = Clamp(jogo->volumeAtual, 0.0f, 1.0f);
        }
    }
    SetMusicVolume(music, jogo->volumeAtual);
}

void DrawVolumeSlider (EstadoJogo *jogo, Vector2 sliderPos) {

    float comprimentoTotalSlider = 400.0f;
    float alturaSlider = (float)jogo->options.barraFundoEsq.height;

    // 1. Desenha a Barra de Fundo
    if (jogo->options.barraFundoEsq.id > 0) {
        DrawTextureV(jogo->options.barraFundoEsq, sliderPos, WHITE);
        Rectangle sourceMeio = {0, 0, (float)jogo->options.barraFundoMeio.width, (float)jogo->options.barraFundoMeio.height};
        Rectangle destMeio = {sliderPos.x + jogo->options.barraFundoEsq.width, sliderPos.y, comprimentoTotalSlider - jogo->options.barraFundoEsq.width - jogo->options.barraFundoDir.width, alturaSlider};
        DrawTexturePro(jogo->options.barraFundoMeio, sourceMeio, destMeio, (Vector2){0,0}, 0.0f, WHITE);
        DrawTextureV(jogo->options.barraFundoDir, (Vector2){sliderPos.x + comprimentoTotalSlider - jogo->options.barraFundoDir.width, sliderPos.y}, WHITE);
    }

    // 2. Desenha a Barra de Preenchimento
    float comprimentoPreenchimento = comprimentoTotalSlider * jogo->volumeAtual;
    if (jogo->options.barraPreenchimentoCompleta.id > 0) {
        Texture2D preenchimento = jogo->options.barraPreenchimentoCompleta;
        float larguraDoRecorte = (float)preenchimento.width * jogo->volumeAtual;
        Rectangle sourceRecorte = { 0.0f, 0.0f, larguraDoRecorte, (float)preenchimento.height };
        Rectangle destRec = { sliderPos.x, sliderPos.y, comprimentoPreenchimento, alturaSlider };
        DrawTexturePro(preenchimento, sourceRecorte, destRec, (Vector2){0,0}, 0.0f, WHITE);
    }

    // 3. Desenha o Puxador
    if (jogo->options.puxadorVolume.id > 0) {
        Vector2 posPuxador = {
            sliderPos.x + comprimentoPreenchimento - ((float)jogo->options.puxadorVolume.width / 2.0f),
            sliderPos.y + (alturaSlider / 2.0f) - ((float)jogo->options.puxadorVolume.height / 2.0f)
        };
        DrawTextureV(jogo->options.puxadorVolume, posPuxador, WHITE);
    }
}