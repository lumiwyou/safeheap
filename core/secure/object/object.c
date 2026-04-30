#include "object.h"

SecureObjectContext ** secured_objects_table;
secured_objects_count = 0;

SecureObjectContext * get_context_by_handle(SecureHandle secure_handle) {
    for(int a = 0; a < secured_objects_count; a++) {
        if(secured_objects_table[a]->secure_handle == secure_handle) {
            return secured_objects_table[a];
        }
    }
}

SecureHandle add_secure_object(Sensitivity grade, size_t size) {
    SecureObjectContext ** available_spot;
    SecureObjectContext ** buffer;
    SecureObjectContext * new_context = malloc(sizeof(SecureObjectContext));
    new_context->data_total_size = size;
    new_context->secure_handle = malloc(new_context->data_total_size);
    new_context->scheme_id = get_scheme_by_grade(grade, size);

    // If there is a NULLED entry (from previous removal) then use that instead of creating a new one in table
    if((available_spot = find_empty_context()) != NULL) {
        available_spot = new_context;
    }else{
        if((buffer = realloc(secured_objects_table, sizeof(SecureObjectContext) * secured_objects_count++)) == NULL) {
            return NULL;
        }
        secured_objects_table = buffer;
        secured_objects_table[secured_objects_count] = new_context;
    }
    return new_context->secure_handle;
}

void remove_secure_object(SecureHandle secure_handle) {
    for(int o = 0; o < secured_objects_count; o++) {
        if(secured_objects_table[o]->secure_handle == secure_handle) {
            SecureObjectContext * object = secured_objects_table[o];
            SecureObjectScheme * scheme = get_scheme_by_identifier(object->scheme_id);
            for(int m = 0; m < object->memory_unit_count; m++) {
                // Wipe if enabled
                if(scheme->data_wiping.enabled) {
                    wipe_data(object->memory_units[m]->address);
                }
                free(object->memory_units[m]->address);
            }
            free(object->memory_units);
            free(object);
        }
    }
}

void update_secure_object(SecureHandle secure_handle, Sensitivity grade, size_t size) {
    SecureObjectContext * secure_context = get_context_by_handle(secure_handle);
    
    if(grade != NULL) {
        SecureObjectScheme * new_scheme;
        if((new_scheme = get_scheme_by_grade(grade))->id != secure_context->scheme_id) {
            secure_context->scheme_id = new_scheme->id;
            // TODO: Update entire memory units
            // ! ISSUE: this duty is reserved for interface function, conflicting.
            for(int m = 0; m < secure_context->memory_unit_count; m++) {
                // Re-fragment
                // Re-encrypt
            }
        }
    }
}