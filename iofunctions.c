#include "ioheader.h"
#include <stdio.h>

void readfile(struct account accarray[], int* numcust, char filename[])
{




}





void writefile(struct account accarray[], int numcust, char filename[])
{

    FILE *filepointer;
    filepointer = fopen(filename, "a");

    fprintf(filepointer,"%s,%d,%f,\n", accarray->name, accarray->accountno, accarray->balance);



}
