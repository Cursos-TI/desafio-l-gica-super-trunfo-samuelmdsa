/*
  super_trunfo.c
  Nível: Novato
  Objetivo: Comparar duas cartas do Super Trunfo usando um único atributo numérico
  Autor: Samuel Marcelino dos Santos
  Compilar: gcc -o super_trunfo super_trunfo.c
*/

#include <stdio.h>
#include <string.h>

/* --- Escolha do atributo de comparação ---
   Ajuste esta constante para escolher o atributo usado na comparação.
   0 = População (maior vence)
   1 = Área (maior vence)
   2 = PIB (maior vence)
   3 = Número de pontos turísticos (maior vence)
   4 = Densidade Populacional (menor vence)
   5 = PIB per capita (maior vence)
*/
#define COMPARE_ATTRIBUTE 0

/* Constantes para leitura do atributo em texto */
const char *attribute_names[] = {
    "População",
    "Área",
    "PIB",
    "Número de pontos turísticos",
    "Densidade Populacional",
    "PIB per capita"
};

/* Estrutura que representa uma carta */
typedef struct {
    char estado[4];        // ex: "SP"
    char codigo[16];       // codigo da carta
    char nome[64];         // nome da cidade
    int populacao;         // população (int)
    float area;            // área em km^2 (float)
    float pib;             // PIB em milhões (ou unidades que desejar) (float)
    int pontos_turisticos; // número de pontos turísticos (int)
    float densidade;       // população / área (float)
    float pib_per_capita;  // pib / populacao (float)
} Carta;

/* Função para calcular densidade e pib per capita */
void calcular_indicadores(Carta *c) {
    if (c->area > 0.0f) {
        c->densidade = (float)c->populacao / c->area;
    } else {
        c->densidade = 0.0f; // proteção contra divisão por zero
    }

    if (c->populacao > 0) {
        c->pib_per_capita = c->pib / (float)c->populacao;
    } else {
        c->pib_per_capita = 0.0f;
    }
}

/* Imprime resumo da carta (usado para exibir resultados) */
void imprimir_carta(const Carta *c, int id) {
    printf("Carta %d - %s (%s)\n", id, c->nome, c->estado);
    printf("  Código: %s\n", c->codigo);
    printf("  População: %d\n", c->populacao);
    printf("  Área: %.2f km^2\n", c->area);
    printf("  PIB: %.2f\n", c->pib);
    printf("  Pontos turísticos: %d\n", c->pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km^2\n", c->densidade);
    printf("  PIB per capita: %.6f (PIB/unidade de população)\n", c->pib_per_capita);
    printf("\n");
}

int main() {
    /* --- Duas cartas pré-definidas (ajuste os valores conforme desejar) --- */
    Carta carta1 = {
        .estado = "SP",
        .codigo = "SP001",
        .nome = "São Paulo",
        .populacao = 12300000,
        .area = 1521.11f,
        .pib = 700000.0f, /* unidade arbitrária */
        .pontos_turisticos = 45
    };

    Carta carta2 = {
        .estado = "RJ",
        .codigo = "RJ002",
        .nome = "Rio de Janeiro",
        .populacao = 6000000,
        .area = 1182.3f,
        .pib = 350000.0f, /* unidade arbitrária */
        .pontos_turisticos = 55
    };

    /* Calcular indicadores derivados */
    calcular_indicadores(&carta1);
    calcular_indicadores(&carta2);

    /* Exibir cartas e indicadores */
    printf("===== Cartas cadastradas e indicadores calculados =====\n\n");
    imprimir_carta(&carta1, 1);
    imprimir_carta(&carta2, 2);

    /* Seleciona qual atributo será comparado (definido via COMPARE_ATTRIBUTE) */
    int attr = COMPARE_ATTRIBUTE;
    printf("Comparação de cartas (Atributo: %s):\n\n", attribute_names[attr]);
    /* Exibir valor do atributo para cada carta */
    switch (attr) {
        case 0: // População
            printf("Carta 1 - %s (%s): %d\n\n", carta1.nome, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%s): %d\n\n", carta2.nome, carta2.estado, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
            else if (carta2.populacao > carta1.populacao)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 1: // Área
            printf("Carta 1 - %s (%s): %.2f km^2\n\n", carta1.nome, carta1.estado, carta1.area);
            printf("Carta 2 - %s (%s): %.2f km^2\n\n", carta2.nome, carta2.estado, carta2.area);
            if (carta1.area > carta2.area)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
            else if (carta2.area > carta1.area)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // PIB
            printf("Carta 1 - %s (%s): %.2f\n\n", carta1.nome, carta1.estado, carta1.pib);
            printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nome, carta2.estado, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
            else if (carta2.pib > carta1.pib)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // Número de pontos turísticos
            printf("Carta 1 - %s (%s): %d\n\n", carta1.nome, carta1.estado, carta1.pontos_turisticos);
            printf("Carta 2 - %s (%s): %d\n\n", carta2.nome, carta2.estado, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
            else if (carta2.pontos_turisticos > carta1.pontos_turisticos)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Densidade Populacional -> menor vence (regra do enunciado)
            printf("Carta 1 - %s (%s): %.2f hab/km^2\n\n", carta1.nome, carta1.estado, carta1.densidade);
            printf("Carta 2 - %s (%s): %.2f hab/km^2\n\n", carta2.nome, carta2.estado, carta2.densidade);
            if (carta1.densidade < carta2.densidade)
                printf("Resultado: Carta 1 (%s) venceu! (menor densidade é melhor)\n", carta1.nome);
            else if (carta2.densidade < carta1.densidade)
                printf("Resultado: Carta 2 (%s) venceu! (menor densidade é melhor)\n", carta2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // PIB per capita
            printf("Carta 1 - %s (%s): %.6f\n\n", carta1.nome, carta1.estado, carta1.pib_per_capita);
            printf("Carta 2 - %s (%s): %.6f\n\n", carta2.nome, carta2.estado, carta2.pib_per_capita);
            if (carta1.pib_per_capita > carta2.pib_per_capita)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
            else if (carta2.pib_per_capita > carta1.pib_per_capita)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Atributo inválido selecionado para comparação.\n");
    }

    return 0;
}
