echo "\nTest #1";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/code/cmake-build-debug/hw2 -f /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/input1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/out1-1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/out1-2.txt;

echo "\nTest #2";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/code/cmake-build-debug/hw2 -f /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/input2.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/out2-1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/out2-2.txt;

echo "\nTest #3";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/code/cmake-build-debug/hw2 -f /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/input3.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/out3-1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/out3-2.txt;

echo "\nTest #4";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/code/cmake-build-debug/hw2 -f /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/input4.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/out4-1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/out4-2.txt;

echo "\nTest #5";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/code/cmake-build-debug/hw2 -f /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/input5.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/out5-1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/out5-2.txt;

echo "\nRandom Test #1";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/code/cmake-build-debug/hw2 -n 100 /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/outrnd1-1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/outrnd1-2.txt;

echo "\nRandom Test #2";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/code/cmake-build-debug/hw2 -n 10000 /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/outrnd2-1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw2/tests/outrnd2-2.txt;