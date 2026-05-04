#include "secure.h"

// #14 @lumiwyou add a check to ensure not empty on compile
SecureObjectScheme security_schemes[] = {
};

SecureObjectScheme * get_scheme_by_grade(Sensitivity grade) {
    for(int s = 0; s < (sizeof(security_schemes) / sizeof(SecureObjectScheme)); s++) {
        if(grade == security_schemes[s].sensitivity) {
            return &security_schemes[s];
        }
    }
}