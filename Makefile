UNITY_DIR=./tests/UnityUnitTests/src/unity.c
ALL_TESTS_DIR=./tests/tests.c
TEST_DIR=./tests/src/
DS_DIR=./DataStructures/src/

test_stack:
		gcc -o test_stack ${UNITY_DIR} ${ALL_TESTS_DIR} ${TEST_DIR}stack_tests.c ${DS_DIR}stack.c
		./test_stack

clean:
		rm test_stack