#pragma once
/*STL ����Ӧ��
queue
back() �������һ��Ԫ�� 
empty() ������п��򷵻��� 
front() ���ص�һ��Ԫ�� 
pop() ɾ����һ��Ԫ�� 
push() ��ĩβ����һ��Ԫ�� 
size() ���ض�����Ԫ�صĸ��� 
 
*/
#include "..\Comm.h"
void visit(int e){
	cout << e << " ";
}
typedef queue<int> QI;
typedef deque<int> DQI;
class QueueSTL{
public:
	
	void testDeque(){
		DQI dqi;
		for(int i=0; i<5; i++){
				dqi.push_back(20+i);
				dqi.push_front(2*i);
		}
		showDQ(dqi);
	}
	
	//����˫�˶��� 
	void showDQ(DQI dq){
		//for_each������Χ [begin(), end() ) 
		//for_each(dq.begin(), dq.end(),  visit); 
		
		
		//������ 
		DQI::iterator it; //it��ָ��
		cout<<"["; 
		for(it = dq.begin(); it != dq.end(); ++it){
			visit(*it);
			
			(it != dq.end()-1 ) ? cout << "," : cout<<"]"; 
		}
		cout << endl;
		
		//�±귨:
		cout<<"["; 
		for(int i=0; i< dq.size(); i++){
			visit(dq.at(i));
			
			i != dq.size()-1? cout << "," : cout << "]";
			
		} 
		
		cout << endl;
	}
	
	/*
	��ӡ������� , n�� 
	0 1 1  0 1 2 1 0 1 3 3 1 0 1 4 6 4 1 
	0 1 5 10 10 5 1
	ÿ����0��ʼ 
	
	���ö��д�ӡ����չ��ʽϵ���ĳ��� 
	Binomial expansion coefficient

	TestCase:
	
	1 1
	1 2 1
	1 3 3 1
	
	--------------------------------
	Process exited after 0.5717 seconds with return value 0
�밴���������. . .

	*/
	void printYanghui(int n){
		int first, last, coe = 0; //����,��β,ϵ��
		
		int cur, next;//��ǰ�к�,��һ����
		
		QI qi;
		qi.push(1); qi.push(1) ;
		
		
		//[1,1, 0,1,2,1,0,1]
		for(cur = 1; cur <= n; cur++){//����
		  //��ӡ��ǰ��cur
		  
		  qi.push(0);//0�����е���ʼֵ 
		  	
		  	for(next = 1; next <= cur+2; next++){
			 	first = qi.front();
				qi.pop();
				 
				last = first + coe;
				qi.push(last);
				coe = first;
				if(next != cur+2){
					cout << coe << " ";
				}			
			
			}	  
					
		  cout << endl;
		}
		
		 
		
	} 
	
	void testQueue(){
		QI iQ;
		
		for(int i=0; i<5; i++){
			iQ.push(rand()%100);
		}
	
		showQueue(iQ);
		
	}	

	//�������
	void showQueue( QI q ){
		int e;
		cout << "[";
		while(! q.empty()){
			e = q.front();
			visit(e);
			 cout << ",";			
			q.pop();
			
		}
		cout << "]";
		cout << endl;		
	} 

	
};


