#include <stdio.h>

int main() {
    int a[10];
    int n, i;
    int is_sorted_asc = 1;   // Flag for ascending check
    int is_sorted_desc = 1;  // Flag for descending check

    printf("Enter length of the array (max 10):\n");
    scanf("%d", &n);

   
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Check if array is sorted in ascending order
    for(i = 0; i < n - 1; i++) {
        if(a[i] > a[i + 1]) {
            is_sorted_asc = 0;
            break;
        }
    }

    // Check if array is sorted in descending order
    for(i = 0; i < n - 1; i++) {
        if(a[i] < a[i + 1]) {
            is_sorted_desc = 0;
            break;
        }
    }

    if(is_sorted_asc)
        printf("The array is sorted in ascending order.\n");
    else
        printf("The array is not sorted in ascending order.\n");

    if(is_sorted_desc)
        printf("The array is sorted in descending order.\n");
    else
        printf("The array is not sorted in descending order.\n");

    return 0;
}