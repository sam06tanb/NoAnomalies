#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include "estruturas.h"
#include "menu_screen.h"
#include "popup_opcoes.h"
#include "defines.h"


EstadoJogo Jogo;

static float min_float(float a, float b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {

    InitWindow(VIRTUAL_SCREEN_WIDTH, VIRTUAL_SCREEN_HEIGHT, "NoAnomalies");
    InitAudioDevice();

    RenderTexture2D target = LoadRenderTexture(VIRTUAL_SCREEN_WIDTH, VIRTUAL_SCREEN_HEIGHT);

    SetTargetFPS(60);

    init_estado_jogo(&Jogo);

    Music musicMenu = LoadMusicStream("../assets/audio/menuMusic.mp3");
    PlayMusicStream(musicMenu);
    SetMusicVolume(musicMenu, Jogo.volumeAtual);

    Vector2 tituloPos      = { 190.0f,  20.0f };
    Vector2 botaoJogarPos  = { 600.0f, 470.0f };
    Vector2 botaoOpcoesPos = { 1000.0f, 470.0f };
    Vector2 botaoSairPos   = { 800.0f, 700.0f };

    while (!WindowShouldClose()) {

        UpdateMusicStream(musicMenu);


        float scale = min_float((float)GetScreenWidth() / VIRTUAL_SCREEN_WIDTH, (float)GetScreenHeight() / VIRTUAL_SCREEN_HEIGHT);


        Rectangle destRec = {
            (GetScreenWidth() - ((float)VIRTUAL_SCREEN_WIDTH * scale)) * 0.5f,
            (GetScreenHeight() - ((float)VIRTUAL_SCREEN_HEIGHT * scale)) * 0.5f,
            (float)VIRTUAL_SCREEN_WIDTH * scale,
            (float)VIRTUAL_SCREEN_HEIGHT * scale
        };

        Vector2 mousePosReal = GetMousePosition();

        Vector2 mousePosVirtual = {
            (mousePosReal.x - destRec.x) / scale,
            (mousePosReal.y - destRec.y) / scale
        };

        Vector2 mousePos = GetMousePosition();

        // --- LÓGICA DE ATUALIZAÇÃO ---
        switch (Jogo.screen) {
            case SCREEN_MENU:
                if (Jogo.popupOpcoesVisivel) {
                    UpdatePopupOpcoes(&Jogo, mousePosVirtual, musicMenu);
                } else {
                    UpdateMenuScreen(&Jogo, mousePosVirtual, botaoJogarPos, botaoOpcoesPos, botaoSairPos);
                }
                break;
            case SCREEN_GAME:

                break;
            case SCREEN_OPTIONS:

                break;
        }

        if (Jogo.screen == SCREEN_SAIR) {
            EndDrawing();
            UnloadTexture(Jogo.menu.fundo);
            UnloadTexture(Jogo.menu.titulo);
            UnloadTexture(Jogo.menu.botaoJogar);
            UnloadTexture(Jogo.menu.botaoOpcoes);
            UnloadTexture(Jogo.menu.botaoSair);

            CloseWindow();
            return 0;
        }

        // --- LÓGICA DE INICIALIZAÇÃO ---
        BeginTextureMode(target);
        ClearBackground(BLACK);

        switch (Jogo.screen) {
            case SCREEN_MENU:

                DrawMenuScreen(&Jogo, tituloPos, botaoJogarPos, botaoOpcoesPos, botaoSairPos);
                if (Jogo.popupOpcoesVisivel) {
                    DrawPopupOpcoes(&Jogo);
                }
                break;
            case SCREEN_GAME:
                DrawTexture(Jogo.texturaComodoAtual, 0, 0, WHITE);

                break;
        }
        EndTextureMode();

        BeginDrawing();
        ClearBackground(BLACK);


        Rectangle sourceRec = {0.0f, 0.0f, (float)target.texture.width, -(float)target.texture.height};
        Vector2 origin = { 0.0f, 0.0f };

        DrawTexturePro(target.texture, sourceRec, destRec, origin, 0.0f, WHITE);
        EndDrawing();
    }

    UnloadRenderTexture(target);
    UnloadMusicStream(musicMenu);

    UnloadTexture(Jogo.menu.fundo);
    UnloadTexture(Jogo.menu.titulo);
    UnloadTexture(Jogo.menu.botaoJogar);
    UnloadTexture(Jogo.menu.botaoOpcoes);
    UnloadTexture(Jogo.menu.botaoSair);

    if (Jogo.texturaComodoAtual.id > 0) {
        UnloadTexture(Jogo.texturaComodoAtual);
    }


    CloseAudioDevice();
    CloseWindow();
    return 0;
}
