#include <iostream>

using namespace std;

typedef struct Node {
    string name;
    string pos;
    int id;
    struct Node *next;
} NODE, *PNODE;

typedef struct List {
    PNODE pHead;
    PNODE pTail;
} LIST, *PLIST;

void init_List(int, PLIST);//初始化链表
void traverse_List(LIST);//遍历链表
bool is_Empty(LIST);//判断链表非空
int len_List(LIST);//得到链表节点长度
bool insert_list(PLIST plist);//插入元素
bool delete_List(PLIST);//删除元素
bool search_list(LIST);//查找元素

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    LIST list;
    init_List(n, &list);
    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op;
        switch (op) {
            case 1 : {
                if (delete_List(&list)) {
                    traverse_List(list);
                } else {
                    cout << "-1" << endl;
                }
                break;
            }
            case 2: {
                if (insert_list(&list)) {
                    traverse_List(list);
                } else {
                    cout << "-1" << endl;
                }
                break;
            }
            case 3: {
                if (search_list(list)) {
                    cout << endl;
                } else {
                    cout << "-1" << endl;
                }
                break;
            }
            default:
                cout << "-1" << endl;
        }
    }
    return 0;
}

void init_List(int num, PLIST list) {
    list->pHead = NULL;
    list->pHead = new NODE();
    if (list->pHead == NULL) {
        cout << "-1" << endl;
    }
    list->pTail = list->pHead;
    list->pTail->next = NULL;
    int len = num;
    for (int i = 1; i <= len; ++i) {
        PNODE pNew = new NODE();
        cin >> pNew->name >> pNew->pos >> pNew->id;
        list->pTail->next = pNew;
        pNew->next = NULL;
        list->pTail = pNew;
    }
}

void traverse_List(LIST list) {
    PNODE p;
    for (p = list.pHead->next; p; p = p->next) {
        cout << p->name << " " << p->pos << " " << p->id << " ";
    }
    cout << endl;
}

bool is_Empty(LIST list) {
    if (NULL == list.pHead->next)
        return true;
    return false;
}

int len_List(LIST list) {
    int cnt = 0;
    for (PNODE p = list.pHead->next; p; p = p->next) {
        cnt++;
    }
    return cnt;
}

bool delete_List(PLIST plist) {
    int pos;//删除第pos个位置的元素
    cin >> pos;

    //找到需要被删除节点的上一个节点位置，并用p指向它
    int i = 0;
    PNODE p = plist->pHead;
    while (NULL != p->next && i < pos - 1) {
        i++;
        p = p->next;
    }
    if (i > pos - 1 || nullptr == p->next)
        return false;

    PNODE q = p->next;
    p->next = p->next->next;

    return true;
}

bool insert_list(PLIST plist) {
    int pos;//在第pos个节点的前一个位置插入val，pos从1开始
    cin >> pos;
    string name;
    string position;
    int id;
    cin >> name >> position >> id;
    int i = 0;
    PNODE p = plist->pHead;
    while (NULL != p && i < pos - 1) {
        i++;
        p = p->next;
    }
    if (i > pos - 1 || p == NULL)
        return false;
    PNODE pNew = new NODE();

    if (NULL == pNew)
        return false;

    PNODE q;//临时存放原来pos位置的节点
    pNew->name = name;
    pNew->pos = position;
    pNew->id = id;

    q = p->next;
    p->next = pNew;
    pNew->next = q;

    return true;
}

bool search_list(LIST list) {
    int index;
    cin >> index;
    if (is_Empty(list) || index > len_List(list) || index <= 0) {
        return false;
    }
    PNODE p = list.pHead;
    for (int i = 0; i < index; ++i) {
        p = p->next;
    }
    cout << p->name + " " + p->pos + " " << p->id;
    return true;
}