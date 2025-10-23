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
    unsigned long int populacao;      // <<-- TIPO ALTERADO: unsigned long int
    float area_km2;                   
    float pib_bilhoes;                
    int num_pontos_turisticos;        

    // Variáveis de Saída (Cálculos)
    float densidade_populacional;     
    float pib_per_capita;             
    float super_poder;                // Novo atributo
};


// Constante para facilitar o cálculo do PIB per Capita (1 bilhão)
const float BILHAO = 1000000000.0; 


// =======================================================
// FUNÇÃO PRINCIPAL
// =======================================================
int main() {
    
    // Declaração de duas cartas
    struct CartaSuperTrunfo carta1;
    struct CartaSuperTrunfo carta2;
    
    // Variáveis para armazenar o resultado da comparação (0 ou 1)
    int pop_vence, area_vence, pib_vence, pontos_vence;
    int densidade_vence, pib_pc_vence, super_poder_vence;


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
    
    printf("4. Insira a Populacao (unsigned long int): ");
    // <<-- USO DE %lu PARA unsigned long int
    scanf("%lu", &carta1.populacao);
    
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
    
    printf("4. Insira a Populacao (unsigned long int): ");
    scanf("%lu", &carta2.populacao);
    
    printf("5. Insira a Area em km2 (float): ");
    scanf("%f", &carta2.area_km2);
    
    printf("6. Insira o PIB (em bilhoes de R$): ");
    scanf("%f", &carta2.pib_bilhoes);
    
    printf("7. Insira o Num. de Pontos Turisticos (int): ");
    scanf("%d", &carta2.num_pontos_turisticos);


    // --------------------------------------------------------------------------------
    // CÁLCULOS: DENSIDADE, PIB PER CAPITA E SUPER PODER
    // --------------------------------------------------------------------------------
    
    // CARTA 1
    carta1.densidade_populacional = (float)carta1.populacao / carta1.area_km2;
    float pib_total_c1 = carta1.pib_bilhoes * BILHAO;
    carta1.pib_per_capita = pib_total_c1 / (float)carta1.populacao;
    
    // CÁLCULO DO SUPER PODER CARTA 1
    // Conversão de Tipos (Casting) é CRUCIAL aqui!
    carta1.super_poder = 
        (float)carta1.populacao + 
        carta1.area_km2 + 
        carta1.pib_bilhoes + 
        (float)carta1.num_pontos_turisticos + 
        carta1.pib_per_capita + 
        (1.0f / carta1.densidade_populacional); // Inverso da Densidade
        
    // CARTA 2
    carta2.densidade_populacional = (float)carta2.populacao / carta2.area_km2;
    float pib_total_c2 = carta2.pib_bilhoes * BILHAO;
    carta2.pib_per_capita = pib_total_c2 / (float)carta2.populacao;
    
    // CÁLCULO DO SUPER PODER CARTA 2
    carta2.super_poder = 
        (float)carta2.populacao + 
        carta2.area_km2 + 
        carta2.pib_bilhoes + 
        (float)carta2.num_pontos_turisticos + 
        carta2.pib_per_capita + 
        (1.0f / carta2.densidade_populacional); // Inverso da Densidade

    
    // --------------------------------------------------------------------------------
    // COMPARAÇÃO DAS CARTAS (Lógica Booleana)
    // --------------------------------------------------------------------------------

    // 1 VENCE: Maior População
    pop_vence = (carta1.populacao > carta2.populacao);
    
    // 1 VENCE: Maior Área
    area_vence = (carta1.area_km2 > carta2.area_km2);
    
    // 1 VENCE: Maior PIB
    pib_vence = (carta1.pib_bilhoes > carta2.pib_bilhoes);
    
    // 1 VENCE: Mais Pontos Turísticos
    pontos_vence = (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos);
    
    // 1 VENCE: MENOR Densidade Populacional (REGRA INVERSA)
    densidade_vence = (carta1.densidade_populacional < carta2.densidade_populacional);
    
    // 1 VENCE: Maior PIB per Capita
    pib_pc_vence = (carta1.pib_per_capita > carta2.pib_per_capita);
    
    // 1 VENCE: Maior Super Poder
    super_poder_vence = (carta1.super_poder > carta2.super_poder);
    
    
    // --------------------------------------------------------------------------------
    // ÁREA PARA EXIBIÇÃO DOS DADOS E RESULTADOS
    // --------------------------------------------------------------------------------
    
    // Exibição dos Dados Completos (Intermediário + Super Poder)
    printf("\n\n==================================================\n");
    printf("          INFORMACOES DAS CARTAS CADASTRADAS\n");
    printf("==================================================\n");
    
    // Exibição da Carta 1
    printf("\nCarta 1: %s\n", carta1.nome_cidade);
    printf("  Estado: %c | Codigo: %s\n", carta1.estado, carta1.codigo);
    printf("  População: %lu\n", carta1.populacao);
    printf("  Área: %.2f km²\n", carta1.area_km2);
    printf("  PIB: %.2f bi R$\n", carta1.pib_bilhoes); 
    printf("  Pontos Turísticos: %d\n", carta1.num_pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("  PIB per Capita: %.2f reais\n", carta1.pib_per_capita);
    printf("  SUPER PODER: %.2f\n", carta1.super_poder);
    
    // Exibição da Carta 2
    printf("\nCarta 2: %s\n", carta2.nome_cidade);
    printf("  Estado: %c | Codigo: %s\n", carta2.estado, carta2.codigo);
    printf("  População: %lu\n", carta2.populacao);
    printf("  Área: %.2f km²\n", carta2.area_km2);
    printf("  PIB: %.2f bi R$\n", carta2.pib_bilhoes);
    printf("  Pontos Turísticos: %d\n", carta2.num_pontos_turisticos);
    printf("  Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("  PIB per Capita: %.2f reais\n", carta2.pib_per_capita);
    printf("  SUPER PODER: %.2f\n", carta2.super_poder);
    
    
    // RESULTADOS DA COMPARAÇÃO
    printf("\n==================================================\n");
    printf("           RESULTADOS DA COMPARACAO\n");
    printf("==================================================\n");
    
    // Uso do operador ternário para imprimir "Carta 1 venceu" (se a comparação for 1) ou "Carta 2 venceu" (se for 0)
    printf("População: %s (%d)\n", pop_vence ? "Carta 1 venceu" : "Carta 2 venceu", pop_vence);
    printf("Área: %s (%d)\n", area_vence ? "Carta 1 venceu" : "Carta 2 venceu", area_vence);
    printf("PIB: %s (%d)\n", pib_vence ? "Carta 1 venceu" : "Carta 2 venceu", pib_vence);
    printf("Pontos Turísticos: %s (%d)\n", pontos_vence ? "Carta 1 venceu" : "Carta 2 venceu", pontos_vence);
    printf("Densidade Populacional: %s (%d)\n", densidade_vence ? "Carta 1 venceu" : "Carta 2 venceu", densidade_vence);
    printf("PIB per Capita: %s (%d)\n", pib_pc_vence ? "Carta 1 venceu" : "Carta 2 venceu", pib_pc_vence);
    printf("Super Poder: %s (%d)\n", super_poder_vence ? "Carta 1 venceu" : "Carta 2 venceu", super_poder_vence);

    printf("\n==================================================\n");

    return 0;
}