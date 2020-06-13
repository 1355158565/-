#include<bits/stdc++.h>
#include"block.h"
using namespace std;

void block::init_dia() 
{
    int i, j, k, z;
    for (i = 0; i < 3; i++)
        block[0][0].space[1][i] = 1;
    block[0][0].space[2][1] = 1;     //土形
    for (i = 1; i < 4; i++)
        block[1][0].space[i][1] = 1;
    block[1][0].space[1][2] = 1;    //L形--1
    for (i = 1; i < 4; i++)
        block[2][0].space[i][2] = 1;
    block[2][0].space[1][1] = 1;    //L形--2
    for (i = 0; i < 2; i++)
    {
        block[3][0].space[1][i] = 1;
        block[3][0].space[2][i + 1] = 1; //Z形--1

        block[4][0].space[1][i + 1] = 1;
        block[4][0].space[2][i] = 1;  //Z形--2

        block[5][0].space[1][i + 1] = 1;
        block[5][0].space[2][i + 1] = 1;  //田字形
    }
    for (i = 0; i < 4; i++)
        block[6][0].space[i][2] = 1;  //1形 
    //基础7个形状
    for (i = 0; i < 7; i++)
    {
        for (z = 0; z < 3; z++)
        {
            for (j = 0; j < 4; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    temp[j][k] = block[i][z].space[j][k];
                }
            }
            for (j = 0; j < 4; j++)
            {
                for (k = 0; k < 4; k++)
                {
                    block[i][z + 1].space[j][k] = temp[4 - k - 1][j];
                }
            }
        }
    } //旋转后的21个形状
}
