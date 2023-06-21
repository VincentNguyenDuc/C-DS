################################## COMMANDS ###################################

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

################################## DIRECTORIES #################################

# LIB DIRECTORIES
UNITY_DIR=./Lib/UnityTest/unity.c
UTILS_DIR=./Lib/Utils/Utils.c

# TESTS DIRECTORY
TEST_DIR=./Tests

# DATA STRUCTURES DIRECTORY
DS_DIR=./Src/DataStructures/Src

# ALGORITHMS DIRECTORY

AL_DIR=./Src/Algorithms/Src

# DEFAULT
TEST_DEFAULT=${UNITY_DIR} ${UTILS_DIR}

#################################### TESTING ####################################

################# DATA STRUCTURES ####################

# STACK
test_array_stack:
		gcc -o TestArrayStack.${TARGET_EXTENSION} ${TEST_DEFAULT} ${TEST_DIR}/ArrayStackTests.c ${DS_DIR}/ArrayStack.c
		./TestArrayStack.${TARGET_EXTENSION}

# QUEUE
test_array_queue:
		gcc -o TestArrayQueue.${TARGET_EXTENSION} ${TEST_DEFAULT} ${TEST_DIR}/ArrayQueueTests.c ${DS_DIR}/ArrayQueue.c
		./TestArrayQueue.${TARGET_EXTENSION}

# LIST
test_array_list:
		gcc -o TestArrayList.${TARGET_EXTENSION} ${TEST_DEFAULT} ${TEST_DIR}/ArrayListTests.c ${DS_DIR}/ArrayList.c
		./TestArrayList.${TARGET_EXTENSION}

# SET
test_array_set:
		gcc -o TestArraySet.${TARGET_EXTENSION} ${TEST_DEFAULT} ${TEST_DIR}/ArraySetTests.c ${DS_DIR}/ArraySet.c
		./TestArraySet.${TARGET_EXTENSION}

# TEST ALL
test_all:	
		make test_array_stack
		make test_array_queue
		make test_array_list
		make test_array_set

################ ALGORITHMS #####################



##################################### CLEAN ############################################
clean:	
		${CLEANUP} *.${TARGET_EXTENSION}
