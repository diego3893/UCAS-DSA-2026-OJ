#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char chdata;
    struct Node *succ;
    struct Node *next;
}Node;

int main(){
    int n, m;
    int find = 0;
    char c;
    scanf("%d%d", &n, &m);
    Node *head_str, *head_pat, *p, *q;
    head_str = (Node*)malloc(sizeof(Node));
    head_str->next = NULL;
    head_str->succ = NULL;
    getchar();
    q = head_str;
    for(int i=0; i<n; ++i){
        c = getchar();
        p = (Node*)malloc(sizeof(Node));
        q->succ = p;
        p->succ = NULL;
        p->next = q;
        q = p;
        p->chdata = c;
    }
    getchar();
    head_pat = (Node*)malloc(sizeof(Node));
    head_pat->next = NULL;
    head_pat->succ = NULL;
    q = head_pat;
    for(int i=0; i<m; ++i){
        c = getchar();
        p = (Node*)malloc(sizeof(Node));
        q->succ = p;
        p->succ = NULL;
        p->next = NULL;
        q = p;
        p->chdata = c;
    }
    head_pat->succ->next = head_pat;
    q = head_pat->succ->succ;
    p = head_pat;
    while(q){
        while(p!=head_pat && p->succ->chdata!=q->chdata){
            p = p->next;
        }
        if(p->succ->chdata == q->chdata){
            p = p->succ;
        }
        q->next = p;
        q = q->succ;
    }
    p = head_pat;
    q = head_str->succ;
    for(int i=1; i<=n; ++i){
        while(p!=head_pat && q->chdata!=p->succ->chdata){
            p = p->next;
        }
        if(p->succ->chdata == q->chdata){
            p = p->succ;
        }
        if(p->succ == NULL){
            printf("%d", i-m);
            find = 1;
            break;
        }
        q = q->succ;
    }
    if(!find){
        printf("-1");
    }
    return 0;
}