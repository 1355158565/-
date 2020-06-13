#include<bits/stdc++.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include "game.h"
#include "draw.h"
using namespace std;

game::game(int v, int vv) :nn(v), nnn(vv)
{
    space_c = 0;
    space_c1 = 0;
}

void game::start_game1()
{
    int n, ch, t = 0, x = 0, y = 8, i, j;
    draw_kong(nn, 0, 4, 23);
    n = nn;
    nn = rand() % 7;    //随机生成下一块
    color(nn);
    draw_block(nn, 0, 4, 23);
    while (1)
    {
        color(n);
        draw_block(n, space_c, x, y);//画出图形
        if (t == 0)
            t = 10000;//控制下降时间
        while (--t)
        {
            if (kbhit() != 0)//有输入就跳出
                break;
        }
        if (t == 0)
        {
            if (pd(n, space_c, x + 1, y) == 1)//判断下一行是否能下降
            {
                draw_kong(n, space_c, x, y);
                x++;            //向下降落
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        if (block[n][space_c].space[i][j] == 1)
                        {
                            face.data[x + i][y + j] = 1;
                            face.color[x + i][y + j] = n;
                            while (xc());
                        }
                    }
                }
                break;
            }
        }
        else
        {
            ch = getch();
            switch (ch)     //移动
            {
            case 'a': if (pd(n, space_c, x, y - 1) == 1)   //判断是否可以移动
            {
                draw_kong(n, space_c, x, y);
                y--;
            }
                    break;
            case 'd': if (pd(n, space_c, x, y + 1) == 1)
            {
                draw_kong(n, space_c, x, y);
                y++;
            }
                    break;
            case 's': if (pd(n, space_c, x + 1, y) == 1)
            {
                draw_kong(n, space_c, x, y);
                x++;
            }
                    break;
            case 'w': if (pd(n, (space_c + 1) % 4, x + 1, y) == 1)
            {
                draw_kong(n, space_c, x, y);
                space_c = (space_c + 1) % 4;
            }
                    break;
            case 27:   system("cls");
                gotoxy(29 / 2, 45);
                printf("---游戏结束!---\n\n");
                gotoxy(29 / 2 + 2, 45);
                printf("---按任意键退出!---\n");
                getch();
                exit(0);
                break;
            }
        }
    }
}

void game::start_game2()
{
    int n, ch, t = 0, x = 0, y = 38, i, j;
    draw_kong(nnn, 0, 4, 53);
    n = nnn;
    nnn = rand() % 7;    //随机生成下一块
    color(nnn);
    draw_block(nnn, 0, 4, 53);
    while (1)
    {
        color(n);
        draw_block(n, space_c1, x, y);//画出图形
        if (t == 0)
            t = 10000;//控制下降时间
        while (--t)
        {
            if (kbhit() != 0)//有输入就跳出
                break;
        }
        if (t == 0)
        {
            if (pd1(n, space_c1, x + 1, y) == 1)//判断下一行是否能下降
            {
                draw_kong(n, space_c1, x, y);
                x++;            //向下降落
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        if (block[n][space_c1].space[i][j] == 1)
                        {
                            face1.data[x + i][y + j] = 1;
                            face1.color[x + i][y + j] = n;
                            while (xc1());
                        }
                    }
                }
                break;
            }
        }
        else
        {
            ch = getch();
            switch (ch)     //移动
            {
            case 75: if (pd1(n, space_c1, x, y - 1) == 1)   //判断是否可以移动
            {
                draw_kong(n, space_c1, x, y);
                y--;
            }
                   break;
            case 77: if (pd1(n, space_c1, x, y + 1) == 1)
            {
                draw_kong(n, space_c1, x, y);
                y++;
            }
                   break;
            case 80: if (pd1(n, space_c1, x + 1, y) == 1)
            {
                draw_kong(n, space_c1, x, y);
                x++;
            }
                   break;
            case 72: if (pd1(n, (space_c1 + 1) % 4, x + 1, y) == 1)
            {
                draw_kong(n, space_c1, x, y);
                space_c1 = (space_c1 + 1) % 4;
            }
                   break;
            case 27:   system("cls");
                gotoxy(29 / 2, 45);
                printf("---游戏结束!---\n\n");
                gotoxy(29 / 2 + 2, 45);
                printf("---按任意键退出!---\n");
                getch();
                exit(0);
                break;
            }
        }
    }
}

//消除
int game::xc()  
{
    int i, j, k, sum;
    for (i = 27; i > 4; i--)
    {
        sum = 0;
        for (j = 1; j < 19; j++)
        {
            sum += face.data[i][j];
        }
        if (sum == 0)
            break;
        if (sum == 18)   //满一行，减掉
        {
            color(8);
            for (j = 1; j < 19; j++)
            {
                face.data[i][j] = 0;
                gotoxy(i, 2 * j);
                cout << " ";
            }
            generate1(&face1);
            for (j = i; j > 1; j--)
            {
                sum = 0;
                for (k = 1; k < 19; k++)
                {
                    sum += face.data[j - 1][k] + face.data[j][k];
                    face.data[j][k] = face.data[j - 1][k];
                    if (face.data[j][k] == 0)
                    {
                        gotoxy(j, 2 * k);
                        cout << "  ";
                    }
                    else
                    {
                        gotoxy(j, 2 * k);
                        color(face.color[j][k]);
                        cout << "■";  //消除之后剩余的方块
                    }
                }
                if (sum == 0)
                    return 1;
            }
        }
    }
    for (i = 1; i < 19; i++)
    {
        if (face.data[1][i] == 1)
        {
            char n;
            Sleep(10);  //延时判断到顶
            system("cls");
            color(7);
            gotoxy(29 / 2, 50);
            cout << "傻妞胜利!!" << endl;
            exit(0);
        }
    }
    return 0;
}

//消除
int game::xc1()  
{
    int i, j, k, sum;
    for (i = 27; i > 4; i--)
    {
        sum = 0;
        for (j = 31; j < 49; j++)
        {
            sum += face1.data[i][j];
        }
        if (sum == 0)
            break;
        if (sum == 18)  //满一行，减掉
        {
            color(8);
            for (j = 31; j < 49; j++)
            {
                face1.data[i][j] = 0;
                gotoxy(i, 2 * j);
                cout << "  ";
            }
            generate(&face);
            for (j = i; j > 1; j--)
            {
                sum = 0;
                for (k = 31; k < 49; k++)
                {
                    sum += face1.data[j - 1][k] + face1.data[j][k];
                    face1.data[j][k] = face1.data[j - 1][k];
                    if (face1.data[j][k] == 0)
                    {
                        gotoxy(j, 2 * k);
                        cout << "  ";
                    }
                    else
                    {
                        gotoxy(j, 2 * k);
                        color(face1.color[j][k]);
                        cout << "■";  //消除之后剩余的方块
                    }
                }
                if (sum == 0)
                    return 1;
            }
        }
    }
    for (i = 31; i < 49; i++)
    {
        if (face1.data[1][i] == 1)
        {
            char n;
            Sleep(10);  //延时判断到顶
            system("cls");
            color(7);
            gotoxy(29 / 2, 50);
            cout << "傻der胜利!!" << endl;
            exit(0);
        }
    }
    return 0;
}

void game::addline(struct Face* t) {
    int i, j;
    for (i = 1; i <= 27; i++)  //将整体画布坐标上移
    {
        for (j = 1; j < 19; j++)
        {
            t->data[i - 1][j] = t->data[i][j];
        }
    }
    for (i = 0; i <= 27; i++)  //将全部方块都清空
    {
        for (j = 1; j < 19; j++)
        {
            gotoxy(i, j * 2);
            cout << " ";
            gotoxy(i, j * 2 + 1);
            cout << " ";
        }
    }
    srand(time(NULL));   //根据不同时间生成不同的种子
    int deadline = rand() % 17 + 8;  //随机产生生成行的方块数
    for (i = 1; i <= 18; i++)
        t->data[27][i] = 0;
    for (i = 1; i <= deadline; i++) {
        int k = rand() % 18 + 1;
        if (t->data[27][k] == 0) {
            t->data[27][k] += 1;
            t->color[27][k] = 0;
        }
    }
    for (i = 0; i <= 27; i++)  //重新画画布 
    {
        for (j = 1; j < 19; j++)
        {
            if (t->data[i][j] == 1)
            {
                gotoxy(i, j * 2);
                color(t->color[i][j]);
                cout << "■";
            }
            else
            {
                gotoxy(i, j * 2);
                cout << "  ";
            }
        }
    }
}

void game::addline1(struct Face* t) {
    int i, j;
    for (i = 1; i <= 27; i++)  //将整体画布坐标上移
    {
        for (j = 32; j < 49; j++)
        {
            t->data[i - 1][j] = t->data[i][j];
        }
    }
    for (i = 0; i <= 27; i++)  //将全部方块都清空
    {
        for (j = 32; j < 49; j++)
        {
            gotoxy(i, j * 2);
            cout << " ";
            gotoxy(i, j * 2 + 1);
            cout << " ";
        }
    }
    srand(time(NULL));  //根据不同时间生成不同的种子
    int deadline = rand() % 17 + 8;  //随机产生生成行的方块数
    for (i = 32; i < 49; i++)
        t->data[27][i] = 0;
    for (i = 1; i <= deadline; i++) {
        int k = rand() % 49 + 32;
        if (t->data[27][k] == 0) {
            t->data[27][k] += 1;
            t->color[27][k] = 0;
        }
    }
    for (i = 0; i <= 27; i++)  //重新画画布 
    {
        for (j = 32; j < 49; j++)
        {
            if (t->data[i][j] == 1)
            {
                gotoxy(i, j * 2);
                color(t->color[i][j]);
                cout << "■";
            }
            else
            {
                gotoxy(i, j * 2);
                cout << "  ";
            }
        }
    }
}

int game::pd(int n, int space_c, int x, int y)  //判断能否继续向下
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (block[n][space_c].space[i][j] == 0)
                continue;
            else if (face.data[x + i][y + j] == 2 || face.data[x + i][y + j] == 1)
                return 0;
        }
    }
    return 1;
}

int game::pd1(int n, int space_c, int x, int y)  //判断能否继续向下
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (block[n][space_c].space[i][j] == 0)
                continue;
            else if (face1.data[x + i][y + j] == 2 || face1.data[x + i][y + j] == 1)
                return 0;
        }
    }
    return 1;
}

void game::draw_kong(int base, int space_c, int x, int y)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            gotoxy(x + i, 2 * (y + j));
            if (block[base][space_c].space[i][j] == 1)
                cout << "  ";
        }
    }
}

void game::draw_block(int base, int space_c, int x, int y)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            gotoxy(x + i, 2 * (y + j));
            if (block[base][space_c].space[i][j] == 1)
                cout << "■";
        }
    }
}
