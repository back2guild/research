#include <criterion/criterion.h>
#include "../src/common.h"
#include "../src/response.h"

response__t *res = NULL;

void setup() {
    res = createResponse();
}

void teardown() {
    destroyResponse(res);
}

Test(ResponseTest, TestNewInstance, .init = setup, .fini= teardown) {
    response__t* instance = createResponse();
    cr_assert(instance != NULL, "Instance must not be NULL");
}

Test(ResponseTest, TestResponseStatusSuccess, .init = setup, .fini= teardown) {
    response__t *res = createResponse();
    setResponseStatus(res,SUCCESS);
    setResponseText(res,RESPONSE_STATUS_SUCCESS);
    cr_assert(isResponseSuccess(res) == true);
}

Test(ResponseTest, TestResponseStatusError , .init = setup, .fini= teardown) {
    response__t *res = createResponse();
    setResponseStatus(res,ERROR);
    setResponseText(res,RESPONSE_STATUS_ERROR);
    cr_assert(isResponseSuccess(res) == false);
}