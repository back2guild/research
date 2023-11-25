#include <criterion/criterion.h>
#include "../src/response.h"

Test(ResponseTest, TestNewInstance) {
    response__t* instance = newInstance();
    cr_assert(instance != NULL, "Instance must not be NULL");
}

Test(ResponseTest, TestResponseStatusWithNull) {
    response__t *res = newInstance();
    res->setStatus(res,SUCCESS);
    res->setText(res,RESPONSE_STATUS_SUCCESS);
    assert(isResponseSuccess(res) == true);
}