#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <float.h>
int getString(char dato[], char msg[], char errorMsg[], int len);
char getUpperChar(char msg[]);
int getInt(char msg[], char errorMsg[], int minRange, int maxRange);
float getFloat(char msg[], char errorMsg[], float minRange, float maxRange);
int getStringFull(char dato[], char msg[], char errorMsg[], int len);
