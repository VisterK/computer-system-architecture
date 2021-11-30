echo "Test #1";
time ./task -f ./tests/input1.txt ./tests/output1_1.txt ./tests/output1_2.txt;

echo "Test #2";
time ./task -f ./tests/input2.txt ./tests/output2_1.txt ./tests/output2_2.txt;

echo "Test #3";
time ./task -f ./tests/input3.txt ./tests/output3_1.txt ./tests/output3_2.txt;

echo "Test #4";
time ./task -f ./tests/input4.txt ./tests/output4_1.txt ./tests/output4_2.txt;

echo "Test #5";
time ./task -f ./tests/input5.txt ./tests/output5_1.txt ./tests/output5_2.txt;


echo "Random test #1";
time ./task -n 100 ./tests/output_random2_1.txt ./tests/output_random2_2.txt;

echo "Random Test #2";
time ./task -n 10000 ./tests/output_random2_1.txt ./tests/output_random2_2.txt;
