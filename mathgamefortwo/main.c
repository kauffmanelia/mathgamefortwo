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

int main(void){
    srand(time(NULL));
    printf("GREETINGS PROFESSOR FALKEN\n");
    printf("SHALL WE PLAY A GAME?\n");
    printf("I KNOW YOU WOULD PREFER A NICE GAME OF CHESS, OR POSSIBLY GLOBAL THERMONUCLEAR WAR, BUT CURRENTLY I AM ONLY PROGRAMMED FOR A FACILE GAME OF MATH FOR TWO PLAYERS.\nIF YOU ARE STILL INTERESTED, ENTER YES. IF NOT, ENTER NO.");
    char input[10];
    char startstring[] = "yes\n";
    char exitstring[] = "no\n";
    while(true){
        fgets(input, 10, stdin);
        if(strcmp(input, exitstring) == 0) break; // if 'no' is entered, exit
        else if(strcmp(input, startstring) != 0){
            printf("THAT IS NOT A VALID RESPONSE. PLEASE ENTER A VALID RESPONSE. ");
            continue;
        }
        
        
        
        printf("THIS GAME HAS ENDED. SHALL WE PLAY ANOTHER GAME? ");
    }
    return 0;
}
