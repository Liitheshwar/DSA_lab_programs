//menu driven progrsm to determine a number is palindrom, amstrong or perfect number
#include <iostream>
#include <stdlib.h>

class room
{
    private:
        int *num;

    public:
        room()
        { 
            num = (int *)malloc(sizeof(int));
            *num = 0;
        }

        ~room()
        {
            free(num);
        }

        void setnum(int temp);

        int palindrom();
        int amstrong();
        int perfect_num();

};

int main(){

    int *ch = (int *)malloc(sizeof(int));
    int *num = (int *)malloc(sizeof(int));
    int *ret = (int *)malloc(sizeof(int));
    room myroom;

    while(true)
    {
        std::cout << "############ program ############" << std::endl;
        std::cout << "Enter a number: ";
        std::cin >> *num;
        myroom.setnum(*num);
        *ret = 0;
        *ch = 0;

        std::cout << "\n1. Palindrome" << "\n2. Armstrong" << "\n3. Perfect Number" << "\n4. Exit" << std::endl;
        std::cout << "\nEnter your choice: ";
        std::cin >> *ch;

        if (*ch == 4) break;

        //menu to get the function
        switch (*ch)
        {
        case 1:
            *ret = myroom.palindrom();
            if (*ret == 1){
                std::cout << "The number is a Palindrom" << std::endl;
            }
            else {
                std::cout << "The nummber is not a palindrom" << std::endl;
            }
            break;

        case 2:
            *ret = myroom.amstrong();
            if (*ret == 1){
                std::cout << "The number is an Amstrong number" << std::endl;
            }
            else {
                std::cout << "The nummber is not an Amstrong number" << std::endl;
            }
            break;

        case 3:
            *ret = myroom.perfect_num();
            if (*ret == 1){
                std::cout << "The number is a perfect number" << std::endl;
            }
            else {
                std::cout << "The nummber is not a perfect number" << std::endl;
            }
            break;
            break;

        case 4:
            break;
        default:
            std::cout << "\nInvalid Choice\n";
            break;
        }

        std::cout << "#################################\n" << std::endl;
    }

    free(num);
    free(ch);
    return 0;
}

//function set a value to num in private class
void room::setnum(int temp)
{
    *num = temp;
}

//function to find palindrom or not
int room::palindrom()
{
    int *temp = (int *)malloc(sizeof(int));
    int *rem = (int *)malloc(sizeof(int));
    int *rev = (int *)malloc(sizeof(int));
    *rev = 0;
    *temp = *num;

    while(*temp)
    {
        *rem = (*temp)%10;
        *rev = (*rev)*10+(*rem);
        *temp = (*temp)/10;
    }

    if(*num == *rev) {
        
        free(temp);
        free(rev);
        free(rem);
        return 1;
    }

    free(temp);
    free(rev);
    free(rem);
    return -1;
}

//function to find amstrong or not
int room::amstrong()
{
    int *temp = (int *)malloc(sizeof(int));
    int *len = (int *)malloc(sizeof(int));
    int *sum = (int *)malloc(sizeof(int));
    int *rem = (int *)malloc(sizeof(int));
    int *pow = (int *)malloc(sizeof(int));

    *sum = 0;
    *temp = *num;
    *len = 0;

    // Calculate number of digits (length)
    while (*temp != 0)
    {
        *temp /= 10;
        (*len)++;
    }

    *temp = *num;
    
    while (*temp != 0)
    {
        *rem = *temp % 10;
        *pow = 1;
        for (int i = 0; i < *len; i++)
        {
            *pow *= *rem;
        }
        *sum += *pow;
        *temp /= 10;
    }

    if (*sum == *num)
    {
        free(temp);
        free(len);
        free(sum);
        free(rem);
        free(pow);
        return 1;
    }

    free(temp);
    free(len);
    free(sum);
    free(rem);
    free(pow);
    return 0;
}

//function to find perfect number or not
int room::perfect_num()
{
    int *sum = (int *)malloc(sizeof(int));
    int *i = (int *)malloc(sizeof(int));
    

    for (*i = 1; *i<((*num/2)+1); (*i)++)
    {
        if((*num)%(*i) == 0) {
            *sum += *i;
        }
    }

    if(*sum == *num) {
        free(sum);
        free(i);
        return 1;
    }

    free(sum);
    free(i);
    return -1;
}