#include <graphics.h>
void draw_map() {
	initgraph(500, 580);				//��ʼ��ͼ�ν���

	//setcolor(EGERGB(0xFF, 0x0, 0x0));	���û滭��ɫΪ��ɫ
	//setfillcolor(EGERGB(0xBF, 0x99, 0x30));


	setbkcolor(EGERGB(0xFA, 0xF8, 0xEF));					//���ñ�����ɫΪ��ɫ

	setfillcolor(EGERGB(0xBB, 0xAD, 0xA0));  //��Χ����  ��ɫ
	fillellipse(60, 140, 5, 5);				//��ʵ��Բ
	fillellipse(440, 140, 5, 5);
	fillellipse(60, 530, 5, 5);
	fillellipse(440, 530, 5, 5);
	bar(60, 135, 440, 535);
	bar(55, 140, 445, 530);



	setfillcolor(EGERGB(0xCD, 0xC1, 0xB4)); //�ڲ�����  ǳ��ɫ
	//fillellipse(65, 145, 5, 5);				//��ʵ��Բ
	//fillellipse(435, 145, 5, 5);
	//fillellipse(65, 525, 5, 5);
	//fillellipse(435, 525, 5, 5);
	//bar(65, 140, 435, 530);
	//bar(60, 145, 440, 525);
	
	PIMAGE img;
	img = newimage();
	getimage(img, "D/code/c/ege_project/2048/resoure/mode_1_2.png");
	putimage(0, 0, img);
	//setfillcolor(EGERGB(0xCD, 0xC1, 0xB4));
	//fillellipse(65, 205, 5, 5);
	//fillellipse(135, 145, 5, 5);
	//fillellipse(135, 205, 5, 5);
	//bar(65, 140, 135, 210);
	//bar(60, 145, 140, 205);
	//img = newimage();
	//getimage(img, 60, 140, 150, 210);

	//for (int x = 0; x < 4; x++) {
	//	for (int y = 0; y < 4; y++) {
	//		putimage(60 + x * 90, 140 + y * 90,img);
	//	}
	//}
	//


	getch();							//��ͣ���ȴ����̰���

	closegraph();						//�ر�ͼ�ν���
}
void draw_number(int num) {
	switch (num) {
		case 0:

		case 1:

		case 2:

		case 3:

		case 6:

		case 4:

		case 8:

		default :
			;
	}

}