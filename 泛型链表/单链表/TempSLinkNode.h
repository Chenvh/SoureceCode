#ifndef _TEMPSLINKNODE_0409_
#define _TEMPSLINKNODE_0409_
#include "hfile.h"
/*
    ���͵�����
*/

template<typename Type>
class TSLinKNode
{  
public:
    Type m_data;
    TSLinKNode<Type>* next;

    //���캯��
    //��������
    TSLinKNode():next(NULL){
    }

    //������
    TSLinKNode(Type data): m_data(data), next(NULL) {
    }

    TSLinKNode(Type data, TSLinKNode<Type>* node): m_data(data), next(node) {
    }

    //�������
    void show() const {
        cout << m_data << "," << endl;
    }
};

//���Խ�㺯��
void testNode() {
    TSLinKNode<char> node1;
    TSLinKNode<char> node2('A');
    node1.show();
    node2.show();
}



#endif