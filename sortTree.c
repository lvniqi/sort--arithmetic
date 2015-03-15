#include<stdlib.h>
#include<stdbool.h>
#include"sortTree.h"
void initTree(sortTree_node* p){
    p->left = NULL;
    p->right = NULL;
}
void printTree(sortTree_node* p){
    if(NULL == p){
        return;
    }
    printTree(p->left);
    printf("my: %d\n",p->value);
    printTree(p->right);
    //printf("goto left:\n");
    //printf("goto right:\n");
}
int _printTree_byLevel(sortTree_root T, int level) {  
    if (!T || level < 0){
        return 0;  
    }
    if (0 == level) {
        printf("%d\t",T->value);
        return 1;  
    }  
    return _printTree_byLevel(T->left, level - 1) 
        + _printTree_byLevel(T->right, level - 1);  
}
void printTree_byLevel(sortTree_root T) {  
    int i = 0;   
    for (i = 0; ; i++) {
        printf("\n");
        if (!_printTree_byLevel(T, i)){
           break; 
        }   
    }    
    printf("\n");
}  
/*查找，找到返回1，否则，返回0*/
bool searchTree(sortTree_root root, datatype dat){
    sortTree_node *p;
    p = root;
    if(p == NULL){
        return false;
    }
    if(p->value == dat){
        return true;
    }
    else if(p->value > dat){
        return searchTree(p->left, dat);
    }
    else{
        return searchTree(p->right, dat);
    }
}
int getTreeDepth(sortTree_root p){
    if(p == NULL) // 递归出口  
        return 0;  
    int depthLeft = getTreeDepth(p->left);  
    int depthRight = getTreeDepth(p->right);  
    return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);   
}

sortTree_node* _insertTree(sortTree_root root,
        sortTree_node* now,datatype dat){
    if(now == NULL){
        now = (sortTree_node*)malloc(sizeof(sortTree_node));
        initTree(now);
        now->value = dat;
        if(root == NULL){
            return now;
        }else{
            if(dat > root->value){
                root->right = now;
            }else{
                root->left = now;
            }
            return root;
        }
    }
    else{
        if(now->value == dat){
            return root;
        }
        /*若小于节点的值，则查看节点的左孩子，否则，查看右孩子*/
		else if(now->value < dat){
            _insertTree(now,now->right,dat);
            return root;
        }
		else{
			_insertTree(now,now->left,dat);
            return root;
        }
     }
}
/*删除节点值为value的节点*/
bool _deleteTree(sortTree_root root,
        sortTree_node* now,datatype value){
    if(NULL == now){
        return false;
    }
    else if(value == now->value){
        if(value > root->value){
           root->right = now->right;
        }
        else{
            root->left = now->left;
        }
        free(now);
        return true;
    }
    else if(value > now->value){
        return _deleteTree(now,now->right,value);
    }
    else{
        return _deleteTree(now,now->left,value);
    }
}
int main(void){
    sortTree_node*base = NULL;
    int i;
    srand(i);
    int temp;
    for(i=0;i<10;i++){
        temp = rand()%256;
        base = _insertTree(base,base,temp);
        printf("%d\n",temp);
        //addTree(base,p);
    }
    printf("________\n");
    printTree_byLevel(base);
    printf("Tree Depth = %d\n",getTreeDepth(base));
    _deleteTree(base,base,temp);
    printf("________\n");
    printTree(base);
    return 0;
}
