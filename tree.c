#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int Tr_data;
typedef struct _binary_tree_node{
    Tr_data value;
    struct _binary_tree_node* left;
    struct _binary_tree_node* right;
}binary_tree_node;
void printTree(binary_tree_node* p){
    if(NULL != p){
        printf("my: %d\n",p->value);
    }
    else{
        return;
    }
    //printf("goto left:\n");
    printTree(p->left);
    //printf("goto right:\n");
    printTree(p->right);
}
void printTree_level(binary_tree_node* p){
    //SEQUEUE?
    binary_tree_node* queue[100];
    int rear=0,front=0;
    if(NULL != p){
        queue[rear++] = p;
        while(true){
            p = queue[front++];
            printf("data: %d\r\n",p->value);
            if(p->left){
                queue[rear++] = p->left;
            }
            if(p->right){
                queue[rear++] = p->right;
            }
            if(front == rear){
                break;
            }
        }
    }
}
int getTreeDepth(binary_tree_node * p)  
{  
    if(p == NULL) // 递归出口  
        return 0;  
    int depthLeft = getTreeDepth(p->left);  
    int depthRight = getTreeDepth(p->right);  
    return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);   
}  
void addTree(binary_tree_node* p,binary_tree_node* item){
    if(item->value > p->value){
        if(NULL == p->left){
            p->left = item;
        }
        else{
            addTree(p->left,item);
        }
    }
    else{
        if(NULL == p->right){
            p->right = item;
        }
        else{
            addTree(p->right,item);
        }
    }
}
void initTree(binary_tree_node* p){
    p->left = NULL;
    p->right = NULL;
}
int main(void){
    binary_tree_node* p;
    binary_tree_node*base = (binary_tree_node*)malloc(sizeof(binary_tree_node));
    initTree(base);
    base->value = 100;
    int i;
    srand(1);
    for(i=0;i<10;i++){
        p = (binary_tree_node*)malloc(sizeof(binary_tree_node));
        initTree(p);
        p->value = rand()*4906;
        //p->value = i;
        printf("%d\n",p->value);
        addTree(base,p);
    }
    printf("Tree Depth = %d\n",getTreeDepth(base));
    printf("________\n");
    //printTree(base);
    printTree_level(base);
    return 0;
}
