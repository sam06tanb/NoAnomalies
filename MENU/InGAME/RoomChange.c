#include <defines.h>
#include <estruturas.h>

#include "RoomChange.h"

#include "raylib.h"

void UpdateRoomSelector(EstadoJogo *jogo, Vector2 mousePos) {

    Vector2 posSetaEsq = { 30, (float)VIRTUAL_SCREEN_HEIGHT / 2 - (float)jogo->recursos_jogo.setaEsquerdaJogo.height / 2 };
    Vector2 posSetaDir = { VIRTUAL_SCREEN_WIDTH - 30 - jogo->recursos_jogo.setaDireitaJogo.width, (float)VIRTUAL_SCREEN_HEIGHT / 2 - (float)jogo->recursos_jogo.setaDireitaJogo.height / 2 };
    Rectangle hitboxEsq = { posSetaEsq.x, posSetaEsq.y, (float)jogo->recursos_jogo.setaEsquerdaJogo.width, (float)jogo->recursos_jogo.setaEsquerdaJogo.height };
    Rectangle hitboxDir = { posSetaDir.x, posSetaDir.y, (float)jogo->recursos_jogo.setaDireitaJogo.width, (float)jogo->recursos_jogo.setaDireitaJogo.height };

    bool quartoMudou = false;

    if (CheckCollisionPointRec(mousePos, hitboxEsq) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        jogo->indice_comodo_atual--;
        if (jogo->indice_comodo_atual < 0) { jogo->indice_comodo_atual = jogo->num_total_comodos - 1; }
        quartoMudou = true;
    }

    if (CheckCollisionPointRec(mousePos, hitboxDir) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        jogo->indice_comodo_atual++;
        if (jogo->indice_comodo_atual >= jogo->num_total_comodos) { jogo->indice_comodo_atual = 0; }
        quartoMudou = true;
    }

    if (quartoMudou) {
        if (jogo->texturaComodoAtual.id > 0) UnloadTexture(jogo->texturaComodoAtual);
        jogo->texturaComodoAtual = LoadTexture(jogo->todos_os_comodos[jogo->indice_comodo_atual].arquivo_imagem_fundo);
    }
}

void DrawRoomSelector(const EstadoJogo *jogo) {

    Vector2 posSetaEsq = { 30, (float)VIRTUAL_SCREEN_HEIGHT / 2 - (float)jogo->recursos_jogo.setaEsquerdaJogo.height / 2 };
    Vector2 posSetaDir = { VIRTUAL_SCREEN_WIDTH - 30 - jogo->recursos_jogo.setaDireitaJogo.width, (float)VIRTUAL_SCREEN_HEIGHT / 2 - (float)jogo->recursos_jogo.setaDireitaJogo.height / 2 };


    DrawTextureV(jogo->recursos_jogo.setaEsquerdaJogo, posSetaEsq, WHITE);
    DrawTextureV(jogo->recursos_jogo.setaDireitaJogo, posSetaDir, WHITE);

    Texture2D spriteNomeQuarto = jogo->recursos_jogo.spritesNomesComodos[jogo->indice_comodo_atual];
    if (spriteNomeQuarto.id > 0) {
        Vector2 posNomeQuarto = { (float)VIRTUAL_SCREEN_WIDTH / 2 - (float)spriteNomeQuarto.width / 2, 30 };
        DrawTextureV(spriteNomeQuarto, posNomeQuarto, WHITE);
    }
}