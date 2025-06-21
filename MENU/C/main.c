/**
 * @file main.c
 * @brief Ponto de entrada principal e loop do jogo "NoAnomalies".
 *
 * Este arquivo é o coração do programa. Suas responsabilidades são:
 * 1. Inicializar todos os sistemas essenciais (Janela, Áudio, Render Texture).
 * 2. Carregar o estado inicial e os recursos da primeira tela.
 * 3. Executar o loop principal do jogo, que atualiza e desenha tudo a cada frame.
 * 4. Orquestrar qual tela (Menu, Jogo, etc.) deve ser atualizada e desenhada.
 * 5. Gerenciar a "tela virtual" (Render Texture) para que o jogo escale corretamente.
 * 6. Liberar todos os recursos carregados de forma limpa ao fechar o jogo.
 */

#include "raylib.h"
#include "estruturas.h"
#include "menu_screen.h"
#include "popup_opcoes.h"
#include "game_screen.h"
#include "defines.h"
#include "DescCarreg.h"

EstadoJogo Jogo;

/**
 * @brief Função auxiliar estática para encontrar o menor de dois números float.
 *
 * Criada para substituir a macro min() da Raylib e evitar potenciais conflitos
 * de compilação, garantindo um comportamento consistente.
 * @param a Primeiro número.
 * @param b Segundo número.
 * @return O menor valor entre a e b.
 */
static float min_float(float a, float b) {
    return (a < b) ? a : b;
}

int main(void) {

    InitWindow(VIRTUAL_SCREEN_WIDTH, VIRTUAL_SCREEN_HEIGHT, "NoAnomalies");
    InitAudioDevice();

    // Cria a "tela virtual" (Render Texture) com a resolução ideal do jogo.
    // Tudo será desenhado aqui primeiro, e só depois na janela real.
    RenderTexture2D target = LoadRenderTexture(VIRTUAL_SCREEN_WIDTH, VIRTUAL_SCREEN_HEIGHT);

    SetTargetFPS(60);

    init_estado_jogo(&Jogo); // Configura os valores iniciais e carrega os recursos da primeira tela.

    Music musicMenu = LoadMusicStream("../assets/audio/menuMusic.mp3");
    PlayMusicStream(musicMenu);

    Vector2 tituloPos      = { 190.0f,  20.0f };
    Vector2 botaoJogarPos  = { 600.0f, 470.0f };
    Vector2 botaoOpcoesPos = { 1000.0f, 470.0f };
    Vector2 botaoSairPos   = { 800.0f, 700.0f };

    while (!WindowShouldClose()) {

        UpdateMusicStream(musicMenu);
        SetMusicVolume(musicMenu, Jogo.volumeAtual);

        // 1. Mapeamento da Tela Virtual para a Real
        // Calcula a escala e o posicionamento para a tela virtual caber na janela real
        // sem distorcer, adicionando barras pretas se necessário (letterboxing).
        float scale = min_float((float)GetScreenWidth() / VIRTUAL_SCREEN_WIDTH, (float)GetScreenHeight() / VIRTUAL_SCREEN_HEIGHT);
        Rectangle destRec = { (GetScreenWidth() - (VIRTUAL_SCREEN_WIDTH * scale)) * 0.5f, (GetScreenHeight() - (VIRTUAL_SCREEN_HEIGHT * scale)) * 0.5f, VIRTUAL_SCREEN_WIDTH * scale, VIRTUAL_SCREEN_HEIGHT * scale };

        // Converte a posição do mouse (que está na coordenada da janela) para a coordenada da tela virtual.
        // Isso garante que as hitboxes dos botões funcionem em qualquer resolução.
        Vector2 mousePosVirtual = { (GetMousePosition().x - destRec.x) / scale, (GetMousePosition().y - destRec.y) / scale };

        switch (Jogo.screen) {
            case SCREEN_MENU:
                if (Jogo.popupOpcoesVisivel) {
                    UpdatePopupOpcoes(&Jogo, mousePosVirtual, musicMenu);
                } else {
                    UpdateMenuScreen(&Jogo, mousePosVirtual, botaoJogarPos, botaoOpcoesPos, botaoSairPos);
                }
                break;
            case SCREEN_GAME:
                UpdateGameScreen(&Jogo, mousePosVirtual);
                break;
        }


        // 3. Desenha o jogo na Tela Virtual (Render Texture)
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
                    DrawGameScreen(&Jogo);
                    break;
            }

        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK); // Limpa a janela real (fundo das barras pretas)
            // Desenha a textura da tela virtual, escalada e centralizada
            Rectangle sourceRec = {0.0f, 0.0f, (float)target.texture.width, -(float)target.texture.height}; // Inverte o Y
            DrawTexturePro(target.texture, sourceRec, destRec, (Vector2){0,0}, 0.0f, WHITE);
        EndDrawing();
    }

    if (Jogo.screen == SCREEN_MENU) DescarregarRecursosMenu(&Jogo);
    else if (Jogo.screen == SCREEN_GAME) DescarregarRecursosJogo(&Jogo);

    UnloadRenderTexture(target);
    UnloadMusicStream(musicMenu);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}