typedef struct Diamonds
{   int space[4][4];        //4*4矩阵，为1为方块，0为空
}Dia;
class block 
{
protected:
    Dia block[7][4];  //一维基础7个方块，二维表示4个旋转次数
    int temp[4][4];
public:
    void init_dia();
};
