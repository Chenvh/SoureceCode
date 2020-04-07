#pragma once
/*
SqQueueCy顺序循环队列 (Squence Circular Queue) 模板 
 存放队列的数组作为首尾相连的表。
 队列操作时要配合取模(余数)运算。
– 出队: front = (front+1) % size;
– 进队: rear = (rear+1) % size;
– 队列初始化： front = rear = 0;
– 队空条件： front == rear;
– 队满条件： (rear+1) % size == front
－ 长度(元素个数)：（rear-front+size)%size  

说明
在到达队满状态时，实际还有一个空闲存储单元。
如果不让这个单元空闲，则队满和队空的状态都是 front == rear

*/
#include "..\comm.h"

template<typename T>
class SqQueueCy{
public:
	//出队: front = (front+1) % size;
	bool deQueue(T& e){
		//合法性验证
		if(isEmpty()){
			cerr<<"Queue Empty Error!";
			return false;//exit(1);
		} 
		e = *(base+front);
		front = (front+1) % size;
		return true;
	}
	
	// 进队: rear = (rear+1) % size;
	bool enQueue(T e){
		if( isFull()){
			reSize();
			//return false;
		} 
		
		*(base+rear) = e;
		
		rear = (rear+1) % size;
		
		return true;		
	} 
	
	//重新申请空间 
	bool reSize(){
		cout << "Not enough space, reallocation doubled" << endl;
		
		T*	newBase=new T[size*2];
		if(newBase==NULL){
			return false;
		}
		for(int i=0; i<size-1; i++){
			//*(newBase+i)=* (base+(front+i)%size);//等同于下一行代码 
			newBase[i] = base[(front+i)%size]; 
		}			
		delete[]base;
		
		base=newBase;
		front=0;
		rear=size-1;
		size*=2;
		
		return true;
	} 
	
	//构造函数– 队列初始化： front = rear = 0;
	SqQueueCy(int n = 1){
		base = new T[n] ;
		assert(base != NULL);
		front = rear = 0;
	   size = n; 
	} 
	
	// 队空条件： front == rear;
	bool isEmpty(){
		return front == rear;
	}
	
	// 队满条件： (rear+1) % size == front
	bool isFull(){
		return (rear+1) % size == front;
	}
	
	// 元素个数：（rear-front+size)%size	
	int getLength(){
		
		return (rear-front+size)%size; 
		
	}
	
	//获取队首元素
	bool getFront(T &e)const
	{
		if(isEmpty()){
			return false;
		}
					
		e=*(base+front);
		return true;
	}


	
	// 遍历
	void traverse(){
		int i;
		
		cout <<"size="<<size<< ": [";
		for(i=front; i!= rear; i = ++i % size){
			visit(base[i]);
			cout << ",";
		}
		cout <<"]" << endl;
	} 
	
	void visit(T e){
		cout << e;
	}
	
	//析构函数 
	~SqQueueCy()
	{
		delete[]base;base=NULL; 
	}
	//清空队空 
	void ClearQueue()
	{
		front=rear=0;
	}

	
//private:
protected: //当前类及派生类可以访问 
	T* base ;
	int front,rear;//front指向队列首元素,rear指向队尾元素的下一个位置 
	int size;//空间大小 
	
	
};


/*
TestCase

true
size=8: [A,B,C,]
Not enough space, reallocation doubled
size=16: [A,B,C,D,E,F,G,H,I,J,]

--------------------------------
Process exited after 0.6214 seconds with return value 0
请按任意键继续. . .
 
*/
void testSqQueueCy(){
	SqQueueCy<char>  queue(8);
	cout << boolalpha << queue.isEmpty() << endl;
	for(int i=0; i<3; i++){
		queue.enQueue( (char) ('A'+ i));
		
	}	
	queue.traverse();
	
	for(int i=3; i<10; i++){
		queue.enQueue( (char) ('A'+ i));
		
	}	
	queue.traverse();
	
}
