//
// Created by ������ɫ�ģ� on 2020/2/7.
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

void init_List(PLIST);//��ʼ������
void traverse_List( LIST );//��������
bool is_Empty( LIST );//�ж�����ǿ�
int len_List(LIST);//�õ�����ڵ㳤��
void sort( PLIST );//����������
void add( PLIST );//��ĩβ���Ԫ��
bool insert(PLIST plist);//����Ԫ��
bool delete_List(PLIST);//ɾ��Ԫ��
void test( LIST );//����

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
    cout<<len_List(list)<<endl;//����������ڵ����
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
    cout<<"������������������Ľڵ�����"<<endl;
    cin>>len;

    for (int i = 1; i <= len; ++i) {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        cout<<"������һ����"<<i<<"���ڵ��ֵ��"<<endl;
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
    cout<<"��������Ҫ��ӽڵ������"<<endl;
    cin>>num;
    for (int i = 1; i <= num; ++i) {
        int val;
        cout<< "��������ӵĵ�"<<i<<"���ڵ㣡"<<endl;
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
    int pos, val;//�ڵ�pos���ڵ��ǰһ��λ�ò���val��pos��1��ʼ
    cout<<"��������Ҫ�����λ�ã�"<<endl;
    cin >>pos;
    cout<<"����������Ԫ�أ�"<<endl;
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

    PNODE q;//��ʱ���ԭ��posλ�õĽڵ�

    pNew->data = val;
    q = p->next;
    p->next = pNew;
    pNew->next = q;

    return true;
}

bool delete_List(PLIST plist){
    int pos;//ɾ����pos��λ�õ�Ԫ��
    cout<<"��������Ҫɾ����Ԫ�ص�λ�ã�"<<endl;
    cin >>pos;

    //�ҵ���Ҫ��ɾ���ڵ����һ���ڵ�λ�ã�����pָ����
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

