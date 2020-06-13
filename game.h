#include"block.h"
#include"draw.h"
class game :public block, public draw 
{
protected:
    int space_c;//旋转次数
    int nn;
    int space_c1; 
    int nnn;
public:
    game(int v, int vv);
    void start_game1(); //开始游戏
    void start_game2();
    int xc();
    int xc1();
    int pd(int n, int space_c, int x, int y); //消除
    int pd1(int n, int space_c, int x, int y);
    void draw_kong(int base, int space_c, int a, int b); //画空方块
    void draw_block(int base, int space_c, int a, int b); //画方块
    void addline(struct Face* t); //增加垃圾行
    void addline1(struct Face* t);
};
