#include <stdio.h>
#include <stdlib.h> 

#define maxMalasTotal 45      
#define maxMalasPassageiro 25  

int main() {
    // variaveis
    int numPas,numMal,numMalT = 0,limite_atingido = 0; // flag de controle (0=F, 1=V)
    int numMalBT = 0,numMalAT = 0;
    // arrays para armazenar pesos
    float pesMal[maxMalasTotal],bagA[maxMalasPassageiro],bagB[maxMalasPassageiro];
    // Acumuladores de peso 
    float numPesMalT = 0.0f,bagAPesT = 0.0f,bagBPesT = 0.0f;
    
    printf("informe o numero de passageiros: \n");
    if (scanf("%d", &numPas) != 1 || numPas <= 0) {
        printf("Nenhum passageiro ou entrada invalida. Encerrando o programa.\n");
        return 0;
    }
    // --- leitura ---
    // loop de Passageiros 
    for (int i = 0; i < numPas && limite_atingido == 0; i++) {
        printf("Passageiro %d: informe o numero de malas:\n", i + 1);
        //scanf retorna 1 ,se for numero inteiro,se não for inteiro retorna 0 e exibe a mensagem
        if (scanf("%d", &numMal) != 1 || numMal < 0) {
             printf("Numero de malas invalido. Pulando passageiro.\n");
             continue;
        }

        // loop das Malas do passageiro atual
        for (int j = 0; j < numMal; j++) {
            // Verifica o limite global antes de armazenar
            if (numMalT >= maxMalasTotal) {
                printf("Limite maximo de %d malas atingido. Parando coleta.\n", maxMalasTotal);
                limite_atingido = 1; // Ativa a flag para parar o loop externo
                break;              // Sai do loop 'j' (malas)
            }
            
            float pesoMala;
            printf("  Informe o peso (kg) da mala %d:\n", j + 1);
            if (scanf("%f", &pesoMala) != 1 || pesoMala <= 0.0f) {
                printf("Peso invalido. Pulando mala.\n");
                // continuar o codigo
                continue;
            }
            
            // Armazena no array total
            pesMal[numMalT] = pesoMala;
            numPesMalT += pesoMala;
            numMalT++; // Incrementa o contador GLOBAL de malas lidas
        }
    } // O loop 'i' vai parar na próxima iteração se limite_atingido for 1.
    
    if (numMalT == 0) {
        printf("\nNenhuma mala para distribuir.\n");
        return 0;
    }
    
    // --- equilibrio do pesos das malas ---
    
    for (int i = 0; i < numMalT; i++) {
        float pesoMalaAtual = pesMal[i];
        
        // coloca a mala no bagageiro com o [MENOR] peso atual
        if (bagAPesT <= bagBPesT) {
            // tenta colocar no Bagageiro A (se não estiver cheio)
            if (numMalAT < maxMalasPassageiro) {
                bagA[numMalAT] = pesoMalaAtual;
                bagAPesT += pesoMalaAtual;
                numMalAT++;
            } else if (numMalBT < maxMalasPassageiro) { 
                // A está cheio, tenta B
                bagB[numMalBT] = pesoMalaAtual;
                bagBPesT += pesoMalaAtual;
                numMalBT++;
            } else {
                 printf("AVISO: Mala %.2f kg nao alocada. Ambos os bagageiros estao cheios.\n", pesoMalaAtual);
            }
        } else { // bagBPesT < bagAPesT
            // tenta colocar no Bagageiro B (se não estiver cheio)
            if (numMalBT < maxMalasPassageiro) {
                bagB[numMalBT] = pesoMalaAtual;
                bagBPesT += pesoMalaAtual;
                numMalBT++;
            } else if (numMalAT < maxMalasPassageiro) { 
                // B está cheio, tenta A
                bagA[numMalAT] = pesoMalaAtual;
                bagAPesT += pesoMalaAtual;
                numMalAT++;
            } else {
                 printf("AVISO: Mala %.2f kg nao alocada. Ambos os bagageiros estao cheios.\n", pesoMalaAtual);
            }
        }
    }

    // --- exibição ---
    
    printf("\nnumero total das malas: %d\n", numMalT);
    printf("numero peso total das malas: %.2f kg \n", numPesMalT);
    
    printf("\n----Bagageiro A----\n");
    printf("numero total das malas Bag A: %d \n", numMalAT);
    printf("numero peso total das malas Bag A: %.2f kg\n", bagAPesT);
    for(int i = 0; i < numMalAT; i++){
        printf("bagA[%d],peso: %.2f kg\n", i + 1, bagA[i]);
    }
    
    printf("\n----Bagageiro B----\n");
    printf("numero total das malas Bag B: %d \n", numMalBT);
    printf("numero peso total das malas Bag B: %.2f kg\n", bagBPesT);
    for(int i = 0; i < numMalBT; i++){
        printf("bagB[%d],peso: %.2f kg\n", i + 1, bagB[i]);
    }
    //para conferir deu muito erro antes!!!
    printf("\nVERIFICACAO: (Peso A + Peso B = %.2f kg)\n", bagAPesT + bagBPesT);
    
    return 0;
}