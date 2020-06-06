/*
    插入排序法
*/


#include<iostream>
using namespace std;
#define N 10


//插入排序，小到大
void Isersion_sort (int nums[],int n) {
    int p, i;
    int tmp;
    for(p=1; p<n; p++) {
        tmp = nums[p];
        for( i=p; i>0 && nums[i-1]>tmp; i--)
            nums[i] = nums[i-1]; //移除空位

        nums[i] = tmp; //插入
    }

}

//输出函数
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