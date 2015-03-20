平衡二叉树笔记
==============


## 前言
最近跳入二叉树的坑，本来以为很简单的东西，结果发现自己too young too simple了.....不管如何，慢慢填二叉树的坑吧...今天介绍的是平衡二叉树。

**名词说明**

***平衡因子:	每个结点的左右子树的高度之差的绝对值***

***旋转:	AVL树通过节点间的旋转将不平衡变为平衡***

***
## 为何使用AVL树?
二叉树本来就是为了平衡插入、查找、排序的时间复杂度所设，而普通二叉排序树如果遇到特殊情况就会退化为链表，此时二叉树优势荡然无存。

	1
	  \
  	   2
    	 \
     	  3
      		\
       		  4
        		\
        	     5

例如上述例子，二叉树完全沦为了链表，找一个结点的时间复杂度是**O(N)**。

**而如果使用AVL树**

	 2
  	/ \
 	1   4
	 	/ \
   	   3   5

此时，二叉树找一个结点的时间复杂度是**O(logN)**。

***
## 怎么做？
对于一个avl树来说，其不平衡发生在插入一个节点，造成其平衡因子变成2之后。所以当高度不平衡时，只可能是以下**四种**情况造成的：
	
1. 对该结点的左孩子的左子树进行了一次插入。(LL型)
2. 对该结点的左孩子的右子树进行了一次插入。(LR型)
3. 对该结点的右孩子的左子树进行了一次插入。(RL型)
4. 对该结点的右孩子的右子树进行了一次插入。(RR型)

### 对于情况1和情况4：
对于**LL**和**RR**型，解决方式都是一样的，将**节点**的**左孩子**(**右孩子**)向**右上**(**左上**)旋转,替代原有**节点**,同时将**左孩子**(**右孩子**)的**右子树**(**左子树**)转移到节点的**左子树**(**右子树**)上。

### 对于情况2:
对于**LR**型...语言变得乏力了...我还是盗图先....   
![LR型不平衡转换图](http://img.blog.csdn.net/20130507225406328)   
如图所示，对于**LR型**，需要两次的旋转。
* 首先，将**节点3左旋**，将**节点3**变成**节点4**的**左子树**，
* 然后再将**节点5右旋**，使得**节点4**变成**根节点**。   
> ***注意: 看图的右侧，如果插入的节点C为节点4的右孩子，而此时节点3左旋，节点C并不插入节点3之中***
### 对于情况3:
对于**RL**型,与**LR型**相类似,需要两次的旋转。:   
![LR型不平衡转换图](http://img.blog.csdn.net/20130507225527798)   
* 首先，将**节点5右旋**，将**节点5**变成**节点4**的**右子树**，
* 然后再将**节点3左旋**，使得**节点4**变成**根节点**。   
> ***注意: 看图的右侧，如果插入的节点C为节点4的左孩子，而此时节点5右旋，节点C并不插入节点5之中***
***
## 具体实现
```C
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
//向右旋转
avlTree_node* _rotateAvlTree_R(avlTree_node* p){
    avlTree_node* l_child = p->left;
    p->left = l_child->right;
    l_child->right = p;
    //需要更新节点高度值
    p->nHeight = getMax(getAvlTreeHeight(p->left),
            getAvlTreeHeight(p->right))+1;
    l_child->nHeight = getMax(getAvlTreeHeight(l_child->left),
            getAvlTreeHeight(l_child->right))+1;
    return l_child;
}
//LR型 左旋+右旋
avlTree_node* _rotateAvlTree_LR(avlTree_node* p){
    p->left = _rotateAvlTree_L(p->left);
    return _rotateAvlTree_R(p);
}
//RL型 右旋+左旋
avlTree_node* _rotateAvlTree_RL(avlTree_node* p){
    p->right = _rotateAvlTree_R(p->right);
    return _rotateAvlTree_L(p);
}
```