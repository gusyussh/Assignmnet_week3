/*====================================
File name: exerc_3_1.c
Date: 2014‐02‐10
Group Number: 9
Members that contributed:
Shireen Yusur
Saulius Eidukas
Hristo Spilkov
Demonstration code: ?????
======================================*/

//  Created by Shireen Yusur on 09/02/14.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

/*=======================Struct=======================*/
enum dir{
    N, E, S,W
};


typedef struct{
    int xpos;
    int ypos;
    enum dir dir;
    
} ROBOT;


/*======================Functions passing a pointer=======================*/


void move(ROBOT *coordinates){
    switch (coordinates -> dir) {
            
        case N:
            coordinates->ypos++;
            break;
        case W:
            coordinates->xpos--;
            break;
        case S:
            coordinates->ypos--;
            break;
        case E:
            coordinates->xpos++;
            break;
        default:
            break;
    }
    
}

/* Get the address and change the direction*/
void turn(ROBOT *coordinates){
    switch (coordinates->dir) {
        case N:
            coordinates->dir = E;
            break;
        case E:
            coordinates->dir = S;
            break;
        case S:
            coordinates->dir = W;
            break;
        case W:
            coordinates->dir = N;
            break;
        default:
            break;
    }
    
    
}

/*======================Print_Functions=======================*/
// print
int coordinatesPrint(ROBOT *coordinates){
    
    printf("The coordinates point(x,y) are x = %i and  y = %i:\n", coordinates ->xpos,
           coordinates ->ypos);
    
    return 0;
    
}

/*======================Main=======================*/

int main(){
    
    // pointers to structures
    ROBOT * coordinates = malloc(sizeof(ROBOT));
    
    // declare
    int i;
    char  strings[MAX];
    int length;
    
    
    // prompot the user to enter X coordinate
    printf("Enter the coordinates  of X point:\n");
    scanf("%d", &coordinates->xpos);
    
    // prompot the user to enter Y coordinate
    printf("Enter the coordinates  of Y point:\n");
    scanf("%d", &coordinates->ypos);
    
    
    // prompot the user to enter string of characters
    printf("Enters strings of characters:\n");
    scanf("%s",strings);
    
    // store the lenght of string of characters
    length = strlen(strings);
   
    /*
    // for test
    printf("Your input %s\n", strings);
   printf("Length %i\n", length);
    
    */
    
    // check  the string of charaters are in the stored
    for(i = 0; i < length; i++){
        printf("%c \n", strings[i]);
        
        if (strings[i] == 'm') {
            
            // invoke the move function
            move(coordinates);
            
        }else if(strings[i] == 't'){
              // invoke the trun function
            turn(coordinates);
        } else{
            printf("Sorry there is no match\n");
            return 0;
        }
        
    }
    
    printf("%s\n", strings);
    
    // invoke a print function
    coordinatesPrint(coordinates);
    
    // free the memory
    free(coordinates);
    return 0;
}

