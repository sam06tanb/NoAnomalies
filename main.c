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

    Vector2 tituloPos      = { 190.0f,  20.0f };
    Vector2 botaoJogarPos  = { 600.0f, 470.0f };
    Vector2 botaoOpcoesPos = { 1000.0f, 470.0f };
    Vector2 botaoSairPos   = { 800.0f, 700.0f };

    bool mouseSobreBotaoJogar = false;
    bool mouseSobreBotaoOpcoes = false;
    bool mouseSobreBotaoSair = false;

    const float escalaNormalGlobal = 1.5f;
    const float escalaHoverGlobal = 1.65f;

    float animatedEscalaJogar = escalaNormalGlobal;
    float animatedEscalaOpcoes = escalaNormalGlobal;
    float animatedEscalaSair = escalaNormalGlobal;

    while (!WindowShouldClose()) {

        Vector2 mousePos = GetMousePosition();

        switch (Jogo.screen) {
            case SCREEN_MENU:

                //BOTAO JOGAR
                float escalaJogar = 1.3f;

                //Cria a hitbox do botao
                Rectangle hitboxBotaoJogar = {
                    botaoJogarPos.x,
                    botaoJogarPos.y,
                    (float)Jogo.menu.botaoJogar.width * escalaNormalGlobal,
                    (float)Jogo.menu.botaoJogar.height * escalaNormalGlobal
                    };

                //Checa se o mouse esta por cima do botao
                if (CheckCollisionPointRec(mousePos, hitboxBotaoJogar)) {
                    mouseSobreBotaoJogar = true;
                    //Checa o clique do mouse, se clicar vai para o jogo
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        Jogo.screen = SCREEN_GAME;
                    }
                } else {
                    mouseSobreBotaoJogar = false;
                }

                float targetEscalaJogar;
                if (mouseSobreBotaoJogar) {
                    targetEscalaJogar = escalaHoverGlobal;
                } else {
                    targetEscalaJogar = escalaNormalGlobal;
                }

                float velocidadeAnimacao = 0.05f;
                animatedEscalaJogar += (targetEscalaJogar - animatedEscalaJogar) * velocidadeAnimacao;


                //BOTAO OPCOES
                float escalaOpcoes = 1.3f;

                //Cria a hitbox do botao
                Rectangle hitboxBotaoOpcoes = {
                    botaoOpcoesPos.x,
                    botaoOpcoesPos.y,
                    (float)Jogo.menu.botaoOpcoes.width * escalaNormalGlobal,
                    (float)Jogo.menu.botaoOpcoes.height * escalaNormalGlobal
                    };

                //Checa se o mouse esta por cima do botao
                if (CheckCollisionPointRec(mousePos, hitboxBotaoOpcoes)) {
                    mouseSobreBotaoOpcoes = true;
                    //Checa o clique do mouse, se clicar vai para o jogo
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        Jogo.screen = SCREEN_OPTIONS;
                    }
                } else {
                    mouseSobreBotaoOpcoes = false;
                }

                float targetEscalaOpcoes;
                if (mouseSobreBotaoOpcoes) {
                    targetEscalaOpcoes = escalaHoverGlobal;
                } else {
                    targetEscalaOpcoes = escalaNormalGlobal;
                }

                animatedEscalaOpcoes += (targetEscalaOpcoes - animatedEscalaOpcoes) * velocidadeAnimacao;

                //BOTAO SAIR
                float escalaSair = 1.3f;

                //Cria a hitbox do botao
                Rectangle hitboxBotaoSair = {
                    botaoSairPos.x,
                    botaoSairPos.y,
                    (float)Jogo.menu.botaoSair.width * escalaNormalGlobal,
                    (float)Jogo.menu.botaoSair.height * escalaNormalGlobal
                    };

                //Checa se o mouse esta por cima do botao
                if (CheckCollisionPointRec(mousePos, hitboxBotaoSair)) {
                    mouseSobreBotaoSair = true;
                    //Checa o clique do mouse, se clicar vai para o jogo
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        Jogo.screen = SCREEN_SAIR;
                    }
                } else {
                    mouseSobreBotaoSair = false;
                }

                float targetEscalaSair;
                if (mouseSobreBotaoSair) {
                    targetEscalaSair = escalaHoverGlobal;
                } else {
                    targetEscalaSair = escalaNormalGlobal;
                }

                animatedEscalaSair += (targetEscalaSair - animatedEscalaSair) * velocidadeAnimacao;


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
                Vector2 origin = {0.0f, 0.0f};

                const float escalaNormalJogar = 1.5f;
                const float escalaHoverJogar = 1.65f;

                float escalaAtualJogar;

                //redimensiona o botao de acordo com o estado, ou o mouse está em cima do botao, ou nao, se estiver aumenta se nao, ai nao aumenta
                if (mouseSobreBotaoJogar) {
                    escalaAtualJogar = escalaHoverJogar;
                } else {
                    escalaAtualJogar = escalaNormalJogar;
                }

                //largura e altura original do botao
                float larguraOriginalTextura = (float)Jogo.menu.botaoJogar.width;
                float alturaOriginalTextura = (float)Jogo.menu.botaoJogar.height;

                //escala de tamanho atual deles, ou seja, dependendo do estado
                float larguraNormalBotao = larguraOriginalTextura * escalaNormalGlobal;
                float alturaNormalBotao = alturaOriginalTextura * escalaNormalGlobal;

                //escala de tamanho atual deles, ou seja, dependendo do estado
                float larguraAnimadaBotao = larguraOriginalTextura * animatedEscalaJogar;
                float alturaAnimadaBotao = alturaOriginalTextura * animatedEscalaJogar;

                float offSetX = (larguraAnimadaBotao - larguraNormalBotao) / 2.0f;
                float offSetY = (alturaAnimadaBotao - alturaNormalBotao) / 2.0f;

                //posicao para onde o botao vai quando passar em cima = a posicao dele no menu
                float posXDestino = botaoJogarPos.x - offSetX;
                float posYDestino = botaoJogarPos.y - offSetY;

                Rectangle destRecJogar = {
                    posXDestino,
                    posYDestino,
                    larguraAnimadaBotao,
                    alturaAnimadaBotao
                };

                DrawTexturePro(Jogo.menu.botaoJogar, sourceRecJogar, destRecJogar, origin, 0.0f, WHITE);
            }

            // Redimensiona tamanho do botao Opcoes
            if (Jogo.menu.botaoOpcoes.id > 0) {
                Rectangle sourceRecOpcoes = { 0.0f, 0.0f, (float)Jogo.menu.botaoOpcoes.width, (float)Jogo.menu.botaoOpcoes.height };
                Vector2 origin = {0.0f, 0.0f};

                //largura e altura original do botao
                float larguraOriginalTextura = (float)Jogo.menu.botaoOpcoes.width;
                float alturaOriginalTextura = (float)Jogo.menu.botaoOpcoes.height;

                //escala de tamanho atual deles, ou seja, dependendo do estado
                float larguraNormalBotao = larguraOriginalTextura * escalaNormalGlobal;
                float alturaNormalBotao = alturaOriginalTextura * escalaNormalGlobal;

                //escala de tamanho atual deles, ou seja, dependendo do estado
                float larguraAnimadaBotao = larguraOriginalTextura * animatedEscalaOpcoes;
                float alturaAnimadaBotao = alturaOriginalTextura * animatedEscalaOpcoes;

                float offSetX = (larguraAnimadaBotao - larguraNormalBotao) / 2.0f;
                float offSetY = (alturaAnimadaBotao - alturaNormalBotao) / 2.0f;

                //posicao para onde o botao vai quando passar em cima = a posicao dele no menu
                float posXDestino = botaoOpcoesPos.x - offSetX;
                float posYDestino = botaoOpcoesPos.y - offSetY;

                Rectangle destRecOpcoes = {
                    posXDestino,
                    posYDestino,
                    larguraAnimadaBotao,
                    alturaAnimadaBotao
                };

                DrawTexturePro(Jogo.menu.botaoOpcoes, sourceRecOpcoes, destRecOpcoes, origin, 0.0f, WHITE);
            }

            // Redimensiona tamanho do botao Sair
            if (Jogo.menu.botaoSair.id > 0) {
                Rectangle sourceRecSair = { 0.0f, 0.0f, (float)Jogo.menu.botaoSair.width, (float)Jogo.menu.botaoSair.height };
                Vector2 origin = {0.0f, 0.0f};

                //largura e altura original do botao
                float larguraOriginalTextura = (float)Jogo.menu.botaoSair.width;
                float alturaOriginalTextura = (float)Jogo.menu.botaoSair.height;

                //escala de tamanho atual deles, ou seja, dependendo do estado
                float larguraNormalBotao = larguraOriginalTextura * escalaNormalGlobal;
                float alturaNormalBotao = alturaOriginalTextura * escalaNormalGlobal;

                //escala de tamanho atual deles, ou seja, dependendo do estado
                float larguraAnimadaBotao = larguraOriginalTextura * animatedEscalaSair;
                float alturaAnimadaBotao = alturaOriginalTextura * animatedEscalaSair;

                float offSetX = (larguraAnimadaBotao - larguraNormalBotao) / 2.0f;
                float offSetY = (alturaAnimadaBotao - alturaNormalBotao) / 2.0f;

                //posicao para onde o botao vai quando passar em cima = a posicao dele no menu
                float posXDestino = botaoSairPos.x - offSetX;
                float posYDestino = botaoSairPos.y - offSetY;

                Rectangle destRecSair = {
                    posXDestino,
                    posYDestino,
                    larguraAnimadaBotao,
                    alturaAnimadaBotao
                };

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
            EndDrawing();
            UnloadTexture(Jogo.menu.fundo);
            UnloadTexture(Jogo.menu.titulo);
            UnloadTexture(Jogo.menu.botaoJogar);
            UnloadTexture(Jogo.menu.botaoJogarHover);
            UnloadTexture(Jogo.menu.botaoOpcoes);
            UnloadTexture(Jogo.menu.botaoOpcoesHover);
            UnloadTexture(Jogo.menu.botaoSair);
            UnloadTexture(Jogo.menu.botaoSairHover);
            CloseWindow();
            return 0;
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

