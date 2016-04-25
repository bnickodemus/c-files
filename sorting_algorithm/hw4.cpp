#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void quickSort(int x[],int first,int last) {
    int pivot,j,temp,i;
    
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        
        while(i<j){
            while(x[i]<=x[pivot]&&i<last)
                i++;
            while(x[j]>x[pivot])
                j--;
            if(i<j){
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
        
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        quickSort(x,first,j-1);
        quickSort(x,j+1,last);
        
    }
}

void radixSort(int *input, int n)
{
    int i;
    // find the max number in the given list.
    // to be used in loop termination part.
    int maxNumber = input[0];
    for (i = 1; i < n; i++)
    {
        if (input[i] > maxNumber)
            maxNumber = input[i];
    }
    // run the loop for each of the decimal places
    int exp = 1;
    int *tmpBuffer = new int[n];
    while (maxNumber / exp > 0)
    {
        int decimalBucket[10] = {  0 };
        // count the occurences in this decimal digit.
        for (i = 0; i < n; i++)
            decimalBucket[input[i] / exp % 10]++;
        
        // Prepare the position counters to be used for re-ordering the numbers
        // for this decimal place.
        for (i = 1; i < 10; i++)
            decimalBucket[i] += decimalBucket[i - 1];
        // Re order the numbers in the tmpbuffer and later copy back to original buffer.
        for (i = n - 1; i >= 0; i--)
            tmpBuffer[--decimalBucket[input[i] / exp % 10]] = input[i];
        for (i = 0; i < n; i++)
            input[i] = tmpBuffer[i];
        // Move to next decimal place.
        exp *= 10;
    }
}

/*
 * Purpose: used with mergeSort()
 */
void merge(int a[], int low, int mid, int high)
{
    int b[10000];
    int i = low, j = mid + 1, k = 0;
    
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    
    while (j <= high)
        b[k++] = a[j++];
    
    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        k--;
    }
}
void mergeSort(int a[], int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergeSort(a, low, m);
        mergeSort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

void bubbleSort(int v[], int n){
    int temp = 0;
    for (int i = 0 ; i < ( n - 1 ); i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (v[j] > v[j+1]) {
                // swap
                temp        = v[j];
                v[j]   = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

void selectionSort(int *num, int size)
{
    // Step through each element of the array
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        int smallestIndex = startIndex;
        // Look for smallest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller than our previously found smallest
            if (num[currentIndex] < num[smallestIndex])
                // This is the new smallest number for this iteration
                smallestIndex = currentIndex;
        }
        // Swap our start element with our smallest element
        int temp = 0;
        temp = num[startIndex];
        num[startIndex] = num[smallestIndex];
        num[smallestIndex] = temp;
    }
}

/*
 * In: An array that we want to fill
 * Out: The numbers array will be filled with the 10,000 numbers
 * Purpose: This function will be used to initialize and reinitalize our numbers array so that each
 * sorting algorithm looks at the same data
 */
int * fillArray(int * numbers) {
    int num = 0;
    int size = 0;
    string line;
    ifstream ifile ("/Users/Broc/Desktop/data.txt"); // replace this with the location of data.txt
    if (ifile.is_open()) {
        while (ifile >> num) {
            //cout << line;
            numbers[size] = num;
            size++;
        }
        ifile.close();
    }
    return numbers;
}

/*
 * Purpose: check to make sure a sorting algorithm is working properly
 */
void print(int numbers[],int size) {
    for (int i = 0; i<size; i++)
        cout << numbers[i] << " " << endl;
}

int main(int argc, const char * argv[]) {
    int numbers[10000];
    int size = 10000;
    
    fillArray(numbers); // init array
    clock_t t;
    t = clock();
    bubbleSort(numbers, size);
    t = clock() -t;
    cout << "bubbleSort time:" << ((float)t)/CLOCKS_PER_SEC << endl;
    //print(numbers, size);
    
    fillArray(numbers); // reinit array
    t = 0;
    t = clock();
    selectionSort(numbers, size);
    t = clock() -t;
    cout << "selectionSort time:" << ((float)t)/CLOCKS_PER_SEC << endl;
    //print(numbers, size);
    
    fillArray(numbers); // reinit array
    t = 0;
    t = clock();
    mergeSort(numbers, 0, size-1);
    t = clock() -t;
    cout << "mergeSort time:" << ((float)t)/CLOCKS_PER_SEC << endl;
    //print(numbers, size);
    
    fillArray(numbers); // reinit array
    t = 0;
    t = clock();
    radixSort(numbers, size);
    t = clock() -t;
    cout << "radixSort time:" << ((float)t)/CLOCKS_PER_SEC << endl;
    //print(numbers, size);
    
    fillArray(numbers); // reinit array
    t = 0;
    t = clock();
    quickSort(numbers, 0, size);
    t = clock() -t;
    cout << "quickSort time:" << ((float)t)/CLOCKS_PER_SEC << endl;
    //print(numbers, size);
}





