#include "ioheader.h"

int main(int argc, char* argv[])
{

  FILE *filepointer;
  filepointer = fopen("testtest.txt", "a");

  fprintf(filepointer, "TEST");



}




void readfile(struct account accarray[], int* numcust, char filename[])
{




}





void writefile(struct account accarray[], int numcust, char filename[])
{
    FILE *filepointer;
    filepointer = fopen(filename, "a");

    fprintf(filepointer,"%s,%d,%f\n", accarray.name, accarray.accountno, accarray.balance);

}
