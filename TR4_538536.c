#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

//Função de criação e inicializacao do vetor.
VETORORD* VETORD_create(int n, COMP* compara)
{
	VETORORD *p = (VETORORD*)malloc(sizeof(VETORORD));//alocacao de memoria de um ponteiro de tipo definido VETORORD
	if(p == NULL){//condicional que testa se o ponteiro esta apontando para nulo, caso seja valido...
	
		fprintf(stderr, "Não foi possível alocar memória.\n");
		exit(EXIT_FAILURE);
	}
	//... os valores contidos no vetor serão inicializados com os parâmetros iniciais
	p -> N = n;
	p -> P = 0;
	p -> comparador = compara;//ponteiro apontando para o valor desejado
	p -> elems = (void**)malloc(sizeof(void*) * p->N);
	
	if(p -> elems == NULL){
		fprintf(stderr, "Não foi possível alocar memória\n");
		exit(EXIT_FAILURE);
	}
	for(unsigned i = 0; i < p->N; ++i)//estrutrura de repeticao que inicializa as posicoes do vetor com o endereco nulo.
		p->elems[i] = NULL;
	
	return p;//retorna o ponteiro com o endereco do vetor criado e inicializado
}

//Função de adição de elementos no vetor.
void VETORD_add(VETORORD* vetor, void* newelem)
{
	
	if (vetor->P < vetor->N){//condicional que verifica se o vetor possui espaco para o elemento a ser adicionado
	
       	if (vetor->P == 0)//testa se o vetor esta vazio, em caso valido, a posicao inicial recebera o novo elemento passado por parametro.
            vetor->elems[0] = newelem;
        else if //condicional que testa se o novo elemento a ser adicionado é maior ou equivalente ao ultimo elemento ja adicionado no vetor.
        (
			vetor->comparador(newelem, vetor->elems[vetor->P-1]) == 1 ||
			vetor->comparador(newelem, vetor->elems[vetor->P-1]) == 0
        ) 
            vetor->elems[vetor->P] = newelem;//caso o condicional seja valido, o novo elemento e adicionado ao final.
	else{//adicao de elementos nas posicoes do meio do vetor   
            for (int i = vetor->P-1; i > -1; --i){//Laço que percorre o vetor de sua posição final ate a inicial.     
                if (vetor->comparador(newelem, vetor->elems[i]) == 1){//condicional que testa se o novo elemento é maior ou equivalente aos elementos das posições do vetor
                    vetor->elems[i+1] = vetor->elems[i];//caso o condicional seja valido, os elementos do vetor serão reorganizados em novas posições a depender da posição
                    vetor->elems[i] = newelem;		//a qual o novo elemento foi adicionado, mantendo sempre a sua propriedade de ordenação
                }
		else 
			break;
            }
	}
        vetor->P++;//ao final de qualquer caso de adição, a valor do tamanho do vetor é incrementado.
    }	
}

//Função de remoção de elementos
void* VETORD_remove(VETORORD* vetor)
{
	void* aux = vetor->elems[0];//definição de um ponteiro auxiliar do tipo void, que recebe o valor e o endereço do primeiro elemento do vetor para assim ser realizada sua exclusão
    for(int i = 0; i < vetor->P-1; i++)//Laço que percorre todas as outras posições restantes do vetor
        vetor->elems[i] = vetor->elems[i+1];//reorganização das posições do vetor após o primeiro elemento ter sido excluido.

    --vetor->P;//Decremento no valor do tamanho do vetor.

    return aux;//retorna o valor contido na primeira posição que foi removida.
}
