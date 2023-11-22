#include<criterion/criterion.h>
#include "../src/common.h"

Test(CommonTest, TestNewInstance) {
    response__t* instance = newInstance();
    cr_assert(instance != NULL, "Instance must not be NULL");
}