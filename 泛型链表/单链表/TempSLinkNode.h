#ifndef _TEMPSLINKNODE_0409_
#define _TEMPSLINKNODE_0409_
#include "hfile.h"
/*
    泛型单链表
*/

template<typename Type>
class TSLinKNode
{  
public:
    Type m_data;
    TSLinKNode<Type>* next;

    //构造函数
    //不带参数
    TSLinKNode():next(NULL){
    }

    //带参数
    TSLinKNode(Type data): m_data(data), next(NULL) {
    }

    TSLinKNode(Type data, TSLinKNode<Type>* node): m_data(data), next(node) {
    }

    //输出函数
    void show() const {
        cout << m_data << "," << endl;
    }
};

//测试结点函数
void testNode() {
    TSLinKNode<char> node1;
    TSLinKNode<char> node2('A');
    node1.show();
    node2.show();
}



#endif