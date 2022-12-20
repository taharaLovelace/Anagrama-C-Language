#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#define TAM 30

/* Feito por :
Augusto Guaschi Morato 
Hugo Tahara Menegatti 
Mattheus Goncalves Anitelli
Vinicius Lara
*/


void imprime_anagrama(char letras2[], int acertos2, int erros2, char bancoacertos2[][21], char bancopalavra2[][21]) {
int j=0;
    printf ("============================================== \n");
    printf ("\t\t        ANAGRAMA \n");
    printf ("REGRAS: \n");
    printf ("=> Forme as palavras com as letras do quadro \n");
    printf ("=> Total de 30 palavras \n");
    printf ("=> 5 tentativas no maximo\n");
    printf("=> A cada 5 acertos (válidos somente ateh o 15° acerto) voce recebera uma dica!!\n");
    printf ("\n\t\t    => Boa Sorte!! <=\n");
    printf ("============================================== \n");
    printf ("\nLetras a serem usadas:\n");
  printf("|===============|\n|");
     for (int i = 0; i < 25; i++)
    {
       printf ("%2c ", letras2[i]);
       j++;
       if (j == 5)
    {
       printf("|\n|");
       j = 0;
    }
    }
    printf ("===============|");
    printf ("\n\nPara parar o jogo tecle somente a letra x");

    printf ("\n\nAcertos: %d de 30", acertos2);
    printf ("\nErros: %d de 5", erros2);
    printf ("\n\n\t\t  Palavras Acertadas: \n");
    for (int i = 0; i<acertos2; i++){
      if (strcmp(bancoacertos2[i], bancopalavra2[i]) == 0) {
        printf ("%s  ", bancoacertos2[i]);
        }
    }
}

void ler_string (char palavralida2[]){
        printf ("\n\nPalavra: ");
        fflush (stdin);
        gets (palavralida2);


}

void valida_palavra (char palavralida2[],char bancoacertos2[][21]){
    int i;
    int flag;

    do {
        flag = 1;
        ler_string(palavralida2);
    for (i=0;i<strlen(palavralida2);i++)
        {
            if (!isalpha(palavralida2[i])){
                flag = 0;
                printf ("\nNumeros e/ou acentos nao sao permitidos!!");
                break;
            }


            if (strcmp(palavralida2,bancoacertos2[i])==0){
                flag = 0;
                printf ("\nEssa palavra ja foi utilizada!!");
                break;
            }


      }}while (flag == 0);}

void verifica_palavra (char palavralida2[], char bancopalavra2[][21], int *acertos2, int *erros2, char bancoacertos2 [][21]){
    int flag=0;
  for (int i = 0; i < TAM; i++)
  {

 if (strcmp(palavralida2,bancoacertos2[i]) == 0)
        {printf("Palavra ja utizada");}
  }

    for (int i = 0; i < TAM+1; i++)
    {
        if(strcmp(palavralida2,bancopalavra2[i]) == 0){

        strcpy(bancoacertos2[*acertos2],bancopalavra2[i]);
        (*acertos2)++;
        flag++;
    }



    flag++;
    }
    if(flag == TAM+1)
        (*erros2)++;

 }

void dica_jogo (int acertos2) {
  if (acertos2 == 5) {
      printf ("\n\nDica: Toda igreja tem e faz barulho !!\n");
    }


  if (acertos2==10) {
      printf ("\n\nDica: Rato ama comer !!");

    }

  if (acertos2==15){

      printf ("\n\nDica: 5x melhor do mundo no futebol !");
    }

}


void termina_jogo (char palavralida2[], char bancopalavra2[][21], int erros2, int acertos2){

  int escolha, j=0, i=0;
    if (palavralida2[0] == 'x') {
        printf ("\nVoce teve %d acerto(s) de 30!!\n\nDeseja ver o banco de palavras?\n[1] Para ver!\n[2] Se nao quiser ver!\n\nQual deseja escolher?? ", acertos2);
        scanf("%d", &escolha);
        switch (escolha) {
        case 1:
            printf("\n\n");
            for (i=0; i < 30; i++)
            {
                printf ("%3s ", bancopalavra2[i]);
                j++;
                if (j == 5)
            {
                printf ("\n\n");
                j = 0;
            }
            }
            printf ("\n=======================================\n\n\t     Obrigado por jogar!! \n");
            system ("pause");
            exit (0);
            break;

        case 2:
            printf ("\n=======================================\n\n\t     Obrigado por jogar!! \n");
            system ("pause");
            exit (0);
            break;

        }
}
  if (erros2==5) {
        printf ("\nVoce teve %d acerto(s) de 30 e %d ERROS!!\n\nDeseja ver o banco de palavras?\n[1] Para ver!\n[2] Se nao quiser ver!\n\nQual deseja escolher?? ", acertos2, erros2);
        scanf("%d", &escolha);
        switch (escolha) {
        case 1:
            printf("\n\n");
            for (i=0; i < 30; i++)
            {
                printf ("%3s ", bancopalavra2[i]);
                j++;
                if (j == 5)
            {
                printf ("\n\n");
                j = 0;
            }
            }
            printf ("\n=======================================\n\n        Obrigado por jogar!! \n");
            system ("pause");
            exit (0);
            break;

        case 2:
            printf ("\n=======================================\n\n        Obrigado por jogar!! \n");
            system ("pause");
            exit (0);
            break;
}}
  if(acertos2==30){
    printf("\n==============================================\n\n\tParabens, voce ganhou o jogo (^-^) !!!\n\n\t       Obrigado por jogar!!");
  }
}

int main () {

    char letras [] = {'o','e','t','a','o','s','p','c','r','m','a','s','i','c','i','q','u','n','o','m','g','l','v','j','e'};
    char bancopalavra [TAM][21] = {"agua", "amargo", "arco", "caro",
     "circo", "cor", "cristiano", "etanol", "jogo", "leite", "letra", "leva", "lua", "maca", "mala",
      "mesa","meta","mira","missa","ovo","rua", "queijo","quimono","sinuca",
      "sino","soletra","soneca","suino","sumo","taco"};

    char bancoacertos [TAM][21];
    char palavralida[21];
    int acertos = 0;
    int erros = 0;


    while (acertos < 30 && erros < 5) {
        system ("cls");
        imprime_anagrama (letras, acertos, erros, bancoacertos, bancoacertos);
        dica_jogo (acertos);
        valida_palavra (palavralida,bancoacertos);
        verifica_palavra (palavralida,bancopalavra,&acertos, &erros,bancoacertos);
        termina_jogo (palavralida, bancopalavra, erros, acertos);


    }

        return 0;
}
