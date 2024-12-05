#include <stdio.h>

int i = 0, j = 0, temp = 0, k = 0, c[100];

void display(int a[], int n)
{
    printf("\nWatch The Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void bubblesort(int a[], int n)
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            printf("\nPass %d, Comparison %d: ", i + 1, j + 1);
            for (k = 0; k < n; k++)
            {
                printf("%d ", a[k]);
            }
        }
        printf("\n");
    }
}

void selectionsort(int a[], int n)
{
    int min = 0, minpos = 0;
    for (i = 0; i < n; i++)
    {
        min = a[i];
        minpos = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                minpos = j;
            }
            printf("\nPass %d, Comparison %d: ", i + 1, j - i);
            for (k = 0; k < n; k++)
            {
                printf("%d ", a[k]);
            }
        }
        if (i != minpos)
        {
            temp = a[i];
            a[i] = a[minpos];
            a[minpos] = temp;
        }
    }
}
void insertionsort(int a[], int n)
{
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
            printf("\nPass %d, Shifting: ", i);
            for (k = 0; k < n; k++)
            {
                printf("%d ", a[k]);
            }
        }
        a[j + 1] = temp;
        printf("\nPass %d, Inserted: ", i);
        for (k = 0; k < n; k++)
        {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
}
int partition(int a2[], int p, int r, int n)
{
    int pivot = a2[p]; // Pivot is the first element
    int i = p, j = r, temp;

    printf("\nPivot selected: %d", pivot);

    while (i < j)
    {
        while (a2[i] <= pivot && i < r)
            i++; // Move right to find a value greater than pivot
        while (a2[j] > pivot)
            j--; // Move left to find a value smaller than pivot
        if (i < j)
        {
            // Swap elements at i and j
            temp = a2[i];
            a2[i] = a2[j];
            a2[j] = temp;
            printf("\nSwapping %d and %d: ", a2[i], a2[j]);
            display(a2, n);
        }
    }

    // Final swap with pivot
    a2[p] = a2[j];
    a2[j] = pivot;
    printf("\nPlacing pivot %d in correct position:", pivot);
    display(a2, n);

    return j;
}

void quicksort(int a2[], int p, int r, int n)
{
    if (p < r)
    {
        int q = partition(a2, p, r, n); // Get the pivot index
        quicksort(a2, p, q - 1, n);     // Sort the left subarray
        quicksort(a2, q + 1, r, n);     // Sort the right subarray
    }
}

void merge(int a[], int l, int m, int r, int n)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2]; // Create temporary arrays for left and right halves

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    printf("\nMerging subarrays: ");
    printf("\nLeft: ");
    for (i = 0; i < n1; i++)
        printf("%d ", L[i]);
    printf("\nRight: ");
    for (j = 0; j < n2; j++)
        printf("%d ", R[j]);

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }

    printf("\nAfter merging: ");
    display(a, n);
}

void mergesort(int a[], int l, int r, int n)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(a, l, m, n);     // Sort first half
        mergesort(a, m + 1, r, n); // Sort second half
        merge(a, l, m, r, n);      // Merge the sorted halves
    }
}
int main()
{
    int a[100], n, pos = 0;
    while (1)
    {
        printf("\nEnter The Size Of The Array: ");
        scanf("%d", &n);
        printf("\nEnter The Elements: ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("\nChoose The Sorting Algorithm (Bubble Sort(1) / Selection Sort(2) / Insertion Sort(3) / Quick Sort(4) / Merge Sort(5)): ");
        scanf("%d", &pos);
        switch (pos)
        {
        case 1:
            bubblesort(a, n);
            printf("\nAfter Bubble Sort: ");
            display(a, n);
            break;
        case 2:
            selectionsort(a, n);
            printf("\nAfter Selection Sort: ");
            display(a, n);
            break;
        case 3:
            insertionsort(a, n);
            printf("\nAfter Insertion Sort: ");
            display(a, n);
            break;
        case 4:
            quicksort(a, 0, n - 1, n);
            printf("\nAfter Quick Sort: ");
            display(a, n);
            break;
        case 5:
            mergesort(a, 0, n - 1, n);
            printf("\nAfter Merge Sort: ");
            display(a, n);
            break;
        default:
            printf("\nEnter The Correct Option");
            switch (pos)
                ;
            break;
        }
    }
    return 0;
}
