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
 *	fileName: InOrderThrTree.h ������������ģ�� 
 *	Descripton:InOrderThrTree.h ������������ģ��,ʵ�ֱ��� 
 * ��������������:������������������������� 
 
 ����˫������. �ܴӵ�1�����(head)���Ա��������1�����.
 Ҳ���Դ����1���������(��ǰ)���Ա�������1�����(head).
 ˫��������ѭ��˫������.head��prior(ǰ��)ָ�����1���ڵ�.
 ͬ��,���1������next(���)ָ���1�����(head) 
 
 
 *******************************/

//#include "data.h"
#include "comm.h"
#include "ThreadNode.h" 
#define MAXDEPTH 100 

template<typename Type>
class InOrderThrTree{
	//������������ͷ��� ,����˫ѭ�������head 
	ThreadNode<Type>* head_thrt ;
	
	ThreadNode<Type> * mp_root; //�� 
	
	Type m_stop; 
	
	//���� 
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
	
	/*�������������������. 
	����һ�����head_thrt,
	������ָ��ָ������mp_root,������ΪChild 
	������ָ��ָ�����1�����,������ΪThread(���)
	
	��������ĵ�1�����(�����½��)
	������ָ��ָ�� head_thrt,������ΪThread(ǰ��)
	������������1�����(�����½��)
	������ָ��ָ�� head_thrt, ������ΪThread(���) 
	
	��head_thrt��ʼ,�ȿ��Դӵ�1����� �غ�̱���
	Ҳ���Դ����1�������ǰ������ 
	*/
	void inOrderThreading(){
		
		//����head_thrt,��ʼʱ����������ΪThread ,����ָ���ָ������ 
		head_thrt = new ThreadNode<Type>;
	
		
		if(!mp_root){//�յĶ����� 
			//����ָ���ָ����
			head_thrt->mp_left = head_thrt;
			head_thrt->mp_right = head_thrt; 
			return;
		}
		
		//����head_thrt
		head_thrt->left_clue = Child;	
		head_thrt->mp_left = mp_root; 
		
		ThreadNode<Type> *pre = head_thrt;
		
		//�Ӹ������������������ 
		createInThread (mp_root, pre); 
		
		//��ʱpreָ�����1�����,��ָ��ָ�� head_thrt, ������ΪThread(���)
		pre->right_clue = Thread;
		pre->mp_right = head_thrt;
		
		//����head_thrt,��ָ��ָ�����1�����,������ΪThread(���)	
		head_thrt->right_clue = Thread;
		head_thrt->mp_right = pre; 
	} 
	
	/*ThreadNode<Type> *pre��Ҫ��������,д����,����Ϊ& 
	*/
	void createInThread(ThreadNode<Type> * cur, ThreadNode<Type> * &pre){
		if(cur != NULL){
		
			//������������ 
			createInThread(cur->mp_left, pre);
			
			//������ǰ����ǰ������
			if(!cur->mp_left){ //cur����Ϊ��
				cur->left_clue = Thread;
				cur->mp_left = pre; 
			}else{
				cur->left_clue = Child;
			}
			
			//��ǰ���ǰ��pre������, ����ǰ�����ĺ������ 
			if(!pre->mp_right){
				pre->right_clue = Thread;
				pre->mp_right = cur;
			}else{
				pre->right_clue = Child;
			} 
			
			//ǰ�����ϵ�ǰ��� 
			pre = cur;
			
			//������������ 
			createInThread(cur->mp_right, pre);
			
		}
		
	}//--- createInThread() END 
	
	
	//Ѱ����curΪ�������������ĵ�һ�����
	ThreadNode<Type> *getFirst(ThreadNode<Type> * cur){
		ThreadNode<Type> *target = cur;
		
		while( target->left_clue == Child){
			target = target->mp_left;
		}//�����µĽ��,loop END,target->left_clue == Thread;
		
		return target;
		
	}//--- getFirst() END
	
	//Ѱ���������������cur�ĺ��,  
	ThreadNode<Type> * getNext(ThreadNode<Type>* cur){
		ThreadNode<Type> *target = cur->mp_right;
		
		if(cur->right_clue == Child){//�к���
		 	return getFirst(target);
		}
		return target;
	}//--- getNext() END 
	
	
    /*Ѱ�����������һ�����
      ������*p_curΪ������������������������������һ�����
    */
    ThreadNode<Type> * getLast(ThreadNode<Type> *p_cur)  {
   
        ThreadNode<Type> *p_target = p_cur;
        while (p_target->right_clue==Child){
        
            p_target = p_target->mp_right;
        }
        return p_target;
    }
    
    //Ѱ�ҽ���������µ�ǰ�����
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
    
    
    //===���������������������󸸽ڵ�
   ThreadNode<Type>* getParent(ThreadNode<Type>* p_cur){
    
	  if(p_cur==mp_root){    //���ڵ��޸��ڵ�
	  
	      return NULL;
	  }
	  
	  ThreadNode<Type>* p_target;
	  for (p_target = p_cur; p_target->left_clue == Child; p_target = p_target->mp_left) {
	  	
	  } //loop END,p_target->left_clue == Thread,
	  //��p_curΪ���������µĵ�һ�����p_target
	  
		
		//ȡ��1�����ǰ��, (��������������1�����,����ǰ��Ϊͷ���; 
		p_target = p_target->mp_left; 
	   
		 	
	   if(p_target->mp_right == p_cur){
	   	return p_target;//�ҵ� 
		}
		
		//������δ�ҵ� 
		//��p_target���Һ��ӿ�ʼ���������ӣ�һֱ�ҵ�һ����㣬
		//p_cur�������������
		p_target=p_target->mp_right;//ȡ���Һ���(��ǰ�����Һ���)
		 
		while(p_target->mp_left != p_cur){
			p_target=p_target->mp_left;
		}
	   return p_target;
		 
	    /*
	    ����ı���̫������ 
		 
		  //���1
	     if (p_target->mp_left != NULL)    //��p_target������ָ��Ϊ��
	     {
	         
				//��p_targetΪp_target��������ָ��Ľ�㣬
				//�жϴ˽���Ƿ��Ҵ˽ڵ��������������ָ�򶼲�Ϊp_cur��
				//�ٽ�p_targetΪp_target���Һ��ӽ��
	         
				for (p_target = p_target->mp_left; 
						p_target!= NULL && p_target->mp_left!=p_cur &&	p_target->mp_right!= p_cur; 
						p_target = p_target->mp_right){
				}
	     }
	     //���2
	     //��������ѭ�����ˣ�������p_target==NULL������ѭ����
		  //û���ҵ���p_cur��ȵĽ�㣬����һֱ�ҵ��������������ĵ�һ������ˣ�
		  //��ʱ�����־�Ҫ�õ����2�ķ���
	     if (p_target==NULL||p_target->mp_left==NULL)
	     {
	         //�ҵ�*p_curΪ���������µ����һ�����
	         for (p_target = p_cur; p_target->right_clue == 0; p_target = p_target->mp_right){
				}
	         //�ú�����ָ�����һ�����ָ��Ľ�㣬�������㿪ʼ���Դ��ж��������Ӻ��Ӻ��Һ����Ƿ��p_cur���
	         for (p_target = p_target->mp_right; p_target != NULL&&p_target->mp_left != p_cur&&p_target->mp_right != p_cur; p_target = p_target->mp_left);
	     }
	     return p_target;
	     */
	     
	 }// --- getParent() END
	 
	 
	
	
	
	//������д�cur��ʼ�������ȫ�����
	void inOrderThreadTree(ThreadNode<Type> * cur){
		ThreadNode<Type> *start = getFirst(cur);
		
		//while(start != head_thrt){ //error,end of head_thrt,not NULL  
		while(start != head_thrt){ 
			
			start->show();
			start = getNext(start);
		}
	}//---inOrderThreadTree 
	
	
	
    //=== ������������������ʵ��ǰ��������㷨
    void preOrderThreadTree(ThreadNode<Type>* p_cur)
    {
        //while (p_cur!=NULL){
        while (p_cur!= head_thrt){
        	
            //cout << p_cur->data<<" ";    //�ȷ��ʸ��ڵ�
            p_cur->show();
            if (p_cur->left_clue==Child)
            {
                p_cur = p_cur->mp_left;    //������������Ϊ���
            }
            else if(p_cur->right_clue==Child)    //����������������Ϊ���
            {
                p_cur = p_cur->mp_right;
            }
            else  {   //����������
           
               //while (p_cur!=NULL&&p_cur->right_clue==1) {   //���������
               while (p_cur!= head_thrt &&p_cur->right_clue==1) {   //���������
                    p_cur = p_cur->mp_right;    //ֱ���ҵ����������Ľ��
                }
                //if (p_cur!=NULL){    
                if (p_cur!= head_thrt){    
                    p_cur = p_cur->mp_right;    //�ý���������Ϊ���
                }
            }
        }
        cout << endl;
    }//---preOrderThreadTree() ENDING
    
   //���������������ĺ�������㷨
   void postOrderThreadTree(ThreadNode<Type>* p_cur){
    
     ThreadNode<Type>* p_move = p_cur;
     
       //Ѱ�Һ�����һ�����
     while (p_move->left_clue==Child ||p_move->right_clue==Child){  
     
         if(p_move->left_clue==Child){
         
             p_move = p_move->mp_left;
         }
         else if(p_move->right_clue==Child){
         
             p_move = p_move->mp_right;
         }
     }
     p_move->show();
     //cout << p_move->data<<" ";    //���ʵ�һ�����
     while ((p_cur=getParent(p_move))!= NULL){    //ÿ�ζ����ҵ���ǰ���ĸ����
     
         //����ǰ����Ǹ��ڵ�����������ߵ�ǰ�����������������������ڵ�û����������������µĺ��Ϊ�ĸ��ڵ�
         if (p_cur->mp_right==p_move||p_cur->right_clue==1)
         {
             p_move = p_cur;
         }
         //�����ڵ�ǰ������������������ڣ����ظ�ִ������Ĳ���
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
	//��ȡ����� 
	ThreadNode<Type>* getRoot() const
	{
		return mp_root;

	}
	
	void createBiTreePreFromFile(ifstream &ifs){
		//��ȡ����ֵ 
		if(ifs.good()){
			ifs >> m_stop; cout<<"stop:" << m_stop << endl;
		}
		else{
			cout << "read file error!" << endl;
		}
		
		createBiTreeByPreOrder(ifs, mp_root);
	}
	
	//�����������н���һ�Ŷ�����,'.'�������,���ļ��ж��� 
	//��������1��abc..de.g..f...#
	//��������2:-+a..*b..-c..d../e..f..#
	//TestCase3:0 1 2 4 7 0 0 0 5 0 0 3 0 6 0 0
	
	void createBiTreeByPreOrder(ifstream &ifs, ThreadNode<Type>* &subTree){
		/*�������������������нڵ��ֵ��һ���ַ���������ַ���ʾ������������������ʾ�Ķ�����
		ע�⣺��������ַ���������#�ţ�Ϊn��������Ӧ�Ŀ�������ž�Ӧ����n+1��
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
				//����� 
			subTree = new ThreadNode<Type>(e);//	mp_root->m_data = e;
			assert(subTree !=NULL);
			
			//���� 
			createBiTreeByPreOrder(ifs, subTree->mp_left);
			
			//�Һ��� 
			createBiTreeByPreOrder(ifs, subTree->mp_right);
		}
		
	}

	//�������:�ݹ�
	void preOrderTraverse(ThreadNode<Type>* cur){
		if(cur!= NULL){
			//visit(cur);
			//cout << cur->m_data << ' ';
			cur->show();
			preOrderTraverse(cur->mp_left);
			preOrderTraverse(cur->mp_right);
		}
	}
	//�������:�ݹ�
	void inOrderTraverse(ThreadNode<Type>* cur){
		if(cur!= NULL){
			inOrderTraverse(cur->mp_left);	
			
			cur->show();
			//cout << cur->m_data << ' ';
		
			inOrderTraverse(cur->mp_right);
		}
	}
	//�������:�ݹ�
	void postOrderTraverse(ThreadNode<Type>* cur){
		if(cur!= NULL){
			
			postOrderTraverse(cur->mp_left);
			
			postOrderTraverse(cur->mp_right);
			
			//visit(cur);
			cur->show(); 
			//cout << cur->m_data << ' ';
		}
	} //--- postOrderTraverse() END
	
	/*=== ���:�ݹ�	
	@param start:��ǰ���
	@param n: ��ǰ���start�ĸ߶� 
	@param tag: ��ʶΪ��,��, ��; Ĭ��Ϊroot 
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
	
	/*theadTreeInt.txt,��1��0����ֹ��,�������� 
	0 1 2 4 7 0 0 0 5 0 0 3 0 6 0 0
	*/
	ifstream ifs("theadTreeInt.txt");
	 
	thr_tree.createBiTreePreFromFile(ifs);
	
		
	thr_tree.printBiTreeCurs(thr_tree.getRoot());
	//thr_tree.drawBiTree(thr_tree.getRoot());
	
	//δ�������ö�������3�ֱ���(�ݹ鷽ʽ) 
	cout << "No Threading!" << endl;
	cout<< "preOrder:\n";thr_tree.preOrderTraverse(thr_tree.getRoot());
	cout<< "\n\ninOrder:\n";thr_tree.inOrderTraverse(thr_tree.getRoot());
	cout<< "\n\npostOrder:\n";thr_tree.postOrderTraverse(thr_tree.getRoot());
	
	thr_tree.inOrderThreading();
	cout << endl << endl;
	
	//��������
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
�밴���������. . .
*/


#endif
