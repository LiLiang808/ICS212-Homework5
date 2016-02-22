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

    printf("\n***Tests of writefile***\n");
    printf("\nTest when filename is invalid. Should print an error.\n: ");

    for (customer = 0; customer < numcustomers; customer++)
    {
    strcpy(bankone[customer].name, "Name");
    bankone[customer].accountno = accnoTestCount;
    bankone[customer].balance = balanceTestCount;
    balanceTestCount++;
    accnoTestCount++;
    }
    balanceTestCount = 0;
    accnoTestCount = 1.00;

    numcustomers = 5;
    writefile(bankone, numcustomers, "");

    printf("\nTest of writing an invalid number of records.");
    printf("Should print an error.\n: ");

    numcustomers = 0;
    writefile(bankone, 0, "InvalidTest.txt");

    printf("\nTest of adding a single record,");
    printf(" the output file is called test1rec.txt\n");

    for (customer = 0; customer < numcustomers; customer++)
    {
    strcpy(bankone[customer].name, "Name");
    bankone[customer].accountno = accnoTestCount;
    bankone[customer].balance = balanceTestCount;
    balanceTestCount++;
    accnoTestCount++;
    }
    balanceTestCount = 0;
    accnoTestCount = 1.00;

    numcustomers = 1;
    writefile(bankone, numcustomers, "test1rec.txt");

    printf("\nTest of adding 5 records to an empty file,");
    printf(" the output file is called test5rec.txt\n");

    for (customer = 0; customer < numcustomers; customer++)
    {
    strcpy(bankone[customer].name, "Name");
    bankone[customer].accountno = accnoTestCount;
    bankone[customer].balance = balanceTestCount;
    balanceTestCount++;
    accnoTestCount++;
    }
    balanceTestCount = 0;
    accnoTestCount = 1.00;

    numcustomers = 5;
    writefile(bankone, numcustomers, "test5rec.txt");

    printf("\n***Test of readfile***");
    printf("\nFrom here, if any output says 'Readfile didn't work', then");
    printf("the function isn't working.");
    printf("\nTest when filename is invalid. Should print an error.\n: ");

    readfile(bankone, &numcustomers, "NonExistantFile.txt");

    printf("\nTest of reading a single record,");
    printf(" 1 record will be read and printed from test1rec.txt\n");

    for (customer = 0; customer < numcustomers; customer++)
    {
    strcpy(bankone[customer].name, "Readfile didn't work.");
    bankone[customer].accountno = 999;
    bankone[customer].balance = 999.999;
    }

    numcustomers = 1;
    readfile(bankone, &numcustomers, "test1rec.txt");

    for (customer = 0; customer < numcustomers; customer++)
    {

      printf("%s\n%d\n%f\n\n", bankone[customer].name, bankone[customer].accountno,
      bankone[customer].balance);
    }

    printf("\nTest of reading 3 records from a file that contains only 1 record.");
    printf(" Only 1 record will be read from test1rec.txt\n");
    printf("\nPrinted output should include 1 record from test1rec and 2 Blank records.");
    for (customer = 0; customer < numcustomers; customer++)
    {
    strcpy(bankone[customer].name, "Blank");
    bankone[customer].accountno = 999;
    bankone[customer].balance = 999.999;
    }
    numcustomers = 3;
    readfile(bankone, &numcustomers, "test1rec.txt");

    for (customer = 0; customer < numcustomers; customer++)
    {

      printf("%s\n%d\n%f\n\n", bankone[customer].name, bankone[customer].accountno,
      bankone[customer].balance);
    }


    printf("\nTest of reading 3 records from a file that contains 5 records.");
    printf(" 3 records will be read from test5rec.txt\n");
    for (customer = 0; customer < numcustomers; customer++)
    {
    strcpy(bankone[customer].name, "Readfile didn't work.");
    bankone[customer].accountno = 999;
    bankone[customer].balance = 999.999;
    }
    numcustomers = 3;
    readfile(bankone, &numcustomers, "test5rec.txt");

    for (customer = 0; customer < numcustomers; customer++)
    {

      printf("%s\n%d\n%f\n\n", bankone[customer].name, bankone[customer].accountno,
      bankone[customer].balance);
    }


    printf("\nTest of reading 5 records from a file that contains 5 records.");
    printf(" 5 records will be read from test5rec.txt\n");
    for (customer = 0; customer < numcustomers; customer++)
    {
    strcpy(bankone[customer].name, "Readfile didn't work.");
    bankone[customer].accountno = 999;
    bankone[customer].balance = 999.999;
    }
    numcustomers = 5;
    readfile(bankone, &numcustomers, "test5rec.txt");

    for (customer = 0; customer < numcustomers; customer++)
    {

      printf("%s\n%d\n%f\n\n", bankone[customer].name, bankone[customer].accountno,
      bankone[customer].balance);
    }

return 0;
}
