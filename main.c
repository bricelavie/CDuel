#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "defines.h"
#include "functions.h"

int main() {
    SetConsoleTitle("CDuel Client");
    int i;

    char title[] = "CDuel\n\t\t\t\t\t\t  Game by Brice LaVie\n\n\n\t\t\t\t\t\tPress enter to continue";
    center;
    for (i = 0; i < strlen(title); i++) {
        putchar(title[i]);
        wait(25);
    }

    _getch();
    clr;

    char instructions[] = "How to Play\n\n\t\t\t\t\tPlayer 1 turns with A and shoots with S\n\t\t\t\t\tPlayer 2 turns with L and shoots with K\n\n\t\t\t\t Whoever turns and shoots first after the countdown wins!";
    xy(54, 10);
    for (i = 0; i < strlen(instructions); i++) {
        putchar(instructions[i]);
        wait(5);
    }

    xy(1, 25);
    printf("Loading");

    for (i = 0; i < 110; i++) {
        xy(9 + i, 25);
        printf("/");
        wait(25);
    }

    wait(1000);
    clr;

    char start[] = "Press enter to start the game";
    xy(45, 10);
    for (i = 0; i < strlen(start); i++) {
        putchar(start[i]);
        wait(25);
    }

    _getch();
    clr;

    Start();

    return 0;
}
