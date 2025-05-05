//header file to build different sort function

//bubble sort
void bsort(int arr[], int len)
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
}


//insertion sort
void isort(int arr[], int len)
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
}


//selection sort
void selection_sort(int arr[], int len)
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
}