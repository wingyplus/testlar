#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "testlar/testing.h"
#include "t.h"

int main(int argc, const char *argv[]) {
  testing_t *t = (testing_t *)malloc(sizeof(testing_t));

  t_error(t, "do test failed");

  if (!t->failed) {
    fprintf(stderr, "it's not failed\n");
    return TEST_FAIL;
  }

  if (!t->finished) {
    fprintf(stderr, "it's not finished\n");
    return TEST_FAIL;
  }

  if (strcmp(t->output, "do test failed") != 0) {
    fprintf(stderr, "message isn't `do test failed` but got `%s`\n", t->output);
    return TEST_FAIL;
  }

  free(t->output);
  free(t);
  return TEST_PASS;
}
