#include "object.h"

SecureObjectContext ** secured_objects_table;
int secured_objects_count = 0;

SecureObjectContext * get_secure_object(SecureHandle secure_handle) {
    for(int a = 0; a < secured_objects_count; a++) {
        if(secured_objects_table[a]->secure_handle == secure_handle) {
            return secured_objects_table[a];
        }
    }
    return NULL;
}

SecureHandle create_secure_object(Sensitivity grade, size_t size) {
    SecureObjectContext * new_context = malloc(sizeof(SecureObjectContext));
    
    new_context->scheme = get_scheme_by_grade(grade);
    new_context->data_total_size = size;
    new_context->secure_handle = malloc(size);
    
    SecureObjectContext ** available;
    if((available = find_empty_context()) != NULL) {
        *available = new_context;
    }else{
        SecureObjectContext ** buffer;
        if((buffer = realloc(secured_objects_table, sizeof(SecureObjectContext*) * secured_objects_count++)) != NULL) {
            secured_objects_table = buffer;
        }
        secured_objects_table[secured_objects_count] = new_context;
    }
    return new_context->secure_handle;
}

void delete_secure_object(SecureHandle secure_handle) {
    for(int o = 0; o < secured_objects_count; o++) {
        if(secured_objects_table[o]->secure_handle == secure_handle) {
            SecureObjectContext * context = secured_objects_table[o];
            SecureObjectScheme * scheme = context->scheme;
            for(int m = 0; m < context->memory_unit_count; m++) {
                free(context->memory_units[m]->address);
            }
            free(context->memory_units);
            free(context);
        }
    }
}

void update_secure_object(SecureHandle secure_handle, Sensitivity grade, size_t size) {
}

SecureObjectContext ** find_empty_context(void) {
    for(int c = 0; c < secured_objects_count; c++) {
        if(secured_objects_table[c] == NULL) {
            return &secured_objects_table[c];
        }
    }
    return NULL;
}