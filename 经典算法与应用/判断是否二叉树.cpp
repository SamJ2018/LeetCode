/*
 *  判断给定的二叉树是否是二叉排序树 
 */

typedef int keyType;
keyType predt = -32767; //predt 代表当前结点的值

typedef struct Node
{
    Node *lchild, *rchild;
    keyType data;
} * BiTree;

int judgeBST(BiTree bt)
{
    int b1, b2; //用于判断左右子树是否是二叉排序树;
    if (bt == nullptr)
        return 1;
    else
    {
        b1 = judgeBST(bt->lchild);        //判断左子树是否是二叉排序树
        if (b1 == 0 || predt >= bt->data) //若左子树返回值为0或前驱大于等于当前结点的值
            return 0;                     //则不是二叉排序树
        predt = bt->data;
        b2 = judgeBST(bt->rchild); //判断右子树
        return b2;                 //返回右子树的结果
    }
}