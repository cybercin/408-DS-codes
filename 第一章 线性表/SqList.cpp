#include <stdio.h>
#define MaxSize 50
typedef int ElementType;

typedef struct {
    ElementType data [MaxSize];
    int length = 0;
}SqList;

bool insertList(SqList &list, int pos, ElementType e) {
    if (pos <1 || pos > (list.length+1) || list.length >= MaxSize)
    {
        return false;
    }
    for (int i = list.length; i > pos ; i--) {
        list.data[i] = list.data[i-1];
    }
    list.data[pos -1] = e;
    list.length ++;
    return true;
}

bool GetElement (SqList list,int pos, ElementType & e) {
    if (pos <1 || pos > list.length) {
        return false;
    }
    e = list.data[pos-1];
    return true;
}

int LocateElement (SqList list, ElementType e) {
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] == e) {
            return i+1;
        }
    }
    return 0;
}

void PrintList(SqList List) {
    for (int i = 0; i < List.length; ++i) {
        printf("data [%d] = %d\n",i, List.data[i]);
    }
}

bool DeleteList (SqList &list, int pos, ElementType &e) {
    if (pos <1 || pos > list.length) {
        return false;
    }
    e = list.data [pos-1];

    for (int i = pos; i < list.length; ++i) {
        list.data [i-1] = list.data [i];
    }
    list.length --;
    return true;
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    SqList sqList ;
    insertList(sqList,1,1);
    insertList(sqList,2,2);
    insertList(sqList,3,3);
    printf("insert numbers...\n");
    PrintList(sqList);
    printf("insert numbers finished\n\n");

    int ret;
    GetElement(sqList,2,ret);
    printf("%d\n",ret);

    int location = LocateElement(sqList,1);
    printf("location = %d\n",location);


    int deleteNumber;
    DeleteList(sqList, 4, deleteNumber);
    printf("%d\n",deleteNumber);
    PrintList(sqList);
    return 0;
}
