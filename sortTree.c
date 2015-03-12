#include<stdlib.h>
#include<stdbool.h>
#include"sortTree.h"
void initTree(sort_tree_node* p){
    p->left = NULL;
    p->right = NULL;
}
void printTree(sort_tree_node* p){
    if(NULL == p){
        return;
    }
    printTree(p->left);
    printf("my: %d\n",p->value);
    printTree(p->right);
    //printf("goto left:\n");
    //printf("goto right:\n");
}
/*查找，找到返回1，否则，返回0*/
bool searchTree(sort_tree_node *root, datatype dat){
    sort_tree_node *p;
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
int getTreeDepth(sort_tree_node * p){
    if(p == NULL) // 递归出口  
        return 0;  
    int depthLeft = getTreeDepth(p->left);  
    int depthRight = getTreeDepth(p->right);  
    return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);   
}

sort_tree_node* _insertTree(sort_tree_node* root,
        sort_tree_node* now,datatype dat){
    if(now == NULL){
        now = (sort_tree_node*)malloc(sizeof(sort_tree_node));
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
bool _deleteTree(sort_tree_node *root,
        sort_tree_node* now,datatype value){
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
    sort_tree_node*base = NULL;
    int i;
    srand(i);
    int temp;
    for(i=0;i<10;i++){
        temp = rand()*4096;
        base = _insertTree(base,base,temp);
        printf("%d\n",temp);
        //addTree(base,p);
    }
    printf("________\n");
    _deleteTree(base,base,temp);
    printf("Tree Depth = %d\n",getTreeDepth(base));
    printf("________\n");
    printTree(base);
    return 0;
}
