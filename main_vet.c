#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

//Função de comparação dos elementos desejados para o teste
int myCOMP(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);
	if(ptx < pty){
		return -1;
	}else{
		if(ptx > pty) 
			return 1;
		else 
			return 0;
	}
}

//Função de imprimir os elementos-teste do vetor
void print(void** vet, int P){
	int i;
	printf("VETOR DE %d TAMANHO:\n", P);
	for(i = 0; i < 10; i++){
		printf(" %d ", *((int*)vet[i]));
	}
	printf("\n");
}

int main(){
   	VETORORD* vet = VETORD_create(10, myCOMP);//Define um ponteiro que recebe um vetor de 10 posições referente à função de comparação dos testes
   	
   	int* x;
   	int i;
   	
   	printf("INCLUINDO... \n");
	for(i = 0; i < 10; i++){//Laço que permite a adição dos 10 elementos gerados no vetor
		x = malloc(sizeof(int));
		*x = i*10;
		VETORD_add(vet, x);//Chamada de função que adiciona os valores dentro do vetor
	}
	
	print(vet->elems, vet->P);//Imprime o valor de cada posição do vetor.
  
  	printf("REMOVENDO!");
  	VETORD_remove(vet);//Chamada de função que remove o elemento da primeira posição do vetor.
  	
	print(vet->elems, vet->P);//imprime os elementos das posições do vetor após a remoção do primeiro item.
   
	return 0;  
}
