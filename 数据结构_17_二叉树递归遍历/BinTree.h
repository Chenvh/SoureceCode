#ifndef _BINTREE_HH_2020
#define _BINTREE_HH_2020

#include "comm.h"


/*
��������ģ�� 
*/
template <typename T>
T getOneElem(T s[]){
	static int i=1; //staticֻ��ʼ��һ�� 
	return s[i++];
} 

template <typename T>
class BinTree{
private:
	BinTNode<T>* mp_root; //����� 
	T m_stop; //ֹͣ��� 
	void detroyTree(BinTNode<T>* start){
		if(start != NULL){
			detroyTree(start->m_left); //Left
			detroyTree(start->m_right); //Right
			delete start;
			start = NULL;
		}
	}
	
	
public:
	//���캯��
	BinTree(){
		mp_root = NULL; 
	} 
	~BinTree(){
		detroyTree(mp_root);
	}
	
	
	void visitBinTNode(BinTNode<T>* cur){
		cur->show();
		cout << ",";
	}
	
	//=== get Root Node, �����Ŀ��� 
	BinTNode<T>* getRoot(){
		return mp_root;
	}
	
	//=== get Root Node Reference,������������� 
	BinTNode<T>*& getRootRef(){
		return mp_root;
	}
	
	//build binary tree
	//�������д��������� 
	// ����Ϊ�������������: char s_binTree[] = "#ABDG###E##C#F##";
	void createBinTreeFromArr(T s[]){
		m_stop = s[0]; 
		
		T e;
		e = getOneElem(s); 
		//cout << e<< ","; 
		if(e != m_stop){
			
			mp_root = new BinTNode<T>(e);
			assert(mp_root != NULL);
			
			//build left tree
			BinTree<T> child;//��������ע�ⲻ�������BinTNode  
			 
			child.createBinTreeFromArr(s);
			mp_root->m_left = child.mp_root;
			child.mp_root = NULL;
			
			//build right tree 
			child.createBinTreeFromArr(s);
			mp_root->m_right = child.mp_root;
			child.mp_root = NULL;
		}
		else { //e == m_stop
			return;
		}	
		
	} //--- createBinTreeFromArr() END
	
	//�����������򴴽�������
	//����Ϊ�������������: char s_binTree[] = "#ABDG###E##C#F##";
	void createTreePreOrderFromArr(BinTNode<T>* & subTree, T s[]){
		m_stop = s[0]; 
		
		T e;
		e = getOneElem(s); 
		//cout << e<< ","; 
		if(e != m_stop){
			
			subTree = new BinTNode<T>(e);
			assert(subTree != NULL);
			
			createTreePreOrderFromArr(subTree->m_left,s);
			createTreePreOrderFromArr(subTree->m_right,s);
		}
		else{
			return;
		}
	} 
	
	
	//����:�ݹ�recurive
	//VLR
	void preOrderRecur(BinTNode<T>* subTree){
		if(subTree != NULL){
			visitBinTNode(subTree); //Visit
			preOrderRecur(subTree->m_left);//Left
			preOrderRecur(subTree->m_right);//Right
		}else{
			return;
		}
	} 

	//LVR
	void inOrderRecur(BinTNode<T>* subTree){
		if(subTree != NULL){
			preOrderRecur(subTree->m_left);//Left
			visitBinTNode(subTree); //Visit			
			preOrderRecur(subTree->m_right);//Right
		}else{
			return;
		}
	}
	//LRV
	void postOrderRecur(BinTNode<T>* subTree){
		if(subTree != NULL){
			
			preOrderRecur(subTree->m_left);//Left
			preOrderRecur(subTree->m_right);//Right
			visitBinTNode(subTree); //Visit
		}else{
			return;
		}
	}	
	
}; 

/*===testTraverse
TestCase

PreOrder Traverse Recurive:
A,B,D,G,E,C,F,

InOrder Traverse Recurive:
B,D,G,E,A,C,F,

PostOrder Traverse Recurive:
B,D,G,E,C,F,A,


--------------------------------
Process exited after 0.5588 seconds with return value 0
�밴���������. . .
*/

template <typename T>
void testTraverse(BinTree<T> &tree){
	cout<<"PreOrder Traverse Recurive:" << endl;
	tree.preOrderRecur(tree.getRoot());
	cout << endl<< endl;
	
	cout<<"InOrder Traverse Recurive:" << endl;
	tree.inOrderRecur(tree.getRoot());
	cout << endl<< endl;
	
	cout<<"PostOrder Traverse Recurive:" << endl;
	tree.postOrderRecur(tree.getRoot());
	cout << endl<< endl;
}


/*
A,B,D,G,#,#,#,E,#,#,C,#,F,#,#,
--------------------------------
Process exited after 0.7018 seconds with return value 0
�밴���������. . .
*/
void testBinTree(){
	//����Դ 
	char s_binTree[] = "#ABDG###E##C#F##";
	
	//���������� 
	BinTree<char> tree;
	tree.createTreePreOrderFromArr(tree.getRootRef(), s_binTree); 
	//tree.createBinTreeFromArr(s_binTree);
	
	testTraverse(tree);
	
	
}

#endif
