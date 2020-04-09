#ifndef _TEMPSLINKLIST_0409_
#define _TEMPSLINKLIST_0409_
#include "TempSLinkNode.h"
/*
    ���͵�����
*/

template<typename Type>
class TSLinkList
{
private:
    TSLinKNode<Type> *head, *tail;
public:
    //���캯��
    TSLinkList():head(NULL), tail(NULL) {
    }
    
    //��������
    //~TempSLinkList();

    //ͷ�巨
    void addToHead(Type data) {
        head = new TSLinKNode<Type>(data, head);

        //����tail
        if(tail == NULL) {
            tail = head;
        }
    }

    //β�巨
    void addToTail(Type data) {
        if(tail != NULL) {
            tail->next = new TSLinKNode<Type>(data);
            tail = tail->next;
        }
        else {
            head = tail = new TSLinKNode<Type>(data);
        }
    }

    //ɾ��β���
    void delFromTail(Type &e) {
        //�Ϸ�����֤
        if(isEmpty()) {
            cout << "Empty" << endl;
            return ;
        }

        //��ȡtail
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

    //�п�
    bool isEmpty() {
        return NULL == head;
    }

    //�鿴����
    void visitNode(TSLinKNode<Type> * pnode) {
        cout << pnode->m_data << "->";
    }

    //����������
    void showList(){
        cout << "[";
        for(TSLinKNode<Type> *p = head; p!=NULL; p=p->next) {
            visitNode(p);
        }
        cout << "NULL" ;
        cout << "]" << endl;
    }
};

//char �����ݲ���
void testLinkListChar() {
    TSLinkList<char> list1;
    list1.addToHead('a');
    list1.showList();
    list1.addToTail('b');
    list1.showList();
}

//�������ݲ���
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