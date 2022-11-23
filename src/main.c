#include "chess_def.h"


//**************************主函數******************************//
int main(){
    //生成棋盤
    chessboardBuilding();
    // redMove();
    for (int i = ROW*COL; i > 0 ; i --) {

        printf("%s", (char*)all_chess->top->value);
        all_chess->top = all_chess->top -> previous;
        // if (i==(9 | 18 | 27 | 36 | 45 | 54 | 63 | 72 | 81 )) printf("\n");
    }
    for (int i = 0; i < ROW ; i ++) {
        for (int j = 0; j < COL ; j ++) {
            printf("%s", (char*)all_chess->top->value);
            all_chess->top = all_chess->top -> next;
        }
        printf("\n");
    }
    // 開始下棋
    // int turn = -1;
    // while (gameOverSign) {
    //     isStandard = 1;
    //     turn *= (-1);       //雙方交替下棋
    //     switch (turn) {
    //         case 1:
    //             redMove();
    //             turn = (restart) ? (turn*-1) : turn;
    //             break;
    //         case -1:
    //             blueMove();
    //             turn = (restart) ? (turn*-1) : turn;
    //             break;
    //     }
    //     isGameOver();
        
    // }
    // printf("遊戲結束!\n");
    
}