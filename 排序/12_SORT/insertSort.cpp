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
#define N 10 //���鳤�� 
#define M 2 //����ֽ� 
#define COL 20

#define F_SIZE 4

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define EMPTYDATA -1

//���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ
#define MAX_LENGTH_INSERT_SORT 7

typedef int Status;

typedef struct {
	Elem arr[N+1];	//���ڴ洢Ҫ�������飬arr[0]�����ڱ�����ʱ����
	int length;		// ���ڼ�¼˳���ĳ��� 	
	
} SqList;

// ����L������r���±�Ϊi��j��ֵ
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
@param border:int,����ֽ�,[0, border-1]�ǵ���,[border,length-1]˳��
*/
void inputData(SqList& list , int border) {
	srand(time(NULL));
	
	//������д��length������
	for (int i = 0; i <list.length; i++) {
		
			list.arr[i] = rand()% 100;//list.length; //value is [0, length-1]
		
	}
}


/*
@param list:˳��� 
@param border:int,����ֽ�,[0, border-1]�ǵ���,[border,length-1]˳��
*/
void inputData_1(SqList& list , int border) {

	//������д��10000������ ǰborder���� ��֮��˳��
	for (int i = 1; i <list.length; i++) {
		if (i <= border) { //[1, border-1]������
			list.arr[i] = border+1-i; //value is [border,1 ]
		} else { //[border,length-1]˳��
			list.arr[i] = i; //value is [border, length-1]
		}
	}
}



/*�������
����:
[27,26,30,15,14,
26,22,21]
@param list,SqList
*/
void outputData(SqList list) {
	int i;

	printf("[");
	for(i=0; i<list.length; i++) {
		printf("%d",  list.arr[i]);
		if(i != list.length-1) { //�������һ��Ԫ��
			printf(",");
			
		} else { //�����һ��Ԫ��
			printf("]");
		}

	}
	printf("\n");
}

//����ǰ������
void insertSort(SqList *pList);
void shellSort(SqList *pList);
void binaInsertSort(SqList *pList);
void path2InsertSort(SqList *pList);

/*����ָ��
@param pList:SqList *
*/
void (*pFunc_sort[F_SIZE])(SqList* pList) = {insertSort, shellSort, binaInsertSort, path2InsertSort};
string funcName[F_SIZE] = {"insertSort", "shellSort", "binaInsertSort", "path2InsertSort"};

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

/* ϣ������
@param pList :SqList˳���
*/
void shellSort(SqList *pList) {
	int i,j,k=0;
	int increment=pList->length;
	do {
		increment=increment/3 + 1;/* ���趨�������� */
		for(i=increment+1; i<=pList->length; i++) {
			if (pList->arr[i]<pList->arr[i-increment]) { /*  �轫pList->arr[i]�������������ӱ� */
				pList->arr[0]=pList->arr[i]; /*  �ݴ���pList->arr[0] */
				for(j=i-increment; j>0 && pList->arr[0]<pList->arr[j]; j-=increment)
					pList->arr[j+increment]=pList->arr[j]; /*  ��¼���ƣ����Ҳ���λ�� */
				pList->arr[j+increment]=pList->arr[0]; /*  ���� */
			}
		}
		//printf("	��%d��������: ", ++k );
		//print(*pList);
	} while(increment>1);

}

/*���ֲ��Ҳ������� "��˳���L���۰��������
*/
void  binaInsertSort (SqList* pList) {
	int i, j, low , high, m;
	//
	for  (i=2; i<=pList->length; i++)    {
		pList->arr[0] = pList->arr[i];             //��pList.arr[i]�ݴ浽pList.arr[0]
		low = 1;
		high = i-1;
		while  (low <= high)      {     //��arr[low, high]���۰����	��������λ��

			m = (low + high)/2;
			if (pList->arr[0] < pList->arr[m]) {//���pList.arr[0].key<pList.arr[m].key��
				high = m-1; //�������ڵͰ���
			} else { //���������ڸ߰���
				low = m + 1;
			}
		}//while end,low > high, pList->arr[0] > pList->arr[high] && pList->arr[0] < pList->arr[low]  
		
		for(j=i-1; j>=high+1; --j) {
			pList->arr[j+1] = pList->arr[j];   //��¼����
		}
		pList->arr[high+1] = pList->arr[0];    //����λ��high+1��low
	}//for
}// binaInsertSort


//=== path2InsertSort 2·����
void path2InsertSort(SqList *pList)  {  // 2-·��������

	int length=pList->length;
	//cout << length << endl;
	 
	
	SqList  tmpList;//tmpListΪ�����ռ�	
	tmpList.length = length;
	init(tmpList);

	tmpList.arr[0] = pList->arr[0];   //tmpList.arr�еĵ�һ����¼ΪpList.arr���ź���ļ�¼
	outputData(tmpList);
	
	int first = 0,last = 0; //first����ָʾtmpList.arr���ź������СԪ�أ�
	//lastָʾ���Ԫ�� ; ע������û����arr[0]������

	for (int i = 1; i < length; i++)     {
		cout << "insert " << pList->arr[i] << "  ";
		if (pList->arr[i] < tmpList.arr[first]) {  //����С��Ԫ��С�����뵽��ǰ
			cout << " < "<<"(K(first)="<<first<<":V="<<tmpList.arr[first] << ")--> ";
			//update 
			first = (first - 1 + length) % length;  //update index 
			tmpList.arr[first] = pList->arr[i]; //update value
			
			outputData(tmpList);
		} 
		else if (pList->arr[i] >tmpList.arr[last])   { //������Ԫ�ر����Ԫ�ش󣬲��뵽���
			cout << " > "<<"(K(last)="<<last<<":V="<<tmpList.arr[last] << ")--> ";
			
			//update
			last=(last+1+length)%length; //update index			
			tmpList.arr[last] =pList->arr[i];//update value
			outputData(tmpList);
		} 
		else //������Ԫ�ر���С�Ĵ󡢱�����С	,������last�����,last��Ҫupdate		
		{
			cout << " between "<<"[K(first)="<<first<<":V="<<tmpList.arr[first]<< ", AND ";
			cout <<  "K(last)="<<last<<":V="<< tmpList.arr[last] << "]--> ";
			
			int k;			 
			//ͨ�������������Ԫ�ز��ҳ������λ��
			for(k = last; pList->arr[i] < tmpList.arr[k]; k=(k-1+length)%length ){
				tmpList.arr[(k+1+length) %length]  = tmpList.arr[k]; //���� 
			} //loop end,k+1ΪҪ�����λ�� 
			
			tmpList.arr[(k+1+length)%length]  = pList->arr[i];//���� 
			
			//attention: update last
			last = (last+1+length)%length;
			
			outputData(tmpList);
		}
	}
	//�������ļ�¼tmpList���Ƶ�ԭ����˳��� pList
	for(int k=0; k<length; k++)    {
		pList->arr[k]  = tmpList.arr[(first+length+k) % length];
	}
}//---path2InsertSort 2·���� END






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
		printf( "\t%4d/%02d/%02d ����%1d \n", sysTime[0].wYear, sysTime[0].wMonth, sysTime[0].wDay,sysTime[0].wDayOfWeek);


		pFunc_sort[i](&list);

		GetLocalTime( &sysTime[1] );
		cout << funcName[i]<<", end time is:\n";
		printf( "\t%02d:%02d:%02d.%03d ", sysTime[1].wHour,sysTime[1].wMinute, sysTime[1].wSecond, sysTime[1].wMilliseconds);
		printf( "\t%4d/%02d/%02d ����%1d\n", sysTime[1].wYear, sysTime[1].wMonth, sysTime[1].wDay,sysTime[1].wDayOfWeek);



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

#define N 100 //���鳤��
#define M 20 //����ֽ�

���н��:
before:
[20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,
61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,
81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100]

insertSort, start time is:
        04:29:08.720    2002/01/01 ����2
insertSort, end time is:
        04:29:08.720    2002/01/01 ����2
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
        04:29:08.767    2002/01/01 ����2
shellSort, end time is:
        04:29:08.767    2002/01/01 ����2
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
�밴���������-> -> .


#define N 1000 //���鳤��
#define M 200 //����ֽ�

insertSort, start time is:
        04:31:14.284    2002/01/01 ����2
insertSort, end time is:
        04:31:14.284    2002/01/01 ����2
insertSort, runned time is :
        0 ms !


====================================================
shellSort, start time is:
        04:31:14.284    2002/01/01 ����2
shellSort, end time is:
        04:31:14.284    2002/01/01 ����2
shellSort, runned time is :
        0 ms !


====================================================



--------------------------------
Process exited after 0.04155 seconds with return value 0
�밴���������. . .



#define N 10000 //���鳤��
#define M 2000 //����ֽ�

���н��:

insertSort, start time is:
        04:32:29.118    2002/01/01 ����2
insertSort, end time is:
        04:32:29.118    2002/01/01 ����2
insertSort, runned time is :
        0 ms !


====================================================
shellSort, start time is:
        04:32:29.118    2002/01/01 ����2
shellSort, end time is:
        04:32:29.118    2002/01/01 ����2
shellSort, runned time is :
        0 ms !


====================================================



--------------------------------
Process exited after 0.04038 seconds with return value 0
�밴���������. . .



before:
[57,5,44,15,13,56,72,49,99,73]

insertSort, start time is:
        09:48:42.573    2019/06/04 ����2
insertSort, end time is:
        09:48:42.573    2019/06/04 ����2
insertSort, runned time is :
        0 ms !

after sort:
[62,5,13,15,44,49,56,62,72,73]

====================================================
before:
[57,5,44,15,13,56,72,49,99,73]

shellSort, start time is:
        09:48:42.576    2019/06/04 ����2
shellSort, end time is:
        09:48:42.576    2019/06/04 ����2
shellSort, runned time is :
        0 ms !

after sort:
[73,5,13,15,44,49,56,72,73,99]

====================================================
before:
[57,5,44,15,13,56,72,49,99,73]

binaInsertSort, start time is:
        09:48:42.580    2019/06/04 ����2
binaInsertSort, end time is:
        09:48:42.584    2019/06/04 ����2
binaInsertSort, runned time is :
        4 ms !

after sort:
[99,5,13,15,44,49,56,72,73,99]

====================================================
before:
[57,5,44,15,13,56,72,49,99,73]

path2InsertSort, start time is:
        09:48:42.629    2019/06/04 ����2
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
        09:48:42.672    2019/06/04 ����2
path2InsertSort, runned time is :
        43 ms !

after sort:
[5,13,15,44,49,56,57,72,73,99]

====================================================



--------------------------------
Process exited after 0.6031 seconds with return value 0
�밴���������. . .


*/
