#include "chess_def.h"


void write_chessboard(void){
    // if ( == "s" || "S"){
        FILE *fptr;
    // use appropriate location if you are using MacOS or Linux
        fptr = fopen("/Users/zhouchou/github-classroom/NCU-DSA-111-1/assignment_2-Mondayhs/storage_Game/game.txt","w");

        if(fptr == NULL){
            printf("Error!");   
            exit(1);             
        }
        chessPointer_Init();
        while (all_chess->top->next != NULL){
            fprintf(fptr,"%s",(char*)all_chess->top->value);
            all_chess->top = all_chess-> top-> next;
        }
        fclose(fptr);
    // }
} 

void Read_chessboard(void){
    char chess_t;
    FILE *fptr;
    fptr = fopen("/Users/zhouchou/github-classroom/NCU-DSA-111-1/assignment_2-Mondayhs/storage_Game/game.txt","r");
    if ( fptr == NULL){
        printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
        exit(1);
    }
    
    do{              // use push
        chess_t = fgetc(fptr);
        // fscanf(fptr,"%s",&chess_t);
        push(all_chess, (void*) &chess_t); 
    }while (chess_t != EOF);

    fclose(fptr);
    chessboardPrint();
}
