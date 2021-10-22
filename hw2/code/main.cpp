#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "container.h"

void errMessage1() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}


int main(int argc, char* argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");

    Container *cont;
    int size;

    if (!strcmp(argv[1], "-f")) {
        FILE *in = fopen(argv[2], "r");
        fscanf(in, "%d\n", &size);
        cont = new Container(size);
        cont->In(in);
        fclose(in);
    }
    else if (!strcmp(argv[1], "-n")) {
        size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            std::cout << "incorrect numer of movies = "
                      << size
                      << ". Set 0 < number <= 10000\n";
            return 3;
        }
        srand(static_cast<unsigned int>(time(0)));
        cont = new Container(size);
        cont->InRnd();
    }
    else {
        errMessage2();
        return 2;
    }
    FILE *out1 = fopen(argv[3], "w");
    FILE *out2 = fopen(argv[4], "w");

    fprintf(out1, "Filled container:\n");
    cont->Out(out1);

    sort(*cont);

    fprintf(out2, "Sorted container complete:\n");
    cont->Out(out2);

    delete cont;
    printf("Stop\n");

    fclose(out1);
    fclose(out2);
    return 0;
}