#ifndef _BINTNODE_CC_0407_
#define _BINTNODE_CC_0407_

/*
    树结点类模板
*/
#include "comm.h"

template<typename T>
class BinTNode {
public:
    //PS：m 意思是成员(member)变量
    T m_data;
    BinTNode* m_left;//左子树
    BinTNode* m_right;//右子树

    //构造函数,用初始化列表方式
    //不带参数
    BinTNode(): m_left(NULL), m_right(NULL) {
        //m_data 是模板，不初始化
    }

    //带参数
    BinTNode(T data): m_data(data), m_left(NULL), m_right(NULL) {
        //data c初始化 m_data
    }

    //输出函数
    void show() const {
        cout << m_data;
        //cout << ",";
    }
};

//树结点测试函数
void testBinTNode() {
    BinTNode<string> * t_node = new BinTNode<string>("ccc");
    t_node->show();

}



#endif