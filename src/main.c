#include "chess_def.h"




//**************************主函數******************************//
int main(){
    // Read_chessboard();
    
    //生成棋盤
    int read_fun = 0 ;
    read_fun = read_last();
    if (read_fun == 0){
        Read_chessboard();
    }
    else if (read_fun == 1){
        chessboardBuilding();
        
    }
    chessboardPrint();
    //開始下棋
    int turn = -1;
    while (gameOverSign) {
        isStandard = 1;
        turn *= (1);       //雙方交替下棋
        switch (turn) {
            case 1:
                // redMove();
                blueMove();
                turn = (restart) ? (turn*-1) : turn;
                break;
            case -1:
                // blueMove();
                redMove();
                turn = (restart) ? (turn*-1) : turn;
                break;
        }
        isGameOver();
        
    }
    printf("遊戲結束!\n");
    
}