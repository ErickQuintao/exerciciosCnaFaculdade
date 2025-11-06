#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
void linha(void){
 printf("----------------------------------------\n");
}
void menu(void){
    //menu
    linha();
    printf(" -> Programa Loteria Mega <- \n");
    linha();
}
int numApostados(){
    //variaveis
    int ind;
    //parte1 inicio
    printf("->Informe a qnt. de Numero que deseja jogar(max:60): ");
    scanf("%d",&ind);
    linha();
    return ind;
}
void cartao(void){
    //Gerar novos números a cada aposta,estava com problema de numeros no gerador de num ale
     srand(time(NULL));
    //variaveis 
    int ind = numApostados(),acu = 0,acertos = 0,cartaoAposta[6][10],numSort[ind],num[60];
    //lida qnt numeros eu devo informar
for(int i = 0; i < ind; i++){
        printf("->Informe o %d numero: ", i + 1);
        int temp_num; // usamos uma variável temporária para ler e validar
  
        // validação 
        //normalmente scanf espera inteiro e se o if vai retorna 1,mas aqui espera 0 ou seja que não seja inteiro 
        if (scanf("%d", &temp_num) != 1) {
            printf("Erro de entrada! Digite um numero inteiro.\n");
            while (getchar() != '\n'); // limpando tudo oque não for numero inteiro
            i--; // volta uma posição para poder escrever denovo o numero 
            continue; // pula para a próxima iteração 
        }
        //  validação Max e Min
        if(temp_num > 60 || temp_num < 1){ 
            printf("Erro! O numero deve ser entre 1 e 60.\n");
            i--; // volta uma posição para poder escrever denovo o numero 
            continue; // pula para a próxima iteração
        }
        //validação de repetição
        if (i > 0) {
            int encontrado_repetido = 0;
            for (int k = 0; k < i; k++) { // compara  (índices de 0 a i-1)
                if (num[k] == temp_num) {
                    printf("Erro! O numero %d ja foi digitado. Nao pode repetir.\n", temp_num);
                    encontrado_repetido = 1;
                    break; // sai do loop de verificação
                }
            }
            if (encontrado_repetido) {
                i--; // volta uma posição para poder escrever denovo o numero
                continue; // Pula para a próxima iteração 
            }
        }

        num[i] = temp_num; // AGORA guarda o número no array

        numSort[i] = 1 + ( rand() % 60 ); 
    }

    linha();
    //parte2 Cartao da Aposta
    printf("Cartao da Aposta:\n");
    linha();
    //exibicao do cartao
    for(int l = 0; l < 6; l++){ 
        for(int c = 0; c < 10; c++){ 
            //conta os números de 1 a 60.
            acu++;
            // preenche a célula da tabela.
            cartaoAposta[l][c] = acu; 

        
            int encontrado = 0;
            for (int k = 0; k < ind; k++) { 
                if (cartaoAposta[l][c] == num[k]) {
                    //marca como encontrado!
                    encontrado = 1;
                    //para o for e nao o codigo
                    break;
                }
            }
            if (encontrado) {
                //se num e colocado no cartao 
                printf(" %2d ", cartaoAposta[l][c]); 
            } else {
                //se nao é colocado --
                printf(" -- "); 
            }
        }
        printf("\n"); 
    }
    linha();
    //escreva os numeros sorteados
    for(int i = 0; i < ind; i++){
        printf("-> informe o %d numero - sorteado: %d \n", i + 1, numSort[i]);
    }
    //parte 3 resultado
    linha();
    printf("Resultado da aposta \n");
    linha();
    printf("\n-> Numero Sorteados:");
    for(int i = 0; i < ind; i++){
        printf(" %d -",numSort[i]);
    }
    printf("\n-> Numero Apostados:");
    for(int i = 0; i < ind; i++){
        printf(" %d -",num[i]);
    }
    for(int i = 0; i < ind; i++){
        if(numSort[i]== num[i]){
            acertos++;
        }
    }
    printf("\n-> Pontuacao Final: %d Acertos\n",acertos);
    linha();
}
int main() {
    //variavel decisão
    int opcao;
    do{
    menu();
    cartao();

    printf("Autor: professor Cristiano \nDev: Erick Quintao\n");
    printf("-> Digite [1] - nova aposta / [2] - sair: \n");
    scanf("%d",&opcao);
    //não menor 0 ou maior 2
    if(opcao < 0 || opcao > 2){
       printf("-> Digite [1] - nova aposta / [2] - sair: \n");
        scanf("%d",&opcao); 
    }
    if(opcao == 2){
        printf("Programa Encerrado!!");
    }
    }while(opcao == 1 );
    return 0;
}

