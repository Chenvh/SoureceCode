#include "BoyRing.h"
#ifndef JOSE_H_2020
#define JOSE_H_2020
/*
Josephus �� 
*/

class Jose{
private:
	//����, �����, ��ʼ��, ��ʤ���� 
	int n, m , s;
	//int w;//��ʤ�� 
	
	//��Ա����, ��,ѭ������ 
	BoyRing ring; //���� 
	
public:
	Jose(int , int , int=1);
	void getWinner();
};

#endif //JOSE_H_2020
