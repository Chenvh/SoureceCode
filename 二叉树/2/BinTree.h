#ifndef _BINTREE_CC_0407_
#define _BINTREE_CC_0407_

/*
    二叉树模板
*/
#include "BinTNode.h"

template<typename T>
T getOneElem(T arr[]) {
    static int i=1;//static：该变量只初始化一次
    return arr[i++];
}


template<typename T>
class BinTree {
private:
    BinTNode<T>* mp_root;//树的根
    T m_stop;//停止标记

    /*
    释放二叉树(释放树节点)：利用递归
    @pargam: BinTNode<T>* 类型参数传入，而不是BinTRee<T>类型
    方法：判空->递归(left)->递归(right)->delete操作->置空操作
    */
    void destroyTree(BinTNode<T>* cur) {
        if(cur != NULL) {
            destroyTree(cur->m_left);//left
            destroyTree(cur->m_right);//right
            delete cur;//释放内存
            cur = NULL;//置空
        }
    }

public:
    //构造函数
    BinTree() {
        mp_root = NULL;
    }

    //析构函数
    ~BinTree() {
        cout << "Destroy binary tree" << endl;
        destroyTree(mp_root);
    }

    //输出树根
    void visitBinTNode(BinTNode<T>* cur) {
        cur->show();
        cout << ",";
    }

    //拷贝根节点
    BinTNode<T> *getRoot() {
        return mp_root;
    }

    //拷贝根节点引用类型
    BinTNode<T> * &getRootRef() {
        return mp_root;
    }

   /*
	build binary tree
	从数组中创建二叉树 
	数组为先序遍历的序列: char s_binTree[] = "#ABDG###E##C#F##";
    -> 一个参数
   */
    void createBinTreeFromArr(T s[]) {
        m_stop = s[0]; //取停止标记

        T e;
        e = getOneElem(s);
        if(e != m_stop) {
            mp_root = new BinTNode<T>(e);
            assert(mp_root != NULL);//判空

            //build left tree
            BinTree<T> child;//子树对象而不是子树结点

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
    }//--->createBinTreeFromArr() END --> 一个参数

   /*
	build binary tree
	从数组中创建二叉树 
	数组为先序遍历的序列: char s_binTree[] = "#ABDG###E##C#F##";
    --> 2个参数
   */
    void createBinTreeFromArr(BinTNode<T> * &subtree, T s[]) {
        m_stop = s[0];//获取停止标记

        T e;
        e = getOneElem(s);//获取数组中元素

        if(e != m_stop) {
            
            subtree = new BinTNode<T>(e);
            assert( subtree != NULL);//判空

            createBinTreeFromArr(subtree->m_left, s);//左子树
            createBinTreeFromArr(subtree->m_right, s);//右子树
        }
        else {
            return ;
        }
    }//createBinTreeFromArr() END ----> 两个参数

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
        BinTree<T> child;
        child.createBinTreeFromFile(ifs, stop);
        mp_root->m_left = child.mp_root;
        child.mp_root = NULL;

        //build right tree
        child.createBinTreeFromFile(ifs, stop);
        mp_root->m_right = child.mp_root;
        child.mp_root = NULL;
    }//createBinTreeFromFile() END


    //递归遍历(recurive)
    //VLR：前序遍历
    void preOrderRecur(BinTNode<T> *subtree) {
        if(subtree != NULL) {
            visitBinTNode(subtree);
            preOrderRecur(subtree->m_left);
            preOrderRecur(subtree->m_right);
        }
        else {
            return ;
        }
    }//preOrderRecur() END;

    //LVR：中序遍历
    void inOrderRecur(BinTNode<T> *subtree) {
        if(subtree != NULL) {
            inOrderRecur(subtree->m_left);
            visitBinTNode(subtree);
            inOrderRecur(subtree->m_right);
        }
        else {
            return ;
        }
    }//inOrderRecur() END

    //LRV：后序遍历
    void postOrderRecur(BinTNode<T> * subtree) {
        if(subtree != NULL) {
            postOrderRecur(subtree->m_left);
            postOrderRecur(subtree->m_right);
            visitBinTNode(subtree);
        }
        else {
            return;
        }
    }

    //非递归遍历
    //VLR(前序遍历)==>Stack-->栈方法
    void preOrderStack() {
        stack<BinTNode<T> *> s_pre;
        s_pre.push(NULL);//reset ：初始化

        BinTNode<T>* start = mp_root;

        while(start != NULL) {
            visitBinTNode(start);

            if(start->m_right != NULL) {
                s_pre.push(start->m_right);//save right subtree
            }

            if(start->m_left != NULL) {
                start = start->m_left;
            }
            else {
                start = s_pre.top();//取栈顶元素
                s_pre.pop();//出栈
            }
        }
    }//preOrderStack() END

    //LVR(中序遍历)==>Stack-->栈方法
    void inOrderStack() {
        stack<BinTNode<T> *> s_in;

        BinTNode<T>* start = mp_root;
        while(start != NULL || ! s_in.empty()) {
            if(start != NULL) {
                s_in.push(start);//save root

                start = start->m_left;
            }
            else {
                start = s_in.top();//取栈顶
                s_in.pop();//出栈

                visitBinTNode(start);

                start = start->m_right;
            }
        }
    }//inOrderStack() END


    //层序遍历: level traverse
    void levelOrderQueue() {

        queue<BinTNode<T> *> q_level;
        BinTNode<T>* start = mp_root;
        BinTNode<T>* cur;
        if(start != NULL) {
            q_level.push(start);
        }

        //traverse queue
        while( ! q_level.empty()) {

            cur = q_level.front();
            visitBinTNode(cur);

            if(cur->m_left != NULL) {
                q_level.push(cur->m_left);
            }
            if(cur->m_right != NULL) {
                q_level.push(cur->m_right);
            }

            q_level.pop();//出队
        }
    }//--levelOrderQueue() END

    /*
    ->获取当前结点的双亲结点，利用队列
    */
    BinTNode<T>* getParentQueue(BinTNode<T>* cur) const {
        queue<BinTNode<T>* > q;
        BinTNode<T> *first;

        if(mp_root != NULL)
        {
            q.push(mp_root);
            while(!q.empty())
            {
                first = q.front();
                q.pop();

                if(first->m_left!=NULL && first->m_left==cur ||
                    first->m_right!=NULL && first->m_right==cur)
                {
                    return first;
                }
                else {
                    if(first->m_left != NULL) {
                        q.push(first->m_left);
                    }

                    if(first->m_right != NULL) {
                        q.push(first->m_right);
                    }
                }
            }
        }
    }//--->getParentQueue() END



};

//输出函数测试
template<typename T>
void TestTraverse(BinTree<T>& tree) {
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
    string Filname = "bintree.txt";

    ifstream ifs(Filname.c_str());

    tree.createBinTreeFile(ifs);

    TestTraverse(tree);
    /*
    程序显示多次调用析构函数，是为啥
    */
}


//二叉树测试函数
void TestBinTree() {
    char s_binTree[] = "#ABDG###E##C#F##";
    BinTree<char> tree;
    testCreateBinTreeFromFile();
    // tree.createBinTreeFromArr(tree.getRootRef(),s_binTree);
    // TestTraverse(tree);

}




#endif