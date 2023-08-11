#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

/*Създайте структурата MyTime, която пази информация за :
година
месец
ден
час
минути
секунди

Изполвайте подходящи типове и член данни, така че размерът на структурата да е възможно най-малък.  
Изпечатайте размера на структурата в main.

Реализирайте следните функции:
int isLeapYear(MyTime t) - връща 1 ако годината е високосна и 0 ако годината не е високосна
int totalDaysInYear(MyTime t) - връща броя на дните в годината
void printMonth(MyTime t) - печата символен низ, отговарящ на месеца
int secondsPassed(MyTime t) - печата общия брой изминали секунди от 1 януари 1970 година.

Направете примерни извиквания в main*/

typedef struct MyTime{
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minutes;
    uint8_t seconds;
}MyTime;

int isLeapYear(MyTime t){
    uint16_t year = 1900 + t.year; 

    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1; 
    } 
    else{
        return 0; 
    }
}

int totalDaysInYear(MyTime t){
    return isLeapYear(t) ? 366 : 367;
}

void printMonth(MyTime t){
    char* months[] ={
                        "January", "February", "March", "April",
                        "May", "June", "July", "August",
                        "September", "October", "November", "December"};

    if(t.month >= 1 && t.month <= 12){
        printf("Month: %s\n", months[t.month - 1]);
    } 
    else{
        printf("Invalid month!\n");
    }
}

int secondsPassed(MyTime t){
    int seconds = 0;

    for(uint8_t year = 0; year < t.year; year++){
        MyTime temp = {year, 12, 31, 23, 59, 59}; 
        seconds += totalDaysInYear(temp) * 24 * 60 * 60;
    }

    for(uint8_t month = 1; month < t.month; month++){
        MyTime temp = {t.year, month, 1, 0, 0, 0};
        seconds += totalDaysInYear(temp) * 24 * 60 * 60;
    }

    seconds += (t.day - 1) * 24 * 60 * 60;

    seconds += t.hour * 60 * 60 + t.minutes * 60 + t.seconds;

    return seconds;
}

int main(int argc, char* argv[]){
    MyTime time;
    printf("The size of the struct Time is: %lu", sizeof(time));

    MyTime t1 = {22, 7, 30, 12, 45, 0}; // 2022-07-30 12:45:00
    MyTime t2 = {24, 2, 29, 15, 45, 0}; // 2024-02-29 15:45:00

    printf("The size of the struct MyTime is: %lu bytes\n", sizeof(MyTime));

    printf("For t1:\n");
    printMonth(t1);
    printf("Total days in the year: %d\n", totalDaysInYear(t1));
    printf("Total seconds passed since January 1, 1970: %d\n", secondsPassed(t1));

    printf("\nFor t2:\n");
    printMonth(t2);
    printf("Total days in the year: %d\n", totalDaysInYear(t2));
    printf("Total seconds passed since January 1, 1970: %d\n", secondsPassed(t2));

    return 0;
}