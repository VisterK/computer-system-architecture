echo "\nTest #1";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/code/cmake-build-debug/hw1 -f /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/input1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output1_1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output1_2.txt;

echo "\nTest #2";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/code/cmake-build-debug/hw1 -f /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/input2.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output2_1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output2_2.txt;

echo "\nTest #3";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/code/cmake-build-debug/hw1 -f /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/input3.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output3_1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output3_2.txt;

echo "\nTest #4";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/code/cmake-build-debug/hw1 -f /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/input4.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output4_1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output4_2.txt;

echo "\nTest #5";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/code/cmake-build-debug/hw1 -f /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/input5.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output5_1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output5_2.txt;


echo "\nRandom test #1";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/code/cmake-build-debug/hw1 -n 100 /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output_random2_1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output_random2_2.txt;

echo "\nRandom Test #2";
time /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/code/cmake-build-debug/hw1 -n 10000 /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output_random2_1.txt /Users/mac/Documents/University/computer-system-architecture-hw1/homework/hw1/tests/output_random2_2.txt;
