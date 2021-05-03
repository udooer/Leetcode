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
private:
	TreeNode *m_root;
public:
	BinaryTree():m_root(0){};
	BinaryTree(TreeNode *ptr):m_root(ptr){};
	void preOrder(TreeNode *);
	void inOrder(TreeNode *);
	void postOrder(TreeNode *);
};

void BinaryTree::postOrder(TreeNode *root){
	if(root){
		postOrder(root->m_left_child);
		postOrder(root->m_right_child);
		cout<<root->m_data<<" ";
	}
	return;
}

void BinaryTree::preOrder(TreeNode *root){
	if(root){
		cout<<root->m_data<<" ";
		preOrder(root->m_left_child);
		preOrder(root->m_right_child);
	}
	return;
}

void BinaryTree::inOrder(TreeNode *root){
	if(root){
		inOrder(root->m_left_child);
		cout<<root->m_data<<" ";
		inOrder(root->m_right_child);
	}
	return;
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
	BinaryTree BT(ptr_A);

	cout<<"pre-order list: \n";
	BT.preOrder(ptr_A);
	cout<<"\nin-order list: \n";
	BT.inOrder(ptr_A);
	cout<<"\npost-order list: \n";
	BT.postOrder(ptr_A);
}	


