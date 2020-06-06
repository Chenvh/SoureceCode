#include<iostream>
using namespace std;

/*
    归并排序，递归实现
*/
typedef int ElementType;
//核心算法：
// L 左边起始位置，R右边起始位置，Rightend右边终点位置
void Merge(ElementType *A, ElementType TmpA[], int L, int R, int Rightend)
{
    //将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列
    int LeftEnd, NumElements, Tmp; //起始位置，元素个数，额外数组的下标
    int i;
    
    LeftEnd = R-1; //左边终点位置
    Tmp = L; // 有序序列的起始位置
    NumElements = Rightend - L +1;

    //归并开始，元素个数相同部分归并到临时数组
    while(L <= LeftEnd && R<=Rightend) {
        if(A[L] <= A[R])
            TmpA[Tmp++] = A[L++]; //将左边复制到TmpA
        else 
            TmpA[Tmp++] = A[R++]; //将左边复制到TmpA

    } //元素个数相同部分归并结束

    //相对多余部分复制到临时数组
    while(L <= LeftEnd) 
        TmpA[Tmp++] = A[L++];
    while(R <= Rightend) 
        TmpA[Tmp++] = A[R++];

    //将临时数组复制到原数组
    for(i=0; i<NumElements; i++, Rightend--) {
        //倒叙复制
        A[Rightend] = TmpA[Rightend];
    }
 
} // 核心代码结束

//核心递归排序函数
void Msort(ElementType *A, ElementType TmpA[], int L, int RightEnd) {
    int Center; //中间位置

    if(L < RightEnd) {
        Center = (L+RightEnd) / 2; // 计算中间位置
        Msort(A, TmpA, L, Center); //递归解决左边
        Msort(A, TmpA, Center+1, RightEnd); //递归解决右边
        Merge(A, TmpA, L, Center+1, RightEnd); //合并两段

    }
}

//函数接口
void Merge_sort(ElementType *A, int n) {
    ElementType *TmpA;
    TmpA = (ElementType *) malloc(n*sizeof(ElementType));

    if(TmpA != NULL) {
        Msort(A, TmpA, 0, n-1);
        free(TmpA);
    }
    else cout << "空间不足";
}

//输出函数
void show(int a[], int n) {
    int i;
    cout << "[" ;
    for(i=0; i<n; i++) {
        cout << a[i];
        if(i < n-1)
        cout << " < ";
    }
    cout << "]" << endl;

}

int main(void)
{
    int N=10;
    int nums[N] = {5,6,8,2,7,10,19,98,11,46};
    Merge_sort(nums, N);
    show(nums,N);

    return 0;
}