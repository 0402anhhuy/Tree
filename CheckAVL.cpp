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
		else Insert(t -> right, x);
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

int main(){
	int n, key; cin >> n;
	TREE t = NULL;
	for(int i = 0; i < n; i++){
		cin >> key; Insert(t, key);
	}
	cout << boolalpha << CheckAVL(t) << endl;
	return 0;
}
