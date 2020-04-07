#include "DbLinkList.h" 
/*PART2:
 ˫ѭ�������ʵ��: 
 ͨ�����������ʶ��:: 
*/

//���캯��:����˫��ѭ������ı�ͷ���
DbLinkList::DbLinkList(int v){
	cur =head = new DbLinkNode(v);
	if(NULL == head){
		cerr << "merory error!";
		exit(1);
	} 
	
	//��ʼʱ,ǰ����̽�ָ������ 
	head->lLink = head->rLink = head;
	//cur = head; //��ǰ��� == ͷ��� head 
	
}

//���
void DbLinkList:: showAll(){
	DbLinkNode *p;
	p = cur;
	do{
	  visitNode(p);	
	  cout << "->";
	  p=p->rLink;
	}while( p != cur);	
	
	cout << endl;
}

void DbLinkList::visitNode(DbLinkNode * node){
	if(NULL == node){
		cout << "NULL";
	}else{
		cout << node->data;
	}
}

/*��ֵΪv��Ԫ�ز�������ĵ�ǰ���cur֮�� 
*/
int DbLinkList::insertTail(const int &v){
	
	//step1: ��v��װΪ�½�� 
	DbLinkNode *pNewNode = new DbLinkNode(v);
	
	//step2: ���½�� ������ cur����

	//�����½��ĺ��ǰ�� 
	pNewNode->rLink = cur->rLink;
	pNewNode->lLink = cur;
	
	//ԭ��cur�ĺ�̵�ǰ������Ϊ�½�� 
	cur->rLink->lLink = pNewNode; 
		
	//ԭ���cur�ĺ�̸���Ϊ�½�� 
	cur->rLink = pNewNode;  
	
	//cur����Ϊ�½��
	cur = cur->rLink;  
	 
}
