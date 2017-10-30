#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}Link;

void createLink(int pInt[10000], int n1, int brr[10000], int n2, int start, int len, int insert);

void printLink(Link *pNode);

int main(void)
{
  //  freopen("C:\\Users\\mu\\Desktop\\1.txt", "r", stdin); //文件输入到标准输入流
    int n1=0,n2=0;
    int arr[10000],brr[10000];
    char c;
        while (scanf("%d",&arr[n1++]) != EOF && getchar() != '\n');

    while (scanf("%d",&brr[n2++]) != EOF && getchar() != '\n');

    int start,len,insert;
    scanf("%d%d%d",&start,&len,&insert);
    createLink(arr,n1,brr,n2,start,len,insert);
}

void createLink(int arr[10000], int n1, int brr[10000], int n2, int start, int len, int insert) {
    Link * h1=NULL,* h2=NULL,*p,*t=NULL;
    for(int i=0;i<n1;i++){
       if(i<start-1||i>start+len-2){
           p=(Link *)malloc(sizeof(Link));
           p->data=arr[i];
           p->next=NULL;
           if(!h1){
               t=h1=p;
           }
           else{
               t=t->next=p;
           }
       }
    }
    t=NULL;
    for(int i=0;i<n2;i++){
        if(i==insert){
            for(int j=start-1;j<=start+len-2;j++){
                p=(Link *)malloc(sizeof(Link));
                p->data=arr[j];
                p->next=NULL;
                if(!h2){
                    t=h2=p;
                }
                else{
                    t=t->next=p;
                }
            }
        }

        p = (Link *) malloc(sizeof(Link));
        p->data = brr[i];
        p->next = NULL;
        if (!h2) {
            t = h2 = p;
        } else {
            t = t->next = p;
        }

    }
    printf("la:");
    printLink(h1);
    printf("\n");
    printf("lb:");
    printLink(h2);
}

void printLink(Link *pNode) {
    if(pNode){
        printf("%d ",pNode->data);
        printLink(pNode->next);
    }
}