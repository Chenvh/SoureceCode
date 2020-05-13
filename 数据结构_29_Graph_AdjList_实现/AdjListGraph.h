#ifndef AdjListGraph_HH_2020
#define AdjListGraph_HH_2020

/***********************************
 *	Copyright(c) 2016-2099 CTGU YOUNGMIEN
 *  All rights reserved.

 *	Version: v1.0
 *	Author: YOUNGMIEN
 *	Date: 201606
 *	Company: CTGU
 *
 *	fileName:AdjListGraph.h 图的邻接表类
 *	Descripton:AdjListGraph.h 图的邻接表类（AdjListGraph类）
	Adjacency list
 *
 *******************************/

#include "AGraph.h"
#include "VertexNodeAdj.h"
#include "ArcNodeAdj.h"

//邻接表类模板 
template <typename NameType, typename CostType>
class AdjListGraph : public AGraph<NameType,CostType>{
	
typedef ArcNodeAdj<CostType> ARCADJTYPE;	
typedef  list< ArcNodeAdj<CostType> >  LISTARCADJTYPE;
	
	protected:
		vector<VertexNodeAdj<NameType, CostType> > mv_adjVertex;
	public:
		
		//=== Read 文件数据创建图的邻接表
		void createFromFile(string fileName); 
		
		/*===DFS深度遍历 
		@param start:起始点下标
		@param fn:函数指针,传入函数
		@param Visited:bool,标识该顶点是否被访问过 
		*/
		void	DFS(int start, void(*fn)(VertexNode<NameType>), vector<bool> &Visited);
		
				
		/*===DFSTraverse深度优先遍历
		@param start:起始点下标
		@param fn:函数指针,传入函数
		@param Visited:bool,标识该顶点是否被访问过 
		*/
		void 	DFSTraverse(void(*fn)(VertexNode<NameType>));
		
		/*===BFSTraverse广度优先遍历
		@param fn:函数指针,传入函数 
		*/
		void BFSTraverse(void(*fn)(VertexNode<NameType>)) ; 
		 
		
		//访问顶点的邻接表 
		void showList( list<ArcNodeAdj<CostType> > vexList) {
			//cout<<"***for_each****"<<std::endl;
			typename list< ArcNodeAdj<CostType> > :: iterator iter;
			//list<ARCADJTYPE>::iterator iter;
			for(iter = vexList.begin(); iter != vexList.end() ;iter++){
				//iter ->show();
				cout << iter->m_dest ;
				if(this->Weight){
					cout <<"(w:" << iter->m_arc.m_cost;
				}
				cout <<")";
				if( iter!= vexList.end() ){
					cout << "->";
				}
			}
			cout << "null" << endl;
		} 
		
		//===show输出邻接表信息
		void show() {
			int i;
		

			int id= 2*this->Directed+this->Weight;
			//g_kind = GraphKind[id];
				
			cout << "该图是包含" << mv_adjVertex.size() <<"个顶点及" ; 
			cout<< this->arc_num<<"条弧组成的" << graph_type[id] << "!!!\n";
			cout <<"各顶点名依次是:\n";
			
			for(i=0; i<mv_adjVertex.size(); i++) {
				
				Visit(mv_adjVertex[i].m_head);
				if(i+1 == mv_adjVertex.size()){//is the last element
					cout << endl;
				}else{
					cout << "," ;
				}
			}
			
			cout<<endl;
			cout << "各顶点及邻接表是:\n";
			cout << "vexId(m_cost)->"<<endl;
			for(i=0; i<mv_adjVertex.size(); i++) {
				
				Visit(mv_adjVertex[i].m_head);
				cout << "->";
				showList(mv_adjVertex[i].m_adjList); 
			}

			cout<<endl<<this->arc_num<<"条弧："<<endl;
			typename list<ArcNodeAdj<CostType> >::const_iterator it;
			for(i=0; i<mv_adjVertex.size(); i++) {
				for(it=mv_adjVertex[i].m_adjList.begin(); it!=mv_adjVertex[i].m_adjList.end(); it++) {
					if(this->Directed||i<it->m_dest) {
						 this->outputArc(
							this->Directed, 
							mv_adjVertex[i].m_head, mv_adjVertex[it->m_dest].m_head, 
							it->m_arc
							);
					}

				}
				cout<<endl;
			}
		}//---show输出邻接表信息 END



		//===getFirstAdjVex获取第一个邻接点
		int getFirstAdjVex(int i)const {
			typename list<ArcNodeAdj<CostType> >::const_iterator it=mv_adjVertex[i].m_adjList.begin();
			if(it!=mv_adjVertex[i].m_adjList.end()) {

				return it->m_dest;
			} else {
				return -1;
			}

		}//---getFirstAdjVex获取第一个邻接点

		//===getNextAdjVex获取start结点的邻接点dest之后的邻接点
		int getNextAdjVex(int start, int dest)const {
			typename list<ArcNodeAdj<CostType> >::const_iterator it;
			for(it=mv_adjVertex[start].m_adjList.begin(); it!=mv_adjVertex[start].m_adjList.end(); it++)
				if(it->m_dest==dest) {
					it++;
					break;
				}
			if(it==mv_adjVertex[start].m_adjList.end()) {

				return -1;
			} else {

				return it->m_dest;
			}
		}//---getNextAdjVex获取start结点的邻接点dest之后的邻接点 END
	
		//===getVex根据序号获取顶点信息
		VertexNode<NameType> getVex(int start)const {
			if(start>=mv_adjVertex.size() || start<0) {
				exit(1);
			}

			return mv_adjVertex[start].m_head;
		}//---getVex根据序号获取顶点信息

		//===getIdVex根据顶点获取其序号
		int getIdVex(VertexNode<NameType> u)const {
			//visit(u);
			for(int start=0; start<mv_adjVertex.size(); start++){
				//visit(mv_adjVertex[start].m_head);
				
				if(this->equals(u, mv_adjVertex[start].m_head)) {
					return start;
				}	
			}		

			return -1;
		}//---getIdVex根据顶点获取其序号 END
		
		
		
		//===insertVex插入顶点
		void insertVex(VertexNode<NameType> vtx) {
			mv_adjVertex.resize(mv_adjVertex.size()+1);//增加1单位空间 
			mv_adjVertex[mv_adjVertex.size()-1].m_head=vtx;
		}//---insertVex插入顶点 ENDING

		//===deleteVex删除顶点
		bool deleteVex(VertexNode<NameType> v) {
			int i, k;
			typename list<ArcNodeAdj<CostType> >::iterator it;
			k=this->getIdVex(v);//获取该顶点的序号 
			if(k<0) {

				return false;
			}
			
			//遍历邻接表 
			for(i=0; i<mv_adjVertex.size(); i++) {
				//遍历边 
				for(it=mv_adjVertex[i].m_adjList.begin(); it!=mv_adjVertex[i].m_adjList.end(); it++) {
					if(it->m_dest == k) {//找到邻接点 
						mv_adjVertex[i].m_adjList.erase(it);
						this->arc_num--;
						break;
					}
				}

			}
			if(this->Directed) {//有向图 
				//更新弧数 
				this->arc_num -= mv_adjVertex[k].m_adjList.size();
			}
			mv_adjVertex.erase(mv_adjVertex.begin()+k);
			
			//更新邻接表 
			for(i=0; i<mv_adjVertex.size(); i++) {
				for(it=mv_adjVertex[i].m_adjList.begin(); it!=mv_adjVertex[i].m_adjList.end(); it++) {

					if(it->m_dest>k) {

						it->m_dest--;
					}
				}
			}
			return true;
		}//---deleteVex删除顶点 END

		//===insertArc插入边(弧)
		bool insertArc(VertexNode<NameType> v, VertexNode<NameType> w) {
			ArcNodeAdj<CostType> arc_adj;
			int origin, dest;//origin destination
			origin=this->getIdVex(v);
			dest=this->getIdVex(w);
			if(origin<0 || dest<0){
				return false;
			}
				
			this->arc_num++;//边数+1 
			arc_adj.m_dest=dest;
			
			//获取边信息 
			inputArc(this->Directed, this->Weight, v, w, arc_adj.m_arc);
			mv_adjVertex[origin].m_adjList.push_front(arc_adj);//保存 
			
			if(!this->Directed) {//无向图 
				arc_adj.m_dest=origin;
				mv_adjVertex[dest].m_adjList.push_front(arc_adj);
			}
			return true;
		}//---insertArc插入边(弧) END

		//===deleteArc删除边(弧)
		bool deleteArc(VertexNode<NameType> v, VertexNode<NameType> w) {
			typename list<ArcNodeAdj<CostType> >::iterator it;
			int origin, dest;
			origin=this->getIdVex(v);
			dest=this->getIdVex(w);
			if(origin<0 || dest<0 || origin==dest) {

				return false;
			}
			//遍历边链表 
			for(it=mv_adjVertex[origin].m_adjList.begin(); it!=mv_adjVertex[origin].m_adjList.end(); it++) {
				if(it->m_dest==dest) {
					mv_adjVertex[origin].m_adjList.erase(it);
					this->arc_num--;
					break;
				}
			}

			if(!this->Directed){//无向图 
				for(it=mv_adjVertex[dest].m_adjList.begin(); it!=mv_adjVertex[dest].m_adjList.end(); it++) {
					if(it->m_dest==origin) {
						mv_adjVertex[dest].m_adjList.erase(it);
						break;
					}
				}
			}
				

			return true;
		}//---deleteArc删除边(弧) END



};

#endif

