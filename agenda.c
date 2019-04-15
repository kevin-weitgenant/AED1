#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nome[20];
    int idade;
    int matricula;
}aluno;

int *p,*qtd,*i,*j;
void *pBUFFER;
aluno *paluno;


void reapontar(){

    p = (int*)pBUFFER;

    qtd =  p+1;
    i =  qtd+1;
    j =  i+1;

}

void adiciona(){


    (*qtd)++;

    pBUFFER = realloc(pBUFFER, (sizeof(int)*4) + (sizeof(aluno)*(*qtd)));
    if (pBUFFER == NULL) printf("\nNULL\n");
    reapontar();
    paluno = j + 1;
    paluno= paluno+ (sizeof(aluno)*(*qtd -1));




    printf("Nome: ");
    scanf("%s", paluno->nome);
    printf("Idade: ");
    scanf("%d", &paluno->idade);
    printf("Matricula: ");
    scanf("%d", &paluno->matricula);


}

void listar(){


    paluno = j+1;

    for(*i=0;*i<*qtd; (*i)++){
        printf("Nome: %s\n", paluno->nome);
        printf("Idade: %d\n",paluno->idade);
        printf("Matricula: %d\n",paluno->matricula);
        paluno+=sizeof(aluno);
    }


}





int main()
{
    pBUFFER = malloc(sizeof(int)*4);
    reapontar();
    *qtd = 0;
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


    }
    return 0;
}
