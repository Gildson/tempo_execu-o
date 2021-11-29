/*
 *  ordenacao.cpp
 *  
 *
 *  Created by Luiz Affonso Guedes on 06/03/17.
 *  modified by Gildson Bezerra on 29/11/21.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

// UFRN-CT-DCA
// Programa: programa para ordenação de um vetor

// Manipulação de tempo em c,c++
// Programa: programa que usa manipuladores de tempo para 
// medir o desempenho de algoritmos de ordenação


#include <cstdlib>   //qsort
#include  <time.h>   // clock(),time()
#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()
#include <sys/time.h>

//Vetores usados pelos métodos de ordenação
int *vetorQuickSort;
int *vetorBubbleSort;
int tamanho;

//Função usada pelo qsort para comparar dois numeros
int compare_ints( const void* a, const void* b ) {
	int* arg1 = (int*) a;
	int* arg2 = (int*) b;
	if( *arg1 < *arg2 ) return -1;
	else if( *arg1 == *arg2 ) return 0;
	else return 1;
}

//Algoritmos de ordenação bubble sort
void bubbleSort(int *vetor, int tamanho) {
	int aux;
	for (int i = 0; i < tamanho-1; i++) {
		for (int j = 0; j < tamanho-1; j++) {
			if (vetor[j] > vetor[j+1]) {
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}


//Observe que os números são gerados aleatoriamente baseados
//em uma semente. Se for passado a mesma semente, os 
//números aleatórios serão os mesmos
void criarVetor(int tamanhoVetor, int semente){
	srand (semente);
	vetorQuickSort = new int[tamanhoVetor];
	vetorBubbleSort = new int[tamanhoVetor];
	for (int i=0;i<tamanhoVetor;i++){
		vetorQuickSort[i] =  rand()%100000;
        vetorBubbleSort[i] = vetorQuickSort[i]; // utilizar os mesmos valores
		//vetorBubbleSort[i] = rand()%100000;
	}
}



int main ()
{

	struct timeval time_inicial_q, time_final_q, time_inicial_b, time_final_b, time_vector_inicial, time_vector_final;
	int time_quick, time_bubble, time_vector;
	
	//Tamanho do vetor
	int n = 100000;
	
	//tempo para criar o vetor aleatorio
	gettimeofday(&time_vector_inicial, NULL);	
	//Criar vetor com elementos aleatorios[0,100000] 
	criarVetor(n,23);
	gettimeofday(&time_vector_final, NULL);
	time_vector = (int) (1000 * (time_vector_final.tv_sec - time_vector_inicial.tv_sec) + (time_vector_final.tv_usec - time_vector_inicial.tv_usec) / 1000); //transforma em milissegundos
	
	//tempo para ordenar o vector criado utilizando o Quicksort
	gettimeofday(&time_inicial_q, NULL);
	//Ordenar utilizando quickSort
	qsort (vetorQuickSort, n, sizeof(int), compare_ints);
	gettimeofday(&time_final_q, NULL);
	time_quick = (int) (1000 * (time_final_q.tv_sec - time_inicial_q.tv_sec) + (time_final_q.tv_usec - time_inicial_q.tv_usec) / 1000);
	
	//tempo para ordernar o vector criado utilizando o BubbleSort
	gettimeofday(&time_inicial_b, NULL);
	//Ordenar utilizando bubleSort
	bubbleSort(vetorBubbleSort,n);
	gettimeofday(&time_final_b, NULL);
	time_bubble = (int) (1000 * (time_final_b.tv_sec - time_inicial_b.tv_sec) + (time_final_b.tv_usec - time_inicial_b.tv_usec) / 1000);
	
	 printf("tempo decorrido para criar o vetor: %d milissegundos\n", time_vector);
 	 printf("tempo decorrido para ordenar o vetor com QuickSort: %d milissegundos\n", time_quick);
 	 printf("tempo decorrido para ordenar o vetor com BubbleSort: %d milissegundos\n", time_bubble);
    printf("terminou");
	exit(0);
}


