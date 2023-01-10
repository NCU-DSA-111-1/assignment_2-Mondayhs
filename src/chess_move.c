#include "chess_def.h"
#include "stack.h"

void Move_rule(void){
    printf("輸入座標(段與筋)，段與筋皆為數字(1-9)，先輸入段(行)，再輸入筋(列)，(若輸入 O，表示悔棋，可連續悔棋)。");
}

//紅棋移動
void redMove(void){
    int ot_fun = 0 ;
    move_chess = init_node();
    location = init_node();
    if (restart) {
        printf("\033[36m違反遊戲規則，請重新輸入\033[0m\n");
        restart = 0;
    }
    printf("玩家 Y : \n");
    printf("[紅棋]請輸入你要移動的棋子:\n");
    scanf("%d %d",&move_chess_R, &move_chess_C);
    move_chess = find_chess((move_chess_R-1), (move_chess_C-1));
    // printf("%s%s", (char*)move_chess->value,"\n");       //test
    if (redOrBlue(move_chess) == -1){
        printf("[紅棋]移動的棋子為:\n");
        printf("%s%s", (char*)move_chess->value,"\n");
        printf("[紅棋]請輸入你要放置的位置:\n");
        scanf("%d %d",&loc_chess_R, &loc_chess_C);
        location = find_chess((loc_chess_R-1), (loc_chess_C-1));
        printf("[紅棋]放置位置為:\n");
        printf("%s%s", (char*)location->value ,"\n");
        ot_fun = other_fun();
        if (ot_fun == 1){
            rulesOfAllKindsOfChessPieces();
            chessboardPrint();
        }
        else if (ot_fun == 2){
            redMove();
        }
        else if (ot_fun == 3){
            exit(1);
        }
    }
    else{ 
        printf("\033[36m您選錯旗子了！ 請重新輸入。\033[0m \n");
        redMove();
    }
}

//藍棋移動
void blueMove(void){
    int ot_fun=0;
    move_chess = init_node();
    location = init_node();
    if (restart) {
        printf("違反遊戲規則，請重新輸入\n");
        restart = 0;
    }
    printf("玩家 X : \n");
    printf("[藍棋]請輸入你要移動的棋子:\n");
    scanf("%d %d",&move_chess_R,&move_chess_C);
    move_chess = find_chess(move_chess_R-1, move_chess_C-1);
    // printf("%s%s", (char*)move_chess->value,"\n");
    if (redOrBlue(move_chess) == 1){
        printf("[藍棋]移動的棋子為:\n");
        printf("%s%s", (char*)move_chess->value,"\n");
        printf("[藍棋]請輸入你要放置的位置:\n");
        scanf("%d %d",&loc_chess_R,&loc_chess_C);
        location = find_chess((loc_chess_R-1), (loc_chess_C-1));
        printf("[藍棋]放置位置為:\n");
        printf("%s%s", (char*)location->value ,"\n");
        ot_fun = other_fun();
        if (ot_fun == 1){
            rulesOfAllKindsOfChessPieces();
            chessboardPrint();
        }
        else if (ot_fun == 2){
            blueMove();
        }
        else if (ot_fun == 3){
            exit(1);
        }
    }
    else{
        printf("\033[36m您選錯旗子了！ 請重新輸入。\033[0m \n");
        blueMove();
    }
}

Node_t *find_chess(int Row_chess,int Col_chess){
    chessPointer_Init();
    Node_t* stk = (Node_t*)malloc(sizeof(Node_t));
    stk = NULL;
    stk = all_chess->top;
    int stop_pt = (Row_chess)*9+(Col_chess);
    for (int i = 0; i < stop_pt ; i ++) {
        stk = stk -> next;
    }
    if (Row_chess== -1 || Col_chess== -1 ){
        stk->value = "Nothing";
    }
    return stk;
}

void find_location(int Row_chess,int Col_chess){
    chessPointer_Init();
    int stop_pt = (Row_chess)*9+(Col_chess);
    for (int i = 0; i < stop_pt ; i ++) {
        all_chess->top = all_chess->top -> next;
    }
}

int other_fun(void){
    char fun_t;
    int ret=0;
    printf("\033[36m-------------------您需要以下的服務嗎？--------------------------\033[0m\n");
    printf(" NOTE-0: 沒有任何問題？ 按下「y」or 「Y」：\n");
    printf(" NOTE-1: 是否確定放置為以上？ 若想悔棋請按下「O」：\n");
    printf(" NOTE-2: 是否想要休息一下稍等玩？ 若想存檔請按下「s」：\n");

    scanf("%s",&fun_t);
    if (fun_t == ('y' | 'Y')){
        ret = 1;
    }
    else if (fun_t == ( 'O' | 'o' | '0' )){
        printf("\033[35m你悔棋請重新輸入！\033[0m\n");
        ret = 2;
    }
    else if (fun_t == ('s' | 'S')){
        printf("\033[35m下次見！\033[0m\n");
        write_chessboard();
        ret = 3;
    }
    
    return ret;
}

int read_last(void){
    char fun_t;
    int ret=0;
    printf("------------------- \033[36m您是要玩上一場遊戲嗎 ？\033[0m--------------------------\n");
    printf(" 要 請按下「r」or 「R」： \n");
    printf(" 不要，我要開新的一局 請打「n」： \n");
    scanf("%s",&fun_t);
    if (fun_t == ('r' | 'R')){
        printf(" \033[35m又見面了！\033[0m \n");
        ret = 0;
    }
    else if (fun_t == ('n' | 'N')){
        printf(" \033[35m 讓我們玩下去吧！\033[0m \n");
        ret = 1;
    }
    return ret;
}