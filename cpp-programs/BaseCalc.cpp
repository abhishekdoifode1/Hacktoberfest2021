#include <iostream>
using namespace std;

int main() {
    bool run_again = true;
    do
    {
        //User entered variables
        int user_input = 0; //User entered positive number
        string run_choice;  //Choice to run program again
        int modified_int = 0; //User_input that is changed
        int base = 0; //User entered base

        //Constants + (Magic numbers)
        int converted = 0; //Number converted to chosen base
        int maximum = 500000000; //Maximum amount of digits
        int between = 0; //Special case (Discovered while testing)

        //After ones
        int after_one_1 = 0; //Used to detect betweens
        int after_one_2 = 0; //This took forever to figure out
        int after_one_3 = 0;

        //Storage
        int outbox_1 = 0; //Duplicates of each other
        int outbox_2 = 0; //One int can only handle up to 2,147,483,647
        int outbox_3 = 0; //Maximum amount of digits is 31
        int outbox_4 = 0; //Each holds 9 digits for overflow purposes

        //Betweens
        int between_1 = 0; //Duplicates of each other
        int between_2 = 0; //Checks for betweens in each loop
        int between_3 = 0; //Same process just divided

        //Booleans
        bool overflow_2 = false; //Duplicates of each other
        bool overflow_3 = false; //Used for the printing process
        bool overflow_4 = false; //COUTs at the end


        //--------------------------------------------------------
        //#1 - Prompt for non-negative number w/ bounds check
        do
        {
            cout << "Enter a positive number: ";
            cin >> user_input;
            if (user_input < 0)
            {
                cout << "That's not a proper input. Try again." << endl;
            }
        } while (user_input < 0 || user_input > 2147483647);
        modified_int = user_input;
        //--------------------------------------------------------
        //#2 - Prompt for base (2-9) number w/ bounds check
        do
        {
            cout << "Enter a base from 2-9: ";
            cin >> base;
            if (base < 2 || base > 10)
            {
                cout << "That's not a proper input. Try again." << endl;
            }
        } while (base < 2 || base > 9);
        //--------------------------------------------------------
        //#3 and 4 - Convert to the base and reverse
        for (int i = 1; i <= maximum; i *= 10)
        {
            converted = (modified_int % base);
            if (converted >= 1)
            {
                after_one_1 = 0;
            }
            else
            {
                after_one_1++;
            }
            converted *= i;
            outbox_1 += converted;
            modified_int /= base;
        }
        //--------------------------------------------------------
        if (modified_int != 0)
        {
            overflow_2 = true;
            for (int i = 1; i <= maximum; i *= 10)
            {
                converted = (modified_int % base);
                if (after_one_1 > 0 && converted >= 1)
                {
                    between_1 = after_one_1;
                    after_one_1 = 0;
                }
                if (converted > 1)
                {
                    after_one_2 = 0;
                }
                else
                {
                    after_one_2++;
                }
                converted *= i;
                outbox_2 += converted;
                modified_int /= base;
            }
        }
        //--------------------------------------------------------
        if (modified_int != 0)
        {
            overflow_3 = true;
            for (int i = 1; i <= maximum; i *= 10)
            {
                converted = (modified_int % base);
                if (after_one_1 > 0 && converted >= 1)
                {
                    between_2 = after_one_2;
                    after_one_2 = 0;
                }
                if (converted > 1)
                {
                    after_one_3 = 0;
                }
                else
                {
                    after_one_3++;
                }
                converted *= i;
                outbox_3 += converted;
                modified_int /= base;
            }
        }
        //--------------------------------------------------------
        if (modified_int != 0)
        {
            overflow_4 = true;
            for (int i = 1; i <= maximum; i *= 10)
            {
                converted = (modified_int % base);
                if (after_one_1 > 0 && converted >= 1)
                {
                    between_3 = after_one_3;
                    after_one_3 = 0;
                }
                converted *= i;
                outbox_4 += converted;
                modified_int /= base;
            }
        }
        //--------------------------------------------------------
        //#5 and 6 - Printing in a sentence
        if (overflow_2 == false && overflow_3 == false && overflow_4 == false)
        {
            cout << "The number " << user_input << " in base " << base << " is " << outbox_1 << endl;
        }
        //-------------------------------------------------------
        else if (overflow_2 == true && overflow_3 == false && overflow_4 == false)
        {
            cout << "The number " << user_input << " in base " << base << " is " << outbox_2;
            if (between_1 >= 1)
            {
                while (between_1 != 0)
                {
                    cout << between;
                    between_1--;
                }
            }
            cout << outbox_1 << endl;
        }
        //--------------------------------------------------------
        else if (overflow_2 == true && overflow_3 == true && overflow_4 == false)
        {
            cout << "The number " << user_input << " in base " << base << " is " << outbox_3;
            if (between_2 >= 1)
            {
                while (between_2 != 0)
                {
                    cout << between;
                    between_2--;
                }
            }
            cout << outbox_2;
            if (between_1 >= 1)
            {
                while (between_1 != 0)
                {
                    cout << between;
                    between_1--;
                }
            }
            cout << outbox_1 << endl;
        }
        //--------------------------------------------------------
        else if (overflow_2 == true && overflow_3 == true && overflow_4 == true)
        {
            cout << "The number " << user_input << " in base " << base << " is " << outbox_4;
            if (between_3 >= 1)
            {
                while (between_3 != 0)
                {
                    cout << between;
                    between_3--;
                }
            }
            cout << outbox_3;
            if (between_2 >= 1)
            {
                while (between_2 != 0)
                {
                    cout << between;
                    between_2--;
                }
            }
            cout << outbox_2;
            if (between_1 >= 1)
            {
                while (between_1 != 0)
                {
                    cout << between;
                    between_1--;
                }
            }
            cout << outbox_1 << endl;
        }
        cout << "Would you like to convert another number? (Yes - No) " << endl;
        cin >> run_choice;
        if (run_choice == "Y" || run_choice == "y" || run_choice == "Yes" || run_choice == "yes")
        {
            run_again = true;
        }
        else
        {
            run_again = false;
        }
    } while (run_again == true);
}