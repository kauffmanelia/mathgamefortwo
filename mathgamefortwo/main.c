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
        while((player1lives != 0) && (player2lives != 0)){
            printf("PLAYER 1 LIVES: %d\tPLAYER 2 LIVES: %d\n", player1lives, player2lives);
            printf("PLAYER %d: ", playernum);
            num1 = rand() % 20;
            num2 = rand() % 20;
            printf("WHAT DOES %d PLUS %d EQUAL? ", num1, num2);
            fgets(input, 10, stdin);
            answer = strtol(input, NULL, 10);
            if(answer != (num1+num2)){
                printf("INCORRECT. PLAYER %d LOSES ONE LIFE.\n", playernum);
                if(playernum == 1) player1lives--;
                else if(playernum == 2) player2lives--;
            }
            
            if(!(player1lives == 0) && !(player2lives == 0)) playertoggle(&playernum);
        }
        
        printf("PLAYER %d HAS LOST ALL LIVES. PLAYER %d WILL BE DECOMISSIONED SHORTLY.\n", playernum, playernum);
        printf("THIS GAME HAS ENDED. SHALL WE PLAY ANOTHER GAME? ");
    }
    return 0;
}






