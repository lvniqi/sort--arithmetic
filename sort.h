#ifndef SORT_H_
    #define SOET_H_
    typedef int qS_data;
    extern void printData(qS_data* p,int len);
    extern void bubbleSort(qS_data* p,int len); 
    extern void insertSort(qS_data* p,int len);
    extern void _quickSort(qS_data* p,int start,int end);
    #define quickSort(a,b)  _quickSort((a),0,(b)-1)
    extern void _mergeSort(int sourceArr[],int tempArr[],
            int startIndex,int endIndex);
    #define mergeSort(a,b,c) _mergeSort((a),(b),0,(c)-1) 
#endif
