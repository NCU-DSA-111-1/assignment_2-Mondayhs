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

static char chess_all[ROW*COL][20];

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

/*-----------------Move Chess-------------------*/
int move_chess_R,move_chess_C;  //要移動的棋子
int loc_chess_R,loc_chess_C;    //移動的目標位置
int Rm,Cm;
int Rp,Cp;

int r_i;
int b_i;

/*-----------------Rule-------------------*/
bool isStandard ;//是否符合規則，初始值1，符合
bool restart ;
bool gameOverSign ;//遊戲是否結束，0結束



/*++++++++++++++++++++++"Chess funtion"++++++++++++++++++++++++*/
/**----------Chess board & rules------------**/
void chessboardBuilding(void);
void chessPointer_Init(void);
void chessboardPrint(void);
int redOrBlue(Node_t *loc_ch);
void Get_chess(void);
void rulesOfAllKindsOfChessPieces(void);
void isGameOver(void);

/**---------------Chess move----------------**/
void redMove(void);
void blueMove(void);
Node_t *find_chess(int Row_chess,int Col_chess);
void find_location(int Row_chess,int Col_chess);

// 悔棋功能
int other_fun(void);
// 玩上一局功能
int read_last(void);
/*----------------"Chessboard Read and write "-------------------*/
// char chess_t
;
void write_chessboard(void);
void Read_chessboard(void);
void identify_chess(char  *chess_t);



#endif 

