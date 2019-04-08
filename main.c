#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char nome[20];
    int idade;
    int matricula;
}aluno;

int *p,*qtd,i,j;
void *pBUFFER;
aluno *paluno;

int main()
{
    pBUFFER = malloc(sizeof(int)*4);
    p = (int*) pBUFFER;
    qtd = p+1;
    *qtd = 0;

    while (*p != 5){
        printf("Digite\n(1) Adicionar\n(2) Listar\n(3) Buscar\n(4) Deletar\n(5) Sair\n");
        scanf("%d", p);

        if (*p == 1){
            adiciona();
        }
    }
    return 0;
}

void reapontar(){
    p = pBUFFER;
    qtd = p+1;
    i = qtd+1;
    j = i+1;
    paluno = (aluno*) j+1;
}


void adiciona(){
    pBUFFER = realloc(pBUFFER, 4*sizeof(int) + sizeof(aluno) * *qtd);
    reapontar();
    paluno +=  (*qtd-1) * sizeof(aluno);

    printf("Nome: ");
    scanf("%s", paluno->nome);
    printf("Idade: ");
    scanf("%d", &paluno->idade);
    printf("Matricula: ");
    scanf("%d", &paluno->matricula);
}
