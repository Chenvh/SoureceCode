/*
    ��������
*/


#include<iostream>
using namespace std;
#define N 10


//��������С����
void Isersion_sort (int nums[],int n) {
    int p, i;
    int tmp;
    for(p=1; p<n; p++) {
        tmp = nums[p];
        for( i=p; i>0 && nums[i-1]>tmp; i--)
            nums[i] = nums[i-1]; //�Ƴ���λ

        nums[i] = tmp; //����
    }

}

//�������
void show(int a[], int n) {
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