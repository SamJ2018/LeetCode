/*
    ���ָ������ڶ����������еĲ��
    ˼·��ÿ����һ�㣬������+1
*/

int level(BiTree bt, BSTNode *p)
{
    int n = 0; //��¼����
    BiTree t = bt;
    if (bt != nullptr)
    { //���ǿգ��ٽ����ж�
        n++;
        while (t->data != p->data)
        {
            if (t->data < p->data)
                t = t->rchild; //������
            else
                t = t->lchild; //������
            n++;
        }
    }
    return n;
}