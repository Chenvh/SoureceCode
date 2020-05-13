
#include "AdjListGraph.h"


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

=== Read 文件数据创建图的邻接表
*/
template <typename NameType, typename CostType>
void AdjListGraph<NameType,CostType>::createFromFile(string fileName){
	ifstream fin(fileName.c_str());
			
	this->init(fin);			
	
	VertexNodeAdj<NameType, CostType> vtx_adj;
	int k;	
	for(k=0; k<this->vtx_num; k++) {				
		//inputVertexFromFile(fin, vtx_adj.m_head);				
		fin >>  vtx_adj.m_head;
		mv_adjVertex.push_back(vtx_adj);
	}



	//输入边(弧)信息
	fin>>this->arc_num;//个数			cout<<"arcnum:" << this->arc_num << endl;
	
	int origin, dest;//origin destination
	VertexNode<NameType> v_orig, v_dest;
	ArcNodeAdj<CostType> arc_adj;
	
	for(k=0; k<this->arc_num; k++) {
		fin >> v_orig;
		fin >> v_dest;
		//cout << "v_orig->" << v_orig << ",v_dest->" << v_dest << endl; 
		
		origin = getIdVex(v_orig); //第1个点 
		dest = getIdVex(v_dest); //第2个点 
		//cout << "origin->" << origin << ",dest->" << dest << endl; 
		arc_adj.m_dest=dest;//邻接点 

		if(this->Weight) { //有权值
			fin>>arc_adj.m_arc.m_cost;
		}

		//inputArcFromFile(fin, arc_adj.m_arc);
		mv_adjVertex[origin].m_adjList.push_front(arc_adj); //保存至邻接表中 

		if(!this->Directed) {//无向图 
			arc_adj.m_dest = origin; //第1个点是第2个点的邻接点 
			mv_adjVertex[dest].m_adjList.push_front(arc_adj);
		}
	}//输入边结束
	
	fin.close();
}//---createFromFile由文件创建邻接表 ENDING

	
/*===DFS深度遍历 
@param start:起始点下标
@param fn:函数指针,传入函数
@param Visited:bool,标识该顶点是否被访问过 
*/
template <typename NameType, typename CostType>
void AdjListGraph<NameType,CostType>::
DFS(int start, void(*fn)(VertexNode<NameType>), vector<bool> &Visited)
{
	Visited[start]=true;
	fn(getVex(start));
	for(int j=getFirstAdjVex(start); j>=0; j=getNextAdjVex(start, j))
	
		if(!Visited[j])
			DFS(j, fn, Visited);
			
}//---DFS深度遍历 END


/*===DFSTraverse深度优先遍历
@param start:起始点下标
@param fn:函数指针,传入函数
@param Visited:bool,标识该顶点是否被访问过 
*/
template <typename NameType, typename CostType>
void AdjListGraph<NameType,CostType>::
DFSTraverse(void(*fn)(VertexNode<NameType>))
{
	int start;
	//初始时所有顶点皆未被访问 
	vector<bool> Visited(mv_adjVertex.size(), false);
	//traverse 所有顶点 
	for(start=0; start<mv_adjVertex.size(); start++){
		if(!Visited[start]){
			DFS(start, fn, Visited);
		}
			
	}
		
	cout<<endl;
}//---DFSTraverse深度优先遍历

/*===BFSTraverse广度优先遍历
@param fn:函数指针,传入函数 
*/
template <typename NameType, typename CostType>
void AdjListGraph<NameType,CostType>::
BFSTraverse(void(*fn)(VertexNode<NameType>))
{
	int start, j, k;
	vector<bool> Visited(mv_adjVertex.size(), false);
	
	queue<int> q;
	for(start=0; start<mv_adjVertex.size(); start++)
		if(!Visited[start])
		{
			Visited[start]=true;
			fn(getVex(start)); //用传入函数处理 
			
			q.push(start);
			while(!q.empty())
			{
				j=q.front();
				q.pop();
				for(k=getFirstAdjVex(j); k>=0; k=getNextAdjVex(j, k))
					if(!Visited[k])
					{
						Visited[k]=true;
						fn(this->getVex(k));
						q.push(k);
					}
			}
		}
	cout<<endl;
}//---BFSTraverse广度优先遍历		

