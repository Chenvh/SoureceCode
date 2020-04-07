#ifndef _BINTNODE_CC_0406_
#define _BINTNODE_CC_0406_

/*
    数结点类模板
*/
#include "comm.h"

template<typename T>
class BinTNode {
public:
    //PS: m 表示该变量为成员(member)变量
    T m_data;
    BinTNode * m_left;//左孩子
    BinTNode * m_right;//右孩子

    //构造函数，用初始化列表的方式
    //不带参数
    BinTNode(): m_left(NULL), m_right(NULL) {
        //其中 m_data 是模板类，先不初始化
    }

    //带参数
    BinTNode(T data): m_data(data), m_left(NULL), m_right(NULL) {

    }

    //查看函数
    void show() const {
        cout << m_data;
    }

};

//结点测试函数
void testBinTNode() {
    BinTNode<string> * t_node = new BinTNode<string>("ccc");
    t_node->show();
    cout << endl;
}




#endif