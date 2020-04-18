/*
���ȣ��ø�����n����㽨��һ�ö�����������ʹ
����ÿ������ֵ���ڸý��ķǿ������������н���ֵ��
��С�ڸý��ǿ������������н���ֵ������������Ϊ������������
Ȼ�󣬰���������������������õ�n�����������У�������С�����ź���ġ�
�������ö�����������������ķ�����֮Ϊ��������
18,  14,    7�� 3,  11,  22,  35,  27

*/
#include "comm.h"
#include "BinTNode.h"

template <typename T>
class BinSortTree{
private:
	BinTNode<T> * mp_root;
public:
	//���ɶ���������:����
	//void createBST(vector<T> s, int n){
	void createBST(T s[], int n){
		if(n<1) return;
		T e;
		mp_root = new BinTNode<T>(s[0]);
		
		//���β���
		for(int i=1; i<n; i++){
			insert(mp_root, s[i]);
		} 
		
	}//--- createBST() END
	 
	//�ڸ�Ϊcur�Ķ������в���Ԫ��e 
	void insert(BinTNode<T> * cur, T e){
		
		//�����½�� 
		BinTNode<T> * newNode = new BinTNode<T>(e);
		
		//ѭ������,ֱ���ҵ�newNodeҪ�����λ��
		while(1) { //��������С������
		
			if(moreThan(newNode, cur)){ //newNode > cur
				if(cur->m_right != NULL){
					cur = cur->m_right;
				}
				else{ //cur û�� �Һ���
					//�ҵ�
					cur->m_right = newNode;
					break; 
				}			
				
			} //newNode > cur END
			 
			else{ //newNode <= cur
				if(cur->m_left != NULL){
					cur = cur->m_left;
				}
				else{ //cur û�� ����
					//�ҵ�
					cur->m_left = newNode;
					break; 
				}			
				 
			} //newNode < cur END 
		} 
		
	}//insert() END
	
	//�ݹ����
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
�밴���������. . .

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
