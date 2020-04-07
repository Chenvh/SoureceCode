/*
#include <queue>
定义：priority_queue<Type, Container, Functional>
Type 就是数据类型，
Container 就是容器类型（Container必须是用数组实现的容器，
比如vector,deque等等，但不能用 list,queue。STL里面默认用的是vector），
Functional 就是比较的方式，当需要用自定义的数据类型时才需要传入这三个参数，
使用基本数据类型时，只需要传入数据类型，默认是大根堆

优先队列具有队列的所有特性，包括基本操作，
不同的是:添加了内部的一个排序，让优先级高的排在队列前面,优先出队
我们可以自定义其中数据的优先级,
它本质是一个堆实现的

*/
#include "Person.h" 
#include "PersonCmp.h"
//前置声明 
void showPriorQueue(priority_queue<int>);

void testPriorityQueue(){
	Person pn[3] = {Person(), Person("Tom1", 24), Person("Tom2", 17)};
	
	//case 1:
	priority_queue<Person> pqObj;
	//等同于
	//priority_queue<Person, vector<Person> , less<Person> > pqObj; 
	
	//case 2:
	priority_queue<Person, vector<Person>, greater<Person> > pqObj2;
	
	//case 3: class bind
	priority_queue<Person, vector<Person>, PersonCmp> pqObj3;
	
	for(int i=0; i<3; i++){
		pqObj.push(pn[i]);
		pqObj2.push(pn[i]);
		pqObj3.push(pn[i]);
	}


	while(! pqObj3.empty()){
		Person e = pqObj3.top();
		cout << e << ",";
		pqObj3.pop();
	}
	cout << endl;


	while(! pqObj2.empty()){
		Person e = pqObj2.top();
		cout << e << ",";
		pqObj2.pop();
	}
	cout << endl;
	
	while(! pqObj.empty()){
		Person e = pqObj.top();
		cout << e << ",";
		pqObj.pop();
	}
	
	
	
	priority_queue<int> pqi;	
	//等同于 
	//priority_queue<int, vector<int>, less<int> >  pqi;
	
	//PS: 加上空格,防止出现>>
	priority_queue<int, vector<int> , greater<int>  > pqi2;
	
	
	
	for(int i=0; i<5; i++){
		pqi.push(rand()%100);
		pqi2.push(rand()%100); 
	}
	
	showPriorQueue(pqi);
	//showPriorQueue(pqi2);
	while(! pqi2.empty()){
		int e = pqi2.top();
		cout << e << ",";
		pqi2.pop();
	}
} 

void showPriorQueue(priority_queue<int> q){
	int e;
		cout << "[";
		while(! q.empty()){
			e = q.top();
			visit(e);
			 cout << ",";			
			q.pop();
			
		}
		cout << "]";
		cout << endl;	
}





