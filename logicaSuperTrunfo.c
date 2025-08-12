#include <stdio.h>

struct Carta {
    char estado[3];
    char codigo[4];
    char cidade[100];
    int populacao;
    float area;
    double pib; // PIB em bilhões de reais
    int pontos_turisticos;
    float densidade;
    double pib_per_capita;
};

int main() {
    struct Carta carta1, carta2;

    // ===== Cadastro das Cartas =====
    printf("Cadastro da Carta 1:\n");
    printf("Estado (ex: A-H): ");
    scanf("%2s", carta1.estado);

    printf("Codigo da carta (ex: A01): ");
    scanf("%3s", carta1.codigo);

    printf("Nome da cidade (sem espacos): ");
    scanf("%99s", carta1.cidade);

    printf("Populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhoes de reais): ");
    scanf("%lf", &carta1.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cálculos
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao;

    printf("\nCadastro da Carta 2:\n");
    printf("Estado (ex: A-H): ");
    scanf("%2s", carta2.estado);

    printf("Codigo da carta (ex: B02): ");
    scanf("%3s", carta2.codigo);

    printf("Nome da cidade (sem espacos): ");
    scanf("%99s", carta2.cidade);

    printf("Populacao: ");
    scanf("%d", &carta2.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhoes de reais): ");
    scanf("%lf", &carta2.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Cálculos
    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1000000000) / carta2.populacao;

    // ===== Menu Interativo =====
    int opcao;
    printf("\nEscolha o atributo para comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\n===== Resultado da Comparacao =====\n");

    switch(opcao) {
        case 1: // População
            printf("Comparacao de Populacao:\n");
            printf("%s: %d habitantes\n", carta1.cidade, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.cidade, carta2.populacao);
            if(carta1.populacao > carta2.populacao)
                printf("Vencedor: %s!\n", carta1.cidade);
            else if(carta2.populacao > carta1.populacao)
                printf("Vencedor: %s!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Comparacao de Area:\n");
            printf("%s: %.2f km²\n", carta1.cidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.cidade, carta2.area);
            if(carta1.area > carta2.area)
                printf("Vencedor: %s!\n", carta1.cidade);
            else if(carta2.area > carta1.area)
                printf("Vencedor: %s!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Comparacao de PIB:\n");
            printf("%s: %.2lf bilhoes de reais\n", carta1.cidade, carta1.pib);
            printf("%s: %.2lf bilhoes de reais\n", carta2.cidade, carta2.pib);
            if(carta1.pib > carta2.pib)
                printf("Vencedor: %s!\n", carta1.cidade);
            else if(carta2.pib > carta1.pib)
                printf("Vencedor: %s!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos Turísticos
            printf("Comparacao de Pontos Turisticos:\n");
            printf("%s: %d pontos\n", carta1.cidade, carta1.pontos_turisticos);
            printf("%s: %d pontos\n", carta2.cidade, carta2.pontos_turisticos);
            if(carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("Vencedor: %s!\n", carta1.cidade);
            else if(carta2.pontos_turisticos > carta1.pontos_turisticos)
                printf("Vencedor: %s!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade Demográfica (menor vence)
            printf("Comparacao de Densidade Demografica:\n");
            printf("%s: %.2f hab/km²\n", carta1.cidade, carta1.densidade);
            printf("%s: %.2f hab/km²\n", carta2.cidade, carta2.densidade);
            if(carta1.densidade < carta2.densidade)
                printf("Vencedor: %s!\n", carta1.cidade);
            else if(carta2.densidade < carta1.densidade)
                printf("Vencedor: %s!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;

        case 6: // PIB per capita
            printf("Comparacao de PIB per Capita:\n");
            printf("%s: %.2lf reais\n", carta1.cidade, carta1.pib_per_capita);
            printf("%s: %.2lf reais\n", carta2.cidade, carta2.pib_per_capita);
            if(carta1.pib_per_capita > carta2.pib_per_capita)
                printf("Vencedor: %s!\n", carta1.cidade);
            else if(carta2.pib_per_capita > carta1.pib_per_capita)
                printf("Vencedor: %s!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}
