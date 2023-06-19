# COMMANDS
ifeq ($(OSTYPE),cygwin)
	CLEANUP=rm -f
	MKDIR=mkdir -p
	TARGET_EXTENSION=out
else ifeq ($(OS),Windows_NT)
	CLEANUP=del /F /Q
	MKDIR=mkdir
	TARGET_EXTENSION=exe
else
	CLEANUP=rm -f
	MKDIR=mkdir -p
	TARGET_EXTENSION=out
endif

# LIB DIRECTORIES
UNITY_DIR=./Lib/UnityTest/unity.c
UTILS_DIR=./Lib/Utils/Utils.c

# TESTS DIRECTORIES
TEST_DIR=./Tests/Src

# DATA STRUCTURES DIRECTORIES
DS_DIR=./Src/DataStructures/Src

# DEFAULT
DEFAULT=${UNITY_DIR} ${UTILS_DIR}

# STACK
test_array_stack:
		gcc -o TestArrayStack.${TARGET_EXTENSION} ${DEFAULT} ${TEST_DIR}/ArrayStackTests.c ${DS_DIR}/ArrayStack.c
		./TestArrayStack.${TARGET_EXTENSION}

# QUEUE
test_array_queue:
		gcc -o TestArrayQueue.${TARGET_EXTENSION} ${DEFAULT} ${TEST_DIR}/ArrayQueueTests.c ${DS_DIR}/ArrayQueue.c
		./TestArrayQueue.${TARGET_EXTENSION}

# LIST
test_array_list:
		gcc -o TestArrayList.${TARGET_EXTENSION} ${DEFAULT} ${TEST_DIR}/ArrayListTests.c ${DS_DIR}/ArrayList.c
		./TestArrayList.${TARGET_EXTENSION}

# ALL
all:	
		make test_array_stack
		make test_array_queue
		make test_array_list

# CLEAN
clean:	
		${CLEANUP} *.${TARGET_EXTENSION}
