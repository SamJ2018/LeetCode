KeyType minKey(BSTNode *bt)
{
    //求二叉排序树最小关键字结点
    while (bt->lchild != nullptr)
        bt = bt->lchild;
    return bt->data;
}

KeyType maxKey(BSTNode *bt)
{
    while (bt->rchild != null)
        bt = bt - rchild;
    return bt->data;
}

//求二叉排序树中所有值不小于k的关键字
void output(BSTNode *bt, keyType k)
{
    if (bt == NULL)
        return;
    if (bt->rchild != nullptr)
        output(bt->rchild, k); //递归输出右子树结点
    if (bt->data >= k)
        cout << bt->data;
    if (bt->lchild != nullptr)
        output(bt->lchild, k);
}