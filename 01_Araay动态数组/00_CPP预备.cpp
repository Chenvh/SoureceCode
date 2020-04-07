/*
C++的预备知识 
1. 包含的库文件有所不同 
2. 引入 input output输入输出流 cin cout用来替换scanf() printf()
 \n 与 endl都可以使用,表示换行 

3. 引入新的基本数据类型 bool string 
bool : 逻辑值, false  true
 
string:字符串 char[] 

4. struct 用 类class来实现. struct是类的特殊情况 

5. 类作用域标识符 ::
 
*/
#include <string.h>
#include <iostream>
using namespace std;

typedef struct student{
	char name[20];
	int age;
}STUDENT; 
//STUDENT 等价于 struct student 

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
	
	
	//定义一个学生结构体变量(对象) 
	STUDENT s;
	
	Student student;//定义学生对象 
	
	
	int i; double d; char c; char name[20] = "Tom0";
	char name1[20];
	string s_name = "Mike"; 
	string s_name1;
	
	strcpy(s.name, name); //ok 
	
	student.name = s_name; // ok
	
	
	//拷贝操作,将一个字符串拷贝给另一个字符串
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
