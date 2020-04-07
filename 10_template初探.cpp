/*
顺序栈
实现方式1: 
下标是从0开始 
初始化:
top = -1;//top初始时指向的是空位置 
非空时,top指向栈顶元素所在的位置 

push
top ++;
base[top] = e;
等同于 
base[++top] = e; 

实现方式2: 顺序表
初始化:
top = 0; //top初始时指向的是有效位置,第0号
非空时, top指向的是栈顶元素的下一个位置 

push
base[top] = e;
top ++;
等同于
base[top++] = e;  

模板template ,泛型 

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
将数据类型抽象化 
模板template 的关键字是
template class 或 
template typename 
*/

/*
函数模板 
*/
//template <class T>
template <typename T> 
T getMax(T x, T y){
	
	return x>y?x:y;	
}

//类模板 
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
 



