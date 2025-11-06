#include <stdio.h>
#include<stdlib.h>
// definição da chave de deslocamento

void linha(void){
 printf("-> --------------------------------------- <-\n");
}
int menu(){
    int opcao;
    linha();
    printf("-> Programa Criptografia de Substituição <-\n");
    linha();
    printf("->  [ 01 ] - Criptografar uma Palavra <- \n -> [ 02 ] - Descriptografar uma Palavra <- \n -> [ 03 ] - Sair  <-\n");
    linha();
    printf("-> Digite Opção: ");
    scanf("%d",&opcao);
    return opcao;
}
void criptografia(void){
    // variaveis
    #define CHAVE1 1
    char palavra[30];
    int contador =0,i=0;
    linha();
    //header opcao 1
    printf("-> Programa Criptografia uma Palavra <-\n");
    linha();
    printf("-> Informe uma Palavra p/ser Criptografida(max 29): ");
    //limite de letras
    scanf("%29s",palavra);
    printf("-> Palavra Origem: %s\n",palavra);
    //processamento
    //separa as letras
for (int i = 0; palavra[i] != '\0'; i++) {
        char caractere = palavra[i];
        // processa letras minusculas
        if (caractere >= 'a' && caractere <= 'z') {
            //parte mais importante: 
            //primeiro: transforma as letras em numeros 0 a 25 ,a = 97.[a-a=0,b-a=1,c-a=2] etc.
            //segundo: a chave desloca um numero
            //terceiro: % 26 garante que nunca sai do alfabeto ,exe:z: (25 + 1) % 26 = 26 % 26 = 0
            palavra[i] = (char)(((caractere - 'a') + CHAVE1) % 26 + 'a');
            
        } else if (caractere >= 'A' && caractere <= 'Z') {
            // Processa letras maiúsculas:
            palavra[i] = (char)(((caractere - 'A') + CHAVE1) % 26 + 'A');
            
        }
        printf("[%d] - %c -> %c \n",i+1,caractere,palavra[i]);
    }
    printf("-> Palavra Destino: %s\n",palavra);
}
void descriptografar(void){
    // variaveis
    #define CHAVE2 -1
    char palavra[30];
    int contador =0,i=0;
    linha();
    //header opcao 1
    printf("-> Programa Descriptografar uma Palavra <-\n");
    linha();
    printf("-> Informe uma Palavra p/ser descriptografada(max 29): ");
    //limite de letras
    scanf("%29s",palavra);
    printf("-> Palavra Origem: %s\n",palavra);
    //processamento
    //separa as letras
for (int i = 0; palavra[i] != '\0'; i++) {
        char caractere = palavra[i];
        // processa letras minusculas
        if (caractere >= 'a' && caractere <= 'z') {
            //parte mais importante: 
            //primeiro: transforma as letras em numeros 0 a 25 ,a = 97.[a-a=0,b-a=1,c-a=2] etc.
            //segundo: a chave desloca um numero
            //terceiro: % 26 garante que nunca sai do alfabeto ,exe:z: (25 + 1) % 26 = 26 % 26 = 0
            palavra[i] = (char)(((caractere - 'a') + CHAVE2) % 26 + 'a');
            
        } else if (caractere >= 'A' && caractere <= 'Z') {
            // Processa letras maiúsculas:
            palavra[i] = (char)(((caractere - 'A') + CHAVE2) % 26 + 'A');
            
        }
        printf("[%d] - %c -> %c \n",i+1,caractere,palavra[i]);
    }
    printf("-> Palavra Destino: %s\n",palavra);
}
void sair(void){
    linha();
    printf("-> [ 03 ] - Sair  <-\n");
    linha();
    printf("-> Programa Encerrado c/sucesso!!! <-\n");
    // termina com o programa lib:<stdlib.h>
    // saida sem erro
    exit(0);
}
int main() {
    int opcao;
    do{
        opcao = menu();
        switch(opcao){
            case 1: 
                criptografia();
            break;
            case 2:
                descriptografar();
            break;
            case 3:
                sair();
            break;
            default:
            printf("opcao invalida!");
            break;
        }
    }while(opcao !=3);
    return 0;
}