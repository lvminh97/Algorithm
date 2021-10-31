#include <iostream>
#include <cstdlib>
#include <ctime>

void mergeSort(int a[], int L, int R){
    if(L >= R)
        return;
    int mid = (L + R) / 2;
    mergeSort(a, L, mid);
    mergeSort(a, mid + 1, R);
    int *tmp = new int[R - L + 1];
    int id = 0, lid = L, rid = mid + 1;
    while(lid <= mid || rid <= R){
        if(lid <= mid && rid <= R){
            if(a[lid] < a[rid]){
                tmp[id] = a[lid];
                lid++;
            }
            else{
                tmp[id] = a[rid];
                rid++;
            }
        }
        else if(lid <= mid){
            tmp[id] = a[lid];
            lid++;
        }
        else{
            tmp[id] = a[rid];
            rid++;
        }
        id++;
    }
    for(int i = L; i <= R; i++){
        a[i] = tmp[i - L];
    }
    delete[] tmp;
}

int a[100000];

int main(){
    srand(time(NULL));
    for(int i = 0; i < 100000; i++){
        a[i] = rand();
    }
    mergeSort(a, 0, 99999);
    bool check = true;
    for(int i = 1; i < 100000; i++){
        if(a[i] < a[i - 1])
            check = false;
    }
    printf("Result: %s", check ? "True" : "False");
    return 0;
}