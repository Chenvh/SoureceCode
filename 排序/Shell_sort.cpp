/*
    ϣ������
*/


#include<iostream>
using namespace std;
#define N 10



//ϣ������С���������˲�������
void Isersion_sort (int *nums,int n) {
    int p, i;
    int d;//����
    int tmp;
    //�����������У��磺n/2
    for(d=n/2; d>0; d/=2) { //ϣ����������

        //��������
        for(p=d; p<n; p++) {
            tmp = nums[p];
            for( i=p; i>=d && nums[i-d]>tmp; i-=d)
                nums[i] = nums[i-d]; //�Ƴ���λ
                
            nums[i] = tmp; //����
        }
        
    }

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