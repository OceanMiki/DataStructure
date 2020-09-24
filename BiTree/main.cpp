/**输入格式：
    第一行两个正整数n, r. 代表树的结点数量与根节点编号。
    接下来n行, 每行3个整数x, y, z
    表示结点x的左儿子是y， 右儿子是z

    数据保证输入是合法二叉树，所有结点编号均在1~n的范围内
 *
 *  思路：
 *  题目已经说明每个结点的编号不一样
 *  而且如果某个结点的左右两个子结点都为0的话，
 *  说明再往下就没有子树了
 *  所以很容易由此每次找到结点创建它的左右子树
 *  当然如果题目直接给前（中、后）序遍历结果就更简单了
 *  求深度，递归左右子树后比较得到最大深度即可
 */

#include <iostream>

using namespace std;

/**
 * 二叉树结点的结构体
 */

typedef struct BinaryTreeNode {
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
} NODE, *PNODE;

/**
 * 记录二叉树的根结点
 */

typedef struct BinaryTree {
    BinaryTreeNode *root;
} TREE, *PTREE;

/**
 * 根据给定结点生成左右子节点
 * @param p 给定结点
 * @param left 左子结点的data
 * @param right 右子结点的data
 */

void CreateNode(PNODE p, int left, int right) {
    p->left = new NODE;
    p->right = new NODE;
    p->left->data = left;
    p->right->data = right;
}

/**
 * 查找需要生成子节点的二叉树结点（中序）
 * @param pNode 最开始给定二叉树的根结点，后续递归查找
 * @param data  所查找的结点的data
 * @return 查找到的结点
 */

PNODE SearchNode(PNODE pNode, int data) {
    if (pNode->data == data) {
        return pNode;
    }
    PNODE result = new NODE;
    if (pNode->left->data != 0) {
        result = SearchNode(pNode->left, data);
    }
    if (result->data == data) {
        return result;
    }
    if (pNode->right->data != 0) {
        result = SearchNode(pNode->right, data);
    }
    return result;
}

/**
 * 边界条件明显，递归简直不要太简单
 * @param p 树根root
 * @return 深度
 */

int depth(PNODE p) {
    if (p->data != 0) {
        int l = depth(p->left);
        int r = depth(p->right);
        return l > r ? l + 1 : r + 1;
    }
    return 0;
}

int main() {
    int n, r;
    cin >> n >> r;
    PTREE T = new TREE;//建议使用auto
    T->root = new NODE;
    T->root->data = r;
    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        PNODE p = SearchNode(T->root, x);
        CreateNode(p, y, z);
    }
    cout << depth(T->root) << endl;
    return 0;
}
