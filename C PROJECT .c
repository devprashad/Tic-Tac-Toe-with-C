#include <stdio.h>

int check_for_winner();
void displaying_board();
void choice_entering();
char X_or_O();


void player_vs_computer();
int get_computer_move_easy();
int get_computer_move_medium();
int get_computer_move_hard();

void reset();


int player_1_score;
int player_2_score;
int how = 1;
int do_you;
int difficulty;
int player = 1, i, choice;
char mark;


char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
struct text
{
    char txt1[100];
    char txt2[100];
    
};

int main()
{
//	how=1
    while (how)
    {
        printf("\t\t\t\t\tTIC TAC TOE\n");   
        struct text t1={"1.Press 1 to play Player vs Player","2.Press 2 to play Player vs Coumputer"};
        struct text*ptr=&t1;
        printf("\t\t\t\t%s \n\t\t\t\t%s\n\n",ptr->txt1,ptr->txt2);


        printf("Enter your choice :");
        scanf("%d", &do_you);
        printf("\n\n");
        
        if (do_you == 1)
        {
            choice_entering();
        }
        else if(do_you == 2)
        {
            player_vs_computer();
        }
        else{
        	printf("\t\t\t\tInvalid choice\n");
		}

        printf("\t\t\t\tDo you want to play again '1 for yes and '0' for no :");
        scanf("%d", &how);

        reset();
    }

    return 0;
}

char X_or_O()
{
    player = (player % 2) ? 1 : 2;
    
    if (do_you == 1)
    {
        printf("\n");
        printf("\t\t\t\t Player %d, enter a number:  ", player);
        scanf("%d", &choice);
    }
    
    else if (do_you == 2)
    {
    	
        if (player == 1)
        {
            printf("\t\t\t\t Player %d, enter a number:  ", player);
            scanf("%d", &choice);
        }
        else if (player == 2 && difficulty==1)
        {
            choice = get_computer_move_easy();
            printf("\t\t\t\t The computer chose %d\n", choice);
        }
        else if (player == 2 && difficulty==2)
        {
            choice = get_computer_move_medium();
            printf("\t\t\t\t The computer chose %d\n", choice);
        }
        else if (player == 2 && difficulty==3)
        {
            choice = get_computer_move_hard();
            printf("\t\t\t\t The computer chose %d\n", choice);
        }
        
    }
    
    return (player == 1) ? 'X' : 'O';
}

void choice_entering()
{
    do
    {
        displaying_board();
        

        mark = X_or_O();

        if (choice == 1 && board[1] == '1')
            board[1] = mark;

        else if (choice == 2 && board[2] == '2')
            board[2] = mark;

        else if (choice == 3 && board[3] == '3')
            board[3] = mark;

        else if (choice == 4 && board[4] == '4')
            board[4] = mark;

        else if (choice == 5 && board[5] == '5')
            board[5] = mark;

        else if (choice == 6 && board[6] == '6')
            board[6] = mark;

        else if (choice == 7 && board[7] == '7')
            board[7] = mark;

        else if (choice == 8 && board[8] == '8')
            board[8] = mark;

        else if (choice == 9 && board[9] == '9')
            board[9] = mark;

        else
        {
            printf("\n\n\n");
            printf("\t\t\t********Invalid move**********\n");

            player--;
        }

        i = check_for_winner();
        
        player++;
        
        
    } while (i == -1);
    
    displaying_board();

    if (i == 1)
    {
        printf("\t\t\t********Player %d is the winner **********\n", --player);
        if (player == 1)
        {
            player_1_score++;
        }
        else
        {
            player_2_score++;
        }
    }
    else
    {
        printf("\t\t\t*********Game draw*************\n");
    }
}

int check_for_winner()
{
    if (board[1] == board[2] && board[2] == board[3])
        return 1;

    else if (board[4] == board[5] && board[5] == board[6])
        return 1;

    else if (board[7] == board[8] && board[8] == board[9])
        return 1;

    else if (board[1] == board[4] && board[4] == board[7])
        return 1;

    else if (board[2] == board[5] && board[5] == board[8])
        return 1;

    else if (board[3] == board[6] && board[6] == board[9])
        return 1;

    else if (board[1] == board[5] && board[5] == board[9])
        return 1;

    else if (board[3] == board[5] && board[5] == board[7])
        return 1;

    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' &&
             board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9')

        return 0;

    else
        return -1;
}

void displaying_board()
{

       printf("\n\n\t\t\t\t              Tic Tac Toe\n\n");

    printf("\t\t\t       player 1 score :%d         player 2 score :%d  \n", player_1_score, player_2_score);

    printf("\t\t\t              Player 1 (X)  -  Player 2 (O)  \n\n\n");

    printf("\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t  %c  |  %c  |  %c \n", board[1], board[2], board[3]);
    printf("\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t__ __ __ __ __ __\n\n");
    printf("\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t  %c  |  %c  |  %c \n", board[4], board[5], board[6]);
    printf("\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t__ __ __ __ __ __\n");
    printf("\t\t\t\t\t     |     |     \n");
    printf("\t\t\t\t\t  %c  |  %c  |  %c \n", board[7], board[8], board[9]);
    printf("\t\t\t\t\t     |     |     \n\n\n");
}

int get_computer_move_hard()
{

    int q;

    if (0)
    {
        //////
    }

    else if (board[1] == 'X' && board[2] == 'X' && board[3] == '3')
    {
        return 3;
    }

    else if (board[1] == 'X' && board[3] == 'X' && board[2] == '2')
    {
        return 2;
    }
    else if (board[2] == 'X' && board[3] == 'X' && board[1] == '1')
    {
        return 1;
    }

    else if (board[4] == 'X' && board[5] == 'X' && board[6] == '6')
    {
        return 6;
    }
    else if (board[5] == 'X' && board[6] == 'X' && board[4] == '4')
    {
        return 4;
    }
    else if (board[4] == 'X' && board[6] == 'X' && board[5] == '5')
    {
        return 5;
    }

    else if (board[7] == 'X' && board[8] == 'X' && board[9] == '9')
    {
        return 9;
    }
    else if (board[8] == 'X' && board[9] == 'X' && board[7] == '7')
    {
        return 7;
    }
    else if (board[7] == 'X' && board[9] == 'X' && board[8] == '8')
    {
        return 8;
    }

    else if (board[1] == 'X' && board[4] == 'X' && board[7] == '7')
    {
        return 7;
    }
    else if (board[4] == 'X' && board[7] == 'X' && board[1] == '1')
    {
        return 1;
    }
    else if (board[1] == 'X' && board[7] == 'X' && board[4] == '4')
    {
        return 4;
    }

    else if (board[2] == 'X' && board[5] == 'X' && board[8] == '8')
    {
        return 8;
    }
    else if (board[5] == 'X' && board[8] == 'X' && board[2] == '2')
    {
        return 2;
    }
    else if (board[2] == 'X' && board[8] == 'X' && board[5] == '5')
    {
        return 5;
    }

    else if (board[3] == 'X' && board[6] == 'X' && board[9] == '9')
    {
        return 9;
    }
    else if (board[9] == 'X' && board[3] == 'X' && board[6] == '6')
    {
        return 6;
    }
    else if (board[9] == 'X' && board[6] == 'X' && board[3] == '3')
    {
        return 3;
    }

    else if (board[1] == 'X' && board[5] == 'X' && board[9] == '9')
    {
        return 9;
    }
    else if (board[1] == 'X' && board[9] == 'X' && board[5] == '5')
    {
        return 5;
    }
    else if (board[9] == 'X' && board[5] == 'X' && board[1] == '1')
    {
        return 1;
    }

    else if (board[3] == 'X' && board[5] == 'X' && board[7] == '7')
    {
        return 7;
    }
    else if (board[3] == 'X' && board[7] == 'X' && board[5] == '5')
    {
        return 5;
    }
    else if (board[5] == 'X' && board[7] == 'X' && board[3] == '3')
    {
        return 3;
    }

    else if (board[5] == '5')
    {
        return 5;
    }
    else if (board[1] == '1')
    {
        return 1;
    }
    else if (board[3] == '3')
    {
        return 3;
    }
    else if (board[7] == '7')
    {
        return 7;
    }
    else if (board[9] == '9')
    {
        return 9;
    }

    else
    {
        for (q = 1; q < 10; q++)
        {
            if (board[q] == 'X' || board[q] == 'O')
            {
            }
            else
            {
                return q;
            }
        }
    }
}

void player_vs_computer()
{
	printf("How difficult do you need \n");
	printf("1.Easy\n");
	printf("2.Medium\n");
	printf("3.Hard\n");
	printf("Enter the difficulty level:");
	scanf("%d",&difficulty);
	
	
    choice_entering();
}



int get_computer_move_easy(){
	int n;
	
	for (n = 1; n < 10; n++)
        {
            if (board[n] == 'X' || board[n] == 'O')
            {
            }
            else
            {
                return n;
            }
        }
	
	
	
}




int get_computer_move_medium(){
	int h;
	if(0){
		///
	}
	else if (board[5] == '5')
    {
        return 5;
    }
    else if (board[1] == '1')
    {
        return 1;
    }
    else if (board[3] == '3')
    {
        return 3;
    }
    else if (board[7] == '7')
    {
        return 7;
    }
    else if (board[9] == '9')
    {
        return 9;
    }

    else
    {
        for (h = 1; h< 10; h++)
        {
            if (board[h] == 'X' || board[h] == 'O')
            {
            }
            else
            {
                return h;
            }
        }
    }
	
	
	
}


void reset()
{
    how = 1;
    do_you = 0;

    board[0] = '0';
    board[1] = '1';
    board[2] = '2';
    board[3] = '3';
    board[4] = '4';
    board[5] = '5';
    board[6] = '6';
    board[7] = '7';
    board[8] = '8';
    board[9] = '9';

    player = 1;
    i = 0;
    choice = 0;
}
