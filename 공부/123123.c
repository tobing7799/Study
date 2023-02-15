#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

typedef struct info {
	char title[50];
	int stock;
	double price;
	struct info* next;
}info;

typedef struct theinventory {
	char lastname[30];
	char firstname[30];
	info* books;
}theinventory;

void greeting(void);//인사함수 선언
void readDatabase(theinventory* list);
int printMenu(void);//메뉴+서비스선택
void displayAuthorsWork(theinventory* list);

int main(void)
{
	greeting();

	//theinventory 선언
	theinventory* list=(theinventory*)malloc(sizeof(theinventory)*20);
	if (list != NULL)
	{
		for (int i = 0; i < 20; ++i)
		{
			list[i].books = (info*)malloc(sizeof(info));
		}
		readDatabase(list);
	}

	int flag = 1;
	//while (flag)
	//{
	//	int choice = printMenu();
	//};
	if (list != NULL)
	{
		for (int i = 0; i < 20; ++i)
		{
			free(list[i].books);
		}
		free(list);
	}
}

//인사함수 정의
void greeting(void)
{
	printf("이 프로그램은 서점관리프로그램입니다. 반갑습니다.\n");
}

void readDatabase(theinventory* list)
{
	char fname[30];
	FILE* data;
	int i = 0;
	char buf[100];
	char* stk[10] = { NULL };

	printf("Enter the name of file: ");
	scanf("%s", fname);

	data = fopen(fname, "r");//파일 오픈
	if (data == NULL)
	{
		printf("\nError:Unable to open file <%s>\n", fname);
		return;
	}//파일 열기 실패시 프로그램 종료


	while (!feof(data))
	{
		fgets(buf, sizeof(buf), data);

		strcpy(list[i].firstname, strtok(buf, ","));
		strcpy(list[i].lastname, strtok(NULL, ","));
		printf("%s", list[i].lastname);

		strcpy(list[i].books->title, strtok(NULL, ","));
		list[i].books->stock = atoi(strtok(NULL, ","));
		list[i].books->price = atof(strtok(NULL, ","));
		printf("%f\n", list[i].books->price);
		i++;
	}

	//fscanf',' 건너뛰고 저장하는방법
	//fscanf(data, "%[^,]s",list[i].firstname);
	//printf("%s\n", list[i].firstname);
	//fscanf(data, "%[,]s", ptr);
	//fscanf(data, "%[^,]s", list[i].lastname);
	fclose(data);
}

//메뉴+서비스 정의
int printMenu(void)
{
	int choice;
	printf("Enter 1 to display the inventory\n");
	printf("Enter 2 to display the inventory by name of author\n");
	printf("Enter 3 to display the books by one author\n");
	printf("Enter 4 to add a book\n");
	printf("Enter 5 to change the price\n");
	printf("Enter 6 to change the qty on hand\n");
	printf("Enter 7 to view the total number of books in the inventory\n");
	printf("Enter 8 to see the total amount of the entire inventory\n");
	printf("Enter 9 to exit\n");
	printf("Enter your choice: ");
	scanf_s("%d", &choice);

	return choice;
}

void displayAuthorsWork(theinventory* list)
{
	std::sort(list[0],list[20],[](const list& a, const list& b){
		return })
}