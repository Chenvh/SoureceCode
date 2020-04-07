
/*��汾
��㶨�� 
*/
#include "comm.h" 
class SLinkNode { //Single Link Node
public://���е�
	int data;//������
	SLinkNode * next;// ָ����,ָ����(��һ����� )
	//����(����, ��Ϊ,����)
	
	//���캯��:����ͬ��,û�з�������,�Զ�����
	SLinkNode(){
		data = -2020; 
		next = NULL; 
	} 
	/* ��һ�����ȥ��ʼ����һ�����,��������Ϊthis���ĺ�� 
	@param v:int,����������
	@param ptr: SLinkNode*,������ָ��,Ĭ��ֵΪ0(NULLL) 
	*/
	SLinkNode(int v, SLinkNode* ptr=0){
		data = v;
		next = ptr;
	}
	
	//������ 
	void show(){
		cout << data << "->" << next << endl;
	}	
};

//��Ķ���: ��ͷ���ĵ������ 
class SLinkList{ // Single Link List
private: //��Ա����(���� )
	SLinkNode * head , * tail; //ͷβָ��
public:
	//CRUD,��Ա�������� 
	
	//ͷ�巨: ��ֵΪvԪ�ز���������ĵ�1��λ�� 
	void addToHead(int); 
	
	//β�巨:��ֵΪv��Ԫ�ز����������β��tail
	void addToTail(int);
	
	//ɾ��β���:��ɾ����β������ݱ�����v�� 
	void delFromTail(int&); 
	
	//����:����Ų���,	��head��ʼ�𽥲��� 
	
	//�ж��Ƿ�Ϊ�ձ�
	bool isEmpty(){
		return  NULL == head;
	} 
		
	//���캯�� 
	SLinkList(){
		head = NULL;		
		tail = NULL; //�ձ� 
	} 
	
	void visitNode(SLinkNode * pnode){
		cout << pnode->data << "->";
	}
	
	//traverse����: �������
	void showList(); 
	 
};

//::���������ʶ��,������ʶ�ú���������һ����� 

/*ɾ��β���:��ɾ����β������ݱ�����v�� 
@param v: ����Ϊint&,�������� 
*/
void SLinkList::delFromTail(int& v){
	//step0:�Ϸ�����֤ 
	if(isEmpty()){//�ǿձ� 
		cout << "Empty error!" << endl;
		v = -2020; 
		return; 
	} 
	
	//��ȡtail������ 
	v = tail->data;
	
	if(head == tail){//ֻ��һ����� 
		delete head; // �ͷ��ڴ� 
		head = tail = NULL;  //�ÿ� 
	} 
	else{ //�ж�����
	 //step1: ���ҵ�tail��ǰ��find the predecessor of tail
	 SLinkNode * pre;
	 for(pre=head; pre->next != tail; pre = pre->next){
	 }//for ending,  pre->next == tail	 
	 
	 //step2: ɾ�� 
	 delete tail;
	 pre->next = NULL;//β������ÿ� 
	 tail = pre; //����tail 
	} 
	
} 


//ͷ�巨: ��ֵΪvԪ�ز���������ĵ�1��λ�� 
void SLinkList::addToHead(int v){
	//���½����Ϊ�±��head, ����head�������ԭ��,ԭ����Ϊ�½��ĺ��		
	head  = new SLinkNode(v, head);
	
	//���� tail
	if(tail == NULL){
		tail = head;
	} 
}

//β�巨:��ֵΪv��Ԫ�ز����������β��tail
void  SLinkList::addToTail(int v){
	//�����ǿ�,head�ǲ����޸� 
	if(tail != NULL){
		tail -> next = new SLinkNode(v);//�½����Ϊԭ��tail�ĺ�� 
		tail = tail->next;//�����±�tail 
	} 
	else{ //tail == NULL, head == NULL
		head = tail = new SLinkNode(v);//�ձ�ʱ,�½�����headҲ��tail 
	}	
}
	
//traverse����: �������
void SLinkList::showList(){
	for(SLinkNode * p = head; p!=NULL; p=p->next){
		visitNode(p);			
	}//for ending, p == NULL
	cout << "NULL";
	cout << "\ntraverse over!\n" << endl;
} 	

 
