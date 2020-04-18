/*
首先，用给定的n个结点建造一棵二叉排序树，使
树中每个结点的值大于该结点的非空左子树中所有结点的值，
而小于该结点非空右子树中所有结点的值，称这样的树为二叉排序树。
然后，按中序遍历二叉排序树，得到n个结点的新序列，它是由小到大排好序的。
这种利用二叉排序树进行排序的方法称之为二叉排序。
18,  14,    7， 3,  11,  22,  35,  27

*/
#include "comm.h"
#include "BinTNode.h"

template <typename T>
class BinSortTree{
private:
	BinTNode<T> * mp_root;
public:
	//生成二叉排序树:数组
	//void createBST(vector<T> s, int n){
	void createBST(T s[], int n){
		if(n<1) return;
		T e;
		mp_root = new BinTNode<T>(s[0]);
		
		//依次插入
		for(int i=1; i<n; i++){
			insert(mp_root, s[i]);
		} 
		
	}//--- createBST() END
	 
	//在根为cur的二叉树中插入元素e 
	void insert(BinTNode<T> * cur, T e){
		
		//生成新结点 
		BinTNode<T> * newNode = new BinTNode<T>(e);
		
		//循环查找,直到找到newNode要插入的位置
		while(1) { //大则向左、小则向右
		
			if(moreThan(newNode, cur)){ //newNode > cur
				if(cur->m_right != NULL){
					cur = cur->m_right;
				}
				else{ //cur 没有 右孩子
					//找到
					cur->m_right = newNode;
					break; 
				}			
				
			} //newNode > cur END
			 
			else{ //newNode <= cur
				if(cur->m_left != NULL){
					cur = cur->m_left;
				}
				else{ //cur 没有 左孩子
					//找到
					cur->m_left = newNode;
					break; 
				}			
				 
			} //newNode < cur END 
		} 
		
	}//insert() END
	
	//递归遍历
	//LVR
	void inOrderTraverse(BinTNode<T>* cur){
		if(cur != NULL){
			inOrderTraverse(cur->m_left);
			
			visit(cur); //visit;
			
			inOrderTraverse(cur->m_right);
			
		}
	} 
	
	bool moreThan(BinTNode<T>* one, BinTNode<T>* another ){
		return (one->m_data > another->m_data);
	}
	
	void visit(BinTNode<T>* cur){
		cur->show();
		cout << ",";
		//cout << cur->m_data << ",";
	}
	
	BinSortTree(){
		mp_root = NULL;
	}
	
	BinTNode<T>* getRoot(){
		return mp_root;
	}
	
};

/*
TestCase

3,7,11,14,18,22,27,35,

--------------------------------
Process exited after 0.8703 seconds with return value 0
请按任意键继续. . .

*/

void testBST(){
	vector<int> vi;
	int a[] = {18,14,7,3,11,22,35,27};
	for( int i = 0; i < 8; i++ ) {
    vi.push_back(a[i]);
  }
	
	BinSortTree<int> bst;
	bst.createBST(a,8);
	
	bst.inOrderTraverse(bst.getRoot());
	
}
