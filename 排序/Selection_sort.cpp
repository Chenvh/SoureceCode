#include<iostream>
using namespace std;
typedef int ElementType;

void Swap(ElementType &a, ElementType &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int ScanfForMin(ElementType nums[], int left, int right) {
    int pos;
    int min = nums[left];
    for(int i=left; i<=right; i++) {
        if(min > nums[i]) {
            min = nums[i];
            pos = i;
        }
    }
    return pos;
}

void Selection_sort(ElementType *A, int n) {
    for(int i=0; i<n; i++) {
        int MinPosition = ScanfForMin(A, i, n-1);

        Swap(A[i], A[MinPosition]);
    }
}

//Êä³öº¯Êý
void show(ElementType a[], int n) {
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
    ElementType nums[N] = {5,6,8,2,7,10,19,98,11,46};
    Selection_sort(nums, N);
    show(nums,N);
    
    

    return 0;
}