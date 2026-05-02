#include "wiping.h"

void overwrite_data(void * address, size_t length, Sensitivity grade) {
    SecureObjectScheme * scheme = get_scheme_by_grade(grade);
    for(int r = 0; r < scheme->data_wiping.rounds; r++) {
        for(int b = 0; b < length; b++) {
            for(int p = 0; p < scheme->data_wiping.length; p++) {
                memcpy((char*)&address[b], &scheme->data_wiping.pattern[p], 1);
            }
        }
    }
}