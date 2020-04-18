/*
���ȣ��ø�����n����㽨��һ�ö�����������ʹ
����ÿ������ֵ���ڸý��ķǿ������������н���ֵ��
��С�ڸý��ǿ������������н���ֵ������������Ϊ������������
Ȼ�󣬰���������������������õ�n�����������У�������С�����ź���ġ�
�������ö�����������������ķ�����֮Ϊ��������
18,  14, 7, 3,  11,  22,  35,  27

*/
#include "comm.h"
#include "BinTNode.h"

template <typename T>
class BinSortTree{
private:
	BinTNode<T> * mp_root;
public:
	//��װ���� 
	void delElem(T e){
		removeFromBST(mp_root,e);
	}
	
	//=== ɾ��: �ڸ�Ϊstart��ɾ��Ԫ��e,�ɹ�����true����Ϊfalse
	bool removeFromBST(BinTNode<T> * & start, T e){
		if(NULL == start){
			return false;//����,�����ڸ�Ԫ��,ʧ��,����false 
		}
		else{
			//���� 
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
	
	/*===�ڶ�����������ɾ��curɾ����� 
	@param cur, BinTNode<T> * &,��������,д���� 
	*/
	void delBSTNode(BinTNode<T> *  & cur){
		BinTNode<T> * tmp = cur;
		if(NULL == cur->m_left){//������
			cur = cur->m_right; //���������֮
			delete tmp; 
		} 
		else if(NULL == cur->m_right){//������
			cur = cur->m_left;//���������֮
			delete tmp; 
		}
		else{ //�����ӽԴ���,ȡ����������������֮
			BinTNode<T> * start = cur;
			tmp = cur->m_left;
			//case 1: tmp������,����������������� 
			//case 2: tmp������ 
			
			while(tmp->m_right != NULL){ //case 1
				start = tmp;
				tmp = tmp->m_right;
			}//loop end, tmp->right == NULL
			//tmp Ϊ start������ 
			
			cur->m_data = tmp->m_data;//������������� ֮ 
			
			//ɾ��tmp 
		 	if(start != cur){ //tmp Ϊstart������ ,case 1 
		 		start->m_right = tmp->m_left;//tmp˫��startָ�������� 
			}
			else{ // case 2, tmp Ϊcur(start)������ 
				cur->m_left = tmp->m_left;//tmp˫��curָ�������� 
			} 
			delete tmp;
		}
		
	}
	
	
	
	
	
	
	/*==search:�ڸ�Ϊstart�в���Ԫ��e,�ҵ�����ָ��,���򷵻�NULL 
	@param start: �����ĸ����
	@param e: Ԫ�� 
	*/
	BinTNode<T> * search(BinTNode<T> * start, T e){
		//���������ֵ����Ԫ�� 
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
	
	//���ļ����ɶ���������
	void createBSTFromFile(string fileName){
		ifstream ifs(fileName.c_str());
		T e;
		if(ifs.good()){
			ifs >> e;
		}
		
		mp_root = new BinTNode<T>(e);
		
		//���β�����ļ��ж�ȡ�ĸ�Ԫ�� 
		while(ifs.good()){
			ifs >> e;
			insert(mp_root, e);
		}	
		
	} // --- createBSTFromFile() END 
	
	 
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
	
	bst.delElem(14);
	cout << endl;
	
	bst.inOrderTraverse(bst.getRoot());
	
	
}
