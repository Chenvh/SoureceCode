#ifndef  _THREAD_BI_TREE_HH_2020
#define  _THREAD_BI_TREE_HH_2020

/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.
#pragma once 
 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName: InOrderThrTree.h 线索二叉树类模板 
 *	Descripton:InOrderThrTree.h 线索二叉树类模板,实现遍历 
 * 中序线索二叉树:二叉树按中序遍历进行线索化 
 
 类似双向链表. 能从第1个结点(head)可以遍历至最后1个结点.
 也可以从最后1个结点逆序(向前)可以遍历至第1个结点(head).
 双向链表变成循环双向链表.head的prior(前驱)指向最后1个节点.
 同样,最后1个结点的next(后继)指向第1个结点(head) 
 
 
 *******************************/

//#include "data.h"
#include "comm.h"
#include "ThreadNode.h" 
#define MAXDEPTH 100 

template<typename Type>
class InOrderThrTree{
	//线索二叉树的头结点 ,类似双循环链表的head 
	ThreadNode<Type>* head_thrt ;
	
	ThreadNode<Type> * mp_root; //根 
	
	Type m_stop; 
	
	//销毁 
	void destroyBiTree(ThreadNode<Type>* &t)
	{
		if(t!=NULL)
		{
			destroyBiTree(t->mp_left);
			destroyBiTree(t->mp_right);
			delete t;
			t=NULL;
		}
	}

public:
	
	/*中序遍历线索化二叉树. 
	新增一个结点head_thrt,
	让其左指针指向根结点mp_root,左线索为Child 
	让其右指针指向最后1个结点,右线索为Thread(后继)
	
	中序遍历的第1个结点(最左下结点)
	让其左指针指向 head_thrt,左线索为Thread(前驱)
	中序遍历的最后1个结点(最右下结点)
	让其右指针指向 head_thrt, 右线索为Thread(后继) 
	
	从head_thrt开始,既可以从第1个结点 沿后继遍历
	也可以从最后1个结点沿前驱遍历 
	*/
	void inOrderThreading(){
		
		//创建head_thrt,初始时左右线索皆为Thread ,左右指针皆指向自身 
		head_thrt = new ThreadNode<Type>;
	
		
		if(!mp_root){//空的二叉树 
			//左右指针回指自身
			head_thrt->mp_left = head_thrt;
			head_thrt->mp_right = head_thrt; 
			return;
		}
		
		//更新head_thrt
		head_thrt->left_clue = Child;	
		head_thrt->mp_left = mp_root; 
		
		ThreadNode<Type> *pre = head_thrt;
		
		//从根结点出发进行中序遍历 
		createInThread (mp_root, pre); 
		
		//此时pre指向最后1个结点,右指针指向 head_thrt, 右线索为Thread(后继)
		pre->right_clue = Thread;
		pre->mp_right = head_thrt;
		
		//更新head_thrt,右指针指向最后1个结点,右线索为Thread(后继)	
		head_thrt->right_clue = Thread;
		head_thrt->mp_right = pre; 
	} 
	
	/*ThreadNode<Type> *pre需要被线索化,写操作,参数为& 
	*/
	void createInThread(ThreadNode<Type> * cur, ThreadNode<Type> * &pre){
		if(cur != NULL){
		
			//线索化左子树 
			createInThread(cur->mp_left, pre);
			
			//建立当前结点的前驱线索
			if(!cur->mp_left){ //cur左孩子为空
				cur->left_clue = Thread;
				cur->mp_left = pre; 
			}else{
				cur->left_clue = Child;
			}
			
			//当前结点前驱pre线索化, 建立前驱结点的后继线索 
			if(!pre->mp_right){
				pre->right_clue = Thread;
				pre->mp_right = cur;
			}else{
				pre->right_clue = Child;
			} 
			
			//前驱跟上当前结点 
			pre = cur;
			
			//线索化右子树 
			createInThread(cur->mp_right, pre);
			
		}
		
	}
	
	InOrderThrTree(){
		mp_root = NULL;
		//m_stop = 0;
	}
	~InOrderThrTree(){
		destroyBiTree(mp_root);
	}
	bool isEmpty()const{
		return  NULL == mp_root;
	}
	//获取根结点 
	ThreadNode<Type>* getRoot() const
	{
		return mp_root;

	}
	
	void createBiTreePreFromFile(ifstream &ifs){
		//获取结束值 
		if(ifs.good()){
			ifs >> m_stop; cout<<"stop:" << m_stop << endl;
		}
		else{
			cout << "read file error!" << endl;
		}
		
		createBiTreeByPreOrder(ifs, mp_root);
	}
	
	//利用先序序列建立一颗二叉树,'.'代表空树,从文件中读入 
	//测试用例1：abc..de.g..f...#
	//测试用例2:-+a..*b..-c..d../e..f..#
	//TestCase3:0 1 2 4 7 0 0 0 5 0 0 3 0 6 0 0
	
	void createBiTreeByPreOrder(ifstream &ifs, ThreadNode<Type>* &subTree){
		/*按先序次序输入二叉树中节点的值（一个字符），点号字符表示空树，构造二叉链表表示的二叉树
		注意：若输入的字符数（不含#号）为n个，则相应的空树即点号就应该有n+1个
		*/
		Type e;	
		
		
		if(ifs.good()){
			ifs>>e; 
			//cout << e << ",";
		}
	
		if(e == m_stop){
			subTree = NULL;
			
		}
		else{
				//根结点 
			subTree = new ThreadNode<Type>(e);//	mp_root->m_data = e;
			assert(subTree !=NULL);
			
			//左孩子 
			createBiTreeByPreOrder(ifs, subTree->mp_left);
			
			//右孩子 
			createBiTreeByPreOrder(ifs, subTree->mp_right);
		}
		
	}

	//先序遍历:递归
	void preOrderTraverse(ThreadNode<Type>* cur){
		if(cur!= NULL){
			//visit(cur);
			//cout << cur->m_data << ' ';
			cur->show();
			preOrderTraverse(cur->mp_left);
			preOrderTraverse(cur->mp_right);
		}
	}
	//中序遍历:递归
	void inOrderTraverse(ThreadNode<Type>* cur){
		if(cur!= NULL){
			inOrderTraverse(cur->mp_left);	
			
			cur->show();
			//cout << cur->m_data << ' ';
		
			inOrderTraverse(cur->mp_right);
		}
	}
	//后序遍历:递归
	void postOrderTraverse(ThreadNode<Type>* cur){
		if(cur!= NULL){
			
			postOrderTraverse(cur->mp_left);
			
			postOrderTraverse(cur->mp_right);
			
			//visit(cur);
			cur->show(); 
			//cout << cur->m_data << ' ';
		}
	} //--- postOrderTraverse() END
	
	/*=== 输出:递归	
	@param start:当前结点
	@param n: 当前结点start的高度 
	@param tag: 标识为根,左, 右; 默认为root 
	*/
	void printBiTreeCurs(ThreadNode<Type> *start, int n=1, string tag="Root"){
		if(start == NULL){
			for(int i=0;i<n;i++){
				cout<<" ";
			}
			cout<<"("<<tag<<")"<<"NULL"<<endl;
			return;
		}
		
		//print the right subtree
		printBiTreeCurs(start->mp_right,n+1, "Right"); 
		
		//print blanks with the height of the node
		for(int i=0;i<n;i++){ 
			cout<<" ";
		}
		
		if(n>=0){
			cout<<start->m_data<<"--->"<<tag<<endl;//print the node
		}
		
		//print the left subtree
		printBiTreeCurs(start->mp_left, n+1,"Left"); 
		
	}//--- printBiTreeCurs() END
	
	
	
};


/*
TestCase

stop:0
    (Right)NULL
   6--->Right
    (Left)NULL
  3--->Right
   (Left)NULL
 1--->Root
    (Right)NULL
   5--->Right
    (Left)NULL
  2--->Left
    (Right)NULL
   4--->Left
     (Right)NULL
    7--->Left
     (Left)NULL
No Threading!
preOrder:
[2,0,1,0,3]
[4,0,2,0,5]
[7,0,4,0,NULL]
[NULL,0,7,0,NULL]
[NULL,0,5,0,NULL]
[NULL,0,3,0,6]
[NULL,0,6,0,NULL]


inOrder:
[NULL,0,7,0,NULL]
[7,0,4,0,NULL]
[4,0,2,0,5]
[NULL,0,5,0,NULL]
[2,0,1,0,3]
[NULL,0,3,0,6]
[NULL,0,6,0,NULL]


postOrder:
[NULL,0,7,0,NULL]
[7,0,4,0,NULL]
[NULL,0,5,0,NULL]
[4,0,2,0,5]
[NULL,0,6,0,NULL]
[NULL,0,3,0,6]
[2,0,1,0,3]
After threading,How to Traverse?

--------------------------------
Process exited after 3.1 seconds with return value 3221225725
请按任意键继续. . .
*/

void testThreadTree(){
		InOrderThrTree<int> thr_tree; 
	
	/*theadTreeInt.txt,第1个0是终止数,先序输入 
	0 1 2 4 7 0 0 0 5 0 0 3 0 6 0 0
	*/
	ifstream ifs("theadTreeInt.txt");
	 
	thr_tree.createBiTreePreFromFile(ifs);
	
		
	thr_tree.printBiTreeCurs(thr_tree.getRoot());
	//thr_tree.drawBiTree(thr_tree.getRoot());
	
	//未线索化该二叉树的3种遍历(递归方式) 
	cout << "No Threading!" << endl;
	cout<< "preOrder:\n";thr_tree.preOrderTraverse(thr_tree.getRoot());
	cout<< "\n\ninOrder:\n";thr_tree.inOrderTraverse(thr_tree.getRoot());
	cout<< "\n\npostOrder:\n";thr_tree.postOrderTraverse(thr_tree.getRoot());
	
	thr_tree.inOrderThreading();
	
	//线索化后
	cout << "After threading,How to Traverse?\n";

} 


#endif
