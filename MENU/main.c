#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include "estruturas.h"
#include "menu_screen.h"
#include "popup_opcoes.h"
#include "defines.h"

EstadoJogo Jogo;

int main(void) {

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "NoAnomalies");
    SetTargetFPS(60);

    init_estado_jogo(&Jogo);

    Vector2 tituloPos      = { 190.0f,  20.0f };
    Vector2 botaoJogarPos  = { 600.0f, 470.0f };
    Vector2 botaoOpcoesPos = { 1000.0f, 470.0f };
    Vector2 botaoSairPos   = { 800.0f, 700.0f };

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();

        // --- LÓGICA DE ATUALIZAÇÃO ---
        switch (Jogo.screen) {
            case SCREEN_MENU:
                if (Jogo.popupOpcoesVisivel) {
                    UpdatePopupOpcoes(&Jogo, mousePos);
                } else {
                    UpdateMenuScreen(&Jogo, mousePos, botaoJogarPos, botaoOpcoesPos, botaoSairPos);
                }
                break;
            case SCREEN_GAME:

                break;
            case SCREEN_OPTIONS:

                break;
            case SCREEN_SAIR:

                break;
            default:
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
        BeginDrawing();
        ClearBackground(WHITE);

        switch (Jogo.screen) {
            case SCREEN_MENU:

                DrawMenuScreen(&Jogo, tituloPos, botaoJogarPos, botaoOpcoesPos, botaoSairPos);

                if (Jogo.popupOpcoesVisivel) {
                    DrawPopupOpcoes(&Jogo);
                }
                break;
            case SCREEN_GAME:

                break;
            case SCREEN_OPTIONS:

                break;

        }
        EndDrawing();
    }

    UnloadTexture(Jogo.menu.fundo);
    UnloadTexture(Jogo.menu.titulo);
    UnloadTexture(Jogo.menu.botaoJogar);
    UnloadTexture(Jogo.menu.botaoOpcoes);
    UnloadTexture(Jogo.menu.botaoSair);

    CloseWindow();
    return 0;
}
