#pragma once
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:MSTKruskal.h 最小生成树Kruskal算法 
 *	Descripton:最小生成树Kruskal算法,继承邻接矩阵 
 *
 *******************************/
#include "MergeFindSet.h"
#include "Definition.h"
#include "MSTNode.h"
template<typename NameType, typename CostType>
class MSTKruskal : public MatrixGraph<NameType, CostType> {
private: 

typedef MSTNode<NameType, CostType> MstNode;	
		
	//并查集 ,合并所有顶点至一个集合中. 
	MergeFindSet m_set; 
	
	//优先队列,保存所有的边并按从小到大顺序
	priority_queue<MstNode, vector<MstNode > ,greater<MstNode > >  q_arcs;
	

	//生成的最小生成树
	vector<MstNode > mv_mst;  
	
public:
	//Kruskal 获取最小生成树 
	void miniSpanTree(){
		
		//是无向网 
	if(this->vtx_num>0 && this->Weight && !this->Directed){
			
		initKruskal(); //initialize	
		
		int u,v;
		//N个顶点 N-1条边 
		for(int i=1; i<this->verts.size(); ){//选择 this->verts.size()-1个最小边 
			MstNode node = q_arcs.top(); 
			q_arcs.pop();
			
			//node.show();
			
			u = m_set.find(node.i_from);
			v = m_set.find(node.i_to);
			
			if(u != v){ //不在一个集合
				m_set.merge(u,v);//合并
				//将该node插入至最小生成树中
				mv_mst.push_back(node);
				
				i++;//选择成功 
			}
		}
	}else{
		cout << "Kruskal can not minispan tree!" << endl;
	}	
		
	}//---miniSpanTree() END
	
	
	//=== 输出最小生成树 
	void showVectMST(){
		for(int i=0;i<mv_mst.size(); i++){
			
			mv_mst[i].show();
			cout << endl;
			
		}
		cout << endl;
	}//---showVectMST() END 
	
	
	void initKruskal(){
		//cout <<"queue size: " << q_arcs.size() << endl;
		//cout<<"vertexs:" << this->verts.size() << endl;
		
		//初始时将各顶点下标放入set中 
		m_set.init(this->verts.size());
		
		MstNode node; 
		int i,j;
		//将各顶点的边放入队列中
		for(i=0; i<this->verts.size(); i++){
			for(j=0; j<this->verts.size(); j++){
				if( i!=j && this->matrix_g[i][j].m_cost < (CostType)LIMITED ){ //i,j两点间有边 
					node.set(i,j,this->matrix_g[i][j].m_cost,
						this->verts[i], this->verts[j] );
					//node.show(); 
					q_arcs.push(node);
				}
			}
		
		} 
		
		//cout <<"queue size: " << q_arcs.size() << endl;
	}
	 
};

/*
TestCase:

该图是包含6个顶点及10条弧组成的无向网!!!
各顶点名依次是:
[V1,-1,-1,-1], [V2,-1,-1,-1], [V3,-1,-1,-1], [V4,-1,-1,-1], [V5,-1,-1,-1], [V6,-1,-1,-1]

邻接矩阵是:
(orign,dest):weight
(0,0):0   (0,1):6   (0,2):1   (0,3):5   (0,4):∞  (0,5):∞
(1,0):6   (1,1):0   (1,2):5   (1,3):∞  (1,4):3   (1,5):∞
(2,0):1   (2,1):5   (2,2):0   (2,3):5   (2,4):6   (2,5):4
(3,0):5   (3,1):∞  (3,2):5   (3,3):0   (3,4):∞  (3,5):2
(4,0):∞  (4,1):3   (4,2):6   (4,3):∞  (4,4):0   (4,5):6
(5,0):∞  (5,1):∞  (5,2):4   (5,3):2   (5,4):6   (5,5):0

读取各边数据依次是:
起-终: (权值,备注)
V1—V2：[6,null]
V1—V3：[1,null]
V1—V4：[5,null]
V2—V3：[5,null]
V2—V5：[3,null]
V3—V4：[5,null]
V3—V5：[6,null]
V3—V6：[4,null]
V4—V6：[2,null]
V5—V6：[6,null]

[V1,-1,-1,-1]--[V3,-1,-1,-1]-->(6,[1,null]) 0,2
[V4,-1,-1,-1]--[V6,-1,-1,-1]-->(6,[2,null]) 3,5
[V5,-1,-1,-1]--[V2,-1,-1,-1]-->(6,[3,null]) 4,1
[V3,-1,-1,-1]--[V6,-1,-1,-1]-->(6,[4,null]) 2,5
[V3,-1,-1,-1]--[V2,-1,-1,-1]-->(6,[5,null]) 2,1


--------------------------------
Process exited after 0.5592 seconds with return value 0
请按任意键继续. . .
*/
void testMSTKruskal(){
	string fileName = "udnData1.txt";// "udgData.txt";
	MSTKruskal<string,int> kruskal;

	kruskal.createFromFile(fileName);
	kruskal.show();
	
	kruskal.miniSpanTree();
	kruskal.showVectMST();
	
	
}
