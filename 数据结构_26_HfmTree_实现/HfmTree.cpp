/*Huffman Tree类模板HfmTree.h的实现源文件
FileName: HfmTree.cpp 
*/

#include "HfmTree.h"
#define MAXVALUE 9999
 
//由数组创建Huffman Tree 
template<typename T> 
void HfmTree<T>::createHfmTeeFromArr(T a[], int n){
	initHfm(n);
	
	//读入权值
	int i ;
	for(i=0; i<n; i++){
		mv_ht[i].m_weight = a[i];
	}
	
	//生成Huffman Tree
	buildHfmTree(); 
	
	//show
	for_each(mv_ht.begin(), mv_ht.end(), mem_fun_ref(&HfmTNode<T> :: show ) );
}

/*生成Huffman Tree
① 在F中选取两棵根结点的权值最小的扩充二叉
树, 做为左、右子树构造一棵新的二叉树。置
新的二叉树的根结点的权值为其左、右子树上
根结点的权值之和。
② 在F中删去这两棵二叉树。
③ 把新的二叉树加入F
*/
template<typename T> 
void HfmTree<T>::buildHfmTree(){
	int mini1, mini2; //最小两个结点的下标
	
	//在区间[m_leaf, 2*m_leaf-1]生成结点
	int end;
	for(end = m_leaf; end < 2*m_leaf-1; end++){
		
		//选取最小的两个结点并将下标保存至mini1,mini2
		getDbMini(mini1, mini2, end); 
		
		//更新 向量 mv_ht
		
		//update node end
		mv_ht[end].m_weight = mv_ht[mini1].m_weight + mv_ht[mini2].m_weight;
		mv_ht[end].m_left = mini1;
		mv_ht[end].m_right = mini2;
		
		//update node mini1,mini2
		mv_ht[mini1].m_pa = end;
		mv_ht[mini2].m_pa = end;
		
	} //loop end
}

/*===在向量mv_ht中区间[0,end)选取最小的2个结点并将下标保存至m1,m2
@param m1: int&,引用类型,保存最小结点的下标 
@param m2: int&,引用类型,保存次小结点的下标 
@param end: int,传入区间的下限 
*/
template<typename T> 
void HfmTree<T>::getDbMini(int & m1, int &m2, int end){
	int i;
	
	//擂主(2个):初始化 
	T least = MAXVALUE; //最小者 
	T less = MAXVALUE;  //次小者
	 
	//traverse一次,获取最小的2个结点下标, [0,end)
	for(i=0; i< end; i++){
		//如果该结点已经被选取,忽略 
		if(mv_ht[i].m_pa != -1){
			continue; //跳过 
		} 
		
		//如果结点<最小者 
		if(mv_ht[i].m_weight < least){
			//将最小者保存至次小者 
			less = least; m2 = m1;
			
			//更新最小者 
			least = mv_ht[i].m_weight;
			m1 = i;
		}
		
		//如果结点 <次小者 但 >最小者 
		else if(mv_ht[i].m_weight < less){
			
			//更新次小者 
			less = mv_ht[i].m_weight;
			m2 = i;
		}
		
	}//m1为最小结点的下标,m2为次小结点的下标 
	
}//--- getDbMini() END


	//生成huffman code
template<typename T> 
void HfmTree<T>:: codeFromLeaf(){
	//初始化
	string* p_code;
	int leaf; 
	int cur, pa;//下标:当前,双亲 
	
	mv_code.clear();
	for(leaf = 0; leaf<m_leaf; leaf ++){
		p_code = new string;
		for(cur=leaf,pa=mv_ht[leaf].m_pa ; pa != -1; pa = mv_ht[pa].m_pa){
			if(cur == mv_ht[pa].m_left) {
				p_code->insert(0,"0");
			}
			else{
				p_code->insert(0,"1");
			}
		}//loop END,p_code 保存的是 leaf 编码 
		
		mv_code.push_back(*p_code); 
	}//loop END, mv_code 保存的是所有leaf结点的编码 
	
	//show code
	for(int i=0;i<mv_code.size(); i++){
		cout << mv_code[i] << endl;
	} 
	
	
}
