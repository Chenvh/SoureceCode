/*C++����1 
����:������������ &������=�������ı����� 
��������Ϊ���������ֵ������ô���

������������:ֵ����(����ֵ����,ֻ�ܽ�ʵ�ε�ֵ�������β�,ʵ�����βθ��Զ�ռ�ڴ�)
���ô��� :ʵ�ֵ������ô���(�β���ʵ�ι����ڴ�),ʵ�����β���ͬһ������
ֵ�������ڶ�����
���ô�������д����
 
*/
#include <iostream>
using namespace std;

//���ð汾
/*д���� 
@param a: ����Ϊint& ,��������,ʵ 
*/
void swap(int & aref, int &bref){
	int t;
	t=aref; aref=bref ; bref=t;
} 

//ָ��汾 
void swap(int * a, int *b){
	int t;
	t = *a; *a = *b; *b = t;
}

//ָ��汾 
void createSpace(int ** ppa){
	
}

//���ð汾
/*д���� ��ָ������ڴ�,���Ը���������ͱ���,һά����,��ά����... 
@param par:����Ϊint*&, intָ������� 
*/
void createSpace(int* & paref){
	//�����ڴ� ,
	//paref = new int;//���ͱ���
    //paref = (int*)malloc(sizeof(int));
	
	//д�������� 
	//paref = new int[3];//һά���� 
	paref = new int[4];//һά���� 
	 
	for(int i=1;i<4; i++){	
		paref[i] = 20 + i;
	} 
	paref[0] = 3; //�������0��Ԫ�ر������鳤�� 
	
	
} 

//�˴������൱�������58����63�� 
typedef struct node{
	int data;
	struct node *next;
}Node, * PNode;
// PNode �ȼ��� Node* 

/*
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
typedef struct node* PNode;
*/


//���ð汾 
void createList(PNode& pnoderef){
	pnoderef = new Node;
	pnoderef->data  = 2020;
}
//test
int main(){
	
	//ָ���ʹ��
	PNode pnode; //pnode ָ�� 
	createList(pnode);
	
	cout <<pnode->data << endl; 
	
	
	int * pa; 
	
	//pa�����ڴ� ,
	createSpace(pa); 
	
	cout << *pa << endl;//������ȡ����һά�����е�0��Ԫ��(����)
	//��ӡ����
	for(int i=0;i<*pa+1; i++){
		cout << pa[i] << "," ;
	} 
	cout << endl;
	 
	
	int a=1, b=2;	
	
	swap(a,b);//���ð汾,ʵ�����ô��� ,�ɶ���ǿ 
	
	//swap(&a,&b);//ָ��汾 ,ʵ�����ô��� 
	
	cout << a << "," << b << endl;
	
	return 0;
} 


