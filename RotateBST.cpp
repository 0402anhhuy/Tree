#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
};

typedef struct Node* TREE;

int getHeight(TREE t){
    if(t == NULL) return 0;
    return t -> height;
}

TREE newNode(int x){
    TREE node = new Node();
    node -> data = x;
    node -> left = NULL;
    node -> right = NULL;
    node -> height = 1;
    return node;
}

TREE rightRotate(TREE root){
    TREE x = root -> left;
    TREE T2 = x -> right;

    // Quay
    x -> right = root;
    root -> left = T2;

    // Update heights
    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
    x -> height = max(getHeight(x -> left), getHeight(x -> right)) + 1;
    return x;
}

TREE leftRotate(TREE root){
    TREE y = root -> right;
    TREE T2 = y -> left;

    // Quay
    y -> left = root;
    root -> right = T2;

    // Update heights
    root -> height = max(getHeight(root -> left), getHeight(root -> right)) + 1;
    y -> height = max(getHeight(y -> left), getHeight(y -> right)) + 1;
    return y;
}

int getBalance(TREE t){
    if(t == NULL) return 0;
    return getHeight(t -> left) - getHeight(t -> right);
}

TREE insert(TREE node, int x){
	// 1. Normal BST
    if(node == NULL) return newNode(x);
    if(x < node -> data)
        node -> left = insert(node -> left, x);
    else if(x > node -> data)
        node -> right = insert(node -> right, x);
    else return node;

    node -> height = 1 + max(getHeight(node -> left), getHeight(node -> right));
    int balance = getBalance(node);
    
    // Left Left Case
    if(balance > 1 && x < node -> left -> data)
        return rightRotate(node);

    // Right Right Case
    if(balance < -1 && x > node -> right -> data)
        return leftRotate(node);

    // Left Right Case
    if(balance > 1 && x > node -> left -> data){
        node -> left = leftRotate(node -> left);
        return rightRotate(node);
    }

    // Right Left Case
    if(balance < -1 && x < node -> right -> data){
        node -> right = rightRotate(node -> right);
        return leftRotate(node);
    }
    
    return node;
}

void printTree_NLR(TREE t){
    if(t != NULL){
        cout << t -> data << " ";
        printTree_NLR(t -> left);
        printTree_NLR(t -> right);
    }
}

int main(){
    TREE root = NULL;
    int n, tmp; cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> tmp;
    	root = insert(root, tmp);
	}
	printTree_NLR(root);
    return 0;
}

