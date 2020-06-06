#pragma once
/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:MSTKruskal.h ��С������Kruskal�㷨 
 *	Descripton:��С������Kruskal�㷨,�̳��ڽӾ��� 
 *
 *******************************/
#include "MergeFindSet.h"
#include "Definition.h"
#include "MSTNode.h"
template<typename NameType, typename CostType>
class MSTKruskal : public MatrixGraph<NameType, CostType> {
private: 

typedef MSTNode<NameType, CostType> MstNode;	
		
	//���鼯 ,�ϲ����ж�����һ��������. 
	MergeFindSet m_set; 
	
	//���ȶ���,�������еı߲�����С����˳��
	priority_queue<MstNode, vector<MstNode > ,greater<MstNode > >  q_arcs;
	

	//���ɵ���С������
	vector<MstNode > mv_mst;  
	
public:
	//Kruskal ��ȡ��С������ 
	void miniSpanTree(){
		
		//�������� 
	if(this->vtx_num>0 && this->Weight && !this->Directed){
			
		initKruskal(); //initialize	
		
		int u,v;
		//N������ N-1���� 
		for(int i=1; i<this->verts.size(); ){//ѡ�� this->verts.size()-1����С�� 
			MstNode node = q_arcs.top(); 
			q_arcs.pop();
			
			//node.show();
			
			u = m_set.find(node.i_from);
			v = m_set.find(node.i_to);
			
			if(u != v){ //����һ������
				m_set.merge(u,v);//�ϲ�
				//����node��������С��������
				mv_mst.push_back(node);
				
				i++;//ѡ��ɹ� 
			}
		}
	}else{
		cout << "Kruskal can not minispan tree!" << endl;
	}	
		
	}//---miniSpanTree() END
	
	
	//=== �����С������ 
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
		
		//��ʼʱ���������±����set�� 
		m_set.init(this->verts.size());
		
		MstNode node; 
		int i,j;
		//��������ı߷��������
		for(i=0; i<this->verts.size(); i++){
			for(j=0; j<this->verts.size(); j++){
				if( i!=j && this->matrix_g[i][j].m_cost < (CostType)LIMITED ){ //i,j������б� 
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

[V1,-1,-1,-1]--[V3,-1,-1,-1]-->(6,[1,null]) 0,2
[V4,-1,-1,-1]--[V6,-1,-1,-1]-->(6,[2,null]) 3,5
[V5,-1,-1,-1]--[V2,-1,-1,-1]-->(6,[3,null]) 4,1
[V3,-1,-1,-1]--[V6,-1,-1,-1]-->(6,[4,null]) 2,5
[V3,-1,-1,-1]--[V2,-1,-1,-1]-->(6,[5,null]) 2,1


--------------------------------
Process exited after 0.5592 seconds with return value 0
�밴���������. . .
*/
void testMSTKruskal(){
	string fileName = "udnData1.txt";// "udgData.txt";
	MSTKruskal<string,int> kruskal;

	kruskal.createFromFile(fileName);
	kruskal.show();
	
	kruskal.miniSpanTree();
	kruskal.showVectMST();
	
	
}
