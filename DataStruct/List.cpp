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
    
    Node* pop_back(){
        if(rear == nullptr)
            return nullptr;
        Node *tmp = rear;
        rear = rear->prev;
        if(rear != nullptr){
            rear->next = nullptr;
        }
        size--;
        return tmp;
    }

    Node* pop_front(){
        if(head == nullptr)
            return nullptr;
        Node *tmp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        size--;
        return tmp;
    }

    Node* remove(int index){
        if(index < 0 || index >= size)
            return nullptr;
        if(index == 0){
            return pop_front();
        }
        else if(index == size - 1){
            return pop_back();
        }
        else{
            Node *cur = head;
            while(index > 0){
                cur = cur->next;
                index--;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            size--;
            return cur;
        }
    }

    Node* remove(Node *node){
        Node *cur = head;
        while(cur != nullptr){
            if(cur == node){
                if(cur == head){
                    return pop_front();
                }
                else if(cur == rear){
                    return pop_back();
                }
                else{
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    size--;
                    return cur;
                }
            }
            cur = cur->next;
        }
        return nullptr;
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