#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int idade;
    int matricula;
}aluno;

int *p,*qtd,*qtdC,*i,*j;
char *frase;
void *pBUFFER;
aluno *paluno;


void reapontar(){

    p = (int*)pBUFFER;

    qtd =  p+1;
    qtdC = qtd+1;
    i =  qtdC+1;
    j =  i+1;
    frase = (char*) j +1;
    paluno = frase + (sizeof(char)*20);

}

void adiciona(){


    (*qtd)++;

    pBUFFER = realloc(pBUFFER, (sizeof(int)*5) + (sizeof(char)*20) + (sizeof(char)*(*qtdC)) + (sizeof(aluno)*(*qtd)));
    if (pBUFFER == NULL) printf("\nNULL\n");
    reapontar();
    frase = paluno + sizeof(aluno) * (*qtd -1) + sizeof(char) * (*qtdC)  ;


    printf("Nome: ");
    scanf("%s", frase);
    paluno = frase + (strlen(frase)+1);
    printf("Idade: ");
    scanf("%d", &paluno->idade);
    printf("Matricula: ");
    scanf("%d", &paluno->matricula);

    *qtdC = *qtdC + (strlen(frase) +1);
    pBUFFER = realloc(pBUFFER, (sizeof(int)*5) + sizeof(char)*(*qtdC)+ sizeof(aluno)*(*qtd));



}

void listar(){

    reapontar();
    frase = paluno;

    for(*i=0;*i<*qtd; (*i)++){

        paluno = frase + (sizeof(char)*(strlen(frase)+1));
        printf("Nome: %s\n",frase);
        printf("Idade: %d\n",paluno->idade);
        printf("Matricula: %d\n",paluno->matricula);
        frase= paluno + sizeof(aluno);
    }


}

/*
void buscar(){


    if (*p == 1){
        for(*i = 0; *i<*qtd; (*i)++){
            reapontar();
            paluno = sizeof(char)*20 + paluno;
            paluno = paluno + (*i) * sizeof(aluno);
            printf("*i = %d paluno->nome = %s\n\n\n", *i,(paluno->nome));
            if (strcmp((paluno->nome),frase) == 0){
                printf("Nome: %s\n", paluno->nome);
                printf("Idade: %d\n",paluno->idade);
                printf("Matricula: %d\n\n\n",paluno->matricula);
            }

        }

    }




}
*/

int main()
{
    pBUFFER = malloc(sizeof(int)*5   + 20*sizeof(char) );
    reapontar();
    *qtd = 0;
    *qtdC = 0;
    *p = 6;

    while (*p != 5){
        printf("Digite\n(1) Adicionar\n(2) Listar\n(3) Buscar\n(4) Deletar\n(5) Sair\n");
        scanf("%d", p);
        getchar(); // nao sei se é necessario
        if (*p == 1){
            adiciona();
        }

        else if (*p == 2){
            listar();

        }

        /*else if (*p == 3){
            while (*p != 4){
                printf("Escolha como deseja buscar\n(1) Nome\n(2) Idade\n(3) Matricula\n(4) Voltar para o menu\n");
                scanf("%d", p);
                if (*p == 1){
                    printf("Digite o nome a ser procurado: ");
                    scanf("%s", frase);
                    buscar();
                }
                else if (*p ==2){
                    printf("Digite a idade a ser buscada: ");
                    scanf("%s", frase);
                    buscar();
                }
                else if (*p ==3){
                    printf("Digite a matricula a ser procurada: ");
                    scanf("%s", frase);
                    buscar();


                else  printf("Invalido... Tente novamente\n\n");



            }

        }




    }
    */
    return 0;
}}
