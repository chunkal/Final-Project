#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
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
int password();


int main (){
	
	int choice;
	
	do{
		system("CLS");
		printf("��ܹC��\n\n");
		printf("1.�q���C��\n\n");
		printf("2.�g�Y�D\n\n");
		printf("3.�׷��K�X\n\n");
		printf("4.���}�C��\n\n");
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
			password();
			break;
		case '4':
			break;
		}
	}while(choice != '4');
	system("CLS");
	printf("�P�¹C��\n\n");
	system("pause");
	return 0;
}

//�q���C��------------------------------------------------- 

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
	printf("�ϥ���L�Ǫ��E�c��1,2,3,4,6,7,8,9�����ϧ�\n����U�ؼ���ɨ���������ؼ���N�|1�M0�ഫ\n�C���ت��O�N�ϧΥ����令1�N���!\n");		
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
	printf("\n\n\t%c�@%c�@%c\n",conversion(pPillar[6]),conversion(pPillar[5]),conversion(pPillar[4]));
	printf("\t%c�@�@ %c\n",conversion(pPillar[7]),conversion(pPillar[3]));
	printf("\t%c�@%c�@%c\n\n",conversion(pPillar[0]),conversion(pPillar[1]),conversion(pPillar[2]));
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


void gotoxy(int xpos, int ypos) //���ʴ�Цܫ��w��m 
{

	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

//�q���C��-------------------------------------------------------------------------------------- 

//�g�Y�D---------------------------------------------------------------------------------------- 

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

    printf("�� + �[�W�[�D���t��");

    gotoxy(55, 5);

    printf("�� - ��ֳD���t��");


    gotoxy(55, 7);

    printf("�� P �Ȱ�");

    gotoxy(55, 9);

    printf("����: %d", food * 100);

    gotoxy(55, 11);

    if(speed == 10) {
    	printf("�t�� %3d  (The fastest)", 310-speed);
	}
    else if(speed == 300){
    	printf("�t��: %3d (The slowest)", 310-speed);
	} 
    else {
    	printf("�t��: %3d              ", 310-speed);
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

    int path = 2; // ��V

    int snakeSpeed = 100;

    char gameKey = 'y';

    Snake foodSite, coor, last;



    srand(time(NULL));

    showCursor(0);

    while(1){

        if(gameKey == 'n' || gameKey == 'N') break;

        // ��l���A

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

            printf("�� Enter �}�l�C��");

            gameKey = getch();

            gotoxy(55, 13);

            printf("                            ");

        }while(gameKey != 13);



        while( !gameOver ){

            printInformation(eatenFood, snakeSpeed);

            if( !isFoodEaten ){ // �p�G�S����, �H����X�@�ӭ�������m

                foodSite.x = (rand()%23*2+1)+2;

                foodSite.y = rand()%17+2;

                isFoodEaten = true;

            }

            gotoxy(foodSite.x, foodSite.y);

            printf("O");

            xyChanged = false;

  

            if( kbhit() ){ // ��L�V��

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

  

            } else { // �S������ʧ@�h����path(��V)�e�i

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

                    gotoxy(last.x, last.y); // �M����

                    printf(" ");

                }

                else gameOver = true;

              

                if(sBody[0].x == foodSite.x && sBody[0].y == foodSite.y){ /* Snake ate food */

                    isFoodEaten = false;

                    if(bodyLenght<1000) bodyLenght++; // �קK�D���W�X�}�C����

                    eatenFood++;

                }

            }

        }

        /* Game over ? */

       

            system("CLS");

            printf("�A������: %d\n", eatenFood* 100); 
			system("pause");
           
            break;

    }


    system("CLS");
    return 0;

}

//�g�Y�D---------------------------------------------------------------------------------------- 

//�׷��K�X--------------------------------------------------------------------------------------

int password()
{
	int seed, guess, lower = 1, higher = 100, frequency=1;
	srand(time(NULL));
	do
	{
		seed = rand() % 101;
	} while (seed == 0);
	printf("��J %d~%d ���Ʀr\n", lower, higher); scanf("%d", &guess);
	do
	{
		if (lower <guess && guess<seed)
		{
			lower = guess;
			printf("��J %d~%d ���Ʀr   ����=>%d��\n", lower, higher, frequency); scanf("%d", &guess);
			frequency++;
		}
		else if (guess>seed && higher>guess)
		{
			higher = guess;
			printf("��J %d~%d ���Ʀr   ����=>%d��\n", lower, higher, frequency); scanf("%d", &guess);
			frequency++;
		}
		else
		{
			printf("%d ���O %d~%d ���Ʀr\n",guess, lower, higher); scanf("%d", &guess);
		}
	} while (seed != guess);
	printf("bingo!!\n");
	
	system("pause");
	return 0;
}

//�׷��K�X--------------------------------------------------------------------------------------







