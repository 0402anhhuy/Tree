#include<bits/stdc++.h>
using namespace std;

/*
	7
	4 7 2 1 3 2 5
*/

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

int TreeLevel(TREE &t){
	if(t == NULL) return -1;
	return 1 + max(TreeLevel(t -> left), TreeLevel(t -> right));
}

int main(){
	int n, x; cin >> n;
	TREE t = NULL;
	for(int i = 0; i < n; i++){
		cin >> x;
		Insert(t, x);
	}
	int res = TreeLevel(t);
	cout << res;
	return 0;
}
