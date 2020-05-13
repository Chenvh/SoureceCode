#include "MatrixGraph.cpp"

void testGraph(){
	
	int i, j, k, n;
	//string s="udgData.txt";
	string s="udnData.txt";

	MatrixGraph<string,int> g;
	VertexNode<string> v1, v2;

	g.createFromFile(s);
	g.show();

	cout<<"MatrixGraph类深度优先搜索遍历图的结果：" << endl;
	g.DFSTraverse(Visit);
	cout<<"MatrixGraph类广度优先搜索遍历图的结果：" << endl;
	g.BFSTraverse(Visit);

}
