#include <stdio.h>
#include <stdlib.h>
//f=30%t + 70%e
//cont float f
//if f>=50% print pass else fail

typedef struct
{
   char name[100];
   int sn;//student number
   int Tmark;
   int Emark;
   float Fmark;

}Student;


int main()
{  int n;
    Student kids[n];

    printf("Student Marks System\n\n");

    printf("Enter number of learners: ");
    scanf("%d", &n);
    getchar();

    printf("\nEnter students' details\n\n");
    for (int i=0;i<n;i++)
    {
        printf("student %d\n\n", i+1);
        printf("full names: ");
        fgets(kids[i].name,sizeof(kids[i].name),stdin);

        printf("student number: ");
        scanf("%d", &kids[i].sn);

        printf("test mark: ");
       scanf("%d", &kids[i].Tmark);

        printf("Exam mark: ");
        scanf("%d", &kids[i].Emark);
getchar();

      printf("\n\n");
    }

printf("Students' Results\n\n");
    for (int i=0;i<n;i++)
    {
        printf("Student %d:\n\n ", i+1);
        printf("full names: %s\n", kids[i].name );

        printf("student number: %d\n", kids[i].sn );

        printf("test mark: %d\n", kids[i].Tmark );

        printf("Exam mark: %d\n", kids[i].Emark);

      kids[i].Fmark=(30/100.0*kids[i].Tmark)+(70.0/100*kids[i].Emark);
        printf("Final mark: %.1f \n", kids[i].Fmark);

         printf("Results status: ");
         if (kids[i].Fmark>=50)
            printf("PASSED");
         else
            printf("FAILED");

printf("\n\n");


    };

    return 0;
}
