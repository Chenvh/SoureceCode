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
#define MAX_SIZE

typedef int Status;

typedef struct {
	Elem arr[N+1];	//用于存储要排序顺序表，arr[0]用作哨兵或临时变量
	int length;		// 用于记录顺序表的长度

} SqList;




//函数前置声明
void mergeSort_V1(SqList &list);
void mergeSort_V2(SqList &list);

/*函数指针
@param pList:SqList &lis 
*/
void (*pFunc_sort[F_SIZE])(SqList &list) = {mergeSort_V1, mergeSort_V2};
string funcName[F_SIZE] = {"mergeSort_V1", "mergeSort_V2"};




// 交换list.中数组arr的下标为i和j的值
void swap(SqList &list,int i,int j) {
	Elem temp=list.arr[i];
	list.arr[i]=list.arr[j];
	list.arr[j]=temp;
}



void init(SqList &list) {
	for(int i=0; i<list.length; i++) {
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
		if(!((i+1)%COL)) {
			printf("\n");
		}

	}
	printf("\n");
}




/* mergeListFrom2Block 合并数组orign中2块 至 数组 dest中1块
将有序的orign[left..mid] 与 orign[mid+1..n]归并为有序的 dest[left..right]
@param orign:原始数组
@param dest: 目标数组
@param left: 序列左端
@param mid: 序列中端
@param right: 序列右端
*/
void mergeListFrom2Block(int orign[],int dest[],int left,int mid,int right) {
	int two,first;//first,two分别表示2块数组的下标

	//将orign中记录由小到大地并入dest

	//第二块与第一块依次比较
	for(two=mid+1, first=left; left<=mid && two<=right; first++) {

		if (orign[left]<orign[two]) { //第1块中的小
			dest[first]=orign[left++];
		} else { //第2块中更小
			dest[first]=orign[two++];
		}

	}//loop end,left>mid 或 two>right

	int surplus; //标识剩余的

	//第1块还有剩余的
	if(left<=mid) { // 此时,two > right.即第2块遍历完毕

		for(surplus=0; surplus<=mid-left; surplus++) { //将剩余的orign[left..mid]复制到dest
			dest[first+surplus]=orign[left+surplus];
		}

	} else { //此时, left>mid,第1块遍历完毕, 而 two <= right 即第2块还有剩余的
		if(two<=right) {
			for(surplus=0; surplus<=right-two; surplus++)
				dest[first+surplus]=orign[two+surplus];		/* 将剩余的orign[two..right]复制到dest */
		}
	} //end if,surplus处理完毕

}//---mergeListFrom2Block 合并数组orign中2块 至 数组 dest中1块 END


/* 递归法
将orign[begin..end]归并排序为有序序列 dest[begin..end]
@param orign:原始数组
@param dest: 目标数组

@param begin: 起点
@param end:终点
*/
void sortMgRecursion(int orign[],int dest[],int begin, int end) {
	int mid;
	int tmpArr[N+1];
	if(begin == end) { //只有1个元素
		dest[begin]=orign[begin];
	} else {
		//将orign[begin..end]平分为orign[begin..mid]和orign[mid+1..end]
		mid=(begin+end)/2;

		//递归地将orign[begin..mid]归并为 有序序列的tmpArr[begin..mid]
		sortMgRecursion(orign, tmpArr, begin, mid);

		//递归地将orign[mid+1..end]归并为有序的tmpArr[mid+1..end]
		sortMgRecursion(orign, tmpArr, mid+1, end);

		//将tmpArr[begin..mid]和tmpArr[mid+1..end] 归并到 dest[begin..end]
		mergeListFrom2Block(tmpArr, dest, begin, mid, end);
	}
}

/* 递归法 
对顺序表list作归并排序 
*/
void mergeSort_V1(SqList &list) {
	sortMgRecursion(list.arr, list.arr, 1, list.length);
}

/* 非递归法
将orign[]中相邻跨度为span的子序列两两归并到dest[]
*/
void mergeListBySpan(int orign[],int dest[], int span, int n) {
	int i;

	for (i=1; i <= n-2*span+1; i += 2*span) {

		//将orgin中[i,i+span-1] 与 [i+span, i+2*span-1] 合并至 dest[i, i+2*span-1]
		mergeListFrom2Block(orign, dest, i, i+span-1, i+2*span-1);
	}//loop end, i>n-2*span+1


	if(i<n-span+1) { //余下2个子序列, 归并最后两个序列
		//将orgin中[i,i+span-1] 与 [i+span, n] 合并至 dest[i, n]
		mergeListFrom2Block(orign, dest, i, i+span-1, n);
	}

	else { //只余下1个子序列
		for(int j=i; j <= n; j++) {
			dest[j] = orign[j];
		}

	}

}

/*
对顺序表L作归并非递归排序
*/
void mergeSort_V2(SqList &list) {
	
	//tmpArr申请空间与表list的length相当 
	Elem* tmpArr=(Elem*)malloc(list.length * sizeof(Elem));
	
	int k=1;

	for(k=1; k<list.length; ) {

		//将list中数组按跨度为k合并至数组tmpArr中
		mergeListBySpan(list.arr, tmpArr, k, list.length);

		k *= 2;	//子序列长度加倍

		//将数组tmpArr按跨度为k合并至list中数组arr中
		mergeListBySpan(tmpArr, list.arr, k, list.length);

		k *= 2;	//子序列长度加倍
	}


}



int main() {

	SqList list;
	list.length = N;

	//use windows API
	SYSTEMTIME sysTime[2];

	for(int i=0; i<F_SIZE; i++) {

		inputData(list, 1);
		cout<<"before:"<<endl;
		outputData(list,1);
		cout << endl ;

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
[39,42,34,41,50,99,55,25,19,79,8,61,87,45,56,68,44,30,13,
40,91,8,89,99,58,90,50,15,56,82,75,18,57,70,0,19,75,56,44,
31,17,64,64,68,31,75,87,85,26,5,88,38,13,3,40,23,64,59,49,
43,97,39,62,19,36,71,3,42,84,2,7,19,2,91,8,41,67,46,95,
4,6,74,21,53,47,99,77,22,95,91,15,61,7,72,96,4,10,2,35]


mergeSort_V1, start time is:
        16:38:25.635    2019/06/10 星期1
mergeSort_V1, end time is:
        16:38:25.635    2019/06/10 星期1
mergeSort_V1, runned time is :
        0 ms !

after sort:
[0,1,2,2,2,3,3,4,4,5,6,7,7,8,8,8,10,13,13,
15,15,17,18,19,19,19,19,21,22,23,25,26,30,31,31,34,35,36,38,
39,39,40,40,41,41,42,42,43,44,44,45,46,47,49,50,50,53,55,56,
56,56,57,58,59,61,61,62,64,64,64,67,68,68,70,71,72,74,75,75,
75,77,79,82,84,85,87,87,88,89,90,91,91,91,95,95,96,97,99,99]


====================================================
before:
[39,42,34,41,50,99,55,25,19,79,8,61,87,45,56,68,44,30,13,
40,91,8,89,99,58,90,50,15,56,82,75,18,57,70,0,19,75,56,44,
31,17,64,64,68,31,75,87,85,26,5,88,38,13,3,40,23,64,59,49,
43,97,39,62,19,36,71,3,42,84,2,7,19,2,91,8,41,67,46,95,
4,6,74,21,53,47,99,77,22,95,91,15,61,7,72,96,4,10,2,35]


mergeSort_V2, start time is:
        16:38:25.663    2019/06/10 星期1
mergeSort_V2, end time is:
        16:38:25.664    2019/06/10 星期1
mergeSort_V2, runned time is :
        1 ms !

after sort:
[0,2,2,2,3,3,4,4,5,6,7,7,8,8,8,10,13,13,15,
15,17,18,19,19,19,19,21,22,23,25,26,30,31,31,34,35,36,38,39,
39,40,40,41,41,42,42,43,44,44,45,46,47,49,50,50,53,55,56,56,
56,57,58,59,61,61,62,64,64,64,67,68,68,70,71,72,74,75,75,75,
77,79,82,84,85,87,87,88,89,90,91,91,91,95,95,96,97,99,99,99]


====================================================



--------------------------------
Process exited after 0.5608 seconds with return value 0
请按任意键继续. . .

*/
