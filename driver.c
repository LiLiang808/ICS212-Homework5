#include <stdio.h>

int main(int argc, char* argv[])
{

    FILE *filepointer;

    filepointer=fopen("testtest.txt","a");

    fprintf(filepointer,"This is a test");


}
