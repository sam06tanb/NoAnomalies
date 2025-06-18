/**
 * @file seletor_resolucao.c
 * @brief Contém a lógica e o desenho do componente de UI para selecionar a resolução.
 *
 * Este componente permite ao jogador ciclar entre uma lista pré-definida de resoluções
 * usando botões de seta para a esquerda e para a direita. Ele atualiza um índice no estado
 * do jogo e desenha os sprites correspondentes.
 */

#include "seletor_resolucao.h"
#include "defines.h"

/**
 * @brief Atualiza o estado do seletor de resolução com base nos cliques do mouse nas setas.
 *
 * Esta função é chamada a cada frame quando o pop-up de opções está visível.
 * Ela calcula a área clicável (hitbox) das setas e verifica se o jogador clicou nelas.
 * Se um clique ocorrer, ela atualiza o 'indiceResolucaoAtual' no estado do jogo,
 * implementando uma lógica de "wrap-around" para que a seleção seja um ciclo contínuo.
 *
 * @param jogo Ponteiro para o estado geral do jogo, usado para ler e modificar o índice da resolução.
 * @param mousePos A posição virtual do mouse na tela.
 * @param painelPos A posição do canto superior esquerdo do painel de opções, usada como referência.
 */
void UpdateSeletorResolucao(EstadoJogo *jogo, Vector2 mousePos, Vector2 painelPos) {

    // Largura do painel para ajudar a calcular a posição da seta direita
    float painelLargura = (float)jogo->options.painelPopupOpcoes.width;

    // --- Posições e Hitboxes das Setas ---
    Vector2 posSetaEsquerda = {
        painelPos.x + 150,
        painelPos.y + 450
    };
    Vector2 posSetaDireita = {
        painelPos.x + painelLargura - 150 - jogo->options.setaDireita.width,
        posSetaEsquerda.y
    };

    Rectangle hitboxSetaEsquerda = {
        posSetaEsquerda.x, posSetaEsquerda.y,
        (float)jogo->options.setaEsquerda.width, (float)jogo->options.setaEsquerda.height
    };
    Rectangle hitboxSetaDireita = {
        posSetaDireita.x, posSetaDireita.y,
        (float)jogo->options.setaDireita.width, (float)jogo->options.setaDireita.height
    };

    // --- Lógica de Clique da Seta Esquerda ---
    if (CheckCollisionPointRec(mousePos, hitboxSetaEsquerda)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->indiceResolucoesAtual--;
            // Se o índice ficar negativo, ele "dá a volta" e vai para o final da lista.
            if (jogo->indiceResolucoesAtual < 0) {
                jogo->indiceResolucoesAtual = NUM_RESOLUCOES - 1; // Ex: se NUM_RESOLUCOES é 4, vai para o índice 3.
            }
        }
    }

    // --- Lógica de Clique da Seta Direita ---
    if (CheckCollisionPointRec(mousePos, hitboxSetaDireita)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            jogo->indiceResolucoesAtual++;
            // Se o índice passar do último item válido, ele "dá a volta" e volta para o início (0).
            if (jogo->indiceResolucoesAtual >= NUM_RESOLUCOES) {
                jogo->indiceResolucoesAtual = 0;
            }
        }
    }
}


/**
 * @brief Desenha os componentes visuais do seletor de resolução (setas e o sprite da resolução atual).
 *
 * Esta função desenha os três elementos visuais do seletor:
 * 1. O sprite da seta esquerda.
 * 2. O sprite da seta direita.
 * 3. O sprite da resolução ATUALMENTE selecionada (ex: "1920x1080.png"), que é escolhido
 * do array de texturas usando o 'indiceResolucaoAtual' do estado do jogo.
 * O sprite da resolução é posicionado de forma a ficar sempre centralizado entre as duas setas.
 *
 * @param jogo Ponteiro (const) para o estado do jogo, usado para ler qual resolução mostrar.
 * @param painelPos A posição do painel de opções, usada como referência para desenhar.
 */
void DrawSeletorResolucao(const EstadoJogo *jogo, Vector2 painelPos) {

    // --- Posições das Setas (devem ser idênticas às da função de Update) ---
    Vector2 posSetaEsquerda = {painelPos.x + 150, painelPos.y + 450};
    Vector2 posSetaDireita = {
        painelPos.x + (float)jogo->options.painelPopupOpcoes.width - 150 - (float)jogo->options.setaDireita.width,
        posSetaEsquerda.y
    };

    // Desenha os sprites das duas setas
    DrawTextureV(jogo->options.setaEsquerda, posSetaEsquerda, WHITE);
    DrawTextureV(jogo->options.setaDireita, posSetaDireita, WHITE);

    // Pega o sprite da resolução que está selecionada no momento
    Texture2D spriteResAtual = jogo->options.spritesResolucao[jogo->indiceResolucoesAtual];

    // Só desenha se a textura foi carregada corretamente
    if (spriteResAtual.id > 0) {
        // Calcula o ponto central do espaço VAZIO entre as duas setas
        float meioDoEspacoEntreSetas = posSetaEsquerda.x + jogo->options.setaEsquerda.width +
                                       ((posSetaDireita.x - (posSetaEsquerda.x + jogo->options.setaEsquerda.width)) / 2.0f);

        // Calcula a posição do sprite da resolução para que o CENTRO dele fique no 'meioDoEspacoEntreSetas'
        Vector2 posSpriteResolucao = {
            meioDoEspacoEntreSetas - (float) spriteResAtual.width / 2.0f,
            posSetaEsquerda.y - 30 // Um ajuste fino para subir um pouco o texto visualmente
        };

        // Desenha o sprite da resolução selecionada
        DrawTextureV(spriteResAtual, posSpriteResolucao, WHITE);
    }
}