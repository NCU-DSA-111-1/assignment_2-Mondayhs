#include "chess_move.h"





//判斷遊戲結束
void isGameOver(){
    bool sign_r = 0;
    bool sign_b = 0;
    for (int i = 0; i < ROW; i ++) {
        for (int j = 0; j < COL; j ++) {
            if (array[i][j] == R(王)) {
                sign_r = 1;
            }
            else if (array[i][j] == B(王))
            {
                sign_b = 1;
            }
        }
    }
    if ((sign_r == 0)||(sign_b == 0)) {
        gameOverSign = 0;
    }
}


//**************************主函數******************************//

int main(){
    //生成棋盤
    chessboardBuilding();
    //打印棋盤
    printChessboard();
    //開始下棋
    int turn = -1;
    while (gameOverSign) {
        isStandard = 1;
        turn *= (-1);       //雙方交替下棋
        switch (turn) {
            case 1:
                redMove();
                turn = (restart) ? (turn*-1) : turn;
                break;
            case -1:
                blueMove();
                turn = (restart) ? (turn*-1) : turn;
                break;
        }
        isGameOver();
        
    }
    printf("遊戲結束!\n");
    
}







