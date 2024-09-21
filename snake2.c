
//SNAKE GAME
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <conio.h>

int height = 20, width = 120;
int x, y, foodX, foodY;
int flag, gameEnd, Score;
int bodyX[100], bodyY[100];
int piece = 0;


void display(){
    char ch;
    printf("Let's play snake game!!!\n");
    printf("\n");

    printf("RULES:\n");
    printf("\n");
    printf("1. Snake can move within the boundary\n");
    printf("2. You can use the keys: \n   'u': upward movement\n   'd' : downward movement\n   'r' : right \n   'l' : left\n");
    printf("\n");
    printf("Press 'A' or 'a' to start the game\n");
    
    
    do{
       ch=getch();
    }

 while(ch !='A'&& ch!='a');


}
void moveSnake() {
    int i;
    int prevx, prevy, prev2x, prev2y;
    prevx = bodyX[0];
    prevy = bodyY[0];
    bodyX[0] = x;
    bodyY[0] = y;

    for (i = 1; i < piece; i++) {
        prev2x = bodyX[i];
        prev2y = bodyY[i];
        bodyX[i] = prevx;
        bodyY[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

    switch (flag) {
        case 1: x--; 
                break; // Up
        case 2: x++; 
                break; // Down
        case 3: y++; 
                break; // Right
        case 4: y--; 
                break; // Left
    }

    if (x == 0 || x == height || y == 0 || y == width) {
        gameEnd = 1;
    }

    if (x == foodX && y == foodY) {
        label3:
        foodX = rand() % height;
        if (foodX == 0) {
            goto label3;
        }
        
        label4:
        foodY = rand() % width;
        if (foodY == 0) {
            goto label4;
            }

        Score += 10;
        piece++;
    }
    printf("YOUR SCORE : %d\t",Score);
    printf("\n");
}

void inputKeys() {
    if (kbhit()) {
        switch (getch()) {
            case 'u': flag = 1; 
                      break; // Up
            case 'd': flag = 2; 
                      break; // Down
            case 'r': flag = 3; 
                      break; // Right
            case 'l': flag = 4; 
                      break; // Left
        }
    }
}

void arrangement() {
    x = height / 2;
    y = width / 2;

    label1:
    foodX = rand() % height;
    if (foodX == 0) goto label1;

    label2:
    foodY = rand() % width;
    if (foodY == 0) goto label2;

    gameEnd = 0;
    Score = 0;
    piece = 0;
}

void boundary() {
    system("cls");
    int i, j, k;
    for (i = 0; i <= height; i++) {
        for (j = 0; j <= width; j++) {
            if (i == 0 || i == height || j == 0 || j == width) {
                printf("*");
            } else {
                if (i == x && j == y) {
                    printf("O");
                } else if (i == foodX && j == foodY) {
                    printf("@");
                } else {
                    int print = 0; 
                    for (k = 0; k < piece; k++) {
                        if (i == bodyX[k] && j == bodyY[k]) {
                            printf("o");
                            print = 1; //represents body of the segment printed
                            break;
                        }
                    }
                    if (!print) {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
   
}

int main() {
    display();
    arrangement();
    while (!gameEnd) {
        boundary();
        inputKeys();
        moveSnake();
        Sleep(100); // Add delay to make the game playable
    }
    return 0;
}
