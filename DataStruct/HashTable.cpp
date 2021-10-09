#include <iostream>
#include <cstring>

#define MAX_N 10000
#define MAX_L 21

struct HashNode{
    char key[MAX_L];
    int data;
};

struct Hash{
    HashNode table[MAX_N];

    void clear(){
        for(int i = 0; i < MAX_N; i++){
            table[i].key[0] = 0;
        }
    }

    unsigned int hashKey(char *key){
        unsigned int hash = 5381;
        for(int i = 0; key[i]; i++){
            hash = (((hash << 5) + hash) + key[i]) % MAX_N;
        }
        return hash % MAX_N;
    }

    int put(char *key, int v){
        int hKey = hashKey(key);
        int cnt = MAX_N;
        while(table[hKey].key[0] != 0 && cnt > 0){
            if(strcmp(table[hKey].key, key) == 0){
                table[hKey].data = v;
                return hKey;
            }
            hKey = (hKey + 1) % MAX_N;
            cnt--;
        }
        if(cnt == 0 && table[hKey].key[0] != 0)
            return -1; // fail
        strcpy(table[hKey].key, key);
        table[hKey].data = v;
        return hKey;
    }

    int get(char *key, int &v){
        int hKey = hashKey(key);
        int cnt = MAX_N;
        int id = -1;
        while(table[hKey].key[0] != 0 && cnt > 0){
            if(strcmp(table[hKey].key, key) == 0){
                id = hKey;
                v = table[hKey].data;
                break;
            }
        }
        return id;
    }
};

int main(){
    Hash hash;
    int id, v;
    id = hash.get((char*) "lvminh", v);
    printf("lvminh id=%d v=%d\n", id, v);
    hash.put((char*) "lvminh", 10);
    id = hash.get((char*) "lvminh", v);
    printf("lvminh id=%d v=%d\n", id, v);
    hash.put((char*) "lvminh", 100);
    id = hash.get((char*) "lvminh", v);
    printf("lvminh id=%d v=%d\n", id, v);
    return 0;
}