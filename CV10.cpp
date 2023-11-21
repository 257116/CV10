// CV10.cpp : Defines the entry point for the application.
//

#include "CV10.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Load searched char
    printf("Hladany char: ");
    char searchChar;
    scanf(" %c", &searchChar);

    // Open input file
    FILE* inputFile = fopen("D:\\vstup.txt", "r");

    // Check
    if (inputFile == NULL) {
        perror("Error pri otvarani fileu");
        return 1;
    }

    // Count num of lett and dig + num of char
    int letterCount = 0;
    int digitCount = 0;
    int charCount = 0;
    int vetCount = 0;
    int slovCount = 0;

    // EOF is end char in file
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (isalpha(ch)) {
            letterCount++;
        }
        if (isdigit(ch)) {
            digitCount++;
        }
        if (ch == searchChar) {
            charCount++;
        }
        if (ch == ' ') {
            slovCount++;
        }
        if (ch == '.' || ch == '!' || ch == '?') {
            vetCount++;
        }
    }

    // Close input file
    if (fclose(inputFile) != 0) {
        perror("Error pri zatvarani fileu");
        return 1;
    }

    // Print results
    printf("Num of letters: %d\n", letterCount);
    printf("Num of digits: %d\n", digitCount);
    printf("Num of slov: %d\n", slovCount);
    printf("Num of viet: %d\n", vetCount);
    printf("char '%c' je %d krat v vstup.txt\n", searchChar, charCount);

    // Open output "D:\\257116\CV10\vysledky.txt"
    FILE* outputFile = fopen("D:\\257116\CV10\vysledky.txt", "w");

    if (outputFile == NULL) {
        perror("Error pri otvarani fileu");
        return 1;
    }

    // Print results to file out
    fprintf(outputFile, "Num of letters: %d\n", letterCount);
    fprintf(outputFile, "Num of digits: %d\n", digitCount);
    fprintf(outputFile, "Num of slov: %d\n", slovCount);
    fprintf(outputFile, "Num of viet: %d\n", vetCount);
    fprintf(outputFile, "Char count: %d\n", charCount);

    // Close the output file
    if (fclose(outputFile) != 0) {
        perror("Error pri zatvarani vysledky fileu");
        return 1;
    }

    return 0;
}