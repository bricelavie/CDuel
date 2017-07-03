int allowed = 0;
int player1won = 0;
int player2won = 0;

void xy(int x, int y) {
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}

void Start() {
    int i;

    for (i = 0; i < 120; i++) {
        xy(0 + i, 15);
        printf("_");
        wait(5);
    }

    for (i = 0; i < 30; i++) {
        xy(61 + i, 14);
        printf(">");
        xy(59 - i, 14);
        printf("<");
        xy(60 + i, 14);
        printf(" ");
        xy(60 - i, 14);
        printf(" ");
        wait(25);
    }

    Game();
}

void Game() {
    char playerright[] = ">";
    char playerleft[] = "<";
    int x = 30;
    int player1shot = 0;
    char bullet[] = "-";
    int player1turned = 0;

    int x2 = 90;
    int player2shot = 0;
    int player2turned = 0;
    int i;

    xy(x, 14);
    printf(playerleft);

    xy(x2, 14);
    printf(playerright);

    xy(x, 15);

    wait(2000);

    countdown;
    allowed = 1;

    while (allowed == 1) {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a':
                xy(x, 14);
                printf(" ");
                xy(x + 1, 14);
                printf(playerright);
                player1turned = 1;
                break;
            case 'l':
                xy(x2, 14);
                printf(" ");
                xy(x2 - 1, 14);
                printf(playerleft);
                player2turned = 1;
                break;
            case 's':
                if (player2shot == 0 && player1turned == 1) {
                    player1shot = 1;
                    allowed = 0;
                    for (i = 0; i < (117 - x); i++) {
                        xy((x + 3)+ i, 14);
                        printf(bullet);
                        xy(x, 15);
                        wait(50);
                    }
                    player1won = 1;
                    Won();
                    break;
                }
                else {
                    break;
                }
            case 'k':
                if (player1shot == 0 && player2turned == 1) {
                    player2shot = 1;
                    allowed = 0;
                    for (i = 0; i < (x2 - 2); i++) {
                        xy((x2 - 3) - i, 14);
                        printf(bullet);
                        xy(x2, 15);
                        wait(50);
                    }
                    player2won = 1;
                    Won();
                    break;
                }
                else {
                    break;
                }
            }
        }
    }
}

void Won() {
    char say[50];

    if (player1won == 1) {
        clr;
        xy(53, 10);
        printf("Player 1 won!\n\n\n\t\t\t\t\t   What do you have to say? ");
        scanf("%s", &say);
        clr;
        player1won = 0;
    }
    else if (player2won == 1) {
        clr;
        xy(53, 10);
        printf("Player 2 won!\n\n\n\t\t\t\t\t   What do you have to say? ");
        scanf("%s", &say);
        clr;
        player2won = 0;
    }

    clr;
    xy(50, 10);
    char again[] = "Great job, rematch?";
    for (int i = 0; i < strlen(again); i++) {
        putchar(again[i]);
        wait(25);
    }
    wait(1000);
    clr;

    Start();
}
