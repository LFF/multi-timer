/*

Multi Timer 3.0
A Pebble watch app for running multiple simultaneous timers and stopwatches.
http://github.com/smallstoneapps/multi-timer/

----------------------

The MIT License (MIT)

Copyright © 2013 - 2014 Matthew Tole

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

--------------------

tests/timers.c

*/

#include <pebble.h>
#include "unit.h"
#include "groups.h"
#include "../src/timers.h"

void timers_before(void) {
  timers_init();
}

char* count_zero_when_empty(void) {
  mu_assert(0 == timers_count(), "timers_count was not 0 when no timers added");
  return 0;
}

char* count_one_when_added_single_timer(void) {
  Timer* timer = malloc(sizeof(Timer));
  timers_add(timer);
  mu_assert(1 == timers_count(), "timers_count was not 1 when a timer was added");
  return 0;
}

char* count_10_when_added_ten_timers(void) {
  for (uint8_t t = 0; t < 10; t += 1) {
    Timer* timer = malloc(sizeof(Timer));
    timers_add(timer);
  }
  mu_assert(10 == timers_count(), "timers_count was not 10 when ten timers were added");
  return 0;
}

char* get_timer_null_when_empty(void) {
  mu_assert(NULL == timers_get(0), "timers_get was not null when empty at position 0");
  mu_assert(NULL == timers_get(100), "timers_get was not null when empty at position 100");
  return 0;
}

char* get_timer_returns_item(void) {
  Timer* timer = malloc(sizeof(Timer));
  timers_add(timer);
  mu_assert(NULL != timers_get(0), "timers_get was null with one item at position 0");
  mu_assert(NULL == timers_get(1), "timers_get was not null with one item at position 1");
  return 0;
}

char* find_null_when_empty(void) {
  mu_assert(NULL == timers_find(1), "timers_find was not null when empty with id 1");
  mu_assert(NULL == timers_find(8888), "timers_get was not null when empty with id 8888");
  return 0;
}

char* find_timer_when_exists(void) {
  Timer* timer = malloc(sizeof(Timer));
  timer->id = 1;
  timers_add(timer);
  mu_assert(NULL != timers_find(1), "timers_find was null when exists with id 1");
  return 0;
}

char* timer_remove_false_when_empty(void) {
  mu_assert(false == timers_remove(0), "timers_remove failed when empty");
  return 0;
}

char* timer_remove_true_when_single_timer(void) {
  Timer* timer = malloc(sizeof(Timer));
  timers_add(timer);
  mu_assert(true == timers_remove(0), "timers_remvoe succeeds when single timer");
  return 0;
}

char* timer_remove_false_when_not_existant(void) {
  Timer* timer = malloc(sizeof(Timer));
  timers_add(timer);
  mu_assert(false == timers_remove(5), "timers_remvoe fails when invalid position");
  return 0;
}

char* timer_remove_reduces_count(void) {
  timers_add(malloc(sizeof(Timer)));
  timers_add(malloc(sizeof(Timer)));
  timers_remove(0);
  mu_assert(1 == timers_count(), "timers_remove did not reduce timers count");
  return 0;
}

char* timers_tests(void) {
  mu_run_test(count_zero_when_empty);
  mu_run_test(count_one_when_added_single_timer);
  mu_run_test(count_10_when_added_ten_timers);
  mu_run_test(get_timer_null_when_empty);
  mu_run_test(get_timer_returns_item);
  mu_run_test(find_null_when_empty);
  mu_run_test(find_timer_when_exists);
  mu_run_test(timer_remove_false_when_empty);
  mu_run_test(timer_remove_true_when_single_timer);
  mu_run_test(timer_remove_false_when_not_existant);
  mu_run_test(timer_remove_reduces_count);
  return 0;
}