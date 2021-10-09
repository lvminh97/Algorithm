#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_N 10000

struct Heap{
    int data[MAX_N + 1];
    int size;

    bool cmp(int a, int b){
        return data[a] < data[b];
    }

    void swap(int a, int b){
        int tmp = data[a];
        data[a] = data[b];
        data[b] = tmp;
    }

    void push(int v){
        size++;
        data[size] = v;
        for(int i = size, j = size >> 1; j > 0; i = j, j >>= 1){
            if(cmp(j, i))
                break;
            swap(i, j);
        }
    }

    int top(){
        return data[1];
    }

    void pop(){
        swap(1, size);
        size--;
        for(int i = 1, j = 2; j <= size; i = j, j <<= 1){
            if(j < size && cmp(j + 1, j))
                j++;
            if(cmp(i, j))
                break;
            swap(i, j);
        }
    }
};

int main(){
    Heap heap;
    for(int i = 0; i < MAX_N; i++){
        heap.push(rand() % 30000);
    } 
    while(heap.size > 0){
        printf("%d ", heap.top());
        heap.pop();
    }
    return 0;
}