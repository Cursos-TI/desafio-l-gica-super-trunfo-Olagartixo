#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dados da Carta 1
    char estado1[3];
    char codigo1[4];
    char cidade1[100];
    int populacao1;
    float area1;
    double pib1;
    int pontos_turisticos1;
    float densidade1;
    double pib_per_capita1;

    // Dados da Carta 2
    char estado2[3];
    char codigo2[4];
    char cidade2[100];
    int populacao2;
    float area2;
    double pib2;
    int pontos_turisticos2;
    float densidade2;
    double pib_per_capita2;


    // Cadastro das Cartas
    printf("Cadastro da Carta 1:\n");
    printf("Estado (ex: A-H): ");
    scanf("%2s", estado1);

    printf("Codigo da carta (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Nome da cidade (sem espacos): ");
    scanf("%99s", cidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes de reais): ");
    scanf("%lf", &pib1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos1);

    // Cálculos
    densidade1 = (area1 > 0) ? (float)populacao1 / area1 : 0;
    pib_per_capita1 = (populacao1 > 0) ? (pib1 * 1000000000) / populacao1 : 0;

    printf("\nCadastro da Carta 2:\n");
    printf("Estado (ex: A-H): ");
    scanf("%2s", estado2);

    printf("Codigo da carta (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Nome da cidade (sem espacos): ");
    scanf("%99s", cidade2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes de reais): ");
    scanf("%lf", &pib2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos
    densidade2 = (area2 > 0) ? (float)populacao2 / area2 : 0;
    pib_per_capita2 = (populacao2 > 0) ? (pib2 * 1000000000) / populacao2 : 0;


    // Menu Interativo
    int opcao1, opcao2;
    printf("\n--- MODO DE DISPUTA ---\n");
    printf("Escolha DOIS atributos para a disputa.\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica (MENOR vence)\n");
    printf("6 - PIB per Capita\n");

    printf("\nEscolha o PRIMEIRO atributo: ");
    scanf("%d", &opcao1);
    printf("Escolha o SEGUNDO atributo: ");
    scanf("%d", &opcao2);

    // Validação para garantir que o usuário escolheu opções válidas e distintas
    if (opcao1 < 1 || opcao1 > 6 || opcao2 < 1 || opcao2 > 6) {
       printf("\nErro: Opcao invalida. Encerrando.\n");
       exit(1);
    }
    if (opcao1 == opcao2) {
        printf("\nErro: Os atributos escolhidos devem ser diferentes. Encerrando.\n");
        exit(1);
    }

    // Lógica de Pontuação
    int pontos_carta1 = 0;
    int pontos_carta2 = 0;
    int vencedor_rodada = 0; // 0=empate, 1=carta1, 2=carta2
    const char* nomes_atributos[] = {"", "Populacao", "Area", "PIB", "Pontos Turisticos", "Densidade", "PIB per Capita"};

    printf("\n===== INICIANDO A DISPUTA =====\n");

    // --- Rodada 1: Comparando o primeiro atributo (opcao1) ---
    switch(opcao1) {
        case 1: vencedor_rodada = (populacao1 > populacao2) ? 1 : ((populacao2 > populacao1) ? 2 : 0); break;
        case 2: vencedor_rodada = (area1 > area2) ? 1 : ((area2 > area1) ? 2 : 0); break;
        case 3: vencedor_rodada = (pib1 > pib2) ? 1 : ((pib2 > pib1) ? 2 : 0); break;
        case 4: vencedor_rodada = (pontos_turisticos1 > pontos_turisticos2) ? 1 : ((pontos_turisticos2 > pontos_turisticos1) ? 2 : 0); break;
        case 5: vencedor_rodada = (densidade1 < densidade2) ? 1 : ((densidade2 < densidade1) ? 2 : 0); break;
        case 6: vencedor_rodada = (pib_per_capita1 > pib_per_capita2) ? 1 : ((pib_per_capita2 > pib_per_capita1) ? 2 : 0); break;
    }

    printf("Disputa 1 (%s): ", nomes_atributos[opcao1]);
    if (vencedor_rodada == 1) {
        pontos_carta1++;
        printf("Ponto para %s!\n", cidade1);
    } else if (vencedor_rodada == 2) {
        pontos_carta2++;
        printf("Ponto para %s!\n", cidade2);
    } else {
        printf("Empate!\n");
    }

    // --- Rodada 2: Comparando o segundo atributo (opcao2) ---
    switch(opcao2) {
        case 1: vencedor_rodada = (populacao1 > populacao2) ? 1 : ((populacao2 > populacao1) ? 2 : 0); break;
        case 2: vencedor_rodada = (area1 > area2) ? 1 : ((area2 > area1) ? 2 : 0); break;
        case 3: vencedor_rodada = (pib1 > pib2) ? 1 : ((pib2 > pib1) ? 2 : 0); break;
        case 4: vencedor_rodada = (pontos_turisticos1 > pontos_turisticos2) ? 1 : ((pontos_turisticos2 > pontos_turisticos1) ? 2 : 0); break;
        case 5: vencedor_rodada = (densidade1 < densidade2) ? 1 : ((densidade2 < densidade1) ? 2 : 0); break;
        case 6: vencedor_rodada = (pib_per_capita1 > pib_per_capita2) ? 1 : ((pib_per_capita2 > pib_per_capita1) ? 2 : 0); break;
    }

    printf("Disputa 2 (%s): ", nomes_atributos[opcao2]);
    if (vencedor_rodada == 1) {
        pontos_carta1++;
        printf("Ponto para %s!\n", cidade1);
    } else if (vencedor_rodada == 2) {
        pontos_carta2++;
        printf("Ponto para %s!\n", cidade2);
    } else {
        printf("Empate!\n");
    }

    // Resultado Final da Disputa
    printf("\n--- RESULTADO FINAL DA DISPUTA ---\n");
    printf("Placar Final: %s %d X %d %s\n", cidade1, pontos_carta1, pontos_carta2, cidade2);

    if (pontos_carta1 > pontos_carta2) {
        printf("A carta vencedora e: %s!\n", cidade1);
    } else if (pontos_carta2 > pontos_carta1) {
        printf("A carta vencedora e: %s!\n", cidade2);
    } else {
        printf("A disputa terminou em EMPATE!\n");
    }

    return 0;
}