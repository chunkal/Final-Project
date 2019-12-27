#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include<iostream>
#define true 1
#define false 0

int puzzle();
void start(int *pPillar,int size);
void play(int *pPillar,int size);
void show(int *pPillar,int size);
char conversion(int temp);
bool endflag(int *pPillar,int size);
void gotoxy(int xpos, int ypos);

int snake_main();
int OOXX();
using namespace std;

int main (){
	
	int choice;
	
	do{
		system("CLS");
		printf("選擇遊戲\n\n");
		printf("1.益智遊戲\n\n");
		printf("2.貪吃蛇\n\n");
		printf("3.OOXX\n\n");
		printf("4.離開遊戲\n\n");
		scanf(" %c", &choice);
		
		switch (choice)
		{
		case '1':
			system("CLS");
			puzzle();
			break;
		case '2':
			system("CLS");
			snake_main();
			break;
		case '3':
			system("CLS");
			OOXX();
			break;
		case '4':
			break;
		}
	}while(choice != '4');
	system("CLS");
	printf("感謝遊玩\n\n");
	system("pause");
	return 0;
}

//益智遊戲------------------------------------------------- 

int puzzle()
{
	
	int size=8,Pillar[size];
	srand(time(NULL));
	start(Pillar,size);
	play(Pillar,size);
	printf("       YOU WIN!!\n\n");
	system("pause");
	system("CLS");
	return 0;
}


void start(int *pPillar,int size)
{
	int i;
	for(i=0;i<size;i++)
		pPillar[i]=rand()%2;
	printf("使用鍵盤旁的九宮格1,2,3,4,6,7,8,9對應圖形\n當按下目標鍵時其附近兩顆鍵目標鍵將會1和0轉換\n遊戲目的是將圖形全部改成1就獲勝!\n");		
	show(pPillar,size);
}


void play(int *pPillar,int size)
{
	char key;
	int i,temp;  
	key=getch();  //*1=49(0),*2=50(1),*3=51(2),4=52(5),6=54(7),*7=55(6),8=56(5),9=57(3) 
	for(i=-1;i<2;i++)
	{
		if(key>=49 && key<=57 && key!=53) temp=key-'1';
		else break;
		temp=(temp==3)?7+i:(temp==5)?3+i:(temp==7)?5+i:(temp==8)?4+i:temp+i;
		pPillar[(temp<0)?7:(temp>7)?0:temp]=!pPillar[(temp<0)?7:(temp>7)?0:temp];
	}
	show(pPillar,size); 	
	if(endflag(pPillar,size)!=1)	play(pPillar,size);
}


void show(int *pPillar,int size)
{
	int i;
	gotoxy(8,2); 
	printf("\n\n\t%c　%c　%c\n",conversion(pPillar[6]),conversion(pPillar[5]),conversion(pPillar[4]));
	printf("\t%c　　 %c\n",conversion(pPillar[7]),conversion(pPillar[3]));
	printf("\t%c　%c　%c\n\n",conversion(pPillar[0]),conversion(pPillar[1]),conversion(pPillar[2]));
}


char conversion(int temp)
{
	if (temp==1) return 'I';
	else return 'O';
}


bool endflag(int *pPillar,int size)
{
	int i,count=0;
	for(i=0;i<size;i++)
		(pPillar[i]==1)?count++:0;
	if(count==8) return 1;
	else return 0;
}


void gotoxy(int xpos, int ypos) //移動游標至指定位置 
{

	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

//益智遊戲-------------------------------------------------------------------------------------- 

//貪吃蛇---------------------------------------------------------------------------------------- 

void showCursor(int visible)
{

    CONSOLE_CURSOR_INFO ConCurInf;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleCursorInfo(hStdOut, &ConCurInf);

    ConCurInf.bVisible = visible;

    SetConsoleCursorInfo(hStdOut, &ConCurInf);

}


typedef struct snake
{

    int x;

    int y;

}Snake;


Snake sBody[1000]; // range = 20*50 = 1000


void printSnake(int i)
{

    gotoxy(sBody[i].x, sBody[i].y);

    printf("@");

}


void printWall()
{

    int i, j;

    for(i=0; i<20; i++){

        for(j=0; j<51; j+=2){

            if(i==0 || i==19 || j==0 || j==50){

                gotoxy(j, i);

                printf("*");

            }

        }

    }

}


void printInformation(int food, int speed)
{

    gotoxy(55, 3);

    printf("按 + 加增加蛇的速度");

    gotoxy(55, 5);

    printf("按 - 減少蛇的速度");


    gotoxy(55, 7);

    printf("按 P 暫停");

    gotoxy(55, 9);

    printf("分數: %d", food * 100);

    gotoxy(55, 11);

    if(speed == 10) {
    	printf("速度 %3d  (The fastest)", 310-speed);
	}
    else if(speed == 300){
    	printf("速度: %3d (The slowest)", 310-speed);
	} 
    else {
    	printf("速度: %3d              ", 310-speed);
	}

}


void setSite(int i, int site_x, int site_y)
{

    sBody[i].x = site_x;

    sBody[i].y = site_y;

}


void setStartSite()
{

    int i;

    sBody[0].x = sBody[1].x = sBody[2].x = sBody[3].x = sBody[4].x = 1;

    for(i=0; i<5; i++) sBody[i].y = abs(5 - i);

}


int snake_main()
{
    int startBodyLenght = 5, startEatenFood = 0, bodyLenght, eatenFood;

    int keyinFirst, keyinSecond;

    int i, j, gameOver = false, isFoodEaten = false, xyChanged = false;

    int path = 2; // 方向

    int snakeSpeed = 100;

    char gameKey = 'y';

    Snake foodSite, coor, last;



    srand(time(NULL));

    showCursor(0);

    while(1){

        if(gameKey == 'n' || gameKey == 'N') break;

        // 初始狀態

        setStartSite();

        printWall();

        bodyLenght = startBodyLenght;

        eatenFood= startEatenFood;

        coor.x = 1;

        coor.y = 4;

        path = 2;

        isFoodEaten = false;

        gameOver = false;

        xyChanged = false;

        snakeSpeed = 100;

        printInformation(startEatenFood, snakeSpeed);

        for(i=0; i<bodyLenght; i++)

            printSnake(i);



        do{

            gotoxy(55, 13);

            printf("按 Enter 開始遊戲");

            gameKey = getch();

            gotoxy(55, 13);

            printf("                            ");

        }while(gameKey != 13);



        while( !gameOver ){

            printInformation(eatenFood, snakeSpeed);

            if( !isFoodEaten ){ // 如果沒食物, 隨機算出一個食物的位置

                foodSite.x = (rand()%23*2+1)+2;

                foodSite.y = rand()%17+2;

                isFoodEaten = true;

            }

            gotoxy(foodSite.x, foodSite.y);

            printf("O");

            xyChanged = false;

  

            if( kbhit() ){ // 鍵盤敲擊

                keyinFirst = getch();

                if(keyinFirst == 224) {

                    keyinSecond = getch();

                    switch(keyinSecond){

                        case 72: /* up, 1 */

                            coor.y--;

                            path = 1;

                            break;

                        case 80: /* down, 2 */

                            coor.y++;

                            path = 2;

                            break;

                        case 75: /* left, 3 */

                            coor.x-=2;

                            path = 3;

                            break;

                        case 77: /* right, 4 */

                            coor.x+=2;

                            path = 4;

                            break;

                    }

                    xyChanged = true;

                }

                if(keyinFirst == 'p' || keyinFirst == 'P'){

                    do{

                        gotoxy(55, 13);

                        printf("Pause.");

                        gameKey = getch();

                        gotoxy(55, 13);

                        printf("          ");

                    }while(gameKey != 'p' && gameKey != 'P');

                }

                if(keyinFirst == '+'){

                    if(snakeSpeed > 10) snakeSpeed -= 10;

                        keyinFirst = '\0';

                }

                if(keyinFirst == '-'){

                    if(snakeSpeed < 300) snakeSpeed += 10;

                        keyinFirst = '\0';

                }

  

            } else { // 沒有任何動作則順著path(方向)前進

                switch(path){

                    case 1: /* up, 1 */

                        coor.y--;

                        path = 1;

                        break;

                    case 2: /* down, 2 */

                        coor.y++;

                        path = 2;

                        break;

                    case 3: /* left, 3 */

                        coor.x-=2;

                        path = 3;

                        break;

                    case 4: /* right, 4 */

                        coor.x+=2;

                        path = 4;

                        break;

                    }

                    xyChanged = true;

                }

                for(i=1; i<bodyLenght; i++){ /* Did snake die? */

                    if(coor.x == sBody[i].x && coor.y == sBody[i].y)

                        gameOver = true;

                }

                if(gameOver == 0 && xyChanged == 1){ /* Snake moving */

                    if(coor.x>0 && coor.x<50 && coor.y>0 && coor.y<19){

                        last.x = sBody[bodyLenght-1].x;

                        last.y = sBody[bodyLenght-1].y;

                        for(i=bodyLenght-1; i>=0; i--){

                            if(i == 0)

                                setSite(i, coor.x, coor.y);

                            else

                                setSite(i, sBody[i-1].x, sBody[i-1].y);

                    }

                    for(i=0; i<bodyLenght; i++){

                        printSnake(i);

                    }

                    Sleep(snakeSpeed);

                    gotoxy(last.x, last.y); // 清尾巴

                    printf(" ");

                }

                else gameOver = true;

              

                if(sBody[0].x == foodSite.x && sBody[0].y == foodSite.y){ /* Snake ate food */

                    isFoodEaten = false;

                    if(bodyLenght<1000) bodyLenght++; // 避免蛇身超出陣列長度

                    eatenFood++;

                }

            }

        }

        /* Game over ? */

       

            system("CLS");

            printf("你的分數: %d\n", eatenFood* 100); 
			system("pause");
           
            break;

    }


    system("CLS");
    return 0;

}

//貪吃蛇---------------------------------------------------------------------------------------- 

//OOXX--------------------------------------------------------------------------------------

bool winner(char map[3][3]){
    for(int i=0;i<3;i++) if(map[i][0]!=' '&&map[i][0]==map[i][1]&&map[i][1]==map[i][2]) return true;//列勝利判斷
    for(int i=0;i<3;i++) if(map[0][i]!=' '&&map[0][i]==map[1][i]&&map[1][i]==map[2][i]) return true;//行勝利判斷
    if(map[0][0]!=' '&&map[0][0]==map[1][1]&&map[1][1]==map[2][2]) return true;//左上右下斜勝利判斷
    if(map[0][2]!=' '&&map[0][2]==map[1][1]&&map[1][1]==map[2][0]) return true;//右上左下斜勝利判斷
    return false;//如果沒有勝利出現
}
/*判斷是否能在這個位置放置棋子*/
bool TFset(char Player,int Switch,char map[3][3]){
/*第一列 判斷*/
    if(Switch==7&&map[0][0]==' '){map[0][0]=Player; return true;}
    else if(Switch==8&&map[0][1]==' '){map[0][1]=Player; return true;}
    else if(Switch==9&&map[0][2]==' '){map[0][2]=Player; return true;}
/*第二列 判斷*/
    else if(Switch==4&&map[1][0]==' '){map[1][0]=Player; return true;}
    else if(Switch==5&&map[1][1]==' '){map[1][1]=Player; return true;}
    else if(Switch==6&&map[1][2]==' '){map[1][2]=Player; return true;}
/*第三列 判斷*/
    else if(Switch==1&&map[2][0]==' '){map[2][0]=Player; return true;}
    else if(Switch==2&&map[2][1]==' '){map[2][1]=Player; return true;}
    else if(Switch==3&&map[2][2]==' '){map[2][2]=Player; return true;}
/*錯誤提示*/
    else{ cout<<"按錯了啦 蛤啊你是目洨膩？"<<endl; return false;}
}
/*顯示閘*/
void show(char map[3][3]){
    for(int i=0;i<3;i++){
        cout<<" －－－－－－－－－"<<endl;
        for(int j=0;j<3;j++) { cout<<"|  "<<map[i][j]<<"  "; } cout<<"|"<<endl;
    }cout<<" －－－－－－－－－"<<endl;
}

int OOXX(){
    char map[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};    //空地圖
    char Player='O';                                               //第一顆棋子為O  
    int Switch;                                                    //按下的數字鍵控制項
    
    show(map);													   //地圖顯示
    while(1){												       //遊戲無限迴圈
        cout<<"（按０退出，數字鍵比照九宮格）"<<endl;
        cin>>Switch;
        if(Switch==0) break;									   //如果輸入0，結束迴圈
        
        system("CLS");                                             //清除畫面的系統字
        bool TFSet=TFset(Player, Switch, map);					   //判斷是否能夠放置棋子，並放進棋子
        show(map);								   				   //更新地圖顯示
    /*判斷是否有玩家獲勝*/
        if(winner(map)==true){									   //如果獲勝，輸出地圖與獲勝提示後結束迴圈
            cout<<Player<<" 贏了。\n";
            break;                    
        }
    /*判斷是否滿圖*/
        bool mapover=true;
        for(int i=0;i<3;i++)									   //搜尋全地圖
            for(int j=0;j<3;j++)
                if(map[i][j]==' ') mapover=false;				   //只要有一個是空的，地圖就不為滿  
                
        if(mapover==true){										   //如果滿圖，輸出滿圖提示後結束迴圈
            cout<<"滿圖，不分勝負。\n";
            break;
        }
    /*迴圈繼續，更替棋子*/
        if(TFSet==true){										   //如果方才放入棋子的選項有正常執行
            if(Player=='O') Player='X';						       //更替棋子
            else Player='O';            
        }
    }
    system("pause");
    return 0;
}

//OOXX--------------------------------------------------------------------------------------







