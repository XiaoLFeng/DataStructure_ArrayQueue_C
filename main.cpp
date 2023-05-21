#include <cstdio>

#define MaxSize 100

typedef int datatype;
typedef struct {
    int rear;
    int front;
    datatype data[MaxSize];
} SqQueue;

// 初始化队列
void InitQueue(SqQueue &queue) {
    queue.rear = 0;
    queue.front = 0;
}

// 判断队列是否为空
int isEmpty(SqQueue queue) {
    if (queue.rear == queue.front) return 1;
    return 0;
}

// 判断队列是否为满
int isFull(SqQueue queue) {
    if (queue.front-1 == queue.rear) return 1;
    return 0;
}

// 入队
int enQueue(SqQueue &queue, datatype data) {
    if (queue.front-1 == queue.rear) return 0;
    queue.data[queue.rear] = data;
    if ( (queue.rear+1)%MaxSize == 0 && (queue.rear+1)%MaxSize < queue.front)
        queue.rear = (queue.rear+1)%MaxSize;
    else queue.rear++;
    return 1;
}

// 出队
int deQueue(SqQueue &queue) {
    if (queue.rear == queue.front) return 0;
    queue.data[queue.front] = NULL;
    if ((queue.front+1)%MaxSize == 0 && (queue.front+1)%MaxSize < queue.rear)
        queue.front = (queue.front+1)%MaxSize;
    else queue.front++;
    return 1;
}

// 查询队列
void selQueue(SqQueue queue) {
    printf("[SELECT] 队列列表：[ ");
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
    printf("[INFO] 队列菜单：\n");
    printf("\t=========\n");
    printf("\t1. 入队\n");
    printf("\t2. 出队\n");
    printf("\t3. 队列查询\n");
    printf("\t4. 是否队满\n");
    printf("\t5. 是否队空\n");
    printf("\t==========\n");
    printf("\t选择内容：");
    scanf_s("%d", &ch);
    printf("\n");

    switch (ch) {
        case 1:
            printf("[INSERT] 插入数据：");
            scanf_s("%d", &e);
            if (enQueue(queue,e)) printf("\t[INFO] 队列插入成功\n");
            else printf("\t[INFO] 队列插入失败（队满）");
            printf("\n");
            goto Start;
        case 2:
            if (deQueue(queue)) printf("[INFO] 出队成功\n");
            else printf("[INFO] 出队失败（队空）\n");
            printf("\n");
            goto Start;
        case 3:
            selQueue(queue);
            goto Start;
        case 4:
            if (isFull(queue))
                printf("[SELECT] 队满\n");
            else
                printf("[SELECT] 未满\n");
            printf("\n");
            goto Start;
        case 5:
            if (isEmpty(queue))
                printf("[SELECT] 队空\n");
            else
                printf("[SELECT] 未空\n");
            printf("\n");
            goto Start;
        default: break;
    }
}
