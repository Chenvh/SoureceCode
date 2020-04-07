#ifndef _BINTREE_CC_0406_
#define _BINTREE_CC_0406_

#include "BinTNode.h"

/*
    Binary Tree Template
    二叉树类模板
*/

//获取数组中元素
template<typename T>
T getOneElem(T s[]) {
    static int i=1;//static：只初始化一次
    return s[i++];
}


template<typename T>
class BinTree {
private:
    BinTNode<T>* mp_root;//根节点
    T m_stop;//停止标记

    //释放二叉树：使用递归
    void destroyTree(BinTNode<T>* start) {
        if(start != NULL) {
            destroyTree(start->m_left);//左
            destroyTree(start->m_right);//右
            delete start;
            start = NULL;
        }
    }
public:
    //构造函数
    BinTree() {
        mp_root = NULL;
    }
    //析构函数
    ~BinTree() {
        destroyTree(mp_root);
    }

    //查看当前结点
    void visitBinTNode(BinTNode<T>* cur) {
        cur->show();
        cout << ",";
    }

    //get root node ,根节点拷贝
    BinTNode<T>* getRoot() {
        return mp_root;
    }

    //get root node, 根节点拷贝引用类型
    BinTNode<T>* &getRootRef() {
        return mp_root;
    }


   /*
	build binary tree
	从数组中创建二叉树 
	数组为先序遍历的序列: char s_binTree[] = "#ABDG###E##C#F##";
   */
    void createBinTreeFromArr(T s[]) {
       m_stop = s[0];

       T e;
       e = getOneElem(s); 
       if(e != m_stop) {

           mp_root = new BinTNode<T>(e);
           assert(mp_root != NULL);//判空

           //build left tree
           BinTree<T> child;//注意：子树对象而不是子树结点

           child.createBinTreeFromArr(s);
           mp_root->m_left = child.mp_root;
           child.mp_root = NULL;

           //build right tree
           child.createBinTreeFromArr(s);
           mp_root->m_right = child.mp_root;
           child.mp_root = NULL;
       }
       else {
           return;
       }
   }//--- createBinTreeFromArr() END

   /*
   ->从文件中读取数据创建二叉树
   */
    void createBinTreeFile(ifstream &ifs) {
        ifs >> m_stop;
        createBinTreeFromFile(ifs, m_stop);
    }

    bool inputFormFile(ifstream &ifs, T &e) {
        ifs >> e;
        return ifs.good();
    }

    /*
	@param ifs :输入流
	@param stop: 终止标记.    
    */
    void createBinTreeFromFile(ifstream &ifs, T &stop) {
        T e;

        if(ifs.good()) {
            ifs >> e;
        }

        if(e == stop) return ;

        mp_root = new BinTNode<T>(e);//build root
        assert(mp_root != NULL);//判空

        //build left tree
        BinTree<T> child;//子树对象

        child .createBinTreeFromFile(ifs, stop);
        mp_root->m_left = child.mp_root;
        child.mp_root = NULL;

        //build right tree
        child.createBinTreeFromFile(ifs,stop);
        mp_root->m_right = child.mp_root;
        child.mp_root = NULL;
    }//---->createBinTreeFromFile() END

   /*
	从数组中先序创建二叉树
	数组为先序遍历的序列: char s_binTree[] = "#ABDG###E##C#F##";
   */
    void createBinTreeFromArr(BinTNode<T>* &subtree, T s[]) {
        m_stop = s[0];

        T e;
        e = getOneElem(s);//获取数组元素

        if(e != m_stop) {

            subtree = new BinTNode<T>(e);
            assert(subtree != NULL);//判空

            createBinTreeFromArr(subtree->m_left,s);
            createBinTreeFromArr(subtree->m_right,s);
        }
        else {
            return;
        }//createBinTreeFromArr() END -- 两个参数
    }

    //递归遍历(recurive)
    //VLR：前序遍历
    void preOrderRecur(BinTNode<T>* subtree) {
        if(subtree != NULL) {
            visitBinTNode(subtree);//Visit
            preOrderRecur(subtree->m_left);//->左子树
            preOrderRecur(subtree->m_right);//->右子树
        }
        else {
            return ;
        }
    }

    //LVR：中序遍历
    void inOrderRecur(BinTNode<T>* subtree) {
        if(subtree != NULL) {
            inOrderRecur(subtree->m_left);//-> 左子树
            visitBinTNode(subtree);//Visit
            inOrderRecur(subtree->m_right);//-> 右子树
        }
        else {
            return ;
        }
    }

    //LRV：后序遍历
    void postOrderRecur(BinTNode<T>* subtree) {
        if(subtree != NULL) {
            postOrderRecur(subtree->m_left);//-> 左子树
            postOrderRecur(subtree->m_right);//-> 右子树
            visitBinTNode(subtree);//Visit
        }
        else {
            return ;
        }
    }

    //非递归遍历
    //VLR(前序遍历)==>Stack-->栈方法
    void preOrderStack() {
        stack<BinTNode<T> *> s_pre;
        s_pre.push(NULL);//reset：初始化

        BinTNode<T>* start = mp_root;

        while(start != NULL) {

            visitBinTNode(start);//Visit

            if(start->m_right) {
                s_pre.push(start->m_right);//save right subtree
            }

            if(start->m_left) {
                start = start->m_left;
            }

            else {//叶子结点情况
                start = s_pre.top();//取栈顶元素
                s_pre.pop();//出栈
            }
        }
    }//---->preOrderStack() END;

    //LVR(中序遍历)==>Stack-->栈方法
    void inOrderStack() {
        stack<BinTNode<T> *> s_in;

        BinTNode<T>* start = mp_root;
        while(start != NULL || ! s_in.empty()) {
            if(start != NULL) {
                s_in.push(start);//save root

                start =  start->m_left;//Visit letf subtree
            }
            else {
                start = s_in.top();//取栈顶元素
                s_in.pop();//出栈

                visitBinTNode(start);//Visit
                start = start->m_right;
            }
        }
    }//--->inOrderStack() END
    
    //LRV(后序遍历)==>Stack-->栈方法

   /*
    level traverse：层序遍历
    使用队列方法
   */
    void levelOrderQueue() {
        queue<BinTNode<T>* > q_level;
        BinTNode<T>* start = mp_root;
        BinTNode<T>* cur;

        if(start != NULL) {
            q_level.push(start);
        }

        //traverse queue
        while(! q_level.empty()) {

            cur = q_level.front();
            visitBinTNode(cur);

            if(cur->m_left != NULL) {
                q_level.push(cur->m_left);//left subtree enQueue
            }
            if(cur->m_right != NULL) {
                q_level.push(cur->m_right);//right subtree enQueue
            }

            q_level.pop();//出队
        }
    }//---->levelOrderQueue() END;
    



};

//测试遍历函数(模板)
template <typename T>
void testTraverse(BinTree<T> &tree) {
	cout<<"PreOrder Traverse Stack:" << endl;
    tree.preOrderStack();
	cout << endl<< endl;
	
	cout<<"InOrder Traverse Stack:" << endl;
    tree.inOrderStack();
	cout << endl<< endl;

	cout<<"LevelOrder Traverse Queue:" << endl;
    tree.levelOrderQueue();
	cout << endl<< endl;
	

	cout<<"PreOrder Traverse Recurive:" << endl;
	tree.preOrderRecur(tree.getRoot());
	cout << endl<< endl;
	
	cout<<"InOrder Traverse Recurive:" << endl;
	tree.inOrderRecur(tree.getRoot());
	cout << endl<< endl;
	
	cout<<"PostOrder Traverse Recurive:" << endl;
	tree.postOrderRecur(tree.getRoot());
	cout << endl<< endl;  
}

//测试从文件中读取数据创建二叉树
void testCreateBinTreeFromFile() {

    //创建二叉树
    BinTree<char> tree;
    string fileName = "bintree.txt";

    ifstream ifs(fileName.c_str());//string转char []

    tree.createBinTreeFile(ifs);

    testTraverse(tree);
}

//测试函数
void testBinTree() {
    //数据源
    char s_binTree[] = "#ABDG###E##C#F##";

    //创建二叉树
    BinTree<char> tree;

    testCreateBinTreeFromFile();

    //tree.createBinTreeFromArr(tree.getRootRef(), s_binTree);

    //testTraverse(tree);
}


#endif//二叉树类