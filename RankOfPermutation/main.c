/*
Determining the RANK of a given permutation.
Implementation of pseudocode from SLIDE 13 / LECTURE 2
*/
#include <stdio.h>
#include <stdlib.h>

int factor(int n){
    if(n==1 || n==0)
        return 1;
    else
        return factor(n-1)*n;
}
int rankOfPermutation(int p[], int n){
    int q[n-1];
    int i;
    if(n==1)
        return 0;
    else{
        // adjust p[1..n-1] to become a permutation of {1,...,n-1}
        // memorized in the array q[0 .. n-2]
        for(i=1; i< n-1; i++)
            if(p[i]<p[0])
                q[i-1] = p[i];
            else
                q[i-1] = p[i]-1;
    }
    return rankOfPermutation(q, n-1) + (p[0]-1)*factor(n-1);
}
int main()
{
    int k;
    int p1[] = {2, 3, 1, 5, 4};
    int p2[] = {1, 2, 3, 4, 5};
    int p3[] = {5, 1, 3, 2, 4};
    int p4[] = {5, 4, 3, 2, 1};
    printf("The permutation is:\n");
    for(k=0; k<sizeof(p1)/sizeof(p1[0]); k++)
        printf("%d\t", p1[k]);
    printf("\nThe rank of the permutation is: %d\t", rankOfPermutation(p1,sizeof(p1)/sizeof(p1[0])));
    printf("\nThe permutation is:\n");
    for(k=0; k<sizeof(p2)/sizeof(p2[0]); k++)
        printf("%d\t", p2[k]);
    printf("\nThe rank of the permutation is: %d\t", rankOfPermutation(p2,sizeof(p2)/sizeof(p2[0])));
    printf("\nThe permutation is:\n");
    for(k=0; k<sizeof(p3)/sizeof(p3[0]); k++)
        printf("%d\t", p3[k]);
    printf("\nThe rank of the permutation is: %d\t", rankOfPermutation(p3,sizeof(p3)/sizeof(p3[0])));
    printf("\nThe permutation is:\n");
    for(k=0; k<sizeof(p4)/sizeof(p4[0]); k++)
        printf("%d\t", p4[k]);
    printf("\nThe rank of the permutation is: %d\t", rankOfPermutation(p4,sizeof(p4)/sizeof(p4[0])));
    return 0;
}
