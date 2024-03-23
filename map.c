#include <stdio.h>
#include <stdlib.h>
int n;
typedef struct node {
    int valuex;
    int valuey;
    struct node *next;
} LinkList;
LinkList* new_list(int x,int y) {
    LinkList *new_node = (LinkList*)malloc(sizeof(LinkList));//开辟节点 初始化
    new_node->valuex = x;
    new_node->valuey = y;
    new_node->next = NULL;
    return new_node;
}
int main() {
    int n, x1, y1, x2, y2;
    scanf("%d",&n);
    LinkList *Head = new_list(0,0);
    LinkList *t = Head;
    LinkList *t1,*t2;
    for(int i = 1;i <= n;i++) {
        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
        t1 = new_list(x1,y1);
        t2 = new_list(x2,y2);
        t->next = t1;
        t1->next = t2;
        t = t->next->next;
    }
    return 0;
}
/*
4
3214 567 456 23 4 234 45 7 23 4 346 45 7 34 346 5

*/