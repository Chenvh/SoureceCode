/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:
 *	Descripton: MiniSpanTree Prim�㷨���� 
 *
 *******************************/
#include "Definition.h"
#include "MSTNode.h"
template<typename NameType, typename CostType>
class MSTPrim:public MatrixGraph<NameType, CostType>{

private:
	vector<ArcNodeAdj<CostType> > mv_miniArc;
	vector<MSTNode<NameType,CostType> > mv_mst; 

	void init(int cur){
		ArcNodeAdj<CostType> arc;
		//arc.m_arc.m_cost = 0;
		
		cout << this->vtx_num << "," << this->Weight << "," << this->Directed << endl;
		
		mv_miniArc.assign(this->vtx_num , arc);
		
		//��ʼ��miniArc,���� ������start ������������ľ���,�������cur�� 
		for(int col=0;  col<this->vtx_num ; col++ ){		
			//��cur�е�col�� 
			mv_miniArc[col].m_dest = cur;
			mv_miniArc[col].m_arc.m_cost = this->matrix_g[cur][col].m_cost;	
		} 
		
		showVectArcAdj();		
	}
	
	
public:
	//Prim�㷨
	void miniSpanTree(int start){
		//����������� 
		if(this->vtx_num >0 && this->Weight && !this->Directed){
			
			//step1: ��ʼ��
			init(start); 
			
			int dest;
			//step2:���ι��������,N�����㹲N-1���� 
			for(int i=0; i<this->vtx_num-1; i++  ){//�� this->vtx_num -1 ��
				//step3: �ӳ����㿪ʼ�����е��ڽӱ���ѡȡһ����С��
				dest = getIdMiniCostArc();
				
				MSTNode<NameType,CostType> mstNode;
				mstNode.m_from = this->verts[ mv_miniArc[dest].m_dest];
				mstNode.m_adjArc.m_dest = dest;
				mstNode.m_adjArc.m_arc.m_cost = mv_miniArc[dest].m_arc.m_cost ;
				mstNode.m_to = this->verts[ dest ];
				mv_mst.push_back(mstNode);
				
				//Visit(this->verts[ mv_miniArc[dest].m_dest]);
				//Visit(this->verts[ dest ]); 
				//cout << mv_miniArc[dest].m_arc.m_cost << endl;
				
				//�ϲ��õ�,������dest��m_cost����Ϊ0
				mv_miniArc[dest].m_arc.m_cost = 0;
				 
				//����mv_miniAr
				//������������dest�� m_cost
				resetVectMiniArc(dest); 
				
				//showVectArcAdj();
			 
			}
			
		}
		else{//��������,������
			cout << "No undirected net!No suitable the algorithm!" << endl;
			return; 
		}
		
	}//---  miniSpanTree() END
	
	
	//=== resetVectMiniArc���¸����㵽��ǰ���m_cost 
	void resetVectMiniArc(int cur){
		
		//��ʼ��miniArc,���� ������start ������������ľ���,�������i�� 
		for(int col=0;  col<this->vtx_num ; col++ ){
		
			//���cur������col�Ĵ��� m_cost< ��������� ����,�����
			//��cur�е�col�� 
			if( mv_miniArc[col].cmpCost(this->matrix_g[cur][col].m_cost) > 0 ){				
				mv_miniArc[col].m_dest = cur;
				mv_miniArc[col].m_arc.m_cost = this->matrix_g[cur][col].m_cost;	
			}
		
			
		} 
	}//--- resetVectMiniArc() END
	
	
	//=== getIdMiniCostArc ���������������arc��ѡȡ��С�� 
	int getIdMiniCostArc(){
		int i, m_id;//�����±� master index
		
		//step1:ѡ�����±� master index
		for(m_id=0;mv_miniArc[m_id].cmpCost(0) == 0; m_id ++){
		} 
		
		//step2:�ں�����ʣ���������PK
		for(i = m_id+1; i<mv_miniArc.size(); i++){
			//arc�����ұ�����С
			if(mv_miniArc[i].cmpCost(0) != 0 && 
				mv_miniArc[i].lessThan( mv_miniArc[m_id]) ) {
					m_id = i;
			}
		} 
		return m_id; 
	}//--- getIdMiniCostArc() END
	
	void showVectArcAdj(){
		for(int i=0;i<mv_miniArc.size(); i++){
			
			mv_miniArc[i].show();
			cout << " , ";
			
		}
		cout << endl;
	//	for_each(mv_miniArc.begin(), mv_miniArc.end(), mem_fun(ArcVertexAdj::show);
		 
	}
	
	void showVectMST(){
		for(int i=0;i<mv_mst.size(); i++){
			
			mv_mst[i].show();
			cout << endl;
			
		}
		cout << endl;
	}
	

};

/*
TestCase

udnData1.txt
false
true
6
V1 V2 V3 V4 V5 V6
10
V1 V2 6
V1 V3 1
V1 V4 5
V2 V3 5
V2 V5 3
V3 V4 5
V3 V5 6
V3 V6 4
V4 V6 2
V5 V6 6


false,true
6
��ͼ�ǰ���6�����㼰10������ɵ�������!!!
��������������:
[V1,-1,-1,-1], [V2,-1,-1,-1], [V3,-1,-1,-1], [V4,-1,-1,-1], [V5,-1,-1,-1], [V6,-1,-1,-1]

�ڽӾ�����:
(orign,dest):weight
(0,0):0   (0,1):6   (0,2):1   (0,3):5   (0,4):��  (0,5):��
(1,0):6   (1,1):0   (1,2):5   (1,3):��  (1,4):3   (1,5):��
(2,0):1   (2,1):5   (2,2):0   (2,3):5   (2,4):6   (2,5):4
(3,0):5   (3,1):��  (3,2):5   (3,3):0   (3,4):��  (3,5):2
(4,0):��  (4,1):3   (4,2):6   (4,3):��  (4,4):0   (4,5):6
(5,0):��  (5,1):��  (5,2):4   (5,3):2   (5,4):6   (5,5):0

��ȡ��������������:
��-��: (Ȩֵ,��ע)
V1��V2��[6,null]
V1��V3��[1,null]
V1��V4��[5,null]
V2��V3��[5,null]
V2��V5��[3,null]
V3��V4��[5,null]
V3��V5��[6,null]
V3��V6��[4,null]
V4��V6��[2,null]
V5��V6��[6,null]

6,true,false
(0,[0,null]) , (0,[6,null]) , (0,[1,null]) , (0,[5,null]) , (0,[9999,null]) , (0,[9999,null]) ,
[V1,-1,-1,-1]--[V3,-1,-1,-1]-->(2,[1,null])
[V3,-1,-1,-1]--[V6,-1,-1,-1]-->(5,[4,null])
[V6,-1,-1,-1]--[V4,-1,-1,-1]-->(3,[2,null])
[V3,-1,-1,-1]--[V2,-1,-1,-1]-->(1,[5,null])
[V2,-1,-1,-1]--[V5,-1,-1,-1]-->(4,[3,null])


--------------------------------
Process exited after 0.3641 seconds with return value 0
�밴���������. . . 
*/



void testMSTPrim(){
	string fileName = "udnData1.txt";// "udgData.txt";
	MSTPrim<string,int> prim;

	prim.createFromFile(fileName);
	prim.show();
	
	prim.miniSpanTree(0);
	prim.showVectMST();
	
	
}
