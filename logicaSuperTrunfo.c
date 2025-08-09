#include <stdio.h>

int main() {
    // ==== Estrutura de dados da carta ====
    char estado1[3], codigo1[4], nomeCidade1[50];
    char estado2[3], codigo2[4], nomeCidade2[50];
    unsigned long int populacao1, populacao2; // População grande
    double area1, area2, pib1, pib2; // PIB em bilhões
    int pontosTuristicos1, pontosTuristicos2;

    // ==== Entrada de dados da Carta 1 ====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (sigla): ");
    scanf("%2s", estado1);
    printf("Codigo da carta: ");
    scanf("%3s", codigo1);
    printf("Nome da cidade: ");
    scanf(" %99s", nomeCidade1);
    printf("Populacao: ");
    scanf("%lu", &populacao1);
    printf("Area (km²): ");
    scanf("%lf", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%lf", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // ==== Entrada de dados da Carta 2 ====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (sigla): ");
    scanf("%2s", estado2);
    printf("Codigo da carta: ");
    scanf("%3s", codigo2);
    printf("Nome da cidade: ");
    scanf("%99s", nomeCidade2);
    printf("Populacao: ");
    scanf("%lu", &populacao2);
    printf("Area (km²): ");
    scanf("%lf", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%lf", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // ==== Cálculos adicionais ====
    double densidade1 = populacao1 / area1;
    double densidade2 = populacao2 / area2;
    double pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;
    double pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // ==== Escolha do atributo para comparação ====
    // 1 - População | 2 - Área | 3 - PIB | 4 - Densidade | 5 - PIB per capita
    int atributoEscolhido = 1; // altere aqui para mudar o critério

    printf("\n=== Comparação de Cartas ===\n");
    if (atributoEscolhido == 1) {
        printf("Atributo: População\n");
        printf("%s: %lu\n", nomeCidade1, populacao1);
        printf("%s: %lu\n", nomeCidade2, populacao2);
        if (populacao1 > populacao2)
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        else if (populacao2 > populacao1)
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        else
            printf("Empate!\n");
    }
    else if (atributoEscolhido == 2) {
        printf("Atributo: Área (km²)\n");
        printf("%s: %.2lf\n", nomeCidade1, area1);
        printf("%s: %.2lf\n", nomeCidade2, area2);
        if (area1 > area2)
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        else if (area2 > area1)
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        else
            printf("Empate!\n");
    }
    else if (atributoEscolhido == 3) {
        printf("Atributo: PIB (bilhões de R$)\n");
        printf("%s: %.2lf\n", nomeCidade1, pib1);
        printf("%s: %.2lf\n", nomeCidade2, pib2);
        if (pib1 > pib2)
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        else if (pib2 > pib1)
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        else
            printf("Empate!\n");
    }
    else if (atributoEscolhido == 4) {
        printf("Atributo: Densidade Populacional (hab/km²)\n");
        printf("%s: %.2lf\n", nomeCidade1, densidade1);
        printf("%s: %.2lf\n", nomeCidade2, densidade2);
        if (densidade1 < densidade2)
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        else if (densidade2 < densidade1)
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        else
            printf("Empate!\n");
    }
    else if (atributoEscolhido == 5) {
        printf("Atributo: PIB per capita (R$)\n");
        printf("%s: %.2lf\n", nomeCidade1, pibPerCapita1);
        printf("%s: %.2lf\n", nomeCidade2, pibPerCapita2);
        if (pibPerCapita1 > pibPerCapita2)
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        else if (pibPerCapita2 > pibPerCapita1)
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        else
            printf("Empate!\n");
    }

    return 0;
}
