/*
    ��������
*/
#include <iostream>
using namespace std;
#define N 10
typedef int  ElementType; 

//��������
void Swap(ElementType &a, ElementType &b) {
    ElementType tmp;
    tmp = a;
    a = b;
    b = tmp;
}

//ѡȡ��Ԫ
ElementType Median3(ElementType A[], int Left, int Right) {
    int Center = (Left + Right) / 2;
    if(A[Left] > A[Right]) 
        Swap(A[Left], A[Right]);
    if(A[Left] > A[Right])
        Swap(A[Left], A[Right]);
    if(A[Center] > A[Right])
        Swap(A[Center], A[Right]);
    
    //����׼Pivot �ŵ��ұ�
    Swap(A[Center], A[Right-1]); 
    //����
    return A[Right-1];
}

//��������С����
void Isersion_sort (int *nums,int n) {
    int p, i;
    int tmp;
    for(p=1; p<n; p++) {
        tmp = nums[p];
        for( i=p; i>0 && nums[i-1]>tmp; i--)
            nums[i] = nums[i-1]; //�Ƴ���λ

        nums[i] = tmp; //����
    }
}

//�����㷨
void Qsort(ElementType A[], int Left, int Right) {
   
    //Cutoff ����ֵ�������涨���ٸ�����Ԫ��ѡ���������
    int Pivot ,Cutoff, Low, High; 

    if(Cutoff <= Right-Left) {
        Pivot = Median3(A, Left ,Right);
        while(1) {
            while(A[++Low] < Pivot) ;
            while(A[--High] > Pivot) ;
            if(Low <High) Swap(A[Low], A[High]);
            else break;
        }
        
        Swap(A[Low], A[Right-1]); //����׼������ȷλ��

        //�ݹ����
        Qsort(A, Left, Low-1);
        Qsort(A, Low+1, Right);
    }
    else Isersion_sort(A+Left, Right-Left+1);
} 

//�����ӿ�
void Quick_sort(ElementType A[], int n) {
    Qsort(A, 0, n-1);
}

//�������
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