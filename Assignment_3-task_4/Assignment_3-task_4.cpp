
#include <iostream>
#include <stdexcept>
#include "Time.h"
int main()
{
    int min, sec, hours;
    char choice;
    int choicee;

    do {
        Time T;
        cout << "Enter \n1 to Enter the time and \n2 to Print the highest value of time in the File(X Factor)" << endl;
        cin >> choicee;
        switch (choicee) {
        case 1:
            try {
                cout << "Enter the hours" << endl;
                cin >> hours;
                cout << "Enter the minutes" << endl;
                cin >> min;
                cout << "Enter the seconds" << endl;
                cin >> sec;
                T.setHour(hours);
                T.setMinute(min);
                T.setSecond(sec);
            }

            catch (invalid_argument& e)
            {
                cout << "\nException while initializing time: " << e.what() << endl;
               
            }
            T.printStandard();
            T.writetoFile();
            break;

        case 2:
            T.findHighestTimeFromFile();
            break;
        
        }
       

        cout << "\nYou want to iterate the time Enter Y for Yes and N for Exit" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            Time t2(23, 59, 55);

            for (int i = 0; i < 5; i++)
            {
                t2.tick();
                t2.printStandard();
                cout << endl;
            }
        }
        cout << "\nEnter the choice Y to Enter the data again and N to exit" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');





    return 0;
}

