#include<iostream>
using namespace std;


//����
void Swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

// ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ����
void PercDown( int A[], int p, int N )
{ /* �ı����4.24��PercDown( MaxHeap H, int p )    */
  /* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
    int Parent, Child;
    int X;
 
    X = A[p]; /* ȡ��������ŵ�ֵ */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľϴ��� */
        if( X >= A[Child] ) break; /* �ҵ��˺���λ�� */
        else  /* ����X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}

//����
void Heap_srot(int *A, int n) {
    int i;
    for(i=n/2-1; i>=0; i--) {
        //��������
        PercDown(A, i, n);
    }

    //ɾ�����Ѷ�
    for(i=n-1; i>0; i--) {
        Swap(A[0], A[i]);
        PercDown(A, 0, i);
    }
}

//�������
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
    Heap_srot(nums, N);
    show(nums,N);
    
    

    return 0;
}