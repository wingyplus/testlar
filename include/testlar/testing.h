#ifndef TESTING_H_
#define TESTING_H_

#include <stdbool.h>

typedef struct {
  char *output;

  bool failed;
  bool finished;
} testing_t;

typedef void (*testfn_t)(testing_t *t);

typedef struct {
  char *name;
  testfn_t fn;
} test_t;

int t_run(test_t tests[]);

void t_error(testing_t *t, const char *restrict msg);
void t_errorf(testing_t *t, const char *restrict format, ...);

#endif  // TESTING_H_
