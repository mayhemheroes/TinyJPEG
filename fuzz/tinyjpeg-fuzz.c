#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TJE_IMPLEMENTATION
#include "../tiny_jpeg.h"

void write_func(void* context, void* data, int size) {

}

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    if (Size > 4) {
        uint8_t* img_data = (uint8_t*) malloc(Size - 4);
        memcpy(img_data, Data+4, Size-4);
        tje_encode_with_func(write_func, NULL, Data[0], Data[1], Data[2], Data[3], img_data);
    }
    
    return 0;
}