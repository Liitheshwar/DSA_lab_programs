//program to search a element using different methods
#include <iostream>
#include "sort.h"

using namespace std;

int print_array(int arr[],int len);
int linear(int arr[], int len, int obj);
int binary(int arr[], int len, int obj);

int main(){

    int len = 0;
    cout << "Enter the length of array: ";

    cin >> len;
    int arr[len];

    cout << "Enter the elments of the array: " << endl;

    for(int i = 0; i < len; i++)
    {
        cin >> arr[i];
    } 

    isort(arr,len);
    cout << "\nAfter sorting array:" << endl;
    print_array(arr,len);

    int exit = 0;

    //menu to get which method of search to use
    while(true){

        cout << "\n1.linear search" << "\n2.Binary search" << "\n3.Exit" << "\nEnter your choice: ";

        int ch,obj;
        cin >> ch;
        if(ch == 3){
            break;
        }

        cout << "\nEnter element to find: ";
        cin >> obj;

        switch (ch)
        {
        case 1:
            linear(arr,len,obj);
            break;
    
        case 2:
            binary(arr,len,obj);
            break;

        case 3:
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

//function to search for an element linear method
int linear(int arr[],int len, int obj)
{
    for(int i=0; i<len; i++)
    {
        if(arr[i]== obj){
            cout << "The element is found at " << i << endl;
            return i;
        }
    }

    cout << "The element is not present" << endl;
    return -1;
}


//function to search for a element binary method
int binary(int arr[], int len, int obj)
{
    int low,high,mid;
    low =0;
    high = len;
    mid = (low+high)/2;

    print_array(arr,len);

    while(low <= high)
    {
        mid = (low+high)/2;

        if (arr[mid] == obj){
            cout << "The element is found at " << mid << endl;
            return mid;
        }

        if(arr[mid] > obj){
            high = mid-1;
        }

        if(arr[mid] < obj){
            low = mid+1;
        }
    }

    cout << "The element is not present" << endl;
    return -1;
}