#include "../Include/QueueTests.h"
#include "../../Src/DataStructures/Include/QueueADT.h"
#include "../../Lib/UnityTest/unity.h"
#include "../../Lib/Utils/Utils.h"
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