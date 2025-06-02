#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include "estruturas.h"

EstadoJogo Jogo;

int main() {

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "NoAnomalies");
    SetTargetFPS(60);

    init_estado_jogo(&Jogo);

    Vector2 tituloPos = {
        (float)screenWidth / 2 - (float)Jogo.menu.titulo.width / 2,
        60.0f
    };

    Vector2 botaoJogarPos = {
        (float)screenWidth / 2 - (float)Jogo.menu.botaoJogar.width / 2,
        tituloPos.y + Jogo.menu.titulo.height + 30.0f
    };

    Vector2 botaoOpcoesPos = {
        (float)screenWidth / 2 - (float)Jogo.menu.botaoOpcoes.width / 2,
        botaoJogarPos.y + Jogo.menu.botaoJogar.height + 30.0f
    };

    Vector2 botaoSairPos = {
        (float)screenWidth / 2 - (float)Jogo.menu.botaoSair.width / 2,
        botaoOpcoesPos.y + Jogo.menu.botaoOpcoes.height + 10.0f
    };

    while (!WindowShouldClose()) {

        switch (Jogo.screen) {

            case SCREEN_MENU:


                break;
            case SCREEN_GAME:



                break;
            case SCREEN_OPTIONS:



                break;
            case SCREEN_SAIR:



                break;

            default:
        }

        BeginDrawing();
        ClearBackground(WHITE);

        switch (Jogo.screen) {

            case SCREEN_MENU:
                DrawTexture(Jogo.menu.fundo, 0, 0, WHITE);

                DrawTextureV(Jogo.menu.titulo, tituloPos, WHITE);

                //DrawTextureV(Jogo.menu.botaoJogar, botaoJogarPos, WHITE);
                //DrawTextureV(Jogo.menu.botaoOpcoes, botaoOpcoesPos, WHITE);
                //DrawTextureV(Jogo.menu.botaoSair, botaoSairPos, WHITE);
                break;

            case SCREEN_GAME:


                break;

            case SCREEN_OPTIONS:


                break;

            default:
        }

        if (Jogo.screen == SCREEN_SAIR) {
            CloseWindow();
        }

        EndDrawing();
    }

   /* UnloadTexture(Jogo.menu.fundo);
    UnloadTexture(Jogo.menu.titulo);
    UnloadTexture(Jogo.menu.botaoJogar);
    UnloadTexture(Jogo.menu.botaoJogarHover);
    UnloadTexture(Jogo.menu.botaoOpcoes);
    UnloadTexture(Jogo.menu.botaoOpcoesHover);
    UnloadTexture(Jogo.menu.botaoSair);
    UnloadTexture(Jogo.menu.botaoSairHover);
   */
    CloseWindow();
    return 0;
}

