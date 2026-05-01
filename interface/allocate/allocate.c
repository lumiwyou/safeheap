#include "allocate.h"

SecureHandle sfp_malloc(size_t size, Sensitivity grade) {
    SecureHandle secure_handle = add_secure_object(grade, size);
    SecureObjectContext * secure_context = get_context_by_handle(secure_handle);
    SecureObjectScheme * secure_scheme = get_scheme_by_identifier(secure_context->scheme_id);

    if(secure_scheme->fragmentation.enabled) {
        // Calculate fragment count and sizes and add on remainer
        // Account for certain encryption algorithms which may change output size, usually most dont
        calculate_fragmentation_result result;
        calculate_fragmentation(size, secure_scheme->fragmentation.amount, secure_scheme->encryption.size_incremental_difference, &result);

        // Allocate each fragment and add to memory unit list
        for(int f = 0; f < secure_scheme->fragmentation.amount; f++) {
            unsigned char * unit_address = malloc(result.each_size);
            add_memory_unit(secure_handle, unit_address, result.each_size);
        }

        // Add eventual remainder
        if(result.remainder_size > 0) {
            unsigned char * unit_address = malloc(result.remainder_size);
            add_memory_unit(secure_handle, unit_address, result.remainder_size);
        }   
    }

    return secure_handle;
}

SecureHandle sfp_calloc(int num, size_t size, Sensitivity grade) {
    SecureHandle secure_handle = add_secure_object(grade, num * size);
    SecureObjectContext * secure_context = get_context_by_handle(secure_handle);
    SecureObjectScheme * secure_scheme = get_scheme_by_identifier(secure_context->scheme_id);

    if(secure_scheme->fragmentation.enabled) {
        // Calculate fragment count and sizes and add on remainer
        // Account for certain encryption algorithms which may change output size, usually most dont
        calculate_fragmentation_result result;
        calculate_fragmentation(num * size, secure_scheme->fragmentation.amount, secure_scheme->encryption.size_incremental_difference, &result);

        // Allocate each fragment and add to memory unit list
        for(int f = 0; f < secure_scheme->fragmentation.amount; f++) {
            unsigned char * unit_address = calloc(1, result.each_size);
            add_memory_unit(secure_handle, unit_address, result.each_size);
        }

        // Add eventual remainder
        if(result.remainder_size > 0) {
            unsigned char * unit_address = calloc(1, result.remainder_size);
            add_memory_unit(secure_handle, unit_address, result.remainder_size);
        }   
    }

    return secure_handle;
}

SecureHandle sfp_realloc(SecureHandle secure_handle, size_t size) {
    update_secure_object(secure_handle, _DEFAULT, size);
}

void sfp_free(SecureHandle secure_handle) {
    SecureObjectContext * context = get_context_by_handle(secure_handle);
    SecureObjectScheme * scheme = get_scheme_by_identifier(context->scheme_id);

    if(scheme->data_wiping.enabled) {
        for(int m = 0; m < context->memory_unit_count; m++) {
            MemoryUnit * unit = context->memory_units[m];
            overwrite_data(unit->address, unit->length);
            free(unit->address);
        }
    }

    for(int m = 0; m < context->memory_unit_count; m++) {
        MemoryUnit * unit = context->memory_units[m];
        free(unit);
    }

    remove_secure_object(secure_handle);
}