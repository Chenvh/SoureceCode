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
#define N 100 //˳����� 
#define M 20 //˳���ֽ� 
#define COL 20

#define F_SIZE 1

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define EMPTYDATA -1

//���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ
#define MAX_LENGTH_INSERT_SORT 7

typedef int Status;

typedef struct {
	Elem arr[N+1];	//���ڴ洢Ҫ����˳���arr[0]�����ڱ�����ʱ����
	int length;		// ���ڼ�¼˳���ĳ��� 	
	
} SqList;




//����ǰ������
void heapSort(SqList &list);

/*����ָ��
@param pList:SqList *
*/
void (*pFunc_sort[F_SIZE])(SqList &list) = {heapSort};
string funcName[F_SIZE] = {"heapSort"};




// ����list.������arr���±�Ϊi��j��ֵ
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
@param start:int,˳�����ʼλ��,[start,length-1]��� 
*/
void inputData(SqList& list , int start) {
	srand(time(NULL));
	
	//��˳���д��length������
	for (int i = start; i <list.length; i++) {
		
			list.arr[i] = rand()%(list.length); //value is [0, length-1]
		
	}
}


/*
[start,length-1]��� 
@param list:˳��� 
@param border:int,˳���ֽ�,[0, border-1]�ǵ���,[border,length-1]˳��
@param start:int,˳�����ʼλ��
*/
void inputData_1(SqList& list , int border, int start) {

	//��list��д��10000������ ǰborder���� ��֮��˳��
	for (int i = 1; i <list.length; i++) {
		if (i <= border) { //[1, border-1]������
			list.arr[i] = border+1-i; //value is [border,1 ]
		} else { //[border,length-1]˳��
			list.arr[i] = i; //value is [border, length-1]
		}
	}
}



/*���˳���
����:
[27,26,30,15,14,
26,22,21]
@param list,SqList
@param start:int,˳�����ʼλ�� 
*/
void outputData(SqList list, int start) {
	int i;

	printf("[");
	for(i=start; i<list.length; i++) {
		printf("%d",  list.arr[i]);
		if(i != list.length-1) { //�������һ��Ԫ��
			printf(",");
			
		} else { //�����һ��Ԫ��
			printf("]");
		}
		if(!((i+1)%COL)){
			printf("\n");
		} 

	}
	printf("\n");
}







/* ������
������, �󶥶� 
��֪list.arr[begin..end]�м�¼�Ĺؼ��ֳ�list.arr[begin]֮�������ѵĶ���
����������list.arr[begin]�Ĺؼ���,ʹlist.arr[begin..end]��Ϊһ���󶥶�
 */
void heapAdjust(SqList &list, int begin, int end)
{ 
	int child;
	Elem tmp = list.arr[begin];
	
	for(child=2*begin; child<=end; child *= 2)  //�عؼ��ֽϴ�ĺ��ӽ������ɸѡ 
	{
		if(child<end && list.arr[child]<list.arr[child+1]){
			child++; //childΪ�ؼ����нϴ�ļ�¼�ĺ��ӽ���±�
		}
			 
		if(tmp >= list.arr[child]){
			break; //tmpӦ������λ��begin�� 
		}
			
		list.arr[begin] = list.arr[child];
		begin=child;//update
	}
	list.arr[begin]=tmp; /* ���� */
}

/*  
��˳���list���ж����� 
*/
void heapSort(SqList &list)
{
	int i;
	for(i=list.length/2; i>0; i--)  //��list�е�arr������һ������� 
	{
		heapAdjust(list,i,list.length);
	}
	

	for(i=list.length; i>1; i--)
	{ 
		 swap(list,1,i);   //���Ѷ���¼�͵�ǰδ�����������е����һ����¼���� 
		 
		 heapAdjust(list,1,i-1);  //��list.arr[1..i-1]���µ���Ϊ����� 
	}
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
		printf( "\t%4d/%02d/%02d ����%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);


		pFunc_sort[i](list);

		GetLocalTime( &sysTime[1] );
		cout << funcName[i]<<", end time is:\n";
		printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
		printf( "\t%4d/%02d/%02d ����%1d\n", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);



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

#define N 100 //˳�����
#define M 20 //˳���ֽ�

���н��:

before:
[11,25,83,69,79,77,70,34,52,90,75,79,85,84,82,81,19,46,73,
45,58,25,93,18,17,32,83,17,89,37,55,56,97,39,4,88,25,43,93,
26,60,96,92,9,14,38,47,34,28,79,83,56,70,57,61,5,65,90,14,
77,86,52,51,13,73,51,93,74,18,98,77,19,73,86,91,80,88,81,48,
53,93,66,37,39,97,64,42,9,45,11,63,29,19,73,6,92,55,2,54]


heapSort, start time is:
        09:43:19.353    2019/06/10 ����1
heapSort, end time is:
        09:43:19.353    2019/06/10 ����1
heapSort, runned time is :
        0 ms !

after sort:
[1,2,4,5,6,9,9,11,11,13,14,14,17,17,18,18,19,19,19,
25,25,25,26,28,29,32,34,34,37,37,38,39,39,42,43,45,45,46,47,
48,51,51,52,52,53,54,55,55,56,56,57,58,60,61,63,64,65,66,69,
70,70,73,73,73,73,74,75,77,77,77,79,79,79,80,81,81,82,83,83,
83,84,85,86,86,88,88,89,90,90,91,92,92,93,93,93,93,96,97,97]


====================================================



--------------------------------
Process exited after 0.456 seconds with return value 0
*/
