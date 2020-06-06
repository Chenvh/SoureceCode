/*
    快速排序
*/
#include <iostream>
using namespace std;
#define N 10
typedef int  ElementType; 

//交换函数
void Swap(ElementType &a, ElementType &b) {
    ElementType tmp;
    tmp = a;
    a = b;
    b = tmp;
}

//选取主元
ElementType Median3(ElementType A[], int Left, int Right) {
    int Center = (Left + Right) / 2;
    if(A[Left] > A[Right]) 
        Swap(A[Left], A[Right]);
    if(A[Left] > A[Right])
        Swap(A[Left], A[Right]);
    if(A[Center] > A[Right])
        Swap(A[Center], A[Right]);
    
    //将基准Pivot 放到右边
    Swap(A[Center], A[Right-1]); 
    //返回
    return A[Right-1];
}

//插入排序，小到大
void Isersion_sort (int *nums,int n) {
    int p, i;
    int tmp;
    for(p=1; p<n; p++) {
        tmp = nums[p];
        for( i=p; i>0 && nums[i-1]>tmp; i--)
            nums[i] = nums[i-1]; //移除空位

        nums[i] = tmp; //插入
    }
}

//核心算法
void Qsort(ElementType A[], int Left, int Right) {
   
    //Cutoff 是阈值，用来规定多少个数的元素选择快速排序
    int Pivot ,Cutoff, Low, High; 

    if(Cutoff <= Right-Left) {
        Pivot = Median3(A, Left ,Right);
        while(1) {
            while(A[++Low] < Pivot) ;
            while(A[--High] > Pivot) ;
            if(Low <High) Swap(A[Low], A[High]);
            else break;
        }
        
        Swap(A[Low], A[Right-1]); //将基准换到正确位置

        //递归调用
        Qsort(A, Left, Low-1);
        Qsort(A, Low+1, Right);
    }
    else Isersion_sort(A+Left, Right-Left+1);
} 

//函数接口
void Quick_sort(ElementType A[], int n) {
    Qsort(A, 0, n-1);
}

//输出函数
void show(int *a, int n) {
    int i;
    cout << "[" ;
    for(i=0; i<N; i++) {
        cout << a[i];
        if(i < N-1)
        cout << " < ";
    }
    cout << "]" << endl;

}

int main(void )
{
    int num[N] = {5,6,8,2,7,10,19,98,11,46};
    Isersion_sort(num,N);
    show(num,10);

    return 0;
}