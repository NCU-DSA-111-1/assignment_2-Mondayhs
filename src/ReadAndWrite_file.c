#include "chess_def.h"


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
        // fprintf(fptr,"%c", ',' );
        all_chess->top = all_chess-> top-> next;
    }
    fclose(fptr);
    
} 
// static char chess_all[ROW*COL][20];

void Read_chessboard(void){
    FILE *fptr;
    int n=0;
    all_chess = init_stack();


    fptr = fopen("/Users/zhouchou/github-classroom/NCU-DSA-111-1/assignment_2-Mondayhs/storage_Game/game.txt","r");
    if ( fptr == NULL){
        printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
        exit(1);
    }
    while(!feof(fptr)){
        fscanf(fptr,"%s\n",&chess_all[n-1][20]);
        // printf("%s%d\n", "-------",n);
        // printf("%s\n", (char*) chess_all[n]);
        push(all_chess, (void*) &chess_all[n]); 
        n++;
    }
    printf("%s\n", "-------1111");
    printf("%s\n",(char*) chess_all[2]);
    // push(all_chess, (void*) &chess_t); 
    printf("%s\n", (char*)all_chess->top->previous->value);


    // chessboardPrint();
    fclose(fptr);
    
}

