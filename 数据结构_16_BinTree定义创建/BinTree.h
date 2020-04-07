#ifndef _BINTREE_HH_2020
#define _BINTREE_HH_2020

#include "comm.h"


/*
二叉树类模板 
*/
template <typename T>
T getOneElem(T s[]){
	static int i=1; //static只初始化一次 
	return s[i++];
} 

template <typename T>
class BinTree{
private:
	BinTNode<T>* root;
	T m_stop; //停止标记 

public:
	//build binary tree
	//从数组中创建二叉树 
	// 数组为: char s_binTree[] = "#ABDG###E##C#F##";
	void createBinTree(T s[]){
		m_stop = s[0]; 
		
		T e;
		e = getOneElem(s); 
		cout << e<< ","; 
		if(e != m_stop){
			
			root = new BinTNode<T>(e);
			assert(root != NULL);
			
			//build left tree
			BinTree<T> child;//子树对象注意不是树结点BinTNode  
			 
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
请按任意键继续. . .
*/
void testBinTree(){
	char s_binTree[] = "#ABDG###E##C#F##";
	BinTree<char> tree;
	tree.createBinTree(s_binTree);
	
}

#endif
