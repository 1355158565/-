
#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include"draw.h"
using namespace std;

void draw::inter_face()  //界面
{
    int i, j;
    for (i = 0; i < 29; i++)
    {
        for (j = 0; j < 60; j++)
        {
            if (j == 0 || j == 19 || j == 29 || j == 30 || j == 49 || j == 59)
            {
                face.data[i][j] = 2;
                face1.data[i][j] = 2;
                gotoxy(i, 2 * j);
                cout << "■";
            }
            else if (i == 28)
            {
                face.data[i][j] = 1;
                face1.data[i][j] = 1;
                gotoxy(i, 2 * j);
                cout << "■";
            }
            else
            {
                face.data[i][j] = 0;
                face1.data[i][j] = 0;
            }
        }
    }
    gotoxy(11, 45);
    cout << "玩家1";

    gotoxy(13, 45);
    cout << "左移：A";

    gotoxy(15, 45);
    cout << "右移：D";

    gotoxy(17, 45);
    cout << "加速下落：S";

    gotoxy(19, 45);
    cout << "旋转：W";

    gotoxy(21, 45);
    cout << "退出: ESC";

    gotoxy(11, 104);
    cout << "玩家2";

    gotoxy(13, 104);
    cout << "左移: ←";

    gotoxy(15, 104);
    cout << "右移: →";

    gotoxy(17, 104);
    cout << "加速下落: ↓";

    gotoxy(19, 104);
    cout << "旋转: ↑";
}

void draw::gotoxy(int x, int y) //移动坐标
{
    COORD coord;
    coord.X = y;
    coord.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw::hidden()//隐藏光标
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut, &cci);
    cci.bVisible = 0;//赋1为显示，赋0为隐藏
    SetConsoleCursorInfo(hOut, &cci);
}

int draw::color(int ch)
{
    switch (ch)
    {
    case 0: ch = 9; break;
    case 1:
    case 2: ch = 12; break;
    case 3:
    case 4: ch = 14; break;
    case 5: ch = 10; break;
    case 6: ch = 13; break;
    default: ch = 7; break;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ch);        //更改文字颜色
    return 0;
}
