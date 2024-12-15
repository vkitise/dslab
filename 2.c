#include <stdio.h>
int main() {
char STR[100], PAT[100], REP[100], ans[100];
int i, j, c, m, k, flag = 0;
printf("\nEnter the MAIN string: ");
scanf("%99[^\n]", STR); 
printf("Enter a PATTERN string: ");
scanf("%99s", PAT);
printf("Enter a REPLACE string: ");
scanf("%99s", REP);
i = m = c = j = 0;
while (STR[c] != '\0') {
if (STR[c] == PAT[i]) {
i++;
c++;
flag = 1;
if (PAT[i] == '\0') {
for (k = 0; REP[k] != '\0'; k++, j++)
ans[j] = REP[k];
i = 0; 
}
} else { 
ans[j] = STR[c];
j++;
c++;
m = c;
i = 0; 
}
}
if (flag == 0) {
printf("Pattern doesn't found!!!\n");
} else {
ans[j] = '\0';
printf("\nThe RESULTANT string is: %s\n", ans);
}
return 0;
}
