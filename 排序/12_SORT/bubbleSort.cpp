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


void bubbleSort_v1 (Elem arr[] , int length);
void bubbleSort_v2 (Elem arr[] , int length);
void bubbleSort_v3 (Elem arr[] , int length);

/*����ָ��
@param arr:int[],������ʼ��ַ
@param length:int,���鳤��

*/
//int (*bubble_sort)(Elem arr[] , int length);
void (*bubble_sort[])(Elem arr[] , int length) = {bubbleSort_v1,bubbleSort_v2,bubbleSort_v3};;

/*
@param arr:int[],������ʼ��ַ
@param length:int,���鳤��

*/
void bubbleSort_v1 (Elem arr[] , int length) {
	Elem tmp=0;
	for(int i=0; i<length-1; i++) { //����
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
@param arr:int[],������ʼ��ַ
@param length:int,���鳤��

*/
void bubbleSort_v2 (Elem arr[] , int length) {
	Elem tmp=0;
	bool isSorted;//��¼�Ƿ�����

	for(int i=0; i<length-1; i++) {

		//�ٶ�i������
		isSorted = true;

		for(int j=0; j<length-1-i; j++) {
			if(arr[j]>arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;

				//swap mean is not sorted!
				isSorted = false;
			}
		}//for end,��i�˽������

		if(isSorted) { //have been soorted
			break;//end
		}
	}

}


/*
@param arr:int[],������ʼ��ַ
@param length:int,���鳤��

ÿһ�����������ǽ����������������Ĺؼ����ƶ������һ����¼��λ���ϡ�
��������Ľ�������Ϊ��
         ���һ��û�н��н�����¼��
һ������£�ÿ����һ�� bubble��i--����������ÿ�˽���ˡ�
*/

void bubbleSort_v3(Elem arr[], int length) {
	int i, j, lastExchangeIndex;
	Elem tmp;

	//��0��length-1�������ģ�����ŵ�i
	for(i = length-1; i>0;) {
		lastExchangeIndex = 0; //��¼i�˽��������һ����¼��λ��
		for (j = 0;  j < i;  j++) { //ÿ����Ҫ�Ƚϵ�Ԫ�ضԵĸ���
			if (arr[j+1] < arr[j]) {
				//swap(arr[j], arr[j+1]);
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

				lastExchangeIndex = j; //���� �����˽����ļ�¼λ��
			} //if

		}//for-end, lastExchangeIndex�ǽ�����¼���λ��

		i = lastExchangeIndex; // ���˽��й����������һ����¼��λ��
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
@param int a[]:������a,��������Ϊint[] ,�����׵�ַ
@param int n:���鳤��
*/
void outputArray(int a[], int n) {
	int i;

	printf("[");
	for(i=0; i<n; i++) {
		printf("%d",  a[i]);
		if(i != n-1) { //�������һ��Ԫ��
			printf(",");
			//ÿ�д�ӡCOL��
			if((i+1)%COL == 0) {
				printf("\n");
			}
		} else { //�����һ��Ԫ��
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
		printf( "\t%4d/%02d/%02d ����%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);


		bubble_sort[i](arr, N);

		GetLocalTime( &sysTime[1] );
		cout << "bubbleSort_v"<<i+1<<", end time is:\n";
		printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
		printf( "\t%4d/%02d/%02d ����%1d\n", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);



		double run_time = sysTime[1].wSecond*1000 + sysTime[1].wMilliseconds -
		                  (sysTime[0].wSecond*1000 + sysTime[0].wMilliseconds) ;

		cout << "bubbleSort_v"<<i+1<<", runned time is :\n\t" << run_time <<  " ms !" << endl << endl;


	}

/*
	//��1�ַ�ʽ����¼����ʱ��
		cout << "init array is :\n";
		outputArray(arr, N);
		cout << endl << endl;

	cout << "bubbleSort_v1, start time is:\n";
	GetLocalTime( &sysTime[0] );

	printf( "\t%02d:%02d:%02d.%03d ", sysTime[0].wHour,sysTime[0].wMinute, sysTime[0].wSecond, sysTime[0].wMilliseconds);
	printf( "\t%4d/%02d/%02d ����%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);

	bubbleSort_v1(arr, N);

	GetLocalTime( &sysTime[1] );
	cout << "bubbleSort_v1, end time is:\n";
	printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
	printf( "\t%4d/%02d/%02d ����%1d\n", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);



	double run_time = sysTime[1].wSecond*1000 + sysTime[1].wMilliseconds -
	                  (sysTime[0].wSecond*1000 + sysTime[0].wMilliseconds) ;

	cout << "bubbleSort_v1, runned time is : " << run_time <<  " ms !" << endl << endl;

	cout << "bubbleSort_v1 array is :\n";
	outputArray(arr, N);
	cout << endl << endl;

	//��2�ַ�ʽ����¼����ʱ��

	inputArr(arr, N, M);//��������
		cout << "init array is :\n";
		outputArray(arr, N);
		cout << endl << endl;

	cout << "bubbleSort_v2, start time is:\n";
	GetLocalTime( &sysTime[0] );

	printf( "\t%02d:%02d:%02d.%03d ", sysTime[0].wHour,sysTime[0].wMinute, sysTime[0].wSecond, sysTime[0].wMilliseconds);
	printf( "\t%4d/%02d/%02d ����%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);

	bubbleSort_v2(arr, N);

	GetLocalTime( &sysTime[1] );
	cout << "bubbleSort_v2, end time is:\n";

	printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
	printf( "\t%4d/%02d/%02d ����%1d\n ", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);
	run_time = sysTime[1].wSecond*1000 + sysTime[1].wMilliseconds -
	           (sysTime[0].wSecond*1000 + sysTime[0].wMilliseconds) ;

	cout << "bubbleSort_v2, runned time is : " << run_time <<  " ms !" << endl << endl;

		cout << "bubbleSort_v2 array is :\n";
		outputArray(arr, N);
		cout << endl << endl;


	//��3�ַ�ʽ����¼����ʱ��
	inputArr(arr, N, M);//��������
		cout << "init array is :\n";
		outputArray(arr, N);
		cout << endl << endl;

	cout << "bubbleSort_v3, start time is:\n";
	GetLocalTime( &sysTime[0] );
	printf( "\t%4d/%02d/%02d ����%1d ", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);
	printf( "\t%02d:%02d:%02d.%03d \n", sysTime[0].wHour,sysTime[0].wMinute, sysTime[0].wSecond, sysTime[0].wMilliseconds);


	bubbleSort_v3(arr, N);

	GetLocalTime( &sysTime[1] );
	cout << "bubbleSort_v3, end time is:\n";
	printf( "\t%4d/%02d/%02d ����%1d ", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);
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

#define N 100 //���鳤��
#define M 20 //����ֽ�

���н��:

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
        09:48:11.299    2019/05/28 ����2
bubbleSort_v1, end time is:
        09:48:11.299    2019/05/28 ����2
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
        09:48:11.362    2019/05/28 ����2
bubbleSort_v2, end time is:
        09:48:11.366    2019/05/28 ����2
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
        2019/05/28 ����2        09:48:11.473
bubbleSort_v3, end time is:
        2019/05/28 ����2        09:48:11.476
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
�밴���������. . .

#define N 1000 //���鳤��
#define M 200 //����ֽ�

bubbleSort_v1, start time is:
        09:54:00.034    2019/05/28 ����2
bubbleSort_v1, end time is:
        09:54:00.035    2019/05/28 ����2
bubbleSort_v1, runned time is : 1 ms !

bubbleSort_v2, start time is:
        09:54:00.036    2019/05/28 ����2
bubbleSort_v2, end time is:
        09:54:00.037    2019/05/28 ����2
 bubbleSort_v2, runned time is : 1 ms !

bubbleSort_v3, start time is:
        2019/05/28 ����2        09:54:00.038
bubbleSort_v3, end time is:
        2019/05/28 ����2        09:54:00.038
bubbleSort_v3, runned time is : 0 ms !

--------------------------------
Process exited after 0.4066 seconds with return value 0
�밴���������. . .



#define N 10000 //���鳤��
#define M 2000 //����ֽ�

���н��:

bubbleSort_v1, start time is:
        09:56:04.696    2019/05/28 ����2
bubbleSort_v1, end time is:
        09:56:04.848    2019/05/28 ����2
bubbleSort_v1, runned time is : 152 ms !

bubbleSort_v2, start time is:
        09:56:04.850    2019/05/28 ����2
bubbleSort_v2, end time is:
        09:56:04.911    2019/05/28 ����2
 bubbleSort_v2, runned time is : 61 ms !

bubbleSort_v3, start time is:
        2019/05/28 ����2        09:56:04.911
bubbleSort_v3, end time is:
        2019/05/28 ����2        09:56:04.911
bubbleSort_v3, runned time is : 0 ms !

--------------------------------
Process exited after 0.6478 seconds with return value 0
�밴���������. . .


*/
