#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "testlar/testing.h"

int _run(test_t *test) {
  testing_t *t = (testing_t *)malloc(sizeof(testing_t));

  test->fn(t);
  if (t->finished && t->failed) {
    return 1;
  }

  free(t);
  return 0;
}

int _t_run(test_t tests[], int len) {
  int i;
  int ret;

  for (i = 0; i < len; i++) {
    if ((ret = _run(&tests[i])) != 0) {
      return ret;
    }
  }

  return 0;
}

int t_run(test_t *tests) {
  return _t_run(tests, sizeof(*tests) / sizeof(test_t));
}

void t_error(testing_t *t, const char *restrict msg) {
  int len = strlen(msg) + 1;

  t->failed = true;
  t->output = (char *)malloc(sizeof(char) * len);
  strncpy(t->output, msg, len);
  t->finished = true;
}

void t_errorf(testing_t *t, const char *restrict format, ...) {
  char *out;
  va_list argp;

  va_start(argp, format);
  vasprintf(&out, format, argp);

  t_error(t, out);

  va_end(argp);
  free(out);
}
