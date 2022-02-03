/*
PROBLEM 1 / LECTURE 2
Write a program which reads a sequence of n numbers, and
then it displays:
"a permutation" if the sequence is a permutation of {1..n}
"not a permutation" otherwise.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    int n, p[N], i, j;

    printf("Enter n: ");scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for(i=0; i<n; i++){
        printf("p[%d]=",i);
        scanf("%d", &p[i]);
    }

    for(i=0; i<n; i++){
        printf("%d\t",p[i]);
    }

    for(i=0; i<n ;i++){
        if(p[i]<1 || p[i]> n){
            printf("\nNot a permutation!!! Numbers are not between 1 and %d", n);
            exit(0);
        }
    }

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(p[i]==p[j]){
                printf("\nNot a permutation!!! There are duplicates");
                exit(0);
            }
        }
    }
    printf("\nPermuation of integers from [1,%d]", n);
    return 0;
}
