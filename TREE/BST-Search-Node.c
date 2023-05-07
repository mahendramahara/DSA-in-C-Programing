#include <stdio.h>
#include <stdlib.h>

// Structure for a binary search tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node with the given key
struct Node *newNode(int key) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to search for a key in the BST
struct Node *search(struct Node *root, int key) {
    // Base cases: root is null or key is present at the root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key, search in the right subtree
    if (key > root->key)
        return search(root->right, key);

    // Key is smaller than root's key, search in the left subtree
    return search(root->left, key);
}

struct Node *insert(struct Node *root, int key) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    // Return the (unchanged) node pointer
    return root;
}

// Driver code to test the search
int main() {
    struct Node *root = NULL;

    // Insert nodes into the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Search for a key in the binary search tree
    int keyToSearch = 40;
    struct Node *result = search(root, keyToSearch);

    // Display the result
    if (result != NULL)
        printf("Key %d found in the BST.\n", keyToSearch);
    else
        printf("Key %d not found in the BST.\n", keyToSearch);

    return 0;
}
