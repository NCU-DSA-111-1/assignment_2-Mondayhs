#include "chess_def.h"

/*-----------------Red Chess-------------------*/
const char R_soldier[] = R(步);
const char R_car[] = R(香);
const char R_hours[] = R(桂);
const char R_sliver[] = R(銀);
const char R_corner[] = R(角);
const char R_fly[] = R(飛);
const char R_gold[] = R(金);
const char R_king[] = R(王);
/*-----------------Blue Chess-------------------*/
const char B_soldier[] = B(步);
const char B_car[] = B(香);
const char B_hours[] = B(桂);
const char B_sliver[] = B(銀);
const char B_corner[] = B(角);
const char B_fly[] = B(飛);
const char B_gold[] = B(金);
const char B_king[] = B(王);

/*-----------------Move Chess-------------------*/
int move_chess_R,move_chess_C;  //要移動的棋子
int loc_chess_R,loc_chess_C;    //移動的目標位置
int Rm,Cm;
int Rp,Cp;

int r_i=0;
int b_i=0;

/*-----------------Rule-------------------*/
bool isStandard = 1;//是否符合規則，初始值1，符合
bool restart = 0;
bool gameOverSign = 1;//遊戲是否結束，0結束


// system("clear");

// Red_get = init_stack();
// blue_get = init_stack();


// #define CHAR_ALL  ((CHAR*)all_chess->top->value)
// #define CHAR_RED  ((CHAR*)red_get->top->value)
// #define CHAR_BLUE  ((CHAR*)blue_get->top->value)


/*-----------------------------Stack funtion------------------------------*/
Stack_t *init_stack(){
    Stack_t* stk = (Stack_t*)malloc(sizeof(Stack_t)); 
    stk->top = NULL;
    return stk;
}

Node_t *init_node(){
    Node_t* stk = (Node_t*)malloc(sizeof(Node_t)); 
    stk = NULL;
    return stk;
}

void push(Stack_t *const stk, void* src){
    Node_t *node = (Node_t *)malloc(sizeof(Node_t));
    node->value = src;
    node->previous = NULL;

    if(stk->top) {
        stk->top->next = node;
        node->previous = stk->top;
    }
    stk->top = node;

    return;
}


int is_empty(Stack_t *const stk){
    return !stk->top;
}


void pop(Stack_t *const stk, void *des, long size){
    if(is_empty(stk)){
        printf("Stack is empty!\n");
        return;
    }

    Node_t *temp =  stk->top;
    stk->top = temp->previous;
    memcpy(des, temp->value, size);
    free(temp);
    return;
}


/*-----------------------------Chess funtion------------------------------*/

//打印棋盤
void chessboardBuilding()
{
    // 顯示
    printf("  \033[43;30m 將旗 \033[0m\n\n");
    all_chess = init_stack();
    for (int i = 0; i < ROW; i ++) {
        for (int j = 0; j < COL ; j ++) {
        
        /*----------------SET Red Chess-------------------*/
            if ((i==0) && (j==0 || j==8)){
                push(all_chess, (void*) &R_car);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==0) && (j==1 || j==7)){
                push(all_chess, (void*) &R_hours);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==0) && (j==2 || j==6)){
                push(all_chess, (void*) &R_sliver);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==0) && (j==3 || j==5)){
                push(all_chess, (void*) &R_gold);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==0) && (j==4)){
                push(all_chess, (void*) &R_king);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==1) && (j==1)){
                push(all_chess, (void*) &R_fly);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==1) && (j==7)){
                push(all_chess, (void*) &R_corner);
                printf("%s", (char*)all_chess->top->value);
            }
            else if (i==2){
                push(all_chess, (void*) &R_soldier);
                printf("%s", (char*)all_chess->top->value);
            }
        /*----------------SET Blue Chess-------------------*/
            else if ((i==8) && (j==0 || j==8)){
                push(all_chess, (void*) &B_car);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==8) && (j==1 || j==7)){
                push(all_chess, (void*) &B_hours);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==8) && (j==2 || j==6)){
                push(all_chess, (void*) &B_sliver);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==8) && (j==3 || j==5)){
                push(all_chess, (void*) &B_gold);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==8) && (j==4)){
                push(all_chess, (void*) &B_king);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==7) && (j==7)){
                push(all_chess, (void*) &B_fly);
                printf("%s", (char*)all_chess->top->value);
            }
            else if ((i==7) && (j==1)){
                push(all_chess, (void*) &B_corner);
                printf("%s", (char*)all_chess->top->value);
            }
            else if (i==6){
                push(all_chess, (void*) &B_soldier);
                printf("%s", (char*)all_chess->top->value);
            }
        /*----------------SET other where -------------------*/    
            else {
                push(all_chess, (void*) &CROSS);
                printf("%s", (char*)all_chess->top->value);
            }
        }
        printf("\n");
    }


    
}



//紅棋移動
void redMove(){
    move_chess = init_node();
    location = init_node();
    if (restart) {
        printf("違反遊戲規則，請重新輸入\n");
        restart = 0;
    }
    printf("[紅棋]請輸入你要移動的棋子:\n");
    scanf("%d %d",&move_chess_R, &move_chess_C);
    move_chess = find_chess((move_chess_R-1), (move_chess_C-1));
    printf("%s", (char*)move_chess->value);
    
    printf("[紅棋]請輸入你要放置的位置:\n");
    scanf("%d %d",&loc_chess_R, &loc_chess_C);
    location = find_chess((loc_chess_R), (loc_chess_C));
    
    rulesOfAllKindsOfChessPieces(move_chess, location);
    
}

// //藍棋移動
// void blueMove(){
//     if (restart) {
//         printf("違反遊戲規則，請重新輸入\n");
//         restart = 0;
//     }
//     printf("[藍棋]請輸入你要移動的棋子:\n");
//     scanf("%d %d",&move_chess_R,&move_chess_C);
//     // move_chess = find_chess(move_chess_R-1, move_chess_C-1);

//     printf("[藍棋]請輸入你要放置的位置:\n");
//     scanf("%d %d",&loc_chess_R,&loc_chess_C);
//     // printf("%s",array[loc_chess_R-1][loc_chess_C-1]);
//     // rulesOfAllKindsOfChessPieces();
    
// }

Node_t *find_chess(int Row_chess,int Col_chess){
    Node_t* stk = (Node_t*)malloc(sizeof(Node_t)); 
    stk = NULL;
    stk = all_chess->top;
    int stop_pt = (Row_chess+1)*8+(Col_chess+1);
    for (int i = ROW*COL; i > stop_pt ; i --) {
        stk = stk -> previous;
    }
    return stk;
}



// 判斷是紅棋還是藍棋,紅旗返回-1,藍棋返回1,否則返回0
int redOrBlue(Node_t *loc_ch){
    if (loc_ch->value == &R_soldier || loc_ch->value == &R_car || loc_ch->value == &R_hours || loc_ch->value == &R_sliver || loc_ch->value == &R_corner || loc_ch->value == &R_fly || loc_ch->value == &R_gold || loc_ch->value == &R_king){
        return  - 1;
    }
    else if (loc_ch->value == &B_soldier || loc_ch->value == &B_car || loc_ch->value == &B_hours || loc_ch->value == &B_sliver || loc_ch->value == &B_corner || loc_ch->value == &B_fly || loc_ch->value == &B_gold || loc_ch->value == &B_king){
        return 1;
    }
    else
        return 0;
    
}



void swap( Node_t **address_a , Node_t **address_b ){
    Node_t *temp = *(address_a);
    *address_a = *(address_b);
    *address_b = temp;
}

void Get_chess( Node_t *mov_ch, Node_t *loc_ch )//int mov_row, int mov_col, int loc_row, int loc_col)
{   
    if(redOrBlue(loc_ch) == 1)
    {
        swap( &mov_ch, &loc_ch);
        // swap(&array[Rm][Cm], &red_get[r_i]);
        r_i++;
    }
    else if(redOrBlue(loc_ch) == -1)
    {
        swap( &mov_ch, &loc_ch);
        // swap(&array[Rm][Cm], &blue_get[b_i]);
        b_i++;
    }
    else
    {
        swap( &mov_ch, &loc_ch);
    }
    printf("%s", (char*)mov_ch->value);
}


void rulesOfAllKindsOfChessPieces( Node_t *mov_ch, Node_t *loc_ch )
{
    Rm = move_chess_R -1;
    Cm = move_chess_C -1;
    Rp = loc_chess_R -1;
    Cp = loc_chess_C -1;
/*------------------red 步--------------------*/
    if ( mov_ch -> value == R_soldier )
    {
        if ( (Rm > Rp ) || ( Cm != Cp))
            isStandard=0;                   // 如果倒退或左右，則不符合規範
        if (  Rp != Rm+1 )
            isStandard=0;                   // 只能前進一步

        if ( (Cm == Cp) && (isStandard == 1) && (redOrBlue(loc_ch) != -1) )    //如果棋子直行、沒有犯規且落點不是紅棋，可以移動
        {
            Get_chess(mov_ch, loc_ch);
        }

        else
        {
            restart = 1;
        }
    }    
    
    
    
}


//判斷遊戲結束
// void isGameOver(){
//     bool sign_r = 0;
//     bool sign_b = 0;
//     for (int i = 0; i < ROW; i ++) {
//         for (int j = 0; j < COL; j ++) {
//             if (array[i][j] == R(王)) {
//                 sign_r = 1;
//             }
//             else if (array[i][j] == B(王))
//             {
//                 sign_b = 1;
//             }
//         }
//     }
//     if ((sign_r == 0)||(sign_b == 0)) {
//         gameOverSign = 0;
//     }
// }

