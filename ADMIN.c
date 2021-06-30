#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define N 100

void gotoxy(int x,int y){
 COORD coord;
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


FILE *fp,*fp1;
int d = 0;
int loop = 0 ;
int  i ;
int  n;
char another;
char names[50];
char IDS[50];
void admin();
void add(void);
void sugg(void);

struct DATA
{
	char ID[N];
    char PICkup[N];
    char destiny[N];
    char time[N];
    char shift[N];
    int Fares;
}info;


int main()
{
  admin();
   
}
void admin(void)
{
	 printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers\xb2\xdb1\xdb\n\n");

    Sleep(1000);

      gotoxy(16,3);
printf("\xdb\xdb1 ADMIN PANEL \xdb1\xdb");
  gotoxy(16,4);
printf("\n\t\xdb 1- ADD New Point\n");
  gotoxy(16,5);
printf("\n\t\xdb 2- Feedback From User\n");

  gotoxy(16,6);
printf("\n\n\tEnter a choice:  ");
switch(getch())
{
case '1':
    add();
    break;
case '2':
    sugg();
    break;
default:
    system("cls");
   	admin();
}
}
void add(void)
{
     system("cls");
    fp = fopen("bus.txt","a+");
    if(fp==NULL)
    {
        printf("ERROR");
    }
    rewind(fp);
	printf("Enter ID:\n");
	scanf("%s",IDS);
	while(fscanf(fp,"%s%s%s%s%s%d",info.ID,info.PICkup,info.destiny,info.time,info.shift,&info.Fares)!=EOF)
	{
    if(strcmp(info.ID,IDS)==0)
    {
	printf("This ID is exit");
	loop++;
	main();
    }
}
if(loop==0)
{

    strcpy(info.ID,IDS);
    printf("Enter Pickup");
    scanf("%s",info.PICkup);
    printf("ENTER destiny\n");
    scanf("%s",info.destiny);
    printf("Enter time");
    scanf("%s",info.time);
    printf("Enter shift");
    scanf("%s",info.shift);
    info.Fares = 50;
    fprintf(fp,"%s\t%s\t\t%s\t%s\t%s\t%d\n",info.ID,info.PICkup,info.destiny,info.time,info.shift,info.Fares);
	printf("\nPoint Added Successfully\n");

	
}
	system("cls");
	sleep(2000);
admin();
fclose(fp);
}
void sugg()
{
     system("cls");
    fp1 = fopen("sugg.txt","r+");
    if(fp1==NULL)
    {
        printf("Error");
        return;
    }
    printf("Names  Pickup Destiny \n");
    while(fscanf(fp1,"%s%s%s",names,info.PICkup,info.destiny)!=EOF)
    {
        printf("%s\t%s\t%s\n",names,info.PICkup,info.destiny);
    }
    system("cls");
	sleep(2000);
	admin();
	fclose(fp1);
}
