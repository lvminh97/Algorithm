#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int a[], int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void heapify(int a[], int i, int n){
	int L = 2 * i + 1;
	int R = 2 * i + 2;
	int maxId = i;
	if(L < n && a[L] > a[maxId]) 
        maxId = L;
	if(R < n && a[R] > a[maxId]) 
        maxId = R;
	if(maxId != i){
		swap(a, maxId, i);
		heapify(a, maxId, n);
	}
}

void heapSort(int a[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, i, n);
    }
    for(int i = n - 1; i > 0; i--){
        swap(a, 0, i);
        heapify(a, 0, i - 1);
    }
}

int a[100000];

int main(){
    srand(time(NULL));
    for(int i = 0; i < 100000; i++){
        a[i] = rand();
    }
    heapSort(a, 100000);
    bool check = true;
    for(int i = 1; i < 100000; i++){
        if(a[i] < a[i - 1])
            check = false;
    }
    printf("Result: %s", check ? "True" : "False");
    return 0;
}