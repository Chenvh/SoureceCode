#ifndef _MATRIX_GRAPH_H_2020
#define _MATRIX_GRAPH_H_2020
/*
	Name: MatrixGraph.h 
	Copyright: YOUNGMIEN
	Author: YOUNGMIEN
	Date: 13/05/19 15:40
	Description: 图的邻接矩阵类（MatrixGraph类）
*/

#include "AGraph.h"

template <typename NameType, typename CostType>
class MatrixGraph : public AGraph<NameType,CostType>{
//重命名,便于使用 
typedef vector<VertexNode<NameType> > VV;
typedef vector< ArcNode<CostType> > VA;
typedef vector< VA > VVA;

protected:		
	//矩阵:边集,用二维向量保存,
	//二维向量的第0个向量matrix_g[0]保存包含第0号顶点相关的边 
	VVA matrix_g;  

	public:

	//===createFromFile由文件创建邻接表
	void createFromFile(string FileName) ;
	
	//===getFirstAdjVex获取第一个邻接点
	int getFirstAdjVex(int i)const; 
	
	//===getNextAdjVex获取(v,w)下一个相邻顶点
	int getNextAdjVex(int i, int j)const;
	
	
	//===DFS深度遍历 
	void DFS(int i, void(*visit)(VertexNode<NameType>), vector<bool> &Visited);


	//===DFSTraverse深度优先遍历 
	void DFSTraverse(void(*visit)(VertexNode<NameType>));

	//===BFSTraverse广度优先遍历
	void BFSTraverse(void(*visit)(VertexNode<NameType>));

	//===insertVex在图G中末端插入顶点v
	void insertVex(VertexNode<NameType> vetx);
	
	
	//=== deleteVex删除图G中的顶点v
	bool deleteVex(VertexNode<NameType> v) ;

	//===insertArc向图G中插入边(弧)
	bool insertArc(VertexNode<NameType> v, VertexNode<NameType> w) ;


	//===deleteArc删除图G中边(v,w) 或弧<v,w>
	bool deleteArc(VertexNode<NameType> v, VertexNode<NameType> w); 
			
	//===show 输出邻接矩阵 
	void show(){
	
		this->showVertexSet();		
			
		int id= 2*this->Directed+this->Weight;
		int i, j;
		
		cout << "邻接矩阵是:\n";
		cout << "(orign,dest):weight"<<endl;
		for(i=0; i<this->verts.size(); i++){
			for(j=0; j<this->verts.size(); j++){
				cout<<"(" << i <<","<<j<<"):";
				
				//(i,j)的权值 
				if(matrix_g[i][j].m_cost == (CostType)LIMITED){
					cout<<setw(4) << setiosflags(ios::left) <<"∞";
				}					
				else{						
					cout<<setw(4) << setiosflags(ios::left) <<matrix_g[i][j].m_cost;
				}
			}
			cout<<endl;
		}
	
		cout << "\n读取各边数据依次是: \n";
		cout << "起-终: (权值,备注)\n";
		for(i=0; i<this->verts.size(); i++){
		
			if(this->Directed)//有向图 
			{
				for(j=0; j<this->verts.size(); j++){
						if(i!=j && matrix_g[i][j].m_cost != this->threshold ){ //有边 
							this->outputArc( this->Directed, this->verts[i],
							              	   this->verts[j], matrix_g[i][j]
											  );							
						}						
				}						
			}
			else{//无向图 ,输出上三角 
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
	}//---show 输出邻接矩阵 

	

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

该图是包含3个顶点及3条弧组成的无向图!!!
各顶点名依次是:
[a1,-1,-1,-1], [a2,-1,-1,-1], [a3,-1,-1,-1]

邻接矩阵是:
(orign,dest):weight
(0,0):0   (0,1):0   (0,2):0
(1,0):0   (1,1):0   (1,2):0
(2,0):0   (2,1):0   (2,2):0

读取各边数据依次是:
起-终: (权值,备注)

MatrixGraph类深度优先搜索遍历图的结果：
[a1,-1,-1,-1][a2,-1,-1,-1][a3,-1,-1,-1]
MatrixGraph类广度优先搜索遍历图的结果：
[a1,-1,-1,-1][a2,-1,-1,-1][a3,-1,-1,-1]

--------------------------------
Process exited after 0.8414 seconds with return value 0
请按任意键继续. . . 


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




