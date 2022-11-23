#ifndef CHESS_DEF_H
#define CHESS_DEF_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stdbool.h>


#define ROW  9
#define COL  9
#define TOLTAL 20
#define B(piece) "\033[34m"#piece"\033[0m"//藍色棋子
#define R(piece) "\033[31m"#piece"\033[0m"//紅色棋子
#define CROSS "\033[33m十\033[0m"




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

/*-----------------Chess funtion-------------------*/

void chessboardBuilding(void);
void redMove(void);
void blueMove(void);
Node_t *find_chess(int Row_chess,int Col_chess);
int redOrBlue(Node_t *loc_ch);
void Get_chess( Node_t *mov_ch, Node_t *loc_ch );
void rulesOfAllKindsOfChessPieces( Node_t *mov_ch, Node_t *loc_ch );

#endif 


// void Get_chess( )//int mov_row, int mov_col, int loc_row, int loc_col)
// {   
//     if(redOrBlue(loc_row, loc_col) == 1)
//     {
//         swap( &(array[Rp][Cp]) , &(array[Rm][Cm]));
        

//         char pop_data;
//         pop(array[Rp][Cp], (void*) &pop_data, sizeof(char));
//         push(Red_get, (void*) &pop_data);

//     }
//     else if(redOrBlue(loc_row, loc_col) == -1)
//     {
        
        
//     }
//     else
//     {
//         swap( &(array[Rp][Cp]) , &(array[Rm][Cm]));
//         //swap( &array[mov_row][mov_col] , &array[loc_row][loc_col]);
//     }
// }