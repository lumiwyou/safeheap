#include "secure.h"

SecureObjectScheme available_schemes[] = {};

SecureObjectScheme * get_scheme_by_grade(Sensitivity grade) {
    for(int s = 0; s < (sizeof(available_schemes) / sizeof(SecureObjectScheme)); s++) {
        if(grade == available_schemes[s].sensitivity) {
            return &available_schemes[s];
        }
    }
}