// Assignment AI
// This program looks for a value and returns the node that contains that value!
#include<stdio.h>
#include<stdlib.h>

struct Node{
	
	int value;
	struct Node *left, *right;
	
};

struct Node* getNewNode(int value){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct Node* insert(struct Node *node, int value){
	if(node == NULL)
		return getNewNode(value);
		
	if(value < node->value){
		node->left = insert(node->left, value);
	}else{
		node->right = insert(node->right, value);
	}
	
	return node;
}

void inorder(struct Node *node){
	if(node != NULL){
		inorder(node->left);
		printf("%d ", node->value);
		inorder(node->right);
	}
}
struct Node* getNode(struct Node *node, int value){
	if(node == NULL)
		return NULL;
	if(node->value == value)
		return node;
	if(value < node->value)
		return getNode(node->left, value);
	if(value > node->value)
		return getNode(node->right, value);
}

int main(){
	
	struct Node *root = NULL;
	
	// Please choose your input from these values if you want your input to be found!
	root = insert(root, 64);
	insert(root, 1);
	insert(root, 63);
	insert(root, 114);
	insert(root, 27);
	insert(root, 5);
	insert(root, 98);
	insert(root, 19);
	insert(root, 35);
	
	int input;
	printf("input: ");
	scanf("%d", &input);
	
	struct Node *node = getNode(root, input);
	
	node? printf("%d\n", node->value) : printf("Not found!\n");
	
	return 0;
}
