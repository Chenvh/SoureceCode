#include "Cpp.h"

/*
PART 2:类的实现部分 
通过类作用域标识符::来指明成员函数是属于哪一个类 
*/
#include "Date.h" 

/*操作符重载
*/
/* general skeleton of the overloaded output operator
@param os:类型为ostream&, 是对 ostream 对象的引用， 在该对象上将产生输出
@param obj:类型为Date&,是对要输出的类类型的引用,
	const，输出一个对象,不改变该对象 
@return ostream& ,输出流对象的引用 
*/
ostream&  operator<<(ostream& os, const Date &obj)
{
	// any special logic to prepare object
	// actual output of members fill('0')
	os <<  obj.year << "-" << setw(2) << obj.month ;
	os << "-" << setw(2) << obj.day << endl;
	
	// return ostream object reference
	return os;
}

/* general skeleton of the overloaded input operator
@param os:类型为ostream&, 是对 ostream 对象的引用， 在该对象上将产生输出
@param obj:类型为Date&,是对要输出的类类型的引用,
@return istream&,输出流对象的引用	 
*/
istream&  operator>>(istream& is, Date &obj)
{	
	is >>  obj.year >> obj.month >> obj.day ;
	
	// return istream object reference
	return is;
}


//构造函数 ,初始化 

/*无参:
假定日期为2000-1-1 
*/
Date::Date(){ 
	year = 2000; month = 1; day = 1; 
}
/*
@param y,m,d: int ,年,月,日 
*/
Date::Date(int y,int m ,int d){
	year = y; month = m; day = d;
} 

//输出
void Date::show(){
	cout << year << "-" << month << "-" << day << endl;
} 
