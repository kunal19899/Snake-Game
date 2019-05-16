#include <iostream>


using namespace std;

bool GameOver;
const int width = 20;
const int height = 20;
int x, y, mouseX, mouseY, score;
char char_input;

enum Direction {
    STOP = 0, LEFT, RIGHT, UP, DOWN
};

Direction direction;

void setup()
{
    GameOver = false;
    direction = STOP; 
    x = width/2;
    y = height/2;
    mouseX = rand()%width;
    mouseY = rand()%height;
    score = 0;
}

void draw()
{
    system("clear");
    for (int i = 0; i < width+1; i++)
    {
        cout << "#";
    }

    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j==0)
            {
                cout << "#";
            }

            if (i==y && j == x)
            {
                cout << "O";
            }
            else if (i == mouseX && j == mouseY)
            {
                cout << "M";
            }
            else
            {
                cout << " ";
            }

            if (j == width-1)
            {
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width+1; i++)
    {
        cout << "#";
    }

    cout << endl;
}

void input()
{
    if (char_input == 'a' || char_input == 'A')
    {
        direction = LEFT;
    }

    if (char_input == 's' || char_input == 'S')
    {
        direction = DOWN;
    }

    if (char_input == 'd' || char_input == 'D')
    {
        direction = RIGHT;
    }

    if (char_input == 'w' || char_input == 'W')
    {
        direction = UP;
    }
    /*if (1)
    {
        switch ()
        {
            case 'a':
                direction = LEFT;
                break;
            case 'd':
                direction = RIGHT;
                break;
            case 'w':
                direction = UP;
                break;
            case 's':
                direction = DOWN;
                break;
            case 'x':
                GameOver = true;
                break;
        }
    }*/
}

void logic()
{
    if (a_Pressed)
    {
        x--;
    }
    else if (s_Pressed){
        y--;
    }
    else if (d_Pressed)
    {
        x++;
    }
    else if (w_Pressed)
    {
        y++;
    }
}

int main()
{
    setup();
    while (!GameOver)
    {
        draw();
        input();
        logic();
    }

    return 0;
}