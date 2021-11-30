//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "input.c"
#include "inrnd.c"
#include "output.c"

extern double ComplexToReal(void *r);
extern double PolarToReal(void *r);
extern double FractionToReal(void *r);
extern double NumberToReal(void *r);
extern double sort(void *r, int len);

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

int main(int argc, char* argv[]) {
    unsigned char cont[10000 * 3 * sizeof(int)];

    int len = 0;


    if(argc != 5) {
        errMessage1();
        return 1;
    }
    if(!strcmp(argv[1], "-f")) {
        FILE* ifst = fopen(argv[2], "r");
        InContainer(cont, &len, ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) { 
            printf("incorrect numer of figures = %d. Set 0 < number <= 10000\n",
                   size);
            return 3;
        }
        srand((unsigned int)(time(0)));
        InRndContainer(cont, &len, size);
    }
    else {
        errMessage2();
        return 2;
    }

    FILE* ofst1 = fopen(argv[3], "w");
    fprintf(ofst1, "Filled container:\n");
    OutContainer(cont, len, ofst1);
    fclose(ofst1);

    FILE* ofst2 = fopen(argv[4], "w");
    sort(cont, len);
    OutContainer(cont, len, ofst2);
    fclose(ofst2);
    return 0;
}
// boom been barabum