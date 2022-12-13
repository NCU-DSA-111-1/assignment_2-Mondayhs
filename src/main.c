#include "chess_def.h"



//**************************主函數******************************//
int main(){
    //生成棋盤
    chessboardBuilding();
    chessboardPrint();
    //開始下棋
    int turn = -1;
    while (gameOverSign) {
        isStandard = 1;
        turn *= (-1);       //雙方交替下棋
        switch (turn) {
            case -1:
                redMove();
                // blueMove();
                turn = (restart) ? (turn*-1) : turn;
                break;
            case 1:
                blueMove();
                // redMove();
                turn = (restart) ? (turn*-1) : turn;
                break;
        }
        isGameOver();
        
    }
    printf("遊戲結束!\n");
    
}