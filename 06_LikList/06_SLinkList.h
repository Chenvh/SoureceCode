
/*类版本
结点定义 
*/
#include "comm.h" 
class SLinkNode { //Single Link Node
public://公有的
	int data;//数据域
	SLinkNode * next;// 指针域,指向后继(下一个结点 )
	//函数(方法, 行为,操作)
	
	//构造函数:与类同名,没有返回类型,自动调用
	SLinkNode(){
		data = -2020; 
		next = NULL; 
	} 
	/* 用一个结点去初始化另一个结点,传入结点作为this结点的后继 
	@param v:int,结点的数据域
	@param ptr: SLinkNode*,结点对象指针,默认值为0(NULLL) 
	*/
	SLinkNode(int v, SLinkNode* ptr=0){
		data = v;
		next = ptr;
	}
	
	//输出结点 
	void show(){
		cout << data << "->" << next << endl;
	}	
};

//类的定义: 带头结点的单链表表 
class SLinkList{ // Single Link List
private: //成员变量(属性 )
	SLinkNode * head , * tail; //头尾指针
public:
	//CRUD,成员函数声明 
	
	//头插法: 将值为v元素插入至链表的第1个位置 
	void addToHead(int); 
	
	//尾插法:将值为v的元素插入至链表的尾部tail
	void addToTail(int);
	
	//删除尾结点:将删除的尾结点数据保存至v中 
	void delFromTail(int&); 
	
	//查找:按序号查找,	从head开始逐渐查找 
	
	//判断是否为空表
	bool isEmpty(){
		return  NULL == head;
	} 
		
	//构造函数 
	SLinkList(){
		head = NULL;		
		tail = NULL; //空表 
	} 
	
	void visitNode(SLinkNode * pnode){
		cout << pnode->data << "->";
	}
	
	//traverse遍历: 输出链表
	void showList(); 
	 
};

//::类作用域标识符,用来标识该函数属于哪一个类的 

/*删除尾结点:将删除的尾结点数据保存至v中 
@param v: 类型为int&,引用类型 
*/
void SLinkList::delFromTail(int& v){
	//step0:合法性验证 
	if(isEmpty()){//是空表 
		cout << "Empty error!" << endl;
		v = -2020; 
		return; 
	} 
	
	//获取tail的数据 
	v = tail->data;
	
	if(head == tail){//只有一个结点 
		delete head; // 释放内存 
		head = tail = NULL;  //置空 
	} 
	else{ //有多个结点
	 //step1: 查找到tail的前驱find the predecessor of tail
	 SLinkNode * pre;
	 for(pre=head; pre->next != tail; pre = pre->next){
	 }//for ending,  pre->next == tail	 
	 
	 //step2: 删除 
	 delete tail;
	 pre->next = NULL;//尾结点后继置空 
	 tail = pre; //更新tail 
	} 
	
} 


//头插法: 将值为v元素插入至链表的第1个位置 
void SLinkList::addToHead(int v){
	//将新结点作为新表的head, 参数head代表的是原表,原表作为新结点的后继		
	head  = new SLinkNode(v, head);
	
	//更新 tail
	if(tail == NULL){
		tail = head;
	} 
}

//尾插法:将值为v的元素插入至链表的尾部tail
void  SLinkList::addToTail(int v){
	//如果表非空,head是不用修改 
	if(tail != NULL){
		tail -> next = new SLinkNode(v);//新结点作为原表tail的后继 
		tail = tail->next;//更新新表tail 
	} 
	else{ //tail == NULL, head == NULL
		head = tail = new SLinkNode(v);//空表时,新结点既是head也是tail 
	}	
}
	
//traverse遍历: 输出链表
void SLinkList::showList(){
	for(SLinkNode * p = head; p!=NULL; p=p->next){
		visitNode(p);			
	}//for ending, p == NULL
	cout << "NULL";
	cout << "\ntraverse over!\n" << endl;
} 	

 
