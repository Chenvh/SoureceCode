/*C++特性1 
引用:变量数据类型 &引用名=已声明的变量名 
用引用作为函数参数现的是引用传递

函数参数传递:值传递(单向值拷贝,只能将实参的值拷贝给形参,实参与形参各自独占内存)
引用传递 :实现的是引用传递(形参与实参共用内存),实参与形参是同一个对象
值传递用于读操作
引用传递用于写操作
 
*/
#include <iostream>
using namespace std;

//引用版本
/*写操作 
@param a: 类型为int& ,引用类型,实 
*/
void swap(int & aref, int &bref){
	int t;
	t=aref; aref=bref ; bref=t;
} 

//指针版本 
void swap(int * a, int *b){
	int t;
	t = *a; *a = *b; *b = t;
}

//指针版本 
void createSpace(int ** ppa){
	
}

//引用版本
/*写操作 给指针分配内存,可以给其分配整型变量,一维数组,二维数组... 
@param par:类型为int*&, int指针的引用 
*/
void createSpace(int* & paref){
	//申请内存 ,
	//paref = new int;//整型变量
    //paref = (int*)malloc(sizeof(int));
	
	//写入是数组 
	//paref = new int[3];//一维数组 
	paref = new int[4];//一维数组 
	 
	for(int i=1;i<4; i++){	
		paref[i] = 20 + i;
	} 
	paref[0] = 3; //该数组第0个元素保存数组长度 
	
	
} 

//此处定义相当于下面第58行至63行 
typedef struct node{
	int data;
	struct node *next;
}Node, * PNode;
// PNode 等价于 Node* 

/*
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
typedef struct node* PNode;
*/


//引用版本 
void createList(PNode& pnoderef){
	pnoderef = new Node;
	pnoderef->data  = 2020;
}
//test
int main(){
	
	//指针的使用
	PNode pnode; //pnode 指针 
	createList(pnode);
	
	cout <<pnode->data << endl; 
	
	
	int * pa; 
	
	//pa申请内存 ,
	createSpace(pa); 
	
	cout << *pa << endl;//本例获取的是一维数组中第0个元素(长度)
	//打印数组
	for(int i=0;i<*pa+1; i++){
		cout << pa[i] << "," ;
	} 
	cout << endl;
	 
	
	int a=1, b=2;	
	
	swap(a,b);//引用版本,实现引用传递 ,可读性强 
	
	//swap(&a,&b);//指针版本 ,实现引用传递 
	
	cout << a << "," << b << endl;
	
	return 0;
} 


