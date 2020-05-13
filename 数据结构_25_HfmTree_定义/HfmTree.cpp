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
	} 
}

//在向量mv_ht中区间[0,end)选取最小的2个结点并将下标保存至m1,m2
template<typename T> 
void HfmTree<T>::getDbMini(int &m1, int &m2, int end){
	int i;
	
	//擂主(2个)
	T least = MAXVALUE; //最小者 
	T less = MAXVALUE;  //次小者
	 
	//traverse一次,获取最小的2个结点下标, [0,end)
	for(i=0; i< end; i++){
		
		//如果结点<最小者 
		if(mv_ht[i].m_weight < least){
			//将最小者保存至次小者 
			less = least; m2 = m1;
			
			//更新最小者 
			least = mv_ht[i].m_weight;
			m1 = i;
		}
		
		//如果结点<次小者但>最小者 
		else if(mv_ht[i].m_weight < less){
			
			//更新次小者 
			less = mv_ht[i].m_weight;
			m2 = i;
		}
		
	}
	
}
