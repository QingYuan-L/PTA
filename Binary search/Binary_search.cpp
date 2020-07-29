//
// Created by admin on 2020/7/28.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
Position BinarySearch( List L, ElementType X )//����ʵ��
{
    Position Right=1;
    Position Left= L->Last;
    Position mid ;
    while(Right<=Left)
    {
        mid = (Right+Left)/2;
        if(L->Data[mid]==X)return mid;
        if(X>L->Data[mid])Right=mid+1;
        else Left=mid-1;
    }
    return  NotFound;
}
//Position BinarySearch( List L, ElementType X )//�ݹ�ʵ��
//{
//
//}