#include "MatrixGraph.h"

//===createFromFile由文件创建邻接表
template <typename NameType, typename CostType>
void MatrixGraph<NameType, CostType> ::createFromFile(string FileName) {
		
		ifstream fin(FileName.c_str());
	
		this->init(fin);			
		
		//初始化边 集
		ArcNode<CostType> arc(this->threshold );			 
		
		VA varcs;
		varcs.assign(this->vtx_num, arc);//向量有vtx_num个空的边
		
		//初始化矩阵 
		for(int i=0; i<this->vtx_num; i++){
			matrix_g.push_back(varcs);//初始化边集保存至边矩阵中 
		}				
		
		
		int  k;
		VertexNode<NameType> vtx;	//顶点结点				
		//依次输入各顶点 
		for(k=0; k<this->vtx_num; k++) {
			fin >> vtx;   //	vtx.show(); cout << endl; 				
			this->verts.push_back(vtx);
											
		}	
		
		//设置主对角线 main diagonal  
		for(k=0; k<this->vtx_num; k++) {
			if(this->Weight){ //带权图或网
				matrix_g[k][k].m_cost = 0;
			}
			else{ //无权 
				matrix_g[k][k].m_cost = 0; 
			}
		}

		//输入边(弧)信息
		fin >> this->arc_num;//边数
		//	cout<<"arcnum:" << ArcNum << endl;
		
		VertexNode<NameType> v1, v2; //1条边的2个顶点 
		int id1,id2;//每条边上2个顶点下标 
					
		for(k=0; k<this->arc_num; k++) {
			
			//每次输入1条边的2个顶点  
			fin >> v1; //inputVertexNameFromFile(fin, v1);
			fin >> v2; //inputVertexNameFromFile(fin, v2);
			//cout << "v1->" << v1 << ",v2->" << v2<<"#";

			id1 = this->locateVex(v1); //第1个点下标 
			id2 = this->locateVex(v2); //第2个点下标 
			//cout << "i->" << i << ",j->" << j << endl;

			if(this->Weight) { //带权图 
				//更新顶点i到邻接点j 的权值.即(i,j)的权值 
				fin>>matrix_g[id1][id2].m_cost;
			//	cout << "arc.adj:" << arc.adj << "\n";
			}
						//	inputArcFromIS(fin, verts[i].matrix_g[j]);
			if(!this->Directed) {//无向图
				
				//更新顶点j到邻接点i 的权值为顶点i到邻接点j 的权值 \
				即(j,i)的权值 等于 (i,j)的权值 
				matrix_g[id2][id1].m_cost = matrix_g[id1][id2].m_cost;
			}

		}//输入边结束


		fin.close();
	}//---createFromFile由文件创建邻接表 ENDING
	
	

//===BFSTraverse广度优先遍历
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
}//---BFSTraverse广度优先遍历


//===getFirstAdjVex获取第一个邻接点
template <typename NameType, typename CostType>
int MatrixGraph<NameType, CostType>::getFirstAdjVex(int i)const {

	//设置空值	
	//this->threshold = (this->Weight?LIMITED:0);

	for(int k=0; k<this->verts.size(); k++) {

		if(k!=i && matrix_g[i][k].m_cost!=this->threshold ) {

			return k;
		}
	}
	return -1;
}//---getFirstAdjVex获取第一个邻接点 END

//===getNextAdjVex获取(v,w)下一个相邻顶点
template <typename NameType, typename CostType>
int MatrixGraph<NameType, CostType>::getNextAdjVex(int i, int j)const {
	
	
	//设置空值	
	//this->threshold = (this->Weight?LIMITED:0);		

	if(matrix_g[i][j].m_cost!=this->threshold ) {
		for(int k=j+1; k<this->verts.size(); k++) {
			if(i!=k && matrix_g[i][k].m_cost != this->threshold ) {
				return k;
			}
		}
	}

	return -1;
}//--- getNextAdjVex获取(v,w)下一个相邻顶点 END


//===DFS深度遍历 
template <typename NameType, typename CostType>
void MatrixGraph<NameType, CostType>:: DFS(int i, void(*visit)(VertexNode<NameType>), vector<bool> &Visited)
{
	Visited[i]=true;
	visit(this->getVex(i));
	for(int j=getFirstAdjVex(i); j>=0; j=getNextAdjVex(i, j))
	
		if(!Visited[j])
			DFS(j, visit, Visited);
			
}//---DFS深度遍历 END

//===DFSTraverse深度优先遍历 
template <typename NameType, typename CostType>
void MatrixGraph<NameType,CostType>::DFSTraverse(void(*visit)(VertexNode<NameType>)){
	int i;
	vector<bool> Visited(this->verts.size(), false);
	
	for(i=0; i<this->verts.size(); i++)
		if(!Visited[i])
			DFS(i, visit, Visited);
	cout<<endl;
}//---DFSTraverse深度优先遍历




	//===insertVex在图G中末端插入顶点v
template <typename NameType, typename CostType>
void MatrixGraph<NameType,CostType>::insertVex(VertexNode<NameType> vetx) {
		//放入顶点集中 
		this->verts.push_back(vetx); 
		this->vtx_num ++; //更新顶点数 
		
		//增加1个顶点,矩阵阶数 + 1

		//定义1个空边 ,网的权值为无穷大,图为0 
		ArcNode<CostType> arc(this->threshold );		
		//arc.m_cost=(this->Weight? LIMITED: 0);		
		VA varcs;		
		//构造包含有vtx_num个边的空向量	
		varcs.assign(this->vtx_num, arc);
	
		//增加空向量至矩阵最后1行 
		matrix_g.push_back(varcs);
		
		//从[0,vtx_num-2]的前vtx_num-1行更新每行的列数 每行加多一空列
		for(int i=0; i<this->vtx_num-1; i++){			 
			matrix_g[i].push_back(arc);//增加1个空的边 
		}			
		
	}//---===insertVex在图G中末端插入顶点v END

	//=== deleteVex删除图G中的顶点v
template <typename NameType, typename CostType>
bool MatrixGraph<NameType,CostType>::deleteVex(VertexNode<NameType> v) {
		int i, k;
		//获取序号
		k=this->locateVex(v);

		if(k<0) {
			return false;
		}
		
		//在矩阵中删除第k行和第k列 
		//更新边数目
		
		//检查第k行是否存在有边 
		for(i=0; i<this->verts.size(); i++) {
			if(matrix_g[k][i].m_cost>0 && matrix_g[k][i].m_cost != LIMITED) {
				this->arc_num--;
			}

			if(this->Directed) { //有向,检查k列 
				if(matrix_g[i][k].m_cost>0 && matrix_g[i][k].m_cost!=LIMITED) {
					this->arc_num--;
				}
			}
		}
		
		//在顶点集中清除第k号顶点 
		this->verts.erase(this->verts.begin()+k);
		
		//删除每行中第k列元素	
		for(i=0; i<this->verts.size(); i++) {
			matrix_g[i].erase(matrix_g[i].begin()+k);
		}
		//删除第k行 
		matrix_g.erase(matrix_g.begin()+k);
	
		return true;
	}//--- deleteVex删除图G中的顶点v END

	//===insertArc向图G中插入边(弧)
template <typename NameType, typename CostType>
bool MatrixGraph<NameType,CostType>:: insertArc(VertexNode<NameType> v, VertexNode<NameType> w) {
		int i, j;
		i = this->locateVex(v);
		j = this->locateVex(w);
		if(i<0 || j<0) {
			return false;
		}
		this->arc_num++;
		if(this->Weight) {//是网 
			cout<<"请输入此弧的权值：";
			cin>>matrix_g[i][j].m_cost;
		} else{
			matrix_g[i][j].m_cost=1;
		}
			
		inputArc(matrix_g[i][j]);
		if(!this->Directed){//无向图或网 
			matrix_g[j][i]=matrix_g[i][j];
		}
			
		return true;
	}

	//===deleteArc删除图G中边(v,w) 或弧<v,w>
template <typename NameType, typename CostType>
bool MatrixGraph<NameType,CostType>::deleteArc(VertexNode<NameType> v, VertexNode<NameType> w) {
		int i, k;
		CostType zero=0;
		if(this->Weight) {
			zero=LIMITED;
		}
		
		//设置空值	
		this->threshold = (this->Weight?LIMITED:0);

		i = this->locateVex(v);
		k = this->locateVex(w);

		if(i<0 || k<0 || i==k) {
			return false;
		}

		if(matrix_g[i][k].m_cost != zero) {//2点间有边 
			//清空权值 
			matrix_g[i][k].m_cost=zero;
			
			if(!this->Directed) {//无向图或网 
				matrix_g[k][i].m_cost=zero;
			}

			this->arc_num--;
		}
		return true;
}//--- deleteArc END

	

