class Game{
  public:
    void YNmove();//检测方块是否可以移动，与别的方块或者界面的碰撞
    int xc();//消除，并加分
    void addblock();//增加一行带空格的方块
    int pd();//判断是否到底
    void restartgame();//将分数清零，胜方胜场加一
  private:
};
