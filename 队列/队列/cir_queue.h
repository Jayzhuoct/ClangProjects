#ifndef CIR_QUEUE_H_INCLUDED
#define CIR_QUEUE_H_INCLUDED
#define true 1
#define false 0
#define MAX_QUEUE_SIZE 6
typedef int datatype;
typedef struct queue
{
    datatype sp_queue_array[MAX_QUEUE_SIZE];
    int front;
    int rear;
}cir_queue;

cir_queue queue_init();
int queue_empty(cir_queue q);
int queue_en(cir_queue *q, datatype e);
int queue_de(cir_queue *q, datatype *e);
void queue_clear(cir_queue *q);
int get_front(cir_queue, datatype *e );
int queue_len(cir_queue q);
void queue_traverse(cir_queue q, void(*visit)(cir_queue q));
void visit(cir_queue s);

#endif // CIR_QUEUE_H_INCLUDED
