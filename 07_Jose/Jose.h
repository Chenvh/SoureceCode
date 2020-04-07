#include "BoyRing.h"
#ifndef JOSE_H_2020
#define JOSE_H_2020
/*
Josephus 类 
*/

class Jose{
private:
	//人数, 间隔数, 开始数, 获胜者数 
	int n, m , s;
	//int w;//获胜者 
	
	//成员对象, 环,循环链表 
	BoyRing ring; //对象 
	
public:
	Jose(int , int , int=1);
	void getWinner();
};

#endif //JOSE_H_2020
