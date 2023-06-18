#include "../include/QueueTests.h"
#include "../../DataStructures/include/QueueADT.h"
#include "../UnityUnitTests/src/unity.h"
#include "../utils/Utils.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Generate a queue for testing
 */
Queue* generate_queue()
{
    Queue* queue_ptr = queue_init(free);

    return queue_ptr;
}