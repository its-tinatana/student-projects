#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a[5];
    int max, min;

    printf("Enter 5 integers:\n");

    for(int i = 0; i < 5; i++)
    {scanf("%d", &a[i]);}
 min = a[0];
    max = a[0];


    for(int i = 1; i < 5; i++)
    {if(a[i] > max)
            max = a[i];

        if(a[i] < min)
            min = a[i];
    }

    printf("\nMaximum value = %d\n", max);
    printf("Minimum value = %d\n", min);
    return 0;
}
