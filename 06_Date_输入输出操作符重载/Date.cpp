#include "Cpp.h"

/*
PART 2:���ʵ�ֲ��� 
ͨ�����������ʶ��::��ָ����Ա������������һ���� 
*/
#include "Date.h" 

/*����������
*/
/* general skeleton of the overloaded output operator
@param os:����Ϊostream&, �Ƕ� ostream ��������ã� �ڸö����Ͻ��������
@param obj:����ΪDate&,�Ƕ�Ҫ����������͵�����,
	const�����һ������,���ı�ö��� 
@return ostream& ,�������������� 
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
@param os:����Ϊostream&, �Ƕ� ostream ��������ã� �ڸö����Ͻ��������
@param obj:����ΪDate&,�Ƕ�Ҫ����������͵�����,
@return istream&,��������������	 
*/
istream&  operator>>(istream& is, Date &obj)
{	
	is >>  obj.year >> obj.month >> obj.day ;
	
	// return istream object reference
	return is;
}


//���캯�� ,��ʼ�� 

/*�޲�:
�ٶ�����Ϊ2000-1-1 
*/
Date::Date(){ 
	year = 2000; month = 1; day = 1; 
}
/*
@param y,m,d: int ,��,��,�� 
*/
Date::Date(int y,int m ,int d){
	year = y; month = m; day = d;
} 

//���
void Date::show(){
	cout << year << "-" << month << "-" << day << endl;
} 
