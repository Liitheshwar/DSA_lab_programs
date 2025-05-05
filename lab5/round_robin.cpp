#include <iostream>
#include "cllroundrobin.h"

int main() {
    int fixed_time;
    std::cout << "Enter the fixed time: ";
    std::cin >> fixed_time;

    
    List round_robin;
    
    int loop = 1;
    while(loop)
    {
        int time,ch;

        std::cout << "\n########### ROUND ROBIN ###########\n";

        std::cout << "1.Insert Process\n"
                  << "2.Execute\n"
                  << "3.Exit\n" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> ch;

        switch (ch)
        {
        case 1:
            std::cout << "Enter the time to insert: ";
            std::cin >> time;

            round_robin.insertprocess(time);
            round_robin.display();

            break;
        
            case 2:
                round_robin.execute(fixed_time);
                round_robin.display();

                break;

            case 3:
                loop = 0;

                break;

        default:
            std::cout << "invalid Input !!!\n";

            break;
        }

        std::cout << "\n###################################\n";

    }
}