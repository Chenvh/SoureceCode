#include<iostream>
using namespace std;

/*
    �鲢���򣬵ݹ�ʵ��
*/
typedef int ElementType;
//�����㷨��
// L �����ʼλ�ã�R�ұ���ʼλ�ã�Rightend�ұ��յ�λ��
void Merge(ElementType *A, ElementType TmpA[], int L, int R, int Rightend)
{
    //�������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ����������
    int LeftEnd, NumElements, Tmp; //��ʼλ�ã�Ԫ�ظ���������������±�
    int i;
    
    LeftEnd = R-1; //����յ�λ��
    Tmp = L; // �������е���ʼλ��
    NumElements = Rightend - L +1;

    //�鲢��ʼ��Ԫ�ظ�����ͬ���ֹ鲢����ʱ����
    while(L <= LeftEnd && R<=Rightend) {
        if(A[L] <= A[R])
            TmpA[Tmp++] = A[L++]; //����߸��Ƶ�TmpA
        else 
            TmpA[Tmp++] = A[R++]; //����߸��Ƶ�TmpA

    } //Ԫ�ظ�����ͬ���ֹ鲢����

    //��Զ��ಿ�ָ��Ƶ���ʱ����
    while(L <= LeftEnd) 
        TmpA[Tmp++] = A[L++];
    while(R <= Rightend) 
        TmpA[Tmp++] = A[R++];

    //����ʱ���鸴�Ƶ�ԭ����
    for(i=0; i<NumElements; i++, Rightend--) {
        //������
        A[Rightend] = TmpA[Rightend];
    }
 
} // ���Ĵ������

//���ĵݹ�������
void Msort(ElementType *A, ElementType TmpA[], int L, int RightEnd) {
    int Center; //�м�λ��

    if(L < RightEnd) {
        Center = (L+RightEnd) / 2; // �����м�λ��
        Msort(A, TmpA, L, Center); //�ݹ������
        Msort(A, TmpA, Center+1, RightEnd); //�ݹ����ұ�
        Merge(A, TmpA, L, Center+1, RightEnd); //�ϲ�����

    }
}

//�����ӿ�
void Merge_sort(ElementType *A, int n) {
    ElementType *TmpA;
    TmpA = (ElementType *) malloc(n*sizeof(ElementType));

    if(TmpA != NULL) {
        Msort(A, TmpA, 0, n-1);
        free(TmpA);
    }
    else cout << "�ռ䲻��";
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
    Merge_sort(nums, N);
    show(nums,N);

    return 0;
}