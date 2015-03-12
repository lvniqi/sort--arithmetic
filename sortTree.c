#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct _sort_tree_node{
    datatype value;
    struct _sort_tree_node* left;
    struct _sort_tree_node* right;
}sort_tree_node;
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
int searchTree(sort_tree_node *root, datatype dat){
    sort_tree_node *p;
    p = root;
    if(p == NULL){
        return 0;
    }
    if(p->value == dat){
        return 1;
    }
    else if(p->value > dat){
        return searchTree(p->left, dat);
    }
    else{
        return searchTree(p->right, dat);
    }
}
int getTreeDepth(sort_tree_node * p)  
{  
    if(p == NULL) // 递归出口  
        return 0;  
    int depthLeft = getTreeDepth(p->left);  
    int depthRight = getTreeDepth(p->right);  
    return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);   
}  
sort_tree_node* insertTree(sort_tree_node* root ,datatype dat){
    sort_tree_node *parent,*node,*child;
    if(root == NULL){
        root = (sort_tree_node*)malloc(sizeof(sort_tree_node));
        initTree(root);
        root->value = dat;
    }
    else{
        parent = root;    /*记录下根节点的位置*/
        node = root;
         while(node != NULL){
            /*待插入数据已经存在，则返回*/
            if(node->value == dat){
                return root;
            }
            else{
				parent = node;
				/*若小于节点的值，则查看节点的左孩子，否则，查看右孩子*/
				if(node->value < dat)
					node = node->right;
				else
					node = node->left;
            }
        }
        child = (sort_tree_node *)malloc(sizeof(sort_tree_node));
        child->value = dat;
        child->left = NULL;
        child->right = NULL;
        if(dat > parent->value){
            parent->right = child; 
        }
        else{
            parent->left = child;
        }
        return root;
    }
}
/*删除节点值为value的节点*/
int deleteTree(sort_tree_node *root, datatype value){
    sort_tree_node *p, *pre=NULL, *mid;
    p = root;
    if(root == NULL){
        return 0;
    }
    /*找到该节点*/
    while((p != NULL) && (p->value != value)){
        pre = p;
        if(p->value < value){
            p = p->right;
        }
        else{
            p = p->left;
        }
    }
    if(p == NULL){
        return 0;
    }
    /*至少有一个子节点为空*/
    if( (p->left == NULL) || (p->right == NULL) ){
        if( pre->left == p ){
            pre->left = ( (p->left == NULL) ? p->right : p->left );
        }
        else{
            pre->right = ( (p->left == NULL) ? p->right : p->left );
        }
        free(p);    /*释放节点*/
    }
    else{
        /*删除的节点有2个子女*/
        mid = p->right;
        pre = p;
        /*寻找中序的第一个节点*/
        while(mid->left != NULL){    
            pre = mid;
            mid = mid->left;
        }
        /*移花接木，直接赋值，避免交换节点*/
        p->value = mid->value;
        
        /*将mid节点的子节点作为pre的子节点，并将mid所指向的节点删除*/
        if(pre->right == mid){
            pre->right = mid->right;
        }
        else{
            pre->left = mid->right;
        }
        free(mid);
    }
    return 1;
}
int main(void){

    sort_tree_node*base = NULL;
    int i;
    srand(i);
    int temp;
    for(i=0;i<10;i++){
        temp = rand()*4096;
        base = insertTree(base,temp);
        printf("%d\n",temp);
        //addTree(base,p);
    }
    printf("________\n");
    deleteTree(base,temp);
    printf("Tree Depth = %d\n",getTreeDepth(base));
    printf("________\n");
    printTree(base);
    return 0;
}
