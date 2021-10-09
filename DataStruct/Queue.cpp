#include <iostream>

#define MAX_N 10000

struct Queue{
    int data[MAX_N];
    int head, rear, size;

    Queue(){
        clear();
    }

    void clear(){
        head = rear = size = 0;
    }

    int front(){
        return data[head];
    }

    void enqueue(int v){
        if(size == MAX_N)
            return;
        data[rear] = v;
        rear = (rear + 1) % MAX_N;
        size++;
    }

    void dequeue(){
        if(size == 0)
            return;
        head = (head + 1) % MAX_N;
        size--;
    }
};

int main(){
    int a[] = {1, 4, 5, 3, -1, 0, 2, 7};
    Queue q;
    for(int i = 0; i < 8; i++){
        q.enqueue(a[i]);
    }    
    while(q.size > 0){
        printf("%d ", q.front());
        q.dequeue();
    }
    return 0;
}