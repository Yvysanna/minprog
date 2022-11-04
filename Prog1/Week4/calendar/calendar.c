// !! Check for year month order
// Beter functies met year &  month arg of global var & void?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global variables
#define START_1800 3
#define START_YEAR 1800
#define YEAR_LENGTH 365
#define FEB 2

int YEAR, MONTH;
char* MONTHS[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Dec"};
int DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Displays calendar to screen
int validate_arguments(int argc, char* argv[]);
void display_calendar(int year, int month);
char* get_month(int month); // Optional function
void display_header(int year, int month); // displays month and year, then horizontal line
void display_grid(int year, int month); // Displays month calendar, calculates calendar algorithm
int number_of_days_from_1800(int month, int year); // Count_number_of_days_from_1800
int get_number_of_days_in_month(int year, int month);
int get_first_of_the_month(int year, int month);
int number_days_1800_til_year(int year);
int number_of_days_from_jan_til_month(int year, int month);
int check_leap_year(int year);


int main(int argc, char* argv[]){

    if (validate_arguments(argc, argv) != 0){
      return 1;
    }

    int year = YEAR;
    int month = MONTH;

    display_calendar(year, month);
}

// Checks for correct usage and input types to work with
int validate_arguments(int argc, char* argv[]){

    // Valid lenght: [./calendar, year, month]
    if (argc != 3){
        printf("Usage: ./calendar year month");
        return 1;
    }

    // Convert into numbers and write into variables
    YEAR = atoi(argv[1]), MONTH = atoi(argv[2])-1;

    // Check for validity of args
    if (YEAR < 1|| (MONTH > 12 || MONTH < 0)){
      return 1;
    }

    // Everything correct for further execution for program
    return 0;
}

void display_calendar(year, month){
    display_header(year, month);
    display_grid(year, month);
}

// Get string from month number
char* get_month(month){
    return MONTHS[month];
}


// Leap year is num divisible by 4 and divisible by 400 too
int check_leap_year(year){
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
      return 1;
  }
  return 0;
}


// Displays headline such as month year and weekdays
void display_header(year, month){
    char* month_name = get_month(month);

    // Padding voor de header
    printf("%9c%s %d\n", ' ', month_name, year);
    printf("---------------------------\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
}

int get_number_of_days_in_month(year, month){
    if (strcmp(MONTHS[month], "Feb") == 0){
      //printf("DAYS IN FUNC: LY%d\n", (DAYS[month] + check_leap_year(year)));
      return DAYS[month] + check_leap_year(year);
    }
    //printf("DAYS IN FUNC: %d\n", (DAYS[month] + check_leap_year(year)));
    return DAYS[month];
}

int number_of_days_1800_til_year(year){
    int days = 0;
    for (int i = START_YEAR; i < year; i++){
        days += (YEAR_LENGTH + check_leap_year(i));
        // printf("NuMBER OF DAYS 1800 TIL YEAR%d\n", days);
    }
    return days;
}

int number_of_days_from_jan_til_month(year, month){
    int days = 0;

    // Start loop at 1 because month calculated from 1 - 12
    for (int i = 0; i < month; i++){
        days += get_number_of_days_in_month(year, i);
        // printf("DAYS: %d\n", days);
    }
    return days;
}

// For calculation of weekday
int number_of_days_from_1800(year, month){
    int numdays = 0;

    // Add all years until actual year
    numdays += number_of_days_1800_til_year(year);
    // printf("YEAR: %d\n", numdays);
    numdays += number_of_days_from_jan_til_month(year, month);
    // printf("MONTH: %d\n", numdays);
    return numdays;
}

// Count_number_of_days_from_1800
int get_first_of_the_month(year, month){
    return ((number_of_days_from_1800(year, month) + START_1800) % 7);
}

void display_grid(year, month){
    int day = get_number_of_days_in_month(year, month);
    int weekday = get_first_of_the_month(year, month);

    // TODO: Avoid magic number
    // Add padding for first weekday
    if (weekday != 0){
      printf("%*c", 4 * weekday, ' ');
    }

    for (int i = 0; i < day; i++){

      // Check if end of week and if so, print new line
      if (weekday > 6){
          printf("\n");
          weekday = 0;
      }

      // Check if date below 10 to print more spaces accordingly
      if (i < 9) {
        printf("%2c%d", ' ', i + 1);
        printf("%c", ' ');
      }
      else {
        printf("%c%d", ' ', i + 1);
        printf("%c", ' ');
      }
      weekday++;
    }
    printf("\n");
}
