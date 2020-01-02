#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//int snake_main();
//int OOXX();
//int puzzle();

int main (){	
	long int choice;
	
	do{
		system("CLS");
		printf("שÝשששששששששששששששששששששש¿ן¾Ü¹Cְ¸שששששששששששששששששששששששß\nשר                              שר\n");
		printf("שר          1.¯q´¼¹Cְ¸          שר\nשר                              שר\n");
		printf("שר          2.  OOXX            שר\nשר                              שר\n");
		printf("שר          3.ֲק¶}¹Cְ¸          שר\nשר                              שר\n");
		printf("שדשששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששו\n");
		scanf(" %d", &choice);

		switch (choice)
		{
		case 1:
			system("CLS");
			//puzzle();
			break;
		case 2:
			system("CLS");
			//OOXX();
			break;
		case 3:
			break;
		case 228922:
			system("CLS");
			//snake_main();
			break;
		}
	}while(choice != 3);
	system("CLS");
	printf("·Pֱֲ¹C×±\n\n");
	system("pause");
	return 0;
}
