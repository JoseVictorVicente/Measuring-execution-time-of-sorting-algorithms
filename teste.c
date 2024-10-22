#include <stdio.h>
#include <stdlib.h>
#include "ordenadores.h"
#include <time.h>
#include <math.h>
#define amount 10
#define numTempos 6
/////////////////////////////////////////////////////////////////////////
//Verificação de metodo de preenchimento de vetor
void method(int arr[], int metodo, int size){
    if(metodo == 0){
        srand(time(0));
        for (int j = 0; j < size; j++){
            arr[j] = rand() % size;
        }
    }
    else if(metodo == 1){
        for(int j = 0; j < size; j++){
            arr[j] = j;
        }
    }
    else if(metodo == -1){
        for(int j = 0; j < size; j++){
            arr[j] = size - j;
        }
    }
}
/////////////////////////////////////////////////////////////////////////
void testeBubble(double tempos[], int metodo){
    if(metodo == 0 || metodo == 1 || metodo == -1){
    clock_t start, end;
    double cpu_time_used;
    int k = amount;
    for (int i = 0; i < numTempos; i++) {
    int *array = malloc(k * sizeof(int)); // Alocação dinâmica
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    method(array, metodo, k);
    start = clock();
    bubbleSort(array, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    tempos[i] = cpu_time_used;
    k*= amount;
    free(array); // Libera a memória
}
    }
    else
        printf("\nMetodo invalido");
}
///////////////////////////////////////////////////////////////////////////
void testeBucket(double tempos[], int metodo){
    if(metodo == 0 || metodo == 1 || metodo == -1){
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < numTempos; i++) {
    int k = amount * pow(10, i); // Calcular o tamanho atual
    int *array = malloc(k * sizeof(int)); // Alocação dinâmica
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    method(array, metodo, k);
    start = clock();
    bucketSort(array, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    tempos[i] = cpu_time_used;
    free(array); // Libera a memória
}
    }
    else
        printf("\nMetodo invalido");
}
//////////////////////////////////////////////////////////////////////////
void testeCount(double tempos[], int metodo){
    if(metodo == 0 || metodo == 1 || metodo == -1){
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < numTempos; i++) {
    int k = amount * pow(10, i); // Calcular o tamanho atual
    int *array = malloc(k * sizeof(int)); // Alocação dinâmica
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    method(array, metodo, k);
    start = clock();
    countSort(array, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    tempos[i] = cpu_time_used;
    free(array); // Libera a memória
}
    }
    else
        printf("\nMetodo invalido");   
}
//////////////////////////////////////////////////////////////////////////
void testeRadix(double tempos[], int metodo){
    if(metodo == 0 || metodo == 1 || metodo == -1){
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < numTempos; i++) {
    int k = amount * pow(10, i); // Calcular o tamanho atual
    int *array = malloc(k * sizeof(int)); // Alocação dinâmica
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    method(array, metodo, k);
    start = clock();
    radixSort(array, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    tempos[i] = cpu_time_used;
    free(array); // Libera a memória
}
    }
    else
        printf("\nMetodo invalido"); 
}
//////////////////////////////////////////////////////////////////////////
void testeHeap(double tempos[], int metodo){
    if(metodo == 0 || metodo == 1 || metodo == -1){
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < numTempos; i++) {
    int k = amount * pow(10, i); // Calcular o tamanho atual
    int *array = malloc(k * sizeof(int)); // Alocação dinâmica
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    method(array, metodo, k);
    start = clock();
    heapSort(array, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    tempos[i] = cpu_time_used;
    free(array); // Libera a memória
}
    }
    else
        printf("\nMetodo invalido");
}
//////////////////////////////////////////////////////////////////////////
void testeInsertion(double tempos[], int metodo){
    if(metodo == 0 || metodo == 1 || metodo == -1){
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < numTempos; i++) {
    int k = amount * pow(10, i); // Calcular o tamanho atual
    int *array = malloc(k * sizeof(int)); // Alocação dinâmica
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    method(array, metodo, k);
    start = clock();
    insertionSort(array, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    tempos[i] = cpu_time_used;
    free(array); // Libera a memória
}
    }
    else
        printf("\nMetodo invalido");   
}
//////////////////////////////////////////////////////////////////////////
void testeMerge(double tempos[], int metodo){
    if(metodo == 0 || metodo == 1 || metodo == -1){
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < numTempos; i++) {
    int k = amount * pow(10, i); // Calcular o tamanho atual
    int *array = malloc(k * sizeof(int)); // Alocação dinâmica
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    method(array, metodo, k);
    start = clock();
    mergeSort(array, 0, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    tempos[i] = cpu_time_used;
    free(array); // Libera a memória
}
    }
    else
        printf("\nMetodo invalido");   
}
//////////////////////////////////////////////////////////////////////////
void testeQuick(double tempos[], int metodo){
    if(metodo == 0 || metodo == 1 || metodo == -1){
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < numTempos; i++) {
    int k = amount * pow(10, i); // Calcular o tamanho atual
    int *array = malloc(k * sizeof(int)); // Alocação dinâmica
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    method(array, metodo, k);
    start = clock();
    quickSort(array, 0, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    tempos[i] = cpu_time_used;
    free(array); // Libera a memória
}
    }
    else
        printf("\nMetodo invalido");
}
//////////////////////////////////////////////////////////////////////////
void testeSelection(double tempos[], int metodo){
    if(metodo == 0 || metodo == 1 || metodo == -1){
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < numTempos; i++) {
    int k = amount * pow(10, i); // Calcular o tamanho atual
    int *array = malloc(k * sizeof(int)); // Alocação dinâmica
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    method(array, metodo, k);
    start = clock();
    selectionSort(array, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    tempos[i] = cpu_time_used;
    free(array); // Libera a memória
}
    }
    else
        printf("\nMetodo invalido");
}
//////////////////////////////////////////////////////////////////////////
void testeShell(double tempos[], int metodo){
    if(metodo == 0 || metodo == 1 || metodo == -1){
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < numTempos; i++) {
    int k = amount * pow(10, i); // Calcular o tamanho atual
    int *array = malloc(k * sizeof(int)); // Alocação dinâmica
    if (array == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    method(array, metodo, k);
    start = clock();
    shellSort(array, k);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    tempos[i] = cpu_time_used;
    free(array); // Libera a memória
}
    }
    else
        printf("\nMetodo invalido");
}
//////////////////////////////////////////////////////////////////////////