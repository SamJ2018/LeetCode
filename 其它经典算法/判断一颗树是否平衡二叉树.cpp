

void judgeAVL(BiTree bt, int &balance, int &h)
{                                       //balance �Ƿ�ƽ�� h����
    int bl = 0, br = 0, hl = 0, hr = 0; //��������������ƽ���Ǻ͸߶�
    if (bt == nullptr)
    {
        h = 0;
        balance = 1;
    }
    else if (bt->lchild == nullptr && bt->rchild == nullptr)
    {
        //�����и����
        h = 1;
        balance = 1;
    }
    else
    {
        judgeAVL(bt->lchild, bl, hl); //����������
        judgeAVL(bt->rchild, br, hr); //����������
        h = (hl > hr ? hl : hr) + 1;  //����=������/��������+1
        if (abs(hl - hr) < 2)
            balance = bl && br; //ȡ��������������ƽ����
        else
            balance = 0;
    }
}