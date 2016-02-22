/*****************************************************************
//
// NAME: Alex Watanabe
//
// HOMEWORK: 5
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: Feb 20 , 2016
//
// FILE: iofunctions.c
//
// DESCRIPTION: This file contains the iofunctions for Homework 5
//
//****************************************************************/

#include "ioheader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************
//
// Function name: readfile
//
// DESCRIPTION: Function that reads records from a file into a provided
//              array of records. The record has parameters name (char[])
//              accountno (int), and balance (float). Will stop when
//              the number of records requrested have been read or
//              the end of file has been reached, whichever is first.
//
// Parameters:  accarray (account []): array of records to be filled.
//              numcust (int*) : Pointer to requested number of customers
//              filename (char[]) : Name of file to be read from.
//
//****************************************************************/

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
        printf("Error opening file. Cannot find file called %s\n", filename);
    }
}

/*****************************************************************
//
// Function name: writefile
//
// DESCRIPTION: Writes data from provided records to the specified file.
//              Will create a file if file does not exist.
//              If file aleady exists, it appends to the file.
//
// Parameters:  accarray (account[]) : The array of records to be written.
//              numcust(int) : the number of records to be added.
//              filename (char[]) : The name of the file to write to.
//
//****************************************************************/

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
