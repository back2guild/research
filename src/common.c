#include "common.h"

struct Response {
    enum ResponseStatus statusCode;
    char *statusText;
    void *data;
};

response__t* newInstance(void) {
    response__t *result = (response__t*) malloc(sizeof(response__t));
    if(!result)
    {
        perror("ERROR: Creating response instance failed\n");
    }
    return result;
}
