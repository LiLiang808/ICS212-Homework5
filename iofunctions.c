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
//              the end of the file has been reached. The file must be a .txt
//              file.
//
//
// Parameters:  accarray (account []): array of records to be filled.
//              numcust (int*) : Pointer to number of customers in file.
//              filename (char[]) : Name of file to be read from.
//
// Returns : 0 on successful read.
//          -1 if file not found.
//
//****************************************************************/

int readfile(struct account accarray[], int* numcust, char filename[])
{
    char line[80];
    int customer = 0;
    int returnvalue = 0;
    FILE *filepointer;

    *numcust = 0;



    if (filename[strlen(filename)-4] == '.' &&
        filename[strlen(filename)-3] == 't' &&
        filename[strlen(filename)-2] == 'x' &&
        filename[strlen(filename)-1] == 't')
    {
        filepointer = fopen(filename, "r");
    }
    else
    {
        filepointer = NULL;
    }

    if (filepointer != NULL)
    {
        while (feof(filepointer) == 0)
        {

            fgets(line, 80, filepointer);

            if (feof(filepointer) == 0)
            {
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

                customer++;
                *numcust = *numcust + 1;

            }

        }
        fclose(filepointer);
    }
    else
    {
        returnvalue = -1;
    }
    return returnvalue;
}

/*****************************************************************
//
// Function name: writefile
//
// DESCRIPTION: Writes data from provided records to the specified file.
//              Will create a file if file does not exist.
//              If file aleady exists, it overwrites the file.
//              The file must be a .txt file.
//
// Parameters:  accarray (account[]) : The array of records to be written.
//              numcust(int) : the number of records to be added.
//              filename (char[]) : The name of the file to write to.
//
// Retunrs: 0 : on successful write.
//          -1 : if write is unsuccesful for any reason such as
//               invalid number of customers.
//
//****************************************************************/

int writefile(struct account accarray[], int numcust, char filename[])
{
    int customer = 0;
    int returnvalue = 0;

    FILE *filepointer;

    if (filename[strlen(filename)-4] == '.' &&
        filename[strlen(filename)-3] == 't' &&
        filename[strlen(filename)-2] == 'x' &&
        filename[strlen(filename)-1] == 't')
    {
        filepointer = fopen(filename, "w");
    }
    else
    {
       filepointer = NULL;
    }

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
            returnvalue = -1;
            fclose(filepointer);
        }
    }
    else
    {
        returnvalue = -1;

    }

    return returnvalue;
}
