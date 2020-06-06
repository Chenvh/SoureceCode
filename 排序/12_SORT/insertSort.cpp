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
#define N 10 //数组长度 
#define M 2 //数组分界 
#define COL 20

#define F_SIZE 4

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define EMPTYDATA -1

//用于快速排序时判断是否选用插入排序阙值
#define MAX_LENGTH_INSERT_SORT 7

typedef int Status;

typedef struct {
	Elem arr[N+1];	//用于存储要排序数组，arr[0]用作哨兵或临时变量
	int length;		// 用于记录顺序表的长度 	
	
} SqList;

// 交换L中数组r的下标为i和j的值
void swap(SqList *L,int i,int j) {
	int temp=L->arr[i];
	L->arr[i]=L->arr[j];
	L->arr[j]=temp;
}

void print(SqList L) {
	int i;
	for(i=1; i<L.length; i++)
		printf("%d,",L.arr[i]);
	printf("%d",L.arr[i]);
	printf("\n");
}

void init(SqList &list){
	for(int i=0; i<list.length; i++){
		list.arr[i] = EMPTYDATA;
	}
}

/*
@param pList:SqList *
@param border:int,数组分界,[0, border-1]是倒序,[border,length-1]顺序
*/
void inputData(SqList& list , int border) {
	srand(time(NULL));
	
	//向数组写入length个数据
	for (int i = 0; i <list.length; i++) {
		
			list.arr[i] = rand()% 100;//list.length; //value is [0, length-1]
		
	}
}


/*
@param list:顺序表 
@param border:int,数组分界,[0, border-1]是倒序,[border,length-1]顺序
*/
void inputData_1(SqList& list , int border) {

	//向数组写入10000个数据 前border逆序 ，之后顺序。
	for (int i = 1; i <list.length; i++) {
		if (i <= border) { //[1, border-1]是逆序
			list.arr[i] = border+1-i; //value is [border,1 ]
		} else { //[border,length-1]顺序
			list.arr[i] = i; //value is [border, length-1]
		}
	}
}



/*输出数组
形如:
[27,26,30,15,14,
26,22,21]
@param list,SqList
*/
void outputData(SqList list) {
	int i;

	printf("[");
	for(i=0; i<list.length; i++) {
		printf("%d",  list.arr[i]);
		if(i != list.length-1) { //不是最后一个元素
			printf(",");
			
		} else { //是最后一个元素
			printf("]");
		}

	}
	printf("\n");
}

//函数前置声明
void insertSort(SqList *pList);
void shellSort(SqList *pList);
void binaInsertSort(SqList *pList);
void path2InsertSort(SqList *pList);

/*函数指针
@param pList:SqList *
*/
void (*pFunc_sort[F_SIZE])(SqList* pList) = {insertSort, shellSort, binaInsertSort, path2InsertSort};
string funcName[F_SIZE] = {"insertSort", "shellSort", "binaInsertSort", "path2InsertSort"};

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

/* 希尔排序
@param pList :SqList顺序表
*/
void shellSort(SqList *pList) {
	int i,j,k=0;
	int increment=pList->length;
	do {
		increment=increment/3 + 1;/* 自设定增量序列 */
		for(i=increment+1; i<=pList->length; i++) {
			if (pList->arr[i]<pList->arr[i-increment]) { /*  需将pList->arr[i]插入有序增量子表 */
				pList->arr[0]=pList->arr[i]; /*  暂存在pList->arr[0] */
				for(j=i-increment; j>0 && pList->arr[0]<pList->arr[j]; j-=increment)
					pList->arr[j+increment]=pList->arr[j]; /*  记录后移，查找插入位置 */
				pList->arr[j+increment]=pList->arr[0]; /*  插入 */
			}
		}
		//printf("	第%d趟排序结果: ", ++k );
		//print(*pList);
	} while(increment>1);

}

/*二分查找插入排序 "对顺序表L作折半插入排序
*/
void  binaInsertSort (SqList* pList) {
	int i, j, low , high, m;
	//
	for  (i=2; i<=pList->length; i++)    {
		pList->arr[0] = pList->arr[i];             //将pList.arr[i]暂存到pList.arr[0]
		low = 1;
		high = i-1;
		while  (low <= high)      {     //在arr[low, high]中折半查找	有序插入的位置

			m = (low + high)/2;
			if (pList->arr[0] < pList->arr[m]) {//如果pList.arr[0].key<pList.arr[m].key，
				high = m-1; //则插入点在低半区
			} else { //否则插入点在高半区
				low = m + 1;
			}
		}//while end,low > high, pList->arr[0] > pList->arr[high] && pList->arr[0] < pList->arr[low]  
		
		for(j=i-1; j>=high+1; --j) {
			pList->arr[j+1] = pList->arr[j];   //记录后移
		}
		pList->arr[high+1] = pList->arr[0];    //插入位置high+1或low
	}//for
}// binaInsertSort


//=== path2InsertSort 2路插入
void path2InsertSort(SqList *pList)  {  // 2-路插入排序

	int length=pList->length;
	//cout << length << endl;
	 
	
	SqList  tmpList;//tmpList为辅助空间	
	tmpList.length = length;
	init(tmpList);

	tmpList.arr[0] = pList->arr[0];   //tmpList.arr中的第一个记录为pList.arr中排好序的记录
	outputData(tmpList);
	
	int first = 0,last = 0; //first用来指示tmpList.arr中排好序的最小元素，
	//last指示最大元素 ; 注：此例没有用arr[0]做岗哨

	for (int i = 1; i < length; i++)     {
		cout << "insert " << pList->arr[i] << "  ";
		if (pList->arr[i] < tmpList.arr[first]) {  //比最小的元素小，插入到最前
			cout << " < "<<"(K(first)="<<first<<":V="<<tmpList.arr[first] << ")--> ";
			//update 
			first = (first - 1 + length) % length;  //update index 
			tmpList.arr[first] = pList->arr[i]; //update value
			
			outputData(tmpList);
		} 
		else if (pList->arr[i] >tmpList.arr[last])   { //待插入元素比最大元素大，插入到最后
			cout << " > "<<"(K(last)="<<last<<":V="<<tmpList.arr[last] << ")--> ";
			
			//update
			last=(last+1+length)%length; //update index			
			tmpList.arr[last] =pList->arr[i];//update value
			outputData(tmpList);
		} 
		else //待插入元素比最小的大、比最大的小	,插入至last的左侧,last需要update		
		{
			cout << " between "<<"[K(first)="<<first<<":V="<<tmpList.arr[first]<< ", AND ";
			cout <<  "K(last)="<<last<<":V="<< tmpList.arr[last] << "]--> ";
			
			int k;			 
			//通过遍历以排序的元素查找出插入的位置
			for(k = last; pList->arr[i] < tmpList.arr[k]; k=(k-1+length)%length ){
				tmpList.arr[(k+1+length) %length]  = tmpList.arr[k]; //后移 
			} //loop end,k+1为要插入的位置 
			
			tmpList.arr[(k+1+length)%length]  = pList->arr[i];//插入 
			
			//attention: update last
			last = (last+1+length)%length;
			
			outputData(tmpList);
		}
	}
	//将排序后的记录tmpList复制到原来的顺序表 pList
	for(int k=0; k<length; k++)    {
		pList->arr[k]  = tmpList.arr[(first+length+k) % length];
	}
}//---path2InsertSort 2路插入 END






int main() {

	SqList list; list.length = N;

	//use windows API
	SYSTEMTIME sysTime[2];

	for(int i=0; i<F_SIZE; i++) {

		inputData(list, M);
		cout<<"before:"<<endl;
		outputData(list);cout << endl ;

		cout << funcName[i]<<", start time is:\n";
		GetLocalTime( &sysTime[0] );

		printf( "\t%02d:%02d:%02d.%03d ", sysTime[0].wHour,sysTime[0].wMinute, sysTime[0].wSecond, sysTime[0].wMilliseconds);
		printf( "\t%4d/%02d/%02d 星期%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);


		pFunc_sort[i](&list);

		GetLocalTime( &sysTime[1] );
		cout << funcName[i]<<", end time is:\n";
		printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
		printf( "\t%4d/%02d/%02d 星期%1d\n", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);



		double run_time = sysTime[1].wSecond*1000 + sysTime[1].wMilliseconds -
		                  (sysTime[0].wSecond*1000 + sysTime[0].wMilliseconds) ;

		cout << funcName[i]<<", runned time is :\n\t" << run_time <<  " ms !" << endl << endl;

		cout << "after sort:" <<endl;
		outputData(list);
		cout << endl <<"====================================================" << endl;
	}
	cout << endl << endl;

	return 0;
}


/*

#define N 100 //数组长度
#define M 20 //数组分界

运行结果:
before:
[20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,
61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,
81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100]

insertSort, start time is:
        04:29:08.720    2002/01/01 星期2
insertSort, end time is:
        04:29:08.720    2002/01/01 星期2
insertSort, runned time is :
        0 ms !

after sort:
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,
61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,
81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100]

====================================================
before:
[20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,
61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,
81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100]

shellSort, start time is:
        04:29:08.767    2002/01/01 星期2
shellSort, end time is:
        04:29:08.767    2002/01/01 星期2
shellSort, runned time is :
        0 ms !

after sort:
[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,
61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,
81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100]

====================================================



--------------------------------
Process exited after 0.1351 seconds with return value 0
请按任意键继续-> -> .


#define N 1000 //数组长度
#define M 200 //数组分界

insertSort, start time is:
        04:31:14.284    2002/01/01 星期2
insertSort, end time is:
        04:31:14.284    2002/01/01 星期2
insertSort, runned time is :
        0 ms !


====================================================
shellSort, start time is:
        04:31:14.284    2002/01/01 星期2
shellSort, end time is:
        04:31:14.284    2002/01/01 星期2
shellSort, runned time is :
        0 ms !


====================================================



--------------------------------
Process exited after 0.04155 seconds with return value 0
请按任意键继续. . .



#define N 10000 //数组长度
#define M 2000 //数组分界

运行结果:

insertSort, start time is:
        04:32:29.118    2002/01/01 星期2
insertSort, end time is:
        04:32:29.118    2002/01/01 星期2
insertSort, runned time is :
        0 ms !


====================================================
shellSort, start time is:
        04:32:29.118    2002/01/01 星期2
shellSort, end time is:
        04:32:29.118    2002/01/01 星期2
shellSort, runned time is :
        0 ms !


====================================================



--------------------------------
Process exited after 0.04038 seconds with return value 0
请按任意键继续. . .



before:
[57,5,44,15,13,56,72,49,99,73]

insertSort, start time is:
        09:48:42.573    2019/06/04 星期2
insertSort, end time is:
        09:48:42.573    2019/06/04 星期2
insertSort, runned time is :
        0 ms !

after sort:
[62,5,13,15,44,49,56,62,72,73]

====================================================
before:
[57,5,44,15,13,56,72,49,99,73]

shellSort, start time is:
        09:48:42.576    2019/06/04 星期2
shellSort, end time is:
        09:48:42.576    2019/06/04 星期2
shellSort, runned time is :
        0 ms !

after sort:
[73,5,13,15,44,49,56,72,73,99]

====================================================
before:
[57,5,44,15,13,56,72,49,99,73]

binaInsertSort, start time is:
        09:48:42.580    2019/06/04 星期2
binaInsertSort, end time is:
        09:48:42.584    2019/06/04 星期2
binaInsertSort, runned time is :
        4 ms !

after sort:
[99,5,13,15,44,49,56,72,73,99]

====================================================
before:
[57,5,44,15,13,56,72,49,99,73]

path2InsertSort, start time is:
        09:48:42.629    2019/06/04 星期2
[57,-1,-1,-1,-1,-1,-1,-1,-1,-1]
insert 5   < (K(first)=0:V=57)--> [57,-1,-1,-1,-1,-1,-1,-1,-1,5]
insert 44   between [K(first)=9:V=5, AND K(last)=0:V=57]--> [44,57,-1,-1,-1,-1,-1,-1,-1,5]
insert 15   between [K(first)=9:V=5, AND K(last)=1:V=57]--> [15,44,57,-1,-1,-1,-1,-1,-1,5]
insert 13   between [K(first)=9:V=5, AND K(last)=2:V=57]--> [13,15,44,57,-1,-1,-1,-1,-1,5]
insert 56   between [K(first)=9:V=5, AND K(last)=3:V=57]--> [13,15,44,56,57,-1,-1,-1,-1,5]
insert 72   > (K(last)=4:V=57)--> [13,15,44,56,57,72,-1,-1,-1,5]
insert 49   between [K(first)=9:V=5, AND K(last)=5:V=72]--> [13,15,44,49,56,57,72,-1,-1,5]
insert 99   > (K(last)=6:V=72)--> [13,15,44,49,56,57,72,99,-1,5]
insert 73   between [K(first)=9:V=5, AND K(last)=7:V=99]--> [13,15,44,49,56,57,72,73,99,5]
path2InsertSort, end time is:
        09:48:42.672    2019/06/04 星期2
path2InsertSort, runned time is :
        43 ms !

after sort:
[5,13,15,44,49,56,57,72,73,99]

====================================================



--------------------------------
Process exited after 0.6031 seconds with return value 0
请按任意键继续. . .


*/
