// 25011384 Jake Isaac Harvey
// Assignment 2

#include <iostream>
#include <iomanip>

using std::cout;    // Only picked from the namespace certain things that I want.
using std::cin;
using std::setprecision;
using std::endl;
using std::fixed;

int i, judgeNumber, finalJudgeNumber;
float temp, Mark[8], finalMark, mini, maxi; // setup variables and array.

int main()  {
    cout << "Please enter the number of judges (Between 4 and 8): ";    // Judge no. input and data validation.
    cin >> judgeNumber;
    while ((judgeNumber < 4) || (judgeNumber > 8))  {
        cout << "\nInvalid. Enter the number of judges again (4 to 8): ";
        cin >> judgeNumber;
    }

    temp = 0;

    for (i = 0; i < judgeNumber; i++)  {    // Takes in a mark for each judge, number of judges selected above - with data validation.
        
        cout << "\nEnter the mark for each judge (0.0 to 10.0), followed by enter: ";
        cin >> Mark[i];
        while ((Mark[i] <= 0) || (Mark[i] >= 10.01))  { // Data validation - checks if number is between the range of 0 to 10.
            cout << "\nERROR: mark must be between (0.0 to 10.0) enter mark, followed by enter: ";
            cin >> Mark[i];
        }

        temp += Mark[i]; // Running total for the array of marks.
    }

    maxi = Mark[0];
    mini = Mark[0];

    for (i = 0; i < judgeNumber; i++)  {    // sorting algorithim to find the minimum and maximum value in array.
        if (Mark[i] > maxi)  {
            maxi = Mark[i];
        }

        if (Mark[i] < mini)  {
            mini = Mark[i];
        }
    }
    
    finalJudgeNumber = judgeNumber - 2; // ignoring two of the judges entries for the average

    temp = temp - mini; // remove the lowest mark.

    temp = temp - maxi; // remove the highest mark.

    finalMark = temp / finalJudgeNumber; // average - total marks / number of judges.

    cout << "The final mark is: ";
    cout << std::setprecision(2) << fixed << finalMark; // Final answer displayed to 2 decimal places.
}


