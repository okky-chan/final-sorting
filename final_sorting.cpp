#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

using namespace std;

int a = 0;
int selection = 0;

void option(); /* Menu Option */
void shellSort(); /* option for Shell Sort */
void quickSort(); /* option for Quick Sort */
void exit(); /* Exit */

void option() {

    cout << "\nPlease choose from the following options\n";
    cout << " 1. Shell Sort\n";
    cout << " 2. Quick Sort\n";
    cout << " 3. Exit\n";
    cout << "Your Option : \t";
    cin >> selection;


    if (selection == 1)
    {
       shellSort();
    }
        else if (selection == 2)
            {
                quickSort();
            }
                else if (selection == 3)
                {
                    exit();
                }
}

void shell_sort(int sort[], int size) {
    int a, i, j, gap;
    for(gap = size/2; gap > 0; gap /= 2)
    {
        for(i = gap; i < size; i++)
        {
            int temp = sort[i];
            for(j = i; j >= gap && sort[j-gap]>temp; j -= gap)
            {
                sort[j] = sort[j-gap];
            }

            cout << endl << "Compare " << sort[j] << " with " << temp << endl;
            sort[j] = temp;
            cout << "Swap " << temp << " with " << sort[i] << endl;

            cout << "Iteration : ";
            for (a = 0; a < size; a++)
                cout << "\t" << sort[a];
                cout << endl;
        }
    }
}

void shellSort() {
    int size;
    cout << "\nEnter the array size : ";
    cin >> size;
    int sort[size];

    for(int i = 0; i < size; i++) {
            cout << "Index of #" << (i+1) << ": ";
            cin >> sort[i];
    }
    shell_sort(sort, size);

    cout << "Array After Sorting : ";
    for(int i = 0; i < size; i++) {
        cout << sort[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b) {
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void display(int arr[]) {
cout << "Iteration : ";
            for (int c = 0; c < MAX; c++)
                cout << "\t" << arr[c];
                cout << endl;
}

int Partition(int a[], int l, int h) {
   int pivot, index, i, c;
   index = l;
   pivot = h;
   for(i = l; i < h; i++) {
      if(a[i] < a[pivot]) {
         swap(&a[i], &a[index]);
         index++;
         cout << "Item Swapped " << a[i] << " with " << a[index] << endl;
      }
   }
   display(a);
   swap(&a[pivot], &a[index]);
   return index;
}
int RandomPivotPartition(int a[], int l, int h) {
   int pvt, n, temp;
   n = rand();
   pvt = l + n%(h-l+1);
   swap(&a[h], &a[pvt]);
   cout << endl << "Pivot " << a[pvt] << endl;
   return Partition(a, l, h);
}
int QuickSort(int a[], int l, int h) {
   int pindex, i;
   if(l < h) {
      pindex = RandomPivotPartition(a, l, h);
      QuickSort(a, l, pindex-1);
      QuickSort(a, pindex+1, h);
   }
   return 0;
}
void quickSort() {
   int i;
   int arr[10];
   for(i = 0; i < MAX; i++) {
      cout<<"Enter element #"<<i+1<<": ";
      cin>>arr[i];
   }
   QuickSort(arr, 0, MAX-1);
   cout<<"\nSorted Data ";
   for (i = 0; i < MAX; i++)
      cout<<"->"<<arr[i];
}

void exit(){
       /* to exit from the program */
       cout << endl;
       cout << " See ya !\n";
       a = 1;
}
int main(){

    cout<<"\nThis Program created by \n";
    cout<<" Okky Dwi Triferyawan    \n";
    cout<<"     012201800005     \n";

    while(true)
    {
        cout << endl;
        if (a == 1)
        {
            break;
        }
        option();
    }
   return 0;
}
