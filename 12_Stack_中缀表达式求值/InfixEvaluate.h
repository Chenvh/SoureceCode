#pragma once

/*表达式:

中缀表达式 a + b * c - d / e * f
		
后缀表达式 a b c * + d e / f * -
中缀表达式中相邻两个操作符的计算次序依赖于操作符的优先级和括号：
– 优先级高的先计算；
– 优先级相同的按结合性(左结合,自左向右计算) 
– 括号从最内层开始计算

后缀表达式的处理过程
顺序逐项扫描表达式，根据遇到的项的类型：
– 该项是操作数，则该项入栈；
– 该项是双目操作符，则连续从栈中退出两个操作数，计算后将结果入栈；
– 当处理完表达式的所有项后，栈中应该只有一项内容，就是表达式的计算结果


*/

#include "SqStack.h"


template <typename T>
class InfixEvaluate{
public:
	//构造函数: 
	InfixEvaluate(string s, int n) :length(n),exp(s),
					opndStack(n), optrStack(n){
		
		//成员对象初始化,只允许用初始化列表的形式 : 
		//其余的成员可以用初始化列表进行初始化 
		//length = n; exp = s;
		cout << "Constructor new a Object! " << endl;
	}
	
	void show(){
		cout<< "length=" <<length <<" ,Expression = "<< exp << endl;
		opndStack.traverse();
		optrStack.traverse();
		
	}
	
private: 
	//成员对象 
	SqStack<T> opndStack;//操作数栈
	SqStack<char> optrStack;//操作符栈 	 
	string exp;//表达式 
	
	//成员对象 
	int length; 
	
	
}; 


