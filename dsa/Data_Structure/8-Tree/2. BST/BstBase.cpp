#include <bits/stdc++.h>
using namespace std;

// BST Node
struct node {
    int key;
    struct node *left, *right;
};

// create new BST node
struct node *newNode(int item) {
    node *temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//
struct node *search(struct node *root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

struct node *insert(struct node *root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

node *successor(node *root) {
    root = root->right;
    while (root->left != NULL)
        root = root->left;
    return root;
}

node *predecessor(node *root) {
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node *deleteNode(struct node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return (temp);
        }
        // node with two child
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

struct node *LCARecursive(struct node *root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    if (root->key > n1 && root->key > n2)
        return LCARecursive(root->left, n1, n2);
    if (root->key < n1 && root->key < n2)
        return LCARecursive(root->right, n1, n2);
    return root;
}

struct node *LCA(struct node *root, int n1, int n2) {
    while (root != NULL) {
        if (root->key < n1 && root->key < n2)
            root = root->right;
        else if (root->key > n1 && root->key > n2)
            root = root->left;
        else
            break;
    }
    return root;
}

node *floor(node *root, int x) {
    node *res = NULL;
    while (root != NULL) {
        if (root->key == x)
            return root;
        else if (root->key > x)
            root = root->left;
        else {
            res = root;
            root = root->right;
        }
    }
    return res;
}

node *ceil(node *root, int x) {
    node *res = NULL;
    while (root != NULL) {
        if (root->key == x)
            return root;
        else if (root->key < x)
            root = root->right;
        else {
            res = root;
            root = root->left;
        }
    }
    return res;
}

int main() {
    struct node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    inorder(root);
}
