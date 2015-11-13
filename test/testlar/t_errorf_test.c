#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "testlar/testing.h"
#include "t.h"

int main(int argc, const char *argv[]) {
  testing_t *t = (testing_t *)malloc(sizeof(testing_t));
  t_errorf(t, "expect 1 but got %d", 2);

  if (strcmp(t->output, "expect 1 but got 2") != 0) {
    fprintf(stderr, "t_errorf: Expect `expect 1 but got 2` but got %s\n",
            t->output);
    return TEST_FAIL;
  }

  free(t->output);
  free(t);

  return TEST_PASS;
}
