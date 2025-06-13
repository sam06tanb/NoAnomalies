#include "popup_opcoes.h"

#include <stdio.h>

#include "defines.h"
#include "raymath.h"

void DrawAnimatedButton(Texture2D texture, Vector2 position, float animatedScale) {
    if (texture.id <= 0) return;

    float larguraOriginal = (float) texture.width;
    float alturaOriginal = (float) texture.height;
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
    DrawTexturePro(texture, sourceRec, destRec, (Vector2){0, 0}, 0.0f, WHITE);
}

void UpdatePopupOpcoes(EstadoJogo *jogo, Vector2 mousePos, Music music) {
    if (jogo->popupOpcoesVisivel) {
        float painelLargura = (float) jogo->options.painelPopupOpcoes.width;
        float painelAltura = (float) jogo->options.painelPopupOpcoes.height;
        Vector2 popupPainelPos = {
            (float) VIRTUAL_SCREEN_WIDTH / 2 - painelLargura / 2,
            (float) VIRTUAL_SCREEN_HEIGHT / 2 - painelAltura / 2
        };

        //APLICAR
        Vector2 posAplicar = {1100, 925};
        Rectangle hitBoxAplicar = {
            posAplicar.x,
            posAplicar.y,
            (float) jogo->options.botaoAplicar.width * ESCALA_NORMAL_BOTAO,
            (float) jogo->options.botaoAplicar.height * ESCALA_NORMAL_BOTAO
        };

        if (CheckCollisionPointRec(mousePos, hitBoxAplicar)) {
            jogo->mouseSobreBotaoAplicar = true;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                printf("Aplicando resolucao!\n");

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


        //SLIDER
        Vector2 posSlider = {(float) VIRTUAL_SCREEN_WIDTH / 2 - 200, (float) VIRTUAL_SCREEN_HEIGHT / 2 - 300};
        float comprimentoSlider = 400.0f;
        float alturaSlider = (float) jogo->options.barraFundoEsq.height;
        Rectangle sliderArea = {posSlider.x, posSlider.y, comprimentoSlider, alturaSlider};

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

        //FECHAR
        Vector2 posFechar = {
            popupPainelPos.x + painelLargura - jogo->options.botaoFecharPopup.width - 10, popupPainelPos.y + 10
        };

        Rectangle hitboxBotaoFechar = {
            posFechar.x,
            posFechar.y,
            (float) jogo->options.botaoFecharPopup.width,
            (float) jogo->options.botaoFecharPopup.height
        };

        if (CheckCollisionPointRec(mousePos, hitboxBotaoFechar)) {
            jogo->mouseSobreBotaoFechar = true;

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                jogo->popupOpcoesVisivel = false;
            }
        } else {
            jogo->mouseSobreBotaoFechar = false;
        }

        //BOTAO RESOLUCAO
        Vector2 posSetaEsquerda = {popupPainelPos.x + 150, popupPainelPos.y + 450};
        Vector2 posSetaDireita = {
            popupPainelPos.x + painelLargura - 150 - jogo->options.setaDireita.width, posSetaEsquerda.y
        };

        Rectangle hitboxSetaEsquerda = {
            posSetaEsquerda.x, posSetaEsquerda.y, (float) jogo->options.setaEsquerda.width,
            (float) jogo->options.setaEsquerda.height
        };
        Rectangle hitboxSetaDireita = {
            posSetaDireita.x, posSetaDireita.y, (float) jogo->options.setaDireita.width,
            (float) jogo->options.setaDireita.height
        };

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
        Vector2 posTutorial = {popupPainelPos.x + 150, popupPainelPos.y + 700};
        Rectangle hitboxTutorial = {
            posTutorial.x,
            posTutorial.y,
            (float) jogo->options.botaoTutorial.width * ESCALA_NORMAL_BOTAO,
            (float) jogo->options.botaoTutorial.height * ESCALA_NORMAL_BOTAO
        };

        if (CheckCollisionPointRec(mousePos, hitboxTutorial)) {
            jogo->mouseSobreBotaoTutorial = true;

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                printf("Botao Tutorial  clicado!\n");
            }
        } else {
            jogo->mouseSobreBotaoTutorial = false;
        }

        float targetEscalaTutorial;
        if (jogo->mouseSobreBotaoTutorial) { targetEscalaTutorial = ESCALA_HOVER_BOTAO; } else {
            targetEscalaTutorial = ESCALA_NORMAL_BOTAO;
        }
        jogo->animatedEscalaTutorial += (targetEscalaTutorial - jogo->animatedEscalaTutorial) * VELOCIDADE_ANIM_BOTAO;
    }
}

void DrawPopupOpcoes(const EstadoJogo *jogo) {
    // Escurece a tela de fundo
    DrawRectangle(0, 0, VIRTUAL_SCREEN_WIDTH, VIRTUAL_SCREEN_HEIGHT, Fade(BLACK, 0.7f));

    // --- Desenho do Painel e Botões ---
    Vector2 painelPos = {
        (float) VIRTUAL_SCREEN_WIDTH / 2 - (float) jogo->options.painelPopupOpcoes.width / 2,
        (float) VIRTUAL_SCREEN_HEIGHT / 2 - (float) jogo->options.painelPopupOpcoes.height / 2
    };
    DrawTextureV(jogo->options.painelPopupOpcoes, painelPos, WHITE);

    if (jogo->options.botaoFecharPopup.id > 0) {
        // Botão Fechar
        Vector2 posFechar = {
            painelPos.x + (float) jogo->options.painelPopupOpcoes.width - (float) jogo->options.botaoFecharPopup.width -
            20,
            painelPos.y + 20
        };
        DrawTextureV(jogo->options.botaoFecharPopup, posFechar, WHITE);
    }

    //APLICAR
    Vector2 posAplicar = {1100, 925};
    DrawAnimatedButton(jogo->options.botaoAplicar, posAplicar, jogo->animatedEscalaAplicar);

    //SLIDER
    Vector2 posSlider = {(float) VIRTUAL_SCREEN_WIDTH / 2 - 200, (float) VIRTUAL_SCREEN_HEIGHT / 2 - 300};

    float comprimentoTotalSlider = 400.0f;
    float alturaSlider = (float) jogo->options.barraFundoEsq.height;

    if (jogo->options.barraFundoEsq.id > 0) {
        DrawTextureV(jogo->options.barraFundoEsq, posSlider, WHITE);
        Rectangle sourceMeio = {
            0, 0, (float) jogo->options.barraFundoMeio.width, (float) jogo->options.barraFundoMeio.height
        };
        Rectangle destMeio = {
            posSlider.x + jogo->options.barraFundoEsq.width, posSlider.y,
            comprimentoTotalSlider - jogo->options.barraFundoEsq.width - jogo->options.barraFundoDir.width, alturaSlider
        };
        DrawTexturePro(jogo->options.barraFundoMeio, sourceMeio, destMeio, (Vector2){0, 0}, 0.0f, WHITE);
        DrawTextureV(jogo->options.barraFundoDir, (Vector2){
                         posSlider.x + comprimentoTotalSlider - jogo->options.barraFundoDir.width, posSlider.y
                     }, WHITE);
    }

    if (jogo->options.barraPreenchimentoCompleta.id > 0) {
        // Pega a textura da barra 100% cheia
        Texture2D preenchimento = jogo->options.barraPreenchimentoCompleta;

        // Calcula qual porcentagem da LARGURA da imagem original vamos "recortar" e desenhar
        float larguraDoRecorte = (float) preenchimento.width * jogo->volumeAtual;

        // source: O retângulo de "corte" da imagem original.
        // A gente corta a imagem na largura, mas usa a altura total.
        Rectangle sourceRecortePreenchimento = {0.0f, 0.0f, larguraDoRecorte, (float) preenchimento.height};

        // dest: Onde e com que tamanho na tela vamos desenhar o pedaço que recortamos.
        // A largura do destino também depende do volume.
        Rectangle destRecPreenchimento = {
            posSlider.x, posSlider.y, comprimentoTotalSlider * jogo->volumeAtual, alturaSlider
        };

        // Desenha apenas o pedaço recortado da textura
        DrawTexturePro(preenchimento, sourceRecortePreenchimento, destRecPreenchimento, (Vector2){0, 0}, 0.0f, WHITE);
    }

    // 3. Desenha o Puxador
    if (jogo->options.puxadorVolume.id > 0) {
        float comprimentoPreenchimento = comprimentoTotalSlider * jogo->volumeAtual;
        Vector2 posPuxador = {
            posSlider.x + comprimentoPreenchimento - ((float) jogo->options.puxadorVolume.width / 2.0f),
            posSlider.y + (alturaSlider / 2.0f) - ((float) jogo->options.puxadorVolume.height / 2.0f)
        };
        DrawTextureV(jogo->options.puxadorVolume, posPuxador, WHITE);
    }

    //SETAS E RESOLUCAO
    Vector2 posSetaEsquerda = {painelPos.x + 150, painelPos.y + 450};
    Vector2 posSetaDireita = {
        painelPos.x + (float) jogo->options.painelPopupOpcoes.width - 150 - (float) jogo->options.setaDireita.width,
        posSetaEsquerda.y
    };

    DrawTextureV(jogo->options.setaEsquerda, posSetaEsquerda, WHITE);
    DrawTextureV(jogo->options.setaDireita, posSetaDireita, WHITE);

    Texture2D spriteResAtual = jogo->options.spritesResolucao[jogo->indiceResolucoesAtual];

    if (spriteResAtual.id > 0) {
        float meioDoEspacoEntreSetas = posSetaEsquerda.x + jogo->options.setaEsquerda.width +
                                       ((posSetaDireita.x - (posSetaEsquerda.x + jogo->options.setaEsquerda.width)) /
                                        2.0f);
        Vector2 posSpriteResolucao = {
            meioDoEspacoEntreSetas - (float) spriteResAtual.width / 2.0f,
            posSetaEsquerda.y - 30
        };
        DrawTextureV(spriteResAtual, posSpriteResolucao, WHITE);
    }

    Vector2 posTutorial = {painelPos.x + 150, painelPos.y + 700};
    DrawAnimatedButton(jogo->options.botaoTutorial, posTutorial, jogo->animatedEscalaTutorial);
}
