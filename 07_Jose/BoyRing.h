#ifndef BOYRING_H_2020
#define  BOYRING_H_2020
/*Josephus约瑟夫问题
BoyRing类的声明 
*/
/*结点 
*/
class Boy{
public:
	int code;//编号 
	Boy* next;//后继 

};
/*
循环链表 
*/
class BoyRing{
private:
	Boy* head, * cur, * pre;//头, 当前, 当前结点的前驱 
public:
	//构造函数:初始化对象
	BoyRing(int); 
	
	//遍历循环链表,输出 
	void showAll();
	
	//数m个数 ,使得cur指向第m个结点 
	void countNum(int m); 
	
	//获取当前结点的编号
	int getCodeCur(); 
	
	//删除:将当前结点从环中删除 
	void delNode(); 
	
	//析构函数
	~BoyRing(); 
	
}; 

#endif // BOYRING_H_2020
