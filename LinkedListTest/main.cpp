//
// Created by 冷亚麻色的？ on 2020/2/7.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Node{
    string name;
    int data;
    struct Node *next;
}NODE,*PNODE;

typedef struct List{
    PNODE pHead;
    PNODE pTail;
}LIST,*PLIST;

void init_List(PLIST);//初始化链表
void traverse_List( LIST );//遍历链表
bool is_Empty( LIST );//判断链表非空
int len_List(LIST);//得到链表节点长度
void sort( PLIST );//对链表排序
void add( PLIST );//在末尾添加元素
bool insert(PLIST plist);//插入元素
bool delete_List(PLIST);//删除元素
void test( LIST );//测试

int main(){
    LIST list;
    init_List(&list);
    add(&list);
    traverse_List(list);
    insert(&list);
    traverse_List(list);
    delete_List(&list);
    traverse_List(list);
    cout<<endl;
    cout<<len_List(list)<<endl;//最后输出链表节点个数
    return 0;
}

void init_List(PLIST list){
    list->pHead = NULL;
    list->pHead = (PNODE)malloc(sizeof(NODE));
    if(list->pHead == NULL){
        cout<<"pHead malloc failed!"<<endl;
        exit(-1);
    }
    list->pTail = list->pHead;
    list->pTail->next = NULL;
    int len;
    cout<<"请输入你想生成链表的节点数！"<<endl;
    cin>>len;

    for (int i = 1; i <= len; ++i) {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        cout<<"请输入一个第"<<i<<"个节点的值！"<<endl;
        string name;
        cin>>name;
        int val;
        cin>>val;
        if (pNew == NULL){
            cout<<"New node malloc failed!"<<endl;
        }
        pNew->name = name;
        pNew->data = val;
        list->pTail->next = pNew;
        pNew->next = NULL;
        list->pTail = pNew;
    }
}

void traverse_List(LIST list){
    PNODE p;
    for(p = list.pHead->next; p ; p = p->next){
        cout << p->data << endl;
        cout<<p->name<<endl;
    }
}

bool is_Empty(LIST list){
    if (NULL == list.pHead->next) {
        return true;
    }
    return false;
}

int len_List(LIST list){
    int cnt = 0;
    for(PNODE p = list.pHead->next ; p ; p = p->next){
        cnt++;
    }
    return cnt;
}

void sort(PLIST pList){
    PNODE p,q;
    for (p = pList->pHead->next; p->next ;p = p->next){
        for(q = p->next ; q ; q = q->next){
            if(p->data > q->data){
                int temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
        }
    }
}

void add(PLIST plist){
    int num;
    cout<<"请输入想要添加节点个数！"<<endl;
    cin>>num;
    for (int i = 1; i <= num; ++i) {
        int val;
        cout<< "请输入添加的第"<<i<<"个节点！"<<endl;
        cin>>val;
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL != pNew) {
            pNew->data = val;
            pNew->next = NULL;
            plist->pTail->next = pNew;
            plist->pTail = pNew;
        } else{
            cout<<"new node add failed!"<<endl;
            exit(-1);
        }
    }
}

bool insert(PLIST plist){
    int pos, val;//在第pos个节点的前一个位置插入val，pos从1开始
    cout<<"请输入需要插入的位置："<<endl;
    cin >>pos;
    cout<<"请输入插入的元素："<<endl;
    cin>>val;

    int i = 0;
    PNODE p = plist->pHead;
    while (NULL != p && i < pos - 1){
        i++;
        p = p->next;
    }
    if(i > pos - 1 || p == NULL)
        return false;
    PNODE pNew = (PNODE)malloc(sizeof(NODE));

    if(NULL == pNew)
        return false;

    PNODE q;//临时存放原来pos位置的节点

    pNew->data = val;
    q = p->next;
    p->next = pNew;
    pNew->next = q;

    return true;
}

bool delete_List(PLIST plist){
    int pos;//删除第pos个位置的元素
    cout<<"请输入需要删除的元素的位置："<<endl;
    cin >>pos;

    //找到需要被删除节点的上一个节点位置，并用p指向它
    int i = 0;
    PNODE p = plist->pHead;
    while (NULL != p->next && i < pos - 1){
        i++;
        p = p->next;
    }
    if(i > pos - 1 || NULL == p->next)
        return false;

    PNODE q = p->next;
    p->next = p->next->next;
    free(q);

    return true;
}

void test(LIST list){
    
}

