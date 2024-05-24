#include <cstdio>
#define MaxSize 5
typedef int ElementType;

typedef struct Stack{
    ElementType data[MaxSize];
    int top;
}SqStack;
bool isEmptyStack(Stack stack) {
    return stack.top == -1;
}
bool isFullStack(Stack stack) {
    return stack.top == MaxSize -1;
}
bool Push(SqStack &sqStack, ElementType e) {
    if (isFullStack(sqStack))  return false;
    sqStack.data [ ++sqStack.top] = e;
    return true;
}
bool Pop(SqStack &sqStack, ElementType &e) {
    if (isEmptyStack(sqStack)) return false;
    e = sqStack.data [sqStack.top-- ];
    return true;
}

typedef struct SqQueue{
    ElementType data [MaxSize];
    int front, rear;
}SqQueue;
void initQueue(SqQueue &sqQueue) {
    sqQueue.front = sqQueue.rear = 0;
}
bool isEmptyQueue(SqQueue sqQueue) {
    return sqQueue.front == sqQueue.rear;
}
bool isFullQueue(SqQueue sqQueue) {
    return (sqQueue.rear +1)%MaxSize == sqQueue.front;
}

bool Enqueue2(SqQueue &sqQueue, ElementType e) {
    if (isFullQueue(sqQueue)) {
        printf("false\n");
        return false;
    }
    sqQueue.data[sqQueue.rear] = e;
    sqQueue.rear = (sqQueue.rear + 1)%MaxSize;
    return true;
}
bool Dequeue2(SqQueue &sqQueue, ElementType &e) {
    if (isEmptyQueue(sqQueue))
    {
        return false;
    }
    e = sqQueue.data[sqQueue.front];
    sqQueue.front = (sqQueue.front + 1)%MaxSize;
    return true;
}
int mainxxxw() {
    SqStack s;
    s.top = -1;
    int i1;
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &i1);
        Push(s, i1);
    }

    int i2;
    int loopTimes = s.top + 1;
    for (int i = 0; i < loopTimes; ++i) {
        Pop(s, i2);
        printf("%2d",i2);
    }
    printf("\n");


    //part 2
    SqQueue sq;
    initQueue(sq);
    int i3;
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &i3);
        Enqueue2(sq,i3);
    }
    int i4;
    for (int i = 0; i < 4; ++i) {
        Dequeue2(sq, i4);
        printf("%2d",i4);
    }
};

int main() {
    char signs [10] = "({})[]";
    Stack s;
    for (int i = 0; i < 6; ++i) {
        char c = signs[i] ;
        if (c == '{' || c == '[' || c == '(') {
            Push(s,c);
        }
        int c2;
        if (!Pop(s,c2)) return false;
        char c3 = (char) c2;
        if (c != c3) return false;
    }

    if (!isEmptyStack(s)) return false;
    return true;

}