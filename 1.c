#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day {
char *dayName; int date; char *activity; 
};
struct Day initializeDay(char *name, int date, char *activity) {
struct Day day;
day.dayName = strdup(name); 
day.date = date;
day.activity = strdup(activity); 
return day;
}
void displayDay(struct Day *day) {
printf("%s - %d: %s\n", day->dayName, day->date, day->activity);
}
int main() {
int numDays = 7;
struct Day *calendar = (struct Day *)malloc(numDays * sizeof(struct Day));
calendar[0] = initializeDay("Sunday", 1, "Relaxing");
calendar[1] = initializeDay("Monday", 2, "Work");
calendar[2] = initializeDay("Tuesday", 3, "Meeting");
calendar[3] = initializeDay("Wednesday", 4, "Exercise");
calendar[4] = initializeDay("Thursday", 5, "Study");
calendar[5] = initializeDay("Friday", 6, "Socializing");
calendar[6] = initializeDay("Saturday", 7, "Family Time");
printf("Calendar:\n");
for (int i = 0; i < numDays; i++) {
displayDay(&calendar[i]);
}
for (int i = 0; i < numDays; i++) {
free(calendar[i].dayName);
free(calendar[i].activity);
}
free(calendar);
return 0;
}
