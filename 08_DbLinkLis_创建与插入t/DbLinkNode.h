#pragma once
#include "Cpp.h" 
/*˫ѭ���������� 
*/

//ǰ������
class DbLinkList; 

class DbLinkNode{
private:
	int data;//������ 
	DbLinkNode * lLink, * rLink; //left linkǰ��,right link��� 
public:	
	
	//��DbLinkList����Ϊ��Ԫ��,��ζ�� ��DbLinkList ���Է��ʱ������г�Ա 
	friend class DbLinkList; 
	 
	//���캯��
	// ��ֵΪv��Ԫ�ط��Ϊ��� 
	DbLinkNode(int v=2020):data(v), lLink(NULL), rLink(NULL){
		//data = v; lLink = rLink = NULL; 
	}
	
	DbLinkNode(int v, DbLinkNode* leftPointer, DbLinkNode * rightPointer )
	:data(v), rLink(rightPointer), lLink(leftPointer){
		//data = v; lLink = leftPointer; rLink = rightPointer; 
	}
	
	int getData(){
		return data;
	}
	
};
