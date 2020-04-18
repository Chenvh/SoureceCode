/*
首先，用给定的n个结点建造一棵二叉排序树，使
树中每个结点的值大于该结点的非空左子树中所有结点的值，
而小于该结点非空右子树中所有结点的值，称这样的树为二叉排序树。
然后，按中序遍历二叉排序树，得到n个结点的新序列，它是由小到大排好序的。
这种利用二叉排序树进行排序的方法称之为二叉排序。
18,  14, 7, 3,  11,  22,  35,  27

*/
#include "comm.h"
#include "BinTNode.h"

template <typename T>
class BinSortTree{
private:
	BinTNode<T> * mp_root;
public:
	//包装方法 
	void delElem(T e){
		removeFromBST(mp_root,e);
	}
	
	//=== 删除: 在根为start中删除元素e,成功返回true否则为false
	bool removeFromBST(BinTNode<T> * & start, T e){
		if(NULL == start){
			return false;//空树,不存在该元素,失败,返回false 
		}
		else{
			//查找 
			//BinTNode<T> * target = search(start, e);//error
			
			if( !cmpType(start->m_data,e) ){
				delBSTNode(start);
			}
			else if(cmpType(start->m_data,e) > 0){ //start > e
				removeFromBST(start->m_left, e);
				
			}
			else{ //start < e
				removeFromBST(start->m_right, e);
			}
			
		} 
	}//--- removeFromBST() END
	
	/*===在二叉排序树中删除cur删除结点 
	@param cur, BinTNode<T> * &,引用类型,写操作 
	*/
	void delBSTNode(BinTNode<T> *  & cur){
		BinTNode<T> * tmp = cur;
		if(NULL == cur->m_left){//无左子
			cur = cur->m_right; //用右子替代之
			delete tmp; 
		} 
		else if(NULL == cur->m_right){//无右子
			cur = cur->m_left;//用左子替代之
			delete tmp; 
		}
		else{ //左右子皆存在,取左子树中最大者替代之
			BinTNode<T> * start = cur;
			tmp = cur->m_left;
			//case 1: tmp有右子,最大者在其最右子上 
			//case 2: tmp无右子 
			
			while(tmp->m_right != NULL){ //case 1
				start = tmp;
				tmp = tmp->m_right;
			}//loop end, tmp->right == NULL
			//tmp 为 start的右子 
			
			cur->m_data = tmp->m_data;//用最大的左子替代 之 
			
			//删除tmp 
		 	if(start != cur){ //tmp 为start的右子 ,case 1 
		 		start->m_right = tmp->m_left;//tmp双亲start指向其左子 
			}
			else{ // case 2, tmp 为cur(start)的左子 
				cur->m_left = tmp->m_left;//tmp双亲cur指向其左子 
			} 
			delete tmp;
		}
		
	}
	
	
	
	
	
	
	/*==search:在根为start中查找元素e,找到返回指针,否则返回NULL 
	@param start: 子树的根结点
	@param e: 元素 
	*/
	BinTNode<T> * search(BinTNode<T> * start, T e){
		//空树或根的值等于元素 
		if(NULL == start || !cmpTye( start->m_data,e) ){
			return start;
		}
		else if(cmpType(start->m_data, e) < 0){ //start < e
			return search(start->m_right, e);
		} 
		else{ //start > e
			return search(start->m_left, e);
		}
		
	} //---search() END
	
	
	
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
	
	//由文件生成二叉排序树
	void createBSTFromFile(string fileName){
		ifstream ifs(fileName.c_str());
		T e;
		if(ifs.good()){
			ifs >> e;
		}
		
		mp_root = new BinTNode<T>(e);
		
		//依次插入从文件中读取的各元素 
		while(ifs.good()){
			ifs >> e;
			insert(mp_root, e);
		}	
		
	} // --- createBSTFromFile() END 
	
	 
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
	
	//return, 0: e1==e1; 1: e1>e2; -1: e1<e2;
	int cmpType(T e1, T e2){
		return (e1>e2 ? 1 : ( e1<e2 ? -1 : 0 ) );
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
3,7,11,18,22,27,35,

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
	
	bst.delElem(14);
	cout << endl;
	
	bst.inOrderTraverse(bst.getRoot());
	
	
}
