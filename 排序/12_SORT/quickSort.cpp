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

#define F_SIZE 2

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
void quickSort(SqList &list);
void quickSort_V2(SqList &list);

/*����ָ��
@param pList:SqList *
*/
void (*pFunc_sort[F_SIZE])(SqList &list) = {quickSort,quickSort_V2};
string funcName[F_SIZE] = {"quickSort", "quickSort_V2"};




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



/*
��˳���pList��ֱ�Ӳ������� ,д����
@param pList: SqList ����(ָ��*)
*/
void insertSort(SqList *pList) {
	int i,j;

	for(i=2; i<=pList->length; i++) {
		if (pList->arr[i] < pList->arr[i-1]) { // �轫pList->arr[i]���������ӱ�
			pList->arr[0]=pList->arr[i]; //��i��Ԫ���ݴ�Ϊ�ڱ�,ʹ�������ѭ���ܽ���

			//��i-1��ʼ,�Ӻ���ǰ���� ,�ҵ������ڸ�Ԫ�ص�λ��
			for(j=i-1; pList->arr[j] > pList->arr[0]; j--) {
				pList->arr[j+1]=pList->arr[j]; // ��¼����
			}//loop end, pList->arr[j] <= pList->arr[0]

			pList->arr[j+1]=pList->arr[0]; // ���뵽��ȷλ��,��j+1
		}
	}
}



/* **************************************** */

/* ��������******************************** */
 
/* ����˳���list���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ(��)�ļ�¼������(С)������ */
int partition(SqList &list, int low, int high)
{ 
	int pivotkey;

	pivotkey=list.arr[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	while(low<high) /*  �ӱ�����˽�������м�ɨ�� */
	{ 
		 while(low<high && list.arr[high]>=pivotkey){
		 	high--;
		 }//Loop End, low == high ��  list.arr[high] < pivotkey
		 swap(list, low, high);/* ���������¼С�ļ�¼�������Ͷ� */
		 
		 while(low<high && list.arr[low]<=pivotkey){
		 	low++;
		 }	//Loop End, low == high ��  list.arr[low] > pivotkey		
		 swap(list, low, high);/* ���������¼��ļ�¼�������߶� */
	}//Loop End, low == high 
	return low; /* ������������λ�� */
}

/* ��˳���list�е�������list.arr[low..high]���������� */
void fastSort(SqList &list,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=partition(list,low,high); /*  ��list.arr[low..high]һ��Ϊ�����������ֵpivot */
			fastSort(list,low,pivot-1);		/*  �Ե��ӱ�ݹ����� */
			fastSort(list,pivot+1,high);		/*  �Ը��ӱ�ݹ����� */
	}
}

/* ��˳���list���������� */
void quickSort(SqList &list)
{ 
	fastSort(list, 1, list.length);
}


/* �Ľ����������
 ���������Ż��㷨 
*/

//һ�λ��� 
int partition_V2(SqList &list,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; //��ȡ˳����м��Ԫ�ص��±� 
	
	if (list.arr[low]>list.arr[high])	{//����������Ҷ����ݣ���֤��˽�С
			swap(list,low,high);
	}	
	if (list.arr[m]>list.arr[high]){//�����м����Ҷ����ݣ���֤�м��С
		swap(list,high,m);
	}
	
			
	if (list.arr[m]>list.arr[low]){//�����м���������ݣ���֤��˽�С
		swap(list,m,low);
	}
			
	
	pivotkey=list.arr[low]; // ���ӱ�ĵ�һ����¼�������¼ 	
	list.arr[0]=pivotkey;  //������ؼ��ֱ��汸�ݵ�list.arr[0] 
	
	
	//��ʼʱ,low�˵�ֵ�Ѿ�����(�൱�ڴ˴���ȱ),��Ҫ���һ��С��pivotkey��Ԫ�� 
	//  �ӱ�����˽�������м�ɨ�� 
	while(low<high) 
	{ 
		//��high��ɨ��,�ҳ�С��pivotkey��Ԫ�� 
		 while(low<high&&list.arr[high]>=pivotkey){
		 	high--;
		 }//loop end, list.arr[high] < pivotkey,�߶˴�С����  �� low > high 
		
		if(low < high){ //list.arr[high] < pivotkey,�߶˴�С����  
			list.arr[low] = list.arr[high];
		} 
		
		//�ٴ�low��ɨ�� ,�ҳ���pivotke��Ԫ�� 
		while(low<high&&list.arr[low]<=pivotkey){
			low++;
		}//loop end, low>high ��  list.arr[low] > pivotkey
		
		if(low < high){ //list.arr[low] > pivotkey,�Ͷ˴�������  
			list.arr[high]=list.arr[low];	
		}	
		
	}//loop end, low>=high 
	list.arr[low]=list.arr[0];
	
	return low;  //������������λ�� 
}

void fastSort_V2(SqList &list,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=partition_V2(list,low,high); /*  ��list.arr[low..high]һ��Ϊ�����������ֵpivot */
			fastSort_V2(list,low,pivot-1);		/*  �Ե��ӱ�ݹ����� */
			/* fastSort(list,pivot+1,high);		/*  �Ը��ӱ�ݹ����� */
			low=pivot+1;	/* β�ݹ� */
		}
	}
	else{
		insertSort( &list);//ʹ�ò������� 
	}
		
}

/* ��˳���list���������� */
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
[0,14,11,41,53,29,94,92,2,15,17,7,17,91,89,72,61,93,70,
72,57,93,55,17,47,50,82,61,45,56,64,65,72,48,16,39,29,67,5,
54,33,96,28,27,52,30,15,36,49,63,26,82,68,71,79,12,28,83,97,
78,63,24,61,95,59,75,73,67,25,10,76,76,73,92,5,95,15,17,59,
9,28,40,49,51,78,62,99,39,93,51,17,67,62,99,87,35,24,93,41]


quickSort, start time is:
        08:46:06.098    2019/06/10 ����1
quickSort, end time is:
        08:46:06.098    2019/06/10 ����1
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
        08:46:06.127    2019/06/10 ����1
quickSort_V2, end time is:
        08:46:06.131    2019/06/10 ����1
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
�밴���������. . .

*/
