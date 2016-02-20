#include "ioheader.h"
#include <stdio.h>


void readfile(struct account accarray[], int* numcust, char filename[])
{
    char line[80];
    int customer = 0;
    int counter = 0;

    customer = *numcust;


    FILE *filepointer;
    filepointer = fopen(filename, "r");

    if (filepointer != NULL)
    {


        while (feof(filepointer) == 0)
        {
            printf("\nCustomer %d:\n", customer);

            for (counter = 0; counter < 3; counter++)
            {
            fgets(line, 80, filepointer);
            printf("%s",line);
            }
            fgets(line, 80, filepointer);
            customer++;
        }
    }
    else
    {
        printf("\nError opening file");
    }
}

void writefile(struct account accarray[], int numcust, char filename[])
{
    int customer = 0;

    FILE *filepointer;
    filepointer = fopen(filename, "a");

    for (customer = 0; customer < numcust; customer++)
    {
        fprintf(filepointer,"%s\n%d\n%f\n", accarray[customer].name,
        accarray[customer].accountno, accarray[customer].balance);

    }
        fclose(filepointer);

}
