/* Alexa Brown
 * CSC 112
 * Due 10/03/19
 */


#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;

// MergeSort function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd);

// BubbleSort function declaration
void swap (int *a, int *b);
void bubbleSort(int *a, int n);

int main(int argc, char* argv[]) {
    // get input: first is random seed, second is vector length

    if (argc != 3){
        cout << "Please try again." << endl;
        cout << "Usage: BubbleSort <seed> <length>" << endl;
        exit(1);
    }
    int seed, length;


    seed = atoi(argv[1]);
    length = atoi(argv[2]);

    srand(seed);

    vector<int> v(length); // vector to be sorted
    vector<int> t(length); // temporary workspace

    // define an integer pointer dynamically allocate an array of integers
    int* arr = new int [length];

    // initialize and print input
    cout << "Unsorted:" << endl;
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    //unit testing
    cout << "Unit testing started." << endl;

    //swap unit test
    cout << "Original numbers 12 4. Expecting 4 12" << endl;
    int x = 12;
    int y = 4;
    int* m = &x;
    int* n = &y;
    swap(m, n);
    cout << "Got: " << *m << " " << *n << endl;

    // copy the random list of integers from vector to array
    for (int i = 0; i < length; i++){
        arr[i] = v.at(i);
    }

    clock_t start_mergeSort = clock();
    // sort vector using mergeSort
    mergeSort(v,t, 0, v.size() - 1);
    clock_t end_mergeSort = clock();

    // check output, make sure vector is sorted after mergeSort
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

   /*for (int i = 1; i < length ; i++){
        assert(arr[i-1] <= arr[i]);
    }*/

   // check output, make sure array is sorted after bubbleSort
   /* for(int i = 0; i < length; i++) {
        assert(arr[i] <= arr[i+1]);
    }*/
  //  assert(arr[i] <= arr[i+1]);

    clock_t start_bubbleSort = clock();
    // sort array using bubbleSort
    bubbleSort(arr, length);
    clock_t end_bubbleSort = clock();


    // print sorted vector after mergeSort
    cout << "Sorted with mergeSort:" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // print sorted array after bubbleSort
    cout << "Sorted with BubbleSort: " << endl;
    for (int i = 0; i < length; i++){
        cout << arr[i] << '\t';
    }

   // cout << "mergeSort time: " << end_mergeSort-start_mergeSort<< endl;
    // print elapsed time for mergeSort and bubbleSort
    double elapsed_mergeSort = double(end_mergeSort - start_mergeSort) / CLOCKS_PER_SEC;
    double elapsed_bubbleSort = double(end_bubbleSort - start_bubbleSort) / CLOCKS_PER_SEC;

    cout << endl;

    cout << "mergeSort time: " << elapsed_mergeSort << endl;
    cout << "bubblesort time: " << elapsed_bubbleSort << endl;
    //to print << filename.txt


    delete arr;

    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tempPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmp[tempPos++] = a[leftPos++];
        } else {
            tmp[tempPos++] = a[rightPos++];
        }

    }

    while (leftPos <= leftEnd) {
        tmp[tempPos++] = a[leftPos++];
    }
    while (rightPos <= rightEnd) {
        tmp[tempPos++] = a[rightPos++];
    }

    for (int i = 0; i < numElements; i++, --rightEnd) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    if (left < right) {
        int center = ( left + right ) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        mergeSortedLists(a, tmp, left, center + 1, right);
    }
}

// Swap function
void swap(int *a, int *b) {
    int temp = *a; // save the value of num1
    *a = *b; // copy over num2 to num1
    *b = temp; // copy the saved value of num1 --- switching their values not their pointers
}

// BubbleSort function
void bubbleSort(int *a, int n) {

    bool IsSorted;

    for(int i=0; i<n; i++){
        IsSorted = true; // during every iteration, array has potential of being sorted
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j]>=a[j+1])
            {
                swap(a[j], a[j+1]);
                IsSorted = false; // if swapped, the array was not sorted so sorted is false
            }
        }
        if(IsSorted) { // if no swaps were made, array was sorted, so break
            break;
        }
    }



    /* your code here */
    /*
     * with recursion instead of while loop
    if (n == 1){
        return;
    }
    for (int i = 0; i < n; i++){
        if (a[i] > a[i + 1]){
            swap (a[i], a[i+1]);
        }
    }
    bubbleSort(a, n-1);*/
}