﻿#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

typedef struct mysubway {
	char identity[10]; 
	char name[30]; 
	char kind[10];
	int weight;
	int transeflag; //
	struct mysubway* next;
	struct mysubway* prev; //
	struct mysubway* connect;
}mysubway;

typedef struct Dijkstra
{
	char identity[10];
	char name[30];
	int found;
	int dist;
	int real;
	char kind[10];
	struct Dijkstra * prev;
	struct Dijkstra * next;
}Dijkstra;

typedef struct ForPrint
{
	char name[30];
	int real;
	struct ForPrint * next;
	struct ForPrint * prev;
}ForPrint;

typedef struct ForT
{
	char name[30];
	struct ForPrint* next;
	struct ForPrint* prev;
}ForT;


void Mainmenu(void);
void Load(void);
void addEdge(char*, char*, char*);
void addWeight(char*, char*, int);
void addDlist(char*, char*, char*);
void showConnected(void);
int findDist(char *, char *, char *);
void startDijkstra(char *, char *);
Dijkstra* findShortestNotFound(void);
void connectTransfer(void);
void addDLL(char*, int);
void printRDLL(void);
void addTrans(mysubway*, mysubway*, int);
void addFor(char*);
void printFor();
int isInoverlap(char*);

int Transferdist = 5;
char Overlap[700][35];
Dijkstra * Dlist = NULL;
mysubway* map = NULL;
ForPrint* head = NULL;
ForPrint* first = NULL;
int startrans;
int transflag;
int isInSubway(char*);

int main(void)
{
	while(1)
	{
		Load();
		Mainmenu();
		startrans = 0;
		transflag = 0;
		Dlist= NULL;
		map= NULL;
		head = NULL;
		first = NULL;
	}
	return 0;
}

void Load(void)
{
	// 최초 한 번만 읽어오므로 전역변수일 필요 없음
	FILE* dataload = NULL;
	FILE* connectload = NULL;
	int cnt = 0, escape;
	int dist;
	char identity[20], identity2[20], name[30], kind[10];
	// ----- identity : 역 고유번호 ------ name : 역 이름 ------ kind : 지하철 호선 --------
	dataload = fopen("지하철1.txt", "r");
	// ----- 출발역 ------ 도착역 ------ 소요거리(weight)
	connectload = fopen("지하철2.txt", "r");


	if(dataload != NULL)
	printf("불러오기 성공.\n");
	else
	printf("파일이 손상되었음.\n");

		// 데이터가 공백으로 구분되어 있으므로 fscanf 이용.

		// fscanf_s로 string을 불러올 때 항상 불러올 크기가 있어야함.
	while(1)
	{
		escape = fscanf(dataload,"%s%s%s", identity, name, kind);
		if(escape == EOF) { break; }
		addEdge(identity, name, kind);
	}
	while(1)
	{
		escape = fscanf(connectload,"%s%s%d", identity, identity2, &dist);
		if(escape== EOF) { break; }
		addWeight(identity, identity2, dist);
	}
	connectTransfer();

	fclose(dataload);
	fclose(connectload);
}
void addEdge(char* identity, char* name, char* kind)
{
	mysubway* fresh = (mysubway*)malloc(sizeof(mysubway));
	strcpy(fresh->identity, identity);
	strcpy(fresh->name, name);
	strcpy(fresh->kind, kind);
	fresh->next = fresh->prev = NULL;
	fresh->connect = NULL;
	fresh->weight = 0;
	// 판단은 kind로 결정.
	addDlist(name, identity, kind);

	if(map == NULL)
	{
		map = fresh;
	}
	else
	{
		mysubway * cur = map;
		while(cur->next!= 0)
		{
			cur = cur->next;
		}
		cur->next = fresh;
		fresh->prev = cur;
	}
}
void addWeight(char* identity1, char* identity2, int dist)
{
	mysubway* man1 = map, *man2 = 0;
	mysubway* temp = map;
	while(temp != NULL)
	{
		if(strcmp(identity1, temp->identity) == 0)
		{
			man1 = temp;
			break;
		}
		temp = temp->next;
	}
	temp = map;
	while(temp != NULL)
	{
		if(strcmp(identity2, temp->identity) == 0)
		{
			man2 = (mysubway*)malloc(sizeof(mysubway));
			man2->connect = 0;
			strcpy(man2->identity, temp->identity);
			strcpy(man2->kind, temp->kind);
			strcpy(man2->name, temp->name);
			break;
		}
		temp = temp->next;
	}
	// 이제 연결..
	if(man1->connect == NULL)
	{
		man1->connect = man2;
		man1->connect->weight = dist;
	}
	else
	{
	temp = man1->connect;
	while(temp->connect != NULL)
	{
		temp = temp->connect;
	}
	temp->connect = man2;
	temp->connect->weight = dist;
	}
}
void connectTransfer(void)
{
	mysubway* chain = map;
	mysubway* chain2 = map;
	while(chain->next != NULL)
	{
		chain2 = chain->next;
		while(chain2 != NULL)
		{
			if(strcmp(chain->name, chain2->name) == 0)
			{
				if(strcmp(chain->kind, chain2->kind) != 0)
				{
					addTrans(chain, chain2, 1);
					//            printf("%s %s %s %s\n", chain->name, chain->kind, chain2->name, chain2->kind);
				}
			}
			chain2 = chain2->next;
		}
		chain = chain->next;
	}

}
void addDlist(char* name, char* identity, char* kind)
{
	Dijkstra* fresh = (Dijkstra*)malloc(sizeof(Dijkstra));
	fresh->next = 0;
	fresh->found = 0;
	fresh->dist = 0;
	fresh->real = 0;
	strcpy(fresh->kind, kind);
	strcpy(fresh->name, name);
	strcpy(fresh->identity, identity);
	if(Dlist == NULL)
	{
		Dlist = fresh;
		return;
	}
	else
	{
	Dijkstra* temp = Dlist;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = fresh;
	}
}
void Mainmenu()
{
	char* startsubway;
	char* destsubway;
	printf("\t\t\tDijkstra Subway Program\n");

	while(1)
	{
		startsubway = (char*)malloc(100);
		printf(" 출발역을 입력해주세요 : ");
	    gets_s(startsubway,sizeof(startsubway));
		fflush(stdin);
		// 사용자가 Enter만 연속해서 누를 때의 예외처리
		if(startsubway[0] == NULL)
		{
			system("cls");
			printf("\t\t\tDijkstra Subway Program\n");
			continue;
		}
		// 사용자가 정확히 입력했는지 확인
		while(isInSubway(startsubway) == -999)
		{
			free(startsubway);
			startsubway = (char*)malloc(100);
			printf(" 해당하는 역 이름이 없습니다. 다시 입력해주세요 : ");
			gets_s(startsubway, sizeof(startsubway));
		}
		destsubway = (char*)malloc(100);
		printf(" 도착역을 입력해주세요 : ");
		gets_s(destsubway, sizeof(destsubway));
		fflush(stdin);
		if(destsubway[0] == NULL)
		{
			system("cls");
			printf("\t\t\tDijkstra Subway Program\n");
			continue;
		}
		while(isInSubway(destsubway) == -999)
		{
			free(destsubway);
			destsubway = (char*)malloc(100);
			printf(" 해당하는 역 이름이 없습니다. 다시 입력해주세요 : ");
			gets_s(destsubway, sizeof(destsubway));
		}
		printf(" 결과는 다음과 같습니다\n");
		startDijkstra(startsubway, destsubway);
		free(startsubway);
		free(destsubway);
		return;
	}

}
int isInSubway(char* subway)
{
	// subway가 지하철역에 해당하나?
	Dijkstra* search = Dlist;
	while(search != NULL)
	{
		if(strcmp(search->name, subway) == 0)
		{
			return 1;
		}
		search = search->next;
	}
	return - 999;
}
// ------------ Dijkstra -------------- // 
int findDist(char* main_name, char* sub_name, char* kind)
{
	mysubway* temp= map;
	mysubway* object= NULL;
	while(temp != NULL)
	{
		if(strcmp(temp->name, main_name) == 0)
		{
			object = temp;
			break;
		}
		temp = temp->next;
	}
	temp = object;
	//printf("-----------------------%s", temp->name);
	//getchar();
	while(temp != NULL)
	{
		if(strcmp(temp->name, sub_name) == 0 && strcmp(temp->kind, kind) == 0)
		{
			return temp->weight;
		}
		temp = temp->connect;
	}
	return 999999;
}

Dijkstra* findShortestNotFound(void)
{
	int shortest = 999999;
	Dijkstra* temp = Dlist;
	Dijkstra* shortestNode = 0;
	while(temp != NULL)
	{
		if(temp->found == 0 && temp->dist < shortest)
		{
			shortest = temp->dist;
			shortestNode = temp;
		}
		temp = temp->next;
	}
	return shortestNode;
}

void startDijkstra(char* startStation, char* destStation)
{
	mysubway* temp;
	int shortestNode = -1;
	int prevNode = -1;
	int sum = 0;
	int cnt = 0;
	char change[10];
	char cname[30];
	//  ** 시작노드 **
	Dijkstra* temper = Dlist;
	Dijkstra* show = NULL;
	Dijkstra* startNode = NULL;


	while(temper != NULL)
	{
		if(strcmp(temper->name, startStation) == 0)
		{
			startNode = temper;
			//printf("\ntemper->name: %s\n", startNode->name);
			break;
		}
		temper = temper->next;
	}

	startNode->found = 1;
	startNode->dist = 0;
	startNode->prev= NULL;
	//    printf("시작역 : %s\n", startNode->name);
	// ** startNode에 직접적으로 연결되 있는 노드 탐색  **
	temper = Dlist;
	while(temper != NULL)
	{
		temper->dist = findDist(startStation, temper->name, temper->kind);
		if(temper->dist < 999999 && temper->dist>0)
		{
			temper->prev = startNode;
		}
		temper = temper->next;
	}
	// -------------여기까지 점검 완료 ---------------//

	while(1)
	{
		temper = findShortestNotFound();
		if(temper == NULL)
		{
			return;
		}
		temper->found = 1;
		temp = map;
		// ----------- Original 을 불러옴 ------------- //
		while(temp != NULL)
		{
			if(strcmp(temper->name, temp->name) == 0 && strcmp(temper->kind, temp->kind) == 0)
			{
				//        printf("%s 환승 %s\n", temp->name, temp->kind);
				break;
			}
			temp = temp->next;
		}
		while(temp->connect != NULL)
		{
			show = Dlist;
			while(show != NULL)
			{
				if(strcmp(show->name, temp->connect->name) == 0 && strcmp(show->kind, temp->connect->kind) == 0)
				{
					//        printf("%s 환승2 %s\n", temp->name, temp->kind);
					break;
				}
				show = show->next;
			}
			if(show->dist > temper->dist + temp->connect->weight)
			{
				show->dist = temper->dist + temp->connect->weight;
				show->prev = temper;
				show->real = temp->connect->weight;
			}
			temp = temp->connect;
		}


		if(strcmp(temper->name, destStation) == 0)
		{
			Dijkstra* find = temper;
			// startNode부터 destNode까지의 최단거리를 찾았으니 //
			// destNode부터 prev해서 startNode로 길을 찾아감      //
			do
			{
				addDLL(find->name, find->real);
				if(find->real == 5 && strcmp(find->name, find->prev->name) == 0)
				{
					addFor(find->name);
					transflag = 1;
				}
				find= find->prev;
			}while(find != NULL);
			if(transflag == 1)
			{
				printFor();
			}
			printRDLL();
			if(startrans == 1)
			{
				temper->dist = temper->dist - 5;
			}
			printf("\n");
			printf(">> 소요 거리:  %d distance \n", temper->dist);
			printf("\n");
			return;
		}
	}
}
void addDLL(char* name, int num)
{
	ForPrint* fresh;
	fresh = (ForPrint*)malloc(sizeof(ForPrint));
	fresh->next = fresh->prev = NULL;
	strcpy(fresh->name, name);
	fresh->real = num;
	if(head == NULL)
	{
		head = fresh;
		return;
	}
	else
	{
	ForPrint* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = fresh;
	fresh->prev = temp;
	return;
	}
}
void printRDLL(void)
{
	ForPrint* temp  = head;
	int cnt = 0;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	if(strcmp(temp->name, temp->prev->name) == 0)
	{
		startrans = 1;
	}
	while(temp->prev != NULL)
	{
		if(cnt % 7 == 0)
		{
			printf("\n");
		}
		if(strcmp(temp->name, temp->prev->name) != 0)
		{
			printf("%s->", temp->name);
		}
		temp = temp->prev;
		cnt++;
	}
	printf("%s", temp->name);

}
void addTrans(mysubway* chain, mysubway* chain2, int doReverse)
{
	mysubway* fresh1, * fresh2;
	fresh1 = (mysubway*)malloc(sizeof(mysubway));
	fresh2 = (mysubway*)malloc(sizeof(mysubway));

	strcpy(fresh1->identity, chain->identity);
	strcpy(fresh2->identity, chain2->identity);
	strcpy(fresh1->kind, chain->kind);
	strcpy(fresh2->kind, chain2->kind);
	strcpy(fresh1->name, chain->name);
	strcpy(fresh2->name, chain2->name);
	fresh1->prev = fresh2->prev = NULL;
	fresh1->next = fresh2->next = NULL;
	fresh1->connect = fresh2->connect = NULL;
	fresh1->weight = fresh2->weight = 5;

	if(chain == NULL)
	{
		chain = fresh2;
	}
	else
	{
	mysubway* temp = chain;
	while(temp->connect != NULL)
	{
		temp = temp->connect;
	}
	temp->connect = fresh2;
	//    printf("%s %s %s %s\n", chain->name, chain->kind, fresh2->name, fresh2->kind);
	}

	if(doReverse == 1)
	{
		addTrans(chain2, chain, 0);
	}
}
int isInoverlap(char* find)
{
	int i;
	for (i = 0; i < 700; i++)
	{
		if(strcmp(Overlap[i], find) == 0)
		{
			return 1;
		}
	}
	return 0;
}
void addFor(char* name)
{
	ForPrint* fresh = (ForPrint*)malloc(sizeof(ForPrint));
	fresh->next = fresh->prev = NULL;
	strcpy(fresh->name, name);

	if(first == NULL)
	{
		first = fresh;
		return;
	}
	else
	{
		ForPrint* temp = first;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = fresh;
	fresh->prev = temp;
	}
}
void printFor()
{
	ForPrint* temp =first;

	printf(">> 환승역: ");
	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	while(temp != NULL)
	{
		printf("%s ", temp->name);
		temp = temp->prev;
	}
	printf("\n");
}