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
// FILE: ioheader.h
//
// DESCRIPTION: This file contains the prototype functions for hw5
//
//****************************************************************/
#include "account.h"
int readfile(struct account accarray[], int* numcust, char filename[]);
int writefile(struct account accarray[], int numcust, char filename[]);
