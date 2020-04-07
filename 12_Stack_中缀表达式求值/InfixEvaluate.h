#pragma once

/*���ʽ:

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


*/

#include "SqStack.h"


template <typename T>
class InfixEvaluate{
public:
	//���캯��: 
	InfixEvaluate(string s, int n) :length(n),exp(s),
					opndStack(n), optrStack(n){
		
		//��Ա�����ʼ��,ֻ�����ó�ʼ���б����ʽ : 
		//����ĳ�Ա�����ó�ʼ���б���г�ʼ�� 
		//length = n; exp = s;
		cout << "Constructor new a Object! " << endl;
	}
	
	void show(){
		cout<< "length=" <<length <<" ,Expression = "<< exp << endl;
		opndStack.traverse();
		optrStack.traverse();
		
	}
	
private: 
	//��Ա���� 
	SqStack<T> opndStack;//������ջ
	SqStack<char> optrStack;//������ջ 	 
	string exp;//���ʽ 
	
	//��Ա���� 
	int length; 
	
	
}; 


