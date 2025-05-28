// 25011384 Jake Isaac Harvey 159101 Assignment 1

#include <iostream>
using namespace std;

int difference, inputday, inputmonth, inputyear, finalday, finalmonth, finalyear, leapyear, monthdays;

int main()  {
    cout << "Please enter the difference in days: ";
    cin >> difference;
    cout << "Please input a date in the form 'Day Month Year' : ";
    cin >> inputday >> inputmonth >> inputyear;

    if (inputyear % 4 == 0)  {  // This section checks if the inputted year is a leap year, if it is true then it will assign the month to be february and therefore 29.
        if (inputyear % 100 == 0)  {
            if (inputyear % 400 == 0)  {
                leapyear = 1;
            }  else  {
                leapyear = 0;
            }
        }   else {
            leapyear = 1;
        }
    }   else  {
        leapyear = 0;
    }

    if ((inputmonth == 1) || (inputmonth == 3) || (inputmonth == 5) || (inputmonth == 7) || (inputmonth == 8) || (inputmonth == 10) || (inputmonth == 12))  {
        monthdays = 31; // Checks what month is entered, if one of the above then days of the month == 31.
    }
    if ((inputmonth == 4) || (inputmonth == 6) || (inputmonth == 9) || (inputmonth == 11))  {
        monthdays = 30; // Checks what month is entered, if one of the above then days of the month == 30.
    }
    if ((inputmonth == 2) && (leapyear == 1)) {
        monthdays = 29; // Assigns February to be a leap year with 29 days.
    }
    if ((inputmonth == 2) && (leapyear == 0))  {
        monthdays = 28; // Assigns February to not be leap year with 28 days.
    }

    if ((inputday + difference >= 1) || (inputday + difference <= 30)) { // No month or year change is needed, easiest calculation, falls into addition and subtraction only.
        finalday = inputday + difference;
        finalmonth = inputmonth;
        finalyear = inputyear;
    }
    
    if ((monthdays == 31) && (inputday + difference > 31))  { // Checks for increase over 31 days, increases the month by 1 and works out the correct day.
        finalmonth = inputmonth + 1;
        finalday = (inputday + difference) - 31;
        finalyear = inputyear;
    }

    if ((monthdays == 31) && (inputday + difference > 31) && (inputmonth == 12))  { // Same as above but checks if it is December, if so it increases the year and sets the month to 1.
        finalmonth = 1;
        finalday = (inputday + difference) - 31;
        finalyear = inputyear + 1;
    }

    if ((monthdays == 31) && (inputday + difference < 1) && (inputmonth == 1))  { // If month is January and days subtract past 1, this will set month to December, year minus one and correct day.
        finalmonth = 12;
        finalday = (inputday + difference) + 31;
        finalyear = inputyear - 1;
    }

    if ((monthdays == 30) && (inputday + difference > 30))  { // Checks for increase over 30 days, increases month by 1 and works out correct day.
        finalmonth = inputmonth + 1;
        finalday = (inputday + difference) - 30;
        finalyear = inputyear;
    }

    if ((monthdays == 29) && (inputday + difference > 29))  { // Same as above, but for 29 days with the February leap year.
        finalmonth = inputmonth + 1;
        finalday = (inputday + difference) - 29;
        finalyear = inputyear;
    }

    if ((monthdays == 28) && (inputday + difference > 28))  { // Same as above but for 28 days, non leap year February.
        finalmonth = inputmonth + 1;
        finalday = (inputday + difference) - 28;
        finalyear = inputyear;
    }

    if ((monthdays == 31) && (inputday + difference < 1) && (inputmonth == 12 || inputmonth == 10 || inputmonth == 7 || inputmonth == 5))  { // Subtract days away from a month with 31 days with a 30 day month behind it.
        finalmonth = inputmonth - 1;
        finalday = (inputday + difference) + 30;
        finalyear = inputyear;
    }

    if ((monthdays == 30) && (inputday + difference < 1) && (inputmonth == 11 || inputmonth == 9 || inputmonth == 6 || inputmonth == 4)) { // Subtract days away from a month with 30 days with a 31 day month behind it.
        finalmonth = inputmonth - 1;
        finalday = (inputday + difference) + 31;
        finalyear = inputyear;
    }

    if ((monthdays == 31) && (inputday + difference < 1) && (inputmonth == 8))  { // Subtract days away from a month with 31 days, with a 31 day month behind it.
        finalmonth = inputmonth - 1;
        finalday = (inputday + difference) + 31;
        finalyear = inputyear;
    }

    if ((leapyear == 1) && (monthdays == 31) && (inputday + difference < 1) && (inputmonth == 3))  { // Subtract days away from March into February on a leap year.
        finalmonth = inputmonth - 1;
        finalday = (inputday + difference) + 29;
        finalyear = inputyear;
    } 

    if ((leapyear == 0) && (monthdays == 31) && (inputday + difference < 1) && (inputmonth == 3))  { // Subtract days away from March into February on a non leap year.
       finalmonth = inputmonth - 1;
       finalday = (inputday + difference) + 28;
       finalyear = inputyear;
    }

    cout << "\nThe final date is: " << finalday << "/" << finalmonth << "/" << finalyear; // Final cout for the program that displays the new date
}