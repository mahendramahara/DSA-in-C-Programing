#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct KeyValue {
    int key;
    int value;
    struct KeyValue* next;
};

struct HashTable {
    struct KeyValue *table[SIZE];
};

int hashFunction(int key) {
    return key % SIZE;
}

void insert(struct HashTable *hashTable, int key, int value) {
    int index = hashFunction(key);
    if (hashTable->table[index] == NULL) {
        struct KeyValue *newPair = (struct KeyValue *)malloc(sizeof(struct KeyValue));
        newPair->key = key;
        newPair->value = value;
        newPair->next = NULL;
        hashTable->table[index] = newPair;
    } else {
        struct KeyValue *current = hashTable->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        struct KeyValue *newPair = (struct KeyValue *)malloc(sizeof(struct KeyValue));
        newPair->key = key;
        newPair->value = value;
        newPair->next = NULL;
        current->next = newPair;
    }
}

int search(struct HashTable *hashTable, int key) {
    int index = hashFunction(key);
    struct KeyValue *current = hashTable->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

int main() {
    struct HashTable hashTable;
    for (int i = 0; i < SIZE; i++) {
        hashTable.table[i] = NULL;
    }
    insert(&hashTable, 12, 100);
    insert(&hashTable, 25, 200);
    insert(&hashTable, 35, 300);
    int value1 = search(&hashTable, 12);
    int value2 = search(&hashTable, 25);
    int value3 = search(&hashTable, 35);
    int value4 = search(&hashTable, 99);
    printf("Value for key 12: %d\n", value1);
    printf("Value for key 25: %d\n", value2);
    printf("Value for key 35: %d\n", value3);
    printf("Value for key 99: %d\n", value4);
    return 0;
}
