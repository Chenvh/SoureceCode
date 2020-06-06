/*

	Name: bubbleSort.cpp
	Copyright: YOUNGMIEN CTGU
	Author: YOUNTMIEN 283538686
	Date: 28/05/19 09:45
	Description: Bubble Sort althorithm

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <iostream>
using namespace std;

typedef int Elem;
#define N 10000 //���鳤�� 
#define M 2000 //����ֽ� 
#define COL 100


void selectSort_v1 (Elem arr[] , int length);
void selectSort_v2 (Elem arr[] , int length);

/*����ָ��
@param arr:int[],������ʼ��ַ
@param length:int,���鳤��

*/
//int (*bubble_sort)(Elem arr[] , int length);
void (*select_sort[])(Elem arr[] , int length) = {selectSort_v1,selectSort_v2};



/*
ѡ������:�����±�(λ��)ѡ��Ԫ��.ȷ��length-1��λ�õ�Ԫ�ؼ���
$1 ����ѭ��
 	��ѭ��:��ʶ����Ԫ���±�(λ�� )
 	for(i=0; i<length-1; i++){//ȷ��length-1��λ��
 		//����СԪ�ص��±� (λ��) 
		for(;;){
			
		}
	}
	for(i=length-1; i>1; i--){//ȷ��length-1��λ��
		//�����Ԫ�ص��±�(λ��) 
		for(;;){
			
		}
	}
 	
��ѭ����:
$1 ��ȡ����boss���±�
$2 ���� 


@param int arr[]:������a,��������Ϊint[] ,�����׵�ַ 
@param int length:���鳤�� 
*/
void selectSort_v1(Elem arr[], int length){
	int i,j,k;
	Elem t;
	
	for(i=0; i<length-1; i++){//ȷ��length-1��λ��
		//����̨
		//step1:���ϴ�
		k=i;//boss���±�
		 
		//step2:��ʣ���Ԫ���������ϴ�PK
		for(j=i+1; j<length; j++){
			if(arr[j] < arr[k]){
				//update
				k = j;
			}
		}//loop ending,k��ֵ��Ϊboss���±�
		
		//step3:swap
		if(k != i){
			t = arr[i];arr[i]= arr[k];arr[k]=t;
		} //if end,swap over
	}//loop end,sort over
	

}


/*
�����Сֵͬʱ�ҳ����ŵ���Ӧ��λ��
@param int arr[]:������arr,��������Ϊint[] ,�����׵�ַ 
@param int length:���鳤�� 
*/
void selectSort_v2(Elem arr[], int len)
{
	//��СԪ�ص��±�,���Ԫ���±�,����λ��,����λ�� 
	int s_id,  l_id, left, right;
	int i;Elem temp;
	for (left = 0, right = len - 1; left < right; left++, right--)
	{
		s_id = left;
		l_id = right;
		for (i = left; i <=right; i++)
		{
			if (arr[i] < arr[s_id])
			{
				s_id = i;
			}
			else if (arr[i]>arr[l_id])
			{
				l_id = i;
			}
		}//loop end, s_id��ŵ�����СԪ���±�,l_id��ŵ������Ԫ���±� 
		
		//ֵ����swap,����Сλ�õ�Ԫ����left�±�λ��Ԫ�ؽ��� 
		if (s_id != left)
		{
			temp = arr[left];
			arr[left] = arr[s_id];
			arr[s_id] = temp;
			
			//attation����Ϊ��ʱ�±겻�䣬����ֵ����
			//������ֵ�������,��������Ľ���,���任����s_id�� 
			//��ʱ���ֵ���±�����s_id			
			if (l_id == left) //leftԭ����ŵ������Ԫ�� 
			{
				l_id = s_id;
			}
			
		}//if end,��СԪ�ؽ�����left
		 
		//ֵ����swap,��l_id(���λ�õ�Ԫ��)��right�±�λ��Ԫ�ؽ��� 
		if (l_id != right)
		{
			temp = arr[right];
			arr[right] = arr[l_id];
			arr[l_id] = temp;
		}//if end,���Ԫ�ؽ�����right
		
	}//loop end,sort over 

}




//�����������
/*�������� 
@param int arr[]:������arr,��������Ϊint[] ,�����׵�ַ 
@param int length:���鳤�� 
*/ 
void inputArray(Elem arr[], int length){
	int i; 
	//printf("arr = %d\n", arr);//��������ֵ��Ϊ��ʼ��ַ 
	srand(time(NULL));
	//printf("%d\n", time(NULL));
	
	//����traverse 
	for(i=0; i<length; i++){
		//scanf("%d", &arr[i]);
		//rand��������һ�����㵽RAND_MAX ֮���α�������
		arr[i] = rand()%21 + 13; //����13~33���� 
	}
	
	/*scanf("%d", &arr[0]);	scanf("%d", &arr[1]);
	scanf("%d", &arr[2]);	...	scanf("%d", &arr[length-1]);*/
}



/*
@param arr:int[],������ʼ��ַ
@param length:int,���鳤��
@param border:int,����ֽ�,[0, border-1]�ǵ���,[border,length-1]˳��
*/
void inputArr(Elem arr[], int length, int border) {

	//������д��10000������ ǰ2018���� ��֮��˳��
	for (int i = 0; i < length; i++) {
		if (i<border) { //[0, border-1]�ǵ���
			arr[i] = border-1 -i; //value is [border-1,0]
		} else { //[border,length-1]˳��
			arr[i] = i; //value is [border, length-1]
		}
	}
}



/*������� 
����: 
[27,26,30,15,14,
26,22,21]
@param int arr[]:������arr,��������Ϊint[] ,�����׵�ַ 
@param int length:���鳤�� 
*/ 
void outputArray(int arr[], int length){
	int i;
	
	printf("[");
	for(i=0; i<length; i++){
		printf("%d",  arr[i]);
		if(i != length-1){//�������һ��Ԫ�� 
			printf(",");
			//ÿ�д�ӡCOL�� 
			if((i+1)%COL == 0){
				printf("\n");
			}
		}else{//�����һ��Ԫ��
			printf("]"); 
		}	
		
	}	
	printf("\n");
}

int main(){
	int arr[N];
	inputArr(arr,N,M);
	
	//use windows API
	SYSTEMTIME sysTime[2];

	for(int i=0; i<2; i++) {

		cout << "selectSort_v"<<i+1<<", start time is:\n";
		GetLocalTime( &sysTime[0] );

		printf( "\t%02d:%02d:%02d.%03d ", sysTime[0].wHour,sysTime[0].wMinute, sysTime[0].wSecond, sysTime[0].wMilliseconds);
		printf( "\t%4d/%02d/%02d ����%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);


		select_sort[i](arr, N);

		GetLocalTime( &sysTime[1] );
		cout << "selectSort_v"<<i+1<<", end time is:\n";
		printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
		printf( "\t%4d/%02d/%02d ����%1d\n", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);



		double run_time = sysTime[1].wSecond*1000 + sysTime[1].wMilliseconds -
		                  (sysTime[0].wSecond*1000 + sysTime[0].wMilliseconds) ;

		cout << "selectSort_v"<<i+1<<", runned time is :\n\t" << run_time <<  " ms !" << endl << endl;


	}

	
	
	
	
	
	
/*	outputArray(arr,N);


	selectSort_v2(arr, N);
	
	outputArray(arr,N);
	*/
	return 0;
}


/*
selectSort_v1, start time is:
        19:45:26.676    2019/05/28 ����2
selectSort_v1, end time is:
        19:45:26.795    2019/05/28 ����2
selectSort_v1, runned time is :
        119 ms !

selectSort_v2, start time is:
        19:45:26.797    2019/05/28 ����2
selectSort_v2, end time is:
        19:45:26.864    2019/05/28 ����2
selectSort_v2, runned time is :
        67 ms !


--------------------------------
Process exited after 0.2088 seconds with return value 0
�밴���������. . .

*/
