/*
    求出指定结点在二叉排序树中的层次
    思路：每深入一层，计数器+1
*/

int level(BiTree bt, BSTNode *p)
{
    int n = 0; //记录层数
    BiTree t = bt;
    if (bt != nullptr)
    { //树非空，再进行判断
        n++;
        while (t->data != p->data)
        {
            if (t->data < p->data)
                t = t->rchild; //右子树
            else
                t = t->lchild; //左子树
            n++;
        }
    }
    return n;
}