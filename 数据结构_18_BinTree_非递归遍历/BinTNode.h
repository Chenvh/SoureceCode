#ifndef _BINTNODE_HH_2016
#define _BINTNODE_HH_2016

#include "comm.h"


/*#pragma once
Binary Tree Node Template
二叉树结点类模板 
*/
template <typename T>
class BinTNode{
public:
	//PS: m表示该变量为成员(member)变量 
	T m_data;
	BinTNode * m_left;//左孩子 
	BinTNode * m_right;// 右孩子 
	
	//构造函数,用初始化列表方式赋值 
	BinTNode(): m_left(NULL), m_right(NULL){
	}
	BinTNode(T data):m_data(data),m_left(NULL), m_right(NULL){
	}
	
	void show()	const{
		cout << m_data; 
	}
	
};

void testBinTNode(){
	//BinTNode<int>* t_node = new BinTNode<int>;
	BinTNode<string>* t_node = new BinTNode<string>("k0");
	t_node->show();
	cout << endl;
}


#endif
