#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

/*
	6
	5 1 -2 2 6 7
*/

struct Node{
    int data;
    Node* left;
    Node* right;
};

typedef struct Node* TREE;

// Them 1 node vao Tree
void Insert(TREE &t, int x){
    if(t == NULL){
        t = new Node();
        t -> data = x;
        t -> left = NULL;
        t -> right = NULL;
    } 
	else{
        if(x < t -> data) Insert(t -> left, x);
        else  Insert(t -> right, x);
    }
}

// Duyet theo thu tu truoc (Pre-order Traversal)
void printTree_NLR(TREE t){
    if(t != NULL){
        cout << t -> data << " ";
        printTree_NLR(t -> left);
        printTree_NLR(t -> right);
    }
}

void printTree_NRL(TREE t){
    if(t != NULL){
        cout << t -> data << " ";
        printTree_NRL(t -> right);
        printTree_NRL(t -> left);
    }
}

// Duyet theo thu tu giua (In-order Traversal)
void printTree_LNR(TREE t){
	if(t != NULL){
		printTree_LNR(t -> left);
		cout << t -> data << " ";
		printTree_LNR(t -> right);
	}
}

void printTree_RNL(TREE t){
	if(t != NULL){
		printTree_RNL(t -> right);
		cout << t -> data << " ";
		printTree_RNL(t -> left);
	}
}

// Duyet theo thu tu sau (Post-order Traversal)
void printTree_LRN(TREE t){
	if(t != NULL){
		printTree_LRN(t -> left);
		printTree_LRN(t -> right);
		cout << t -> data << " ";
	}
}

void printTree_RLN(TREE t){
	if(t != NULL){
		printTree_RLN(t -> right);
		printTree_RLN(t -> left);
		cout << t -> data << " ";
	}
}

int main(){
    int n, x; cin >> n;
    TREE t = NULL;
    for(int i = 0; i < n; i++){
        cin >> x;
        Insert(t, x);
    }
    printTree_NLR(t); cout << endl;
    printTree_NRL(t); cout << endl;
    printTree_LNR(t); cout << endl;
    printTree_RNL(t); cout << endl;
    printTree_LRN(t); cout << endl;
    printTree_RLN(t);
    return 0;
}

