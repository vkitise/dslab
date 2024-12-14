#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day {
char *dayName;
int date;
char *activity;
};
struct Day initializeDay(char *name, int date, char *activity) {
struct Day day;
day.dayName = strdup(name); 
day.date = date;
day.activity = strdup(activity); 
return day;
}
struct Day *createCalendar(int numDays) {
struct Day *calendar = (struct Day *)malloc(numDays * sizeof(struct Day));
return calendar;
}
void readData(struct Day *calendar, int numDays) {
for (int i = 0; i < numDays; i++) {
printf("Enter details for day %d:\n", i + 1);
char name[50];
char activity[100];
printf("Enter day name: ");
scanf("%s", name);
printf("Enter date: ");
scanf("%d", &calendar[i].date);
printf("Enter activity: ");
scanf("%s", activity);
calendar[i] = initializeDay(name, calendar[i].date, activity);
}
}
void displayCalendar(struct Day *calendar, int numDays) {
printf("\nCalendar:\n");
for (int i = 0; i < numDays; i++) {
printf("%s - %d: %s\n", calendar[i].dayName, calendar[i].date, calendar[i].activity);
}
}
void freeCalendar(struct Day *calendar, int numDays) {
for (int i = 0; i < numDays; i++) {
free(calendar[i].dayName);
free(calendar[i].activity);
}
free(calendar);
}
int main() {
int numDays = 7;
struct Day *calendar = createCalendar(numDays);
readData(calendar, numDays);
displayCalendar(calendar, numDays);
freeCalendar(calendar, numDays);
return 0;
}
