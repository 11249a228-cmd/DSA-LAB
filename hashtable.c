#include <stdio.h>
#define TABLESIZE 10
int hashTable[TABLESIZE];
void initHashTable() {
    for(int i=0; i<TABLESIZE; i++) hashTable[i] = -1;
}
int hashFunction(int key) { return key % TABLESIZE; }
void insert(int key) {
    int hashIndex = hashFunction(key), originalIndex = hashIndex;
    while(hashTable[hashIndex] != -1) {
        hashIndex = (hashIndex + 1)%TABLESIZE;
        if(hashIndex == originalIndex) { printf("Hash table is full, cannot insert %d\n", key); return; }
    }
    hashTable[hashIndex] = key;
}
int search(int key) {
    int hashIndex = hashFunction(key), originalIndex = hashIndex;
    while(hashTable[hashIndex] != -1) {
        if(hashTable[hashIndex] == key)
            return hashIndex;
        hashIndex = (hashIndex + 1) % TABLESIZE;
        if(hashIndex == originalIndex) break;
    }
    return -1;
}
void display() {
    printf("Hash Table:\n");
    for(int i=0; i<TABLESIZE; i++)
        if(hashTable[i]==-1) printf("%d: Empty\n", i);
        else printf("%d: %d\n", i, hashTable[i]);
}
int main() {
    initHashTable();
    insert(23); insert(43); insert(13); insert(27); insert(37);
    display();
    int key = 13, result = search(key);
    if(result != -1) printf("Key %d found at index %d\n", key, result);
    else printf("Key %d not found in hash table\n", key);
    key = 50; result = search(key);
    if(result != -1) printf("Key %d found at index %d\n", key, result);
    else printf("Key %d not found in hash table\n", key);
    return 0;
}
