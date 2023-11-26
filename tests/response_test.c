#include <criterion/criterion.h>
#include "../src/response.h"

Test(ResponseTest, TestNewInstance) {
    response__t* instance = newInstance();
    cr_assert(instance != NULL, "Instance must not be NULL");
}

Test(ResponseTest, TestResponseStatusWithNull) {
    response__t *res = newInstance();
    setResponseStatus(res,SUCCESS);
    setResponseText(res,RESPONSE_STATUS_SUCCESS);
    cr_assert(isResponseSuccess(res) == true);
}