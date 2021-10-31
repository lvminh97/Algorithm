#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int a[], int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int partitionSort(int a[], int L, int R){
    int id = (L + R) / 2;
    int pivot = a[id];
    swap(a, id, R);
    id = L;
    for(int i = L; i < R; i++){
        if(a[i] < pivot){
            swap(a, i, id);
            id++;
        }
    }
    swap(a, id, R);
    return id;
}

void quickSort(int a[], int L, int R){
    int pivot = partitionSort(a, L, R);
    if(pivot > L) 
        quickSort(a, L, pivot - 1);
    if(pivot < R) 
        quickSort(a, pivot + 1, R);
}

int a[100000];

int main(){
    srand(time(NULL));
    for(int i = 0; i < 100000; i++){
        a[i] = rand();
    }
    quickSort(a, 0, 99999);
    bool check = true;
    for(int i = 1; i < 100000; i++){
        if(a[i] < a[i - 1])
            check = false;
    }
    printf("Result: %s", check ? "True" : "False");
    return 0;
}