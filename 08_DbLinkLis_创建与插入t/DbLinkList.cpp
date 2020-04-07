#include "DbLinkList.h" 
/*PART2:
 双循环链表的实现: 
 通过类作用域标识符:: 
*/

//构造函数:建立双向循环链表的表头结点
DbLinkList::DbLinkList(int v){
	cur =head = new DbLinkNode(v);
	if(NULL == head){
		cerr << "merory error!";
		exit(1);
	} 
	
	//初始时,前驱后继皆指向自身 
	head->lLink = head->rLink = head;
	//cur = head; //当前结点 == 头结点 head 
	
}

//输出
void DbLinkList:: showAll(){
	DbLinkNode *p;
	p = cur;
	do{
	  visitNode(p);	
	  cout << "->";
	  p=p->rLink;
	}while( p != cur);	
	
	cout << endl;
}

void DbLinkList::visitNode(DbLinkNode * node){
	if(NULL == node){
		cout << "NULL";
	}else{
		cout << node->data;
	}
}

/*将值为v的元素插入链表的当前结点cur之后 
*/
int DbLinkList::insertTail(const int &v){
	
	//step1: 将v封装为新结点 
	DbLinkNode *pNewNode = new DbLinkNode(v);
	
	//step2: 将新结点 插入至 cur后面

	//更新新结点的后继前驱 
	pNewNode->rLink = cur->rLink;
	pNewNode->lLink = cur;
	
	//原表cur的后继的前驱更新为新结点 
	cur->rLink->lLink = pNewNode; 
		
	//原表的cur的后继更新为新结点 
	cur->rLink = pNewNode;  
	
	//cur更新为新结点
	cur = cur->rLink;  
	 
}
