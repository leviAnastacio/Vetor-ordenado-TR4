#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

//Função de comparação para os elementos desejados no teste
int myCOMP(void* x, void* y){
	int ptx = *((int*)x);
	int pty = *((int*)y);
	if(ptx - pty < 5){
		return -1;
	}else{
		if(ptx - pty > 5) 
			return 1;
		else 
			return 0;
	}
}

//Função de imprimir os elementos do vetor
void print(void** vet, int P){
	printf("VETOR DE %d TAMANHO:\n", P);
	for(int i = 0; i < P; i++){
		printf(" %d ", *((int*)vet[i]));
	}
	printf("\n");
}

int main(){
   	VETORORD* vet = VETORD_create(10, myCOMP);//cria um vetor de 10 posições com base na função de comparação para testes.
   	int* x;
   	
   	printf("INCLUINDO... \n");
	for(int i = 0; i < 10; i++){
		x = malloc(sizeof(int));
		*x = i*10;
		VETORD_add(vet, x);
	}
	
	print(vet->elems, vet->P);
  
  	printf("REMOVENDO!");
  	VETORD_remove(vet);
  	
	print(vet->elems, vet->P);
   
	return 0;  
}
