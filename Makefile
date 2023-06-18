UNITY_DIR=./tests/UnityUnitTests/src/unity.c
ALL_TESTS_DIR=./tests/Tests.c
TEST_DIR=./tests/src/
DS_DIR=./DataStructures/src/

test_stack:
		gcc -o TestStack ${UNITY_DIR} ${ALL_TESTS_DIR} ${TEST_DIR}StackTests.c ${DS_DIR}Stack.c
		./TestStack

clean:
		rm TestStack