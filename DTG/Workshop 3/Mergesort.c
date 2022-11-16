
#include <stdio.h>
#include <stdlib.h>

void Merge(int List[], int start, int slut, int midt);
void MergeSort(int L[], int start, int slut);
void printList(int L[], int size);

int main(void)
{
    int L[] = {5, 3, 8, 1, 6, 10, 7, 2, 4, 9};
    int L_size = sizeof(L) / sizeof(L[0]);

    printf("Givet listen \n");
    printList(L, L_size);

    MergeSort(L, 0, L_size - 1);

    printf("Er den sorterede liste \n");
    printList(L, L_size);
    return 0;
}

void Merge(int List[], int start, int slut, int midt)
{
    int i, j, k;
    int n1 = midt - start + 1;
    int n2 = slut - midt;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = List[start + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = List[midt + 1 + j];
    }

    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            List[start + i + j] = L[i];
            i++;
        } else {
            List[start + i + j] = R[j];
            j++;
        }
    }

    if(i == midt - start + 1){
        for(k = j; k < slut -midt - 1;k++){
            L[start + i + k] = R[k];
        }
    }
    else{
        for(k = i; k < midt-start +1;k++){
            L[start + j + k] = L[k];
        }
    }
    /*
    while (i < n1) {
        List[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        List[k] = R[j];
        j++;
        k++;
    }
    */
    

}


void MergeSort(int L[], int start, int slut)
{
    int m;
    if (start < slut)
    {
        m = (slut + start) / 2;

        MergeSort(L, start, m);
        MergeSort(L, 1 + m, slut);

        Merge(L, start, slut, m);
    }
}

void printList(int L[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", L[i]);
    printf("\n");
}
/*



#include <stdio.h> 
#include <stdlib.h> 

void Merge(int L[], int start, int slut, int midt);
void MergeSort(int L[], int start, int slut);
void printList(int L[], int size);

int main(void){ 
    int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 }; 
    int L_size = sizeof(L) / sizeof(L[0]); 
    printf("Givet listen \n"); 
    printList(L, L_size); 

    MergeSort(L, 0, L_size - 1); 

    printf("Er den sorterede liste \n"); 
    printList(L, L_size); 
    return 0; 
} 

void Merge(int L[], int start, int slut, int midt){
    int i, j, k;
    int Left[midt - start], Right[slut - midt + 1];

    i = 0; 
    j = 0; 
    while (i < midt - start && j < slut - midt) {
        if (Left[i] <= Right[j]) {
            L[start + i + j] = Left[i];
            i++;
        }
        else {
            L[start + i + j] = Right[j];
            j++;
        }
        k++;
    }
 
    if(i = midt - start + 1){
        for (k = j; k < slut - midt - 1; k++)
        {
            L[start + i + j] = Right[k];
        } 
    } else {
        for (k = i; k < midt - start; i++)
        {
            L[start + j + k] = Left[k];
        }
    }
}

void MergeSort(int L[], int start, int slut){
    if (start < slut) {
            int m = (start + slut) / 2;

            MergeSort(L, start, m);
            MergeSort(L, m + 1, slut);

            Merge(L, start, m, slut);
        }
}

void printList(int L[], int size){ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", L[i]); 
    printf("\n"); 
}
*/