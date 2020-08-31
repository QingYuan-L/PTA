#include<stdio.h>
#include<stdlib.h>
typedef struct PolyNode * Polynomial;
struct PolyNode
{
    int coef;
    int exp;
    Polynomial next;
};
typedef Polynomial list;

list Read();
list Mult(list L1,list L2);
list Add(list L1,list L2);
void Print(list L);
void Attach_node(list L1,list L2);

int main(int argc, char const *argv[]) {
    list L1 = Read();
    list L2 = Read();
    list mult_L = Mult(L1,L2);
    list add_L = Add(L1,L2);
    Print_list(mult_L);
    Print_list(add_L);
    return 0;
}

void Attach_node(list L1,list L2){
    L2->next = L1->next;
    L1->next = L2;
}
void add_node(list L1,list L2){
    list new = (list)malloc(sizeof(list));
    new->coef = L1->coef+L2->coef;
    new->exp = L1->exp + L2->exp;
    return new;
}

list Read(){
    int num;
    scanf("%d",&num);
    int coef,exp;
    list new=(list)malloc(sizeof(list));
    list p =  new
    ;
    while(num--){
        scanf("%d %d",&coef,&exp);
        list temp=(list)malloc(sizeof(list));
        temp->coef = coef,temp->exp = exp;
        Attach_node(p,temp);
        p = temp;
    }
    p->next = NULL;
    return new;
}

list Mult(list L1,list L2){
    list t1,t2;
    t1 = L1->next,t2= L2->next;
    list temp_L1=t1,temp_L2=t2;
    list after_add = (list)malloc(sizeof(list));
    list temp_add=after_add;
    after_add->next = NULL;
    while(temp_L1){
        temp_L2=t2;
        list after_mult = (list)malloc(sizeof(list));
        after_mult->next =NULL;
        list temp_mult=after_mult;
        while (temp_L2)
        {
            list temp_node = (list)malloc(sizeof(list));
            temp_node->coef = temp_L1->coef * temp_L2->coef;
            temp_node->exp = temp_L1->exp + temp_L2 ->exp;
            Attach_node(temp_mult,temp_node);
            temp_mult = temp_mult->next;
            temp_L2 = temp_L2 ->next;
        }
        temp_L1 = temp_L1->next;
        after_add = Add(after_add,after_mult);
    }
    return after_add;
}
list Add(list L1,list L2){
    list t1,t2;
    t1= L1->next,t2 = L2->next;
    list new = (list)malloc(sizeof(list));
    new ->next = NULL;
    list rear  = new;
    while (t1&&t2)
    {
        list temp = (list)malloc(sizeof(list));
        if(t1->exp==t2->exp){
            temp->exp = t1->exp;
            temp->coef = t1->coef+t2->coef;
            if(temp->coef!=0){
                Attach_node(rear,temp);
                rear = rear ->next;
            }
            t1 = t1->next,t2 = t2->next;
        }else if(t1->exp>t2->exp)
        {
            temp->exp = t1->exp;
            temp->coef = t1->coef;
            Attach_node(rear,temp);
            rear = rear ->next;
            t1 = t1->next;
        }else{
            temp->exp = t2->exp;
            temp->coef = t2->coef;
            Attach_node(rear,temp);
            rear = rear ->next;
            t2 = t2->next;
        }
    }
    while (t1)
    {
        list temp = (list)malloc(sizeof(list));
        temp->exp = t1->exp;
        temp->coef = t1->coef;
        Attach_node(rear,temp);
        rear = rear->next;
        t1 = t1->next;
    } 
    while (t2)
    {
        list temp = (list)malloc(sizeof(list));
        temp->exp = t2->exp;
        temp->coef = t2->coef;
        Attach_node(rear,temp);
        rear = rear->next;
        t2 = t2->next;
    } 
    return new;
}



void Print_list(list L){
    
    L = L->next;
    if(L==NULL){
        printf("0 0\n");
    }
    else{
        printf("%d %d",L->coef,L->exp);
        L = L->next;
        while(L!=NULL){
            printf(" %d %d",L->coef,L->exp);
            L=L->next;
        }
        printf("\n");
    }
}

