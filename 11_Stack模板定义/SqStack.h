#pragma once
#include "..\comm.h"
/*
类模板
顺序栈 

 #include <assert.h>  void assert( int exp ); 
 功能： 宏assert()用于错误检测。
 如果表达式的结果为零，宏写错误信息到STDERR并退出程序执行。
 如果宏NDEBUG已经定义，宏assert()将被忽略。 
 assert(base != NULL);
等同于 
if(base == NULL){
	cerr << "error memory!" <<endl;
	exit(1);
}
		
*/

template <typename T>
class SqStack{
private:
	T * base;//栈底指针
	T * top;//栈顶指针
	int size;//空间大小 
public:
	//构造函数
	SqStack(int n=3){
		base = new T[3];
		assert(base != NULL);
		
		top = base;
		size = n;
		
	} 
	
	//入栈,将元素e放入栈中,top指向栈顶元素的下一个位置 
	void push(T e){
		if( isFull()){
			reSize();
		}
		*top ++  = e;//等同于*top = e;		top ++;
		 
	}
	
	//出栈 
	void pop(T &e){
		assert(!isEmpty()) ;
		e = *--top; //top --;		e =  *top;
		
	}
	
	
	//判断空
	bool isEmpty(){
		return (top == base);
	} 
	
	//空间是否已满
	bool isFull(){
		return top-base >= size;	
	}
	
	
	//增长空间: 按1倍速度增加,让空间为2*size 
	void reSize(){
		cout << "Memory reApply!\n";
		T *pTmp , *q, *p ;
		//step1:重新申请 
		pTmp = new T[2*size];//重新分配2*size个空间
		assert(pTmp != NULL);
		
		//step2: 拷贝
		for( p = base, q = pTmp; p<top; ){
			*q++ = *p ++;
			//pTmp[i++] = *p;
		}//loop ending, p == top 
		
		//step3:update
		delete[]base;//释放原来的内存 
		base = pTmp;
		top = q;
		size *= 2;		
	} // ====reSize() ending
	
	
	
	
	//const:read操作 
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



