/**
 * @file ui_helpers.c
 * @brief Contém funções auxiliares genéricas para desenhar elementos de UI (Interface de Usuário).
 *
 * A ideia deste arquivo é ter funções reutilizáveis, como desenhar um botão animado,
 * para que não precisemos repetir o mesmo código de desenho em várias telas diferentes.
 */

#include "ui_helpers.h"
#include "../H/defines.h"

/**
 * @brief Desenha um botão na tela com uma animação de escala suave que se expande a partir do centro.
 *
 * Esta função é o coração da aparência dos nossos botões. Ela recebe a textura, uma posição base
 * e a escala animada atual (que é calculada na lógica de Update).
 * O truque para a animação parecer centralizada é calcular a diferença de tamanho entre
 * a escala ATUAL (animada) e a escala NORMAL, e então ajustar a posição de desenho (X, Y)
 * para compensar essa diferença.
 *
 * @param texture A textura (o sprite) do botão a ser desenhado.
 * @param position A posição base (canto superior esquerdo) do botão em sua ESCALA NORMAL. A animação se centralizará em torno desta posição.
 * @param animatedScale A escala de animação atual do botão, que determina o seu tamanho neste frame.
 */
void DrawAnimatedButton(Texture2D texture, Vector2 position, float animatedScale) {
    // 1. Verificação de segurança: não tenta desenhar se a textura não foi carregada.
    if (texture.id <= 0) return;

    // 2. Pega as dimensões originais do sprite.
    float larguraOriginal = (float) texture.width;
    float alturaOriginal = (float) texture.height;

    // 3. Calcula qual seria o tamanho do botão na sua escala normal (sem animação de hover).
    //    Isso serve como nossa referência para o posicionamento centralizado.
    float larguraNormal = larguraOriginal * ESCALA_NORMAL_BOTAO;
    float alturaNormal = alturaOriginal * ESCALA_NORMAL_BOTAO;

    // 4. Calcula o tamanho ATUAL do botão, usando a escala animada que muda a cada frame.
    float larguraAnimada = larguraOriginal * animatedScale;
    float alturaAnimada = alturaOriginal * animatedScale;

    // 5. O "Pulo do Gato": Calcula o deslocamento (offset) para centralizar a animação.
    //    Este é o quanto o botão "cresceu" em relação ao seu tamanho normal, dividido por 2.
    float offsetX = (larguraAnimada - larguraNormal) / 2.0f;
    float offsetY = (alturaAnimada - alturaNormal) / 2.0f;

    // 6. Calcula a posição final de desenho.
    //    A gente pega a posição base e subtrai o offset. Se o botão cresceu,
    //    isso "empurra" o ponto de desenho para a esquerda e para cima, fazendo
    //    com que o centro do botão permaneça no mesmo lugar.
    float posXDest = position.x - offsetX;
    float posYDest = position.y - offsetY;

    // 7. Prepara os retângulos de origem e destino para a Raylib.
    Rectangle sourceRec = {0, 0, larguraOriginal, alturaOriginal}; // Usa o sprite inteiro.
    Rectangle destRec = {posXDest, posYDest, larguraAnimada, alturaAnimada}; // Posição e tamanho finais.

    // 8. Desenha o botão na tela.
    DrawTexturePro(texture, sourceRec, destRec, (Vector2){0, 0}, 0.0f, WHITE);
}