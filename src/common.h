#ifndef _RESEARCH_COMMON_H_
#define _RESEARCH_COMMON_H_ 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

#define DEFAULT_MESSAGE_LENGTH 256
typedef struct Response response__t;
enum ResponseStatus {
    SUCCESS,
    ERROR
};

response__t* newInstance(void);

#endif