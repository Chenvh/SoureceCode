/*

	Name: bubbleSort.cpp
	Copyright: YOUNGMIEN CTGU
	Author: YOUNTMIEN 283538686
	Date: 28/05/19 09:45
	Description: insert type Sort althorithm

*/

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <iostream>
using namespace std;

typedef int Elem;
#define N 100 //顺序表长度 
#define M 20 //顺序表分界 
#define COL 20

#define F_SIZE 2

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define EMPTYDATA -1

//用于快速排序时判断是否选用插入排序阙值
#define MAX_LENGTH_INSERT_SORT 7

typedef int Status;

typedef struct {
	Elem arr[N+1];	//用于存储要排序顺序表，arr[0]用作哨兵或临时变量
	int length;		// 用于记录顺序表的长度 	
	
} SqList;




//函数前置声明
void quickSort(SqList &list);
void quickSort_V2(SqList &list);

/*函数指针
@param pList:SqList *
*/
void (*pFunc_sort[F_SIZE])(SqList &list) = {quickSort,quickSort_V2};
string funcName[F_SIZE] = {"quickSort", "quickSort_V2"};




// 交换list.中数组arr的下标为i和j的值
void swap(SqList &list,int i,int j) {
	Elem temp=list.arr[i];
	list.arr[i]=list.arr[j];
	list.arr[j]=temp;
}



void init(SqList &list){
	for(int i=0; i<list.length; i++){
		list.arr[i] = EMPTYDATA;
	}
}

/*
@param pList:SqList *
@param start:int,顺序表起始位置,[start,length-1]随机 
*/
void inputData(SqList& list , int start) {
	srand(time(NULL));
	
	//向顺序表写入length个数据
	for (int i = start; i <list.length; i++) {
		
			list.arr[i] = rand()%(list.length); //value is [0, length-1]
		
	}
}


/*
[start,length-1]随机 
@param list:顺序表 
@param border:int,顺序表分界,[0, border-1]是倒序,[border,length-1]顺序
@param start:int,顺序表起始位置
*/
void inputData_1(SqList& list , int border, int start) {

	//向list中写入10000个数据 前border逆序 ，之后顺序。
	for (int i = 1; i <list.length; i++) {
		if (i <= border) { //[1, border-1]是逆序
			list.arr[i] = border+1-i; //value is [border,1 ]
		} else { //[border,length-1]顺序
			list.arr[i] = i; //value is [border, length-1]
		}
	}
}



/*输出顺序表
形如:
[27,26,30,15,14,
26,22,21]
@param list,SqList
@param start:int,顺序表起始位置 
*/
void outputData(SqList list, int start) {
	int i;

	printf("[");
	for(i=start; i<list.length; i++) {
		printf("%d",  list.arr[i]);
		if(i != list.length-1) { //不是最后一个元素
			printf(",");
			
		} else { //是最后一个元素
			printf("]");
		}
		if(!((i+1)%COL)){
			printf("\n");
		} 

	}
	printf("\n");
}



/*
对顺序表pList作直接插入排序 ,写操作
@param pList: SqList 引用(指针*)
*/
void insertSort(SqList *pList) {
	int i,j;

	for(i=2; i<=pList->length; i++) {
		if (pList->arr[i] < pList->arr[i-1]) { // 需将pList->arr[i]插入有序子表
			pList->arr[0]=pList->arr[i]; //第i个元素暂存为哨兵,使得下面的循环能结束

			//从i-1开始,从后至前遍历 ,找到不大于该元素的位置
			for(j=i-1; pList->arr[j] > pList->arr[0]; j--) {
				pList->arr[j+1]=pList->arr[j]; // 记录后移
			}//loop end, pList->arr[j] <= pList->arr[0]

			pList->arr[j+1]=pList->arr[0]; // 插入到正确位置,即j+1
		}
	}
}



/* **************************************** */

/* 快速排序******************************** */
 
/* 交换顺序表list中子表的记录，使枢轴记录到位，并返回其所在位置 */
/* 此时在它之前(后)的记录均不大(小)于它。 */
int partition(SqList &list, int low, int high)
{ 
	int pivotkey;

	pivotkey=list.arr[low]; /* 用子表的第一个记录作枢轴记录 */
	while(low<high) /*  从表的两端交替地向中间扫描 */
	{ 
		 while(low<high && list.arr[high]>=pivotkey){
		 	high--;
		 }//Loop End, low == high 或  list.arr[high] < pivotkey
		 swap(list, low, high);/* 将比枢轴记录小的记录交换到低端 */
		 
		 while(low<high && list.arr[low]<=pivotkey){
		 	low++;
		 }	//Loop End, low == high 或  list.arr[low] > pivotkey		
		 swap(list, low, high);/* 将比枢轴记录大的记录交换到高端 */
	}//Loop End, low == high 
	return low; /* 返回枢轴所在位置 */
}

/* 对顺序表list中的子序列list.arr[low..high]作快速排序 */
void fastSort(SqList &list,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=partition(list,low,high); /*  将list.arr[low..high]一分为二，算出枢轴值pivot */
			fastSort(list,low,pivot-1);		/*  对低子表递归排序 */
			fastSort(list,pivot+1,high);		/*  对高子表递归排序 */
	}
}

/* 对顺序表list作快速排序 */
void quickSort(SqList &list)
{ 
	fastSort(list, 1, list.length);
}


/* 改进后快速排序
 快速排序优化算法 
*/

//一次划分 
int partition_V2(SqList &list,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; //获取顺序表中间的元素的下标 
	
	if (list.arr[low]>list.arr[high])	{//交换左端与右端数据，保证左端较小
			swap(list,low,high);
	}	
	if (list.arr[m]>list.arr[high]){//交换中间与右端数据，保证中间较小
		swap(list,high,m);
	}
	
			
	if (list.arr[m]>list.arr[low]){//交换中间与左端数据，保证左端较小
		swap(list,m,low);
	}
			
	
	pivotkey=list.arr[low]; // 用子表的第一个记录作枢轴记录 	
	list.arr[0]=pivotkey;  //将枢轴关键字保存备份到list.arr[0] 
	
	
	//初始时,low端的值已经备份(相当于此处空缺),需要填充一个小于pivotkey的元素 
	//  从表的两端交替地向中间扫描 
	while(low<high) 
	{ 
		//从high端扫描,找出小于pivotkey的元素 
		 while(low<high&&list.arr[high]>=pivotkey){
		 	high--;
		 }//loop end, list.arr[high] < pivotkey,高端处小于轴  或 low > high 
		
		if(low < high){ //list.arr[high] < pivotkey,高端处小于轴  
			list.arr[low] = list.arr[high];
		} 
		
		//再从low端扫描 ,找出大pivotke的元素 
		while(low<high&&list.arr[low]<=pivotkey){
			low++;
		}//loop end, low>high 或  list.arr[low] > pivotkey
		
		if(low < high){ //list.arr[low] > pivotkey,低端处大于轴  
			list.arr[high]=list.arr[low];	
		}	
		
	}//loop end, low>=high 
	list.arr[low]=list.arr[0];
	
	return low;  //返回枢轴所在位置 
}

void fastSort_V2(SqList &list,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=partition_V2(list,low,high); /*  将list.arr[low..high]一分为二，算出枢轴值pivot */
			fastSort_V2(list,low,pivot-1);		/*  对低子表递归排序 */
			/* fastSort(list,pivot+1,high);		/*  对高子表递归排序 */
			low=pivot+1;	/* 尾递归 */
		}
	}
	else{
		insertSort( &list);//使用插入排序 
	}
		
}

/* 对顺序表list作快速排序 */
void quickSort_V2(SqList &list)
{ 
	fastSort_V2(list,1,list.length);
}





int main() {

	SqList list; list.length = N;

	//use windows API
	SYSTEMTIME sysTime[2];

	for(int i=0; i<F_SIZE; i++) {

		inputData(list, 1);
		cout<<"before:"<<endl;
		outputData(list,1); cout << endl ;

		cout << funcName[i]<<", start time is:\n";
		GetLocalTime( &sysTime[0] );

		printf( "\t%02d:%02d:%02d.%03d ", sysTime[0].wHour,sysTime[0].wMinute, sysTime[0].wSecond, sysTime[0].wMilliseconds);
		printf( "\t%4d/%02d/%02d 星期%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);


		pFunc_sort[i](list);

		GetLocalTime( &sysTime[1] );
		cout << funcName[i]<<", end time is:\n";
		printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
		printf( "\t%4d/%02d/%02d 星期%1d\n", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);



		double run_time = sysTime[1].wSecond*1000 + sysTime[1].wMilliseconds -
		                  (sysTime[0].wSecond*1000 + sysTime[0].wMilliseconds) ;

		cout << funcName[i]<<", runned time is :\n\t" << run_time <<  " ms !" << endl << endl;

		cout << "after sort:" <<endl;
		outputData(list,1);
		cout << endl <<"====================================================" << endl;
	}
	cout << endl << endl;

	return 0;
}


/*

#define N 100 //顺序表长度
#define M 20 //顺序表分界

运行结果:

before:
[0,14,11,41,53,29,94,92,2,15,17,7,17,91,89,72,61,93,70,
72,57,93,55,17,47,50,82,61,45,56,64,65,72,48,16,39,29,67,5,
54,33,96,28,27,52,30,15,36,49,63,26,82,68,71,79,12,28,83,97,
78,63,24,61,95,59,75,73,67,25,10,76,76,73,92,5,95,15,17,59,
9,28,40,49,51,78,62,99,39,93,51,17,67,62,99,87,35,24,93,41]


quickSort, start time is:
        08:46:06.098    2019/06/10 星期1
quickSort, end time is:
        08:46:06.098    2019/06/10 星期1
quickSort, runned time is :
        0 ms !

after sort:
[0,1,2,5,5,7,9,10,11,12,14,15,15,15,16,17,17,17,17,
17,24,24,25,26,27,28,28,28,29,29,30,33,35,36,39,39,40,41,41,
45,47,48,49,49,50,51,51,52,53,54,55,56,57,59,59,61,61,61,62,
62,63,63,64,65,67,67,67,68,70,71,72,72,72,73,73,75,76,76,78,
78,79,82,82,83,87,89,91,92,92,93,93,93,93,94,95,95,96,97,99]


====================================================
before:
[0,14,11,41,53,29,94,92,2,15,17,7,17,91,89,72,61,93,70,
72,57,93,55,17,47,50,82,61,45,56,64,65,72,48,16,39,29,67,5,
54,33,96,28,27,52,30,15,36,49,63,26,82,68,71,79,12,28,83,97,
78,63,24,61,95,59,75,73,67,25,10,76,76,73,92,5,95,15,17,59,
9,28,40,49,51,78,62,99,39,93,51,17,67,62,99,87,35,24,93,41]


quickSort_V2, start time is:
        08:46:06.127    2019/06/10 星期1
quickSort_V2, end time is:
        08:46:06.131    2019/06/10 星期1
quickSort_V2, runned time is :
        4 ms !

after sort:
[0,2,5,5,7,9,10,11,12,14,15,15,15,16,17,17,17,17,17,
24,24,25,26,27,28,28,28,29,29,30,33,35,36,39,39,40,41,41,45,
47,48,49,49,50,51,51,52,53,54,55,56,57,59,59,61,61,61,62,62,
63,63,64,65,67,67,67,68,70,71,72,72,72,73,73,75,76,76,78,78,
79,82,82,83,87,89,91,92,92,93,93,93,93,94,95,95,96,97,99,99]


====================================================



--------------------------------
Process exited after 0.6259 seconds with return value 0
请按任意键继续. . .

*/
