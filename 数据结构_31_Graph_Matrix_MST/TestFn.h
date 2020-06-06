#include "MatrixGraph.cpp"

void testGraph(){
	
	int i, j, k, n;
	//string s="udgData.txt";
	string s="udnData.txt";

	MatrixGraph<string,int> g;
	VertexNode<string> v1, v2;

	g.createFromFile(s);
	g.show();

	cout<<"MatrixGraph�����������������ͼ�Ľ����" << endl;
	g.DFSTraverse(Visit);
	cout<<"MatrixGraph����������������ͼ�Ľ����" << endl;
	g.BFSTraverse(Visit);

}
