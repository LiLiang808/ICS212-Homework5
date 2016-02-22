#include "ioheader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void readfile(struct account accarray[], int* numcust, char filename[])
{
    char line[80];
    int customer = 0;

    FILE *filepointer;
    filepointer = fopen(filename, "r");

    if (filepointer != NULL)
    {
        for (customer = 0; customer < *numcust; customer++)
        {


            fgets(line, 80, filepointer);

            if (feof(filepointer))
            {
              break;
            }

            if (line[strlen(line) - 1] == '\n')
            {
                line[strlen(line) - 1] = '\0';
            }

            strcpy(accarray[customer].name,line);

            fgets(line, 80, filepointer);

            if (line[strlen(line) - 1] == '\n')
            {
                line[strlen(line) - 1] = '\0';
            }
            accarray[customer].accountno = atoi(line);

            fgets(line, 80, filepointer);

            if (line[strlen(line) - 1] == '\n')
            {
            line[strlen(line) - 1] = '\0';
            }

            accarray[customer].balance = atof(line);

        }
        fclose(filepointer);
    }
    else
    {
        printf("Error opening file. Cannot find file called %s", filename);
    }
}

void writefile(struct account accarray[], int numcust, char filename[])
{
    int customer = 0;

    FILE *filepointer;
    filepointer = fopen(filename, "a");

    if (filepointer != NULL)
    {
        if (numcust > 0)
        {

            for (customer = 0; customer < numcust; customer++)
            {
                fprintf(filepointer,"%s\n%d\n%f\n", accarray[customer].name,
                accarray[customer].accountno, accarray[customer].balance);

            }

            fclose(filepointer);
        }
        else
        {
            printf("Error, cannot add %d customers to file\n", numcust);
            fclose(filepointer);
        }
    }
    else
    {
        printf("Error opening file\n");

    }
}
