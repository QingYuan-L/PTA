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
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
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

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X )//迭代实现
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
//Position BinarySearch( List L, ElementType X )//递归实现
//{
//
//}