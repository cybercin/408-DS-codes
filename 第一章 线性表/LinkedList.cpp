#include <cstdio>
#include <cstdlib>

typedef int ElementType;

typedef struct LNode{
    ElementType data;
    struct LNode *next;
} LNode, *List;

void insertLnodeHead(List &list, ElementType e) {
    LNode *s = (LNode *)malloc(sizeof (LNode));
    s->data=e;
    s->next=list->next;
    list->next =s;
}

void insertLnodeTail(List &list, ElementType e) {
    List s = (LNode *)malloc(sizeof(LNode));
    s -> data = e;
    s -> next = NULL;
    List r = list;

    while (r ->next != NULL) {
        r = r -> next;
    }
    r -> next = s;
    r =s;
}

void printlist(List list) {
    list = list->next;
    while (list != NULL) {
        printf("%3d", list -> data);
        list = list-> next;
    }
    printf("\n");
}

void initList(List &l) {
    l = (LNode *)malloc(sizeof(LNode));
    l-> next = NULL;
}
//按位置查找
List GetElem(List l,int pos) {
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

List LocateElem(List l, ElementType e) {
    List  p = l->next;

    while ( p != NULL && p ->data != e) {
        p = p->next;
    }
    return p;
}

bool insertNode(List &l,int pos,ElementType e) {
    //legal check for position
    int i = 0;
    List prior = GetElem(l,pos -1);
    if (prior == NULL) {
        return false;
    }

    List s = (LNode *)malloc(sizeof(LNode));
    s -> data = e;

    s -> next = prior->next;
    prior -> next = s;
    return true;
}

bool deleteNode(List &l, int pos) {
    List prior = GetElem(l, pos -1);
    if(prior == NULL || prior ->next == NULL) {
        return false;
    }
    List q = prior -> next;
    prior -> next = q -> next;
    free(q);
    return true;
}

void find_middle(List L,List &L2){
    List ppre , pcur;
    ppre = pcur = L -> next;

    while (pcur -> next != NULL &&  pcur -> next -> next != NULL) {
        pcur = pcur -> next -> next;
        ppre = ppre -> next;
    }
    L2->next = ppre->next;
    ppre->next = NULL;
}

void reverseList(List &l2) {
    List r,s,t;

    // l2 only have 0 or 1 element
    if (l2->next==NULL || l2->next->next == NULL) {
        return;
    }

    r = l2->next;
    s = r->next;
    t = s->next;

    while (t != NULL) {
        //swap r s and step forward
        s ->next = r;
        r = s; s = t; t = t->next;
    }
    s ->next = r;

    l2 ->next ->next = NULL;
    l2 ->next = s;
}

void merge (List &l1, List &l2) {
    List  pcur,p,q;
    pcur = l1 -> next;
    p = pcur->next;
    q = l2 -> next;

    while (p != NULL && q != NULL) {
        pcur ->next = q;
        pcur = pcur ->next;
        q = q ->next;

        pcur-> next = p;
        pcur = pcur -> next;
        p = p ->next;
    }

    // p or q has remained one element
    if (p != NULL) {
        pcur ->next = p;
        pcur = pcur ->next;
    }

    if (q != NULL) {
        pcur ->next = q;
        pcur = pcur ->next;
    }
}

int mainxxxx () {
    List l;
    initList(l);
    {
    insertLnodeTail(l,1);
    insertLnodeTail(l,2);
    insertLnodeTail(l,3);
    insertLnodeTail(l,4);
    insertLnodeTail(l,5);
    insertLnodeTail(l,6);
    }
    printlist(l);

    List l2; initList(l2);
    find_middle(l,l2);

    printlist(l);
    printlist(l2);

    reverseList(l2);
    printlist(l2);

    merge(l,l2);
    printlist(l);
    return 0;
}


int main2() {
    List l;
    initList(l);
    insertLnodeHead(l,1);
    insertLnodeHead(l,2);
    insertLnodeHead(l,3);
    insertLnodeTail(l,4);
    insertLnodeTail(l,5);
    insertLnodeTail(l,6);
    printlist(l);
    printf("\n");

    insertNode(l,3,7);
    insertNode(l,1,8);

    printlist(l);
    printf("\n");

    deleteNode(l,1);
    printlist(l);
    printf("\n");

    bool f1 = deleteNode(l,0);
    bool f2 = deleteNode(l,8);
    printlist(l);
    printf("\n");

    printf("%d ",f1);
    printf("%d \n",f2);

    deleteNode(l,7);
    printlist(l);
    printf("\n");
        return 0;
//    List p2 = LocateElem(l,5);
//    printf("%\n");
//    printf("%p",p2);
//
//    List p1 = GetElem(l,5);
//    printf("%\n");
//    printf("%p",p1);
}

//void PrintListOJ(List L){
//    L=L->next;
//    while(L!=NULL){
//        printf("%d",L->data);//打印当前结点数据
//        L=L->next;//指向下一个结点
//
//        if(L!=NULL){
//            printf(" ");
//        }
//    }
//    printf("\n");
//}
//
//int main() {
//    List  l1  = (LNode *) malloc(sizeof (LNode));
//    l1->next = NULL;
//    List  l2  = (LNode *) malloc(sizeof (LNode));
//    l2->next = NULL;
//
//
//    int e1;
//    while (scanf("%d", &e1) && e1 !=9999) {
//        List s = (LNode *) malloc(sizeof (LNode));
//        s->data  = e1;
//
//        s->next = l1 -> next;
//        l1->next = s;
//    }
//    PrintListOJ(l1);
//
//    int e2;
//    LNode * r = l2;
//    while (scanf("%d", &e2) && e2 !=9999) {
//        List s = (LNode *) malloc(sizeof (LNode));
//        s->data  = e2;
//        s -> next = r->next;
//        r->next =s;
//        r = s;
//    }
//    PrintListOJ(l2);
//
//}







