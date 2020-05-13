/*Abstract Base Class
ͼ�ĳ������
 
*/
//ͼ����:����ͼ,������,����ͼ,������ 
#include "comm.h"
#include "VertexNode.h"
#include "ArcNode.h"

#define LIMITED 9999

typedef enum{UDG, UDN, DG, DN} GraphKind;
 
template <typename NameType, typename CostType>
class AGraph{
//����ʹ��,������
typedef vector< VertexNode<NameType> >   VV;
typedef vector< ArcNode<CostType> >   VA;
protected: //������Է��� 
	VV verts; //���㼯��	
	int vtx_num; //������� 
	int arc_num;//�߸���
	
	GraphKind g_kind; //ͼ���� 
	
	CostType threshold;//��ֵ,������֮��û�б�ʱ��ֵ 
	
	bool Directed; //��ʶ����(true),����(false)
	bool Weighted;//��ʶͼ(false),��(true)
	
public:
	//���캯��
	AGraph():vtx_num(0), arc_num(0){
		
	}	
	
	
	/*�����ļ����ݴ���ͼ,��������: 
	false
	false
	3
	a1 a2 a3
	3
	a2 a1
	a2 a3
	a1 a3
	*/ 
	void init(ifstream &ifs){
		if(!ifs){
			cout << "Read file fail!" <<endl;
			return;
		}
		
		//��ȡ����,Ȩֵ 
		ifs >> boolalpha >> Directed;
		ifs >> boolalpha >> Weighted; 
		
		//��ȡ�������
		ifs >> vtx_num; 
		
		VertexNode<NameType> v;
		
		//��ʼ��vtx_num���յĶ��� 
		verts.assign(vtx_num,v);
		
		//���붥�㼯
		for(int i=0; i<vtx_num; i++){
			ifs>>v.m_name;
			verts[i] = v;	
		} 
		
		//����������֮��ձ�ʱֵ 
		threshold = ( Weighted ? LIMITED : 0); 
		
		cout << boolalpha << Directed << "," <<Weighted<<endl;
		cout << vtx_num << "," << threshold << endl;
		
		for_each(verts.begin(),verts.end(), mem_fun_ref(&VertexNode<NameType>::show) );
		
		
	}
	 
};
