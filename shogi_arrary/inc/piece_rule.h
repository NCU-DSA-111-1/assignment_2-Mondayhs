#include "chessboard.h"



//判斷是紅棋還是藍棋,紅旗返回-1,藍棋返回1,否則返回0
int redOrBlue(int x,int y){

    if (array[x][y] == R(步) || array[x][y] == R(香) || array[x][y] == R(桂) || array[x][y] == R(銀) || array[x][y] == R(角) || array[x][y] == R(飛) || array[x][y] == R(金) || array[x][y] == R(王))
    {
        return  - 1;
    }
    else if (array[x][y] == B(步) || array[x][y] == B(香) || array[x][y] == B(桂) || array[x][y] == B(銀) || array[x][y] == B(角) || array[x][y] == B(飛) || array[x][y] == B(金) || array[x][y] == B(王))
    {
        return 1;
    }
    else
        return 0;
}


void swap( char **address_a , char **address_b ){
    char *temp = *(address_a);
    *address_a = *(address_b);
    *address_b = temp;
}

void Get_chess( )//int mov_row, int mov_col, int loc_row, int loc_col)
{   
    if(redOrBlue(Rp,Cp) == 1)
    {
        swap( &array[Rp][Cp], &array[Rm][Cm]);
        swap(&array[Rm][Cm], &red_get[r_i]);
        r_i++;
    }
    else if(redOrBlue(Rp,Cp) == -1)
    {
        swap( &array[Rp][Cp], &array[Rm][Cm]);
        swap(&array[Rm][Cm], &blue_get[b_i]);
        b_i++;
    }
    else
    {
        swap( &array[Rp][Cp], &array[Rm][Cm]);
    }

}





//每種棋子的規則
void rulesOfAllKindsOfChessPieces()
{   
    Rm = move_chess_R -1;
    Cm = move_chess_C -1;
    Rp = loc_chess_R -1;
    Cp = loc_chess_C -1;
/*------------------red 步--------------------*/

    if ( array[Rm][Cm] == R(步) )
    {
        if ( (Rm > Rp ) || ( Cm != Cp))
            isStandard=0;                   // 如果倒退或左右，則不符合規範
        if (  Rp != Rm+1 )
            isStandard=0;                   // 只能前進一步

        if ( (Cm == Cp) && (isStandard == 1) && (redOrBlue(Rp, Cp) != -1) )    //如果棋子直行、沒有犯規且落點不是紅棋，可以移動
        {
            Get_chess();
        }

        else
        {
            restart = 1;
        }
    }
/*------------------blue 步--------------------*/
    else if ( array[Rm][Cm] == B(步) )
    {
        if ( (Rm < Rp ) || ( Cm != Cp ) )
            isStandard=0;                   // 如果倒退或左右，則不符合規範
        if ( Rp != Rm-1 )
            isStandard=0;                   // 只能前進一步
        if ( Cm == Cp && isStandard && redOrBlue(Rp, Cp) != 1)//
        {
            Get_chess();
        }

        else
        {
            restart = 1;
        }
    }
/*------------------red 香--------------------*/
    else if ( array[Rm][Cm] == R(香) )
    {
        if ( (Rm > Rp ) || ( Cm != Cp ) )
            isStandard=0;                   // 如果倒退，則不符合規範
        for (int i = Rm+1; i < Rp; i ++)
        {
            if (array[i][Cp] != CROSS)
                isStandard = 0;
        }
        if ( (Cm == Cp) && (isStandard == 1) && (redOrBlue(Rp, Cp) != -1) )
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }
/*------------------blue 香--------------------*/
    else if ( array[Rm][Cm] == B(香) )
    {
        if ( (Rm < Rp ) || ( Cm != Cp ) )
            isStandard=0;                   // 如果倒退或左右，則不符合規範
        for (int i = Rm-1; i > Rp; i --)
        {
                if (array[i][Cp] != CROSS)
                    isStandard = 0;
        }
        if ( (Cm == Cp) && (isStandard == 1) && (redOrBlue(Rp, Cp) != 1) )
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }

/*------------------red 桂--------------------*/
    else if ( array[Rm][Cm] == R(桂) )
    {
        if ( Rm > Rp )
            isStandard=0;                   // 如果倒退，則不符合規範
        if (array[Rp][Cp] != CROSS)
            isStandard = 0;
        if ( (Cp == Cm+1 || Cp == Cm-1) && (Rp == Rm+2) && (isStandard == 1) && (redOrBlue(Rp, Cp) != -1) )
        {
            // swap( &(array[Rp][Cp]) , &(array[Rm][Cm]));
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }
/*------------------blue 桂--------------------*/
    else if ( array[Rm][Cm] == B(桂) )
    {
        if ( Rm < Rp )
            isStandard=0;                   // 如果倒退，則不符合規範
        if (array[Rp][Cp] != CROSS)
        {
            if ( redOrBlue(Rp, Cp) == -1 )
            isStandard = 0;
        }
        if ( (Cp == Cm+1 || Cp == Cm-1) && (Rp == Rm-2) && (isStandard == 1) && (redOrBlue(Rp, Cp) != 1) )
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }

/*------------------red 銀--------------------*/
    else if ( array[Rm][Cm] == R(銀) )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;                                               // 不能超出兩格
        if((Rp==Rm-1 && Cp==Cm) || (Rp==Rm && (Cp==Cm+1 || Cp==Cm-1)) || (isStandard == 0) || (redOrBlue(Rp, Cp) == -1))       //(Cp == Cm+1 || Cp == Cm-1) && (Rp == Rm+1 || Rp == Rm+1) && 
        {
            restart = 1;
        }
        else 
        {
            Get_chess();
        }

    }

/*------------------blue 銀--------------------*/
    else if ( array[Rm][Cm] == B(銀) )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;
        if ((Rp==Rm+1 && Cp==Cm) || (Rp==Rm && (Cp==Cm+1 || Cp==Cm-1)) || (isStandard == 0) || (redOrBlue(Rp, Cp) == 1) ) 
        {
            restart = 1;
        }
        else 
        {   
            Get_chess();
            
        }
    }

/*------------------red 金--------------------*/
    else if ( array[Rm][Cm] == R(金) )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;
        if ((Rp==Rm-1 && (Cp==Cm-1 || Cp==Cm+1)) || (isStandard == 0) || (redOrBlue(Rp, Cp) == -1) )       
        {
            restart = 1;
        }
        else 
        {
            Get_chess();
        }

    }

/*------------------blue 金--------------------*/
    else if ( array[Rm][Cm] == R(金) )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;
        if ((Rp==Rm+1 && (Cp==Cm-1 || Cp==Cm+1)) || (isStandard == 0) || (redOrBlue(Rp, Cp) == 1))        
        {
            restart = 1;
        }
        else
        {
            Get_chess();
        }

    }

/*------------------red 王--------------------*/
    else if ( array[Rm][Cm] == R(王) )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;
        if ((isStandard == 0) || (redOrBlue(Rp, Cp) == -1) )       
        {
            restart = 1;
        }
        else 
        {
            Get_chess();
        }
    }

/*------------------blue 王--------------------*/
    else if ( array[Rm][Cm] == B(王) )
    {
        if ( Rp >= Rm+2 || Rp <= Rm-2 || Cp >= Cm+2 || Cp <= Cm-2 )
            isStandard=0;
        if ((isStandard == 0) || (redOrBlue(Rp, Cp) == -1) )       
        {
            restart = 1;
        }
        else 
        {
            Get_chess();
        }
    }

/*------------------red 角--------------------*/
    else if ( array[Rm][Cm] == R(角) )
    {
        for (int i = 1; i < abs(Rp-Rm) ; i ++)      // 路上不可以有人
        {
            if ( Rp<Rm && Cp<Cm){
                if (array[Rp+i][Cp+i] != CROSS)
                    isStandard = 0;
            }
            if ( Rp<Rm && Cp>Cm){
                if (array[Rp+i][Cp-i] != CROSS)
                    isStandard = 0;
            }
            if ( Rp>Rm && Cp<Cm){
                if (array[Rp-i][Cp+i] != CROSS)
                    isStandard = 0;
            }
            if ( Rp>Rm && Cp>Cm){
                if (array[Rp-i][Cp-i] != CROSS)
                    isStandard = 0;
            }
        }
        if ( (abs(Cp-Cm) == abs(Rp-Rm)) && (isStandard == 1) && (redOrBlue(Rp, Cp) != -1) )
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }

/*------------------blue 角--------------------*/
    else if ( array[Rm][Cm] == B(角) )
    {
        for (int i = 1; i < abs(Rp-Rm) ; i ++)
        {
            if ( Rp<Rm && Cp<Cm){
                if (array[Rp+i][Cp+i] != CROSS)
                    isStandard = 0;
            }
            if ( Rp<Rm && Cp>Cm){
                if (array[Rp+i][Cp-i] != CROSS)
                    isStandard = 0;
            }
            if ( Rp>Rm && Cp<Cm){
                if (array[Rp-i][Cp+i] != CROSS)
                    isStandard = 0;
            }
            if ( Rp>Rm && Cp>Cm){
                if (array[Rp-i][Cp-i] != CROSS)
                    isStandard = 0;
            }
        }
        if ( (abs(Cp-Cm) == abs(Rp-Rm)) && (isStandard == 1) && (redOrBlue(Rp, Cp) != -1) )
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }

/*------------------red 飛--------------------*/
    else if ( array[Rm][Cm] == R(飛) )
    {
        for (int i = 1; i < abs(Rp-Rm) ; i ++)
        {
            if ( Rp<Rm && Cp==Cm){
                if (array[Rp+i][Cp] != CROSS)
                    isStandard = 0;
            }
            if ( Rp>Rm && Cp==Cm){
                if (array[Rp-i][Cp] != CROSS)
                    isStandard = 0;
            }
            if ( Rp==Rm && Cp<Cm){
                if (array[Rp][Cp+i] != CROSS)
                    isStandard = 0;
            }
            if ( Rp==Rm && Cp>Cm){
                if (array[Rp][Cp-i] != CROSS)
                    isStandard = 0;
            }
        }
        if ( ( Rp == Rm || Cp == Cm) && (isStandard == 1) && (redOrBlue(Rp, Cp) != -1) )
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }
/*------------------blue 飛--------------------*/
    else if ( array[Rm][Cm] == B(飛) )
    {
        for (int i = 1; i < abs(Rp-Rm) ; i ++)
        {
            if ( Rp<Rm && Cp==Cm){
                if (array[Rp+i][Cp] != CROSS)
                    isStandard = 0;
            }
            if ( Rp>Rm && Cp==Cm){
                if (array[Rp-i][Cp] != CROSS)
                    isStandard = 0;
            }
            if ( Rp==Rm && Cp<Cm){
                if (array[Rp][Cp+i] != CROSS)
                    isStandard = 0;
            }
            if ( Rp==Rm && Cp>Cm){
                if (array[Rp][Cp-i] != CROSS)
                    isStandard = 0;
            }
        }
        if ( ( Rp == Rm || Cp == Cm) && (isStandard == 1) && (redOrBlue(Rp, Cp) != -1) )
        {
            Get_chess();
        }
        else
        {
            restart = 1;
        }
    }

}