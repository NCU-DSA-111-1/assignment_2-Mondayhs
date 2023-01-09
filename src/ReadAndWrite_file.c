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



void write_chessboard(void){
    FILE *fptr;
    // use appropriate location if you are using MacOS or Linux
    fptr = fopen("/Users/zhouchou/github-classroom/NCU-DSA-111-1/assignment_2-Mondayhs/storage_Game/game.txt","w");
    if(fptr == NULL){
        printf("Error!");   
        exit(1);             
    }
    chessPointer_Init();
    while (all_chess->top->next != NULL){
        fprintf(fptr,"%s\n",(char*)all_chess->top->value);
        all_chess->top = all_chess-> top-> next;
    }
    fclose(fptr);
    
} 
// static char chess_all[ROW*COL][20];

void Read_chessboard(void){
    FILE *fptr;
    int n=0;
    // char chess_;
    all_chess = init_stack();


    fptr = fopen("/Users/zhouchou/github-classroom/NCU-DSA-111-1/assignment_2-Mondayhs/storage_Game/game.txt","r");
    if ( fptr == NULL){
        printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
        exit(1);
    }
    while(!feof(fptr)){
        fscanf(fptr,"%s\n",&chess_all[n-1][20]);
        push(all_chess, (void*) &chess_all[n]); 
        n++;
        // fscanf(fptr,"%s\n",&chess_);
        // printf("%s\n", (char*) chess_);
        // identify_chess( &chess_ );
        // printf("%d",n++);
    }
    push(all_chess, NULL);
    printf("%lu\n", sizeof((char*)all_chess->top->previous->previous->value));
    // chessboardPrint();
    fclose(fptr);
    
}

void identify_chess( char  *chess_t ){
    if (chess_t == R_soldier)
        push(all_chess, (void*) &R_soldier);
    else if (chess_t == R_car)
        push(all_chess, (void*) &R_car);
    else if (chess_t == R_hours)
        push(all_chess, (void*) &R_hours);
    else if (chess_t == R_sliver)
        push(all_chess, (void*) &R_sliver); 
    else if (chess_t == R_corner)
        push(all_chess, (void*) &R_corner);
    else if (chess_t == R_gold)
        push(all_chess, (void*) &R_gold);
    else if (chess_t == R_fly)
        push(all_chess, (void*) &R_fly);
    else if (chess_t == R_king)
        push(all_chess, (void*) &R_king);

    else if (chess_t == B_soldier)
        push(all_chess, (void*) &B_soldier);
    else if (chess_t == B_car)
        push(all_chess, (void*) &B_car);
    else if (chess_t == B_hours)
        push(all_chess, (void*) &B_hours);
    else if (chess_t == B_sliver)
        push(all_chess, (void*) &B_sliver); 
    else if (chess_t == B_corner)
        push(all_chess, (void*) &B_corner);
    else if (chess_t == B_gold)
        push(all_chess, (void*) &B_gold);
    else if (chess_t == B_fly)
        push(all_chess, (void*) &B_fly);
    else if (chess_t == B_king)
        push(all_chess, (void*) &B_king);
    
    // else if (chess_t == CROSS)
    //     push(all_chess, (void*) &CROSS);

}
