/*string ������
istream & getline( char *buffer, streamsize num );
istream & getline( char *buffer, streamsize num, char delim ); 

getline()������������������ȡ�ַ���buffer�У�ֱ���������������
num - 1���ַ��Ѿ�����, 
����һ�����б�־��
����һ��EOF�� 
���ߣ�����ض��룬ֱ�������ַ�delim��delim�ַ����ᱻ����buffer�С� 
 
*/
#include "common.h"

//ƴ��
/*
@param s1: const string&,����������,���޸Ĵ������ݶ��� 
@param s2: const string&,����������,�����޸Ĵ������(�����������ַ�������) 
@return string: ��ֵ������������, 
*/
string append_v1( const string& s1, const string& s2){
	string tmp;
	//s1 = s2 + s1; //modigy s1 ��������const 
	tmp = s1+s2;
	return tmp;
	
} 
/*
@param s1:  string&,��������,�����޸Ĵ������ݶ��� 
@param s2: const string&,����������,�����޸Ĵ������(�����������ַ�������) 
@return string&: ���ڴ淵�ظ�������, ���ڴ���Ա������߽���д���� 
*/
string& append_v2( string& s1, const string& s2){
	
	s1 = s2 + s1; //modigy s1 ��������const 
	
	return s1;
	
} 

/*
@param s1:  string&,��������,�����޸Ĵ������ݶ��� 
@param s2: const string&,����������,�����޸Ĵ������(�����������ַ�������) 
@return const string&: ���ص��ǳ���������,���ڴ淵�ظ�������,
 		 ���ڴ治���Ա������߽���д���� 
*/
const string& append_v3( string& s1, const string& s2){
	
	s1 = s2 + s1; //modigy s1 ��������const 
	
	return s1;
	
}



int main(){
	
	string origin = "TOM", copy, result;
	
	//input
	//cin>> origin; //��ͬ��%s,����Ĭ�ϵķָ����������ݻ�ȡ 
	//getline(cin,origin); //��ͬ��gets,����һ���ַ���origin 
	
	copy = origin;
	
	result = append_v3(origin, "###");
	
	//���ܽ�"MIKE"���������صĳ�������(�ڴ�),����Ϊorigin 
	//append_v3(origin, "###")  = "MIKE";//error  
	
	cout<< "original string->" << origin << endl; 
	cout<< "result string->" << result << endl; 
	cout<< "result string->" << copy << endl; 
	
	
	result = append_v2(origin, "###");
	
	//��"MIKE"���������ص��ڴ�,����Ϊorigin 
	append_v2(origin, "###")  = "MIKE";  
	
	cout<< "original string->" << origin << endl; 
	cout<< "result string->" << result << endl; 
	cout<< "result string->" << copy << endl; 	
	
	
	result = append_v1(origin, "###");
	
	cout<< "original string->" << origin << endl; 
	cout<< "result string->" << result << endl; 
} 
