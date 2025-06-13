#include "ui_helpers.h"
#include "defines.h"

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