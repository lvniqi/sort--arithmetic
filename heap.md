堆及堆排序
====
## 前言

堆是用数组实现二叉树的一种存储结构(额自己胡编乱造的)。想来用堆来实现二叉树(额，应该是二叉堆)用在单片机上总比一直malloc要强....so，索性补完吧。

**名词说明**   

***完全二叉树：除最后一层外，每一层上的节点数均达到最大值；在最后一层上只缺少右边的若干结点的二叉树。***

---
## 二叉堆的定义
* 二叉堆是**完全二叉树**或者是**近似完全二叉树**。
* 二叉堆**父结点**的键值总是**大于或等于**（小于或等于）**任何**一个**子节点**的键值。
* 二叉堆每个结点的**左子树**和**右子树**都是一个二叉堆（都是最大堆或最小堆）。

---

## 堆的存储
一般都用数组来表示堆，i结点的父结点下标就为(i – 1) / 2。它的左右子结点下标分别为2 * i + 1和2 * i + 2。如第0个结点左右子结点下标分别为1和2。    
下图为盗图....    
![](http://hi.csdn.net/attachment/201108/22/0_1314014706gZqn.gif)

## 插入
插入堆时，先将数据放置在堆的末尾，然后**向上**对堆进行**恢复**操作。
其操作如同**插入排序**中将数据插入有序队列相同。
```C
void insertMinHeap(int a[],int pos,int value){
    a[pos] = value;
    fixMinHeap_up(a,pos);
}
```
其中的fixMinHeap_up为从下往上恢复堆的程序：
```C
void fixMinHeap_up(int a[],int child){
    int parent,temp;
    temp = a[child];
    parent = (child-1)/2;
    while (parent >= 0 && child >0){
        //如 果子节点的值大于父节点
        //则跳出
        if(a[parent] <= temp){
            break;
        }
        a[child] = a[parent];
        child = parent;
        parent = (child-1)/2;
    }
    a[child] = temp;
}
```

## 删除
因为堆的每个节点都可视为一个堆，所以理所应当，当删除时，删除第一个节点所做的操作远小于从一个无序数组恢复有序堆来的开销要小。    
所以，按定义，堆中每次都只能删除第0个数据。为了便于重建堆，实际的操作是将最后一个数据的值赋给根结点，然后再从根结点开始进行一次从上向下的调整。
```C
//删除头节点a[0]
void deleteMinHeap(int a[],int len){
   intSwap(a,a+len-1);
   fixMinHeap_down(a,0,len-1);
}
```
其中的fixMinHeap_down为从上往下恢复堆的程序：
```C
void fixMinHeap_down(int a[],int start,int end){
    //找到最小的到a[0]
    int temp = a[start];
    int child = 2*start+1;
    while(child < end){
        //在左右孩子中找最小的
        if(child +1 <end && a[child+1] < a[child]){
            child++;//子节点+1
        }
        //如果子节点比父节点大，就为正常，不必交换
        if(a[child] > temp){
            break;
        }
        a[start] = a[child];//将子节点上移
        start = child;
        child = 2*start + 1;
    }
    a[start] = temp;
}
```
## 堆化数组
如何对一个数据进行堆化操作？其实我们并不需要一个一个的从数组中取出数据来建立堆。因为子节点本来就是满足堆的条件，所以只要恢复有子节点的堆就行了。
```C
//堆化数组
//子节点不用整理，父节点整理
void makeMinHeap(int a[],int len){
   int i;
   for(i=len/2-1;i>=0;i--){
    fixMinHeap_down(a,i,len);
    }
}
```
## 堆排序
由堆的性质可知，第1个数据是整个堆中最小的数，所以将其取出，然后循环此操作，就可取出从小到大的数，达成排序的操作。    
实际操作中，第一次将A[0]与A[n - 1]交换，然后对A[0…n-2]重新恢复堆。然后依次重复，直至A[0]与A[1]交换。如此便可得到从大到小的有序数组。
```C
void sortByMinHeap(int a[],int len){
    int i;
    for(i=len-1;i>=1;i--){
        intSwap(a,a+i);
        fixMinHeap_down(a,0,i-1);
    }
}
```