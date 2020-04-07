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
	BinTNode<T>* mp_root; //根结点 
	T m_stop; //停止标记 
	
	void detroyTree(BinTNode<T>* start){
		if(start != NULL){
			detroyTree(start->m_left); //Left
			detroyTree(start->m_right); //Right
			delete start;
			start = NULL;
		}
	}
	
	
public:
	//构造函数
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
	
	//=== get Root Node, 根结点的拷贝 
	BinTNode<T>* getRoot(){
		return mp_root;
	}
	
	//=== get Root Node Reference,根结点引用类型 
	BinTNode<T>*& getRootRef(){
		return mp_root;
	}
	
	//build binary tree
	//从数组中创建二叉树 
	// 数组为先序遍历的序列: char s_binTree[] = "#ABDG###E##C#F##";
	void createBinTreeFromArr(T s[]){
		m_stop = s[0]; 
		
		T e;
		e = getOneElem(s); 
		//cout << e<< ","; 
		if(e != m_stop){
			
			mp_root = new BinTNode<T>(e);
			assert(mp_root != NULL);
			
			//build left tree
			BinTree<T> child;//子树对象注意不是树结点BinTNode  
			 
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
	
	//从数组中先序创建二叉树
	//数组为先序遍历的序列: char s_binTree[] = "#ABDG###E##C#F##";
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
	
	
	//遍历:递归recurive
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
			inOrderRecur(subTree->m_left);//Left
			visitBinTNode(subTree); //Visit			
			inOrderRecur(subTree->m_right);//Right
		}else{
			return;
		}
	}
	//LRV
	void postOrderRecur(BinTNode<T>* subTree){
		if(subTree != NULL){
			
			postOrderRecur(subTree->m_left);//Left
			postOrderRecur(subTree->m_right);//Right
			visitBinTNode(subTree); //Visit
		}else{
			return;
		}
	}	
	
	//非递归遍历
	//VLR=Stack
	void preOrderStack(){
		stack<BinTNode<T> *> s_pre;
		s_pre.push(NULL); //reset
		
		BinTNode<T> *start = mp_root;
		
		while(start != NULL){
			
			visitBinTNode(start); //Visit
			
			if(start->m_right){
				s_pre.push(start->m_right); //save right subtree
			}

			if(start->m_left){
				start = start->m_left;
			}
			else{ // 叶子结点
				start = s_pre.top();//获取栈顶元素 
				s_pre.pop(); //出栈 
			}			
			
		}		
		
	} //---preOrderStack() END
	
	//LVR
	//VLR=Stack
	void inOrderStack(){
		stack<BinTNode<T> *> s_in;
		
		BinTNode<T> *start = mp_root;
		while(start!=NULL ||! s_in.empty()){
			if(start){
				s_in.push(start); //save root
				
				start = start->m_left ;//visit left subtree
			}
			else{
				start = s_in.top();//取栈顶 
				s_in.pop();//出栈 
				
				visitBinTNode(start); //Visit 
				
				start = start->m_right;
			} 
			
			
		} //loop end
		
	}//---inOrderStack() END
	
	//level traverse
	void levelOrderQueue(){
		//sequence queue
		queue< BinTNode<T> * > q_level;
		BinTNode<T> * start = mp_root;
		BinTNode <T> * cur;
		if(start ){
			q_level.push(start);
		}
		
		//traverse queue
		while(! q_level.empty()){
			
			cur = q_level.front();
			visitBinTNode(cur);//Visit
			
			if(cur->m_left){
				q_level.push(cur->m_left);//left subtree enQueue
			}
			if(cur->m_right){
				q_level.push(cur->m_right);//right subtree enQueue
			}
			
			q_level.pop();//出队 
			
			 
		} 	
		
	}//---levelOrderQueue() END 
	
	
}; 

/*===testTraverse
TestCase

PreOrder Traverse Stack:
A,B,D,G,E,C,F,

InOrder Traverse Stack:
G,D,B,E,A,C,F,

LevelOrder Traverse Queue:
A,B,C,D,E,F,G,

PreOrder Traverse Recurive:
A,B,D,G,E,C,F,

InOrder Traverse Recurive:
G,D,B,E,A,C,F,

PostOrder Traverse Recurive:
G,D,E,B,F,C,A,


--------------------------------
Process exited after 0.5932 seconds with return value 0
请按任意键继续. . .
*/

template <typename T>
void testTraverse(BinTree<T> &tree){
	cout<<"PreOrder Traverse Stack:" << endl;
	tree.preOrderStack();
	cout << endl<< endl;
	
	cout<<"InOrder Traverse Stack:" << endl;
	tree.inOrderStack();
	cout << endl<< endl;

	cout<<"LevelOrder Traverse Queue:" << endl;
	tree.levelOrderQueue();
	cout << endl<< endl;
	

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
请按任意键继续. . .
*/
void testBinTree(){
	//数据源 
	char s_binTree[] = "#ABDG###E##C#F##";
	
	//创建二叉树 
	BinTree<char> tree;
	tree.createTreePreOrderFromArr(tree.getRootRef(), s_binTree); 
	//tree.createBinTreeFromArr(s_binTree);
	
	testTraverse(tree);
	
	
}

#endif
