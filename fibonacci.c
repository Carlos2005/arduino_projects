/* Fibonacci Sequence
The Fibonacci Sequence is the series of numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ... The next number is found by adding up the two numbers before it.
Copyright (C) 2015 Carlos de la Calleja, carlosdelacalleja@gmail.com */

#include <stdio.h>
#define MAX 6   /* maximum numbers in the sequence */

void main(void)
{

    /* var declarations:  a2 is the second before, a1 is the first before, and current is the actual sequence item */
    int i, current, a2=0, a1=1; 

    printf("Fibonacci Sequence\n");
    printf("==================\n\n");

    for( i=0 ; i < MAX; i++){	
        if (i==0) current = 0;
       else if (i==1) current = 1;
       else {
             current = a2 + a1;           /* current number is the addition of the first and second before */
             a2 = a1;                     /* set the second before the to first before */
             a1 = current;                 /* set the first before the to the current */
             }
        printf("item number %i = ",i+1); 
        printf("%i \n",current); 
     }	
 }
