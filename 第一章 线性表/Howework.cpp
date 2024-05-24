#include <cstdio>
#include <cstdlib>

typedef int ElementType;
typedef struct LNode{
    ElementType data;
    struct LNode *next;
} LNode, *List;

void PrintList(List L){
    L = L->next;
    while (L != NULL)
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;//指向下一个结点
    }
    printf("\n");
}

//按位置查找
List GetElem2(List l,int pos) {
    if (pos < 0) {
        return NULL;
    }
    List p = l;
    int i = 0;
    while ( p != NULL && i < pos) {
        p = p -> next;
        i++;
    }
    return p;
}

bool insertNode2(List &l,int pos,ElementType e) {
    //legal check for position
    int i = 0;
    List prior = GetElem2(l,pos -1);
    if (prior == NULL) {
        return false;
    }

    List s = (LNode *)malloc(sizeof(LNode));
    s -> data = e;

    s -> next = prior->next;
    prior -> next = s;
    return true;
}

bool deleteNode2(List &l, int pos) {
    List prior = GetElem2(l, pos -1);
    if(prior == NULL || prior ->next == NULL) {
        return false;
    }
    List q = prior -> next;
    prior -> next = q -> next;
    free(q);
    return true;
}

int main_homework() {

    List l;
    l = (LNode *)malloc(sizeof(LNode));
    l-> next = NULL;

    int e;
    LNode * r = l;
    while (scanf("%d", &e) && e !=9999) {
        List s = (LNode *)malloc(sizeof(LNode));
        s->data =e;
        s->next = r->next;
        r->next = s;
        r = s;
    }

    printf("%d\n", GetElem2(l,2) ->data );

    insertNode2(l,2,99);
    PrintList(l);


    deleteNode2(l,4);
    PrintList(l);
    int a = 1;
}