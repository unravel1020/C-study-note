/**************************** ˳��� ʵ��˫�˶��� ****************************/
#define DataType int
#define maxn 100005

struct Queue {
    DataType data[maxn<<1];
    int head, tail;
};

/* head �� tail ��һ��λ�� */
void QueueClear(struct Queue* que) {
    que->head = maxn/2;
    que->tail = que->head - 1;
}

void QueueEnqueueFront(struct Queue *que, DataType dt) {
    que->data[ --que->head ] = dt;
}
void QueueEnqueueRear(struct Queue *que, DataType dt) {
    que->data[ ++que->tail ] = dt;
}
void QueueDequeueFront(struct Queue* que) {
    ++que->head;
}
void QueueDequeueRear(struct Queue* que) {
    --que->tail;
}

DataType QueueGetFront(struct Queue* que) {
    return que->data[ que->head ];
}
DataType QueueGetRear(struct Queue* que) {
    return que->data[ que->tail ];
}
int QueueGetSize(struct Queue* que) {
    return que->tail - que->head + 1;
}
int QueueIsEmpty(struct Queue* que) {
    return !QueueGetSize(que);
}

/**************************** ˳��� ʵ��˫�˶��� ****************************/
