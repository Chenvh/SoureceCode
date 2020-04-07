#pragma once
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName: InfixEvaluate
 *	Descripton: 表达式求值


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

	 
   (0-123)*((45-678)*9+10)/(11+23)
   -1234.567*(-(-89/12)*34) 
 *
 *******************************/

#include "..\comm.h"
#include "SqStack.h"


template <typename T>
class InfixEvaluate{

private:
	
	SqStack<char> optrStack; // 操作符栈,存储运算符
	 		
	SqStack<T> opndStack; //操作数栈,存储操作数
	
	int n; // 数的个数 

	string exp;//表达式字符串 
	
	bool iTag;//true: int计算 , false : double 计算 
	
	char ENDC; //结束字符 
	
public:	
	
	//构造函数 
	InfixEvaluate(string s, bool iTag=true, bool fileTag=false):
		optrStack(10), opndStack(10){
		// 操作符栈, 具有10个空间
		//optrStack = new SqStack<char>(10); //error,成员对象只能在初始化列表中
		 
		 //具有10个初始存储空间顺序栈,存储运算数
		//opndStack = new SqStack<T>(10); //error
		 
		ENDC = '#';
		this->iTag = iTag;
		
			
		optrStack.push(ENDC);//操作符加结束标记

		cout<<"输入可以出现负号和括号的算术表达式:"<<endl ;
			
		//fileTag为true表示从文件中读表达式, false从键盘中读取 表达式 
		fileTag? inputExpFromFile(s):inputExp(s);
		
		cout << exp << endl; 
	}

	
	void inputExp(string s){
		exp = s;
	
		exp = exp + ENDC;//加上结束标记 
	}
	
	

	//从文件中读取字符串
	void inputExpFromFile(string fileName){
		//ifstream ifs(fileName.c_str());
		//ifs>>exp;
		exp = exp + ENDC;//加上结束标记 
	} 

	
	//string s ="-5.5*(-(-3/2)*2)"
	T getExpEvalution(){
	
		char stackChar, curChar;
		int i=0;
		T num1st, num2nd, tmpNum;
	
		optrStack.getTop(stackChar); 
		
		//取表达式的下一个字符
		curChar = exp.at(i++); //curChar=exp[i++];
		
		while( curChar != ENDC || stackChar!= ENDC  ){
			/*以下5行代码用于查看栈中数据变化情况*/
			cout << "表达式: " << exp << endl; 
			cout << "Cur=" << curChar <<", stackChar=" << stackChar << endl; 
			cout<<"optr-->";optrStack.traverse(); 
			cout<<"opnd-->";opndStack.traverse(); 
			cout << "----------------------------------------" << endl<<endl;
			
			
			
			if(isAvaild(curChar)){//是操作符且操作符合法
				
				/*处理负号:如 -4.5  或 (-
				如果'-'在最开始或者'-'前面是(,则'-'表示是负号 */
				if( '-' == curChar && 1 == i || '(' == curChar && '-' == exp[i]) {
					opndStack.push(0);////算数找压入0,将负号转换为"0-正数"形式
				}
			 
				
				//根据stackChar,curChar优先级选择运算
				switch(cmpPrior(stackChar, curChar)){
					//PS: case后面有空格,特别是对于字符数据. 
					case '<'://算符栈顶stackChar优先级 < 当前算符curChar
						optrStack.push(curChar); //当前算符curChar入算符栈
	
						//To continue未完继续 
						if(i<exp.length()){ //没到表达式末尾
							//取表达式的下一个字符
							curChar = exp.at(i++);//curChar=exp[i++];
						}
						break;
	
					case '=': //stackChar is '('且 curChar is')'
						optrStack.pop(stackChar);//算符栈出栈,消除一对括号()
						
						//To continue未完继续 
						if(i<exp.length()){
							curChar = exp.at(i++);//curChar = exp[i++];
						}
						break;
	
					case '>': //stackChar的优先级高于当前算符curChar
						optrStack.pop(stackChar);//算符栈出栈
						
						//取2个操作数,先出栈者是第2个操作数 
						opndStack.pop(num2nd);
						opndStack.pop(num1st);
						
						//计算 
						tmpNum = calc(num1st, stackChar, num2nd);
						
						opndStack.push(tmpNum);//计算结果入栈保存 
				}//switch ENDING,比较栈符与当前字符结束 
				
			}//if ending,算符处理完毕
			
			else if(curChar>='0' && curChar<='9'){ //不是操作符,是操作数且合法 
					tmpNum = 0;
					while(curChar>='0' && curChar<='9'){ //连续皆是数字
					
						//整数部分 
						tmpNum=tmpNum*10 + curChar-'0';//拼接成数
						
						//To continue未完继续 
						if(i<exp.length()){ // 不是表达式尾
						
							curChar = exp.at(i++);//curChar=exp[i++];//取下一个字符
							if(!iTag){//是double计算,考虑小数点
								if('.' == curChar) //取到小数点.
								{
									//处理小数部分
									int n=10;
									curChar = exp.at(i++);//curChar=exp[i++];
									while(curChar>='0' && curChar<='9')
									{
										tmpNum +=((double)(curChar-'0'))/n;//小数部分拼接成数
										n*=10;
										
										//To continue未完继续 
										if(i<exp.length()){ // 未结束
											curChar=exp[i++];
										}
									}
								}//if ending,小数部分over 
							}//double处理 
						}//if ending,To continue Over!	
				   }//while ending,连续数字处理over
					 
				    opndStack.push(tmpNum);//获取的数入操作数栈保存 
				    
				}//ifending,数字处理 over 
			
			else{//非操作数非操作符 
					cout << "illegal char!" << endl;
					exit(1);
				}//非法字符 			
			
			
			optrStack.getTop(stackChar);//算符栈栈顶元素存于stackChar
			
		}//loop ending,表达式计算over 
		
		
		opndStack.pop(num1st);//算数栈出栈并将栈顶元素存于num1st(计算结果)

		if(!opndStack.isEmpty())
		{
			cout<<"表达式不正确"<<endl;
			exit(1);
		}
		
		return num1st;
	}
	
	//运算并返回结果
	T calc(T num1st, char op, T num2nd){
		
		switch(op)
		{
			case '+' : return num1st+num2nd;
			case '-' : return num1st-num2nd;
			case '*' : return num1st*num2nd;
			case '/' : return num1st/num2nd;
			default : return num1st*num2nd;
		}
	} 
	
	
	
	//合法操作符判断 
	bool isAvaild(char curChar){ 
	
		switch(curChar)
		{
			case '+':		case '-':
			case '*':		case '/':
			case '(':		case ')':
			case '#':
				return true;
			default:
				return false;
		}	
	} 
	
	/*
	比较算符stackChar和算符curChar的优先级

	@param char stackChar:栈内运算符
	@param char curChar:表达式当前运算符
	@return < = > 及退出 
	*/
	char cmpPrior(char stackChar, char curChar){
		char prior;
		switch(curChar){
			case '(': //curChar 是左括号'(',优先级最高 
				if(')'==stackChar )
				{
					cout<<"括号不匹配"<<endl;
					exit(1);
				}
				else{
					prior='<'; //stackChar < curChar,curChar应该入栈 
				}					
				break;
				
			case '+':
			case '-':
				if( '('==stackChar|| '#'==stackChar){//栈内是左括号,或ENDC 
					prior='<';  //stackChar < curChar,curChar入栈 
				}else{// stackChar > curChar
					prior='>';
				}
				break;
			case '*':
			case '/':
				if('*'==stackChar || '/'==stackChar || ')'==stackChar){
					prior='>';
				}else{
					prior='<';
				}
				break;
			
	
			case ')': //当前字符curChar是右括号')' 
				switch(stackChar){			
					case '(': //左右括号相逢,去括号
						prior = '='; //返回'='表示左右括号相逢 
						break;
					case '#':
						cout<<"缺乏左括号"<<endl;
						exit(1);
					default: prior = '>';
				}
				break;
	
			case '#':
				switch(stackChar){
					case '#':
						prior='=';
						break;
					case '(':
						cout<<"缺乏右括号"<<endl;
						exit(1);
					default:
						prior='>';
				}
				break;
			}
			return prior;	
	} 
	
	string getExpression(){
		return exp;
	}

}; 


/*
TestCase:
double计算 
输入可以出现负号和括号的算术表达式:
-4.5*(-(-3/2)+2.5)#
表达式: -4.5*(-(-3/2)+2.5)#
Cur=-, stackChar=#
optr-->size=10:[#]
opnd-->size=10:[]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=4, stackChar=-
optr-->size=10:[#, -]
opnd-->size=10:[0]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=*, stackChar=-
optr-->size=10:[#, -]
opnd-->size=10:[0, 4.5]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=(, stackChar=*
optr-->size=10:[#, -, *]
opnd-->size=10:[0, 4.5]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=-, stackChar=(
optr-->size=10:[#, -, *, (]
opnd-->size=10:[0, 4.5, 0]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=(, stackChar=-
optr-->size=10:[#, -, *, (, -]
opnd-->size=10:[0, 4.5, 0]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=-, stackChar=(
optr-->size=10:[#, -, *, (, -, (]
opnd-->size=10:[0, 4.5, 0, 0]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=3, stackChar=-
optr-->size=10:[#, -, *, (, -, (, -]
opnd-->size=10:[0, 4.5, 0, 0]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=/, stackChar=-
optr-->size=10:[#, -, *, (, -, (, -]
opnd-->size=10:[0, 4.5, 0, 0, 3]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=2, stackChar=/
optr-->size=10:[#, -, *, (, -, (, -, /]
opnd-->size=10:[0, 4.5, 0, 0, 3]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=), stackChar=/
optr-->size=10:[#, -, *, (, -, (, -, /]
opnd-->size=10:[0, 4.5, 0, 0, 3, 2]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=), stackChar=-
optr-->size=10:[#, -, *, (, -, (, -]
opnd-->size=10:[0, 4.5, 0, 0, 1.5]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=), stackChar=(
optr-->size=10:[#, -, *, (, -, (]
opnd-->size=10:[0, 4.5, 0, -1.5]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=+, stackChar=-
optr-->size=10:[#, -, *, (, -]
opnd-->size=10:[0, 4.5, 0, -1.5]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=+, stackChar=(
optr-->size=10:[#, -, *, (]
opnd-->size=10:[0, 4.5, 1.5]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=2, stackChar=+
optr-->size=10:[#, -, *, (, +]
opnd-->size=10:[0, 4.5, 1.5]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=), stackChar=+
optr-->size=10:[#, -, *, (, +]
opnd-->size=10:[0, 4.5, 1.5, 2.5]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=), stackChar=(
optr-->size=10:[#, -, *, (]
opnd-->size=10:[0, 4.5, 4]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=#, stackChar=*
optr-->size=10:[#, -, *]
opnd-->size=10:[0, 4.5, 4]
----------------------------------------

表达式: -4.5*(-(-3/2)+2.5)#
Cur=#, stackChar=-
optr-->size=10:[#, -]
opnd-->size=10:[0, 18]
----------------------------------------

-18
--------------------------------
Process exited after 0.406 seconds with return value 0
请按任意键继续. . .
*/
void testInfixEvaluateDouble(){
	
	string s= "-4.5*(-(-3/2)+2.5)"; 
	InfixEvaluate<double> infixEva(s,false);
	
	//cin >> s;
	//cout << infixEva.getExpression() << endl;
	cout << infixEva.getExpEvalution();
}

/*
TestCase:
int类型
输入可以出现负号和括号的算术表达式:
(-1+2)*(-2+4/3)+5#
表达式: (-1+2)*(-2+4/3)+5#
Cur=(, stackChar=#
optr-->size=10:[#]
opnd-->size=10:[]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=-, stackChar=(
optr-->size=10:[#, (]
opnd-->size=10:[0]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=1, stackChar=-
optr-->size=10:[#, (, -]
opnd-->size=10:[0]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=-
optr-->size=10:[#, (, -]
opnd-->size=10:[0, 1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=(
optr-->size=10:[#, (]
opnd-->size=10:[-1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=2, stackChar=+
optr-->size=10:[#, (, +]
opnd-->size=10:[-1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=), stackChar=+
optr-->size=10:[#, (, +]
opnd-->size=10:[-1, 2]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=), stackChar=(
optr-->size=10:[#, (]
opnd-->size=10:[1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=*, stackChar=#
optr-->size=10:[#]
opnd-->size=10:[1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=(, stackChar=*
optr-->size=10:[#, *]
opnd-->size=10:[1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=-, stackChar=(
optr-->size=10:[#, *, (]
opnd-->size=10:[1, 0]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=2, stackChar=-
optr-->size=10:[#, *, (, -]
opnd-->size=10:[1, 0]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=-
optr-->size=10:[#, *, (, -]
opnd-->size=10:[1, 0, 2]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=(
optr-->size=10:[#, *, (]
opnd-->size=10:[1, -2]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=4, stackChar=+
optr-->size=10:[#, *, (, +]
opnd-->size=10:[1, -2]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=/, stackChar=+
optr-->size=10:[#, *, (, +]
opnd-->size=10:[1, -2, 4]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=3, stackChar=/
optr-->size=10:[#, *, (, +, /]
opnd-->size=10:[1, -2, 4]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=), stackChar=/
optr-->size=10:[#, *, (, +, /]
opnd-->size=10:[1, -2, 4, 3]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=), stackChar=+
optr-->size=10:[#, *, (, +]
opnd-->size=10:[1, -2, 1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=), stackChar=(
optr-->size=10:[#, *, (]
opnd-->size=10:[1, -1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=*
optr-->size=10:[#, *]
opnd-->size=10:[1, -1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=#
optr-->size=10:[#]
opnd-->size=10:[-1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=5, stackChar=+
optr-->size=10:[#, +]
opnd-->size=10:[-1]
----------------------------------------

表达式: (-1+2)*(-2+4/3)+5#
Cur=#, stackChar=+
optr-->size=10:[#, +]
opnd-->size=10:[-1, 5]
----------------------------------------

4
--------------------------------
Process exited after 0.4089 seconds with return value 0
请按任意键继续. . . 
*/

void testInfixEvaluate(){
	string s= "(-1+2)*(-2+4/3)+5"; 
	InfixEvaluate<int> infixEva(s,true);
	
	//cin >> s;
	//cout << infixEva.getExpression() << endl;
	cout << infixEva.getExpEvalution();
}
