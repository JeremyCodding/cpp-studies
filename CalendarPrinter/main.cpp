#include <iostream>
#include <string>
#include <array>
#include <iomanip>

const std::array<std::string, 12> listOfMonths = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};

std::array<int, 12> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const std::array<std::string, 7> daysOfWeek = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

bool isLeapYear(int year)
{
    return (year % 4 == 0);
}

int main()
{
    int firstDay;
    int year;

    std::cout << "Type the year:" << std::endl;
    std::cin >> year;
    std::cout << "Type the first day of the year [1: Monday, ..., 7: Saturday]:" << std::endl;
    std::cin >> firstDay;

    if (isLeapYear(year))
    {
        daysInMonth[1] = 29; // February has 29 days in a leap year
    }

    for (int month = 0; month < 12; month++)
    {
        int days = daysInMonth[month];

        std::cout << " -- " << listOfMonths[month] << " " << year << " -- " << std::endl;
        std::cout << "Last day is " << daysInMonth[month] % 7 << std::endl;
        for (const auto day : daysOfWeek)
        {
            std::cout << std::setw(10) << day;
        }
        std::cout << std::endl;

        for (int day{1}; day < daysInMonth[month] + firstDay; day++)
        {
            if (firstDay > day)
            {
                std::cout << std::setw(10) << " ";
            }
            else
            {
                std::cout << std::setw(10) << day - firstDay + 1;
            }

            if (day % 7 == 0)
            {
                std::cout << std::endl;
            }
        }

        firstDay = (firstDay + days) % 7;
        if (firstDay == 0)
            firstDay = 7;

        std::cout << std::endl;
    }
    return 0;
}
