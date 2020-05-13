
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

=== Read �ļ����ݴ���ͼ���ڽӱ�
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



	//�����(��)��Ϣ
	fin>>this->arc_num;//����			cout<<"arcnum:" << this->arc_num << endl;
	
	int origin, dest;//origin destination
	VertexNode<NameType> v_orig, v_dest;
	ArcNodeAdj<CostType> arc_adj;
	
	for(k=0; k<this->arc_num; k++) {
		fin >> v_orig;
		fin >> v_dest;
		//cout << "v_orig->" << v_orig << ",v_dest->" << v_dest << endl; 
		
		origin = getIdVex(v_orig); //��1���� 
		dest = getIdVex(v_dest); //��2���� 
		//cout << "origin->" << origin << ",dest->" << dest << endl; 
		arc_adj.m_dest=dest;//�ڽӵ� 

		if(this->Weight) { //��Ȩֵ
			fin>>arc_adj.m_arc.m_cost;
		}

		//inputArcFromFile(fin, arc_adj.m_arc);
		mv_adjVertex[origin].m_adjList.push_front(arc_adj); //�������ڽӱ��� 

		if(!this->Directed) {//����ͼ 
			arc_adj.m_dest = origin; //��1�����ǵ�2������ڽӵ� 
			mv_adjVertex[dest].m_adjList.push_front(arc_adj);
		}
	}//����߽���
	
	fin.close();
}//---createFromFile���ļ������ڽӱ� ENDING

	
/*===DFS��ȱ��� 
@param start:��ʼ���±�
@param fn:����ָ��,���뺯��
@param Visited:bool,��ʶ�ö����Ƿ񱻷��ʹ� 
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
			
}//---DFS��ȱ��� END


/*===DFSTraverse������ȱ���
@param start:��ʼ���±�
@param fn:����ָ��,���뺯��
@param Visited:bool,��ʶ�ö����Ƿ񱻷��ʹ� 
*/
template <typename NameType, typename CostType>
void AdjListGraph<NameType,CostType>::
DFSTraverse(void(*fn)(VertexNode<NameType>))
{
	int start;
	//��ʼʱ���ж����δ������ 
	vector<bool> Visited(mv_adjVertex.size(), false);
	//traverse ���ж��� 
	for(start=0; start<mv_adjVertex.size(); start++){
		if(!Visited[start]){
			DFS(start, fn, Visited);
		}
			
	}
		
	cout<<endl;
}//---DFSTraverse������ȱ���

/*===BFSTraverse������ȱ���
@param fn:����ָ��,���뺯�� 
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
			fn(getVex(start)); //�ô��뺯������ 
			
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
}//---BFSTraverse������ȱ���		

