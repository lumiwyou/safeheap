#include "memory.h"

void add_memory_unit(SecureHandle secure_handle, void * address, size_t size) {
    SecureObjectContext * secure_context = get_context_by_handle(secure_handle);
    MemoryUnit * new_unit = malloc(sizeof(MemoryUnit));

    new_unit->address = address;
    new_unit->length = size;
    
    MemoryUnit ** buffer;
    if((buffer = realloc(secure_context->memory_units, sizeof(MemoryUnit*) * secure_context->memory_unit_count++)) == NULL) {
        return NULL;
    }
    secure_context->memory_unit_count = buffer;
    secure_context->memory_units[secure_context->memory_unit_count] = new_unit;
}