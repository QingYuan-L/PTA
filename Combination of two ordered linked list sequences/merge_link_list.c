#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Read(){
    int a;
    scanf("%d",&a);
    //fflush(stdin);
    PtrToNode new_list = (PtrToNode)malloc(sizeof(PtrToNode));
    PtrToNode temp = new_list;
    while(a--){
        PtrToNode new_node =  (PtrToNode)malloc(sizeof(PtrToNode));
        ElementType data;
        scanf("%d", &data);
        new_node->Data=data;
        temp->Next=new_node;
        temp=temp->Next;
    }
    temp->Next=NULL;
    return new_list;
}
List Merge(List L1,List L2){
    PtrToNode new_list = (PtrToNode)malloc(sizeof(PtrToNode));
    new_list->Next=NULL;
    PtrToNode temp = new_list;
    //使用原节点构建新的list
    while(L1->Next!=NULL && L2->Next!=NULL){
        if(L1->Next->Data<=L2->Next->Data){
            temp->Next= L1->Next;
            temp = temp ->Next;
            L1->Next=L1->Next->Next;
            continue;
        }
        if(L1->Next->Data>L2->Next->Data){
            temp->Next= L2->Next;
            temp = temp ->Next;
            L2->Next=L2->Next->Next;
            continue;
        }
    }
    while (L1->Next!=NULL)
    {
        temp->Next = L1->Next;
        temp = temp ->Next;
        L1->Next=L1->Next->Next;
    }
    while (L2->Next!=NULL)
    {
        temp->Next = L2->Next;
        temp = temp ->Next;
        L2->Next=L2->Next->Next;
    }
    temp->Next = NULL;
    return new_list;
}

void Print(List L){
    if(L->Next==NULL){
        printf("%s","NULL");
        return 0;
    }
    L=L->Next;
    printf("%d",L->Data);
    L=L->Next;
    while(L!=NULL){
        printf(" %d",L->Data);
        L=L->Next;
    }
}