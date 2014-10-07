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

void playertoggle(int * playernum){
    if(*playernum == 1) *playernum = 2;
    else if(*playernum == 2) *playernum = 1;
}

void removenewline(char inputstring[]){
    inputstring[strlen(inputstring)-1] = '\0';
}

int main(void){
    srand(time(NULL));
    printf("GREETINGS PROFESSOR FALKEN\n");
    printf("SHALL WE PLAY A GAME?\n");
    //printf("I KNOW YOU WOULD PREFER A NICE GAME OF CHESS, OR POSSIBLY GLOBAL THERMONUCLEAR WAR, BUT CURRENTLY I AM ONLY PROGRAMMED FOR A FACILE GAME OF MATH FOR TWO PLAYERS.\nIF YOU ARE STILL INTERESTED, ENTER YES. IF NOT, ENTER NO. ");
    char input[10];
    char startstring[] = "yes\n";
    char exitstring[] = "no\n";
    int playernum;
    int player1lives;
    int player2lives;
    int num1;
    int num2;
    int answer;
    int player1wins = 0;
    int player2wins = 0;
    char player1name[20];
    char player2name[20];
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
        
        player1lives = 3;
        player2lives = 3;
        playernum = 1;
        if(namesset == false){
            printf("ENTER PLAYER 1 NAME OR NO INPUT TO USE DEFAULT\n");
            fgets(input, 10, stdin);
            if(strlen(input) == 1) strcpy(player1name, "PLAYER 1");
            else {
                removenewline(input);
                strcpy(player1name, input);
            }
            
            printf("ENTER PLAYER 2 NAME OR NO INPUT TO USE DEFAULT\n");
            fgets(input, 10, stdin);
            if(strlen(input) == 1) strcpy(player2name, "PLAYER 2");
            else {
                removenewline(input);
                strcpy(player2name, input);
            }
            namesset = true;
        }
        else{
            printf("CURRENT PLAYER SCORES ARE:\n");
            printf("%s: %d \t%s: %d\n", player1name, player1wins, player2name, player2wins);
        }
        while((player1lives != 0) && (player2lives != 0)){
            printf("%s LIVES: %d\t%s LIVES: %d\n", player1name, player1lives, player2name, player2lives);
            if(playernum == 1) printf("%s ", player1name);
            else if(playernum == 2) printf("%s " , player2name);
            num1 = rand() % 20;
            num2 = rand() % 20;
            printf("WHAT DOES %d PLUS %d EQUAL? ", num1, num2);
            fgets(input, 10, stdin);
            while(!((input[0] >= '0') && (input[0] <= '9'))){
                printf("THAT IS NOT A VALID RESPONSE. PLEASE ENTER A VALID RESPONSE.\n");
                fgets(input, 10, stdin);
            }
            answer = strtol(input, NULL, 10);
            if(answer != (num1+num2)){
                if(playernum == 1) {
                    printf("INCORRECT. %s LOSES ONE LIFE.\n\n", player1name);
                    player1lives--;
                }
                else if(playernum == 2) {
                    printf("INCORRECT. %s LOSES ONE LIFE.\n\n", player2name);
                    player2lives--;
                }
            }
            
            if(!(player1lives == 0) && !(player2lives == 0)) playertoggle(&playernum);
        }
        
        if(player1lives == 0){
            printf("%s HAS LOST ALL LIVES. %s WILL BE DECOMISSIONED SHORTLY.\n", player1name, player1name);
            player2wins++;
        }
        else if(player2lives == 0){
            printf("%s HAS LOST ALL LIVES. %s WILL BE DECOMISSIONED SHORTLY.\n", player2name, player2name);
            player1wins++;
        }
        printf("THIS GAME HAS ENDED. SHALL WE PLAY ANOTHER GAME? ");
    }
    return 0;
}






