#include <iostream>
#include <vector>
#include <windows.h>
#include<conio.h>

using namespace std;

class Snake;
class Food;

class Board
{
    char **board;
    int row,cols;
public:
    Board()
    {
        cin >> row;
        cin >> cols;
        board = new char*[row];
        for(int i=0;i<row;i++)
        {
            board[i] = new char[cols];
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(i==0 || j==0 || i==(row-1) || j==(cols-1))
                {
                    board[i][j] = '#';
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
        }
    }
    void show()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    friend class Snake;
};

class Food
{
    int x,y;
    char value;
public:
    Food()
    {
        x=10;
        y=10;
        value='F';
    }
    void generateFood(vector<int> x, vector<int> y)
    {
        while(true)
        {
            this->x = rand()%19;
            this->y = rand()%19;
            for(int i=0;i<x.size();i++)
            {
                if(this->x==x[i] || this->y==y[i] || this->x==0 || this->y==0)
                {
                    continue;
                }
                return;
            }
        }
    }
    friend class Snake;
};

class Snake
{
    vector<int> x,y;
    Food food;
    int flag;
    int dx,dy;
    char dir;
public:
    Board board;
    Snake()
    {
        dir = 'w';
        board.board[5][5]='O';
        board.board[food.x][food.y]=food.value;
        x.push_back(5);
        y.push_back(5);
    }

    void moveSnake()//out condition    //move
    {
        int dupx=x[0],dupy=y[0];
        char dup;
        if(kbhit())
        {
            dup=dir;
            dir = getch();
            /*if(dir!='w' && dir!='a' && dir!='d' && dir!='s')
            {
                dir=dup;
            }*/
        }
        board.board[x[0]][y[0]]=' ';
        if(dir=='w')
        {
            if(--x[0]==0)
            {
                x[0] = board.row-2;
            }
        }
        else if(dir=='a')
        {
            if(--y[0]==0)
            {
                y[0] = board.cols-2;
            }
        }
        else if(dir=='s')
        {
            if(++x[0]>(board.row-2))
            {
                x[0] = 1;
            }
        }
        else if(dir=='d')
        {
            if(++y[0]>(board.cols-2))
            {
                y[0] = 1;
            }
        }
        else{
            system("pause");
            dir=dup;
        }
        for(int i=1;i<x.size();i++)
        {
            board.board[x[i]][y[i]]=' ';
            int X = x[i];
            int Y = y[i];
            x[i] = dupx;
            y[i] = dupy;
            dupx=X;
            dupy=Y;
            board.board[x[i]][y[i]]='*';
        }
        board.board[x[0]][y[0]]='O';
    }
    void eatFood()
    {
        if(x[0]==food.x && y[0]==food.y)
        {
            flag=1;
            x.push_back(x[0]);
            y.push_back(y[0]);
            board.board[x[0]][y[0]]='*';
            board.board[food.x][food.y]=' ';
            food.generateFood(x,y);
            board.board[food.x][food.y]=food.value;
        }
    }
    friend class Food;
};

int main()
{
    Snake snake;
    while(true)
    {
        snake.board.show();
        snake.eatFood();
        snake.moveSnake();
        Sleep(100);
        system("cls");
    }
    return 0;
}
