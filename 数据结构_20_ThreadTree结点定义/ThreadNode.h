#pragma once

#include "comm.h"
/*
ltag=0， left为左子女指针
ltag=1， left为前驱线索
rtag=0， right为右子女指针
rtag=1， right为后继线索 
*/

//新定义枚举类型,系统默认值是从0开始 ,枚举enum是int特例 
typedef enum{
	Child, Thread
}Tag; 

template <typename Type>
class ThreadNode{
private: 
	Type m_data;
	Tag ltag,rtag;
	ThreadNode* mp_left;
	ThreadNode* mp_right;
public:
	//构造函数:初始化
	
	//空结点,默认Tag为Thread ,前驱后继指向自身 
	ThreadNode():ltag(Thread), rtag(Thread), mp_left(this),mp_right(this){
	}
	
	//生成的新结点,新结点的左右孩子皆为空结点 
	ThreadNode(Type data):m_data(data),ltag(Child), rtag(Child),
	 mp_left(NULL),mp_right(NULL){
	}
		
	
	//输出函数:显示 [NULL,Child,data,Child,NULL]
	void show(){
		cout <<"[";
		mp_left? cout << mp_left->m_data : cout<< "NULL";
		cout <<","<< ltag << ",";
		cout << m_data << ",";
		cout << rtag << ",";
		mp_right? cout << mp_right->m_data : cout << "NULL";	
		cout << "]";
		cout << endl;
	} 
};

void testThreadNode(){
	ThreadNode<char>* pnode1 = new ThreadNode<char>;
	ThreadNode<char> node2('A');
	
	pnode1->show();
	node2.show();
}

