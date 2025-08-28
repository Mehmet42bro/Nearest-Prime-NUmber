//! prime numbers are numbers that are only divisible to 1 and their selves (so only to 2 numbers)

#include <iostream> // a library to get inputs from user and give outputs

using namespace std;

int main()
{
    while (true)
    {
        int number = 0;                       // our input number
        int nearestprimeup, nearestprimedown; // we are looking for the nearest prime numbers 1 is larger and 1 is smaller than our number so we need 2 integers
        int up = 0, down = 0;                 // to understand if the larger or the smaller prime number is closer to our number we need two integers that count the difference
        bool isprime = false;                 // it stops the loop which checks if the number is a prime number
        cout << "Please enter a number: ";
        cin >> number;
        nearestprimeup = number; // to start looking for the nearest prime number that is larger than our number we are setting the "nearestprimeup" integer to our numbers value

        while (isprime == false) // a loop that checks every number until we get a prime number
        {
            int divideby = 0;                         // this integer counts, to how many numbers is our "nearestprimeup" integer divisible by
            for (int i = 1; i <= nearestprimeup; i++) // this loop checks to how many numbers is a specific number divisible by
            {
                if (nearestprimeup % i == 0) // this if statement is increasing the "divideby" integer if our number is divisible to another number
                {
                    divideby++;
                }
            }
            if (divideby == 2) // this if statement checks if our number is a prime number
            {
                isprime = true;
            }
            else
            {
                nearestprimeup++; // this line increases the number by one so the loop will continue until we get a prime number
                up++;             // this line increases the "up" integer so the code knows how many numbers are from our number to the larger nearest prime number
            }
        }

        if (number >= 2) // this if statement checks if the number is larger than 1 because if its smaller than 2 the loop will go forever since there aren't any prime numbers smaller than 2
        {
            nearestprimedown = number;
            isprime = false;
            while (isprime == false) // this loop does the same thing as the last one but goes down until we get a prime number so the code knows the smaller nearest prime number
            {
                int divideby = 0;
                for (int i = 1; i <= nearestprimedown; i++)
                {
                    if (nearestprimedown % i == 0)
                    {
                        divideby++;
                    }
                }
                if (divideby == 2)
                {
                    isprime = true;
                }
                else
                {
                    nearestprimedown--; // this line ensures that the number goes smaller if its not a prime number
                    down++;
                }
            }
        }
        if (nearestprimeup == number) // this if statement checks if the entered number is a prime number if yes its printing the input back
        {
            cout << "Your number is a prime number." << endl;
        }
        else if (up > down && down != 0) // this else if statement checks if the smaller nearest prime number is closer than the larger as long as the second while loop is used
        {
            cout << "The nearest prime number to your number is " << nearestprimedown << endl;
        }
        else if (down == up) // this else if statement checks if the distance between smaller and larger nearest prime numbers are the same
        {
            cout << "The nearest prime numbers to your number are " << nearestprimedown << " and " << nearestprimeup << endl;
        }
        else
        {
            cout << "The nearest prime number to your number is " << nearestprimeup << endl; // this line prints the larger nearest prime number
        }
    }
}