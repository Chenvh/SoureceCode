/*BoyRing类的实现 
*/
#include "BoyRing.h"
#include "Cpp.h" 

	
//删除:将当前结点从环中删除 
void BoyRing::delNode(){
	pre->next = cur->next;
	delete cur;
	cur = pre;//回到初始状态(二者指向同一个结点) 
}


//获取当前结点的编号
int BoyRing:: getCodeCur(){
	return cur->code;
}
	


/*
数m个数 ,使得cur指向第m个结点,pre是cur的前驱的位置关系不能更改 
*/
void BoyRing::countNum(int m){
	
	//后移m次,cur初始时指向的是最后一个结点 
	for(int i=0; i<m; i++){
		pre = cur;
		cur = cur->next;
	} //for ending, pre 为cur前驱,cur指向第m个结点 
}



//循环链表traverse遍历 使用do{} while(); 
void BoyRing:: showAll(){
	
	//单链表遍历 
	//for(Boy *p = head; p!=NULL; p=p->next){
	//} 
	Boy *p = cur;
	do{
		cout << p->code;
		cout << "->";
		p = p->next;		
	}while(p != cur);
	cout << endl;
}


//构造函数:初始化 
BoyRing::BoyRing(int n){
	head = new Boy[n]; //申请内存
	
	//设置编号 并将它们组成环 
	for(int i=1; i<=n; i++){
		
		head[i-1].code = i; 
		head[i-1].next = & head[i%n];
		//i%n使得第n个结点指向第0个结点 
	} 
	
	//初始状态时,pre,cur都指向最后(第n-1个)结点 
	pre = cur = & head[n-1];	
	
}

//析构函数
BoyRing::~BoyRing(){
	cout << "descontruct called!" << endl;
	delete []head; head = NULL;
}
