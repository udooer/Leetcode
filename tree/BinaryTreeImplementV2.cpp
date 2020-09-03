#include<string>
#include<iostream>
using namespace std;

class BinaryTree;
class TreeNode{
public:
	TreeNode *m_left_child;
	TreeNode *m_right_child;
	TreeNode *m_parent;
	string m_data;
	TreeNode():m_left_child(0), m_right_child(0), m_parent(0), m_data(""){};
	TreeNode(string data):m_left_child(0), m_right_child(0), m_parent(0), m_data(data){};
};
class BinaryTree{
public:
	TreeNode *m_root;
	BinaryTree():m_root(0){};
	BinaryTree(TreeNode *ptr):m_root(ptr){};
	TreeNode* leftMost(TreeNode *);
	TreeNode* inorderSuccesor(TreeNode *);
	void printInorderTraversal(TreeNode *);
};

TreeNode* BinaryTree::leftMost(TreeNode *current){
	while(current->m_left_child){
		current = current->m_left_child;
	}
	return current;
}

TreeNode* BinaryTree::inorderSuccesor(TreeNode *current){
	if(current->m_right_child){
		return leftMost(current->m_right_child);
	}
	else{
		TreeNode *temp=current;
		current = current->m_parent;
		while(current && current->m_left_child!=temp){
			temp = current;
			current = current->m_parent;
		}
		return current;
	}
}
void BinaryTree::printInorderTraversal(TreeNode *root){
	TreeNode *current = leftMost(root); 
	while(current){
		cout<<current->m_data<<' ';
		current = inorderSuccesor(current);
	}
	cout<<'\n';
}


int main(){
	TreeNode *ptr_A = new TreeNode("A");
	TreeNode *ptr_B = new TreeNode("B");
	TreeNode *ptr_C = new TreeNode("C");
	TreeNode *ptr_D = new TreeNode("D");
	TreeNode *ptr_E = new TreeNode("E");
	TreeNode *ptr_F = new TreeNode("F");
	TreeNode *ptr_G = new TreeNode("G");
	TreeNode *ptr_H = new TreeNode("H");
	TreeNode *ptr_I = new TreeNode("I");

	ptr_A->m_left_child = ptr_B;
	ptr_B->m_left_child = ptr_D;
	ptr_B->m_right_child = ptr_E;
	ptr_E->m_left_child = ptr_G;
	ptr_E->m_right_child = ptr_H;
	ptr_A->m_right_child = ptr_C;
	ptr_C->m_left_child = ptr_F;
	ptr_F->m_right_child = ptr_I;

	ptr_D->m_parent = ptr_B;
	ptr_B->m_parent = ptr_A;
	ptr_E->m_parent = ptr_B;
	ptr_G->m_parent = ptr_E;
	ptr_H->m_parent = ptr_E;
	ptr_I->m_parent = ptr_F;
	ptr_F->m_parent = ptr_C;
	ptr_C->m_parent = ptr_A;

	BinaryTree BT(ptr_A);
	BT.printInorderTraversal(BT.m_root);
	return 0;
}	


