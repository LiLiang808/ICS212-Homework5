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
// FILE: driver.c
//
// DESCRIPTION: This file contains the driver function for hw5
//
//****************************************************************/

#include "ioheader.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    struct account bankone[5];
    int numcustomers;
    int customer = 0;
    int accnoTestCount = 1;
    float balanceTestCount = 1.00;
    int errorcheck = 13;

    printf("\n***Tests of writefile***\n");
    printf("\nTest when filename is missing.");
    printf(" Should return -1 which means error.\n");

    for (customer = 0; customer < 5; customer++)
    {
        strcpy(bankone[customer].name, "Name");
        bankone[customer].accountno = accnoTestCount;
        bankone[customer].balance = balanceTestCount;
        balanceTestCount++;
        accnoTestCount++;
    }
    accnoTestCount = 1;
    balanceTestCount = 1.00;

    numcustomers = 5;
    errorcheck = writefile(bankone, numcustomers, "");

    if (errorcheck == -1)
    {
        printf("Error, %d returned\n", errorcheck);
        errorcheck = 5;
    }
    else
    {
        printf("Returned %d", errorcheck);
        errorcheck = 5;
    }

    printf("\nTest when file is not a .txt file");
    printf(" Should return -1 which means error.\n");

    for (customer = 0; customer < 5; customer++)
    {
        strcpy(bankone[customer].name, "Name");
        bankone[customer].accountno = accnoTestCount;
        bankone[customer].balance = balanceTestCount;
        balanceTestCount++;
        accnoTestCount++;
    }
    accnoTestCount = 1;
    balanceTestCount = 1.00;

    numcustomers = 5;
    errorcheck = writefile(bankone, numcustomers, "badfile.t");

    if (errorcheck == -1)
    {
        printf("Error, %d returned\n", errorcheck);
        errorcheck = 5;
    }
    else
    {
        printf("Returned %d", errorcheck);
        errorcheck = 5;
    }

    printf("\nTest of writing an invalid number of records.");
    printf(" Should return -1 which means error.\n");

    numcustomers = 0;
    errorcheck = writefile(bankone, 0, "InvalidTest.txt");

    if (errorcheck == -1)
    {
        printf("Error, %d returned\n", errorcheck);
        errorcheck = 5;
    }
    else
    {
        printf("Returned %d", errorcheck);
        errorcheck = 5;
    }

    printf("\nTest of adding a single record,");
    printf(" the output file is called test1rec.txt\n");

    for (customer = 0; customer < 5; customer++)
    {
        strcpy(bankone[customer].name, "Name");
        bankone[customer].accountno = accnoTestCount;
        bankone[customer].balance = balanceTestCount;
        balanceTestCount++;
        accnoTestCount++;
    }
    accnoTestCount = 1;
    balanceTestCount = 1.00;

    numcustomers = 1;
    errorcheck = writefile(bankone, numcustomers, "test1rec.txt");

    if (errorcheck == -1)
    {
        printf("Error, %d returned\n", errorcheck);
        errorcheck = 5;
    }




    printf("\nTest of adding 5 records to an empty file,");
    printf(" the output file is called test5rec.txt\n");

    for (customer = 0; customer < 5; customer++)
    {
        strcpy(bankone[customer].name, "Name");
        bankone[customer].accountno = accnoTestCount;
        bankone[customer].balance = balanceTestCount;
        balanceTestCount++;
        accnoTestCount++;
    }
    accnoTestCount = 1;
    balanceTestCount = 1.00;

    numcustomers = 5;
    errorcheck = writefile(bankone, numcustomers, "test5rec.txt");

    if (errorcheck == -1)
    {
        printf("\nError, %d returned\n", errorcheck);
        errorcheck = 5;
    }



    printf("\n***Test of readfile***");
    printf("\nFrom here, if any output says 'Readfile didn't work', then");
    printf(" the function isn't working.\n");
    printf("\nTest when filename is invalid. Should print an error.\n");

    errorcheck = readfile(bankone, &numcustomers, "NonExistantFile.txt");

    if (errorcheck == -1)
    {
        printf("Error, %d returned\n", errorcheck);
        errorcheck = 5;
    }
    else
    {
        printf("Returned %d", errorcheck);
        errorcheck = 5;
    }

    printf("\nTest when filen is not a .txt file");
    printf(" Should return -1 which means error.\n");

    for (customer = 0; customer < 5; customer++)
    {
        strcpy(bankone[customer].name, "Name");
        bankone[customer].accountno = accnoTestCount;
        bankone[customer].balance = balanceTestCount;
        balanceTestCount++;
        accnoTestCount++;
    }
    accnoTestCount = 1;
    balanceTestCount = 1.00;

    numcustomers = 5;
    errorcheck = readfile(bankone, &numcustomers, "badfile.t");

    if (errorcheck == -1)
    {
        printf("Error, %d returned\n", errorcheck);
        errorcheck = 5;
    }
    else
    {
        printf("Returned %d", errorcheck);
        errorcheck = 5;
    }

    printf("\nTest of reading a single record,");
    printf(" 1 record will be read and printed from test1rec.txt\n");

    for (customer = 0; customer < 5; customer++)
    {
        strcpy(bankone[customer].name, "Readfile didn't work.");
        bankone[customer].accountno = 999;
        bankone[customer].balance = 999.999;
    }

    readfile(bankone, &numcustomers, "test1rec.txt");

    for (customer = 0; customer < numcustomers; customer++)
    {

        printf("%s\n%d\n%f\n\n", bankone[customer].name,
        bankone[customer].accountno,
        bankone[customer].balance);
    }

    printf("\nTest of reading 5 records from a file that contains 5 records.");
    printf(" 5 records will be read from test5rec.txt\n");
    for (customer = 0; customer < 5; customer++)
    {
        strcpy(bankone[customer].name, "Readfile didn't work.");
        bankone[customer].accountno = 999;
        bankone[customer].balance = 999.999;
    }

    readfile(bankone, &numcustomers, "test5rec.txt");

    for (customer = 0; customer < numcustomers; customer++)
    {
        printf("%s\n%d\n%f\n\n", bankone[customer].name,
        bankone[customer].accountno,
        bankone[customer].balance);
    }

return 0;
}
