#include <iostream>

using namespace std;

typedef struct car {
    int num;
    struct car *next;
} CAR, *PCAR;

typedef struct my_stack {
    int maxsize;
    PCAR stack_head;
    PCAR stack_tail;
} STACK, *PSTACK;

typedef struct my_queue {
    int maxsize;
    PCAR queue_head;
    PCAR queue_tail;
} QUEUE, *PQUEUE;

void stack_init(PSTACK);

int stack_length(STACK);

bool stack_isfull(STACK);

bool stack_pop(PSTACK);

void stack_traverse(STACK);

bool stack_isempty(STACK);

bool stack_push(PSTACK, int);

bool stack_search(STACK);

void queue_init(PQUEUE);

void queue_traverse(QUEUE);

bool queue_isfull(QUEUE);

int queue_length(QUEUE);

bool queue_push(PQUEUE, int);

bool queue_pop(PQUEUE, int *);

bool queue_isempty(QUEUE);

bool queue_search(QUEUE);

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    STACK stack;
    QUEUE queue;
    stack_init(&stack);
    queue_init(&queue);
    stack.maxsize = n;
    queue.maxsize = m;
    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        switch (op) {
            case 1 : {
                int car_num;
                cin >> car_num;
                if (stack_push(&stack, car_num)) {
                    stack_traverse(stack);
                    queue_traverse(queue);
                } else if (queue_push(&queue, car_num)) {
                    stack_traverse(stack);
                    queue_traverse(queue);
                }
                break;
            }
            case 2: {
                if (stack_pop(&stack)) {
                    if (!queue_isempty(queue)) {
                        int car_num;
                        queue_pop(&queue, &car_num);
                        stack_push(&stack, car_num);
                    }
                    stack_traverse(stack);
                    queue_traverse(queue);
                }else{
                    stack_traverse(stack);
                    queue_traverse(queue);
                }
                break;
            }
            case 3: {
                if (stack_search(stack)) {
                    cout << endl;
                } else {
                    cout << "-1" << endl;
                }
                break;
            }
            case 4: {
                if (queue_search(queue)) {
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

void stack_init(PSTACK pstack) {
    pstack->stack_head = new CAR();
    pstack->stack_head->next = NULL;
}

int stack_length(STACK stack) {
    int len = 0;
    for (PCAR p = stack.stack_head->next; p; p = p->next) {
        len++;
    }
    return len;
}

bool stack_isfull(STACK stack) {
    return stack.maxsize == stack_length(stack);
}

void stack_traverse(STACK stack) {
    PCAR p;
    cout << "parking lot:";
    for (p = stack.stack_head->next; p; p = p->next) {
        cout << " " << p->num;
    }
    cout << endl;
}

bool stack_isempty(STACK stack) {
    return stack.stack_head->next == NULL;
}

bool stack_pop(PSTACK pstack) {
    int num;
    cin >> num;
    PCAR p = pstack->stack_head;//找到需要出栈的车俩的前一个位置
    PCAR q = p->next;//临时存放节点，方便free
    while (q != NULL) {
        if (q->num == num) {
            p->next = q->next;
            free(q);
            return true;
        }
        p = p->next;
        q = q->next;
    }
    return false;
}

bool stack_push(PSTACK pstack, int car_num) {
    if (stack_isfull(*pstack)) {
        return false;
    }
    PCAR p = pstack->stack_head;
    while (p->next != NULL) {
        p = p->next;
    }
    PCAR pcar_new = new CAR();
    pcar_new->num = car_num;
    pcar_new->next = NULL;
    p->next = pcar_new;
    return true;
}

bool stack_search(STACK stack) {
    int index;
    cin >> index;
    if (stack_isempty(stack) || index > stack_length(stack) || index <= 0) {
        return false;
    }
    PCAR pcar = stack.stack_head;
    for (int i = 0; i < index; ++i) {
        pcar = pcar->next;
    }
    cout << pcar->num;
    return true;
}

void queue_init(PQUEUE pqueue) {
    pqueue->queue_head = new CAR();
    pqueue->queue_head->next = NULL;
}

void queue_traverse(QUEUE queue) {
    PCAR p;
    cout << "waiting queue:";
    for (p = queue.queue_head->next; p; p = p->next) {
        cout << " " << p->num;
    }
    cout << endl;
}

int queue_length(QUEUE queue) {
    int len = 0;
    for (PCAR p = queue.queue_head->next; p; p = p->next) {
        len++;
    }
    return len;
}

bool queue_isfull(QUEUE queue) {
    return queue.maxsize == queue_length(queue);
}

bool queue_isempty(QUEUE queue) {
    return queue.queue_head->next == NULL;
}

bool queue_push(PQUEUE pqueue, int car_num) {
    if (queue_isfull(*pqueue)) {
        return false;
    }
    PCAR p = pqueue->queue_head;
    while (p->next != NULL) {
        p = p->next;
    }
    PCAR pcar_new = new CAR();
    pcar_new->num = car_num;
    pcar_new->next = NULL;
    p->next = pcar_new;
    return true;
}

bool queue_pop(PQUEUE pqueue, int *pVal) {
    if (queue_isempty(*pqueue)) {
        return false;
    }
    PCAR p = pqueue->queue_head;
    PCAR q = p->next;
    p->next = q->next;
    *pVal = q->num;
    free(q);
    return true;
}

bool queue_search(QUEUE queue) {
    int index;
    cin >> index;
    if (queue_isempty(queue) || index > queue_length(queue) || index <= 0) {
        return false;
    }
    PCAR pcar = queue.queue_head;
    for (int i = 0; i < index; ++i) {
        pcar = pcar->next;
    }
    cout << pcar->num;
    return true;
}


