#include "SLinkList.h"

//test
int main(){
	//SLinkList Test
	SLinkList list;// 创建空表
	
	//boolalpha : 将bool打印成 true false 
	cout << boolalpha << list.isEmpty() << endl;
	
	list.showList(); 
	
	list.addToHead(11);
	list.showList();
	cout << boolalpha << list.isEmpty() << endl;
	
	
	
	cout << endl << endl;
	//SLinkNode Test
	SLinkNode node;//创建空对象 
	node.show(); 
	
	

	SLinkNode node2(11);//创建对象并初始化 
	node2.show(); 
	
	return 0;
}
