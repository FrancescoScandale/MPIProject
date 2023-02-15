#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//if wanted, we can represent the date as a struct instead of having all the fields
/*typedef struct {
    char *dateRep;
    int day;
    int month;
    int year;
} dateStruct;*/

typedef struct {
    char *dateRep;
    int day;
    int month;
    int year;
    int cases;
    int deaths;
    char *countriesAndTerritories;
    char geoId[8];
    char countryTerritoryCode[7];
    int popData2019;
    char *continentExp;
    int cumulativeCases; //cumulative cases of last 14 days per 100000 people
} data;

int main(){
    FILE *inputFile;
    char *firstString;

    inputFile = fopen("data.csv", "r");
    firstString = malloc(sizeof(char)*200);

    fgets(firstString,200,inputFile);
    printf("\n%s\n",firstString);

    //split function in C
    char *token = strtok(firstString, ",");
    
    while (token != NULL) // Keep printing tokens while one of the delimiters present in firstString.
    {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    free(firstString);
    fclose(inputFile);
 
    return 0;
}