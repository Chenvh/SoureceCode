/*
C++��Ԥ��֪ʶ 
1. �����Ŀ��ļ�������ͬ 
2. ���� input output��������� cin cout�����滻scanf() printf()
 \n �� endl������ʹ��,��ʾ���� 

3. �����µĻ����������� bool string 
bool : �߼�ֵ, false  true
 
string:�ַ��� char[] 

4. struct �� ��class��ʵ��. struct������������ 

5. ���������ʶ�� ::
 
*/
#include <string.h>
#include <iostream>
using namespace std;

typedef struct student{
	char name[20];
	int age;
}STUDENT; 
//STUDENT �ȼ��� struct student 

class Student{
public:
//private: 
	string name;
	int age;
	static int year ; 
}; 

int year = 2019;
int Student::year = 2020;

//test
int main(){
	
	cout << Student::year << endl;
	
	
	//����һ��ѧ���ṹ�����(����) 
	STUDENT s;
	
	Student student;//����ѧ������ 
	
	
	int i; double d; char c; char name[20] = "Tom0";
	char name1[20];
	string s_name = "Mike"; 
	string s_name1;
	
	strcpy(s.name, name); //ok 
	
	student.name = s_name; // ok
	
	
	//��������,��һ���ַ�����������һ���ַ���
	//name1 = name; //error
	strcpy(name1, name);//ok,
	s_name1 = s_name; //ok
	 
	cout << name << endl;
	cout << name1 << endl;
	cout << s_name << endl;
	cout << s_name1 << endl;
	
	
	cout<<showpos<<12 << endl;                                     // +12
	cout<<hex<<18<<" "<<showbase<<18<< endl;        // 12  0x12
	cout<<hex<<255<<" "<<uppercase<<255<< endl;   // ff  FF
	cout<<123.0<<" "<<showpoint<<123.0<< endl;       // 123  123.000
	cout<<(2>3)<<" "<<boolalpha<<(2>3)<< endl;         // 0  false
	cout<<fixed<<12345.678<< endl;                  // 12345.678000
	cout<<scientific<<123456.678<< endl;           // 1.234568e+05

	
	
	//input 
	//scanf("%d%lf%c%s", &i, &d, &c, name);
//	cin >> i >> d >> c >> name;
	
	//output
	//printf();
	//cout << i << d << c << name;
	 
	
	
	return 0;
} 
