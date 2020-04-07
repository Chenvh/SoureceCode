#pragma once
/*
SqQueueCy˳��ѭ������ (Squence Circular Queue) ģ�� 
 ��Ŷ��е�������Ϊ��β�����ı�
 ���в���ʱҪ���ȡģ(����)���㡣
�C ����: front = (front+1) % size;
�C ����: rear = (rear+1) % size;
�C ���г�ʼ���� front = rear = 0;
�C �ӿ������� front == rear;
�C ���������� (rear+1) % size == front
�� ����(Ԫ�ظ���)����rear-front+size)%size  

˵��
�ڵ������״̬ʱ��ʵ�ʻ���һ�����д洢��Ԫ��
������������Ԫ���У�������Ͷӿյ�״̬���� front == rear

*/
#include "..\comm.h"

template<typename T>
class SqQueueCy{
public:
	//����: front = (front+1) % size;
	bool deQueue(T& e){
		//�Ϸ�����֤
		if(isEmpty()){
			cerr<<"Queue Empty Error!";
			return false;//exit(1);
		} 
		e = *(base+front);
		front = (front+1) % size;
		return true;
	}
	
	// ����: rear = (rear+1) % size;
	bool enQueue(T e){
		if( isFull()){
			reSize();
			//return false;
		} 
		
		*(base+rear) = e;
		
		rear = (rear+1) % size;
		
		return true;		
	} 
	
	//��������ռ� 
	bool reSize(){
		cout << "Not enough space, reallocation doubled" << endl;
		
		T*	newBase=new T[size*2];
		if(newBase==NULL){
			return false;
		}
		for(int i=0; i<size-1; i++){
			//*(newBase+i)=* (base+(front+i)%size);//��ͬ����һ�д��� 
			newBase[i] = base[(front+i)%size]; 
		}			
		delete[]base;
		
		base=newBase;
		front=0;
		rear=size-1;
		size*=2;
		
		return true;
	} 
	
	//���캯���C ���г�ʼ���� front = rear = 0;
	SqQueueCy(int n = 1){
		base = new T[n] ;
		assert(base != NULL);
		front = rear = 0;
	   size = n; 
	} 
	
	// �ӿ������� front == rear;
	bool isEmpty(){
		return front == rear;
	}
	
	// ���������� (rear+1) % size == front
	bool isFull(){
		return (rear+1) % size == front;
	}
	
	// Ԫ�ظ�������rear-front+size)%size	
	int getLength(){
		
		return (rear-front+size)%size; 
		
	}
	
	//��ȡ����Ԫ��
	bool getFront(T &e)const
	{
		if(isEmpty()){
			return false;
		}
					
		e=*(base+front);
		return true;
	}


	
	// ����
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
	
	//�������� 
	~SqQueueCy()
	{
		delete[]base;base=NULL; 
	}
	//��նӿ� 
	void ClearQueue()
	{
		front=rear=0;
	}

	
//private:
protected: //��ǰ�༰��������Է��� 
	T* base ;
	int front,rear;//frontָ�������Ԫ��,rearָ���βԪ�ص���һ��λ�� 
	int size;//�ռ��С 
	
	
};


/*
TestCase

true
size=8: [A,B,C,]
Not enough space, reallocation doubled
size=16: [A,B,C,D,E,F,G,H,I,J,]

--------------------------------
Process exited after 0.6214 seconds with return value 0
�밴���������. . .
 
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
