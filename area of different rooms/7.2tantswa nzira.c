#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// wall=4/5 C=1/5
//
typedef struct
{
char name[100];
char colourW[50];
char colourC[50];
float l;
float w;
float h;
float aW;  //=l*h*2+h*w*2 area for walls
float aC;//=w*l; //area for ciling
 float literC;
 float literW;
} Area;

int main()
{int n;


printf("To calculate liters of paint needed for the whole flat, enter the following:\n\n");

printf("Number of rooms: ");
scanf("%d", &n);
getchar();

Area area[n];

printf("\n\n list the name of the rooms: \n\n");

for(int i=0;i<n;i++)
{
  printf("%d. ",i+1);

  fgets(area[i].name, sizeof(area[i].name),stdin);
};

printf("\n\n");

for(int i=0;i<n;i++)
{

    printf("FOR %s\n",area[i].name );

   printf("Enter length of walls (in meters): \n");
    scanf("%f", &area[i].l);

    printf("Enter width of walls (in meters): \n");
    scanf("%f", &area[i].w);

    printf("Enter height of walls (in meters): \n");
    scanf("%f", &area[i].h);
    getchar();

    printf("Enter colour of walls: \n");
    fgets(area[i].colourW, sizeof(area[i].colourW),stdin);

   printf("Enter colour of ceiling: \n");
    fgets(area[i].colourC, sizeof(area[i].colourC),stdin);

    printf("\n\n");
};

printf("\n\n");

    for (int i=0 ; i<n;i++)
    {
        area[i].aW= area[i].l*area[i].h*2+area[i].h*area[i].w*2 ;
area[i].aC= area[i].w*area[i].l ;
area[i].literW = area[i].aW/5;
area[i].literC = area[i].aC/5;

         printf("FOR %s\n\n",area[i].name );

         printf("TOTAL AREA OF WALLS= %.3f square meters\n", area[i].aW);
         printf("AREA OF CEILING= %.3f square meters\n", area[i].aC);
     printf("\nYou will need: \n\n");
    printf("%.3f l of %s paint for ceiling\n\n", area[i].literC, area[i].colourC);
      printf("%.3f l of %s paint for walls\n", area[i].literW, area[i].colourW);


      printf("\n\n");
    };

    return 0;
}
