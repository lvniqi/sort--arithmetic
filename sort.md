排序及查找笔记
==============
## 前言

排序的坑其实是在二叉树之前就补得差不多了，但是懒，所以一直没写。现在还差堆排序(堆排序会另外写一篇)。我个人觉得，排序是为之后的其他搜索、插入等等操作节省时间和空间的折中做法，例如，没有排序就无法二分查找。

至于查找....这个...因为平时单片机用惯了，以KB计算的单片机内存根本体现不出算法的优势啊.....而且查找在我编写的程序中确实很难用得到...但是作为基本算法，一并补了吧，反正也就看了简单的二分法。

**名词说明**

***swap:	交换...懒得打代码，直接用函数***
***

## 选择排序
选择排序的逻辑很简单，选一个**最小**的放到第一个，次小的放到第二个，以此类推...    
就如同我们平时整理东西一样，你看桌子上一堆书，怎么放整齐呢？你把最小的放上面，再把次小的放第二层以此类推。
```C
void selectSort(datatype *p,int len){
	int i,j,now;
	for(i=0;i<len;i++){
		now = i;
		for(j=i+1;j<len;j++){
		    if(p[now] >p[j]){
				now = j;
			}
		}
        if(now != i){
            swap(p+i,p+now);
        }
	}
}
```
***

## 冒泡排序
冒泡也很简单，但是日常生活中这个做的确实不多。    
想象下，你整理书本是这个样子的：
* 从一摞书的最后开始看。
* 如果这一本书比上面一本小，把它与上面一本书交换。
* 重复这个动作直至扫完这一摞书。
* 然后再扫一次，这次扫到从上往下第二本书。
* 然后一直循环....直至你不用扫了为止。

对于一个正常的人类来说，这样做还不如选择排序好呢，原因是人将书交换的速度还不如直接扫一眼更快呢。换言之，比较比交换快多了。如果有人这样理书，只能说明这人在..装...X...。    
***关于冒泡排序的名称由来，不用说就知道...
水中的气泡越冒越大，就和这个排序一样，由此得名***
```C
void bubbleSort(datatype* p,int len){
    int i;
    for(i=0;i<len;i++){
        int j;
        for(j=len-1;j>0;j--){
            if(p[j]<p[j-1]){
               swap(p+j,p+j-1);
            }
        }
    }
}

```
### 改进冒泡排序
冒泡排序的最佳时间复杂度怎么算都是**O(N^2)**，但网上和许多书上都写道是**O(n)**。于是google下，找到了答案：
```C
void bubbleSort(datatype* p,int len) {
    bool didSwap;
    for(int i = 0; i < len - 1; i++) {
        didSwap = false;
        for(int j = 0; j < len - i - 1; j++) {
            if(p[j + 1] < arr[j]) {
                swap(p+j,p+ j + 1);
                didSwap = true;
            }
        }
        if(didSwap == false)
            return;
    }    
}
```
这个改进算法中，使用**didSwap**确保如果一次扫过所有的对象都排序正确时，及时退出，使得最佳情况时时间复杂度为**O(n)**。

***

## 插入排序
插入排序是指，将一个值插入一个有序数组，获得一个新的有序数组的排序方式。
```C
void insertSort(datatype* p,int len){
    int i;
    for(i=1;i<len;i++){
        int j;
        int temp = p[i];
        for(j=i-1;j>=0;j--){
            if(temp<p[j]){
                p[j+1]=p[j];
            } 
            else{
                break;
            }
            p[j] = temp;
        }
    }
}
```
***
## 希尔排序
希尔排序可以看作是插入排序的优化版，用于减少插入排序造成的大量数据交换。通过将数据**间隔某个增量划分为组**，同时将间隔减少，直至最后减少至0，完成排序。
```C
void shellSort(datatype *p,int len){
    int now,gap;
    //增量定义方式
    for(gap = len/2;gap>0;gap/=2){
        //插入排序
        for(now=gap;now<len;now+=gap){
            int last = now-gap;
            //需要插入
            if(p[now] <p[last]){
                int temp = p[now];
                while(last >=0 && p[last] >temp){
                    p[last+gap] = p[last];
                    last -= gap;
                }
                p[last+gap] = temp;
            }
        }
    }
}
```

## 快速排序
快速排序可以称为最快的排序算法。平均狀況时间复杂度**Ο(n log n)**，最坏情况**Ο(n^2)**,最好情况**Ο(n)**。因为最坏情况出现几率很少，所以几乎可以忽略不计。     
### 快速排序的思路
根据[morewindows](http://www.cnblogs.com/morewindows/archive/2011/08/13/2137415.html)的介绍，将快速排序归纳为**挖坑填数**+**分治法**。
#### 分治法   
* 情况1：排序数量只有2个，则排序就是将大的数放到小的数之后。
* 情况2：添加排序数量，例如10个，我们总可以将其分为2个序列，一个比另一个都小，然后再将这个分割。最后回到情况1。

#### 挖坑填数
* 使用左右两个指针，一个挖坑一个填。(具体要盗图，还是去看[原文](http://www.cnblogs.com/morewindows/archive/2011/08/13/2137415.html)的。
```C
void _quickSort(datatype* p,int start,int end){
    int i=start,j=end;
    if(i>=j){
        return;
    }
    datatype key = p[start];
    while(i<j){
        while(i<j&&p[j]>=key){
            j--;
        }
        p[i] = p[j];
        while(i<j&&p[i]<=key){
            i++;
        }
        p[j] = p[i];
    }
    p[i] = key;
    //printData(p,DATA_LEN);
    //printf("i:%d,j:%d\n",i,j);
    _quickSort(p,start,i-1);
    _quickSort(p,j+1,end);
    return;
}
```
***
## 归并排序
归并排序属于**分治法(Divide and Conquer)** 的典型应用之一。   
简要思想为：
* 将数组中的数二分为两组。
* 然后再二分....一直到只剩两个数，此时，排序的操作变得异常简单，选择即可。
* 返回，现在你得到了一堆已经排序的含有两个数的数组。
* 然后将其合并，合并时，选择两个数列中的最小值，将其复制到临时空间。删除序列中的这个值再重复此操作。
* 这样，交换空间中的4个数就是排完序的4个数，将其复制回数组，2个数组的归并完成。
* 重复此操作，直至归并完成。

从其简要思想来看，递归是一个节省脑力的小技巧。如下是总体程序。因为需要temp空间，所以可以想见，其空间复杂度一定不低。
```C
void _mergeSort(int sourceArr[],int tempArr[],int startIndex,int endIndex)
{
    int midIndex;
    if(startIndex<endIndex)
    {
        midIndex=(startIndex+endIndex)/2;
        _mergeSort(sourceArr,tempArr,startIndex,midIndex);
        _mergeSort(sourceArr,tempArr,midIndex+1,endIndex);
        _Merge(sourceArr,tempArr,startIndex,midIndex,endIndex);
    }
}
```
其中，_Merge是真正进行排序操作的函数。其思想即是**选择两个数列中的最小值**，**复制到临时空间**,**删除序列中的这个值**再重复此操作。最后从临时空间中将数据复制回来。
```C
void _Merge(int sourceArr[],int tempArr[],int startIndex,int midIndex,int endIndex)
{
    int i = startIndex,j=midIndex+1,k = startIndex;
    while(i<=midIndex && j<=endIndex)
    {
        if(sourceArr[i]<sourceArr[j])
            tempArr[k++] = sourceArr[i++];
        else
            tempArr[k++] = sourceArr[j++];
    }
    while(i<=midIndex)
        tempArr[k++] = sourceArr[i++];
    while(j<=endIndex)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex;i<=endIndex;i++)
        sourceArr[i] = tempArr[i];
} 
```
***
## 二分查找
