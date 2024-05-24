#include <cstdlib>
#include <cstdio>

#define MaxSize 50
#define initTop -1
typedef int ElementType;

typedef struct {
    ElementType data[MaxSize];
    int top;
}Stack, *pStack;

typedef struct LinkNode{
    ElementType data;
    struct LinkNode *next;
}Listack, *pListack;

void initStack (pStack &p) {
    p -> top = initTop;
}

void initLinkStack(pListack p) {
    p = NULL;
}
bool isLiStackEmpty (pListack &p) {
    return (p = NULL);
}

bool isEmpty (Stack s) {
    return (s.top == initTop);
}

bool isFull(Stack s) {
    return (s.top == MaxSize -1);
}

bool push (Stack &stack, ElementType e) {
    // if full returns false
    if (stack.top == MaxSize -1) return false;
    stack.data [++ stack.top] = e;
    return true;
}

bool pop (Stack &stack, ElementType &e) {
    if (stack.top == initTop) return false;
    e = stack.data [stack.top--];
    return true;
}

bool getTop(Stack stack, ElementType &e) {
    if (stack.top == initTop) return false;
    e = stack.data[stack.top];
    return true;
}

int mainxsxsa() {
    pListack p;
    initLinkStack(p);

    pListack s = (Listack *)malloc(sizeof(LinkNode));
    s->data = 1111;
    s->next = p;
    p = s;

    if (p != NULL) {
        ElementType e = p->data;
        pListack q = p ->next ;
        free(p);
        p = q;
    }
}
int main222x() {

    Stack s;
    pStack p = & s;
    initStack(p);
    printf("%d\n", isEmpty(s));

    push(s,222);
    printf("%d\n", isEmpty(s));

    int e;
    //pop(s,e);
    getTop(s,e);
    printf("%d\n", isEmpty(s));
    printf("%d\n", e);
    return 0;
}