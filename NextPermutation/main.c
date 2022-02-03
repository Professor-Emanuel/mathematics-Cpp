/*
Determining the next permutation of a given permutation.
Implementation of pseudocode from SLIDE 9 / LECTURE 2
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100

void nextPermutation(int *p, int n){
    int i, j, temp, k, c=0;
    i = n-2;
    while(p[i]>p[i+1]){
        i--;
        c++;
    }
    if(c==n-1){
        printf("\nNO NEXT PERMUTATION!!!");
    }
    else{
    j = n-1;
    while(p[j]<p[i])
        j--;

    // swap p[i] with p[j]
    temp = p[i];
    p[i] = p[j];
    p[j] = temp;

    // revert (p[i+1],...,p[n-1])

    for(k=0; k<(n-i-1)/2; k++){
        // swap p[i+1+k] with p[n-1-k]
        temp = p[i+1+k];
        p[i+1+k] = p[n-1-k];
        p[n-1-k] = temp;
    }
    printf("\nThe next permutation is:\n");
    for(k=0; k<n; k++)
        printf("%d\t", *(p+k));
    }
}
int main()
{
    int k, n;
    char c=' ';
    int p[N];
    //int p[] = {5,4,3,2,1};//{5, 1, 3, 2, 4}; // example from lecture 2
    //int p2[] = {5, 2, 4, 3, 1}; // example from lecture 2
    do{
        printf("Enter n: ");
        scanf("%d", &n);

        printf("Enter the elements of the permutation: ");
        for(k=0; k<n; k++)
            scanf("%d", &p[k]);

        printf("The permutation is:\n");
        for(k=0; k<n; k++)
            printf("%d\t", p[k]);

        nextPermutation(p, n);
        printf("\nIf you want to enter another exemple type y:");
        fflush(stdin);
        scanf("%c", &c);
    }while(c=='y');

    return 0;
}
