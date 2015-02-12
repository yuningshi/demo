#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*****************************************************************************
 * This program generate n random numbers from 0 to 1, and print out the
 * maximum number. n is defined using command line argument
 ****************************************************************************/

double max(double *x,int n)
{
    int i;
    double  x_max =-999.0;

    for (i = 0; i<n;i++){
        if (x[i] > x_max)
                x_max = x[i];
    }

    return x_max;
}

int main(int argc, char *argv[])
{
    double *x;
    int n;
    int i;

    /* Test if the number of random numbers is defined */
    if (argc!=2)
    {
        printf("Please specify number of random numbers.\n");
        exit (1);}
    else
        sscanf (argv[1], "%d", &n);

    /* Allocate memory for x */
    //x = (double *)malloc (n*sizeof (double));

    /* Generate random numbers */
    srand(time (NULL));
    for(i= 0; i <n; i++)
    {
        x[i] = (double)(rand()%100)/ 100.0;
        printf ("%lf\t", x[i]);
    }

    /* Find the max value and print */
    printf ("\nMax value: %lf\n", max(x,n));

    return 0;
}
