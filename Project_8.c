#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

const int BOARD_SIZE=3;
int check;
int check_difficulty;
char player1[30];
char player2[30];

#define X 'X'
#define O 'O'

typedef struct 
{
    int player;
    int computer;
    int draw;
}Score;

Score score;

void menu();
void difficulty();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();
void player_move(char board[BOARD_SIZE][BOARD_SIZE],char player);
void computer_move(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE],char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
void clear_screen();
void multiplayer();


int main() {
    printf("======> Welcome to Tic-Tac-Toe Game. <======\n");
    srand(time(NULL));
    menu();
    if (check==2)
    {
        return 0;
    }
    clear_screen();
    play_game();
    return 0;
}

void menu() {
    score.computer=0,score.draw=0,score.player=0;
    while ( check!=1 && check!=2 ) {
        printf("\nSelect the mode:-\n");
        printf("1. Vs Computer.\n");
        printf("2. Vs Player\n");
        printf("Choose mode: ");
        scanf("%d",&check);
        if (check!=1 && check!=2) {
            printf("\nInvalid choice!\n");
        }
    }
    if (check==1) {
        difficulty();
    }
    else if (check==2) {
        multiplayer();
    }
}

void difficulty() {
    check_difficulty=0;
    while (check_difficulty!=1 && check_difficulty!=2)
    {
        printf("\nSelect Difficulty Level:-\n");
        printf("1 - HUMAN (Standard)\n");
        printf("2 - GOD (Impossible to win)\n");
        printf("Choice: ");
        scanf("%d",&check_difficulty);
        if (check_difficulty!=1 && check_difficulty!=2)
        {
            printf("\nIncorrect choice entered (1/2)!!\n");
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    if(check==1 ) {
        printf("Score - Player X: %d, Computer: %d, Draw: %d\n",score.player,score.computer,score.draw);
    }
    else {
        printf("Score - %s (X): %d, %s (O): %d, Draw: %d\n",player1,score.player,player2,score.computer,score.draw);
    }
    printf("Tic-Tac-Toe");
    if (check_difficulty==2)
    {
        printf(" ---> God Mode!!");
    }
    else if(check_difficulty==1){
        printf(" ---> Standard Mode.");
    }
    printf("\n\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c ",board[i][j]);
            if (j<2)
            {
                printf("|");
            }
        }
        if (i<2)
        {
            printf("\n---+---+---\n");
        } 
    }
    printf("\n");
}

void play_game() {
    int choice;
    do{
        char board[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };
        char current_player= rand() % 2 == 0 ? X : O ;
            while (1) {
                clear_screen();
                print_board(board);
                if (current_player==O)
                {
                    printf("\nComputer Turn.");
                }
                
                if (current_player==X) {
                    player_move(board,X);
                    if (check_win(board,X))
                    {
                        score.player++;
                        clear_screen();
                        print_board(board);
                        printf("\n=====> Congratulations!!You won. <=====\n");
                        break;
                    }
                    current_player=O;
                }
                else {
                    sleep(1);
                    computer_move(board);
                    if (check_win(board,O)) {
                        score.computer++;
                        clear_screen();
                        print_board(board);
                        printf("\n=====> Better Luck Next Time! I Won. <=====\n");
                        break;
                        
                    }
                    current_player=X;
                }
                if (check_draw(board))
                {
                    score.draw++;
                    clear_screen();
                    print_board(board);
                    printf("\n=====> It's a Draw <=====\n");
                    break;
                }
            }
            printf("Play again? (1 for yes, 0 for no): ");
            scanf("%d",&choice);
    } while (choice==1);    
}


void multiplayer() {
    getchar();
    printf("Enter first players name: ");
    fgets(player1,30,stdin);
    player1[strlen(player1)-1]='\0';
    printf("Enter second players name: ");
    fgets(player2,30,stdin);
    player2[strlen(player2)-1]='\0';
    int response;
    do
    {
        char board[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };
        char current_player = rand() % 2 == 0 ? X : O ;

        while (1)
        {
            clear_screen();
            print_board(board);
            if (current_player==X)
            {
                player_move(board,X);
                if (check_win(board,X) )
                {
                    score.player++;
                    clear_screen();
                    print_board(board);
                    break;
                }
                current_player=O;
            }
            else
            {
                player_move(board,O);
                if (check_win(board,O))
                {
                    score.computer++;
                    clear_screen();
                    print_board(board);
                    break;
                }
                current_player=X;
            }

            if (check_draw(board))
            {
                score.draw++;
                clear_screen();
                print_board(board);
                break;
            } 
        }
        printf("Play again? (1 for yes, 0 for no): ");
        scanf("%d",&response);
    } while (response==1);
}


void player_move(char board[BOARD_SIZE][BOARD_SIZE],char player) {
    int count=0,x,y;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j]==' ')
            {
                count++;
                x=i;
                y=j;
            }
            
        }
    }


    if (count==1)
    {
        board[x][y]=player;
        return;
    }
    
    
    int row,col;
    while (1)
    {
        if ( check==2 )
        {
            if (player==X)
            {
                printf("%s's Turn",player1);
            }
            else if(player==O)
            {
                printf("%s's Turn",player2);
            }
        }
        else {
            printf("\nYour Turn.");
        }

        printf("\nEnter row and column (1/3): ");
        scanf("%d%d",&row,&col);
        while (getchar() != '\n');
        if (row >= 1 && row <= 3 && col >=1 && col <= 3 && board[row-1][col-1]==' ')
        {
            board[row-1][col-1]=player;
            return;
        }
    }
    
    
}


void computer_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    //1.For Immediate win
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j]==' ' )
            {
                board[i][j]=O;
                if (check_win(board,O))
                {
                    return;
                }
                board[i][j]=' ';
            }
        }
        
    }

    //2.For immediate deffense
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j]==' ' )
            {
                board[i][j]=X;
                if (check_win(board,X))
                {
                    board[i][j]=O;
                    return;
                }
                board[i][j]=' ';
            }
        }
    }

   //GOD MODE 
    if (check_difficulty==2)
    {
        //3.For center
         if (board[1][1]==' ')
                {
                    board[1][1]=O;
                    return;
                }

        //4.For Corner
        int corner[4][2]={ {0,0} , {2,0} , {0,2} , {2,2} };
        for (int i = 0; i < 4; i++)
        {
            if  ( board[corner[i][0] ] [corner[i][1] ] ==' ' ) {
                board[ corner[i][0] ] [ corner[i][1] ]=O;
                return;
            }
        }
    }
    
    //5. Random move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = O;
                return;
            }
        }
    }
}



int check_win(char board[BOARD_SIZE][BOARD_SIZE],char player) {
    for (int  i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0]==player && board[i][1]==player && board[i][2]==player)
        {
            return 1;
        }

        if (board[0][i]==player && board[1][i]==player && board[2][i]==player)
        {
            return 1;
        }
        
    }
    
    if ( (board[0][0]==player && board[1][1]==player && board[2][2]==player) || (board[2][0]==player && board[1][1]==player && board[0][2]==player) ) {
        return 1;
    }
    
    return 0;
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i=0;i<BOARD_SIZE;i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j]==' ') {
                return 0;
            }   
        } 
    }
    return 1;
}

void clear_screen() {
    #ifdef _WIN32
    system("cls");
    #else 
    system("clear");
    #endif
}