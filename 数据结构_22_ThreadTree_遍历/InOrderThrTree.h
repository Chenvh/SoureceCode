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
		
	}//--- createInThread() END 
	
	
	//寻找以cur为根中序线索树的第一个结点
	ThreadNode<Type> *getFirst(ThreadNode<Type> * cur){
		ThreadNode<Type> *target = cur;
		
		while( target->left_clue == Child){
			target = target->mp_left;
		}//最左下的结点,loop END,target->left_clue == Thread;
		
		return target;
		
	}//--- getFirst() END
	
	//寻找中序线索树结点cur的后继,  
	ThreadNode<Type> * getNext(ThreadNode<Type>* cur){
		ThreadNode<Type> *target = cur->mp_right;
		
		if(cur->right_clue == Child){//有孩子
		 	return getFirst(target);
		}
		return target;
	}//--- getNext() END 
	
	
    /*寻找中序下最后一个结点
      返回以*p_cur为根的中序线索二叉树中序遍历的最后一个结点
    */
    ThreadNode<Type> * getLast(ThreadNode<Type> *p_cur)  {
   
        ThreadNode<Type> *p_target = p_cur;
        while (p_target->right_clue==Child){
        
            p_target = p_target->mp_right;
        }
        return p_target;
    }
    
    //寻找结点在中序下的前驱结点
    ThreadNode<Type>* getPrior(ThreadNode<Type>* p_cur)
    {
        ThreadNode<Type>* p_target = p_cur->mp_left;
        if (p_cur->left_clue==Child){
        
            return getLast(p_target);
        }
        else{
        
            return p_target;
        }
    }
    
    
    //===在中序线索化二叉树中求父节点
   ThreadNode<Type>* getParent(ThreadNode<Type>* p_cur){
    
	  if(p_cur==mp_root){    //根节点无父节点
	  
	      return NULL;
	  }
	  
	  ThreadNode<Type>* p_target;
	  for (p_target = p_cur; p_target->left_clue == Child; p_target = p_target->mp_left) {
	  	
	  } //loop END,p_target->left_clue == Thread,
	  //即p_cur为根的中序下的第一个结点p_target
	  
		
		//取第1个结点前驱, (如果是中序遍历第1个结点,则其前驱为头结点; 
		p_target = p_target->mp_left; 
	   
		 	
	   if(p_target->mp_right == p_cur){
	   	return p_target;//找到 
		}
		
		//至此仍未找到 
		//从p_target的右孩子开始，沿着左孩子，一直找到一个结点，
		//p_cur是这个结点的左孩子
		p_target=p_target->mp_right;//取其右孩子(即前驱的右孩子)
		 
		while(p_target->mp_left != p_cur){
			p_target=p_target->mp_left;
		}
	   return p_target;
		 
	    /*
	    下面的编码太繁琐了 
		 
		  //情况1
	     if (p_target->mp_left != NULL)    //当p_target左子树指向不为空
	     {
	         
				//令p_target为p_target的左子树指向的结点，
				//判断此结点是否并且此节点的左右子树结点的指向都不为p_cur，
				//再将p_target为p_target的右孩子结点
	         
				for (p_target = p_target->mp_left; 
						p_target!= NULL && p_target->mp_left!=p_cur &&	p_target->mp_right!= p_cur; 
						p_target = p_target->mp_right){
				}
	     }
	     //情况2
	     //如果上面的循环完了，由于是p_target==NULL结束的循环，
		  //没有找到与p_cur相等的结点，就是一直找到了中序线索化的第一个结点了，
		  //这时候这种就要用到情况2的方法
	     if (p_target==NULL||p_target->mp_left==NULL)
	     {
	         //找到*p_cur为根的中序下的最后一个结点
	         for (p_target = p_cur; p_target->right_clue == 0; p_target = p_target->mp_right){
				}
	         //让后让他指向最后一个结点指向的结点，从这个结点开始，以此判断它的左孩子孩子和右孩子是否和p_cur相等
	         for (p_target = p_target->mp_right; p_target != NULL&&p_target->mp_left != p_cur&&p_target->mp_right != p_cur; p_target = p_target->mp_left);
	     }
	     return p_target;
	     */
	     
	 }// --- getParent() END
	 
	 
	
	
	
	//输出树中从cur开始按中序的全部结点
	void inOrderThreadTree(ThreadNode<Type> * cur){
		ThreadNode<Type> *start = getFirst(cur);
		
		//while(start != head_thrt){ //error,end of head_thrt,not NULL  
		while(start != head_thrt){ 
			
			start->show();
			start = getNext(start);
		}
	}//---inOrderThreadTree 
	
	
	
    //=== 中序线索化二叉树上实现前序遍历的算法
    void preOrderThreadTree(ThreadNode<Type>* p_cur)
    {
        //while (p_cur!=NULL){
        while (p_cur!= head_thrt){
        	
            //cout << p_cur->data<<" ";    //先访问根节点
            p_cur->show();
            if (p_cur->left_clue==Child)
            {
                p_cur = p_cur->mp_left;    //有左子树，即为后继
            }
            else if(p_cur->right_clue==Child)    //否则，有右子树，即为后继
            {
                p_cur = p_cur->mp_right;
            }
            else  {   //无左右子树
           
               //while (p_cur!=NULL&&p_cur->right_clue==1) {   //检测后继线索
               while (p_cur!= head_thrt &&p_cur->right_clue==1) {   //检测后继线索
                    p_cur = p_cur->mp_right;    //直到找到有右子树的结点
                }
                //if (p_cur!=NULL){    
                if (p_cur!= head_thrt){    
                    p_cur = p_cur->mp_right;    //该结点的右子树为后继
                }
            }
        }
        cout << endl;
    }//---preOrderThreadTree() ENDING
    
   //中序线索二叉树的后序遍历算法
   void postOrderThreadTree(ThreadNode<Type>* p_cur){
    
     ThreadNode<Type>* p_move = p_cur;
     
       //寻找后续第一个结点
     while (p_move->left_clue==Child ||p_move->right_clue==Child){  
     
         if(p_move->left_clue==Child){
         
             p_move = p_move->mp_left;
         }
         else if(p_move->right_clue==Child){
         
             p_move = p_move->mp_right;
         }
     }
     p_move->show();
     //cout << p_move->data<<" ";    //访问第一个结点
     while ((p_cur=getParent(p_move))!= NULL){    //每次都先找到当前结点的父结点
     
         //若当前结点是父节点的右子树或者当前结点是左子树，但是这个父节点没有右子树，则后续下的后继为改父节点
         if (p_cur->mp_right==p_move||p_cur->right_clue==1)
         {
             p_move = p_cur;
         }
         //否则，在当前结点的右子树（如果存在）上重复执行上面的操作
         else
         {
             p_move = p_cur->mp_right;
             while (p_move->left_clue==Child || p_move->right_clue==Child)
             {
                 if (p_move->left_clue==Child){
                 
                     p_move = p_move->mp_left;
                 }
                 else if (p_move->right_clue==Child)
                 {
                     p_move = p_move->mp_right;
                 }
             }
         }
         p_move->show();
         //cout << p_move->data << " ";
     }
    }//--- postOrderThreadTree() END

	
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
	cout << endl << endl;
	
	//线索化后
	cout << "After threading,How to Traverse?\n";
	
	//cout<< "\n\ninOrder:\n";thr_tree.inOrderTraverse(thr_tree.getRoot());//error
	cout << endl ;
	cout << "preOrder:\n";
	thr_tree.preOrderThreadTree(thr_tree.getRoot());

	cout << endl ;
	cout << "inOrder:\n";
	thr_tree.inOrderThreadTree(thr_tree.getRoot());

	cout << endl ;
	cout << "postOrder:\n";
	thr_tree.postOrderThreadTree(thr_tree.getRoot());


} 

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

preOrder:
[2,0,1,0,3]
[4,0,2,0,5]
[7,0,4,1,2]
[12724128,1,7,1,4]
[2,1,5,1,1]
[1,1,3,0,6]
[3,1,6,1,12724128]


inOrder:
[12724128,1,7,1,4]
[7,0,4,1,2]
[4,0,2,0,5]
[2,1,5,1,1]
[2,0,1,0,3]
[1,1,3,0,6]
[3,1,6,1,12724128]

postOrder:
[12724128,1,7,1,4]
[7,0,4,1,2]
[2,1,5,1,1]
[4,0,2,0,5]
[3,1,6,1,12724128]
[1,1,3,0,6]
[2,0,1,0,3]

--------------------------------
Process exited after 22.56 seconds with return value 3221225725
请按任意键继续. . .
*/


#endif
