struct Face
{
    int data[29][60];    //数值，为1是方块，为0是空格
    int color[29][60];   //对应方块的颜色
};

class draw {
protected:
	struct Face face;
	struct Face face1;
public:
	void gotoxy(int x, int y);  //移动光标
	int color(int c);   //颜色
	void hidden();  //隐藏光标
	void inter_face();  //初始化界面	
};
