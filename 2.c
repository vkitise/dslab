#include <stdio.h>
#include <string.h>
int main() {
    char STR[100], PAT[100], REP[100], result[100];
    int i = 0, j = 0, k = 0, match = 0;
    printf("Enter the MAIN string: ");
    scanf(" %[^\n]", STR);
    printf("Enter the PATTERN string: ");
    scanf("%s", PAT);
    printf("Enter the REPLACE string: ");
    scanf("%s", REP);
    while (STR[i] != '\0') {
        match = 1;
        for (k = 0; PAT[k] != '\0'; k++) {
            if (STR[i + k] != PAT[k]) {
                match = 0;
                break;
            }
        }
        if (match) {
            for (k = 0; REP[k] != '\0'; k++) {
                result[j++] = REP[k];
            }
            i += strlen(PAT); 
        } else {
            result[j++] = STR[i++];
        }
    }
    result[j] = '\0'; 
    if (j > 0) {
        printf("\nThe RESULTANT string is: %s\n", result);
    } else {
        printf("Pattern not found!!!\n");
    }
    return 0;
}
