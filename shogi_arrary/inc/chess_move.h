#include "piece_rule.h"





//紅棋移動
void redMove(){
    if (restart) {
        printf("違反遊戲規則，請重新輸入\n");
        restart = 0;
    }
    printf("[紅棋]請輸入你要移動的棋子:\n");
    scanf("%d %d",&move_chess_R,&move_chess_C);
    printf("%s",array[move_chess_R-1][move_chess_C-1]);
    printf("[紅棋]請輸入你要放置的位置:\n");
    scanf("%d %d",&loc_chess_R,&loc_chess_C);
    printf("%s",array[loc_chess_R][loc_chess_C]);
    
    rulesOfAllKindsOfChessPieces();
    printChessboard();
}

//藍棋移動
void blueMove(){
    if (restart) {
        printf("違反遊戲規則，請重新輸入\n");
        restart = 0;
    }
    printf("[藍棋]請輸入你要移動的棋子:\n");
    scanf("%d %d",&move_chess_R,&move_chess_C);
    printf("%s",array[move_chess_R-1][move_chess_C-1]);
    printf("[藍棋]請輸入你要放置的位置:\n");
    scanf("%d %d",&loc_chess_R,&loc_chess_C);
    printf("%s",array[loc_chess_R-1][loc_chess_C-1]);
    rulesOfAllKindsOfChessPieces();
    printChessboard();
}



