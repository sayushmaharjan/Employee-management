#include <stdio.h>

int main_()
{
    FILE *fp;

    fp = fopen("test.txt", "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);

    return 0;
}

struct threeNum
{
   int n1, n2, n3;
};

struct employee
{
    int empid;
    char firstname[30];
    char lastname[30];
    char address,position,gender;
    int age,phone,salary;
}empdata;

int main()
{
   int n;
   struct threeNum num;
   FILE *fptr;

   printf("Reading from file\n");
   if ((fptr = fopen("empbase.bin","rb")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       //exit(1);
   }

   while(fread(&empdata, sizeof(struct employee), 1, fptr) == 1)
      //printf("id: %d\tfirst name: %s\tlast name: %s\n", empdata.empid, empdata.firstname, empdata.lastname);
        printf("%d\t%s\t\t%s\t%d\t%s\t%s\t%d\t%s\t%d\n",empdata.empid,empdata.firstname,empdata.lastname,empdata.age,empdata.gender,empdata.address,empdata.phone,empdata.position,empdata.salary);
   fclose(fptr);

   return 0;
}
