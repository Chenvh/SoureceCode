#pragma once
#include "Cpp.h" 
/*双循环链表结点类 
*/

//前置声明
class DbLinkList; 

class DbLinkNode{
private:
	int data;//数据域 
	DbLinkNode * lLink, * rLink; //left link前驱,right link后继 
public:	
	
	//将DbLinkList声明为友元类,意味着 类DbLinkList 可以访问本类所有成员 
	friend class DbLinkList; 
	 
	//构造函数
	// 将值为v的元素封底为结点 
	DbLinkNode(int v=2020):data(v), lLink(NULL), rLink(NULL){
		//data = v; lLink = rLink = NULL; 
	}
	
	DbLinkNode(int v, DbLinkNode* leftPointer, DbLinkNode * rightPointer )
	:data(v), rLink(rightPointer), lLink(leftPointer){
		//data = v; lLink = leftPointer; rLink = rightPointer; 
	}
	
	int getData(){
		return data;
	}
	
};
