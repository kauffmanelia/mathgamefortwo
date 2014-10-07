//
//  main.c
//  mathgamefortwo
//
//  Created by Elia Kauffman on 2014-10-07.
//  Copyright (c) 2014 Elia Kauffman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char name[20];
    int lives;
    int wins;
} Player;

enum operator {
    addition = 0,
    subtraction = 1,
    multiplication = 2
};

void playertoggle(int * playernum){
    if(*playernum == 1) *playernum = 2;
    else if(*playernum == 2) *playernum = 1;
}

void removenewline(char inputstring[]){
    inputstring[strlen(inputstring)-1] = '\0';
}

bool isrightanswer(char input[]){
    int num1 = rand() % 20;
    int num2 = rand() % 20;
    enum operator whichop = rand() % 3;
    bool retval;
    if(whichop == addition){
        printf("WHAT DOES %d PLUS %d EQUAL? ", num1, num2);
    }
    if(whichop == subtraction){
        printf("WHAT DOES %d MINUS %d EQUAL? ", num1, num2);
    }
    if(whichop == multiplication){
        printf("WHAT DOES %d TIMES %d EQUAL? ", num1, num2);
    }
    fgets(input, 10, stdin);
    while( // This funky while condition only returns true if both these conditions are met:
          (!((input[0] >= '0') && (input[0] <= '9'))) // The first character of the input is not a number
          &&
          !(input[0] == '-')){ // and the first character is not a dash, so this allows for negative number input
        printf("THAT IS NOT A VALID RESPONSE. PLEASE ENTER A VALID RESPONSE.\n");
        fgets(input, 10, stdin);
    }
    int answer = strtol(input, NULL, 10);
    if(whichop == addition){
        if(answer == (num1+num2)) retval = true;
        else retval = false;
    }
    if(whichop == subtraction){
        if(answer == (num1-num2)) retval = true;
        else retval = false;
    }
    if(whichop == multiplication){
        if(answer == (num1*num2)) retval = true;
        else retval = false;
    }
    return retval;
}

int main(void){
    srand(time(NULL));
    printf("GREETINGS PROFESSOR FALKEN\n");
    printf("SHALL WE PLAY A GAME?\n");
    //printf("I KNOW YOU WOULD PREFER A NICE GAME OF CHESS, OR POSSIBLY GLOBAL THERMONUCLEAR WAR, BUT CURRENTLY I AM ONLY PROGRAMMED FOR A FACILE GAME OF MATH FOR TWO PLAYERS.\nIF YOU ARE STILL INTERESTED, ENTER YES. IF NOT, ENTER NO. ");
    char input[10];
    char startstring[] = "yes\n";
    char exitstring[] = "no\n";
    Player player1;
    player1.wins = 0;
    Player player2;
    player2.wins = 0;
    int playernum;
    bool answer;
    bool namesset = false;
    while(true){
        
        fgets(input, 10, stdin);
        if(strcmp(input, exitstring) == 0){
            printf("GOODBYE PROFESSOR FALKEN\n");
            break; // if 'no' is entered, exit
        }
        else if(strcmp(input, startstring) != 0){
            printf("THAT IS NOT A VALID RESPONSE. PLEASE ENTER A VALID RESPONSE. ");
            continue;
        }
        
        player1.lives = 3;
        player2.lives = 3;
        playernum = 1;
        if(namesset == false){
            printf("ENTER PLAYER 1 NAME OR NO INPUT TO USE DEFAULT\n");
            fgets(input, 10, stdin);
            if(strlen(input) == 1) strcpy(player1.name, "PLAYER 1");
            else {
                removenewline(input);
                strcpy(player1.name, input);
            }
            
            printf("ENTER PLAYER 2 NAME OR NO INPUT TO USE DEFAULT\n");
            fgets(input, 10, stdin);
            if(strlen(input) == 1) strcpy(player2.name, "PLAYER 2");
            else {
                removenewline(input);
                strcpy(player2.name, input);
            }
            namesset = true;
        }
        else{
            printf("CURRENT PLAYER SCORES ARE:\n");
            printf("%s: %d \t%s: %d\n", player1.name, player1.wins, player2.name, player2.wins);
        }
        while((player1.lives != 0) && (player2.lives != 0)){
            printf("%s LIVES: %d\t%s LIVES: %d\n", player1.name, player1.lives, player2.name, player2.lives);
            if(playernum == 1) printf("%s ", player1.name);
            else if(playernum == 2) printf("%s " , player2.name);
            answer = isrightanswer(input);
            if(!answer){
                if(playernum == 1) {
                    printf("INCORRECT. %s LOSES ONE LIFE.\n\n", player1.name);
                    player1.lives--;
                }
                else if(playernum == 2) {
                    printf("INCORRECT. %s LOSES ONE LIFE.\n\n", player2.name);
                    player2.lives--;
                }
            }
            else {
                printf("CORRECT.\n");
            }
            
            if(!(player1.lives == 0) && !(player2.lives == 0)) playertoggle(&playernum);
        }
        
        if(player1.lives == 0){
            printf("%s HAS LOST ALL LIVES. %s WILL BE DECOMISSIONED SHORTLY.\n", player1.name, player1.name);
            player2.wins++;
        }
        else if(player2.lives == 0){
            printf("%s HAS LOST ALL LIVES. %s WILL BE DECOMISSIONED SHORTLY.\n", player2.name, player2.name);
            player1.wins++;
        }
        printf("THIS GAME HAS ENDED. SHALL WE PLAY ANOTHER GAME? ");
    }
    return 0;
}






