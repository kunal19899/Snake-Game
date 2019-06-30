#include <iostream>
#include <ncurses.h>
#include <cstdlib>

bool gameOver;
const int width = 20, height = 20;
int x, y, Fx, Fy, score;
enum eDirection {STOP = 0, UP, LEFT, RIGHT, DOWN};
eDirection dir;
int Tx[100], Ty[100];
int nTail = 0;

void setup()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);

    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    Fx = (rand() % width) + 1;
    Fy = (rand() % height) + 1;
    score = 0;
}

void input()
{
    keypad(stdscr, TRUE);
    halfdelay(1); // the snake moves after pressing key once

    int c = getch();
    switch(c)
    {
        case KEY_LEFT: dir = LEFT; break;
        case KEY_RIGHT: dir = RIGHT; break;
        case KEY_UP: dir = UP; break;
        case KEY_DOWN: dir = DOWN; break;
        case 113: gameOver = true; break;
    }
}

void draw()
{
    clear();

    for (int i = 0; i < width + 2; i++)
    {
        mvprintw(0, i, "+");
    }

    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || i == 21)
            {
                mvprintw(i, j, "+");
            }
            else if (j == 0 || j == 21)
            {
                mvprintw(i, j, "+");
            }
            else if (i == y && j == x)
            {
                mvprintw(i, j, "0");
            }
            else if (i == Fy && j == Fx)
            {
                mvprintw(i, j, "@");
            }
            else{
                for (int k = 0; k < nTail; k++)
                {
                    if (Tx[k] == j && Ty[k] == i)
                    {
                        mvprintw(i, j, "o");
                        
                    }
                }
            }
        }
    }

    mvprintw(23, 0, "score = %d", score);
    refresh();
}

void logic()
{
    int Px;
    int Py;
    int P2x, P2y;

    Tx[0] = x;
    Ty[0] = y;
    Px = Tx[0];
    Py = Ty[0];

    for (int i = 0; i < nTail; i++)
    {
        P2x = Tx[i];
        P2y = Ty[i];

        Tx[i] = Px;
        Ty[i] = Py;

        Px = P2x;
        Py = P2y;
    }

    switch(dir)
    {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }

    if (x < 1 || x > width || y < 1 || y > height)
    {
        gameOver = true;
    }

    if (x == Fx && y == Fy)
    {
        score++;
        Fx = (rand()%width) + 1;
        Fy = (rand()%height) + 1;
        nTail++;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (Tx[i] == x && Ty[i] == y)
        {
            gameOver = true;
        }
    }
}

int main()
{
    setup();
    
     while(!gameOver)
     {
        draw();
        input();
        logic();
    }
    getch();
    endwin();

    return 0;
}
