/*BoyRing���ʵ�� 
*/
#include "BoyRing.h"
#include "Cpp.h" 

	
//ɾ��:����ǰ���ӻ���ɾ�� 
void BoyRing::delNode(){
	pre->next = cur->next;
	delete cur;
	cur = pre;//�ص���ʼ״̬(����ָ��ͬһ�����) 
}


//��ȡ��ǰ���ı��
int BoyRing:: getCodeCur(){
	return cur->code;
}
	


/*
��m���� ,ʹ��curָ���m�����,pre��cur��ǰ����λ�ù�ϵ���ܸ��� 
*/
void BoyRing::countNum(int m){
	
	//����m��,cur��ʼʱָ��������һ����� 
	for(int i=0; i<m; i++){
		pre = cur;
		cur = cur->next;
	} //for ending, pre Ϊcurǰ��,curָ���m����� 
}



//ѭ������traverse���� ʹ��do{} while(); 
void BoyRing:: showAll(){
	
	//��������� 
	//for(Boy *p = head; p!=NULL; p=p->next){
	//} 
	Boy *p = cur;
	do{
		cout << p->code;
		cout << "->";
		p = p->next;		
	}while(p != cur);
	cout << endl;
}


//���캯��:��ʼ�� 
BoyRing::BoyRing(int n){
	head = new Boy[n]; //�����ڴ�
	
	//���ñ�� ����������ɻ� 
	for(int i=1; i<=n; i++){
		
		head[i-1].code = i; 
		head[i-1].next = & head[i%n];
		//i%nʹ�õ�n�����ָ���0����� 
	} 
	
	//��ʼ״̬ʱ,pre,cur��ָ�����(��n-1��)��� 
	pre = cur = & head[n-1];	
	
}

//��������
BoyRing::~BoyRing(){
	cout << "descontruct called!" << endl;
	delete []head; head = NULL;
}
