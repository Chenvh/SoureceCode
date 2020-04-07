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
	BinTNode<T>* root;
	T m_stop; //ֹͣ��� 

public:
	//build binary tree
	//�������д��������� 
	// ����Ϊ: char s_binTree[] = "#ABDG###E##C#F##";
	void createBinTree(T s[]){
		m_stop = s[0]; 
		
		T e;
		e = getOneElem(s); 
		cout << e<< ","; 
		if(e != m_stop){
			
			root = new BinTNode<T>(e);
			assert(root != NULL);
			
			//build left tree
			BinTree<T> child;//��������ע�ⲻ�������BinTNode  
			 
			child.createBinTree(s);
			root->m_left = child.root;
			child.root = NULL;
			
			//build right tree 
			child.createBinTree(s);
			root->m_right = child.root;
			child.root = NULL;
		}
		else { //e == m_stop
			return;
		}	
		
	} 
	
	
}; 


/*
A,B,D,G,#,#,#,E,#,#,C,#,F,#,#,
--------------------------------
Process exited after 0.7018 seconds with return value 0
�밴���������. . .
*/
void testBinTree(){
	char s_binTree[] = "#ABDG###E##C#F##";
	BinTree<char> tree;
	tree.createBinTree(s_binTree);
	
}

#endif
