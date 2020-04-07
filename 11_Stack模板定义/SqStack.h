#pragma once
#include "..\comm.h"
/*
��ģ��
˳��ջ 

 #include <assert.h>  void assert( int exp ); 
 ���ܣ� ��assert()���ڴ����⡣
 ������ʽ�Ľ��Ϊ�㣬��д������Ϣ��STDERR���˳�����ִ�С�
 �����NDEBUG�Ѿ����壬��assert()�������ԡ� 
 assert(base != NULL);
��ͬ�� 
if(base == NULL){
	cerr << "error memory!" <<endl;
	exit(1);
}
		
*/

template <typename T>
class SqStack{
private:
	T * base;//ջ��ָ��
	T * top;//ջ��ָ��
	int size;//�ռ��С 
public:
	//���캯��
	SqStack(int n=3){
		base = new T[3];
		assert(base != NULL);
		
		top = base;
		size = n;
		
	} 
	
	//��ջ,��Ԫ��e����ջ��,topָ��ջ��Ԫ�ص���һ��λ�� 
	void push(T e){
		if( isFull()){
			reSize();
		}
		*top ++  = e;//��ͬ��*top = e;		top ++;
		 
	}
	
	//��ջ 
	void pop(T &e){
		assert(!isEmpty()) ;
		e = *--top; //top --;		e =  *top;
		
	}
	
	
	//�жϿ�
	bool isEmpty(){
		return (top == base);
	} 
	
	//�ռ��Ƿ�����
	bool isFull(){
		return top-base >= size;	
	}
	
	
	//�����ռ�: ��1���ٶ�����,�ÿռ�Ϊ2*size 
	void reSize(){
		cout << "Memory reApply!\n";
		T *pTmp , *q, *p ;
		//step1:�������� 
		pTmp = new T[2*size];//���·���2*size���ռ�
		assert(pTmp != NULL);
		
		//step2: ����
		for( p = base, q = pTmp; p<top; ){
			*q++ = *p ++;
			//pTmp[i++] = *p;
		}//loop ending, p == top 
		
		//step3:update
		delete[]base;//�ͷ�ԭ�����ڴ� 
		base = pTmp;
		top = q;
		size *= 2;		
	} // ====reSize() ending
	
	
	
	
	//const:read���� 
	void traverse()const{
		cout << "size=" << size << ":";
		T *p;
		cout << "[";
		for( p=base; p < top; p++){
			visit(*p);
		} 
		cout << "]";
	}// end of traverse
	
	void visit(T obj)const{
		cout << obj << ",";
	}
	
	~SqStack(){
		delete[]base; base=NULL; top=NULL;
	}
}; 



