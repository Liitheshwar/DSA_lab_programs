//program to sort a array using different methods
#include <iostream>

using namespace std;

int print_array(int arr[], int len);
int bubble_sort(int arr[], int len);
int insertion_sort(int arr[], int len);
int selection_sort(int arr[], int len);

int main() 
{
    int len = 0;
    int arr[50];
    int exit = 0;

    //menu to get which method of sort to use
    while(true){

        cout << "\n1.bubble sort" << "\n2.insertion sort" << "\n3.selection sort" << "\n4.Exit" << "\nEnter your choice: ";

        int ch;
        cin >> ch;

        if(ch == 4){
            break;
        }

        cout << "Enter the length of array: ";

        cin >> len;

        cout << "Enter the elments of the array: " << endl;

        for(int i = 0; i < len; i++)
        {
            cin >> arr[i];
        } 
        print_array(arr,len);

        switch (ch)
        {
        case 1:
            bubble_sort(arr,len);
            break;
    
        case 2:
            insertion_sort(arr,len);
            break;

        case 3:
            selection_sort(arr,len);
            break;

        case 4:
            exit = 1;

        default:
            break;
        }

        if(exit == 1){
            break;
        }
    }

    return 0;
}

//function to print the array
int print_array(int arr[], int len)
{
    cout << "[";
    for(int i=0; i<len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}


//function to sort the array through bubble sort
int bubble_sort(int arr[], int len)
{
    for(int i = 0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "The bubble sorted array is:" << endl;
    print_array(arr,len);
    cout << "\n";

    return 0;
}

//function to sort the array through insertion sort
int insertion_sort(int arr[], int len)
{
    int j, key;
    for(int i=0; i<len; i++)
    {
        j = i-1;
        key = arr[i];

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }

    cout << "The insertion sorted array is:" << endl;
    print_array(arr,len);
    cout << "\n";

    return 0;
}


//function to sort the array through selection sort
int selection_sort(int arr[], int len)
{
    int min_id,temp;
    for( int i=0; i<len; i++)
    {
        min_id = i;
        for (int j=i+1; j<len; j++)
        {
            if( arr[j] < arr[min_id]){
                min_id = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_id];
        arr[min_id] = temp;
    }

    cout << "The selection sorted array is:" << endl;
    print_array(arr,len);
    cout << "\n";

    return 0;
}