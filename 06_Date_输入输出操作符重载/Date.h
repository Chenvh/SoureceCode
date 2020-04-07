#pragma once

#include "Cpp.h"
/* Part 1 :类的定义声明部分
自定义的数据类型 

为了与 IO 标准库一致，操作符应接受 ostream& 作为第一个
形参，对类类型 const 对象的引用作为第二个形参，并返回对
ostream 形参的引用。
重载输出操作符一般的简单定义如下：
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
public: //成员函数(操作,方法) 
	
	//声明为友元函数 
	friend ostream& operator<<(ostream& ,const Date &);//read
	friend istream& operator>>(istream&, Date&); //write

	//构造函数
	Date();
	Date(int,int,int); 
	
	void show();	
private: //成员变量(属性) 
	//年月日
	int year , month, day; 
};
