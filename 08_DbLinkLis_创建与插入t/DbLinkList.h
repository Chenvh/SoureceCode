#pragma once

#include "DbLinkNode.h"
/*
双向循环链表定义 
*/
class DbLinkList{
	
public:	//成员函数


	DbLinkList(int =2020);//构造函数
	
	//输出
	void showAll(); 
	void visitNode(DbLinkNode *);
	
	//将值为v的元素插入链表的当前结点cur之后 
	int insertTail(const int &v);
	
	
/*	//建立数据域值为y的新结点
	//并将其插入至数据域值为x的结点后面
	int Insert(const Type &x, const Type &y);

	~DbLinkList( ); //析构函数
	int Length( ) const; //计算循环双向链表的长度
	
	int IsEmpty( ) { return head->link==head; }
	//判断循环双向链表是否为空表
	
	int Find(const Type &x);
	//在循环双向链表搜索其数据域为给定值的结点
	
	int Head( ); //定位于表头结点
	
	int Next( ); //定位于当前结点的后继结点
	
	int Prior( ); //定位于当前结点的前驱结点
	
	
	
	int Delete(const Type &x); //删除数据域值为x的结点
*/	 
private:
	DbLinkNode *head; //表头指针
	DbLinkNode * cur;//当前结点 
};
