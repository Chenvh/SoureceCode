/*
˳��ջ
ʵ�ַ�ʽ1: 
�±��Ǵ�0��ʼ 
��ʼ��:
top = -1;//top��ʼʱָ����ǿ�λ�� 
�ǿ�ʱ,topָ��ջ��Ԫ�����ڵ�λ�� 

push
top ++;
base[top] = e;
��ͬ�� 
base[++top] = e; 

ʵ�ַ�ʽ2: ˳���
��ʼ��:
top = 0; //top��ʼʱָ�������Чλ��,��0��
�ǿ�ʱ, topָ�����ջ��Ԫ�ص���һ��λ�� 

push
base[top] = e;
top ++;
��ͬ��
base[top++] = e;  

ģ��template ,���� 

int getMax(int x, int y){
	
	return x>y?x:y;	
}
double getMax(double x, double y){
	
	return x>y?x:y;
	
}
char getMax(char x, char y){
	
	return x>y?x:y;	
}

string getMax(string x, string y){
	
	return x>y?x:y;	
}
*/
#include "comm.h"

/*
���������ͳ��� 
ģ��template �Ĺؼ�����
template class �� 
template typename 
*/

/*
����ģ�� 
*/
//template <class T>
template <typename T> 
T getMax(T x, T y){
	
	return x>y?x:y;	
}

//��ģ�� 
template <typename Type>
class Node{
public:
	Type data;
	Node * next;
    void show(){
    	cout << data << endl;
	}
    
};

int main(){
	Node<string> node ;
	node.data = "Tom";
	node.show();
	
	Node<int> inode;
	inode.data = 2020;
	inode.show();
	
	string a="hello", b="hi";
	
	cout << getMax(a,b) << endl;
	
	
	return 0;
}
 



