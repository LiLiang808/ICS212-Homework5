#include "ioheader.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    struct account bankone[5];
    int numcustomers = 1;

    strcat(bankone[0].name, "Name");
    bankone[0].accountno = 1;
    bankone[0].balance = 10.11;

    writefile(bankone, 1, "test.txt");

    readfile(bankone, &numcustomers, "test.txt");


}
