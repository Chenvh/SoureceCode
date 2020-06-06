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


void bubbleSort_v1 (Elem arr[] , int length);
void bubbleSort_v2 (Elem arr[] , int length);
void bubbleSort_v3 (Elem arr[] , int length);

/*函数指针
@param arr:int[],数组起始地址
@param length:int,数组长度

*/
//int (*bubble_sort)(Elem arr[] , int length);
void (*bubble_sort[])(Elem arr[] , int length) = {bubbleSort_v1,bubbleSort_v2,bubbleSort_v3};;

/*
@param arr:int[],数组起始地址
@param length:int,数组长度

*/
void bubbleSort_v1 (Elem arr[] , int length) {
	Elem tmp=0;
	for(int i=0; i<length-1; i++) { //趟数
		for(int j=0; j<length-1-i; j++) {
			if(arr[j]>arr[j+1]) {
				//swap
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}//if end, swap over
		}//for end, this turns over
	}//for end, this sub over

}


/*
@param arr:int[],数组起始地址
@param length:int,数组长度

*/
void bubbleSort_v2 (Elem arr[] , int length) {
	Elem tmp=0;
	bool isSorted;//记录是否有序

	for(int i=0; i<length-1; i++) {

		//假定i趟有序
		isSorted = true;

		for(int j=0; j<length-1-i; j++) {
			if(arr[j]>arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;

				//swap mean is not sorted!
				isSorted = false;
			}
		}//for end,第i趟交换完毕

		if(isSorted) { //have been soorted
			break;//end
		}
	}

}


/*
@param arr:int[],数组起始地址
@param length:int,数组长度

每一趟起泡排序都是将待排序序列中最大的关键字移动到最后一个记录的位置上。
起泡排序的结束条件为，
         最后一趟没有进行交换记录。
一般情况下，每经过一趟 bubble，i--，但并不是每趟皆如此。
*/

void bubbleSort_v3(Elem arr[], int length) {
	int i, j, lastExchangeIndex;
	Elem tmp;

	//从0…length-1中找最大的，结果放到i
	for(i = length-1; i>0;) {
		lastExchangeIndex = 0; //记录i趟交换过最后一个记录的位置
		for (j = 0;  j < i;  j++) { //每趟需要比较的元素对的个数
			if (arr[j+1] < arr[j]) {
				//swap(arr[j], arr[j+1]);
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

				lastExchangeIndex = j; //保存 进行了交换的记录位置
			} //if

		}//for-end, lastExchangeIndex是交换记录最后位置

		i = lastExchangeIndex; // 本趟进行过交换的最后一个记录的位置
	} // for end

} // bubbleSort_v3 END

/*
void bubbleSort_V3 (Elem arr[] , int length) {
	int tmp = 0;
	int lastExchangeIndex = 0;
	int sortBorder = length - 1;
	for (int i = 0; i < length-1; i++) {
		boolean isSorted = true;
		for (int j = 0; j < sortBorder; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				isSorted = false;
				lastExchangeIndex = j;
			}
		}
		sortBorder = lastExchangeIndex;
		if (isSorted) {
			break;
		}
	}
}
}
*/


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
@param int a[]:数组名a,数据类型为int[] ,代表首地址
@param int n:数组长度
*/
void outputArray(int a[], int n) {
	int i;

	printf("[");
	for(i=0; i<n; i++) {
		printf("%d",  a[i]);
		if(i != n-1) { //不是最后一个元素
			printf(",");
			//每行打印COL个
			if((i+1)%COL == 0) {
				printf("\n");
			}
		} else { //是最后一个元素
			printf("]");
		}

	}
	printf("\n");
}


int main() {

	Elem arr[N];
	inputArr(arr, N, M);

	string fn_name="bubbleSort_v1";

	/*	fn_name = fn_name.replace(fn_name.end()-1, fn_name.end(), 1, '2');
		cout << "1: " << fn_name << endl;   // 1: bubbleSort_v2*/



	//use windows API
	SYSTEMTIME sysTime[2];

	for(int i=0; i<3; i++) {

		cout << "bubbleSort_v"<<i+1<<", start time is:\n";
		GetLocalTime( &sysTime[0] );

		printf( "\t%02d:%02d:%02d.%03d ", sysTime[0].wHour,sysTime[0].wMinute, sysTime[0].wSecond, sysTime[0].wMilliseconds);
		printf( "\t%4d/%02d/%02d 星期%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);


		bubble_sort[i](arr, N);

		GetLocalTime( &sysTime[1] );
		cout << "bubbleSort_v"<<i+1<<", end time is:\n";
		printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
		printf( "\t%4d/%02d/%02d 星期%1d\n", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);



		double run_time = sysTime[1].wSecond*1000 + sysTime[1].wMilliseconds -
		                  (sysTime[0].wSecond*1000 + sysTime[0].wMilliseconds) ;

		cout << "bubbleSort_v"<<i+1<<", runned time is :\n\t" << run_time <<  " ms !" << endl << endl;


	}

/*
	//第1种方式，记录运行时间
		cout << "init array is :\n";
		outputArray(arr, N);
		cout << endl << endl;

	cout << "bubbleSort_v1, start time is:\n";
	GetLocalTime( &sysTime[0] );

	printf( "\t%02d:%02d:%02d.%03d ", sysTime[0].wHour,sysTime[0].wMinute, sysTime[0].wSecond, sysTime[0].wMilliseconds);
	printf( "\t%4d/%02d/%02d 星期%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);

	bubbleSort_v1(arr, N);

	GetLocalTime( &sysTime[1] );
	cout << "bubbleSort_v1, end time is:\n";
	printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
	printf( "\t%4d/%02d/%02d 星期%1d\n", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);



	double run_time = sysTime[1].wSecond*1000 + sysTime[1].wMilliseconds -
	                  (sysTime[0].wSecond*1000 + sysTime[0].wMilliseconds) ;

	cout << "bubbleSort_v1, runned time is : " << run_time <<  " ms !" << endl << endl;

	cout << "bubbleSort_v1 array is :\n";
	outputArray(arr, N);
	cout << endl << endl;

	//第2种方式，记录运行时间

	inputArr(arr, N, M);//重置数组
		cout << "init array is :\n";
		outputArray(arr, N);
		cout << endl << endl;

	cout << "bubbleSort_v2, start time is:\n";
	GetLocalTime( &sysTime[0] );

	printf( "\t%02d:%02d:%02d.%03d ", sysTime[0].wHour,sysTime[0].wMinute, sysTime[0].wSecond, sysTime[0].wMilliseconds);
	printf( "\t%4d/%02d/%02d 星期%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);

	bubbleSort_v2(arr, N);

	GetLocalTime( &sysTime[1] );
	cout << "bubbleSort_v2, end time is:\n";

	printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
	printf( "\t%4d/%02d/%02d 星期%1d\n ", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);
	run_time = sysTime[1].wSecond*1000 + sysTime[1].wMilliseconds -
	           (sysTime[0].wSecond*1000 + sysTime[0].wMilliseconds) ;

	cout << "bubbleSort_v2, runned time is : " << run_time <<  " ms !" << endl << endl;

		cout << "bubbleSort_v2 array is :\n";
		outputArray(arr, N);
		cout << endl << endl;


	//第3种方式，记录运行时间
	inputArr(arr, N, M);//重置数组
		cout << "init array is :\n";
		outputArray(arr, N);
		cout << endl << endl;

	cout << "bubbleSort_v3, start time is:\n";
	GetLocalTime( &sysTime[0] );
	printf( "\t%4d/%02d/%02d 星期%1d ", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);
	printf( "\t%02d:%02d:%02d.%03d \n", sysTime[0].wHour,sysTime[0].wMinute, sysTime[0].wSecond, sysTime[0].wMilliseconds);


	bubbleSort_v3(arr, N);

	GetLocalTime( &sysTime[1] );
	cout << "bubbleSort_v3, end time is:\n";
	printf( "\t%4d/%02d/%02d 星期%1d ", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);
	printf( "\t%02d:%02d:%02d.%03d \n", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);

	run_time = sysTime[1].wSecond*1000 + sysTime[1].wMilliseconds -
	           (sysTime[0].wSecond*1000 + sysTime[0].wMilliseconds) ;

	cout << "bubbleSort_v3, runned time is : " << run_time <<  " ms !" << endl;
		cout << "bubbleSort_v3 array is :\n";
		outputArray(arr, N);
		cout << endl << endl;*/

	return 0;
}


/*

#define N 100 //数组长度
#define M 20 //数组分界

运行结果:

init array is :
[19,18,17,16,15,14,13,12,11,10,
9,8,7,6,5,4,3,2,1,0,
20,21,22,23,24,25,26,27,28,29,
30,31,32,33,34,35,36,37,38,39,
40,41,42,43,44,45,46,47,48,49,
50,51,52,53,54,55,56,57,58,59,
60,61,62,63,64,65,66,67,68,69,
70,71,72,73,74,75,76,77,78,79,
80,81,82,83,84,85,86,87,88,89,
90,91,92,93,94,95,96,97,98,99]


bubbleSort_v1, start time is:
        09:48:11.299    2019/05/28 星期2
bubbleSort_v1, end time is:
        09:48:11.299    2019/05/28 星期2
bubbleSort_v1, runned time is : 0 ms !

bubbleSort_v1 array is :
[0,1,2,3,4,5,6,7,8,9,
10,11,12,13,14,15,16,17,18,19,
20,21,22,23,24,25,26,27,28,29,
30,31,32,33,34,35,36,37,38,39,
40,41,42,43,44,45,46,47,48,49,
50,51,52,53,54,55,56,57,58,59,
60,61,62,63,64,65,66,67,68,69,
70,71,72,73,74,75,76,77,78,79,
80,81,82,83,84,85,86,87,88,89,
90,91,92,93,94,95,96,97,98,99]


init array is :
[19,18,17,16,15,14,13,12,11,10,
9,8,7,6,5,4,3,2,1,0,
20,21,22,23,24,25,26,27,28,29,
30,31,32,33,34,35,36,37,38,39,
40,41,42,43,44,45,46,47,48,49,
50,51,52,53,54,55,56,57,58,59,
60,61,62,63,64,65,66,67,68,69,
70,71,72,73,74,75,76,77,78,79,
80,81,82,83,84,85,86,87,88,89,
90,91,92,93,94,95,96,97,98,99]


bubbleSort_v2, start time is:
        09:48:11.362    2019/05/28 星期2
bubbleSort_v2, end time is:
        09:48:11.366    2019/05/28 星期2
 bubbleSort_v2, runned time is : 4 ms !

bubbleSort_v2 array is :
[0,1,2,3,4,5,6,7,8,9,
10,11,12,13,14,15,16,17,18,19,
20,21,22,23,24,25,26,27,28,29,
30,31,32,33,34,35,36,37,38,39,
40,41,42,43,44,45,46,47,48,49,
50,51,52,53,54,55,56,57,58,59,
60,61,62,63,64,65,66,67,68,69,
70,71,72,73,74,75,76,77,78,79,
80,81,82,83,84,85,86,87,88,89,
90,91,92,93,94,95,96,97,98,99]


init array is :
[19,18,17,16,15,14,13,12,11,10,
9,8,7,6,5,4,3,2,1,0,
20,21,22,23,24,25,26,27,28,29,
30,31,32,33,34,35,36,37,38,39,
40,41,42,43,44,45,46,47,48,49,
50,51,52,53,54,55,56,57,58,59,
60,61,62,63,64,65,66,67,68,69,
70,71,72,73,74,75,76,77,78,79,
80,81,82,83,84,85,86,87,88,89,
90,91,92,93,94,95,96,97,98,99]


bubbleSort_v3, start time is:
        2019/05/28 星期2        09:48:11.473
bubbleSort_v3, end time is:
        2019/05/28 星期2        09:48:11.476
bubbleSort_v3, runned time is : 3 ms !
bubbleSort_v3 array is :
[0,1,2,3,4,5,6,7,8,9,
10,11,12,13,14,15,16,17,18,19,
20,21,22,23,24,25,26,27,28,29,
30,31,32,33,34,35,36,37,38,39,
40,41,42,43,44,45,46,47,48,49,
50,51,52,53,54,55,56,57,58,59,
60,61,62,63,64,65,66,67,68,69,
70,71,72,73,74,75,76,77,78,79,
80,81,82,83,84,85,86,87,88,89,
90,91,92,93,94,95,96,97,98,99]



--------------------------------
Process exited after 0.6719 seconds with return value 0
请按任意键继续. . .

#define N 1000 //数组长度
#define M 200 //数组分界

bubbleSort_v1, start time is:
        09:54:00.034    2019/05/28 星期2
bubbleSort_v1, end time is:
        09:54:00.035    2019/05/28 星期2
bubbleSort_v1, runned time is : 1 ms !

bubbleSort_v2, start time is:
        09:54:00.036    2019/05/28 星期2
bubbleSort_v2, end time is:
        09:54:00.037    2019/05/28 星期2
 bubbleSort_v2, runned time is : 1 ms !

bubbleSort_v3, start time is:
        2019/05/28 星期2        09:54:00.038
bubbleSort_v3, end time is:
        2019/05/28 星期2        09:54:00.038
bubbleSort_v3, runned time is : 0 ms !

--------------------------------
Process exited after 0.4066 seconds with return value 0
请按任意键继续. . .



#define N 10000 //数组长度
#define M 2000 //数组分界

运行结果:

bubbleSort_v1, start time is:
        09:56:04.696    2019/05/28 星期2
bubbleSort_v1, end time is:
        09:56:04.848    2019/05/28 星期2
bubbleSort_v1, runned time is : 152 ms !

bubbleSort_v2, start time is:
        09:56:04.850    2019/05/28 星期2
bubbleSort_v2, end time is:
        09:56:04.911    2019/05/28 星期2
 bubbleSort_v2, runned time is : 61 ms !

bubbleSort_v3, start time is:
        2019/05/28 星期2        09:56:04.911
bubbleSort_v3, end time is:
        2019/05/28 星期2        09:56:04.911
bubbleSort_v3, runned time is : 0 ms !

--------------------------------
Process exited after 0.6478 seconds with return value 0
请按任意键继续. . .


*/
