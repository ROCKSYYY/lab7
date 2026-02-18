/************************
* Автор: Долинин Н.К.   *  
* Название: Вариант 5   *
*************************/

#include <iostream>
#include <iomanip>

using namespace std;

bool isLeapYear(int year) {
  int leapYearInterval, centuryInterval;
  
  leapYearInterval = 4;
  centuryInterval = 100;
  
  return (year % leapYearInterval == 0 && year % centuryInterval != 0) || (year % (centuryInterval * leapYearInterval) == 0);
}

int getDaysInMonth(int month, int year) {
  int februaryNumber, daysInLeapFebruary, daysInCommonFebruary, daysInShortMonth, daysInLongMonth, aprilNumber, juneNumber, septemberNumber, novemberNumber;
  
  daysInLeapFebruary = 29;
  daysInCommonFebruary = 28;
  februaryNumber = 2;
  daysInShortMonth = 30;
  daysInLongMonth = 31;
  aprilNumber = 4;
  juneNumber = 6;
  septemberNumber = 9;
  novemberNumber = 11;
  
  if (month == februaryNumber) {
    return isLeapYear(year) ? daysInLeapFebruary : daysInCommonFebruary;
  }
  if (month == aprilNumber || month == juneNumber || month == septemberNumber || month == novemberNumber) {
    return daysInShortMonth;
  }
  return daysInLongMonth;
}

int getFirstDayOfMonth(int month, int year) {
  int marchMonthNumber, monthsInYear, centuryDivisor, firstDayOfMonth, zellerMonthCoefficient, zellerMonthDivisor, leapYearCycleQuarter, centuryCoefficient, daysInWeek, isoWeekdayOffset;
  
  centuryDivisor = 100;
  monthsInYear = 12;
  marchMonthNumber = 3;
  isoWeekdayOffset = 5;
  daysInWeek = 7;
  centuryCoefficient = 5;
  leapYearCycleQuarter = 4;
  zellerMonthCoefficient = 13;
  firstDayOfMonth = 1;
  zellerMonthDivisor = 5;
  
  
  if (month < marchMonthNumber) {
    month += monthsInYear;
    year--;
  }
  int lastTwoDigits = year % centuryDivisor;
  int century = year / centuryDivisor;
  int dayOfWeek = (firstDayOfMonth + zellerMonthCoefficient * (month + firstDayOfMonth) / isoWeekdayOffset + lastTwoDigits + lastTwoDigits / leapYearCycleQuarter + century / leapYearCycleQuarter + centuryCoefficient * century) % daysInWeek;
  return (dayOfWeek + zellerMonthDivisor) % daysInWeek;
}

string getMonthName(int month) {
  int arrayIndexOffset;
  
  arrayIndexOffset = 1;
  
  string monthNames[] = {
    "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
    "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
  };
  return monthNames[month - arrayIndexOffset];
}

void printMonthCalendar(int month, int year) {
  int firstDay, daysInMonth, dayAWeek, dateFieldWidth;

  cout << endl << getMonthName(month) << endl << " Пн  Вт  Ср  Чт  Пт  Сб  Вс" << endl;
  
  firstDay = getFirstDayOfMonth(month, year);
  daysInMonth = getDaysInMonth(month, year);
  dayAWeek = 7;
  dateFieldWidth = 3;
  
  for (int spaceCounter = 0; spaceCounter < firstDay; ++spaceCounter) {
    cout << "    ";
  }
  
  for (int currentDay = 1; currentDay <= daysInMonth; ++currentDay) {
    cout << setw(dateFieldWidth) << currentDay << " ";
    if ((firstDay + currentDay) % dayAWeek == 0) {
      cout << endl;
    }
  }
  cout << endl;
}

int main() {
  int selectedYear, numberOfMonthsInAYear;
  
  cout << "Введите год: ";
  cin >> selectedYear;
  
  numberOfMonthsInAYear = 12;
  
  cout << endl;
  cout << "КАЛЕНДАРЬ НА " << selectedYear << " ГОД" << endl << "============================" << endl;
  
  for (int currentMonth = 1; currentMonth <= numberOfMonthsInAYear; ++currentMonth) {
    printMonthCalendar(currentMonth, selectedYear);
  }
  
  return 0;
}
