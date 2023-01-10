#include "stack.h"
#include "chess_def.h"


/*-----------------Red Chess-------------------*/
static const char R_soldier[] = R(步);
static const char R_car[] = R(香);
static const char R_hours[] = R(桂);
static const char R_sliver[] = R(銀);
static const char R_corner[] = R(角);
static const char R_fly[] = R(飛);
static const char R_gold[] = R(金);
static const char R_king[] = R(王);
/*-----------------Blue Chess-------------------*/
static const char B_soldier[] = B(步);
static const char B_car[] = B(香);
static const char B_hours[] = B(桂);
static const char B_sliver[] = B(銀);
static const char B_corner[] = B(角);
static const char B_fly[] = B(飛);
static const char B_gold[] = B(金);
static const char B_king[] = B(王);



/*-----------------Rule-------------------*/
bool isStandard = 1;//是否符合規則，初始值1，符合
bool restart = 0;
bool gameOverSign = 1;//遊戲是否結束，0結束

int r_i = 0;
int b_i = 0;




// system("clear");

// Red_get = init_stack();
// blue_get = init_stack();



// /*-----------------------------Stack funtion------------------------------*/
// Stack_t *init_stack(){
//     Stack_t* stk = (Stack_t*)malloc(sizeof(Stack_t)); 
//     stk->top = NULL;
//     return stk;
// }

// Node_t *init_node(){
//     Node_t* stk = (Node_t*)malloc(sizeof(Node_t)); 
//     stk = NULL;
//     return stk;
// }

// void push(Stack_t *const stk, void* src){
//     Node_t *node = (Node_t *)malloc(sizeof(Node_t));
//     node->value = src;
//     node->previous = NULL;

//     if(stk->top) {
//         stk->top->next = node;
//         node->previous = stk->top;
//     }
//     stk->top = node;

//     return;
// }


// int is_empty(Stack_t *const stk){
//     return !stk->top;
// }


// void pop(Stack_t *const stk, void *des, long size){
//     if(is_empty(stk)){
//         printf("Stack is empty!\n");
//         return;
//     }

//     Node_t *temp =  stk->top;
//     stk->top = temp->previous;
//     memcpy(des, temp->value, size);
//     free(temp);
//     return;
// }


/*-----------------------------Chess funtion------------------------------*/

//生成棋盤
void chessboardBuilding(void)
{
    // 顯示
    all_chess = init_stack();
    for (int i = 0; i < ROW; i ++) {
        for (int j = 0; j < COL ; j ++) {
        /*----------------SET Red Chess-------------------*/
            if ((i==0) && (j==0 || j==8)){
                push(all_chess, (void*) &R_car);
            }
            else if ((i==0) && (j==1 || j==7)){
                push(all_chess, (void*) &R_hours);
            }
            else if ((i==0) && (j==2 || j==6)){
                push(all_chess, (void*) &R_sliver);
            }
            else if ((i==0) && (j==3 || j==5)){
                push(all_chess, (void*) &R_gold);
            }
            else if ((i==0) && (j==4)){
                push(all_chess, (void*) &R_king);
            }
            else if ((i==1) && (j==1)){
                push(all_chess, (void*) &R_fly);
            }
            else if ((i==1) && (j==7)){
                push(all_chess, (void*) &R_corner);
            }
            else if (i==2){
                push(all_chess, (void*) &R_soldier);
            }
        /*----------------SET Blue Chess-------------------*/
            else if ((i==8) && (j==0 || j==8)){
                push(all_chess, (void*) &B_car);
            }
            else if ((i==8) && (j==1 || j==7)){
                push(all_chess, (void*) &B_hours);
            }
            else if ((i==8) && (j==2 || j==6)){
                push(all_chess, (void*) &B_sliver);
            }
            else if ((i==8) && (j==3 || j==5)){
                push(all_chess, (void*) &B_gold);
            }
            else if ((i==8) && (j==4)){
                push(all_chess, (void*) &B_king);
            }
            else if ((i==7) && (j==7)){
                push(all_chess, (void*) &B_fly);
            }
            else if ((i==7) && (j==1)){
                push(all_chess, (void*) &B_corner);
            }
            else if (i==6){
                push(all_chess, (void*) &B_soldier);
                
            }
        /*----------------SET other where -------------------*/    
            else {
                push(all_chess, (void*) &CROSS);
            }
        }
    }
    push(all_chess, NULL); 
}

void chessPointer_Init(void)
{
    while (all_chess->top->previous != NULL)
    {
        all_chess->top = all_chess->top -> previous;
    }
}

// void chessboardPrint(void)
// {
//     printf("  \033[43;30m 將旗 \033[0m\n\n");
//     chessPointer_Init();
//     for (int i = 0; i < ROW+1 ; i ++) {
//         for (int j = 0; j < COL+1 ; j ++){
//             if ( (i==9 && j==0) || (i==0 && j==9) )
//                 printf("1");
//             else if ((i==9 && j==1) || (i==1 && j==9))
//                 printf("2");
//             else if ((i==9 && j==2) || (i==2 && j==9))
//                 printf("3");
//             else if ((i==9 && j==3) || (i==3 && j==9))
//                 printf("4");
//             else if ((i==9 && j==4) || (i==4 && j==9))
//                 printf("5");
//             else if ((i==9 && j==5) || (i==5 && j==9))
//                 printf("6");
//             else if ((i==9 && j==6) || (i==6 && j==9))
//                 printf("7");
//             else if ((i==9 && j==7) || (i==7 && j==9))
//                 printf("8");
//             else if ((i==9 && j==8) || (i==8 && j==9))
//                 printf("9");
//             else if (i==9 && j==9)
//                 printf("段/筋");
//             else
//                 printf("%s", (char*)all_chess->top->value);
//                 all_chess->top = all_chess->top -> next;
//         }
//         printf("\n");
//     }
// }

void chessboardPrint(void)
{
    printf("  \033[43;30m 將旗 \033[0m\n\n");
    chessPointer_Init();
    for (int i = 0; i < ROW ; i ++) {
        for (int j = 0; j < COL ; j ++) {
            printf("%s", (char*)all_chess->top->value);
            all_chess->top = all_chess->top -> next;
        }
        printf("\n");
    }
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
void Get_chess(){   
    if(redOrBlue(location) == 1)
    {
        find_location(Rp,Cp);
        all_chess->top->value= move_chess->value;
        find_location(Rm,Cm);
        all_chess->top->value= CROSS;
        r_i++;
    }
    else if(redOrBlue(location) == -1)
    {
        find_location(Rp,Cp);
        all_chess->top->value= move_chess->value;
        find_location(Rm,Cm);
        all_chess->top->value= CROSS;
        b_i++;
    }
    else
    {
        find_location(Rp,Cp);
        all_chess->top->value= move_chess->value;
        find_location(Rm,Cm);
        all_chess->top->value= CROSS;
        
    }
}


void rulesOfAllKindsOfChessPieces()// Node_t *mov_ch, Node_t *loc_ch )
{
    Rm = move_chess_R -1;
    Cm = move_chess_C -1;
    Rp = loc_chess_R -1;
    Cp = loc_chess_C -1;   
/*------------------red 步--------------------*/
    if ( move_chess -> value == R_soldier )
    {
        if ( (Rm > Rp ) || ( Cm != Cp))
            isStandard=0;                   // 如果倒退或左右，則不符合規範
        if (  Rp != Rm+1 )
            isStandard=0;                   // 只能前進一步
        if ( (Cm == Cp) && (isStandard == 1) && (redOrBlue(location) != -1) )    //如果棋子直行、沒有犯規且落點不是紅棋，可以移動
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }    
/*------------------blue 步--------------------*/
    else if ( move_chess -> value == B_soldier )
    {
        if ( (Rm < Rp ) || ( Cm != Cp ) )
            isStandard=0;                   // 如果倒退或左右，則不符合規範
        if ( Rp != Rm-1 )
            isStandard=0;                   // 只能前進一步
        if ( Cm == Cp && isStandard && redOrBlue(location) != 1)//
        {
            Get_chess();
        }

        else
        {
            restart = 1;
        }
    }    
/*------------------red 香--------------------*/
    else if ( move_chess -> value == R_car )
    {
        if ( (Rm > Rp ) || ( Cm != Cp ) )
            isStandard=0;                   // 如果倒退，則不符合規範
        for (int i = Rm+1; i < Rp; i ++)    // 中間不可有其子
        {
            find_chess(i,Cp);
            if (redOrBlue(all_chess->top) != 0)
                isStandard = 0;
        }
        if ( (Cm == Cp) && (isStandard == 1) && redOrBlue(location) != -1 )
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }
/*------------------blue 香--------------------*/
    else if ( move_chess -> value == B_car )
    {
        if ( (Rm < Rp ) || ( Cm != Cp ) )
            isStandard=0;                   // 如果倒退或左右，則不符合規範
        for (int i = Rm-1; i > Rp; i --)    // 中間不可有其子
        {
            find_chess(i,Cp);
            if (redOrBlue(all_chess->top) != 0)
                isStandard = 0;
        }
        if ( (Cm == Cp) && (isStandard == 1) && redOrBlue(location) != 1) 
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }    
/*------------------red 桂--------------------*/
    else if ( move_chess -> value == R_hours )
    {
        if ( Rm > Rp )
            isStandard=0;                   // 如果倒退，則不符合規範
        // if (location->value != CROSS)
        //     isStandard = 0;
        if ( (Cp == Cm+1 || Cp == Cm-1) && (Rp == Rm+2) && (isStandard == 1) && (redOrBlue(location) != -1) )
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }
/*------------------blue 桂--------------------*/
    else if ( move_chess -> value == B_hours )
    {
        if ( Rm < Rp )
            isStandard=0;                   // 如果倒退，則不符合規範
        // if (location->value != CROSS)
        //     // if ( redOrBlue(location) == -1 )
        //     isStandard = 0;
        
        if ( (Cp == Cm+1 || Cp == Cm-1) && (Rp == Rm-2) && (isStandard == 1) && (redOrBlue(location) != 1)) 
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }    
/*------------------red 銀--------------------*/
    else if ( move_chess -> value == R_sliver )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;                                               // 不能超出兩格
        if((Rp==Rm-1 && Cp==Cm) || (Rp==Rm && (Cp==Cm+1 || Cp==Cm-1)) || (isStandard == 0) || redOrBlue(location) == -1)      //(Cp == Cm+1 || Cp == Cm-1) && (Rp == Rm+1 || Rp == Rm+1) && 
        {
            restart = 1;
        }
        else 
        {
            Get_chess();
        }

    }

/*------------------blue 銀--------------------*/
    else if ( move_chess -> value == B_sliver )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;
        if ((Rp==Rm+1 && Cp==Cm) || (Rp==Rm && (Cp==Cm+1 || Cp==Cm-1)) || (isStandard == 0) || redOrBlue(location) == 1)
        {
            restart = 1;
        }
        else 
        {   
            Get_chess();
            
        }
    }

/*------------------red 金--------------------*/
    else if ( move_chess -> value == R_gold )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;
        if ((Rp==Rm-1 && (Cp==Cm-1 || Cp==Cm+1)) || (isStandard == 0) || redOrBlue(location) == -1)      
        {
            restart = 1;
        }
        else 
        {
            Get_chess();
        }

    }

/*------------------blue 金--------------------*/
    else if ( move_chess -> value == B_gold )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;
        if ((Rp==Rm+1 && (Cp==Cm-1 || Cp==Cm+1)) || (isStandard == 0) || redOrBlue(location) == 1)        
        {
            restart = 1;
        }
        else
        {
            Get_chess();
        }
    }
/*------------------red 王--------------------*/
    else if ( move_chess -> value == R_king )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;
        if ((isStandard == 0) || redOrBlue(location) == -1)       
        {
            restart = 1;
        }
        else 
        {
            Get_chess();
        }
    }
/*------------------blue 王--------------------*/
    else if ( move_chess -> value == B_king )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;
        if ((isStandard == 0) || redOrBlue(location) == -1)        
        {
            restart = 1;
        }
        else 
        {
            Get_chess();
        }
    }
}

// 判斷遊戲結束
void isGameOver(void){
    bool sign_r = 0;
    bool sign_b = 0;
    chessPointer_Init();
    for (int i = 0; i < ROW*COL; i ++) {
        if ( all_chess->top -> value == R_king ) {
            sign_r = 1;
        }
        else if ( all_chess->top -> value == B_king ) {
            sign_b = 1;
        }
        all_chess->top = all_chess->top->next;
    }
    if ((sign_r == 0)||(sign_b == 0)) {
        gameOverSign = 0;
    }
}

