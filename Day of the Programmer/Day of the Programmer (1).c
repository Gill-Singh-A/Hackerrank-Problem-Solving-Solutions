#include <stdio.h>

int main()
{
    int year, days;
    scanf("%d", &year);
    if( year == 1918 )
    {
        days = 26;
    }
    else if( ((year < 1918) && (year % 4 == 0)) || (year%400==0) || (year%4==0 && year % 100 != 0) )
    {
        days = 12;
    }
    else 
    {
        days = 13;
    }
    printf("%02d.09.%d", days, year);
}
