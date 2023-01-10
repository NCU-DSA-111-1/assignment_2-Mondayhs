#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stdbool.h>

/*-----------------Stack-------------------*/

typedef struct Node{
    void *value;
    struct Node *previous;
    struct Node *next;
}Node_t;

typedef struct Stack{
    Node_t *top;
    //
}Stack_t;

Stack_t *all_chess;
Stack_t *Red_get;
Stack_t *blue_get;


Node_t *move_chess;
Node_t *location;

Stack_t *init_stack();
Node_t *init_node();
int is_empty(Stack_t *const stk);
void push(Stack_t *const , void* );
void pop(Stack_t *const stk, void *des, long size);

/**---------------Chess move----------------**/
Node_t *find_chess(int Row_chess,int Col_chess);
/**----------Chess board & rules------------**/
int redOrBlue(Node_t *loc_ch);

#endif