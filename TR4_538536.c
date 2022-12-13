#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

/*função de criação do vetor.
nesta função, serão alocados espaços na memória para as posições do vetor e
todos os seus valores serão inicializados, criando assim, um vetor vazio pronto 
para receber elementos que é retornado ao final da função.*/
VETORORD* VETORD_create(int n, COMP* compara)
{
	VETORORD *p = (VETORORD*)malloc(sizeof(VETORORD));
	if(p == NULL)
	{
		fprintf(stderr, "Não foi possível alocar memória.\n");
		exit(EXIT_FAILURE);
	}
	p -> N = n;
	p -> P = 0;
	p -> comparador = compara;
	p -> elems = (void**)malloc(sizeof(void*) * p->N);
	
	if(p -> elems == NULL)
	{
		fprintf(stderr, "Não foi possível alocar memória\n");
		exit(EXIT_FAILURE);
	}
	for(unsigned i = 0; i < p->N; ++i)
		p->elems[i] = NULL;
	
	return p;
}

/*Função de adição de elementos.
Nesta função são realizadas operações com o objetivo de armazenar elementos no vetor
e também com o intuito de organizar esses elementos de forma ordenada por meio de comparações
dos valores dos elementos em suas respectivas posições*/
void VETORD_add(VETORORD* vetor, void* newelem)
{
	
	if (vetor->P < vetor->N) 
	{
       	if (vetor->P == 0) 
            vetor->elems[0] = newelem;
        else if 
        (
			vetor->comparador(newelem, vetor->elems[vetor->P-1]) == 1 ||
			vetor->comparador(newelem, vetor->elems[vetor->P-1]) == 0
        ) 
            vetor->elems[vetor->P] = newelem;
		else     
            for (int i = vetor->P-1; i > -1; --i) 
			{        
                if (vetor->comparador(newelem, vetor->elems[i]) == 1) 
				{
                    vetor->elems[i+1] = vetor->elems[i];
                    vetor->elems[i] = newelem;
                }
				else 
					break;
            }

        vetor->P++;
    }	
}

/*Função de remover.
Nesta função, suas operações removem o primeiro elemento do vetor e logo após os outros valores
são realocados em novas posições, fazendo com que o vetor continue com sua propriedade de ordenação
mesmo depois do primeiro elemento ter sido removido.*/
void* VETORD_remove(VETORORD* vetor)
{
	void* aux = vetor->elems[0];
    for(int i = 0; i < vetor->P-1; i++)
        vetor->elems[i] = vetor->elems[i+1]; 

    --vetor->P;

    return aux;
}
