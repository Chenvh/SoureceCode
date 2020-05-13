/*Abstract Base Class
图的抽象基类
 
*/
//图类型:无向图,无向网,有向图,有向网 
#include "comm.h"
#include "VertexNode.h"
#include "ArcNode.h"

#define LIMITED 9999

typedef enum{UDG, UDN, DG, DN} GraphKind;
 
template <typename NameType, typename CostType>
class AGraph{
//便于使用,重命名
typedef vector< VertexNode<NameType> >   VV;
typedef vector< ArcNode<CostType> >   VA;
protected: //子类可以访问 
	VV verts; //顶点集合	
	int vtx_num; //顶点个数 
	int arc_num;//边个数
	
	GraphKind g_kind; //图类型 
	
	CostType threshold;//阀值,两顶点之间没有边时的值 
	
	bool Directed; //标识有向(true),无向(false)
	bool Weighted;//标识图(false),网(true)
	
public:
	//构造函数
	AGraph():vtx_num(0), arc_num(0){
		
	}	
	
	
	/*读入文件数据创建图,数据如下: 
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
		
		//读取方向,权值 
		ifs >> boolalpha >> Directed;
		ifs >> boolalpha >> Weighted; 
		
		//读取顶点个数
		ifs >> vtx_num; 
		
		VertexNode<NameType> v;
		
		//初始化vtx_num个空的顶点 
		verts.assign(vtx_num,v);
		
		//输入顶点集
		for(int i=0; i<vtx_num; i++){
			ifs>>v.m_name;
			verts[i] = v;	
		} 
		
		//设置两顶点之间空边时值 
		threshold = ( Weighted ? LIMITED : 0); 
		
		cout << boolalpha << Directed << "," <<Weighted<<endl;
		cout << vtx_num << "," << threshold << endl;
		
		for_each(verts.begin(),verts.end(), mem_fun_ref(&VertexNode<NameType>::show) );
		
		
	}
	 
};
