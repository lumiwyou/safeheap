#include "secure.h"

SecureObjectScheme available_schemes[] = {
    {
        TEST,
        CRITICAL,
        {
            // Encryption
            true
        },
        {
            // Fragmentation
            true
        },
        {
            // Noising
            true
        }
    },
};

SecureObjectScheme * get_scheme_by_identifier(SchemeIdentifier id) {
    for(int s = 0; s < (sizeof(available_schemes) / sizeof(SecureObjectScheme)); s++) {
        if(id == available_schemes[s].id) {
            return &available_schemes[s];
        }
    }
}

SecureObjectScheme * get_scheme_by_grade(Sensitivity grade) {
    for(int s = 0; s < (sizeof(available_schemes) / sizeof(SecureObjectScheme)); s++) {
        if(grade == available_schemes[s].sensitivity) {
            return &available_schemes[s];
        }
    }
}