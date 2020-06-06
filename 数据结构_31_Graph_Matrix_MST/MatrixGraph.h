#ifndef _MATRIX_GRAPH_H_2020
#define _MATRIX_GRAPH_H_2020
/*
	Name: MatrixGraph.h 
	Copyright: YOUNGMIEN
	Author: YOUNGMIEN
	Date: 13/05/19 15:40
	Description: ͼ���ڽӾ����ࣨMatrixGraph�ࣩ
*/

#include "AGraph.h"

template <typename NameType, typename CostType>
class MatrixGraph : public AGraph<NameType,CostType>{
//������,����ʹ�� 
typedef vector<VertexNode<NameType> > VV;
typedef vector< ArcNode<CostType> > VA;
typedef vector< VA > VVA;

protected:		
	//����:�߼�,�ö�ά��������,
	//��ά�����ĵ�0������matrix_g[0]���������0�Ŷ�����صı� 
	VVA matrix_g;  

	public:

	//===createFromFile���ļ������ڽӱ�
	void createFromFile(string FileName) ;
	
	//===getFirstAdjVex��ȡ��һ���ڽӵ�
	int getFirstAdjVex(int i)const; 
	
	//===getNextAdjVex��ȡ(v,w)��һ�����ڶ���
	int getNextAdjVex(int i, int j)const;
	
	
	//===DFS��ȱ��� 
	void DFS(int i, void(*visit)(VertexNode<NameType>), vector<bool> &Visited);


	//===DFSTraverse������ȱ��� 
	void DFSTraverse(void(*visit)(VertexNode<NameType>));

	//===BFSTraverse������ȱ���
	void BFSTraverse(void(*visit)(VertexNode<NameType>));

	//===insertVex��ͼG��ĩ�˲��붥��v
	void insertVex(VertexNode<NameType> vetx);
	
	
	//=== deleteVexɾ��ͼG�еĶ���v
	bool deleteVex(VertexNode<NameType> v) ;

	//===insertArc��ͼG�в����(��)
	bool insertArc(VertexNode<NameType> v, VertexNode<NameType> w) ;


	//===deleteArcɾ��ͼG�б�(v,w) ��<v,w>
	bool deleteArc(VertexNode<NameType> v, VertexNode<NameType> w); 
			
	//===show ����ڽӾ��� 
	void show(){
	
		this->showVertexSet();		
			
		int id= 2*this->Directed+this->Weight;
		int i, j;
		
		cout << "�ڽӾ�����:\n";
		cout << "(orign,dest):weight"<<endl;
		for(i=0; i<this->verts.size(); i++){
			for(j=0; j<this->verts.size(); j++){
				cout<<"(" << i <<","<<j<<"):";
				
				//(i,j)��Ȩֵ 
				if(matrix_g[i][j].m_cost == (CostType)LIMITED){
					cout<<setw(4) << setiosflags(ios::left) <<"��";
				}					
				else{						
					cout<<setw(4) << setiosflags(ios::left) <<matrix_g[i][j].m_cost;
				}
			}
			cout<<endl;
		}
	
		cout << "\n��ȡ��������������: \n";
		cout << "��-��: (Ȩֵ,��ע)\n";
		for(i=0; i<this->verts.size(); i++){
		
			if(this->Directed)//����ͼ 
			{
				for(j=0; j<this->verts.size(); j++){
						if(i!=j && matrix_g[i][j].m_cost != this->threshold ){ //�б� 
							this->outputArc( this->Directed, this->verts[i],
							              	   this->verts[j], matrix_g[i][j]
											  );							
						}						
				}						
			}
			else{//����ͼ ,��������� 
				for(j=i+1; j<this->verts.size(); j++){
					if(matrix_g[i][j].m_cost != this->threshold ){
						this->outputArc( this->Directed, this->verts[i], 
											   this->verts[j], matrix_g[i][j]
											);					
					}				
				}			
			}						
		}
	
		cout<<endl;
	}//---show ����ڽӾ��� 

	

};




/*
udgData.txt
false
false
3
a1 a2 a3
3
a2 a1
a2 a3
a1 a3

��ͼ�ǰ���3�����㼰3������ɵ�����ͼ!!!
��������������:
[a1,-1,-1,-1], [a2,-1,-1,-1], [a3,-1,-1,-1]

�ڽӾ�����:
(orign,dest):weight
(0,0):0   (0,1):0   (0,2):0
(1,0):0   (1,1):0   (1,2):0
(2,0):0   (2,1):0   (2,2):0

��ȡ��������������:
��-��: (Ȩֵ,��ע)

MatrixGraph�����������������ͼ�Ľ����
[a1,-1,-1,-1][a2,-1,-1,-1][a3,-1,-1,-1]
MatrixGraph����������������ͼ�Ľ����
[a1,-1,-1,-1][a2,-1,-1,-1][a3,-1,-1,-1]

--------------------------------
Process exited after 0.8414 seconds with return value 0
�밴���������. . . 


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
 
*/

#endif




