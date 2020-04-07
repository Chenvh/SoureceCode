/*string 的引用
istream & getline( char *buffer, streamsize num );
istream & getline( char *buffer, streamsize num, char delim ); 

getline()函数用于输入流，读取字符到buffer中，直到下列情况发生：
num - 1个字符已经读入, 
碰到一个换行标志，
碰到一个EOF， 
或者，任意地读入，直到读到字符delim。delim字符不会被放入buffer中。 
 
*/
#include "common.h"

//拼接
/*
@param s1: const string&,常对象引用,不修改传入数据对象 
@param s2: const string&,常对象引用,不能修改传入对象(本例传入是字符串常量) 
@return string: 将值拷贝给调用者, 
*/
string append_v1( const string& s1, const string& s2){
	string tmp;
	//s1 = s2 + s1; //modigy s1 不能用于const 
	tmp = s1+s2;
	return tmp;
	
} 
/*
@param s1:  string&,对象引用,允许修改传入数据对象 
@param s2: const string&,常对象引用,不能修改传入对象(本例传入是字符串常量) 
@return string&: 将内存返回给调用者, 此内存可以被调用者进行写操作 
*/
string& append_v2( string& s1, const string& s2){
	
	s1 = s2 + s1; //modigy s1 不能用于const 
	
	return s1;
	
} 

/*
@param s1:  string&,对象引用,允许修改传入数据对象 
@param s2: const string&,常对象引用,不能修改传入对象(本例传入是字符串常量) 
@return const string&: 返回的是常对象引用,将内存返回给调用者,
 		 此内存不可以被调用者进行写操作 
*/
const string& append_v3( string& s1, const string& s2){
	
	s1 = s2 + s1; //modigy s1 不能用于const 
	
	return s1;
	
}



int main(){
	
	string origin = "TOM", copy, result;
	
	//input
	//cin>> origin; //等同于%s,遇到默认的分隔符结束数据获取 
	//getline(cin,origin); //等同于gets,输入一行字符至origin 
	
	copy = origin;
	
	result = append_v3(origin, "###");
	
	//不能将"MIKE"保存至返回的常对象引(内存),本处为origin 
	//append_v3(origin, "###")  = "MIKE";//error  
	
	cout<< "original string->" << origin << endl; 
	cout<< "result string->" << result << endl; 
	cout<< "result string->" << copy << endl; 
	
	
	result = append_v2(origin, "###");
	
	//将"MIKE"保存至返回的内存,本处为origin 
	append_v2(origin, "###")  = "MIKE";  
	
	cout<< "original string->" << origin << endl; 
	cout<< "result string->" << result << endl; 
	cout<< "result string->" << copy << endl; 	
	
	
	result = append_v1(origin, "###");
	
	cout<< "original string->" << origin << endl; 
	cout<< "result string->" << result << endl; 
} 
