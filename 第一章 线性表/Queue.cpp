#include <stdio.h>
#define MaxSize 4
typedef int ElementType;

typedef struct {
    ElementType data[MaxSize];
    int front, rear;
}SqQueue, *pSq;

void initSqQueue(SqQueue &sq) {
    sq.front = 0;
    sq.rear = 0;
}

bool isEmpty(SqQueue sq) {
    return sq.front == sq.rear;
}

bool isFull(SqQueue sq) {
    return ((sq.rear +1 ) % MaxSize) == sq.front;
}

bool Enqueue(SqQueue &sq, ElementType e) {
    if (isFull(sq)) {
        printf("QUEUE IS FULL and data is %d\n",e);
        return false;
    }

    sq.data [sq.rear] = e;
    sq.rear = (sq.rear + 1) % MaxSize;
    return true;
}

bool Dequeue(SqQueue &sq, ElementType &e) {
    if (isEmpty(sq)) {
        printf("QUEUE IS Empty, front = %d, rear =%d\n",sq.front,sq.rear);
        return false;
    }

    e = sq.data[sq.front];
    sq. front = (sq.front + 1) % MaxSize;
    return true;
}

int main22sd() {
    SqQueue sq;
    initSqQueue(sq);
    printf("is full ? %d\n", isEmpty(sq));

    Enqueue(sq,1);
    Enqueue(sq,2);
    Enqueue(sq,3);

    int i1,i2,i3,i4,i5,i6;
    Dequeue(sq,i1);
    Dequeue(sq,i2);
    Dequeue(sq,i3);
    Dequeue(sq,i4);
    Dequeue(sq,i4);

    Enqueue(sq,44);
    Enqueue(sq,45);
    int i =1;
}
