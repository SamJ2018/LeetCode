

void judgeAVL(BiTree bt, int &balance, int &h)
{                                       //balance 是否平衡 h树高
    int bl = 0, br = 0, hl = 0, hr = 0; //左子树、右子树平衡标记和高度
    if (bt == nullptr)
    {
        h = 0;
        balance = 1;
    }
    else if (bt->lchild == nullptr && bt->rchild == nullptr)
    {
        //仅仅有根结点
        h = 1;
        balance = 1;
    }
    else
    {
        judgeAVL(bt->lchild, bl, hl); //深入左子树
        judgeAVL(bt->rchild, br, hr); //深入右子树
        h = (hl > hr ? hl : hr) + 1;  //树高=左子树/右子树高+1
        if (abs(hl - hr) < 2)
            balance = bl && br; //取决于左右子树的平衡性
        else
            balance = 0;
    }
}