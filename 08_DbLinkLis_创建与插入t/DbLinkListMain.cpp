#include "Cpp.h"
#include "DbLinkNode.h"
#include "DbLinkList.h"
/*Test
2020->
13->2020->11->12->

--------------------------------
Process exited after 0.7516 seconds with return value 0
请按任意键继续. . .


*/
int main() {
	DbLinkList *list = new DbLinkList;
	list->showAll();
	for(int i=0;i<3;i++){
		list->insertTail(11+i);
	}
	
	list->showAll();
	
	/*
	DbLinkNode * head = new DbLinkNode(2020);
	cout << head->getData();
	*/
	return 0;
}
