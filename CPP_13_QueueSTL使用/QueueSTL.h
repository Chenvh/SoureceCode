#pragma once
/*STL 队列应用
queue
back() 返回最后一个元素 
empty() 如果队列空则返回真 
front() 返回第一个元素 
pop() 删除第一个元素 
push() 在末尾加入一个元素 
size() 返回队列中元素的个数 
 
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
	
	//遍历双端队列 
	void showDQ(DQI dq){
		//for_each遍历范围 [begin(), end() ) 
		//for_each(dq.begin(), dq.end(),  visit); 
		
		
		//迭代器 
		DQI::iterator it; //it是指针
		cout<<"["; 
		for(it = dq.begin(); it != dq.end(); ++it){
			visit(*it);
			
			(it != dq.end()-1 ) ? cout << "," : cout<<"]"; 
		}
		cout << endl;
		
		//下标法:
		cout<<"["; 
		for(int i=0; i< dq.size(); i++){
			visit(dq.at(i));
			
			i != dq.size()-1? cout << "," : cout << "]";
			
		} 
		
		cout << endl;
	}
	
	/*
	打印杨辉三角 , n行 
	0 1 1  0 1 2 1 0 1 3 3 1 0 1 4 6 4 1 
	0 1 5 10 10 5 1
	每行以0开始 
	
	利用队列打印二项展开式系数的程序 
	Binomial expansion coefficient

	TestCase:
	
	1 1
	1 2 1
	1 3 3 1
	
	--------------------------------
	Process exited after 0.5717 seconds with return value 0
请按任意键继续. . .

	*/
	void printYanghui(int n){
		int first, last, coe = 0; //队首,队尾,系数
		
		int cur, next;//当前行号,下一行数
		
		QI qi;
		qi.push(1); qi.push(1) ;
		
		
		//[1,1, 0,1,2,1,0,1]
		for(cur = 1; cur <= n; cur++){//行数
		  //打印当前行cur
		  
		  qi.push(0);//0作该行的起始值 
		  	
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

	//输出队列
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


