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
		printf("��������������������������ܹC��������������������������\n��                              ��\n");
		printf("��          1.�q���C��          ��\n��                              ��\n");
		printf("��          2.  OOXX            ��\n��                              ��\n");
		printf("��          3.���}�C��          ��\n��                              ��\n");
		printf("����������������������������������������������������������������\n");
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
	printf("�P�¹C��\n\n");
	system("pause");
	return 0;
}
