#include <iostream>

struct Node{
    int data;
    Node *prev, *next;

    Node(int v){
        data = v;
        prev = next = nullptr;
    }
};

struct List{
    Node *head, *rear;
    int size;

    List(){
        head = rear = nullptr;
        size = 0;
    }

    Node *front(){
        return head;
    }

    Node *back(){
        return rear;
    }

    void push_back(int v){
        Node *nNode = new Node(v);
        if(head == nullptr){
            head = rear = nNode;
        }
        else{
            rear->next = nNode;
            nNode->prev = rear;
            rear = nNode;
        }
        size++;
    }

    void push_front(int v){
        Node *nNode = new Node(v);
        if(head == nullptr){
            head = rear = nNode;
        }
        else{
            nNode->next = head;
            head->prev = nNode;
            head = nNode;
        }
        size++;
    }
    
    Node *pop_back(){
        Node *tmp = rear;
        rear = rear->prev;
        if(rear != nullptr){
            rear->next = nullptr;
        }
        size--;
        return tmp;
    }

    Node *pop_front(){
        Node *tmp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        size--;
        return tmp;
    }

    bool remove(int index){
        
    }
};

int main(){
    List list;
    list.push_front(7);
    list.push_back(1);
    list.push_back(4);
    list.push_back(3);
    list.push_front(2);

    Node *cur = list.head;
    while(cur != nullptr){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    return 0;
}