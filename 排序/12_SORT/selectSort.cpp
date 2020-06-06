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
#define N 10000 //数组长度 
#define M 2000 //数组分界 
#define COL 100


void selectSort_v1 (Elem arr[] , int length);
void selectSort_v2 (Elem arr[] , int length);

/*函数指针
@param arr:int[],数组起始地址
@param length:int,数组长度

*/
//int (*bubble_sort)(Elem arr[] , int length);
void (*select_sort[])(Elem arr[] , int length) = {selectSort_v1,selectSort_v2};



/*
选择法排序:根据下标(位置)选择元素.确定length-1个位置的元素即可
$1 二重循环
 	外循环:标识数组元素下标(位置 )
 	for(i=0; i<length-1; i++){//确定length-1个位置
 		//找最小元素的下标 (位置) 
		for(;;){
			
		}
	}
	for(i=length-1; i>1; i--){//确定length-1个位置
		//找最大元素的下标(位置) 
		for(;;){
			
		}
	}
 	
外循环体:
$1 获取数组boss的下标
$2 交换 


@param int arr[]:数组名a,数据类型为int[] ,代表首地址 
@param int length:数组长度 
*/
void selectSort_v1(Elem arr[], int length){
	int i,j,k;
	Elem t;
	
	for(i=0; i<length-1; i++){//确定length-1个位置
		//打擂台
		//step1:找老大
		k=i;//boss的下标
		 
		//step2:将剩余的元素依次与老大PK
		for(j=i+1; j<length; j++){
			if(arr[j] < arr[k]){
				//update
				k = j;
			}
		}//loop ending,k的值即为boss的下标
		
		//step3:swap
		if(k != i){
			t = arr[i];arr[i]= arr[k];arr[k]=t;
		} //if end,swap over
	}//loop end,sort over
	

}


/*
最大最小值同时找出来放到相应的位置
@param int arr[]:数组名arr,数据类型为int[] ,代表首地址 
@param int length:数组长度 
*/
void selectSort_v2(Elem arr[], int len)
{
	//最小元素的下标,最大元素下标,最左位置,最右位置 
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
		}//loop end, s_id存放的是最小元素下标,l_id存放的是最大元素下标 
		
		//值交换swap,将最小位置的元素与left下标位置元素交换 
		if (s_id != left)
		{
			temp = arr[left];
			arr[left] = arr[s_id];
			arr[s_id] = temp;
			
			//attation，因为此时下标不变，仅仅值交换
			//如果最大值在最左边,经过上面的交换,将其换至了s_id处 
			//此时最大值的下标变成了s_id			
			if (l_id == left) //left原来存放的是最大元素 
			{
				l_id = s_id;
			}
			
		}//if end,最小元素交换至left
		 
		//值交换swap,将l_id(最大位置的元素)与right下标位置元素交换 
		if (l_id != right)
		{
			temp = arr[right];
			arr[right] = arr[l_id];
			arr[l_id] = temp;
		}//if end,最大元素交换至right
		
	}//loop end,sort over 

}




//数组输入输出
/*输入数组 
@param int arr[]:数组名arr,数据类型为int[] ,代表首地址 
@param int length:数组长度 
*/ 
void inputArray(Elem arr[], int length){
	int i; 
	//printf("arr = %d\n", arr);//数组名的值即为起始地址 
	srand(time(NULL));
	//printf("%d\n", time(NULL));
	
	//遍历traverse 
	for(i=0; i<length; i++){
		//scanf("%d", &arr[i]);
		//rand函数返回一个在零到RAND_MAX 之间的伪随机整数
		arr[i] = rand()%21 + 13; //产生13~33的数 
	}
	
	/*scanf("%d", &arr[0]);	scanf("%d", &arr[1]);
	scanf("%d", &arr[2]);	...	scanf("%d", &arr[length-1]);*/
}



/*
@param arr:int[],数组起始地址
@param length:int,数组长度
@param border:int,数组分界,[0, border-1]是倒序,[border,length-1]顺序
*/
void inputArr(Elem arr[], int length, int border) {

	//向数组写入10000个数据 前2018倒序 ，之后顺序。
	for (int i = 0; i < length; i++) {
		if (i<border) { //[0, border-1]是倒序
			arr[i] = border-1 -i; //value is [border-1,0]
		} else { //[border,length-1]顺序
			arr[i] = i; //value is [border, length-1]
		}
	}
}



/*输出数组 
形如: 
[27,26,30,15,14,
26,22,21]
@param int arr[]:数组名arr,数据类型为int[] ,代表首地址 
@param int length:数组长度 
*/ 
void outputArray(int arr[], int length){
	int i;
	
	printf("[");
	for(i=0; i<length; i++){
		printf("%d",  arr[i]);
		if(i != length-1){//不是最后一个元素 
			printf(",");
			//每行打印COL个 
			if((i+1)%COL == 0){
				printf("\n");
			}
		}else{//是最后一个元素
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
		printf( "\t%4d/%02d/%02d 星期%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);


		select_sort[i](arr, N);

		GetLocalTime( &sysTime[1] );
		cout << "selectSort_v"<<i+1<<", end time is:\n";
		printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
		printf( "\t%4d/%02d/%02d 星期%1d\n", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);



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
        19:45:26.676    2019/05/28 星期2
selectSort_v1, end time is:
        19:45:26.795    2019/05/28 星期2
selectSort_v1, runned time is :
        119 ms !

selectSort_v2, start time is:
        19:45:26.797    2019/05/28 星期2
selectSort_v2, end time is:
        19:45:26.864    2019/05/28 星期2
selectSort_v2, runned time is :
        67 ms !


--------------------------------
Process exited after 0.2088 seconds with return value 0
请按任意键继续. . .

*/
