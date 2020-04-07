#pragma once


#include "SqQueueCy.h"

template<typename T>
class DeQueueCy : public SqQueueCy<T>{ //继承 
public:
	
	DeQueueCy(int n=1):SqQueueCy<T>(n)
	{
	}
	
	//获取队尾元素
	bool getRear(T &e)const
	{
		if(this->isEmpty()){
			return false;
		}
					
		e = *(this->base+( this->rear- 1 + this->size )% this->size);
		return true;
	} 
	
	//入队(增)
	bool enQueueAtFront(T e){
		if(this-> isFull()){
			this->reSize();
			//return false;
		} 
		
		this->front = (this->front-1+this->size)%this->size;
		
		*(this->base+this->front) = e;  //base[front] = e;
		
		return true;		
	} 
	
	//出队
	bool deQueueAtRear(T& e){
		//合法性验证
		if(this->isEmpty()){
			cerr<<"Queue Empty Error!";
			return false;//exit(1);
		} 
		this->rear =(this->rear-1+this->size)% this->size;
		e = *(this->base+this->rear);
		return true;
	} 
	
 
};

void testDeQueueCy(){
	DeQueueCy<int>  queue(8);
	cout << boolalpha << queue.isEmpty() << endl;
	for(int i=1; i<=3; i++){
		queue.enQueue( i);
		queue.enQueueAtFront(2*i);
		
	}	
	queue.traverse();
}
