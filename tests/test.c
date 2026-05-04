/**
 * @file test.c
 * @brief Unit Testing used by Github Actions
 *
 * Performs test scenarios on various functions of the library.
 *
 * @author
 * Lumi Hyväri <lumi.hyvari@gmail.com>
 *
 * @copyright
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <safeheap.h>

void log_message(const char* text) {
    if (!text) {
        fprintf(stderr, "Invalid log message\n");
        return;
    }
    time_t now = time(NULL);
    char * output = ctime(&now);
    for(int c = 0; c < strlen(output); c++) {
        if(output[c] == '\n') {
            output[c] = ' ';
        }
    }
    printf("%s| %s\n", output, text);
}

void TEST_PUBLIC_SFP_MALLOC(Sensitivity grade) {
    log_message("TEST GRADE %d PUBLIC SFP_MALLOC");

    const char * test_string = "This is a string";
    SecureHandle my_string = sfp_malloc(sizeof(test_string), grade);
    sfp_free(my_string);
}

void TEST_PUBLIC_INTERFACES(Sensitivity grade) {
    //TEST_PUBLIC_SFP_MALLOC(grade);
    ///TEST_PUBLIC_SFP_CALLOC(grade);
    ///TEST_PUBLIC_SFP_REALLOC(grade);
    ///TEST_PUBLIC_SFP_FREE(grade);
    //TEST_PUBLIC_SFP_WRITE(grade);
    //TEST_PUBLIC_SFP_READ(grade);
}

void TEST_GRADE(Sensitivity grade) {
    TEST_PUBLIC_INTERFACES(grade);
    //TEST_INTERNALS(grade);
}

Sensitivity GRADES_TO_TEST[] = {
    CRITICAL,
    INTERNAL,
    PUBLIC
};

int main(void) {
    log_message("TESTSTART");
    for(int g = 0; g < sizeof(GRADES_TO_TEST) / sizeof(Sensitivity); g++) {
        TEST_GRADE(GRADES_TO_TEST[g]);
    }
}