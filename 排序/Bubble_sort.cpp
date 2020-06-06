/*
    √∞≈›≈≈–Ú∑®
*/


#include<iostream>
using namespace std;
// #define N 10

void Swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
} 


//√∞≈›≈≈–Ú£¨–°µΩ¥Û
void Bubble_sort (int *nums,int N) {
    int p;
    int i;
    int flag;
    for(p=N-1; p>=0; p--) {
        flag = 0;

        for(i=0; i<p; i++) {
            if(nums[i]>nums[i+1]) 
            Swap(nums[i],nums[i+1]);
            flag = 1;
        }
        if(flag == 0) break;
    }

}

void show(int *a, int N) {
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
    int num[10] = {5,6,8,2,7,10,19,98,11,46};
    Bubble_sort(num,10);
    show(num,10);

    return 0;
}