#include "SLinkList.h"

//test
int main(){
	//SLinkList Test
	SLinkList list;// �����ձ�
	
	//boolalpha : ��bool��ӡ�� true false 
	cout << boolalpha << list.isEmpty() << endl;
	
	list.showList(); 
	
	list.addToHead(11);
	list.showList();
	cout << boolalpha << list.isEmpty() << endl;
	
	
	
	cout << endl << endl;
	//SLinkNode Test
	SLinkNode node;//�����ն��� 
	node.show(); 
	
	

	SLinkNode node2(11);//�������󲢳�ʼ�� 
	node2.show(); 
	
	return 0;
}
