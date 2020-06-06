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
#define MAX_SIZE

typedef int Status;

typedef struct {
	Elem arr[N+1];	//���ڴ洢Ҫ����˳���arr[0]�����ڱ�����ʱ����
	int length;		// ���ڼ�¼˳���ĳ���

} SqList;




//����ǰ������
void mergeSort_V1(SqList &list);
void mergeSort_V2(SqList &list);

/*����ָ��
@param pList:SqList &lis 
*/
void (*pFunc_sort[F_SIZE])(SqList &list) = {mergeSort_V1, mergeSort_V2};
string funcName[F_SIZE] = {"mergeSort_V1", "mergeSort_V2"};




// ����list.������arr���±�Ϊi��j��ֵ
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
		if(!((i+1)%COL)) {
			printf("\n");
		}

	}
	printf("\n");
}




/* mergeListFrom2Block �ϲ�����orign��2�� �� ���� dest��1��
�������orign[left..mid] �� orign[mid+1..n]�鲢Ϊ����� dest[left..right]
@param orign:ԭʼ����
@param dest: Ŀ������
@param left: �������
@param mid: �����ж�
@param right: �����Ҷ�
*/
void mergeListFrom2Block(int orign[],int dest[],int left,int mid,int right) {
	int two,first;//first,two�ֱ��ʾ2��������±�

	//��orign�м�¼��С����ز���dest

	//�ڶ������һ�����αȽ�
	for(two=mid+1, first=left; left<=mid && two<=right; first++) {

		if (orign[left]<orign[two]) { //��1���е�С
			dest[first]=orign[left++];
		} else { //��2���и�С
			dest[first]=orign[two++];
		}

	}//loop end,left>mid �� two>right

	int surplus; //��ʶʣ���

	//��1�黹��ʣ���
	if(left<=mid) { // ��ʱ,two > right.����2��������

		for(surplus=0; surplus<=mid-left; surplus++) { //��ʣ���orign[left..mid]���Ƶ�dest
			dest[first+surplus]=orign[left+surplus];
		}

	} else { //��ʱ, left>mid,��1��������, �� two <= right ����2�黹��ʣ���
		if(two<=right) {
			for(surplus=0; surplus<=right-two; surplus++)
				dest[first+surplus]=orign[two+surplus];		/* ��ʣ���orign[two..right]���Ƶ�dest */
		}
	} //end if,surplus�������

}//---mergeListFrom2Block �ϲ�����orign��2�� �� ���� dest��1�� END


/* �ݹ鷨
��orign[begin..end]�鲢����Ϊ�������� dest[begin..end]
@param orign:ԭʼ����
@param dest: Ŀ������

@param begin: ���
@param end:�յ�
*/
void sortMgRecursion(int orign[],int dest[],int begin, int end) {
	int mid;
	int tmpArr[N+1];
	if(begin == end) { //ֻ��1��Ԫ��
		dest[begin]=orign[begin];
	} else {
		//��orign[begin..end]ƽ��Ϊorign[begin..mid]��orign[mid+1..end]
		mid=(begin+end)/2;

		//�ݹ�ؽ�orign[begin..mid]�鲢Ϊ �������е�tmpArr[begin..mid]
		sortMgRecursion(orign, tmpArr, begin, mid);

		//�ݹ�ؽ�orign[mid+1..end]�鲢Ϊ�����tmpArr[mid+1..end]
		sortMgRecursion(orign, tmpArr, mid+1, end);

		//��tmpArr[begin..mid]��tmpArr[mid+1..end] �鲢�� dest[begin..end]
		mergeListFrom2Block(tmpArr, dest, begin, mid, end);
	}
}

/* �ݹ鷨 
��˳���list���鲢���� 
*/
void mergeSort_V1(SqList &list) {
	sortMgRecursion(list.arr, list.arr, 1, list.length);
}

/* �ǵݹ鷨
��orign[]�����ڿ��Ϊspan�������������鲢��dest[]
*/
void mergeListBySpan(int orign[],int dest[], int span, int n) {
	int i;

	for (i=1; i <= n-2*span+1; i += 2*span) {

		//��orgin��[i,i+span-1] �� [i+span, i+2*span-1] �ϲ��� dest[i, i+2*span-1]
		mergeListFrom2Block(orign, dest, i, i+span-1, i+2*span-1);
	}//loop end, i>n-2*span+1


	if(i<n-span+1) { //����2��������, �鲢�����������
		//��orgin��[i,i+span-1] �� [i+span, n] �ϲ��� dest[i, n]
		mergeListFrom2Block(orign, dest, i, i+span-1, n);
	}

	else { //ֻ����1��������
		for(int j=i; j <= n; j++) {
			dest[j] = orign[j];
		}

	}

}

/*
��˳���L���鲢�ǵݹ�����
*/
void mergeSort_V2(SqList &list) {
	
	//tmpArr����ռ����list��length�൱ 
	Elem* tmpArr=(Elem*)malloc(list.length * sizeof(Elem));
	
	int k=1;

	for(k=1; k<list.length; ) {

		//��list�����鰴���Ϊk�ϲ�������tmpArr��
		mergeListBySpan(list.arr, tmpArr, k, list.length);

		k *= 2;	//�����г��ȼӱ�

		//������tmpArr�����Ϊk�ϲ���list������arr��
		mergeListBySpan(tmpArr, list.arr, k, list.length);

		k *= 2;	//�����г��ȼӱ�
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
[39,42,34,41,50,99,55,25,19,79,8,61,87,45,56,68,44,30,13,
40,91,8,89,99,58,90,50,15,56,82,75,18,57,70,0,19,75,56,44,
31,17,64,64,68,31,75,87,85,26,5,88,38,13,3,40,23,64,59,49,
43,97,39,62,19,36,71,3,42,84,2,7,19,2,91,8,41,67,46,95,
4,6,74,21,53,47,99,77,22,95,91,15,61,7,72,96,4,10,2,35]


mergeSort_V1, start time is:
        16:38:25.635    2019/06/10 ����1
mergeSort_V1, end time is:
        16:38:25.635    2019/06/10 ����1
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
        16:38:25.663    2019/06/10 ����1
mergeSort_V2, end time is:
        16:38:25.664    2019/06/10 ����1
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
�밴���������. . .

*/
