#include <cstdio>

#define MaxSize 100

typedef int datatype;
typedef struct {
    int rear;
    int front;
    datatype data[MaxSize];
} SqQueue;

// ��ʼ������
void InitQueue(SqQueue &queue) {
    queue.rear = 0;
    queue.front = 0;
}

// �ж϶����Ƿ�Ϊ��
int isEmpty(SqQueue queue) {
    if (queue.rear == queue.front) return 1;
    return 0;
}

// �ж϶����Ƿ�Ϊ��
int isFull(SqQueue queue) {
    if (queue.front-1 == queue.rear) return 1;
    return 0;
}

// ���
int enQueue(SqQueue &queue, datatype data) {
    if (queue.front-1 == queue.rear) return 0;
    queue.data[queue.rear] = data;
    if ( (queue.rear+1)%MaxSize == 0 && (queue.rear+1)%MaxSize < queue.front)
        queue.rear = (queue.rear+1)%MaxSize;
    else queue.rear++;
    return 1;
}

// ����
int deQueue(SqQueue &queue) {
    if (queue.rear == queue.front) return 0;
    queue.data[queue.front] = NULL;
    if ((queue.front+1)%MaxSize == 0 && (queue.front+1)%MaxSize < queue.rear)
        queue.front = (queue.front+1)%MaxSize;
    else queue.front++;
    return 1;
}

// ��ѯ����
void selQueue(SqQueue queue) {
    printf("[SELECT] �����б�[ ");
    for (int i = queue.front; i < queue.rear-1; ++i) {
        printf("%d, ",queue.data[i]);
    }
    printf("%d ]\n",queue.data[queue.rear-1]);
    printf("\n");
}

int main() {
    int ch;
    datatype e;
    SqQueue queue;
    InitQueue(queue);
    Start:
    printf("[INFO] ���в˵���\n");
    printf("\t=========\n");
    printf("\t1. ���\n");
    printf("\t2. ����\n");
    printf("\t3. ���в�ѯ\n");
    printf("\t4. �Ƿ����\n");
    printf("\t5. �Ƿ�ӿ�\n");
    printf("\t==========\n");
    printf("\tѡ�����ݣ�");
    scanf_s("%d", &ch);
    printf("\n");

    switch (ch) {
        case 1:
            printf("[INSERT] �������ݣ�");
            scanf_s("%d", &e);
            if (enQueue(queue,e)) printf("\t[INFO] ���в���ɹ�\n");
            else printf("\t[INFO] ���в���ʧ�ܣ�������");
            printf("\n");
            goto Start;
        case 2:
            if (deQueue(queue)) printf("[INFO] ���ӳɹ�\n");
            else printf("[INFO] ����ʧ�ܣ��ӿգ�\n");
            printf("\n");
            goto Start;
        case 3:
            selQueue(queue);
            goto Start;
        case 4:
            if (isFull(queue))
                printf("[SELECT] ����\n");
            else
                printf("[SELECT] δ��\n");
            printf("\n");
            goto Start;
        case 5:
            if (isEmpty(queue))
                printf("[SELECT] �ӿ�\n");
            else
                printf("[SELECT] δ��\n");
            printf("\n");
            goto Start;
        default: break;
    }
}
