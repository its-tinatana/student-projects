#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototype
void save();
void display();
void rm();
void menu();


typedef struct
{
char uni[100];
char name[50];
char address[100];
int year;

} Student;

void line(char *str)
{
    str[strcspn(str,"\n")]='\0';
}


void menu()
{
    printf("\n\nchoose the operation you want by entering the number\n\n");
    printf("1. Save data in a file\n");
   printf("2. Display data from file\n");
   printf("3. Delete last student data\n");
      printf("4. Exit\n\n");
      printf("Enter number: ");
}
int main(void)
{
    int choice;
    do
    { menu();
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
        case 1: save();break;
       case 2: display();break;
        case 3: rm();break;
        case 4: printf("\n\nPress enter to exit");break;

      default: printf("invalid"); break;
    }

    }while (choice!=4);

    return 0;
}

void save()
{
    int n;
printf("STUDENT DATABASE\n");
   printf("\nEnter number of students: ");
   scanf("%d", &n);
   getchar();




    FILE *f= fopen("data.txt","w");
    if(f==NULL)
    {
         printf("cant save file");
         return;
    }

Student students;
   for (int i=0; i<n; i++)
   {

    printf("\n\nDATA FOR STUDENT %d\n\n", i+1);

    printf("Name of the university: ");
     fgets(students.uni, sizeof(students.uni),stdin);
     line(students.uni);

    printf("full name: ");
     fgets(students.name, sizeof(students.name), stdin);
     line(students.name);

    printf("Street and city: ");
     fgets(students.address, sizeof(students.address) ,stdin);
     line(students.address);

    printf("Year of study: ");
     scanf("%d", &students.year);
     getchar();


    fprintf(f, "%s,%s,%s,%d\n",
            students.uni,students.name, students.address, students.year);
   }

printf("\nfile is saved\n\n");
while (getchar()!='\n');
    fclose(f);
    }

void display()
{
    FILE *f = fopen("data.txt","r");
    if(f==NULL)
    {
      printf("data is empty");
      return;
    }

 Student students;
  int i=1;
while (fscanf(f,"%99[^,],%49[^,],%99[^,],%d",
               students.uni,
               students.name,
               students.address,
               &students.year)==4)
   {

    printf("\n\nDATA FOR STUDENT %d\n\n", i++);

    printf("Name of the university: %s\n", students.uni);

    printf("full name: %s\n", students.name);

    printf("Street and city: %s\n", students.address);

    printf("Year of study: %d\n", students.year);


  }; fclose(f);
}

void rm()
{
    FILE *f= fopen("data.txt","r");
    if(!f)
    {
        printf("no data");
        return;
    }

   Student students[100];
   int i=0;

 while(fscanf(f, "%99[^,],%49[^,],%99[^,],%d", students[i].uni,
 students[i].name, students[i].address, &students[i].year)==4)
 {
     i++;
 }
    fclose(f);


    if(i==0)
    {
        printf("file is empty");
        return;
    }
    if (i<=1)
    {
        printf("not enough data to delete");
        return;
    }
    f= fopen("data.txt","w");
    for(int j=0;j<i-1;j++)
    {
fprintf(f,"%s,%s,%s,%d\n",
        students[j].uni ,students[j].name ,students[j].address
        ,students[j].year);
    }

    fclose(f);

      printf("file has been modified");
}

