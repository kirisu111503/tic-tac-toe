//You can visit me @github https://github.com/kirisu111503 -------//
//My simple tic-tac-toe-------//
//**********************************//
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
//**********************************//
/* Guide to Play
>>>Numbers represent the value of blocks
>>>Input the number of the desire position of your move
     —————————————
     | 1 | 2 | 3 |  Example: you input: 1      —————————————
     —————————————  This should be the output: | O |   |   |
     | 4 | 5 | 6 |                             —————————————
     —————————————                             |   |   |   |
     | 7 | 8 | 9 |                             —————————————
     —————————————                             |   |   |   |
                                               —————————————
*/
//*********************************//
//prototypes needed in the program
void tempVal(char user_input[10]);
void drawBoard(char user_input[10]);
bool already_filled(int select,char user_input[10]);
bool win(char test,char user_input[10]);
bool invalidInput(int select);
void default_player_name(char pname[20], char pname1[20]);

int main()
{
    char user_input[10];//this will be the X and O for tic tac toe
    int i, j;
    int select;
    char restart;
    int player1_score = 0, player2_score = 0;
    char pname[2][15];
    int custom;
    int temp=1;
    printf("Reminder: Inputting a number that not\npart of the choice will automatically\nDefault the name");
    printf("\n1. Custom name\n2. Default name\n");
    printf("Select: ");
    scanf(" %d", &custom);
    printf("\e[1;1H\e[2J");
    if(custom==1) {//prompt the user for names
        printf("Enter Player 1 name: ");
        scanf(" %[^\n]s", pname[0]);
        printf("\e[1;1H\e[2J");
        printf("Enter Player 2 name: ");
        scanf(" %[^\n]s", pname[1]);
    } else//default the player names
        default_player_name(pname[0],pname[1]);
    tempVal(user_input);
    do {
        //player switch if x win o turn if o win x turn
        if(win(user_input[select],user_input)) {
            if(user_input[select] == 'X')
                temp=1;
            else if(user_input[select] == 'O')
                temp=2;
        }
        //for if draw
        if(temp==1)
            j=10;
        else
            j=11;

        tempVal(user_input);
        for(i=temp; i<=j; i++) {
            //header
            printf("\e[1;1H\e[2J");
            printf("Welcome to Tic Tac Toe!\n");
            printf("Score:\n[ O ] Player %s = %d\n[ X ] Player %s = %d\n\n",pname[0],player1_score,pname[1],player2_score);
            drawBoard(user_input);
            //check who win
            if(win(user_input[select],user_input)) {
                printf("Player %s [%c] win!\n", user_input[select] == 'O'? pname[0]:pname[1], user_input[select]);
                if(user_input[select] == 'O')
                    player1_score++;
                else
                    player2_score++;
                break;
            }
            //check if the players meet the end of the loop means it's draw
            if(i==j) {
                printf("\tDraw!\n");
                break;
            }
            do {
                do {
                    //prompt the user to input
                    printf("[ %c ] Player %s pick [1-9]: ", i%2==0? 'X':'O', i%2==0? pname[1]:pname[0]);
                    scanf("%d", &select);
                    //check if the value user inputted is valid
                    if(invalidInput(select))
                        printf("Invalid Input!\n");
                } while(invalidInput(select));
                //check if the number user pick is already filled before assigning value
                if(already_filled(select,user_input))
                    printf("The number is already filled.\n");
            } while(already_filled(select,user_input));
            //to switch player 1 to player 2
            //assigning value for players
            if(i%2==0) {
                //player 2
                user_input[select] = 'X';
          /*>>*/printf("\a");//put '//' here if you want to remove the sound 
            }
            else {
                //player 1
                user_input[select] = 'O';
          /*>>*/printf("\a");//put '//' here if you want to remove the sound 
            }


        }//ask the user if he/she want to restart the board
        printf("Restart board[y/n]: ");
        scanf(" %c", &restart);
    } while(restart == 'y');//if the user decision is no then display the final tally
    printf("\e[1;1H\e[2J");
    printf("\nFinal scores:\nPlayer %s = %d\nPlayer %s = %d\n\n",pname[0],player1_score,pname[1],player2_score);
    if(player1_score>player2_score)
        printf("        [    Player 1 win!     ]\n");
    else if(player2_score>player1_score)
        printf("        [    Player 2 win!     ]\n");
    else
        printf("	  [    Draw!    ]\n\n");
    printf("     [   Thank you for playing!   ]\n");
    return 0;
}


//draw board
void drawBoard(char user_input[10]) {
    int i;
    for(i=1; i<=9; i++) {
        if(i==1||i==4||i==7) {
            printf("	—————————————\n");
            printf("	|");
        }
        printf(" %c |", user_input[i]);
        if(i==9)
            printf("\n	—————————————");
        if(i%3==0)
            printf("\n");
    }
    printf("\n");
}

//initialized value in array
void tempVal(char user_input[10]) {
    for(int i=0; i<10; i++) {
        user_input[i] = ' ';//manually assign each index a value
    }
}

//check if the player already pick the number
bool already_filled(int select,char user_input[10]) {
    if(user_input[select] == 'X'|| user_input[select] == 'O')
        return true;
    else
        return false;
}

//check if either the player win
bool win(char test, char user_input[10]) {
    if(!(test == ' ')) {
        if((user_input[1] == test && user_input[5] == test && user_input[9] == test)||(user_input[3] == test && user_input[5] == test &&user_input[7] == test))
            return true;
        else if((user_input[1] == test && user_input[2] == test && user_input[3] == test )||(user_input[4] == test && user_input[5] == test && user_input[6] == test )||(user_input[7] == test && user_input[8] == test && user_input[9] == test))
            return true;
        else if((user_input[1] == test && user_input[4] == test && user_input[7] == test )||(user_input[2] == test && user_input[5] == test && user_input[8] == test )||(user_input[3] == test && user_input[6] == test && user_input[9] == test))
            return true;
        else
            return false;
    } else
        return false;

}
//invalid input if the player input lessthan 1 and greater than 9
bool invalidInput(int select) {
    if(select<1 || select>9)
        return true;
    else
        return false;

}

//to default the players name//---Just me being lazy to think
void default_player_name(char pname[20], char pname1[20]) {
    char p1[20] = "Default 1";
    char p2[20] = "Default 2";
    int length = strlen(p1);
    int i;
    for(i=0; i<=length; i++) {
        pname[i] = p1[i];
        pname1[i] = p2[i];
    }
}

/*
I'm just getting started with programming,
but I'm eager to enhance this game in the near future.
I'm still very much a beginner, learning the ropes,
but I'm determined to improve.
Feel free to leave some feedback for me to improve,
I hope you enjoy the game. 
*/