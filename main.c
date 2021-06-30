#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#define N 500



void gotoxy(int x,int y){
 COORD coord;
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


struct data{
	char username[N];
	char name[N];
	char e_mail[N];
	char pass[N];
	unsigned long phone;
	char choice[N];
}sign;


struct DATA
{
	char ID[N];
    char PICkup[N];
    char destiny[N];
    char time[N];
    char shift[N];
    int Fares;
}info;

//------------------------File variable declarations--------------
FILE *pub,*pub1,*fast,*res,*reg,*logs,*sug;

//------------------------variable declarations-------------
int ii=0;
int c = 0;
int loop = 0;
int found = 0;
int opt;
int got = 0 ;
int check = 0;
static int in=0;
int d = 0;
int gos = 0;
char cpy[N];
char user[N];
char user1[N];
char code[N] = "Fast1234";
char add[N];
char search[N];
char search1[N];
char sc[N];


//------------------------functions declaration--------------

void welcome(void);   //
void load(void);      //
void signup(void);    //
void register1(void); //
void log1(void);      //
void home(void);      //
void reserve(void);   //
void publics(void);   //
void fastia(void);    //
void about(void);     //
void feedback(void);  //
void suggest(void);
//void end(void);      //


//-----------------------main-----------------------//
int main()
{
    system("title FASTmovers console");
    system("mode 650");
    system("color 34");
welcome();
load();
home();

return 0;

}

//---------------------functions definitions----------------------

void welcome(void)
{
    	printf("\n\n\n");
Sleep(1000);
	printf("\t\xDB\xDB2 WELCOME \xDB2\xDB\n\n");
Sleep(1000);
printf("\n\n");
	printf("\t\t  \xdb\xdb2 TO \xdb2\xdb\n");
Sleep(500);
gotoxy(30,12);
printf("\xdb1 F \xdb1\n");
Sleep(500);
gotoxy(31,13);
printf(	"\xdb1 A \xdb1\n");
Sleep(500);
gotoxy(32,14);
printf("\xdb1 S \xdb1\n");
Sleep(500);
gotoxy(33,15);
printf("\xdb1 T \xdb1\n");
Sleep(500);
gotoxy(34,16);
printf("\xdb1 m \xdb1\n");
Sleep(500);
gotoxy(35,17);
printf("\xdb1 o \xdb1\n");
Sleep(500);
gotoxy(36,18);
printf("\xdb1 v \xdb1\n");
Sleep(500);
gotoxy(37,19);
printf("\xdb1 e \xdb1\n");
Sleep(500);
gotoxy(38,20);
printf("\xdb1 r \xdb1\n");
Sleep(500);
gotoxy(39,21);
printf("\xb1 s \xdb1");
gotoxy(25,25);
system("pause");

}

void load(void)
{
    system("cls");
		int a,b;
		gotoxy(35,13);
	printf("Loading...\n");
	gotoxy(35,15);
for(a=0;a<=20;a++){
    for(b=0;b<=100000000;b++);
     printf("%c",177);
}

}


void signup(void)
{
    system("cls");
	char ch;

		printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers\xb2\xdb1\xdb\n\n");

    Sleep(1000);
	printf("\n\tACCOUNT\n");
	printf("\n\t1-For Register\t\t2-For Login\n");
	switch(getche())
{
case '1':
system("cls");
register1();
break;
case '2':
system("cls");
log1();

break;
default:
	printf("\n\tInvalid Choice\n");
	  system("pause");
        home();
    }
}

void register1(void)
{
	reg = fopen("regist.txt","a+");
	if(reg==NULL)
	{
		printf("Error in opening a file");
	}
    rewind(reg);

    printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers\xb2\xdb1\xdb\n\n");

    Sleep(1000);
    gotoxy(16,3);
	printf("\t\xdb\xdb1 Registration Form \xdb1\xdb");
	gotoxy(15,4);
	printf("\n\t->Enter username: ");
	scanf("%s",user);
	loop=0;
	while(fscanf(reg,"%s%s%s%s%s%lu",sign.username,sign.name,sign.e_mail,sign.pass,sign.choice,&sign.phone)!=EOF)
	{
		if(strcmp(sign.username,user)==0)
		{
		    gotoxy(16,5);
			printf("\n\tThis username already exist");
			loop = 1 ;
			signup();
		}
	}
	if(loop==0)
	{
		strcpy(sign.username,user);
		gotoxy(15,5);
		printf("\n\t->Enter a Name: ");
				scanf("%s",sign.name);
		fflush(stdin);
		gotoxy(15,6);
		printf("\n\t->Enter a Email: ");
		scanf("%s",sign.e_mail);
		gotoxy(15,7);
		printf("\n\t->Enter a Password: ");
		scanf("%s",sign.pass);
		gotoxy(15,8);
		printf("\n~Press F if you are FASTian else press P...  ");
		scanf("%s",sign.choice);
		if(strncmp(sign.choice,"F",1)==0)
        {
            gotoxy(15,9);
            printf("\nPlease enter FASTmovers passcode: ");
            scanf("%s",add);
            if(strcmp(code,add)==0)
            {
                check = 1;
            }
        }
        else if(strncmp(sign.choice,"P",1)==0)
        {
            gotoxy(15,9);
        printf("\n\t->Enter your Phone number: ");
		scanf("%lu",&sign.phone);
		fprintf(reg,"\t%s\t%s\t%s\t%s\t%s\t%lu\n",sign.username,sign.name,sign.e_mail,sign.pass,sign.choice,sign.phone);
		gotoxy(15,10);
		printf("\n\tRegistered successfully!\n");
        fclose(reg);
        printf("\n\tTo log in \t");
        system("pause");
		Sleep(2000);
		system("cls");
		log1();
        }
        if(check==1)
        {
            gotoxy(15,11);
		printf("\n\t->Enter your phone number: ");
		scanf("%lu",&sign.phone);
		fprintf(reg,"\t%s\t%s\t%s\t%s\t%s\t%lu\n",sign.username,sign.name,sign.e_mail,sign.pass,sign.choice,sign.phone);
gotoxy(15,12);
		printf("\n\tRegistered successfully!");
		fclose(reg);
		printf("\n\tTo log in \t");
        system("pause");
        Sleep(2000);
		system("cls");
		log1();
    }
    else
    {
        fclose(reg);
    	gotoxy(15,12);
    	printf("\tincorrect passcode!\n\tPlease try again...");
    	Sleep(1500);
    	signup();
	}
	}
		fclose(reg);
}

void log1(void)
{
    char names[50];
    char passw[50];
    int i = 0;
    logs = fopen("regist.txt","r+");
    if(logs==NULL)
    {
        printf("Error in reading a file\n");
        return;
    }

    printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers\xb2\xdb1\xdb\n\n");

    Sleep(1000);
    gotoxy(16,3);
    printf("\t\xdb1\xdbLOGIN\xdb\xdb1\n");
        gotoxy(15,4);
    printf("\t->Enter Username :  ");
    scanf("%s",names);
        gotoxy(15,5);
    printf("\t->Enter a password : ");
    while(1)
{
	char pass1;
pass1=getch();
if(pass1==13)
{
passw[i]=='\0';
break;
}
else if(pass1==8)
{
if(i>0)
{
i--;
printf("\b \b");
}
}
else if(pass1==9||pass1==32)
{
continue;
}
else
{
passw[i]=pass1;
i++;
printf("*");
}
}
passw[i]='\0';
printf("\n\tYour password is %s ",passw);
printf("\n\tLength is %d",i);
    rewind(logs);
    while(fscanf(logs,"%s%s%s%s%s%lu",sign.username,sign.name,sign.e_mail,sign.pass,sign.choice,&sign.phone)!=EOF)
	{
		if((strcmp(sign.username,names)==0)&&(strcmp(sign.pass,passw)==0))
		{
		        gotoxy(15,6);
		    printf("\t~Login Successfully~\n");
		    strcpy(cpy,sign.username);
		    strcpy(user1,sign.username);
		    found = 1;
		    in=1;
		  	 Sleep(2000);
       		 fflush(stdin);
       		 system("cls");
        	home();

		}
	}
if(found==0)
    {
        printf("\n\tusername or password is incorrect.\n\tTry Again!");
        Sleep(2500);
        fclose(logs);
        system("cls");
        log1();
    }
    fclose(logs);
}


void home(void)
{
    system("cls");
     printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers \xb2\xdb1\xdb\n\n");
Sleep(1000);
printf("\t\t\t\xdb\xdb1\xdb2 HOME \xb2\xdb1\xdb\n\n");
printf("\n\n");
printf("\t\xdb\xdb1\xdb1 1-SIGN IN OR SIGN UP\n\n");
printf("\t\xdb\xdb1\xdb1 2-RESERVE A SEAT\n\n");
printf("\t\xdb\xdb1\xdb1 3-FEEDBACK\n\n");
printf("\t\xdb\xdb1\xdb1 4-ABOUT\n\n");
printf("\t\xdb\xdb1\xdb1 5-EXIT\n");
printf("\n\tSelect anyone between 1 to 5... ");
switch(getche())
{
case '1':
system("cls");
signup();
break;
case '2':
system("cls");
reserve();
break;
case '3':
system("cls");
feedback();
break;
case '4':
about();
break;
case '5':
end();
default:
    printf("\t~invalid input\n\n");
    system("pause");
        home();
}
  }

void feedback(void)
{
	   if(!in){
            printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers\xb2\xdb1\xdb\n\n");
    Sleep(1000);
        printf("\t\tYou have not logged in yet.\n\tPlease log in first!\n");
        system("pause");
        Sleep(1000);
        home();
    }
    system("cls");
printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers \xb2\xdb1\xdb\n\n");
Sleep(1000);
printf("\t\t\t\xdb\xdb1\xdb2 FEEDBACK \xb2\xdb1\xdb\n\n");
printf("\t\t\xdb\xdb1 1-Suggest new route\n\n");
printf("\t\t\xdb\xdb1 2-Other suggestion or complain\n\n");
printf("\t\t\xdb\xdb1 3-HOME\n\n");
printf("\n\tEnter respective input...");
switch(getch())
{
case '1':
    suggest();
    gotoxy(25,25);
    system("pause");
    home();
    break;
case '2':
    printf("\n\tEnter your complain or suggestion:\n");
    scanf("%[^\n]",sc);
    printf("\n\tSubmitted successfully,Thanks!");
    system("cls");
    gotoxy(25,25);
    home();
    break;
case '3':
	system("cls");
	home();
	break;
default:
    printf("\n\tInvalid input");
    system("cls");
    gotoxy(25,25);
    system("pause");
        feedback();
}


}
void suggest(void)
{

    sug = fopen("sugg.txt","a+");
    if(sug == NULL)
    {
        printf("Error in opening a file");
        return;
    }
     if(!in){
            printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers\xb2\xdb1\xdb\n\n");
    Sleep(1000);
        printf("\t\tYou have not logged in yet.\n\tPlease log in first!\n");
        system("pause");
        Sleep(1000);
        home();
    }
    system("cls");
    printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers\xb2\xdb1\xdb\n\n");
    Sleep(1000);
    gotoxy(16,3);
    printf("\t->Enter any pickup point: ");
    scanf("%s",info.PICkup);
    fflush(stdin);
    gotoxy(16,4);
    printf("\t->Enter any destination:  ");
    scanf("%s",info.destiny);
    fflush(stdin);
    fprintf(sug,"\t%s\t%s\t%s\n",user1,info.PICkup,info.destiny);
    gotoxy(15,5);
    printf("\n\tYour suggestion received successfully.\n\t Thankyou!");
    fclose(sug);

}


void about(void)
{
    system("cls");
printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers \xb2\xdb1\xdb\n\n");
Sleep(1000);
printf("\t\t\t\xdb\xdb1\xdb2 ABOUT \xb2\xdb1\xdb\n\n\n");
printf("\t\xdb\xdb1 Address:\n");
printf("\t	  22-g block, 6, P.E.C.H.S. Block 6 PECHS, Karachi,Sindh.\n");
printf("\t\xdb\xdb1 Email:\n");
printf("\t	  fastmover@gmail.com\n");
printf("\t\xdb\xdb1 Contact:\n");
printf("\t	 111-456-898\n");
getch();
Sleep(750);
home();
}

void reserve(void)
{
	res = fopen("regist.txt","r+");
 if(res==NULL)
 {
     printf("Error in reading a file");
    return;
}
    if(!in){
            printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers\xb2\xdb1\xdb\n\n");
    Sleep(1000);
        printf("\t\tYou have not logged in yet.\n\tPlease log in first!\n");
        system("pause");
        Sleep(1000);
        home();
    }
    system("cls");
rewind(res);
while(fscanf(res,"%s%s%s%s%s%lu",sign.username,sign.name,sign.e_mail,sign.pass,sign.choice,&sign.phone)!=EOF)
{
if(strcmp(user1,sign.username)==0)
{
if(strcmp(sign.choice,"F")==0)
{
    system("cls");
    fastia();

}
else
{
    system("cls");
   	publics();
}
}
}
fclose(res);
}


void publics(void)
{
pub = fopen("bus.txt","r+");
if(pub==NULL)
{
printf("ERROR");
}
rewind(pub);
printf("\t\t\t\xdb\xdb1\xdb2 FASTmovers\xb2\xdb1\xdb\n\n");
gotoxy(16,3);
printf("\t\xdb\xdb1 SEAT RESERVATION \xdb1\xdb");
gotoxy(16,4);
printf("\n\t->Enter your pickup point: ");
scanf("%s",search);
gotoxy(16,5);
printf("\n\t->Enter your destination: ");
scanf("%s",search1);

while(fscanf(pub,"%s%s%s%s%s%d",info.ID,info.PICkup,info.destiny,info.time,info.shift,&info.Fares)!=EOF)
{
    if(((strcmp(info.PICkup,search)==0)&&(strcmp(info.destiny,search1)==0)))
    {

        printf("\n%s\t%s\t%s\t%s\t%s\n",info.ID,info.PICkup,info.destiny,info.time,info.shift);
        d++;
    }
}
if(d==0)
{
    gotoxy(16,6);
    printf("\n\t~Sorry! No route is available");
    gotoxy(16,7);
    printf("\n\tPress 1 for previous menu and 2 for home");
    if(opt==1){
        Sleep(1000);
    publics();
    }
    else
    home();
}
fclose(pub);
if(d!=0)
{
pub = fopen("bus.txt","r+");
pub1 = fopen("Add.txt","a+");
if(pub==NULL||pub1==NULL)
{
    printf("Error In opening and reading a file");
    return;
}
rewind(pub);
char Id[N];
char ch1;
char map;
printf("\n\tEnter Your route ID: ");
scanf("%s",Id);
while((fscanf(pub,"%s%s%s%s%s%d",info.ID,info.PICkup,info.destiny,info.time,info.shift,&info.Fares)!=EOF))
{
    if(strcmp(info.ID,Id)==0)
	{
		printf("\n\tYour selected route is %s\n",info.ID);
		printf("\n\tPrice of any route is %d",info.Fares);
		printf("\n\tTo check route on Google maps press M/m or S/s to skip... ");
		scanf(" %c",&map);
		if(map=='M'||map=='m')
            system("start https://www.google.com/maps");
		printf("\n\tDo You want a reserve a seat? (Y/N) \n");
		ch1 = getch();
		if(ch1=='Y'){
		fprintf(pub1,"\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",cpy,info.ID,info.PICkup,info.destiny,info.time,info.shift,info.Fares);
		printf("\n\tSeat reserved successfully!\n");
		printf("\n\tRoute is %s\n",info.ID);
		printf("\n\tYour pickup point is %s\n",info.PICkup);
		printf("\n\tYour destination is %s\n",info.destiny);
		printf("\n\ttime is %s\n",info.time);
		printf("\n\tYour total fare is %d",info.Fares);
		gos = 1;
		}
	}

    }
    if(gos==0)
    {
        printf("\n\t~Seat not reserved");
        gotoxy(25,25);
        system("pause");
        fflush(stdin);
        system("cls");
        home();
    }
    if(gos==1)
    {
        gotoxy(25,25);
        system("pause");
        fflush(stdin);
        system("cls");
        home();
    }
fclose(pub1);
fclose(pub);
}
in =0;

}
void fastia(void)
{
int total = 0;
fast = fopen("bus.txt","r+");
if(fast==NULL)
{
printf("ERROR");
}
rewind(fast);
printf("\n\n");
printf("\t->Enter your pickup point: ");
scanf("%s",search);
printf("\n\t->Enter your destination: ");
scanf("%s",search1);

while(fscanf(fast,"%s%s%s%s%s%d",info.ID,info.PICkup,info.destiny,info.time,info.shift,&info.Fares)!=EOF)
{
    if(((strcmp(info.PICkup,search)==0)&&(strcmp(info.destiny,search1)==0)))
    {

        printf("\n%s\t%s\t%s\t%s\t%s\n",info.ID,info.PICkup,info.destiny,info.time,info.shift);
        d++;
    }
}
if(d==0)
{
    printf("\n\tSorry! No Route available now");
    printf("\n\tTo return home:");
    gotoxy(25,25);
    system("pause");
    Sleep(2000);
    system("cls");
    home();
}
fclose(fast);
if(d!=0)
{
fast = fopen("bus.txt","r+");
pub1 = fopen("Add.txt","a+");
if(fast==NULL||pub1==NULL)
{
    printf("Error In opening and reading a file");
    return;
}
rewind(fast);
rewind(pub1);
char Id[N];
char ch1;
int num1;
char map;
printf("\n\tPrice of any route for FAStian is %d",info.Fares-20);
printf("\n\t->Enter Your route ID: ");
scanf("%s",Id);
while((fscanf(fast,"%s%s%s%s%s%d",info.ID,info.PICkup,info.destiny,info.time,info.shift,&info.Fares)!=EOF))
{
    if(strcmp(info.ID,Id)==0)
	{
	    total = info.Fares-20;
		printf("\n\tYour selected route is %s\n",info.ID);
		printf("\n\tPrice of any route is %d",total);
		printf("\n\tTo check route on Google maps press M/m or S/s to skip... ");
		scanf(" %c",&map);
		if(map=='M'||map=='m')
            system("start https://www.google.com/maps");
		printf("\n\tDo You want a reserve a seat? (Y/N) \n");
		ch1 = getch();
		if(ch1=='Y'){
		fprintf(pub1,"\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",cpy,info.ID,info.PICkup,info.destiny,info.time,info.shift,total);
		printf("\n\tSeat reserved successfully!\n");
		printf("\n\tRoute is %s\n",info.ID);
		printf("\n\tYour pickup point is %s\n",info.PICkup);
		printf("\n\tYour destination is %s\n",info.destiny);
		printf("\n\ttime is %s\n",info.time);
		printf("\n\tYour total fare is %d",total);
		gos = 1;
		}
	}
    }
    if(gos==0)
    {
        printf("\n\tseat not reserved.\n");
        gotoxy(25,25);
        system("pause");
        fflush(stdin);
        system("cls");
        home();
    }
    if(gos==1)
    {
        system("pause");
        fflush(stdin);
        system("cls");
        home();
    }
fclose(pub1);
fclose(fast);
}

in =0;
   }


void end(void)
{
    system("cls");
    system("color 02");
    int a;
Sleep(700);
gotoxy(16,3);
printf("\tFASTmovers");
gotoxy(16,4);
printf("\n\tProject in C");
gotoxy(16,5);
printf("\n\tis brought to you by");
gotoxy(16,6);
printf("\n\t%cBrogrammers%c:\tZulfiqar Ahmed Khan\tAhmed Ashraf",3,3);
printf("\n\n");

printf("\n\nExiting in 3 second...........>");
Sleep(3000);
    exit(0);
}


   /*|
     |
    end
     |
     |
        */
