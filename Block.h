  class Block{
       public:
            void rand();//随机生成方块
            void init_dia();//初始化方块信息
       private:
            int dia[10];//初始七种方块
            int block_1style_1[4][4];//田字形方块
            int block_2style_1[4][4];//左L
            int block_2style_2[4][4];//左L1
            int block_2style_3[4][4];//左L2
            int block_3style_1[4][4];//右L
            int block_3style_2[4][4];//右L1
            int block_3style_3[4][4];//右L2
            int block_4style_1[4][4];//土字形
            int block_4style_2[4][4];//土1
            int block_4style_3[4][4];//土2
            int block_4style_4[4][4];//土3
            int block_5style_1[4][4];//上Z字形
            int block_5style_2[4][4];//上Z1
            int block_6style_1[4][4];//下Z字形
            int block_6style_2[4][4];//下Z1
            int block_7style_1[4][4];//竖条
            int block_7style_2[4][4];//横条
            };
            
