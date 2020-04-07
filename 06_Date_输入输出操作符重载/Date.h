#pragma once

#include "Cpp.h"
/* Part 1 :��Ķ�����������
�Զ������������ 

Ϊ���� IO ��׼��һ�£�������Ӧ���� ostream& ��Ϊ��һ��
�βΣ��������� const �����������Ϊ�ڶ����βΣ������ض�
ostream �βε����á�
�������������һ��ļ򵥶������£�
// general skeleton of the overloaded output operator
ostream& operator <<(ostream& os, const ClassType &object)
{
// any special logic to prepare object
// actual output of members
os << // ...
// return ostream object
return os;
}

*/

class Date{	
public: //��Ա����(����,����) 
	
	//����Ϊ��Ԫ���� 
	friend ostream& operator<<(ostream& ,const Date &);//read
	friend istream& operator>>(istream&, Date&); //write

	//���캯��
	Date();
	Date(int,int,int); 
	
	void show();	
private: //��Ա����(����) 
	//������
	int year , month, day; 
};
