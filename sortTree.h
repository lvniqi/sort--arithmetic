#ifndef SORT_TREE_H_
	#define SORT_TREE_H_
	#include<stdio.h>
	typedef int datatype;
	typedef struct _sort_tree_node{
		datatype value;
		struct _sort_tree_node* left;
		struct _sort_tree_node* right;
	}sort_tree_node;

	extern void initTree(sort_tree_node* p);
	extern void printTree(sort_tree_node* p);
	extern bool searchTree(sort_tree_node *root, datatype dat);
	extern int getTreeDepth(sort_tree_node * p);
	extern sort_tree_node* _insertTree(sort_tree_node* root,
		sort_tree_node* now,datatype dat);
	#define insertTree(a,b) _insertTree((a),(a),b)
	extern bool _deleteTree(sort_tree_node *root,
			sort_tree_node* now,datatype value); 
	#define deleteTree(a,b) _deleteTree((a),(a),b)
#endif
