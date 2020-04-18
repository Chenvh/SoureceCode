#pragma once

#include "comm.h"

/*
left_clue=0， left为左子女指针
left_clue=1， left为前驱线索
right_clue=0， right为右子女指针
right_clue=1， right为后继线索 
*/

//新定义枚举类型,系统默认值是从0开始 ,枚举enum是int特例 
typedef enum{
	Child, Thread
}EnumThread; 

//Forward declaration 前置声明 

template <typename Type>
class ThreadNode{
public:
	Type m_data;
	EnumThread left_clue,right_clue;
	ThreadNode* mp_left;
	ThreadNode* mp_right;

	//构造函数:初始化
	
	//空结点,默认EnumThread为Thread ,前驱后继指向自身 
	ThreadNode():left_clue(Thread), right_clue(Thread), 
			mp_left(this),mp_right(this){
	}
	
	//生成的新结点,新结点的左右孩子皆为空结点 
	ThreadNode(Type data):m_data(data),left_clue(Child), right_clue(Child),
	 mp_left(NULL),mp_right(NULL){
	}
		
	
	//输出函数:显示 [NULL,Child,data,Child,NULL]
	void show(){
		cout <<"[";
		mp_left? cout << mp_left->m_data : cout<< "NULL";
		cout <<","<< left_clue << ",";
		cout << m_data << ",";
		cout << right_clue << ",";
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

