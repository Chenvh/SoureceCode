#ifndef _BINTNODE_HH_2016
#define _BINTNODE_HH_2016

#include "comm.h"


/*#pragma once
Binary Tree Node Template
�����������ģ�� 
*/
template <typename T>
class BinTNode{
public:
	//PS: m��ʾ�ñ���Ϊ��Ա(member)���� 
	T m_data;
	BinTNode * m_left;//���� 
	BinTNode * m_right;// �Һ��� 
	
	//���캯��,�ó�ʼ���б�ʽ��ֵ 
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
