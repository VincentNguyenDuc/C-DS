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
test_stack:
		gcc -o TestStack.${TARGET_EXTENSION} ${DEFAULT} ${TEST_DIR}/StackTests.c ${DS_DIR}/Stack.c 
		./TestStack.${TARGET_EXTENSION}

# QUEUE
test_queue:
		gcc -o TestQueue.${TARGET_EXTENSION} ${DEFAULT} ${TEST_DIR}/QueueTests.c ${DS_DIR}/Queue.c
		./TestQueue.${TARGET_EXTENSION}

# ALL
all:	
		make test_stack
		make test_queue

# CLEAN
clean:
		${CLEANUP} *.${TARGET_EXTENSION}
