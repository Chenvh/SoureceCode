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
 *	fileName:AdjListGraph.h ͼ���ڽӱ���
 *	Descripton:AdjListGraph.h ͼ���ڽӱ��ࣨAdjListGraph�ࣩ
	Adjacency list
 *
 *******************************/

#include "AGraph.h"
#include "VertexNodeAdj.h"
#include "ArcNodeAdj.h"

//�ڽӱ���ģ�� 
template <typename NameType, typename CostType>
class AdjListGraph : public AGraph<NameType,CostType>{
	
typedef ArcNodeAdj<CostType> ARCADJTYPE;	
typedef  list< ArcNodeAdj<CostType> >  LISTARCADJTYPE;
	
	protected:
		vector<VertexNodeAdj<NameType, CostType> > mv_adjVertex;
	public:
		
		//=== Read �ļ����ݴ���ͼ���ڽӱ�
		void createFromFile(string fileName); 
		
		/*===DFS��ȱ��� 
		@param start:��ʼ���±�
		@param fn:����ָ��,���뺯��
		@param Visited:bool,��ʶ�ö����Ƿ񱻷��ʹ� 
		*/
		void	DFS(int start, void(*fn)(VertexNode<NameType>), vector<bool> &Visited);
		
				
		/*===DFSTraverse������ȱ���
		@param start:��ʼ���±�
		@param fn:����ָ��,���뺯��
		@param Visited:bool,��ʶ�ö����Ƿ񱻷��ʹ� 
		*/
		void 	DFSTraverse(void(*fn)(VertexNode<NameType>));
		
		/*===BFSTraverse������ȱ���
		@param fn:����ָ��,���뺯�� 
		*/
		void BFSTraverse(void(*fn)(VertexNode<NameType>)) ; 
		 
		
		//���ʶ�����ڽӱ� 
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
		
		//===show����ڽӱ���Ϣ
		void show() {
			int i;
		

			int id= 2*this->Directed+this->Weight;
			//g_kind = GraphKind[id];
				
			cout << "��ͼ�ǰ���" << mv_adjVertex.size() <<"�����㼰" ; 
			cout<< this->arc_num<<"������ɵ�" << graph_type[id] << "!!!\n";
			cout <<"��������������:\n";
			
			for(i=0; i<mv_adjVertex.size(); i++) {
				
				Visit(mv_adjVertex[i].m_head);
				if(i+1 == mv_adjVertex.size()){//is the last element
					cout << endl;
				}else{
					cout << "," ;
				}
			}
			
			cout<<endl;
			cout << "�����㼰�ڽӱ���:\n";
			cout << "vexId(m_cost)->"<<endl;
			for(i=0; i<mv_adjVertex.size(); i++) {
				
				Visit(mv_adjVertex[i].m_head);
				cout << "->";
				showList(mv_adjVertex[i].m_adjList); 
			}

			cout<<endl<<this->arc_num<<"������"<<endl;
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
		}//---show����ڽӱ���Ϣ END



		//===getFirstAdjVex��ȡ��һ���ڽӵ�
		int getFirstAdjVex(int i)const {
			typename list<ArcNodeAdj<CostType> >::const_iterator it=mv_adjVertex[i].m_adjList.begin();
			if(it!=mv_adjVertex[i].m_adjList.end()) {

				return it->m_dest;
			} else {
				return -1;
			}

		}//---getFirstAdjVex��ȡ��һ���ڽӵ�

		//===getNextAdjVex��ȡstart�����ڽӵ�dest֮����ڽӵ�
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
		}//---getNextAdjVex��ȡstart�����ڽӵ�dest֮����ڽӵ� END
	
		//===getVex������Ż�ȡ������Ϣ
		VertexNode<NameType> getVex(int start)const {
			if(start>=mv_adjVertex.size() || start<0) {
				exit(1);
			}

			return mv_adjVertex[start].m_head;
		}//---getVex������Ż�ȡ������Ϣ

		//===getIdVex���ݶ����ȡ�����
		int getIdVex(VertexNode<NameType> u)const {
			//visit(u);
			for(int start=0; start<mv_adjVertex.size(); start++){
				//visit(mv_adjVertex[start].m_head);
				
				if(this->equals(u, mv_adjVertex[start].m_head)) {
					return start;
				}	
			}		

			return -1;
		}//---getIdVex���ݶ����ȡ����� END
		
		
		
		//===insertVex���붥��
		void insertVex(VertexNode<NameType> vtx) {
			mv_adjVertex.resize(mv_adjVertex.size()+1);//����1��λ�ռ� 
			mv_adjVertex[mv_adjVertex.size()-1].m_head=vtx;
		}//---insertVex���붥�� ENDING

		//===deleteVexɾ������
		bool deleteVex(VertexNode<NameType> v) {
			int i, k;
			typename list<ArcNodeAdj<CostType> >::iterator it;
			k=this->getIdVex(v);//��ȡ�ö������� 
			if(k<0) {

				return false;
			}
			
			//�����ڽӱ� 
			for(i=0; i<mv_adjVertex.size(); i++) {
				//������ 
				for(it=mv_adjVertex[i].m_adjList.begin(); it!=mv_adjVertex[i].m_adjList.end(); it++) {
					if(it->m_dest == k) {//�ҵ��ڽӵ� 
						mv_adjVertex[i].m_adjList.erase(it);
						this->arc_num--;
						break;
					}
				}

			}
			if(this->Directed) {//����ͼ 
				//���»��� 
				this->arc_num -= mv_adjVertex[k].m_adjList.size();
			}
			mv_adjVertex.erase(mv_adjVertex.begin()+k);
			
			//�����ڽӱ� 
			for(i=0; i<mv_adjVertex.size(); i++) {
				for(it=mv_adjVertex[i].m_adjList.begin(); it!=mv_adjVertex[i].m_adjList.end(); it++) {

					if(it->m_dest>k) {

						it->m_dest--;
					}
				}
			}
			return true;
		}//---deleteVexɾ������ END

		//===insertArc�����(��)
		bool insertArc(VertexNode<NameType> v, VertexNode<NameType> w) {
			ArcNodeAdj<CostType> arc_adj;
			int origin, dest;//origin destination
			origin=this->getIdVex(v);
			dest=this->getIdVex(w);
			if(origin<0 || dest<0){
				return false;
			}
				
			this->arc_num++;//����+1 
			arc_adj.m_dest=dest;
			
			//��ȡ����Ϣ 
			inputArc(this->Directed, this->Weight, v, w, arc_adj.m_arc);
			mv_adjVertex[origin].m_adjList.push_front(arc_adj);//���� 
			
			if(!this->Directed) {//����ͼ 
				arc_adj.m_dest=origin;
				mv_adjVertex[dest].m_adjList.push_front(arc_adj);
			}
			return true;
		}//---insertArc�����(��) END

		//===deleteArcɾ����(��)
		bool deleteArc(VertexNode<NameType> v, VertexNode<NameType> w) {
			typename list<ArcNodeAdj<CostType> >::iterator it;
			int origin, dest;
			origin=this->getIdVex(v);
			dest=this->getIdVex(w);
			if(origin<0 || dest<0 || origin==dest) {

				return false;
			}
			//���������� 
			for(it=mv_adjVertex[origin].m_adjList.begin(); it!=mv_adjVertex[origin].m_adjList.end(); it++) {
				if(it->m_dest==dest) {
					mv_adjVertex[origin].m_adjList.erase(it);
					this->arc_num--;
					break;
				}
			}

			if(!this->Directed){//����ͼ 
				for(it=mv_adjVertex[dest].m_adjList.begin(); it!=mv_adjVertex[dest].m_adjList.end(); it++) {
					if(it->m_dest==origin) {
						mv_adjVertex[dest].m_adjList.erase(it);
						break;
					}
				}
			}
				

			return true;
		}//---deleteArcɾ����(��) END



};

#endif

