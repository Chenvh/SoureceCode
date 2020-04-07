#ifndef _PERSON_H_H_2020
#define _PERSON_H_H_2020

class Person{
public://就是外部不不能直接访问的数据或执行的操作
	//成员变量:属性(姓名,年龄,身高) 
	string name; //char name[50]; 
	int age;
	double high;	
public://就是外部可以访问的数据或执行的操作
	Person(){
		name="Tom"; age = 20;
	}
	Person(string n, int a){
		name = n; age = a;
	}
	
	//重载运算符
	friend istream& operator>>(istream& in, Person &obj); 
 	friend ostream& operator<<(ostream& out, Person &obj);
 	
	 //操作符 < 重载 ,就可以使用priority_queue 默认方式less来排序 
 	friend bool operator<(const Person p1, const Person p2 ); 
 	friend bool operator>(const Person p1, const Person p2 );
 	
//成员函数(方法)

	void show(){
		cout<<"[name:"<<name<<", age:" << age;
		cout <<", high"<<high<<"]" << endl;
	}
	
	
	/*
	析构函数:销毁对象,释放内存,不能重载
	程序结束由系统自动调用. 析构对象顺序与构造对象顺序相反 
	*/
	~Person(){
		
		  
	}
	
	
	
	/*拷贝构造函数:参数是本类对象的常引用,不能重载 ,
	用一个对象初始化另一个对象
	@param person:参数类型为 const Person& 类对象的常引用
	*/
	Person(const Person& person){
		//cout  << "copy constructor called!\n";
		this->name = person.name;		
		this->age = person.age;
		this->high = person.high; 
		
	}
	
	
	/*构造函数 :创建对象,与类同名,无(返回)类型 ,自动调用,只能是public 
	在栈内存中创建 
	*/
	Person(string name, int age, double high){
		this->name = name;
		this->age = age; 
		this->high = high; 
	}
	

};

//操作符重载
istream& operator>>(istream& in, Person &obj){
	in >> obj.name >> obj.age >> obj.high;
	return in;
} 
ostream& operator<<(ostream& out, Person &obj){
	out <<  obj.name << " " << obj.age;
	out << " " << obj.high <<   endl;
//	out << "[name:" << obj.name << ", age:" << obj.age;
//	out << ", high" << obj.high << "]" << endl;
	return out;
} 

 bool operator>(const Person p1, const Person p2 ){
	return p1.age > p2.age;
}

 bool operator<(const Person p1, const Person p2 ){
	return p1.age < p2.age;
}


#endif

