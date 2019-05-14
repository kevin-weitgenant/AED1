#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int idade;
    int matricula;
}aluno;

 struct comeco{
    int p,qtd,qtdC,i,j;
    char comparar[20];
};

void *pBUFFER;
struct comeco *Comeco;

aluno *paluno;
char *frase;




void reapontar(){

    Comeco = (struct comeco*) pBUFFER;
    paluno = (aluno*)(pBUFFER + sizeof(struct comeco));

}

void adiciona(){


    (Comeco->qtd)++;
    pBUFFER = realloc(pBUFFER, (sizeof(struct comeco) + (sizeof(char)*20) + (sizeof(char)*(Comeco->qtdC)) + (sizeof(aluno)*(Comeco->qtd))));
    if (pBUFFER == NULL) printf("\nNULL\n");
    reapontar();
    frase = (char*)paluno;
    frase = frase + (sizeof(aluno) * ((Comeco->qtd) -1) + sizeof(char) * (Comeco->qtdC));

    printf("Nome: ");
    scanf("%s", frase);
    paluno = (aluno*)(frase + (sizeof(char)* (strlen(frase)+1)))    ;
    printf("Idade: ");
    scanf("%d", &paluno->idade);
    printf("Matricula: ");
    scanf("%d", &paluno->matricula);

    Comeco->qtdC = Comeco->qtdC + (strlen(frase) +1);
    pBUFFER = realloc(pBUFFER, (sizeof(struct comeco) + sizeof(char)*(Comeco->qtdC)+ sizeof(aluno)*(Comeco->qtd)));
    if (pBUFFER == NULL) printf("\nNULL\n");
    reapontar();

}

void listar(){

    reapontar();

    frase = (char*)paluno;

    for(Comeco->i = 0;( Comeco->i) < (Comeco->qtd); (Comeco->i)++){

        paluno = (aluno*)(frase + (sizeof(char)*(strlen(frase)+1)));
        printf("Nome: %s\n",frase);
        printf("Idade: %d\n",paluno->idade);
        printf("Matricula: %d\n",paluno->matricula);
        frase = (char*) (paluno +1);
    }


}


void buscar(){
    reapontar();
    frase = (char*)paluno;

    if (Comeco->p == 1){
        for(Comeco->i = 0;( Comeco->i) < (Comeco->qtd); (Comeco->i)++){
            paluno = (aluno*)(frase + (sizeof(char)*(strlen(frase)+1)));
            if (strcmp(Comeco->comparar,frase) == 0){
                printf("Nome: %s\n", frase);
                printf("Idade: %d\n",paluno->idade);
                printf("Matricula: %d\n\n\n",paluno->matricula);

            }
            frase = (char*) (paluno +1);
        }
    }
}

void deletar(){
    reapontar();
    



}






int main()
{
    pBUFFER = malloc(sizeof(struct comeco));
    reapontar();
    Comeco->qtd = 0;
    Comeco->qtdC = 0;
    Comeco->p = 6;

    while (Comeco->p != 5){
        printf("Digite\n(1) Adicionar\n(2) Listar\n(3) Buscar\n(4) Deletar\n(5) Sair\n");
        scanf("%d", &Comeco->p);
        getchar(); // nao sei se é necessario
        if (Comeco->p == 1){
            adiciona();
        }

        else if (Comeco->p == 2){
            listar();

        }


        //BUSCAR
        else if (Comeco->p == 3){
            while (Comeco->p != 4){
                printf("Escolha como deseja buscar\n(1) Nome\n(2) Idade\n(3) Matricula\n(4) Voltar para o menu\n");
                scanf("%d", &Comeco->p);
                if (Comeco->p == 1){
                    printf("Digite o nome a ser procurado: ");
                    scanf("%s", Comeco->comparar);
                    buscar();
                }
                else if (Comeco->p ==2){
                    printf("Digite a idade a ser buscada: ");
                    scanf("%s", frase);
                    buscar();
                }
                else if (Comeco->p ==3){
                    printf("Digite a matricula a ser procurada: ");
                    scanf("%s", frase);
                    buscar();
                }
                else if (Comeco->p != 4)  printf("Invalido... Tente novamente\n\n");
                }
        }
        
        //DELETAR
        else if (Comeco->p == 4){
                printf("Digite o nome a ser deletado, :\n");
                scanf("%s", Comeco->comparar);
                deletar();
                listar();
        }
    
    
    }


    return 0;
}
