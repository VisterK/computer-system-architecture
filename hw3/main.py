import sys
import time
from container import Container


def error_message():
    print("incorrect command line!\n"
          "  Waited:\n"
          "     command: -f infile outfile01 outfile02\n"
          "  Or:\n"
          "     command: -n number outfile01 outfile02\n")


def main(argv):
    if len(argv) != 4:
        error_message()
        return

    cont = None
    if (argv[0] == '-f'):
        cont = Container(filename=argv[1])
    else:
        cont = Container(size=argv[1], type='n')
    start_time = time.time()
    cont.fill()
    cont.print(argv[2])
    sort_time_s = time.time()
    cont.sort()
    sort_time_e = time.time()
    print(f'Sort time - {sort_time_e - sort_time_s:.10f}s')
    cont.print(argv[3])
    end_time = time.time()
    print(f'Total time - {end_time - start_time:.10f}s')


if __name__ == '__main__':
    main(sys.argv[1:])
