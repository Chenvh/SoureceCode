#ifndef _HFM_TREE_H_2020
#define _HFM_TREE_H_2020



/*

  template<typename _InputIterator, typename _Function>
    _Function
    for_each(_InputIterator __first, _InputIterator __last, _Function __f)
    {
      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_requires_valid_range(__first, __last);
      for (; __first != __last; ++__first)
	__f(*__first);
      return _GLIBCXX_MOVE(__f);
    }

Huffman算法
(1) 由给定的n个权值{w0, w1, w2, …, wn-1}，构造
具有n棵扩充二叉树的森林F={T0, T1, T2, …,Tn-1}，
其中每棵扩充二叉树Ti只有一个带权
值wi的根结点，其左、右子树均为空。
(2) 重复以下步骤，直到F中仅剩下一棵树为止：
① 在F中选取两棵根结点的权值最小的扩充二叉
树, 做为左、右子树构造一棵新的二叉树。置
新的二叉树的根结点的权值为其左、右子树上
根结点的权值之和。
② 在F中删去这两棵二叉树。
③ 把新的二叉树加入F
*/

#include "HfmTNode.h"

template <typename T>
void visit(HfmTNode<T> *  pnode){
	pnode->show();
}

template <typename T>
class HfmTree{
private:
	
typedef HfmTNode<T> HT;
//PS: 加多空格避免将> >编译为 >> 
typedef vector< HfmTNode<T> > VHT;
	
	int m_leaf; //叶子个数
	//vector向量
	
	VHT mv_ht; //huffman tree
	
	vector<string> mv_code;//huffman code
	 
public:
	//由数组创建Huffman Tree 
	void createHfmTeeFromArr(T a[], int n);
	
	//构建Huffman Tree	
	void buildHfmTree(); 
	
	//在向量mv_ht中区间[0,end)选取最小的2个结点并将下标保存至m1,m2
	void getDbMini(int&,int&, int);
	
	//生成huffman code
	void codeFromLeaf(); 
	
	
	
	//初始化 huffman tree 
	void initHfm( int n){
		m_leaf = n;
		
		//huffman tree 共有2*n-1个结点,初始时为空结点 
		mv_ht.assign(2*n-1, HfmTNode<T>());
		
		//huffman code 共有n个,初始时为空串 
		mv_code.assign(m_leaf, ""); 
		
		//for_each(mv_ht.begin(), mv_ht.end(), visit<T> );
		
		//for_each(mv_ht.begin(), mv_ht.end(), mem_fun_ref(&HfmTNode<T> :: show ) );
	}	
	
	
	 
};




#endif
