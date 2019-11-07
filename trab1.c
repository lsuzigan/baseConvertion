/*
*   @file   trab1.c
*
*   @brief  Este programa realiza conversões de bases binária, hexadecimal e decimal, através de um menu principal que permite
*           escolher qual é a operação desejada pelo usuário.
*
*   @authors    Lucas Souza Suzigan - 11821BSI212
*               Danilo Dias Lemos   - 11821BSI211
*
*   @date 07-11-2019
*
*   @bugs   A função FracParaBin() retorna apenas a conversão da parte fracionária do binário.   
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define OPCAO_MINIMA 0
#define OPCAO_MAXIMA 9
#define SAIR OPCAO_MINIMA

#define TAM_BIN 32
#define TAM_BIN_INT_FRAC 49
#define TAM_BIN_FRAC 16

#define TAM_HEX 8
#define TAM_HEX_FRAC 4
#define ALG 17


/*
*	@brief Imprime as opções do menu principal do programa.
*/
void menuOpcoes(void){
	printf("****************************************************\n");
	printf("*                 C o n v e r s o r                *\n");
	printf("****************************************************\n");
	printf("\n");
	printf("Opções:\n");
	printf("\n");
	printf("1 - Converter de binário para decimal.\n");
	printf("2 - Converter de hexadecimal para decimal\n");
	printf("3 - Converter de decimal para binário\n");
	printf("4 - Converter de decimal para hexadecimal\n");
	printf("5 - Converter de binário para hexadecimal\n");
	printf("6 - Converter de hexadecimal para binário\n");
	printf("7 - Converter de fração binária para decimal\n");
	printf("8 - Converter de fração decimal para binário\n");
	printf("9 - Somar dois binários sem sinal\n");
	printf("0 - Sair\n\n");
}//	fim menuOpcoes


/*
*	@brief Lê a opção digitada pelo usuário.
*
*	@return Número inteiro digitado pelo usuário referente a opção do menu.
*/
unsigned int leiaOpcaoMenu(void){
	unsigned int opcao = 0;

	printf("Digite uma opção: ");
	scanf(" %u", &opcao);

	while( !(OPCAO_MINIMA <= opcao && OPCAO_MAXIMA >= opcao)){
		printf("Opção inválida! Digite uma opção válida.\n");
		scanf(" %u", &opcao);
	}//while

	return(opcao);

}// fim leiaOpcaoMenu


/*
*	@brief Converte um binario para decimal.
*/
void BinParaDec(void){// Opção 1 do menu
    
	char binario[TAM_BIN] = {'\0'};
	int posicao = 0;
	int expoente = 0;
	int tamanho = 0;
	int decimal = 0;
	int num = 0;

    printf ("_______________________________________");//40 underline
    printf ("\n\nDigite um binário: ");
	scanf("%s", binario);
    
    // Este loop determina o tamanho da string
    while(binario[tamanho] != '\0') {
        tamanho++;
    }// fim while
    
    // Neste loop, a string é percorrida de trás para frente. Cada caractere é convertido
    // em um número inteiro, multiplicado pela base elevada ao expoente (0..Comprimento da string) 
    // e somado ao valor da variável 'decimal', que recebe as somas sucessivas. 
    for(expoente, posicao=(tamanho-1); expoente < tamanho; expoente++, posicao--) {

            num = (int)binario[posicao] - (int)'0';

        // Aqui verifica se o usuário digitou um binário válido
        if(num > 1 || num < 0) {
            printf("Você informou um número inválido!\n");
            return;
        }
        decimal += num * pow(2, expoente);
    }// fim for

    printf("%s_(2) = %d_(10)", binario, decimal);
    printf ("\n\n_______________________________________\n\n");//40 underline


}// fim BinParaDec


/*
*   @brief Converte um número hexadecimal para decimal natural
*/
void HexParaDec(void){// Opção 2 do menu

	char hexadecimal[TAM_HEX] = {'\0'};	
	unsigned int posicao = 0;
	unsigned int expoente = 0;
	unsigned int tamanho = 0;
	unsigned int decimal = 0;
	unsigned int num = 0;

    printf ("_______________________________________");//40 underline
    printf ("\n\nDigite um hexadecimal: ");
	scanf("%s", hexadecimal);

	while(hexadecimal[tamanho] != '\0') {
        tamanho++;
    }//while


	// For para "traduzir" as letras do hexadecimal
	for(expoente, posicao = tamanho - 1; expoente < tamanho; expoente++, posicao--){
		switch (hexadecimal[posicao]){
			
			case 'a': case 'A':
				num = 10; break;
			
			case 'b': case 'B':
				num = 11; break;

			case 'c': case 'C':
				num = 12; break;

			case 'd': case 'D':
				num = 13; break;

			case 'e': case 'E':
				num = 14; break;

			case 'f': case 'F':
				num = 15; break;

			default:
				num = hexadecimal[posicao] - '0'; break;
		
		}//switch

		decimal += num * pow(16, expoente);
		num = 0;

	}//for

	printf("%s_(16) = %u_(10)", hexadecimal, decimal);
    printf ("\n\n_______________________________________\n\n");//40 underline

}// fim HexParaDec


/*
*	@brief Converte um numero natural para binario.
*/
unsigned int DecParaBin(void) {// Opção 3 do menu
    char binario[TAM_BIN] = {'\0'};
    unsigned int num = 0;
    unsigned int bits = TAM_BIN;
    unsigned int i = bits -1;
    unsigned int j = i;

    printf ("_______________________________________");//40 underline
    printf ("\n\nDigite um decimal: ");
    scanf ("%u" , &num);

        if (num >= 2) {
            while (num/2 > 0) {
                binario [i] = num % 2;
                num /= 2;
                i--;
                j--;
            } //fimwhile

            for (i = 0; i < j; i++){
                binario [i] = 0;
            }//fim for

            binario[j] = 1;

            for (i = 0; i < bits; i++){
                printf ("%u", binario[i]);
            }//fim for
        } else if (num == 1) {
            for (i = 0; i < j; i++){
                printf("%u", binario[i] = 0);          
            }//fim for

            printf("%u",binario[i] = 1);
        } else if (num == 0) {
            for (i = 0; i < bits; i++){
                printf ("%u", binario[i] = 0);
            }//fim for
        } else {
            printf ("\n Valor invalido");
        }//fim else

        printf("\n\n_______________________________________\n\n");

}// fim DecParaBin


/*
*   @brief Converte um número natural para hexadecimal.
*/
void DecParaHex(void){// Opção 4 do menu

	char resto[ALG] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	char hexadecimal[TAM_HEX] = {'\0'};
	char temp[TAM_HEX] = {'\0'};
	int posicao = 0;
	unsigned int decimal = 0;
	unsigned int i = 0;
    unsigned int num = 0;

    printf ("_______________________________________");//40 underline
    printf ("\n\nDigite um decimal: ");
	scanf("%u", &decimal);
    num = decimal; //apenas para imprimir o número lido

	// Este while realiza as operações de divisão. Os restos são guardados no arranjo 'hexadecimal'
	while(decimal > 0) {
       temp[posicao] = resto[decimal % 16];
       decimal /= 16;
       posicao++;
	}// fim while
   
	// Exclui o caractere especial '\0' do final da string
	posicao -= 1;
    
	// Inverte a string contida no vetor num_conv
	for(i, posicao; posicao >= 0; posicao--, i++){
		hexadecimal[i] = temp[posicao];

	}//fim for

	printf("%u_(10) = %s_(16)", num, hexadecimal);
    printf("\n\n_______________________________________\n\n");

}// fim DecParaHex


/*
*   @brief Converte um número hexadecimal para binário.
*/
void HexParaBin(void){// Opção 6 do menu.

    char hexadecimal[TAM_HEX] = {'\0'};
    char binario[TAM_BIN] = {'\0'};    

    printf ("_______________________________________");//40 underline
    printf ("\n\nDigite um hexadecimal: ");
    scanf("%s", hexadecimal);

    for(int i = 0; i < TAM_HEX && hexadecimal[i] != '\0'; i++){

        switch (hexadecimal[i]){

            case '0':
				strcat(binario, "0000"); break;

            case '1':
				strcat(binario, "0001"); break;
            
            case '2':
				strcat(binario, "0010"); break;

            case '3':
				strcat(binario, "0011"); break;

            case '4':
				strcat(binario, "0100"); break;

            case '5':
				strcat(binario, "0101"); break;
            
            case '6':
				strcat(binario, "0110"); break;
            
            case '7':
				strcat(binario, "0111"); break;

            case '8':
				strcat(binario, "1000"); break;

            case '9':
				strcat(binario, "1001"); break;

            case 'a': case 'A':
				strcat(binario, "1010"); break;
			
			case 'b': case 'B':
				strcat(binario, "1011"); break;

			case 'c': case 'C':
				strcat(binario, "1100"); break;

			case 'd': case 'D':
				strcat(binario, "1101"); break;

			case 'e': case 'E':
				strcat(binario, "1110"); break;

			case 'f': case 'F':
				strcat(binario, "1111"); break;

        }// fim switch

    }// fim for

    printf("%s_(16) = %s_(10)", hexadecimal, binario);
    printf("\n\n_______________________________________\n\n");

}// fim HexParaBin


/*
*   @brief Converte um número binário com ponto flutuante em decimal.
*/
void BinFracParaDec(void){// Opcao 7 do menu.
    
    char bin_original[TAM_BIN_INT_FRAC] = {'\0'};
    char bin_inteiro[TAM_BIN] = {'\0'};
    char bin_frac[TAM_BIN_FRAC] = {'\0'};
    char bit = '\0';

    int tamanho_int = 0;
    int tamanho_frac = 0;
    double expoente = 0;
    int posicao = 0;
    double num = 0;

    double decimal_int = 0.0;
    double decimal_frac = 0.0;
    double decimal_final = 0.0;

    printf ("_______________________________________");//40 underline
    printf ("\n\nDigite um binário fracionário: ");     
    scanf("%s", bin_original);

    for(int i = 0; bin_original[tamanho_int] != ','; i++, tamanho_int++){
        bin_inteiro[i] = bin_original[tamanho_int];
        bin_inteiro[i+1] = '\0'; 
    }// fim for

    tamanho_frac = tamanho_int + 2;

    for(int j = 0; bin_original[tamanho_frac] != '\0'; j++, tamanho_frac++){
        bin_frac[j] = bin_original[tamanho_frac - 1];
        bin_frac[j+1] = '\0';
    }// fim for

    tamanho_frac = 0;

    while(bin_frac[tamanho_frac] != '\0'){
        tamanho_frac++;
    }// fim while

    // Converte a parte inteira do binário(bin_inteiro) para decimal.
    for(expoente, posicao=(tamanho_int-1); expoente < tamanho_int; expoente++, posicao--) {

        num = (int)bin_inteiro[posicao] - (int)'0';

        decimal_int += num * pow(2, expoente);

    }// fim for

    num = 0;
    expoente = -tamanho_frac;
    posicao = 0;

    // Converte a parte fracionária do binário(bin_frac) para decimal.(Bugado)
    for(expoente, posicao=tamanho_frac-1; expoente < 0; expoente++, posicao--) {

        num = (int)bin_frac[posicao] - (int)'0';

        decimal_frac += num * pow(2, expoente);

    }// fim for

    decimal_final = decimal_int + decimal_frac;

    printf("%s_(2) = %.4lf_(10)", bin_original, decimal_final);
    printf("\n\n_______________________________________\n\n");

}// fim BinFracParaDec


/*
*   @brief Converte um número natural para binário.
*/
void FracParaBin(void) {// Opção 8 do menu.

    double frac = 0.0;
    int resto = 0;

    printf ("_______________________________________");//40 underline
    printf ("\n\nDigite um número decimal: ");
    scanf ("%lf" , &frac);

    frac = frac - (int)frac; // remove a parte inteira.

    while (frac != 0.0) {
        frac *= 2;
        resto = (int)frac;
        frac -= resto;

        printf ("%d", resto);
        
    }// fim while

    printf("\n\n_______________________________________\n\n");

}// fim fracParaBin


/*
*   @brief 
*
*   @param Um inteiro sem sinal.
*/
void menu(unsigned int opcao){

    char repete = '\0';

	while(opcao != SAIR){

		menuOpcoes();
		opcao = leiaOpcaoMenu();

		if(opcao == 1){ //BinParaDec

            BinParaDec();

            printf("Deseja realizar a operação novamente? (s/n) \n");
                scanf (" %c", &repete);

                while(repete != 'n'){
                    BinParaDec();
                    printf("Deseja realizar a operação novamente? (s/n) \n");
                    scanf (" %c", &repete);

                }//fim while
                
                repete = '\0';
            
		} else if(opcao == 2){ // HexParaDec
            
            HexParaDec();

            printf("Deseja realizar a operação novamente? (s/n) \n");
            scanf (" %c", &repete);

            while(repete != 'n'){
                HexParaDec();
                printf("Deseja realizar a operação novamente? (s/n) \n");
                scanf (" %c", &repete);

            }//fim while
            
            repete = '\0';

        } else if(opcao == 3){ // DecParaBin
            
            DecParaBin();

            printf("Deseja realizar a operação novamente? (s/n) \n");
            scanf (" %c", &repete);

            while(repete != 'n'){
                DecParaBin();
                printf("Deseja realizar a operação novamente? (s/n) \n");
                scanf (" %c", &repete);

            }//fim while
            
            repete = '\0';

        } else if(opcao == 4){ // DecParaHex

            DecParaHex();

            printf("Deseja realizar a operação novamente? (s/n) \n");
            scanf (" %c", &repete);

            while(repete != 'n'){
                DecParaHex();
                printf("Deseja realizar a operação novamente? (s/n) \n");
                scanf (" %c", &repete);

            }//fim while
            
            repete = '\0';
            
        } else if(opcao == 5){

            printf("\tOperação não disponível. \n\nRetornando ao menu principal.\n");
            
        } else if(opcao == 6){// HexParaBin

            HexParaBin();

            printf("Deseja realizar a operação novamente? (s/n) \n");
            scanf (" %c", &repete);

            while(repete != 'n'){
                HexParaBin();
                printf("Deseja realizar a operação novamente? (s/n) \n");
                scanf (" %c", &repete);

            }//fim while
            
            repete = '\0';
            
        } else if(opcao == 7){// BinFracParaDec

            BinFracParaDec();

            printf("Deseja realizar a operação novamente? (s/n) \n");
            scanf (" %c", &repete);

            while(repete != 'n'){
                BinFracParaDec();
                printf("Deseja realizar a operação novamente? (s/n) \n");
                scanf (" %c", &repete);

            }//fim while
            
            repete = '\0';
            
        } else if(opcao == 8){// FracParaBin

            FracParaBin();

            printf("Deseja realizar a operação novamente? (s/n) \n");
            scanf (" %c", &repete);

            while(repete != 'n'){
                FracParaBin();
                printf("Deseja realizar a operação novamente? (s/n) \n");
                scanf (" %c", &repete);

            }//fim while
            
            repete = '\0';

        } else if(opcao == 9){

            printf("\tOperação não disponível. \n\nRetornando ao menu principal.\n");
            
        } else if(opcao == 0){ // Sair
            exit(1);
        }

	}//while

}// fim menu


int main (void) {

    unsigned int opcao = 10;

    menu(opcao);

    return 0;

}// fim main

