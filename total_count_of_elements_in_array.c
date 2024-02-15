#include <stdio.h>

// Function to find the union of two arrays
int findUnion(int a[], int b[], int n, int m) {
    int unionCount = 0;
    int unionArray[n + m];

    // Add elements of array a[] to unionArray
    for (int i = 0; i < n; i++) {
        unionArray[unionCount++] = a[i];
    }

    // Add elements of array b[] to unionArray
    for (int i = 0; i < m; i++) {
        int isDuplicate = 0;
        // Check if the current element of b[] is already present in unionArray
        for (int j = 0; j < unionCount; j++) {
            if (b[i] == unionArray[j]) {
                isDuplicate = 1;
                break;
            }
        }
        // If not present, then add it to unionArray
        if (!isDuplicate) {
            unionArray[unionCount++] = b[i];
        }
    }

    return unionCount;
}

int main() {
    int n, m;
    printf("Enter the size of array a[]: ");
    scanf("%d", &n);
    printf("Enter the size of array b[]: ");
    scanf("%d", &m);

    int a[n], b[m];

    printf("Enter elements of array a[]: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter elements of array b[]: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    // Find the total count of elements after union operation
    int totalCount = findUnion(a, b, n, m);

    printf("Total number of elements after union: %d\n", totalCount);

    return 0;
}
