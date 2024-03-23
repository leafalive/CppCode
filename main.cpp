#include <graphics.h>					//包含EGE的头文件
#include <stdio.h>
#include "map.cpp"
#include "check.cpp"
#include <time.h>

typedef struct key_msg {
	UINT msg;
	UINT key;
	UINT flags;
}key_msg;
int map_num[4][4] = { 0 };//布局
int k = 0;
int timer;
int rand_num_x;
int rand_num_y;
char str[32];
bool flag_newblock = 1;
int main() {

	draw_map();
	//check();
	initgraph(640, 480);

	//getch();							//暂停，等待键盘按键


	setfont(40, 0, "微软雅黑");
	outtextxy(0, 0, "please press any key");
	timer = time(NULL);

	rand_num_x = rand_num(map_num);
	rand_num_y = (rand() % 4 + 2) / 2 * 2;//随机生成数
	map_num[rand_num_x / 4][rand_num_x % 4] = rand_num_y;

	for (; k != key_esc; ) {
		k = getch();
		cleardevice();
		flag_newblock = check(map_num, k);
		if (k == 97) {//左移
			//outtextxy(0, 0, "left");
			left_m(map_num);
			
			for (int i = 0; i <= 3; i++) {
				for (int j = 0; j <= 3; j++) {
					sprintf(str, "%d", map_num[i][j]);
					outtextxy(100 + j * 50, 200 + i * 50, str);
				}
			}
		}
		else if (k == 100) {//右移
			//ttextxy(0, c, "right");
			right_m(map_num);
			
			for (int i = 0; i <= 3; i++) {
				for (int j = 0; j <= 3; j++) {
					sprintf(str, "%d", map_num[i][j]);
					outtextxy(100 + j * 50, 200 + i * 50, str);
				}
			}
		}
		else if (k == 119) {//上移
			//outtextxy(0, 0, "up");
			up_m(map_num);
			
			for (int i = 0; i <= 3; i++) {
				for (int j = 0; j <= 3; j++) {
					sprintf(str, "%d", map_num[i][j]);
					outtextxy(100 + j * 50, 200 + i * 50, str);
				}
			}
		}
		else if (k == 115) {//下移
			outtextxy(0, 0, "down");
			down_m(map_num);
			
			for (int i = 0; i <= 3; i++) {
				for (int j = 0; j <= 3; j++) {
					sprintf(str, "%d", map_num[i][j]);
					outtextxy(100 + j * 50, 200 + i * 50, str);
				}
			}
		}
		
		if (flag_newblock) {//无用操作不添加bolck
			rand_num_x = rand_num(map_num);
			rand_num_y = (rand() % 4 + 1) / 2 * 2;//随机生成数
			map_num[rand_num_x / 4][rand_num_x % 4] = rand_num_y;
		}
		for (int i = 0; i <= 3; i++) {
			for (int j = 0; j <= 3; j++) {
				sprintf(str, "%d", map_num[i][j]);                      //展示                                                                                                                                                                                                                                                                                                           
				outtextxy(100 + j * 50, 200 + i * 50, str);
			}
		}
		
	}
	closegraph();						//关闭图形界面

	return 0;
}