#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include <windows.h>

COORD coord={0,0}; // this is global variable
                                //center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
{
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void dataentry();
void selectadminoption();
void getdata(int option);
int showadminmenu;

int main()
{
    int canceloption,entryoption,exitoption;
    char choice[1];
    char selectionoption[1];

    canceloption=0;

    //main menu for application
	while(canceloption==0)
	{
	    system("cls");
	    gotoxy(30,7);
	    printf("SELECT AN OPTION");
	    gotoxy(30,10);
	    printf("Data Entry         [1]");
	    gotoxy(30,11);
        printf("Exit               [2]");
	    gotoxy(30,12);

	    printf("Please enter your choice (1/2): ");
	    scanf("%s",&choice);
	    entryoption=strcmp(choice,"1");
	    exitoption=strcmp(choice,"2");



		if (entryoption==0)
		{
		    dataentry();
		    canceloption=0;
		}
		if (exitoption==0)
		{
		    canceloption=1;
		}

		if(!(entryoption==0 || exitoption==0))
		{
		    gotoxy(10,17);
		    printf("You have entered an invalid option.");
		    getch();
		    canceloption=0;
		}
	}
	system("cls");
	gotoxy(23,13);
	printf("The application will close now.");
	gotoxy(34,14);
	printf("Thank You!!");
	getch();
	return 0;
}

//data entry option
void dataentry()
{
    char adminname[10],passwd[5],buffer[1];
    char tempo[6],sel[1];
    int validusernameoption,validuserpwdoption,returnoption,username,inc,tmp;
    char plus;
	system("cls");
	validusernameoption=0;
	validuserpwdoption=0;
	while(validuserpwdoption == 0)
	{
        while(validusernameoption==0)
        {
            system("cls");
            gotoxy(20,5);
            printf("DATA ENTRY SYSTEM");
            gotoxy(20,24);
            printf("******Type return to go to main menu.******");
            gotoxy(28,10);
            printf("Enter admin name: ");
            scanf("%s",&adminname);
            returnoption=strcmp(adminname,"return");
            username=strcmp(adminname,"sayush");

            if (returnoption==0)
            {
                goto stream;
            }
            if (!(username==0 || returnoption==0))
            {
                gotoxy(32,11);
                printf("Admin name is invalid");
                getch();
                validusernameoption=0;
            }
            else
                validusernameoption=1;
        }
        gotoxy(30,11);
        printf("Enter password:");
        inc=0;
        while(inc<5)
        {
            passwd[inc]=getch();
            inc=inc+1;
            printf("* ");
        }
        inc=0;
        while(inc<5)
        {
            tempo[inc]=passwd[inc];
            inc=inc+1;
        }
        tempo[inc] = '\0';
        while(getch()!=13);

	    if (strcmp(tempo,"admin"))
	    {
            gotoxy(28,13);
            printf("The password is incorrect.Please try again.");
            getch();
            validuserpwdoption=0;
            validusernameoption=0;
	    }
	    else
	    {
            system("cls");
            gotoxy(24,11);
            printf("you have successfully logged in.");
            gotoxy(24,17);
            printf("press any key to continue");
            validuserpwdoption=1;
            validusernameoption=1;
            getch();
            showadminmenu=0;

            while(showadminmenu==0)
            {
                char choose[2];

                int choosenew,choosesearch,chooseremove, choosemodify,chooseshow,chooseclose;
                system("cls");
                gotoxy(24,4);
                printf("ADMIN OPTION");
                gotoxy(26,9);
                printf("Add new employee        [1]");
                gotoxy(26,11);
                printf("search employee record  [2]");
                gotoxy(26,13);
                printf("Remove employee         [3]");
                gotoxy(26,15);
                printf("Modify                  [4]");
                gotoxy(26,17);
                printf("Show list               [5]") ;
                gotoxy(26,19);
                printf("Close                   [6]");
                gotoxy(26,21);
                printf("Please enter your choice: ");

                scanf("%s",&choose);
                //printf("\nchoose : %s ", &choose);
                choosenew = strcmp(choose, "1");
                choosesearch = strcmp(choose, "2");
                chooseremove = strcmp(choose, "3");
                choosemodify = strcmp(choose, "4");
                chooseshow = strcmp(choose, "5");
                chooseclose = strcmp(choose, "6");
                if(!(choosenew == 0 || choosesearch == 0 || chooseremove == 0 || choosemodify== 0|| chooseshow==0 || chooseclose == 0))
                {
                    gotoxy(19,21);
                    printf("INVALID INPUT!\n");
                    gotoxy(34,21);
                    printf("Press Any Key To Continue...");
                    getch();
                }
                else
                {
                    printf("Choose: %c\n", choose[0]);
                }
                if(choosenew == 0)
                {
                    //printf("new\n");
                    //getch();
                    system("cls");
                    gotoxy(25,5);
                    getdata(1);
                }
                else if(choosesearch == 0)
                {
                    //printf("search\n");
                    getdata(2);
                }
                else if(chooseremove == 0)
                {
                    //printf("remove\n");
                    getdata(3);
                }
                else if(choosemodify == 0)
                {
                    //printf("modify\n");
                    //getch();
                    getdata(4);
                }
                else if(chooseshow == 0)
                {

                    getdata(5);
                }
                else if(chooseclose == 0)
                {
                    showadminmenu = 1;
                }
                //selectadminoption();
                //getch();
            }
	    }
	}
	stream:{}
}

void getdata(int option)
{
    struct employee
	{
	    int empid;
	    char firstname[30];
	    char lastname[30];
        char address[30],gender[30];
	    int age,phone,salary;
	}empdata;
	FILE *db,*tempdb;
	char anotheremp;
	int choice;
	int showmenu,posx,posy;
	volatile char checksave,checkaddnew;
	int i;
	char confirmpassword[30];
	long int size;
	char lastnametemp[30] = {0},firstnametemp[30] = {0},password[30]={0};
	int searchid;
	char pass[30];
	char findemployee;
	char confirmdelete;

	system("cls");

    /*Opens the Employee Database*/
    //gotoxy(0,0);
    //printf("Opening file\n");
    db=fopen("empbase.bin","r+");
    if (db==NULL)
    {
        db=fopen("empbase.bin","w+");
        if (db==NULL)
        {
        printf("The File could not be opened.\n");
        //exit();
        getch();
        }
        }
        printf("Application Database \n");
        size=sizeof(empdata);
        showmenu=0;
        while (showmenu==0)
        {
        fflush(stdin);
        choice=option;
        /*Based on the choice selected by admin/employee, this switch statement processes the request*/
        switch(choice)
        {
            //To add a new employee to the database*/

            case 1:
                fseek(db,0,SEEK_END);
                anotheremp='y';
                while(anotheremp=='y')
                {
                    checkaddnew=0;
                    while(checkaddnew==0)
                    {
                        system("cls");
                        gotoxy(25,3);
                        printf("ADD A NEW EMPLOYEE");
                        do
                        {
                            gotoxy(5,5);
                            printf("Enter your id: ");
                            scanf("%d",&empdata.empid);
                            if(empdata.empid < 0)
                            {
                                gotoxy(5,5);
                                printf("Invalid ID                                      ");
                                getch();
                            }
                        }while(empdata.empid < 0);

                        gotoxy(5,8);
                        printf("Enter First Name:");
                        scanf("%s",&empdata.firstname);
                        gotoxy(5,10);
                        printf("Enter Last Name:");
                        scanf("%s",&empdata.lastname);
                        gotoxy(5,12);
                        printf("Enter age:");
                        scanf("%d",&empdata.age);
                        gotoxy(5,14);
                        printf("Enter gender:");
                        scanf("%s",&empdata.gender);
                        gotoxy(5,16);
                        printf("Enter address:");
                        scanf("%s",&empdata.address);
                        gotoxy(5,18);
                        printf("Enter phone number:");
                        scanf("%d",&empdata.phone);
                        gotoxy(5,20);
                        printf("Enter salary:");
                        scanf("%d",&empdata.salary);

                        struct employee temp_data;
                            int check_id = 0;
                            /////////////////////////////////////////////////////////////
                            checkaddnew=1;
                            /////////////////////////////////////////////////////////////////
                            rewind(db);
                            while(fread(&temp_data,size,1,db)==1)
                            {
                                if(empdata.empid == temp_data.empid)
                                {
                                    gotoxy(29,16);
                                    printf("ID already Existed!\n");
                                    getch();
                                    check_id = 1;
                                    break;
                                }
                            }

                            if(check_id == 1)
                            {
                                break;
                            }
                        /*
                        rewind(db);
                        empdata.empid=0;

                        while(fread(&empdata,size,1,db)==1)
                            if(empdata.empid<2000)
                                empdata.empid=20400;

                        empdata.empid=empdata.empid+1;
                        */
                        gotoxy(29,25);
                        printf("save employee information?(y/n)");
                        checksave=getche();
                        if(checksave=='y')
                        {
                                fwrite(&empdata, sizeof(struct employee), 1, db);
                        }
                        gotoxy(29,25);
                        printf("would you like to add another employee?(y/n)");
                        fflush(stdin);
                        anotheremp=getche();
                          //printf("%c",anotheremp);
                          //getch();
                        printf("\n");

                    }
                 }
                 break;

            //to search employee
            case 2:
                system("cls");
                gotoxy(27,5);
                printf("SEARCH EMPLOYEE INFORMATION");
                gotoxy(25,9);
                printf("enter employee id to search: ");
                scanf("%d",&searchid);
                findemployee='f';
                rewind(db);
                while(fread(&empdata,size,1,db)==1)
                {
                    gotoxy(0,0);
                    //printf("%d,%s,%s\n",empdata.empid,empdata.firstname,empdata.lastname);
                    if (empdata.empid==searchid)
                    {
                        gotoxy(33,11);
                        printf("Employee information is available.");
                        gotoxy(25,15);
                        printf("Employee name is:%s %s",empdata.firstname,empdata.lastname);
                        gotoxy(25,17);
                        printf("Name: %s %s\n",empdata.lastname,empdata.firstname);
                        gotoxy(25,19);
                        printf("Age: %d\n",empdata.age);
                        gotoxy(25,21);
                        printf("Gender: %s\n",empdata.gender);
                        gotoxy(25,22);
                        printf("Address: %s\n",empdata.address);
                        gotoxy(25,25);
                        printf("Phone: %d\n",empdata.phone);
                        gotoxy(25,27);
                        printf("Salary: %d\n",empdata.salary);
                            findemployee='t';
                        getch();
                    }
                }
                if(findemployee!='t')
                {
                    gotoxy(30,11);
                    printf("Employee information is not available.");
                    getch();
                }
                break;

            //to remove entry of an employee
            case 3:
                system("cls");
                gotoxy(25,5);
                printf("REMOVE AN EMPLOYEE");
                gotoxy(25,9);
                printf("enter employee id to delete: ");
                scanf("%d",&searchid);
                findemployee='f';
                rewind(db);
                while(fread(&empdata,size,1,db)==1)
                {
                    if(empdata.empid==searchid)
                    {
                    gotoxy(33,11);
                    printf("Employee information is available.");
                    gotoxy(25,13);
                    printf("Name: %s %s\n",empdata.lastname,empdata.firstname);

                    findemployee='t';
                    }
                }
                if (findemployee!='t')
                {
                    gotoxy(30,11);
                    printf("Employee information is not available.");
                    getch();
                }
                if (findemployee=='t')
                {
                    gotoxy(29,15);
                    printf("do you want to delete the employee record?(y/n)");
                    confirmdelete=getche();
                    if (confirmdelete=='y' || confirmdelete=='Y')
                    {
                        tempdb=fopen("tempo.bin","w+");
                        rewind(db);
                        while(fread(&empdata,size,1,db)==1)
                        {
                            if(empdata.empid!=searchid)
                            {
                                fseek(tempdb,0,SEEK_END);
                                fwrite(&empdata,size,1,tempdb);
                            }
                        }
                        fclose(tempdb);
                        fclose(db);
                        remove("empbase.bin");
                        rename("tempo.bin","empbase.bin");
                        db=fopen("empbase.bin","r+");
                    }
                }
                break;

            //to remove entry of an employee
            case 4:
                system("cls");
                gotoxy(25,5);
                printf("MODIFY AN EMPLOYEE");
                gotoxy(25,9);
                printf("enter employee id to Modify: ");
                scanf("%d",&searchid);
                findemployee='f';
                rewind(db);
                while(fread(&empdata,size,1,db)==1)
                {
                    if(empdata.empid==searchid)
                    {
                    gotoxy(33,11);
                    printf("Employee information is available.");
                    gotoxy(25,13);
                    printf("Name:%s %s",empdata.firstname,empdata.lastname);
                    findemployee='t';
                    }
                }
                if (findemployee!='t')
                {
                    gotoxy(30,11);
                    printf("Employee information is not available.");
                    getch();
                }
                if (findemployee=='t')
                {
                    gotoxy(29,15);
                    printf("do you want to modify the employee record?(y/n)");
                    confirmdelete=getche();
                    if (confirmdelete=='y' || confirmdelete=='Y')
                    {
                        tempdb=fopen("tempo.bin","w+");
                        rewind(db);
                        while(fread(&empdata,size,1,db)==1)
                        {
                            if(empdata.empid!=searchid)
                            {
                                fseek(tempdb,0,SEEK_END);
                                fwrite(&empdata,size,1,tempdb);
                            }
                            else
                            {
                                system("cls");
                                gotoxy(25,9);
                                printf("Enter new First Name: ");
                                scanf("%s", &empdata.firstname);
                                gotoxy(25,11);
                                printf("Enter new Last Name: ");
                                scanf("%s", &empdata.lastname);
                                printf("Enter age:");
                                gotoxy(25,13);
                                scanf("%d",&empdata.age);
                                gotoxy(5,15);
                                printf("Enter gender:");
                                scanf("%s",&empdata.gender);
                                gotoxy(5,17);
                                printf("Enter address:");
                                scanf("%s",&empdata.address);
                                gotoxy(5,19);
                                printf("Enter phone number:");
                                scanf("%d",&empdata.phone);
                                gotoxy(5,21);
                                printf("Enter salary:");
                                scanf("%d",&empdata.salary);
                                fwrite(&empdata,size,1,tempdb);
                            }
                        }
                        fclose(tempdb);
                        fclose(db);
                        remove("empbase.bin");
                        rename("tempo.bin","empbase.bin");
                        db=fopen("empbase.bin","r+");
                    }
                }
                break;

            case 5:
                system("cls");
                gotoxy(0,0);
                printf("SHOW EMPLOYEE INFORMATION\n\n");
                rewind(db);
                printf("ID\tFirst name\tLast name\tAge\tGender\tAddress\tPhone\tSalary\n");
                while(fread(&empdata,size,1,db)==1)
                {
                    printf("%d\t%s\t\t%s\t%d\t%s\t%s\t%d\t%d\n",empdata.empid,empdata.firstname,empdata.lastname,empdata.age,empdata.gender,empdata.address,empdata.phone,empdata.salary);
                }

                gotoxy(25,30);
                printf("Press any key to continue...");
                getch();
                break;

            //exit
            case 6:
                printf("\n");
                break;
               // exit();
        }
        //getch();
        fclose(db);
        showmenu=1;
        break;
    }
}

