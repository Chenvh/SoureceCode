/*
#include <queue>
���壺priority_queue<Type, Container, Functional>
Type �����������ͣ�
Container �����������ͣ�Container������������ʵ�ֵ�������
����vector,deque�ȵȣ��������� list,queue��STL����Ĭ���õ���vector����
Functional ���ǱȽϵķ�ʽ������Ҫ���Զ������������ʱ����Ҫ����������������
ʹ�û�����������ʱ��ֻ��Ҫ�����������ͣ�Ĭ���Ǵ����

���ȶ��о��ж��е��������ԣ���������������
��ͬ����:������ڲ���һ�����������ȼ��ߵ����ڶ���ǰ��,���ȳ���
���ǿ����Զ����������ݵ����ȼ�,
��������һ����ʵ�ֵ�

*/
#include "Person.h" 
#include "PersonCmp.h"
//ǰ������ 
void showPriorQueue(priority_queue<int>);

void testPriorityQueue(){
	Person pn[3] = {Person(), Person("Tom1", 24), Person("Tom2", 17)};
	
	//case 1:
	priority_queue<Person> pqObj;
	//��ͬ��
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
	//��ͬ�� 
	//priority_queue<int, vector<int>, less<int> >  pqi;
	
	//PS: ���Ͽո�,��ֹ����>>
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





