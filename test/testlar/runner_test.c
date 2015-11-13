#include <stdio.h>

#include "testlar/testing.h"
#include "t.h"

void test_sample(testing_t *t) { printf("run test_sample\n"); }

int main(int argc, const char *argv[]) {
  test_t tests[] = {
      {"test_sample", test_sample},
  };

  return t_run(tests);
}
