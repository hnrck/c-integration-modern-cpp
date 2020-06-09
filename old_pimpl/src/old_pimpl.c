#import <stdlib.h>

#import <old_pimpl.h>

/** Old private implementation setter type */
typedef void (*p_f_old_pimpl_setter_t)(p_old_pimpl_t, int);

/** Old private implementation getter type */
typedef int (*p_f_old_pimpl_getter_t)(p_const_old_pimpl_t);

/**
 * Concrete old private implementation
 */
struct old_pimpl {
    int x; /**< x */

    p_f_old_pimpl_getter_t get_x; /**< Old private implementation x setter pointer */
    p_f_old_pimpl_setter_t set_x; /**< Old private implementation x getter pointer */
};

/**
 * Concrete private implementation setter
 * @param p_old_pimpl Concrete private implementation pointer
 * @param x value to set
 */
static void set_x(p_old_pimpl_t p_old_pimpl, int x) {
    if (p_old_pimpl != NULL) {
        p_old_pimpl->x = x;
    }
}

/**
 * Concrete private implementation getter
 * @param p_old_pimpl Concrete private implementation pointer to constant
 * @return x
 */
static int get_x(p_const_old_pimpl_t p_old_pimpl) {
    int x = 0;
    if (p_old_pimpl != NULL) {
        x = p_old_pimpl->x;
    }
    return x;
}

p_old_pimpl_t old_pimpl_new() {
    p_old_pimpl_t p_old_pimpl = NULL;

    /* Allocation of old pimpl */
    p_old_pimpl = (p_old_pimpl_t) malloc(sizeof(old_pimpl_t));

    if (p_old_pimpl != NULL) {
        /* Initialization of old pimpl values */
        p_old_pimpl->x = 0;

        /* Initialization of old pimpl methods */
        p_old_pimpl->set_x = set_x;
        p_old_pimpl->get_x = get_x;
    }

    return p_old_pimpl;
}

void old_pimpl_del(p_old_pimpl_t p_old_pimpl) {
    if (p_old_pimpl != NULL) {
        /* Deallocation of old pimpl */
        free(p_old_pimpl);
    }
}

void old_pimpl_set_x(p_old_pimpl_t p_old_pimpl, int x) {
    if (p_old_pimpl != NULL) {
        /* Concrete old pimpl setter method call */
        p_old_pimpl->set_x(p_old_pimpl, x);
    }
}

int old_pimpl_get_x(p_const_old_pimpl_t p_old_pimpl) {
    int x = 0;
    if (p_old_pimpl != NULL) {
        /* Concrete old pimpl getter method call */
        x = p_old_pimpl->get_x((p_old_pimpl_t) p_old_pimpl);
    }
    return x;
}
