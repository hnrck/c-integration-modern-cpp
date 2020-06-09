#include <stdlib.h>

#include <old_struct.h>

void old_struct_set_x(p_old_struct_t p_old_struct, int x) {
    if (p_old_struct != NULL) {
        p_old_struct->x = x;
    }
}

int old_struct_get_x(p_const_old_struct_t p_old_struct) {
    int x = 0;
    if (p_old_struct != NULL) {
        x = p_old_struct->x;
    }
    return x;
}
