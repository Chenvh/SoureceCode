#include "MatrixGraph.h"

//===createFromFile���ļ������ڽӱ�
template <typename NameType, typename CostType>
void MatrixGraph<NameType, CostType> ::createFromFile(string FileName) {
		
		ifstream fin(FileName.c_str());
	
		this->init(fin);			
		
		//��ʼ���� ��
		ArcNode<CostType> arc(this->threshold );			 
		
		VA varcs;
		varcs.assign(this->vtx_num, arc);//������vtx_num���յı�
		
		//��ʼ������ 
		for(int i=0; i<this->vtx_num; i++){
			matrix_g.push_back(varcs);//��ʼ���߼��������߾����� 
		}				
		
		
		int  k;
		VertexNode<NameType> vtx;	//������				
		//������������� 
		for(k=0; k<this->vtx_num; k++) {
			fin >> vtx;   //	vtx.show(); cout << endl; 				
			this->verts.push_back(vtx);
											
		}	
		
		//�������Խ��� main diagonal  
		for(k=0; k<this->vtx_num; k++) {
			if(this->Weight){ //��Ȩͼ����
				matrix_g[k][k].m_cost = 0;
			}
			else{ //��Ȩ 
				matrix_g[k][k].m_cost = 0; 
			}
		}

		//�����(��)��Ϣ
		fin >> this->arc_num;//����
		//	cout<<"arcnum:" << ArcNum << endl;
		
		VertexNode<NameType> v1, v2; //1���ߵ�2������ 
		int id1,id2;//ÿ������2�������±� 
					
		for(k=0; k<this->arc_num; k++) {
			
			//ÿ������1���ߵ�2������  
			fin >> v1; //inputVertexNameFromFile(fin, v1);
			fin >> v2; //inputVertexNameFromFile(fin, v2);
			//cout << "v1->" << v1 << ",v2->" << v2<<"#";

			id1 = this->locateVex(v1); //��1�����±� 
			id2 = this->locateVex(v2); //��2�����±� 
			//cout << "i->" << i << ",j->" << j << endl;

			if(this->Weight) { //��Ȩͼ 
				//���¶���i���ڽӵ�j ��Ȩֵ.��(i,j)��Ȩֵ 
				fin>>matrix_g[id1][id2].m_cost;
			//	cout << "arc.adj:" << arc.adj << "\n";
			}
						//	inputArcFromIS(fin, verts[i].matrix_g[j]);
			if(!this->Directed) {//����ͼ
				
				//���¶���j���ڽӵ�i ��ȨֵΪ����i���ڽӵ�j ��Ȩֵ \
				��(j,i)��Ȩֵ ���� (i,j)��Ȩֵ 
				matrix_g[id2][id1].m_cost = matrix_g[id1][id2].m_cost;
			}

		}//����߽���


		fin.close();
	}//---createFromFile���ļ������ڽӱ� ENDING
	
	

//===BFSTraverse������ȱ���
template <typename NameType, typename CostType>
void MatrixGraph<NameType, CostType>::BFSTraverse(void(*visit)(VertexNode<NameType>)){

	int i, j, k;
	vector<bool> Visited(this->verts.size(), false);
	
	queue<int> q;
	for(i=0; i<this->verts.size(); i++)
		if(!Visited[i])
		{
			Visited[i]=true;
			visit(this->getVex(i));
			q.push(i);
			while(!q.empty())
			{
				j=q.front();
				q.pop();
				for(k=getFirstAdjVex(j); k>=0; k=getNextAdjVex(j, k))
					if(!Visited[k])
					{
						Visited[k]=true;
						visit(this->getVex(k));
						q.push(k);
					}
			}
		}
	cout<<endl;
}//---BFSTraverse������ȱ���


//===getFirstAdjVex��ȡ��һ���ڽӵ�
template <typename NameType, typename CostType>
int MatrixGraph<NameType, CostType>::getFirstAdjVex(int i)const {

	//���ÿ�ֵ	
	//this->threshold = (this->Weight?LIMITED:0);

	for(int k=0; k<this->verts.size(); k++) {

		if(k!=i && matrix_g[i][k].m_cost!=this->threshold ) {

			return k;
		}
	}
	return -1;
}//---getFirstAdjVex��ȡ��һ���ڽӵ� END

//===getNextAdjVex��ȡ(v,w)��һ�����ڶ���
template <typename NameType, typename CostType>
int MatrixGraph<NameType, CostType>::getNextAdjVex(int i, int j)const {
	
	
	//���ÿ�ֵ	
	//this->threshold = (this->Weight?LIMITED:0);		

	if(matrix_g[i][j].m_cost!=this->threshold ) {
		for(int k=j+1; k<this->verts.size(); k++) {
			if(i!=k && matrix_g[i][k].m_cost != this->threshold ) {
				return k;
			}
		}
	}

	return -1;
}//--- getNextAdjVex��ȡ(v,w)��һ�����ڶ��� END


//===DFS��ȱ��� 
template <typename NameType, typename CostType>
void MatrixGraph<NameType, CostType>:: DFS(int i, void(*visit)(VertexNode<NameType>), vector<bool> &Visited)
{
	Visited[i]=true;
	visit(this->getVex(i));
	for(int j=getFirstAdjVex(i); j>=0; j=getNextAdjVex(i, j))
	
		if(!Visited[j])
			DFS(j, visit, Visited);
			
}//---DFS��ȱ��� END

//===DFSTraverse������ȱ��� 
template <typename NameType, typename CostType>
void MatrixGraph<NameType,CostType>::DFSTraverse(void(*visit)(VertexNode<NameType>)){
	int i;
	vector<bool> Visited(this->verts.size(), false);
	
	for(i=0; i<this->verts.size(); i++)
		if(!Visited[i])
			DFS(i, visit, Visited);
	cout<<endl;
}//---DFSTraverse������ȱ���




	//===insertVex��ͼG��ĩ�˲��붥��v
template <typename NameType, typename CostType>
void MatrixGraph<NameType,CostType>::insertVex(VertexNode<NameType> vetx) {
		//���붥�㼯�� 
		this->verts.push_back(vetx); 
		this->vtx_num ++; //���¶����� 
		
		//����1������,������� + 1

		//����1���ձ� ,����ȨֵΪ�����,ͼΪ0 
		ArcNode<CostType> arc(this->threshold );		
		//arc.m_cost=(this->Weight? LIMITED: 0);		
		VA varcs;		
		//���������vtx_num���ߵĿ�����	
		varcs.assign(this->vtx_num, arc);
	
		//���ӿ��������������1�� 
		matrix_g.push_back(varcs);
		
		//��[0,vtx_num-2]��ǰvtx_num-1�и���ÿ�е����� ÿ�мӶ�һ����
		for(int i=0; i<this->vtx_num-1; i++){			 
			matrix_g[i].push_back(arc);//����1���յı� 
		}			
		
	}//---===insertVex��ͼG��ĩ�˲��붥��v END

	//=== deleteVexɾ��ͼG�еĶ���v
template <typename NameType, typename CostType>
bool MatrixGraph<NameType,CostType>::deleteVex(VertexNode<NameType> v) {
		int i, k;
		//��ȡ���
		k=this->locateVex(v);

		if(k<0) {
			return false;
		}
		
		//�ھ�����ɾ����k�к͵�k�� 
		//���±���Ŀ
		
		//����k���Ƿ�����б� 
		for(i=0; i<this->verts.size(); i++) {
			if(matrix_g[k][i].m_cost>0 && matrix_g[k][i].m_cost != LIMITED) {
				this->arc_num--;
			}

			if(this->Directed) { //����,���k�� 
				if(matrix_g[i][k].m_cost>0 && matrix_g[i][k].m_cost!=LIMITED) {
					this->arc_num--;
				}
			}
		}
		
		//�ڶ��㼯�������k�Ŷ��� 
		this->verts.erase(this->verts.begin()+k);
		
		//ɾ��ÿ���е�k��Ԫ��	
		for(i=0; i<this->verts.size(); i++) {
			matrix_g[i].erase(matrix_g[i].begin()+k);
		}
		//ɾ����k�� 
		matrix_g.erase(matrix_g.begin()+k);
	
		return true;
	}//--- deleteVexɾ��ͼG�еĶ���v END

	//===insertArc��ͼG�в����(��)
template <typename NameType, typename CostType>
bool MatrixGraph<NameType,CostType>:: insertArc(VertexNode<NameType> v, VertexNode<NameType> w) {
		int i, j;
		i = this->locateVex(v);
		j = this->locateVex(w);
		if(i<0 || j<0) {
			return false;
		}
		this->arc_num++;
		if(this->Weight) {//���� 
			cout<<"������˻���Ȩֵ��";
			cin>>matrix_g[i][j].m_cost;
		} else{
			matrix_g[i][j].m_cost=1;
		}
			
		inputArc(matrix_g[i][j]);
		if(!this->Directed){//����ͼ���� 
			matrix_g[j][i]=matrix_g[i][j];
		}
			
		return true;
	}

	//===deleteArcɾ��ͼG�б�(v,w) ��<v,w>
template <typename NameType, typename CostType>
bool MatrixGraph<NameType,CostType>::deleteArc(VertexNode<NameType> v, VertexNode<NameType> w) {
		int i, k;
		CostType zero=0;
		if(this->Weight) {
			zero=LIMITED;
		}
		
		//���ÿ�ֵ	
		this->threshold = (this->Weight?LIMITED:0);

		i = this->locateVex(v);
		k = this->locateVex(w);

		if(i<0 || k<0 || i==k) {
			return false;
		}

		if(matrix_g[i][k].m_cost != zero) {//2����б� 
			//���Ȩֵ 
			matrix_g[i][k].m_cost=zero;
			
			if(!this->Directed) {//����ͼ���� 
				matrix_g[k][i].m_cost=zero;
			}

			this->arc_num--;
		}
		return true;
}//--- deleteArc END

	

