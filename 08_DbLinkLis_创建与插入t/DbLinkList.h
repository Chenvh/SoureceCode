#pragma once

#include "DbLinkNode.h"
/*
˫��ѭ�������� 
*/
class DbLinkList{
	
public:	//��Ա����


	DbLinkList(int =2020);//���캯��
	
	//���
	void showAll(); 
	void visitNode(DbLinkNode *);
	
	//��ֵΪv��Ԫ�ز�������ĵ�ǰ���cur֮�� 
	int insertTail(const int &v);
	
	
/*	//����������ֵΪy���½��
	//�����������������ֵΪx�Ľ�����
	int Insert(const Type &x, const Type &y);

	~DbLinkList( ); //��������
	int Length( ) const; //����ѭ��˫������ĳ���
	
	int IsEmpty( ) { return head->link==head; }
	//�ж�ѭ��˫�������Ƿ�Ϊ�ձ�
	
	int Find(const Type &x);
	//��ѭ��˫������������������Ϊ����ֵ�Ľ��
	
	int Head( ); //��λ�ڱ�ͷ���
	
	int Next( ); //��λ�ڵ�ǰ���ĺ�̽��
	
	int Prior( ); //��λ�ڵ�ǰ����ǰ�����
	
	
	
	int Delete(const Type &x); //ɾ��������ֵΪx�Ľ��
*/	 
private:
	DbLinkNode *head; //��ͷָ��
	DbLinkNode * cur;//��ǰ��� 
};
