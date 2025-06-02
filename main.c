#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include "estruturas.h"

EstadoJogo Jogo;

int main() {

    //Define tamanho da tela
    const int screenWidth = 1920;
    const int screenHeight = 1080;


    //Inicia a tela do jogo
    InitWindow(screenWidth, screenHeight, "NoAnomalies");
    SetTargetFPS(60);

    //Chama a funcao que carrega as texturas
    init_estado_jogo(&Jogo);

    Vector2 tituloPos      = { 190.0f,  20.0f }; // Ex: Título em X=860, Y=60
    Vector2 botaoJogarPos  = { 1000.0f, 470.0f }; // Ex: Botão Jogar em X=800, Y=250
    Vector2 botaoOpcoesPos = { 600.0f, 470.0f }; // Ex: Botão Opções em X=800, Y=350
    Vector2 botaoSairPos   = { 800.0f, 700.0f }; // Ex: Botão Sair em X=800, Y=450

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

        // Comeca a desenhar o menu
        BeginDrawing();
        ClearBackground(WHITE);

        switch (Jogo.screen) {

            case SCREEN_MENU:
                DrawTexture(Jogo.menu.fundo, 0, 0, WHITE);
                DrawTextureV(Jogo.menu.titulo, tituloPos, WHITE);

            // Redimensiona tamanho do botao Jogar
            if (Jogo.menu.botaoJogar.id > 0) {
                Rectangle sourceRecJogar = { 0.0f, 0.0f, (float)Jogo.menu.botaoJogar.width, (float)Jogo.menu.botaoJogar.height };
                float escalaJogar = 1.5f;

                Rectangle destRecJogar = {
                botaoJogarPos.x,
                botaoJogarPos.y,
                (float)Jogo.menu.botaoJogar.width * escalaJogar,
                (float)Jogo.menu.botaoJogar.height * escalaJogar
                };
                Vector2 origin = {0.0f, 0.0f};
                DrawTexturePro(Jogo.menu.botaoJogar, sourceRecJogar, destRecJogar, origin, 0.0f, WHITE);
            }

            // Redimensiona tamanho do botao Opcoes
            if (Jogo.menu.botaoOpcoes.id > 0) {
                Rectangle sourceRecOpcoes = { 0.0f, 0.0f, (float)Jogo.menu.botaoOpcoes.width, (float)Jogo.menu.botaoOpcoes.height };
                float escalaOpcoes = 1.5f;

                Rectangle destRecOpcoes = {
                    botaoOpcoesPos.x,
                    botaoOpcoesPos.y,
                    (float)Jogo.menu.botaoOpcoes.width * escalaOpcoes,
                    (float)Jogo.menu.botaoOpcoes.height * escalaOpcoes
                    };
                Vector2 origin = {0.0f, 0.0f};
                DrawTexturePro(Jogo.menu.botaoOpcoes, sourceRecOpcoes, destRecOpcoes, origin, 0.0f, WHITE);
            }

            // Redimensiona tamanho do botao Sair
            if (Jogo.menu.botaoSair.id > 0) {
                Rectangle sourceRecSair = { 0.0f, 0.0f, (float)Jogo.menu.botaoSair.width, (float)Jogo.menu.botaoSair.height };
                float escalaSair = 1.5f;

                Rectangle destRecSair = {
                    botaoSairPos.x,
                    botaoSairPos.y,
                    (float)Jogo.menu.botaoSair.width * escalaSair,
                    (float)Jogo.menu.botaoSair.height * escalaSair
                    };
                Vector2 origin = {0.0f, 0.0f};
                DrawTexturePro(Jogo.menu.botaoSair, sourceRecSair, destRecSair, origin, 0.0f, WHITE);
            }



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

    //descarrega as texturas quando sai do looping para nao pesar o jogo com texturas carregadas desnecessariamente
    UnloadTexture(Jogo.menu.fundo);
    UnloadTexture(Jogo.menu.titulo);
    UnloadTexture(Jogo.menu.botaoJogar);
    UnloadTexture(Jogo.menu.botaoJogarHover);
    UnloadTexture(Jogo.menu.botaoOpcoes);
    UnloadTexture(Jogo.menu.botaoOpcoesHover);
    UnloadTexture(Jogo.menu.botaoSair);
    UnloadTexture(Jogo.menu.botaoSairHover);

    //Fecha a tela inteira do jogo
    CloseWindow();
    return 0;
}

