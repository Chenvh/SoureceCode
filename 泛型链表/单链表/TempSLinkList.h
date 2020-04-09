#ifndef _TEMPSLINKLIST_0409_
#define _TEMPSLINKLIST_0409_
#include "TempSLinkNode.h"
/*
    泛型单链表
*/

template<typename Type>
class TSLinkList
{
private:
    TSLinKNode<Type> *head, *tail;
public:
    //构造函数
    TSLinkList():head(NULL), tail(NULL) {
    }
    
    //析构函数
    //~TempSLinkList();

    //头插法
    void addToHead(Type data) {
        head = new TSLinKNode<Type>(data, head);

        //更新tail
        if(tail == NULL) {
            tail = head;
        }
    }

    //尾插法
    void addToTail(Type data) {
        if(tail != NULL) {
            tail->next = new TSLinKNode<Type>(data);
            tail = tail->next;
        }
        else {
            head = tail = new TSLinKNode<Type>(data);
        }
    }

    //删除尾结点
    void delFromTail(Type &e) {
        //合法性验证
        if(isEmpty()) {
            cout << "Empty" << endl;
            return ;
        }

        //获取tail
       e = tail->m_data;

        if(head == tail) {
            delete head;
            head = tail = NULL;
        }
        else {
            TSLinKNode<Type> *pre;
            for(pre=head; pre->next != tail; pre=pre->next) {
            }

            delete tail;
            pre->next = NULL;
            tail = pre;
        }
    }

    //判空
    bool isEmpty() {
        return NULL == head;
    }

    //查看函数
    void visitNode(TSLinKNode<Type> * pnode) {
        cout << pnode->m_data << "->";
    }

    //遍历链表函数
    void showList(){
        cout << "[";
        for(TSLinKNode<Type> *p = head; p!=NULL; p=p->next) {
            visitNode(p);
        }
        cout << "NULL" ;
        cout << "]" << endl;
    }
};

//char 型数据测试
void testLinkListChar() {
    TSLinkList<char> list1;
    list1.addToHead('a');
    list1.showList();
    list1.addToTail('b');
    list1.showList();
}

//整型数据测试
void testLinkListInt() {
    TSLinkList<int> list;
    for(int i=0; i<=30; i++) {
        list.addToTail(i);
    }
    list.showList();

    int n;
    list.delFromTail(n);
    cout << n << endl;


    list.showList();
}






#endif