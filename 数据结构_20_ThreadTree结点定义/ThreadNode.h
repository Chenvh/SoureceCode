#pragma once

#include "comm.h"
/*
ltag=0�� leftΪ����Ůָ��
ltag=1�� leftΪǰ������
rtag=0�� rightΪ����Ůָ��
rtag=1�� rightΪ������� 
*/

//�¶���ö������,ϵͳĬ��ֵ�Ǵ�0��ʼ ,ö��enum��int���� 
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
	//���캯��:��ʼ��
	
	//�ս��,Ĭ��TagΪThread ,ǰ�����ָ������ 
	ThreadNode():ltag(Thread), rtag(Thread), mp_left(this),mp_right(this){
	}
	
	//���ɵ��½��,�½������Һ��ӽ�Ϊ�ս�� 
	ThreadNode(Type data):m_data(data),ltag(Child), rtag(Child),
	 mp_left(NULL),mp_right(NULL){
	}
		
	
	//�������:��ʾ [NULL,Child,data,Child,NULL]
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

