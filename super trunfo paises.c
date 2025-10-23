#include <stdio.h>
#include <stdlib.h>

// Define o tamanho máximo para as strings
#define MAX_STRING 50

// Definindo a estrutura (struct) para uma Carta de Cidade
struct CartaSuperTrunfo {
    // Dados de Entrada
    char estado;                      
    char codigo[5];                   
    char nome_cidade[MAX_STRING];     
    int populacao;                    
    float area_km2;                   
    float pib_bilhoes;                
    int num_pontos_turisticos;        

    // Novas Variáveis de Saída (Cálculos)
    float densidade_populacional;     // População / Área (hab/km2)
    float pib_per_capita;             // (PIB_bilhoes * 1.000.000.000) / População
};


// Desafio Super Trunfo - Países
// Tema 2 - Cálculos e Novas Propriedades
// Objetivo: Calcular Densidade Populacional e PIB per Capita.

int main() {
    // Área para definição das variáveis para armazenar as propriedades das cidades
    
    // Declaração de duas cartas, utilizando a struct definida.
    struct CartaSuperTrunfo carta1;
    struct CartaSuperTrunfo carta2;
    
    // Constante para facilitar o cálculo do PIB per Capita (1 bilhão)
    const float BILHAO = 1000000000.0; 


    // --------------------------------------------------------------------------------
    // ÁREA PARA ENTRADA DE DADOS - CARTA 1
    // --------------------------------------------------------------------------------
    printf("==================================================\n");
    printf("             CADASTRO DA CARTA 1\n");
    printf("==================================================\n");

    printf("1. Insira o Estado (letra de A a H): ");
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
    // CÁLCULOS DA CARTA 1 (Eficiência)
    // --------------------------------------------------------------------------------
    
    // 1. Densidade Populacional = População / Área
    // É essencial fazer o casting para float na Populacao para garantir a divisão correta.
    carta1.densidade_populacional = (float)carta1.populacao / carta1.area_km2;
    
    // 2. PIB per Capita = (PIB_bilhoes * 1.000.000.000) / População
    // Convertemos o PIB de "bilhões" para o valor total antes de dividir pela população.
    float pib_total_c1 = carta1.pib_bilhoes * BILHAO;
    carta1.pib_per_capita = pib_total_c1 / (float)carta1.populacao;
    
    
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
    // CÁLCULOS DA CARTA 2 (Eficiência)
    // --------------------------------------------------------------------------------
    
    // 1. Densidade Populacional = População / Área
    carta2.densidade_populacional = (float)carta2.populacao / carta2.area_km2;
    
    // 2. PIB per Capita = (PIB_bilhoes * 1.000.000.000) / População
    float pib_total_c2 = carta2.pib_bilhoes * BILHAO;
    carta2.pib_per_capita = pib_total_c2 / (float)carta2.populacao;


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
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area_km2);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib_bilhoes); 
    printf("Número de Pontos Turísticos: %d\n", carta1.num_pontos_turisticos);
    
    // NOVOS DADOS CALCULADOS
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pib_per_capita);
    
    // Exibição da Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nome_cidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area_km2);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib_bilhoes);
    printf("Número de Pontos Turísticos: %d\n", carta2.num_pontos_turisticos);
    
    // NOVOS DADOS CALCULADOS
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pib_per_capita);

    printf("\n==================================================\n");

    return 0;
}