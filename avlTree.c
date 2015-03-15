#include <stdio.h>  
#include <stdlib.h> 
typedef int datatype;
typedef struct _avlTree_node
{
    datatype value;
    int nHeight;    /*树的平衡度*/
    struct _avlTree_node *left;
    struct _avlTree_node *right;
}avlTree_node;
typedef avlTree_node* avlTree_root;

void initAvlTree(avlTree_node* p){
    p->left = NULL;
    p->right = NULL;
}
/**
 * 插入
 */
void insertAvlTree(avlTree_root p,datatype value){
    if(p == NULL){
        return ;
    }
    else if(p->value == value){
        return ;
    }
    else if(p->value >value){
        if(p->left != NULL){
            insertAvlTree(p->left,value);
        }
        else{
            avlTree_node* temp = (avlTree_node*)malloc(sizeof(avlTree_node));
            initAvlTree(temp);
            temp->value = value;
            p->left = temp;
        }
    }
    else{
        if(p->right != NULL){
            insertAvlTree(p->right,value);
        }
        else{
            avlTree_node* temp = (avlTree_node*)malloc(sizeof(avlTree_node));
            initAvlTree(temp);
            temp->value = value;
            p->right = temp;
        }
    }
}
int getMax(int x,int y){
    return x > y ? x: y;
}
int getAvlTreeHeight(avlTree_node* p){
    if(NULL == p){
        return -1;
    }
    else{
        return p->nHeight;
    }
}
avlTree_node* _rotateAvlTree_L(avlTree_node* p){  
    //以p为根节点的二叉排序树进行单向左旋处理  
    avlTree_node *r_child=p->right;  
    p->right=r_child->left;  
    r_child->left = p; 
    //需要更新节点高度值
    p->nHeight = getMax(getAvlTreeHeight(p->left),
            getAvlTreeHeight(p->right))+1;
    r_child->nHeight = getMax(getAvlTreeHeight(r_child->left),
            getAvlTreeHeight(r_child->right))+1;
    return r_child;
}  



