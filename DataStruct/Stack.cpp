#include <iostream>

#define MAX_N 10000

struct Stack{
    int data[MAX_N];
    int size;

    Stack(){
        clear();
    }

    void clear(){
        size = 0;
    }

    void push(int v){
        if(size == MAX_N)
            return;
        data[size] = v;
        size++;
    }

    int top(){
        if(size == 0)
            return -1;
        return data[size - 1];
    }

    void pop(){
        if(size == 0)
            return;
        size--;
    }
};

int main(){
    int a[] = {1, 4, 5, 3, -1, 0, 2, 7};
    Stack st;
    for(int i = 0; i < 8; i++){
        st.push(a[i]);
    }    
    while(st.size > 0){
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}