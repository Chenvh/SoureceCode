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
 *	Descripton: ���ʽ��ֵ


	��׺���ʽ a + b * c - d / e * f
			
	��׺���ʽ a b c * + d e / f * -
	��׺���ʽ�����������������ļ�����������ڲ����������ȼ������ţ�
	�C ���ȼ��ߵ��ȼ��㣻
	�C ���ȼ���ͬ�İ������(����,�������Ҽ���) 
	�C ���Ŵ����ڲ㿪ʼ����

	��׺���ʽ�Ĵ������
	˳������ɨ����ʽ������������������ͣ�
	�C �����ǲ��������������ջ��
	�C ������˫Ŀ����������������ջ���˳�����������������󽫽����ջ��
	�C ����������ʽ���������ջ��Ӧ��ֻ��һ�����ݣ����Ǳ��ʽ�ļ�����

	 
   (0-123)*((45-678)*9+10)/(11+23)
   -1234.567*(-(-89/12)*34) 
 *
 *******************************/

#include "..\comm.h"
#include "SqStack.h"


template <typename T>
class InfixEvaluate{

private:
	
	SqStack<char> optrStack; // ������ջ,�洢�����
	 		
	SqStack<T> opndStack; //������ջ,�洢������
	
	int n; // ���ĸ��� 

	string exp;//���ʽ�ַ��� 
	
	bool iTag;//true: int���� , false : double ���� 
	
	char ENDC; //�����ַ� 
	
public:	
	
	//���캯�� 
	InfixEvaluate(string s, bool iTag=true, bool fileTag=false):
		optrStack(10), opndStack(10){
		// ������ջ, ����10���ռ�
		//optrStack = new SqStack<char>(10); //error,��Ա����ֻ���ڳ�ʼ���б���
		 
		 //����10����ʼ�洢�ռ�˳��ջ,�洢������
		//opndStack = new SqStack<T>(10); //error
		 
		ENDC = '#';
		this->iTag = iTag;
		
			
		optrStack.push(ENDC);//�������ӽ������

		cout<<"������Գ��ָ��ź����ŵ��������ʽ:"<<endl ;
			
		//fileTagΪtrue��ʾ���ļ��ж����ʽ, false�Ӽ����ж�ȡ ���ʽ 
		fileTag? inputExpFromFile(s):inputExp(s);
		
		cout << exp << endl; 
	}

	
	void inputExp(string s){
		exp = s;
	
		exp = exp + ENDC;//���Ͻ������ 
	}
	
	

	//���ļ��ж�ȡ�ַ���
	void inputExpFromFile(string fileName){
		//ifstream ifs(fileName.c_str());
		//ifs>>exp;
		exp = exp + ENDC;//���Ͻ������ 
	} 

	
	//string s ="-5.5*(-(-3/2)*2)"
	T getExpEvalution(){
	
		char stackChar, curChar;
		int i=0;
		T num1st, num2nd, tmpNum;
	
		optrStack.getTop(stackChar); 
		
		//ȡ���ʽ����һ���ַ�
		curChar = exp.at(i++); //curChar=exp[i++];
		
		while( curChar != ENDC || stackChar!= ENDC  ){
			/*����5�д������ڲ鿴ջ�����ݱ仯���*/
			cout << "���ʽ: " << exp << endl; 
			cout << "Cur=" << curChar <<", stackChar=" << stackChar << endl; 
			cout<<"optr-->";optrStack.traverse(); 
			cout<<"opnd-->";opndStack.traverse(); 
			cout << "----------------------------------------" << endl<<endl;
			
			
			
			if(isAvaild(curChar)){//�ǲ������Ҳ������Ϸ�
				
				/*������:�� -4.5  �� (-
				���'-'���ʼ����'-'ǰ����(,��'-'��ʾ�Ǹ��� */
				if( '-' == curChar && 1 == i || '(' == curChar && '-' == exp[i]) {
					opndStack.push(0);////������ѹ��0,������ת��Ϊ"0-����"��ʽ
				}
			 
				
				//����stackChar,curChar���ȼ�ѡ������
				switch(cmpPrior(stackChar, curChar)){
					//PS: case�����пո�,�ر��Ƕ����ַ�����. 
					case '<'://���ջ��stackChar���ȼ� < ��ǰ���curChar
						optrStack.push(curChar); //��ǰ���curChar�����ջ
	
						//To continueδ����� 
						if(i<exp.length()){ //û�����ʽĩβ
							//ȡ���ʽ����һ���ַ�
							curChar = exp.at(i++);//curChar=exp[i++];
						}
						break;
	
					case '=': //stackChar is '('�� curChar is')'
						optrStack.pop(stackChar);//���ջ��ջ,����һ������()
						
						//To continueδ����� 
						if(i<exp.length()){
							curChar = exp.at(i++);//curChar = exp[i++];
						}
						break;
	
					case '>': //stackChar�����ȼ����ڵ�ǰ���curChar
						optrStack.pop(stackChar);//���ջ��ջ
						
						//ȡ2��������,�ȳ�ջ���ǵ�2�������� 
						opndStack.pop(num2nd);
						opndStack.pop(num1st);
						
						//���� 
						tmpNum = calc(num1st, stackChar, num2nd);
						
						opndStack.push(tmpNum);//��������ջ���� 
				}//switch ENDING,�Ƚ�ջ���뵱ǰ�ַ����� 
				
			}//if ending,����������
			
			else if(curChar>='0' && curChar<='9'){ //���ǲ�����,�ǲ������ҺϷ� 
					tmpNum = 0;
					while(curChar>='0' && curChar<='9'){ //������������
					
						//�������� 
						tmpNum=tmpNum*10 + curChar-'0';//ƴ�ӳ���
						
						//To continueδ����� 
						if(i<exp.length()){ // ���Ǳ��ʽβ
						
							curChar = exp.at(i++);//curChar=exp[i++];//ȡ��һ���ַ�
							if(!iTag){//��double����,����С����
								if('.' == curChar) //ȡ��С����.
								{
									//����С������
									int n=10;
									curChar = exp.at(i++);//curChar=exp[i++];
									while(curChar>='0' && curChar<='9')
									{
										tmpNum +=((double)(curChar-'0'))/n;//С������ƴ�ӳ���
										n*=10;
										
										//To continueδ����� 
										if(i<exp.length()){ // δ����
											curChar=exp[i++];
										}
									}
								}//if ending,С������over 
							}//double���� 
						}//if ending,To continue Over!	
				   }//while ending,�������ִ���over
					 
				    opndStack.push(tmpNum);//��ȡ�����������ջ���� 
				    
				}//ifending,���ִ��� over 
			
			else{//�ǲ������ǲ����� 
					cout << "illegal char!" << endl;
					exit(1);
				}//�Ƿ��ַ� 			
			
			
			optrStack.getTop(stackChar);//���ջջ��Ԫ�ش���stackChar
			
		}//loop ending,���ʽ����over 
		
		
		opndStack.pop(num1st);//����ջ��ջ����ջ��Ԫ�ش���num1st(������)

		if(!opndStack.isEmpty())
		{
			cout<<"���ʽ����ȷ"<<endl;
			exit(1);
		}
		
		return num1st;
	}
	
	//���㲢���ؽ��
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
	
	
	
	//�Ϸ��������ж� 
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
	�Ƚ����stackChar�����curChar�����ȼ�

	@param char stackChar:ջ�������
	@param char curChar:���ʽ��ǰ�����
	@return < = > ���˳� 
	*/
	char cmpPrior(char stackChar, char curChar){
		char prior;
		switch(curChar){
			case '(': //curChar ��������'(',���ȼ���� 
				if(')'==stackChar )
				{
					cout<<"���Ų�ƥ��"<<endl;
					exit(1);
				}
				else{
					prior='<'; //stackChar < curChar,curCharӦ����ջ 
				}					
				break;
				
			case '+':
			case '-':
				if( '('==stackChar|| '#'==stackChar){//ջ����������,��ENDC 
					prior='<';  //stackChar < curChar,curChar��ջ 
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
			
	
			case ')': //��ǰ�ַ�curChar��������')' 
				switch(stackChar){			
					case '(': //�����������,ȥ����
						prior = '='; //����'='��ʾ����������� 
						break;
					case '#':
						cout<<"ȱ��������"<<endl;
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
						cout<<"ȱ��������"<<endl;
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
double���� 
������Գ��ָ��ź����ŵ��������ʽ:
-4.5*(-(-3/2)+2.5)#
���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=-, stackChar=#
optr-->size=10:[#]
opnd-->size=10:[]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=4, stackChar=-
optr-->size=10:[#, -]
opnd-->size=10:[0]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=*, stackChar=-
optr-->size=10:[#, -]
opnd-->size=10:[0, 4.5]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=(, stackChar=*
optr-->size=10:[#, -, *]
opnd-->size=10:[0, 4.5]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=-, stackChar=(
optr-->size=10:[#, -, *, (]
opnd-->size=10:[0, 4.5, 0]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=(, stackChar=-
optr-->size=10:[#, -, *, (, -]
opnd-->size=10:[0, 4.5, 0]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=-, stackChar=(
optr-->size=10:[#, -, *, (, -, (]
opnd-->size=10:[0, 4.5, 0, 0]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=3, stackChar=-
optr-->size=10:[#, -, *, (, -, (, -]
opnd-->size=10:[0, 4.5, 0, 0]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=/, stackChar=-
optr-->size=10:[#, -, *, (, -, (, -]
opnd-->size=10:[0, 4.5, 0, 0, 3]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=2, stackChar=/
optr-->size=10:[#, -, *, (, -, (, -, /]
opnd-->size=10:[0, 4.5, 0, 0, 3]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=), stackChar=/
optr-->size=10:[#, -, *, (, -, (, -, /]
opnd-->size=10:[0, 4.5, 0, 0, 3, 2]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=), stackChar=-
optr-->size=10:[#, -, *, (, -, (, -]
opnd-->size=10:[0, 4.5, 0, 0, 1.5]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=), stackChar=(
optr-->size=10:[#, -, *, (, -, (]
opnd-->size=10:[0, 4.5, 0, -1.5]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=+, stackChar=-
optr-->size=10:[#, -, *, (, -]
opnd-->size=10:[0, 4.5, 0, -1.5]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=+, stackChar=(
optr-->size=10:[#, -, *, (]
opnd-->size=10:[0, 4.5, 1.5]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=2, stackChar=+
optr-->size=10:[#, -, *, (, +]
opnd-->size=10:[0, 4.5, 1.5]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=), stackChar=+
optr-->size=10:[#, -, *, (, +]
opnd-->size=10:[0, 4.5, 1.5, 2.5]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=), stackChar=(
optr-->size=10:[#, -, *, (]
opnd-->size=10:[0, 4.5, 4]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=#, stackChar=*
optr-->size=10:[#, -, *]
opnd-->size=10:[0, 4.5, 4]
----------------------------------------

���ʽ: -4.5*(-(-3/2)+2.5)#
Cur=#, stackChar=-
optr-->size=10:[#, -]
opnd-->size=10:[0, 18]
----------------------------------------

-18
--------------------------------
Process exited after 0.406 seconds with return value 0
�밴���������. . .
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
int����
������Գ��ָ��ź����ŵ��������ʽ:
(-1+2)*(-2+4/3)+5#
���ʽ: (-1+2)*(-2+4/3)+5#
Cur=(, stackChar=#
optr-->size=10:[#]
opnd-->size=10:[]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=-, stackChar=(
optr-->size=10:[#, (]
opnd-->size=10:[0]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=1, stackChar=-
optr-->size=10:[#, (, -]
opnd-->size=10:[0]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=-
optr-->size=10:[#, (, -]
opnd-->size=10:[0, 1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=(
optr-->size=10:[#, (]
opnd-->size=10:[-1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=2, stackChar=+
optr-->size=10:[#, (, +]
opnd-->size=10:[-1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=), stackChar=+
optr-->size=10:[#, (, +]
opnd-->size=10:[-1, 2]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=), stackChar=(
optr-->size=10:[#, (]
opnd-->size=10:[1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=*, stackChar=#
optr-->size=10:[#]
opnd-->size=10:[1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=(, stackChar=*
optr-->size=10:[#, *]
opnd-->size=10:[1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=-, stackChar=(
optr-->size=10:[#, *, (]
opnd-->size=10:[1, 0]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=2, stackChar=-
optr-->size=10:[#, *, (, -]
opnd-->size=10:[1, 0]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=-
optr-->size=10:[#, *, (, -]
opnd-->size=10:[1, 0, 2]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=(
optr-->size=10:[#, *, (]
opnd-->size=10:[1, -2]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=4, stackChar=+
optr-->size=10:[#, *, (, +]
opnd-->size=10:[1, -2]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=/, stackChar=+
optr-->size=10:[#, *, (, +]
opnd-->size=10:[1, -2, 4]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=3, stackChar=/
optr-->size=10:[#, *, (, +, /]
opnd-->size=10:[1, -2, 4]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=), stackChar=/
optr-->size=10:[#, *, (, +, /]
opnd-->size=10:[1, -2, 4, 3]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=), stackChar=+
optr-->size=10:[#, *, (, +]
opnd-->size=10:[1, -2, 1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=), stackChar=(
optr-->size=10:[#, *, (]
opnd-->size=10:[1, -1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=*
optr-->size=10:[#, *]
opnd-->size=10:[1, -1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=+, stackChar=#
optr-->size=10:[#]
opnd-->size=10:[-1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=5, stackChar=+
optr-->size=10:[#, +]
opnd-->size=10:[-1]
----------------------------------------

���ʽ: (-1+2)*(-2+4/3)+5#
Cur=#, stackChar=+
optr-->size=10:[#, +]
opnd-->size=10:[-1, 5]
----------------------------------------

4
--------------------------------
Process exited after 0.4089 seconds with return value 0
�밴���������. . . 
*/

void testInfixEvaluate(){
	string s= "(-1+2)*(-2+4/3)+5"; 
	InfixEvaluate<int> infixEva(s,true);
	
	//cin >> s;
	//cout << infixEva.getExpression() << endl;
	cout << infixEva.getExpEvalution();
}
