#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int max_element(int array[], int size) {  
    int max = INT_MIN;  
    for (int i = 0; i < size; i++) {
        if (array[i] > max)  
            max = array[i];  
    }
    return max;  
}

void bucketSort(int arr[], int n) {  
    int max = max_element(arr, n); 
    int *bucket = (int *)calloc(max + 1, sizeof(int));

    if (bucket == NULL) {
        fprintf(stderr, "Erro ao alocar memória para os buckets.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)  
        bucket[arr[i]]++;

    int j = 0;   
    for (int i = 0; i <= max; i++) { 
        while (bucket[i] > 0) {  
            arr[j++] = i;  
            bucket[i]--;   
        }  
    }  

    free(bucket);
}

void countSort(int arr[], int n) {
    int M = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > M)
            M = arr[i];

    int* countArray = (int*)calloc(M + 1, sizeof(int));
    for (int i = 0; i < n; i++)
        countArray[arr[i]]++;

    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    int* outputArray = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        outputArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = outputArray[i];

    free(countArray);
    free(outputArray);
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSortRadix(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int* count = (int*)malloc(10 * sizeof(int));

    if (output == NULL || count == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
    free(count);
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp);
}

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0]; 
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = (int *)malloc(n1 * sizeof(int));
    int *rightArr = (int *)malloc(n2 * sizeof(int));

    if (leftArr == NULL || rightArr == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    swap(&arr[low], &arr[mid]);
    int p = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= p) {
            i++;
        }
        while (j >= low + 1 && arr[j] > p) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void shellSort(int arr[], int n) {
    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}
