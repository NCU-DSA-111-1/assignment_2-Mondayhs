#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#define B(piece) "\033[34m"#piece"\033[0m"//藍色棋子
#define R(piece) "\033[31m"#piece"\033[0m"//紅色棋子

#define CROSS "\033[33m十\033[0m"

#define ROW  9
#define COL  9
#define TOLTAL 20




//定義外部變量,棋盤坐標
char* array[ROW][COL];
char* red_get[TOLTAL];
char* blue_get[TOLTAL];




int move_chess_R,move_chess_C;  //要移動的棋子
int loc_chess_R,loc_chess_C;    //移動的目標位置
int Rm,Cm;
int Rp,Cp;

int r_i=0;
int b_i=0;

bool isStandard = 1;//是否符合規則，初始值1，符合
bool restart = 0;
bool gameOverSign = 1;//遊戲是否結束，0結束



// 生成棋盤
void chessboardBuilding()
{
    for (int i = 0; i < ROW; i ++) {
        for (int j = 0; j < COL ; j ++) {
            array[i][j] = CROSS;
        }
        printf("\n");
    }

    for (int i = 0; i < TOLTAL; i ++) {
        red_get[i] = CROSS;
        blue_get[i] = CROSS;
    }

    //布置藍棋
    array[0][0] = array[0][ROW-1] = R(香);
    array[0][1] = array[0][ROW-2] = R(桂);
    array[0][2] = array[0][ROW-3] = R(銀);
    array[0][3] = array[0][ROW-4] = R(金);
    array[0][4] = R(王);
    array[1][1] = R(飛);
    array[1][7] = R(角);
    for (int j = 0; j < COL ; j ++) 
    {
        array[2][j] = R(步);
    }
    
    
    //布置紅棋
    array[8][0] = array[8][ROW-1] = B(香);
    array[8][1] = array[8][ROW-2] = B(桂);
    array[8][2] = array[8][ROW-3] = B(銀);
    array[8][3] = array[8][ROW-4] = B(金);
    array[8][4] = B(王);
    array[7][1] = B(角);
    array[7][7] = B(飛);
    for (int j = 0; j < COL ; j ++) 
    {
        array[6][j] = B(步);
    }
    
}






//打印棋盤
void printChessboard()
{
	system("clear");
    
    //顯示
    printf("  \033[43;30m 將旗 \033[0m\n\n");
    for (int i = 0; i < ROW;  i ++) {
        for (int j = 0; j < COL; j ++) {
            printf("%s",array[i][j]);
        }
        printf("\n");
    }

}