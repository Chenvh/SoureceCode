#pragma once

#include "comm.h"

/*
left_clue=0�� leftΪ����Ůָ��
left_clue=1�� leftΪǰ������
right_clue=0�� rightΪ����Ůָ��
right_clue=1�� rightΪ������� 
*/

//�¶���ö������,ϵͳĬ��ֵ�Ǵ�0��ʼ ,ö��enum��int���� 
typedef enum{
	Child, Thread
}EnumThread; 

//Forward declaration ǰ������ 

template <typename Type>
class ThreadNode{
public:
	Type m_data;
	EnumThread left_clue,right_clue;
	ThreadNode* mp_left;
	ThreadNode* mp_right;

	//���캯��:��ʼ��
	
	//�ս��,Ĭ��EnumThreadΪThread ,ǰ�����ָ������ 
	ThreadNode():left_clue(Thread), right_clue(Thread), 
			mp_left(this),mp_right(this){
	}
	
	//���ɵ��½��,�½������Һ��ӽ�Ϊ�ս�� 
	ThreadNode(Type data):m_data(data),left_clue(Child), right_clue(Child),
	 mp_left(NULL),mp_right(NULL){
	}
		
	
	//�������:��ʾ [NULL,Child,data,Child,NULL]
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

