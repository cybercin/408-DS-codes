#include <stdio.h>
#include <cstdlib>

#define MaxSize 4
typedef int ElementType;

typedef struct LinkNode{
  ElementType data;
  struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
}LinkQueue;

void initLinkQueue(LinkQueue &queue) {
    LinkNode *linkNode = (LinkNode *)malloc(sizeof(LinkNode));
    linkNode ->next = NULL;
    queue.front = linkNode;
    queue.rear= linkNode;
}
bool isEmpty(LinkQueue queue) {
    return queue.front == queue.rear;
}

bool Enqueue(LinkQueue &queue , ElementType e) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s ->data = e;
    s ->next = NULL;

    queue.rear ->next = s;
    queue.rear = s;
    return true;
}

bool Dequeue(LinkQueue &queue, ElementType &e) {
  if (isEmpty(queue)) {
      printf("Queue is empty\n");
      return false;
  }

  LinkNode *p = queue.front ->next;
  e = p->data;
  queue.front->next = p->next;
  if (queue.rear == p) {
      queue.rear = queue.front;
  }
  free(p);
  return true;
}

int mainxxxxx() {
    LinkQueue lq;
    initLinkQueue(lq);

    printf("is empty ? %d\n", isEmpty(lq));

    Enqueue(lq, 5);
    Enqueue(lq, 6);
    Enqueue(lq, 7);
    Enqueue(lq, 8);

    int i ;
    Dequeue(lq,i);
    printf("%d\n", i);
    Dequeue(lq,i);
    printf("%d\n", i);
    Dequeue(lq,i);
    printf("%d\n", i);Dequeue(lq,i);
    printf("%d\n", i);

    int j;
    Dequeue(lq,j);
    printf("%d\n", j);
}
