#include "ioheader.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    struct account bankone[5];
    int numcustomers = 5;
    int customer = 0;
    int accnoTestCount = 1;

    for (customer = 0; customer < numcustomers; customer++)
    {
    strcat(bankone[customer].name, "Name");
    bankone[customer].accountno = accnoTestCount;
    bankone[customer].balance = 10.11;
    accnoTestCount++;
    }

    writefile(bankone, numcustomers, "test.txt");

    for (customer = 0; customer < numcustomers; customer++)
    {
    strcpy(bankone[customer].name, "If this gets printf'd, readfile didn't work.");
    bankone[customer].accountno = 999;
    bankone[customer].balance = 999.999;
    }

    readfile(bankone, &numcustomers, "test.txt");

    for (customer = 0; customer < numcustomers; customer++)
    {
    printf("%s\n%d\n%f\n\n", bankone[customer].name, bankone[customer].accountno,
    bankone[customer].balance);
    }


}
