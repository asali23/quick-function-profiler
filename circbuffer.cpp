#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct circular_buffer
{
    void *buffer;     // data buffer
    void *buffer_end; // end of data buffer
    size_t capacity;  // maximum number of items in the buffer
    size_t count;     // number of items in the buffer
    size_t sz;        // size of each item in the buffer
    void *head;       // pointer to head
    void *tail;       // pointer to tail
} circular_buffer;
static circular_buffer circ_buff;
void cb_init(size_t capacity)
{
	size_t sz = 4;
	circular_buffer *cb = &circ_buff;
    cb->buffer = malloc(capacity * sz);
    if(cb->buffer == NULL)
	{
        // handle error
	}
    cb->buffer_end = (char *)cb->buffer + capacity * sz;
    cb->capacity = capacity;
    cb->count = 0;
    cb->sz = sz;
    cb->head = cb->buffer;
    cb->tail = cb->buffer;
}

void cb_free()
{
	circular_buffer *cb = &circ_buff;
    free(cb->buffer);
    // clear out other fields too, just to be safe
}

int cb_push_back(int item)
{
	circular_buffer *cb = &circ_buff;
    if(cb->count == cb->capacity)
	{
		printf("Debug Buffer Full\n");
        return -1;
	}
    std::memcpy(cb->head, &item, cb->sz);
    cb->head = (char*)cb->head + cb->sz;
    if(cb->head == cb->buffer_end)
        cb->head = cb->buffer;
    cb->count++;
	return 0;
}

int cb_pop_front(int *item)
{
	circular_buffer *cb = &circ_buff;
    if(cb->count == 0)
	{
		return -1;
	}
    memcpy(item, cb->tail, cb->sz);
    cb->tail = (char*)cb->tail + cb->sz;
    if(cb->tail == cb->buffer_end)
        cb->tail = cb->buffer;
    cb->count--;
	return 0;
}



void mainzzzz(void)
{
	int value=100;
	cb_init(100);
	cb_push_back(value);
	value=0;
	cb_pop_front(&value);
	printf("%d\n",value);

}