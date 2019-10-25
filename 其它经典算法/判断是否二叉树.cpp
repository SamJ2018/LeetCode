/*
 *  �жϸ����Ķ������Ƿ��Ƕ��������� 
 */

typedef int keyType;
keyType predt = -32767; //predt ����ǰ����ֵ

typedef struct Node
{
    Node *lchild, *rchild;
    keyType data;
} * BiTree;

int judgeBST(BiTree bt)
{
    int b1, b2; //�����ж����������Ƿ��Ƕ���������;
    if (bt == nullptr)
        return 1;
    else
    {
        b1 = judgeBST(bt->lchild);        //�ж��������Ƿ��Ƕ���������
        if (b1 == 0 || predt >= bt->data) //������������ֵΪ0��ǰ�����ڵ��ڵ�ǰ����ֵ
            return 0;                     //���Ƕ���������
        predt = bt->data;
        b2 = judgeBST(bt->rchild); //�ж�������
        return b2;                 //�����������Ľ��
    }
}