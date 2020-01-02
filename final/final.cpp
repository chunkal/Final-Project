#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <iostream>
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
	
	long int choice;
	
	do{
		system("CLS");
<<<<<<< HEAD
		printf("ùİùùùùùùùùùùùùùùùùùùùùùù¿ï¾Ü¹CÀ¸ùùùùùùùùùùùùùùùùùùùùùùùß\nùø                              ùø\n");
		printf("ùø          1.¯q´¼¹CÀ¸          ùø\nùø                              ùø\n");
		printf("ùø          2.  OOXX            ùø\nùø                              ùø\n");
		printf("ùø          3.Â÷¶}¹CÀ¸          ùø\nùø                              ùø\n");
		printf("ùãùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùå\n");
		scanf(" %d", &choice);
=======
		printf("â•”â•â•â•â•â•â•â•â•â•â•â•é¸æ“‡éŠæˆ²â•â•â•â•â•â•â•â•â•â•â•â•—\nâ•‘                              â•‘\n");
		printf("â•‘          1.ç›Šæ™ºéŠæˆ²          â•‘\nâ•‘                              â•‘\n");
		printf("â•‘          2.è²ªåƒè›‡            â•‘\nâ•‘                              â•‘\n");
		printf("â•‘          3.çµ‚æ¥µå¯†ç¢¼          â•‘\nâ•‘                              â•‘\n");
		printf("â•‘          4.é›¢é–‹éŠæˆ²          â•‘\nâ•‘                              â•‘\n");
		printf("â•šâ•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•â•");
		scanf(" %c", &choice);
>>>>>>> f954234cc952e1656d5b46d203a0d18843795946
		
		switch (choice)
		{
		case 1:
			system("CLS");
			puzzle();
			break;
		case 2:
			system("CLS");
			OOXX();
			break;
		case 3:
			break;
		case 228922:
			system("CLS");
			snake_main();
			break;
		}
	}while(choice != 3);
	system("CLS");
	printf("æ„Ÿè¬éŠç©\n\n");
	system("pause");
	return 0;
}

//ç›Šæ™ºéŠæˆ²------------------------------------------------- 

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
	printf("ä½¿ç”¨éµç›¤æ—çš„ä¹å®®æ ¼1,2,3,4,6,7,8,9å°æ‡‰åœ–å½¢\nç•¶æŒ‰ä¸‹ç›®æ¨™éµæ™‚å…¶é™„è¿‘å…©é¡†éµç›®æ¨™éµå°‡æœƒ1å’Œ0è½‰æ›\néŠæˆ²ç›®çš„æ˜¯å°‡åœ–å½¢å…¨éƒ¨æ”¹æˆ1å°±ç²å‹!\n");		
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
	printf("\n\n\t%cã€€%cã€€%c\n",conversion(pPillar[6]),conversion(pPillar[5]),conversion(pPillar[4]));
	printf("\t%cã€€ã€€ %c\n",conversion(pPillar[7]),conversion(pPillar[3]));
	printf("\t%cã€€%cã€€%c\n\n",conversion(pPillar[0]),conversion(pPillar[1]),conversion(pPillar[2]));
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


void gotoxy(int xpos, int ypos) //ç§»å‹•æ¸¸æ¨™è‡³æŒ‡å®šä½ç½® 
{

	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

//ç›Šæ™ºéŠæˆ²-------------------------------------------------------------------------------------- 

//è²ªåƒè›‡---------------------------------------------------------------------------------------- 

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

    printf("æŒ‰ + åŠ å¢åŠ è›‡çš„é€Ÿåº¦");

    gotoxy(55, 5);

    printf("æŒ‰ - æ¸›å°‘è›‡çš„é€Ÿåº¦");


    gotoxy(55, 7);

    printf("æŒ‰ P æš«åœ");

    gotoxy(55, 9);

    printf("åˆ†æ•¸: %d", food * 100);

    gotoxy(55, 11);

    if(speed == 10) {
    	printf("é€Ÿåº¦ %3d  (The fastest)", 310-speed);
	}
    else if(speed == 300){
    	printf("é€Ÿåº¦: %3d (The slowest)", 310-speed);
	} 
    else {
    	printf("é€Ÿåº¦: %3d              ", 310-speed);
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

    int path = 2; // æ–¹å‘

    int snakeSpeed = 100;

    char gameKey = 'y';

    Snake foodSite, coor, last;



    srand(time(NULL));

    showCursor(0);

    while(1){

        if(gameKey == 'n' || gameKey == 'N') break;

        // åˆå§‹ç‹€æ…‹

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

            printf("æŒ‰ Enter é–‹å§‹éŠæˆ²");

            gameKey = getch();

            gotoxy(55, 13);

            printf("                            ");

        }while(gameKey != 13);



        while( !gameOver ){

            printInformation(eatenFood, snakeSpeed);

            if( !isFoodEaten ){ // å¦‚æœæ²’é£Ÿç‰©, éš¨æ©Ÿç®—å‡ºä¸€å€‹é£Ÿç‰©çš„ä½ç½®

                foodSite.x = (rand()%23*2+1)+2;

                foodSite.y = rand()%17+2;

                isFoodEaten = true;

            }

            gotoxy(foodSite.x, foodSite.y);

            printf("O");

            xyChanged = false;

  

            if( kbhit() ){ // éµç›¤æ•²æ“Š

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

  

            } else { // æ²’æœ‰ä»»ä½•å‹•ä½œå‰‡é †è‘—path(æ–¹å‘)å‰é€²

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

                    gotoxy(last.x, last.y); // æ¸…å°¾å·´

                    printf(" ");

                }

                else gameOver = true;

              

                if(sBody[0].x == foodSite.x && sBody[0].y == foodSite.y){ /* Snake ate food */

                    isFoodEaten = false;

                    if(bodyLenght<1000) bodyLenght++; // é¿å…è›‡èº«è¶…å‡ºé™£åˆ—é•·åº¦

                    eatenFood++;

                }

            }

        }

        /* Game over ? */

       

            system("CLS");

            printf("ä½ çš„åˆ†æ•¸: %d\n", eatenFood* 100); 
			system("pause");
           
            break;

    }


    system("CLS");
    return 0;

}

//è²ªåƒè›‡---------------------------------------------------------------------------------------- 

//OOXX--------------------------------------------------------------------------------------

bool winner(char map[3][3]){
    for(int i=0;i<3;i++) if(map[i][0]!=' '&&map[i][0]==map[i][1]&&map[i][1]==map[i][2]) return true;//åˆ—å‹åˆ©åˆ¤æ–·
    for(int i=0;i<3;i++) if(map[0][i]!=' '&&map[0][i]==map[1][i]&&map[1][i]==map[2][i]) return true;//è¡Œå‹åˆ©åˆ¤æ–·
    if(map[0][0]!=' '&&map[0][0]==map[1][1]&&map[1][1]==map[2][2]) return true;//å·¦ä¸Šå³ä¸‹æ–œå‹åˆ©åˆ¤æ–·
    if(map[0][2]!=' '&&map[0][2]==map[1][1]&&map[1][1]==map[2][0]) return true;//å³ä¸Šå·¦ä¸‹æ–œå‹åˆ©åˆ¤æ–·
    return false;//å¦‚æœæ²’æœ‰å‹åˆ©å‡ºç¾
}
/*åˆ¤æ–·æ˜¯å¦èƒ½åœ¨é€™å€‹ä½ç½®æ”¾ç½®æ£‹å­*/
bool TFset(char Player,int Switch,char map[3][3]){
/*ç¬¬ä¸€åˆ— åˆ¤æ–·*/
    if(Switch==7&&map[0][0]==' '){map[0][0]=Player; return true;}
    else if(Switch==8&&map[0][1]==' '){map[0][1]=Player; return true;}
    else if(Switch==9&&map[0][2]==' '){map[0][2]=Player; return true;}
/*ç¬¬äºŒåˆ— åˆ¤æ–·*/
    else if(Switch==4&&map[1][0]==' '){map[1][0]=Player; return true;}
    else if(Switch==5&&map[1][1]==' '){map[1][1]=Player; return true;}
    else if(Switch==6&&map[1][2]==' '){map[1][2]=Player; return true;}
/*ç¬¬ä¸‰åˆ— åˆ¤æ–·*/
    else if(Switch==1&&map[2][0]==' '){map[2][0]=Player; return true;}
    else if(Switch==2&&map[2][1]==' '){map[2][1]=Player; return true;}
    else if(Switch==3&&map[2][2]==' '){map[2][2]=Player; return true;}
/*éŒ¯èª¤æç¤º*/
    else{ cout<<"æŒ‰éŒ¯äº†å•¦ è›¤å•Šä½ æ˜¯ç›®æ´¨è†©ï¼Ÿ"<<endl; return false;}
}
/*é¡¯ç¤ºé–˜*/
void show(char map[3][3]){
    for(int i=0;i<3;i++){
        cout<<" ï¼ï¼ï¼ï¼ï¼ï¼ï¼ï¼ï¼"<<endl;
        for(int j=0;j<3;j++) { cout<<"|  "<<map[i][j]<<"  "; } cout<<"|"<<endl;
    }cout<<" ï¼ï¼ï¼ï¼ï¼ï¼ï¼ï¼ï¼"<<endl;
}

int OOXX(){
    char map[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};    //ç©ºåœ°åœ–
    char Player='O';                                               //ç¬¬ä¸€é¡†æ£‹å­ç‚ºO  
    int Switch;                                                    //æŒ‰ä¸‹çš„æ•¸å­—éµæ§åˆ¶é …
    
<<<<<<< HEAD
    show(map);													   //¦a¹ÏÅã¥Ü
    while(1){                                                      //¹CÀ¸µL­­°j°é
		
		printf("¡]¼Æ¦rÁä¤ñ·Ó¤E®c®æ¡^");								
        scanf("%d",&Switch);
        if(Switch==0){											   //¦pªG¿é¤J0¡Aµ²§ô°j°é
			break;									   
    	}
        system("CLS");                                             //²M°£µe­±ªº¨t²Î¦r
       
	    bool TFSet=TFset(Player, Switch, map);					   //§PÂ_¬O§_¯à°÷©ñ¸m´Ñ¤l¡A¨Ã©ñ¶i´Ñ¤l
        show(map);												   //§ó·s¦a¹ÏÅã¥Ü
									   				  
    	/*§PÂ_¬O§_¦³ª±®aÀò³Ó*/
        if(winner(map)==true){									   //¦pªGÀò³Ó¡A¿é¥X¦a¹Ï»PÀò³Ó´£¥Ü«áµ²§ô°j°é
            cout<<Player<<" Ä¹¤F¡C\n";
            break;                    
        }
        
   		/*§PÂ_¬O§_º¡¹Ï*/
        bool mapover=true;
        for(int i=0;i<3;i++){									   //·j´M¥ş¦a¹Ï
            for(int j=0;j<3;j++){
                if(map[i][j]==' ') mapover=false;				   //¥u­n¦³¤@­Ó¬OªÅªº¡A¦a¹Ï´N¤£¬°º¡  
            }
        }
        
        if(mapover==true){										   //¦pªGº¡¹Ï¡A¿é¥Xº¡¹Ï´£¥Ü«áµ²§ô°j°é
            printf("º¡¹Ï¡A¤£¤À³Ó­t¡C\n");	
            break;
        }
        
  		/*°j°éÄ~Äò¡A§ó´À´Ñ¤l*/
        if(TFSet==true){										   //¦pªG¤è¤~©ñ¤J´Ñ¤lªº¿ï¶µ¦³¥¿±`°õ¦æ
            if(Player=='O') Player='X';						       //§ó´À´Ñ¤l
=======
    show(map);													   //åœ°åœ–é¡¯ç¤º
    while(1){												       //éŠæˆ²ç„¡é™è¿´åœˆ
        cout<<"ï¼ˆæŒ‰ï¼é€€å‡ºï¼Œæ•¸å­—éµæ¯”ç…§ä¹å®®æ ¼ï¼‰"<<endl;
        cin>>Switch;
        if(Switch==0) break;									   //å¦‚æœè¼¸å…¥0ï¼ŒçµæŸè¿´åœˆ
        
        system("CLS");                                             //æ¸…é™¤ç•«é¢çš„ç³»çµ±å­—
        bool TFSet=TFset(Player, Switch, map);					   //åˆ¤æ–·æ˜¯å¦èƒ½å¤ æ”¾ç½®æ£‹å­ï¼Œä¸¦æ”¾é€²æ£‹å­
        show(map);								   				   //æ›´æ–°åœ°åœ–é¡¯ç¤º
    /*åˆ¤æ–·æ˜¯å¦æœ‰ç©å®¶ç²å‹*/
        if(winner(map)==true){									   //å¦‚æœç²å‹ï¼Œè¼¸å‡ºåœ°åœ–èˆ‡ç²å‹æç¤ºå¾ŒçµæŸè¿´åœˆ
            cout<<Player<<" è´äº†ã€‚\n";
            break;                    
        }
    /*åˆ¤æ–·æ˜¯å¦æ»¿åœ–*/
        bool mapover=true;
        for(int i=0;i<3;i++)									   //æœå°‹å…¨åœ°åœ–
            for(int j=0;j<3;j++)
                if(map[i][j]==' ') mapover=false;				   //åªè¦æœ‰ä¸€å€‹æ˜¯ç©ºçš„ï¼Œåœ°åœ–å°±ä¸ç‚ºæ»¿  
                
        if(mapover==true){										   //å¦‚æœæ»¿åœ–ï¼Œè¼¸å‡ºæ»¿åœ–æç¤ºå¾ŒçµæŸè¿´åœˆ
            cout<<"æ»¿åœ–ï¼Œä¸åˆ†å‹è² ã€‚\n";
            break;
        }
    /*è¿´åœˆç¹¼çºŒï¼Œæ›´æ›¿æ£‹å­*/
        if(TFSet==true){										   //å¦‚æœæ–¹æ‰æ”¾å…¥æ£‹å­çš„é¸é …æœ‰æ­£å¸¸åŸ·è¡Œ
            if(Player=='O') Player='X';						       //æ›´æ›¿æ£‹å­
>>>>>>> f954234cc952e1656d5b46d203a0d18843795946
            else Player='O';            
        }
    }
    system("pause");
    return 0;
}

//OOXX--------------------------------------------------------------------------------------







