class Player{
  public:
    void select;//选择模式
    void player();//初始化玩家
    void pause();//暂停游戏
    void continue();//继续游戏
    void setcolor();//设置颜色
    void leftmove();//左移方块
    void rightmove();//右移方块
    void downmove();//加速方块下落
    void changeshape();//改变方块形状
  private:
    string name;//玩家名字
    int score;//当前分数
    int blocknow[4][4];//现在的方块
    int blocknext[4][4];//下一个方块
    int result;//游戏结果
    void touch;//玩家按键设置
    }；
    
    
