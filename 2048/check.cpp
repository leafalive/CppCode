//用户交互——键盘1
#include <graphics.h>

//这个例子需要这个头文件
#include <stdio.h>
#include <time.h>
int rand_num(int map_num[4][4]) {
	srand(time(0));
	while(1) {
		int cnt = rand() % 16 + 1;
		if (map_num[cnt / 4][cnt % 4] == 0)	return cnt;
	}
}
void left_m(int map_num[4][4]) {
	for (int i = 0; i <= 3; i++) {
		int cnt = 0;
		for (int j = 1; j <= 3; j++) {
			if (map_num[i][j] != 0) {
				if (map_num[i][cnt] == 0) {
					map_num[i][cnt] = map_num[i][j];
					map_num[i][j] = 0;
				}
				else {
					if (map_num[i][cnt] == map_num[i][j]) {//相同
						map_num[i][cnt] *= 2;
						map_num[i][j] = 0;
					}
					else {//不同
						int temp = map_num[i][j];
						map_num[i][j] = 0;
						map_num[i][cnt + 1] = temp;
						cnt++;
					}
				}
			}
		}
	}
}
void right_m(int map_num[4][4]) {
	for (int i = 0; i <= 3; i++) {
		int cnt = 3;
		for (int j = 2; j >= 0; j--) {
			if (map_num[i][j] != 0) {
				if (map_num[i][cnt] == 0) {
					map_num[i][cnt] = map_num[i][j];
					map_num[i][j] = 0;
				}
				else {
					if (map_num[i][cnt] == map_num[i][j]) {//相同
						map_num[i][cnt] *= 2;
						map_num[i][j] = 0;
					}
					else {//不同
						int temp = map_num[i][j];
						map_num[i][j] = 0;
						map_num[i][cnt - 1] = temp;
						cnt--;
					}
				}
			}
		}
	}
}
void up_m(int map_num[4][4]) {
	for (int i = 0; i <= 3; i++) {
		int cnt = 0;
		for (int j = 1; j <= 3; j++) {
			if (map_num[j][i] != 0) {
				if (map_num[cnt][i] == 0) {
					map_num[cnt][i] = map_num[j][i];
					map_num[j][i] = 0;
				}
				else {
					if (map_num[cnt][i] == map_num[j][i]) {//相同
						map_num[cnt][i] *= 2;
						map_num[j][i] = 0;
					}
					else {//不同
						int temp = map_num[j][i];
						map_num[j][i] = 0;
						map_num[cnt + 1][i] = temp;
						cnt++;
					}
				}
			}
		}
	}

}
void down_m(int map_num[4][4]) {
	for (int i = 0; i <= 3; i++) {
		int cnt = 3;
		for (int j = 2; j >= 0; j--) {
			if (map_num[j][i] != 0) {
				if (map_num[cnt][i] == 0) {
					map_num[cnt][i] = map_num[j][i];
					map_num[j][i] = 0;
				}
				else {
					if (map_num[cnt][i] == map_num[j][i]) {//相同
						map_num[cnt][i] *= 2;
						map_num[j][i] = 0;
					}
					else {//不同
						int temp = map_num[j][i];
						map_num[j][i] = 0;
						map_num[cnt - 1][i] = temp;
						cnt--;
					}
				}
			}
		}
	}
}
//寄
bool check(int map_num[4][4], int k) {//判断无用操作  
	int cnt = 0;
	int ch_num[4][4];
	for (int i = 0; i < 16; i++) {
		ch_num[i / 4][i % 4] = map_num[i / 4][i % 4];
	}
	if (k == 97) {
		left_m(ch_num);
	}
	else if (k == 100) {
		right_m(ch_num);
	}
	else if (k == 119) {
		up_m(ch_num);
	}
	else if (k == 115) {
		down_m(ch_num);
	}
	for (int i = 0; i < 16; i++) {
		if (ch_num[i / 4][i % 4] != map_num[i / 4][i % 4])	return 1;
	}
	return 0;
}