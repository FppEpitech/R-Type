
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test1, test1, .timeout = 5)
{
    cr_assert_eq("1", "1");
}
