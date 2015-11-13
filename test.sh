gcc -iquote./include src/testlar/testing.c test/testlar/t_errorf_test.c -o t_errorf_test && ./t_errorf_test
gcc -iquote./include src/testlar/testing.c test/testlar/t_error_test.c -o t_error_test && ./t_error_test
gcc -iquote./include src/testlar/testing.c test/testlar/runner_test.c -o runner_test && ./runner_test
