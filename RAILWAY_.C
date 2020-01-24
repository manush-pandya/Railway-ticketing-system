#include<stdio.h>
#include<conio.h>

char pname[50], medhis[60], address[60];
char mobno[12];
float fare, dist, bill, basic;
int i, age, reset, tclass, passstat=1, ctype, day, month, year, discount=0, extra, r, f, t, n;


void entername(void)
{
	printf("Enter passenger's name(First Middle last)\n");
	gets(pname);
}

void entermed(void)
{
	printf("Enter passenger's medical history (if none please enter [-] )\n");
	gets(medhis);
}

void enteradd(void)
{
	printf("Enter passenger's address\n");
	gets(address);
}

void enterage(void)
{
	printf("Enter passenger's age\n");
	scanf("%d",&age);
}

void entermob(void)
{
	printf("Enter passenger's mobile number\n");
	scanf("%s",mobno);
       /*	if(mobno>9999999999)
		{
		printf("Please enter correct number!!");
		exit();
		} */
}
void enterdate(void)
{
	printf("Enter date of travel\n");
	printf("day: ");
	scanf("%d",&day);
	printf("month: ");
	scanf("%d",&month);
	printf("year: ");
	scanf("%d",&year);
}

void selectroute(void)
{
	printf("Available routes\n route1: Ahmedabad jn[1] -> Surat[2] -> Vapi[3] ->Mumbai Central[4]\n route2:Chennai central[1] -> Nellore[2] -> Bapatla[3] -> nagpur[4] -> bhopal junction[5] -> gwalior[6] ->delhi junc[7]\n\n");
	printf("Select route number: ");
	scanf("%d",&r);
	printf("\n");
	printf("from (select station number): ");
	scanf("%d",&f);
	printf("\n");
	printf("to (select station number): ");
	scanf("%d",&t);

}

void printstation(void)
{
	switch(r)
	{
		case 1: {
				if(f==1)
					printf("\t\tahmedabd jn");
				else if(f==2)
					printf("\t\tSurat");
				else if(f==3)
					printf("\t\tVapi");
				else
					printf("\t\tWrong from station number");

				if(t==2)
					printf("\t\tSurat");
				else if(t==3)
					printf("\t\tVapi");
				else if(t==4)
					printf("\t\tMumbai Central");
				else
					printf("\t\twrong to station number");

				break;
			}
		case 2:	{
				if(f==1)
					printf("\t\tChennai");
				else if(f==2)
					printf("\t\tNellore");
				else if(f==3)
					printf("\t\tBaptala");
				else if(f==4)
					printf("\t\tNagpur");
				else if(f==5)
					printf("\t\tBhopal jn");
				else if(f==6)
					printf("\t\tGwalior");
				else
					printf("\t\twrong from station number");

				if(t==2)
					printf("\t\tNellore");
				else if(t==3)
					printf("\t\tBaptala");
				else if(t==4)
					printf("\t\tNagpur");
				else if(t==5)
					printf("\t\tBhopal jn");
				else if(t==6)
					printf("\t\tGwalior");
				else if(t==7)
					printf("\t\tDelhi");
				else
					printf("\t\twrong to station number");

				break;
			}
		default: {
				printf("\t\twrong route number!");
			 }
}
}
void enterpassstat(void)
{
	char a;
	printf("Does the passenger have an annual pass?(y=1/n=2)\n");
	scanf("%d",&a);
	if(a==1)
		passstat=1;
	else if(a==2)
		passstat=2;
	else
		printf("wrong input!!");
       /*	if(a=='y'||a=='Y')
		passstat=1;
	else if(a=='n'||a=='N')
		passstat=0;
	else
		printf("wrong input!!");
	printf("\n%d",passstat);*/
}

void entertclass(void)
{
	printf("Enter ticket class([1]1AC/[2]2AC/[3]3AC): \n");
	scanf("%d",tclass);
}
void enterctype(void)
{
	printf("Enter coach type([1]AC/[2]Sleeper): \n");
	scanf("%d",&ctype);
	if(ctype==1)
		entertclass();
}

void enterdist(void)
{
	printf("Enter total travel distance: \n");
	scanf("%f",&dist);
}

void calcfare(void)
{
	if(ctype==1)
		{
			if(tclass==1)
				basic=1203;
			else if(tclass==2)
				basic=706;
			else
				basic=498;
		}
	else
		basic=200;
	fare=basic+(((dist-310)/10)*25);
	if(ctype==1)
		fare=fare-(fare*12/100);
	else
		fare=fare-(fare*(4/100));
}

void calcdiscount(void)
{
	if(age>60)
		discount=20;
	if(dist>1000)
		discount=discount+10;
	if(passstat==1)
		discount=discount+5;
}

void calcbill(void)
{       if(discount==0)
	{
		bill=fare;
	}
	else
		bill=fare*discount/100;
}

void display(void)
{
	printf("================================================================================\n");
	printf("Passenger's name");
	printf("\n%s",pname);
	printf("\n================================================================================\n");
	printf("\nContact number\n");
	printf("%s",mobno);
	printf("\n================================================================================\n");
	printf("\nMedical history \n");
	printf("%s",medhis);
	printf("\n================================================================================\n");
	printf("Address");
	printf("\n%s",address);
	printf("\n================================================================================\n");
	printf("Age \t\t\tPass status\n");
	printf("%d ",age);
	if(passstat==1)
		printf("\t\t\tAnnual");
	else
		printf("\t\t\tnone");
	printf("\n================================================================================\n");
	printf("Basic Fare \t\tBoarding from \t\tBoarding to\n");
	printf("%f ",fare);
	printstation();
	printf("\n================================================================================\n");
	printf("Date \t\tDiscount offered \t\tTotal bill to be paid(Rs.)");
	printf("\n%d/%d/%d \t\t%d \t\t\t%f",day,month,year,discount,bill);
	printf("\n================================================================================\n");
}


void main()
{
	clrscr();
	do
	{
	printf("\t\t###############RAILWAY BOOKING SYSTEM##################\n\n");
	printf("--------------------------------------------------------------------------------\n");
	entername();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\n");
	entermed();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\n");
	enteradd();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\n");
	enterage();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\n");
	entermob();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\n");
	enterdate();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\n");
	selectroute();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\n");
	enterpassstat();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\n");
	enterctype();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\n");
	enterdist();
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\n\n");
	calcfare();
	calcdiscount();
	calcbill();
	printf("###############################FINAL BILL#######################################\n\n\n");
	display();
	printf("\n#############################################################################");
	printf("\n\n------------------------------Do you want to check again?(yes=1/no=0)------\n");
	scanf("%d",&reset);
	}while(reset==1);
	getch();
}
