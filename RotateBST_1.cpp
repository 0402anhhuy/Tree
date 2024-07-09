#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

typedef struct Node* TREE;

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

int TreeLevel(TREE t){
	if(t == NULL) return -1;
	return 1 + max(TreeLevel(t -> left), TreeLevel(t -> right));
}

bool CheckAVL(TREE t){
	if(t == NULL) return true;
	if(abs(TreeLevel(t -> left) - TreeLevel(t -> right)) > 1) return false;
	return CheckAVL(t -> left) && CheckAVL(t -> right);
}

TREE rightRotate(TREE root){
    TREE x = root -> left;
    TREE T2 = x -> right;

    // Quay
    x -> right = root;
    root -> left = T2;
    return x;
}

TREE leftRotate(TREE root){
    TREE y = root -> right;
    TREE T2 = y -> left;

    // Quay
    y -> left = root;
    root -> right = T2;
    return y;
}

TREE UpdateTreeAVL(TREE t){
	if(abs(TreeLevel(t -> left) - TreeLevel(t -> right)) > 1){
		if(TreeLevel(t -> left) > TreeLevel(t -> right)){
			TREE p = t -> left;
			if(TreeLevel(p -> left) >= TreeLevel(p -> right)){
				t = rightRotate(t);
			} 
			else{
				t -> left = leftRotate(t -> left);
				t = rightRotate(t);
			}
		} 
		else{
			TREE p = t -> right;
			if(TreeLevel(p -> right) >= TreeLevel(p -> left)){
				t = leftRotate(t);
			} 
			else{
				t -> right = rightRotate(t -> right);
				t = leftRotate(t);
			
			}
		}	
	}
	if(t -> left != NULL) t -> left = UpdateTreeAVL(t -> left);
	if(t -> right != NULL) t -> right = UpdateTreeAVL(t -> right);
	return t;
}

void printTree_NLR(TREE t){
    if(t != NULL){
        cout << t -> data << " ";
        printTree_NLR(t -> left);
        printTree_NLR(t -> right);
    }
}

int main(){
	int n, temp; cin >> n;
	TREE t = NULL;
	for(int i = 0; i < n; i++){
		cin >> temp;
		Insert(t, temp);
	}
	while(!CheckAVL(t)){
		t = UpdateTreeAVL(t);		
	}
	cout << TreeLevel(t) << endl;
	printTree_NLR(t);
	return 0;
}
