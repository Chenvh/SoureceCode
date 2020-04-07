#ifndef _PERSON_H_H_2020
#define _PERSON_H_H_2020

class Person{
public://�����ⲿ������ֱ�ӷ��ʵ����ݻ�ִ�еĲ���
	//��Ա����:����(����,����,���) 
	string name; //char name[50]; 
	int age;
	double high;	
public://�����ⲿ���Է��ʵ����ݻ�ִ�еĲ���
	Person(){
		name="Tom"; age = 20;
	}
	Person(string n, int a){
		name = n; age = a;
	}
	
	//���������
	friend istream& operator>>(istream& in, Person &obj); 
 	friend ostream& operator<<(ostream& out, Person &obj);
 	
	 //������ < ���� ,�Ϳ���ʹ��priority_queue Ĭ�Ϸ�ʽless������ 
 	friend bool operator<(const Person p1, const Person p2 ); 
 	friend bool operator>(const Person p1, const Person p2 );
 	
//��Ա����(����)

	void show(){
		cout<<"[name:"<<name<<", age:" << age;
		cout <<", high"<<high<<"]" << endl;
	}
	
	
	/*
	��������:���ٶ���,�ͷ��ڴ�,��������
	���������ϵͳ�Զ�����. ��������˳���빹�����˳���෴ 
	*/
	~Person(){
		
		  
	}
	
	
	
	/*�������캯��:�����Ǳ������ĳ�����,�������� ,
	��һ�������ʼ����һ������
	@param person:��������Ϊ const Person& �����ĳ�����
	*/
	Person(const Person& person){
		//cout  << "copy constructor called!\n";
		this->name = person.name;		
		this->age = person.age;
		this->high = person.high; 
		
	}
	
	
	/*���캯�� :��������,����ͬ��,��(����)���� ,�Զ�����,ֻ����public 
	��ջ�ڴ��д��� 
	*/
	Person(string name, int age, double high){
		this->name = name;
		this->age = age; 
		this->high = high; 
	}
	

};

//����������
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

