#include <stdio.h>
#include <stdlib.h>
#include "teste.h"
#include <time.h>
#define numTempos 6
#define numTestes 3
int main(){
    double tempos[numTempos];
    int loop;

    while(loop){
        int sort;
        int metodo;
        printf("\nSair(0)");
        printf("\nBubbleSort(1)");
        printf("\nBucketSort(2)");
        printf("\nCountSort(3)");
        printf("\nRadixSort(4)");
        printf("\nHeapSort(5)");
        printf("\nInsertionSort(6)");
        printf("\nMergeSort(7)");
        printf("\nQuickSort(8)");
        printf("\nSelectionSort(9)");
        printf("\nShellSort(10)\n");
        scanf("%d", &sort);
        double media[numTempos];
        switch(sort){
            case 0: loop = 0; break;
            case 1: {
                printf("\nOrdenado(1)");
                printf("\nAleatorio(0)");
                printf("\nInvertido(-1)\n");
                scanf("%d", &metodo);
                for(int i = 0; i < numTestes; i++){
                    testeBubble(tempos, metodo);
                for(int q = 0; q < numTempos; q++){
                    media[q] = 0;
                }
                for(int j = 0; j < numTempos; j++){
                    media[j] += tempos[j];
                }
                }
                for(int i = 0; i < numTempos; i++){
                    media[i] = media[i]/numTestes;
                }
                printf("\nTempos--------------------------------------------\n");
                for(int i = 0; i < numTempos; i++){
                    printf("%lf\n", media[i]);
                }
                printf("--------------------------------------------------\n");
            }break;
            case 2: {
                printf("\nOrdenado(1)");
                printf("\nAleatorio(0)");
                printf("\nInvertido(-1)\n");
                scanf("%d", &metodo);
                for(int i = 0; i < numTestes; i++){
                    testeBucket(tempos, metodo);
                for(int q = 0; q < numTempos; q++){
                    media[q] = 0;
                }
                for(int j = 0; j < numTempos; j++){
                    media[j] += tempos[j];
                }
                }
                for(int i = 0; i < numTempos; i++){
                    media[i] = media[i]/numTestes;
                }
                printf("\nTempos--------------------------------------------\n");
                for(int i = 0; i < numTempos; i++){
                    printf("%lf\n", media[i]);
                }
                printf("--------------------------------------------------\n");
            }break;
            case 3: {
                printf("\nOrdenado(1)");
                printf("\nAleatorio(0)");
                printf("\nInvertido(-1)\n");
                scanf("%d", &metodo);
                for(int i = 0; i < numTestes; i++){
                    testeCount(tempos, metodo);
                for(int q = 0; q < numTempos; q++){
                    media[q] = 0;
                }
                for(int j = 0; j < numTempos; j++){
                    media[j] += tempos[j];
                }
                }
                for(int i = 0; i < numTempos; i++){
                    media[i] = media[i]/numTestes;
                }
                printf("\nTempos--------------------------------------------\n");
                for(int i = 0; i < numTempos; i++){
                    printf("%lf\n", media[i]);
                }
                printf("--------------------------------------------------\n");
            }break;
            case 4: {
                printf("\nOrdenado(1)");
                printf("\nAleatorio(0)");
                printf("\nInvertido(-1)\n");
                scanf("%d", &metodo);
                for(int i = 0; i < numTestes; i++){
                    testeRadix(tempos, metodo);
                for(int q = 0; q < numTempos; q++){
                    media[q] = 0;
                }
                for(int j = 0; j < numTempos; j++){
                    media[j] += tempos[j];
                }
                }
                for(int i = 0; i < numTempos; i++){
                    media[i] = media[i]/numTestes;
                }
                printf("\nTempos--------------------------------------------\n");
                for(int i = 0; i < numTempos; i++){
                    printf("%lf\n", media[i]);
                }
                printf("--------------------------------------------------\n");
            }break;
            case 5: {
                printf("\nOrdenado(1)");
                printf("\nAleatorio(0)");
                printf("\nInvertido(-1)\n");
                scanf("%d", &metodo);
                for(int i = 0; i < numTestes; i++){
                    testeHeap(tempos, metodo);
                for(int q = 0; q < numTempos; q++){
                    media[q] = 0;
                }
                for(int j = 0; j < numTempos; j++){
                    media[j] += tempos[j];
                }
                }
                for(int i = 0; i < numTempos; i++){
                    media[i] = media[i]/numTestes;
                }
                printf("\nTempos--------------------------------------------\n");
                for(int i = 0; i < numTempos; i++){
                    printf("%lf\n", media[i]);
                }
                printf("--------------------------------------------------\n");
            }break;
            case 6: {
                printf("\nOrdenado(1)");
                printf("\nAleatorio(0)");
                printf("\nInvertido(-1)\n");
                scanf("%d", &metodo);
                for(int i = 0; i < numTestes; i++){
                    testeInsertion(tempos, metodo);
                for(int q = 0; q < numTempos; q++){
                    media[q] = 0;
                }
                for(int j = 0; j < numTempos; j++){
                    media[j] += tempos[j];
                }
                }
                for(int i = 0; i < numTempos; i++){
                    media[i] = media[i]/numTestes;
                }
                printf("\nTempos--------------------------------------------\n");
                for(int i = 0; i < numTempos; i++){
                    printf("%lf\n", media[i]);
                }
                printf("--------------------------------------------------\n");
            }break;
            case 7: {
                printf("\nOrdenado(1)");
                printf("\nAleatorio(0)");
                printf("\nInvertido(-1)\n");
                scanf("%d", &metodo);
                for(int i = 0; i < numTestes; i++){
                    testeMerge(tempos, metodo);
                for(int q = 0; q < numTempos; q++){
                    media[q] = 0;
                }
                for(int j = 0; j < numTempos; j++){
                    media[j] += tempos[j];
                }
                }
                for(int i = 0; i < numTempos; i++){
                    media[i] = media[i]/numTestes;
                }
                printf("\nTempos--------------------------------------------\n");
                for(int i = 0; i < numTempos; i++){
                    printf("%lf\n", media[i]);
                }
                printf("--------------------------------------------------\n");
            }break;
            case 8: {
                printf("\nOrdenado(1)");
                printf("\nAleatorio(0)");
                printf("\nInvertido(-1)\n");
                scanf("%d", &metodo);
                for(int i = 0; i < numTestes; i++){
                    testeQuick(tempos, metodo);
                for(int q = 0; q < numTempos; q++){
                    media[q] = 0;
                }
                for(int j = 0; j < numTempos; j++){
                    media[j] += tempos[j];
                }
                }
                for(int i = 0; i < numTempos; i++){
                    media[i] = media[i]/numTestes;
                }
                printf("\nTempos--------------------------------------------\n");
                for(int i = 0; i < numTempos; i++){
                    printf("%lf\n", media[i]);
                }
                printf("--------------------------------------------------\n");
            }break;
            case 9: {
                printf("\nOrdenado(1)");
                printf("\nAleatorio(0)");
                printf("\nInvertido(-1)\n");
                scanf("%d", &metodo);
                for(int i = 0; i < numTestes; i++){
                    testeSelection(tempos, metodo);
                for(int q = 0; q < numTempos; q++){
                    media[q] = 0;
                }
                for(int j = 0; j < numTempos; j++){
                    media[j] += tempos[j];
                }
                }
                for(int i = 0; i < numTempos; i++){
                    media[i] = media[i]/numTestes;
                }
                printf("\nTempos--------------------------------------------\n");
                for(int i = 0; i < numTempos; i++){
                    printf("%lf\n", media[i]);
                }
                printf("--------------------------------------------------\n");
            }break;
            case 10: {
                printf("\nOrdenado(1)");
                printf("\nAleatorio(0)");
                printf("\nInvertido(-1)\n");
                scanf("%d", &metodo);
                for(int i = 0; i < numTestes; i++){
                    testeShell(tempos, metodo);
                for(int q = 0; q < numTempos; q++){
                    media[q] = 0;
                }
                for(int j = 0; j < numTempos; j++){
                    media[j] += tempos[j];
                }
                }
                for(int i = 0; i < numTempos; i++){
                    media[i] = media[i]/numTestes;
                }
                printf("\nTempos--------------------------------------------\n");
                for(int i = 0; i < numTempos; i++){
                    printf("%lf\n", media[i]);
                }
                printf("--------------------------------------------------\n");
            }break;
        }
    }
    return 0;
}