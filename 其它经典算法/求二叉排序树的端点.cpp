KeyType minKey(BSTNode *bt)
{
    //�������������С�ؼ��ֽ��
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

//�����������������ֵ��С��k�Ĺؼ���
void output(BSTNode *bt, keyType k)
{
    if (bt == NULL)
        return;
    if (bt->rchild != nullptr)
        output(bt->rchild, k); //�ݹ�������������
    if (bt->data >= k)
        cout << bt->data;
    if (bt->lchild != nullptr)
        output(bt->lchild, k);
}