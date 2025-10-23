#include <stdio.h>
#include <stdlib.h> // Para a simplicidade do scanf de string sem espacos

// Define o tamanho máximo para as strings
#define MAX_STRING 50

// Definindo a estrutura (struct) para uma Carta de Cidade
struct CartaSuperTrunfo {
    char estado;                      // Ex: 'A'
    char codigo[5];                   // Ex: "A01"
    char nome_cidade[MAX_STRING];     // Ex: "São Paulo"
    int populacao;                    // Ex: 12325000
    float area_km2;                   // Ex: 1521.11
    float pib_bilhoes;                // Ex: 699.28
    int num_pontos_turisticos;        // Ex: 50
};


// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
    // Área para definição das variáveis para armazenar as propriedades das cidades
    
    // Declaração de duas cartas, utilizando a struct definida.
    struct CartaSuperTrunfo carta1;
    struct CartaSuperTrunfo carta2;


    // --------------------------------------------------------------------------------
    // ÁREA PARA ENTRADA DE DADOS - CARTA 1
    // --------------------------------------------------------------------------------
    printf("==================================================\n");
    printf("             CADASTRO DA CARTA 1\n");
    printf("==================================================\n");

    printf("1. Insira o Estado (letra de A a H): ");
    // O espaco em " %c" ignora o enter/nova linha
    scanf(" %c", &carta1.estado); 
    
    printf("2. Insira o Codigo da Carta (ex: A01): ");
    scanf("%s", carta1.codigo); 
    
    printf("3. Insira o Nome da Cidade (sem espacos): ");
    scanf("%s", carta1.nome_cidade); 
    
    printf("4. Insira a Populacao (int): ");
    scanf("%d", &carta1.populacao);
    
    printf("5. Insira a Area em km2 (float): ");
    scanf("%f", &carta1.area_km2);
    
    printf("6. Insira o PIB (em bilhoes de R$): ");
    scanf("%f", &carta1.pib_bilhoes);
    
    printf("7. Insira o Num. de Pontos Turisticos (int): ");
    scanf("%d", &carta1.num_pontos_turisticos);
    

    // --------------------------------------------------------------------------------
    // ÁREA PARA ENTRADA DE DADOS - CARTA 2
    // --------------------------------------------------------------------------------
    printf("\n==================================================\n");
    printf("             CADASTRO DA CARTA 2\n");
    printf("==================================================\n");

    printf("1. Insira o Estado (letra de A a H): ");
    scanf(" %c", &carta2.estado);
    
    printf("2. Insira o Codigo da Carta (ex: B02): ");
    scanf("%s", carta2.codigo);
    
    printf("3. Insira o Nome da Cidade (sem espacos): ");
    scanf("%s", carta2.nome_cidade);
    
    printf("4. Insira a Populacao (int): ");
    scanf("%d", &carta2.populacao);
    
    printf("5. Insira a Area em km2 (float): ");
    scanf("%f", &carta2.area_km2);
    
    printf("6. Insira o PIB (em bilhoes de R$): ");
    scanf("%f", &carta2.pib_bilhoes);
    
    printf("7. Insira o Num. de Pontos Turisticos (int): ");
    scanf("%d", &carta2.num_pontos_turisticos);


    // --------------------------------------------------------------------------------
    // ÁREA PARA EXIBIÇÃO DOS DADOS DA CIDADE
    // --------------------------------------------------------------------------------
    printf("\n\n==================================================\n");
    printf("          INFORMACOES DAS CARTAS CADASTRADAS\n");
    printf("==================================================\n");
    
    // Exibição da Carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nome_cidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km2\n", carta1.area_km2);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib_bilhoes); 
    printf("Numero de Pontos Turisticos: %d\n", carta1.num_pontos_turisticos);
    
    // Exibição da Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nome_cidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km2\n", carta2.area_km2);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib_bilhoes);
    printf("Numero de Pontos Turisticos: %d\n", carta2.num_pontos_turisticos);

    printf("\n==================================================\n");

    return 0;
}