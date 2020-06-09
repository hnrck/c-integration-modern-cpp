#ifndef C_INTEGRATION_OLD_STRUCT_H
#define C_INTEGRATION_OLD_STRUCT_H


/**
 * Old struct
 */
struct old_struct {
    int x; /**< x */
};
typedef struct old_struct old_struct_t; /**< Old struct type */
typedef old_struct_t *p_old_struct_t; /**< Old struct pointer type */
typedef const old_struct_t *p_const_old_struct_t; /**< Old struct pointer to constant type */

/**
 * Old struct x setter
 * @param p_old_struct Old struct pointer to set
 * @param x value to set
 */
void old_struct_set_x(p_old_struct_t p_old_struct, int x);

/**
 * Old struct x getter
 * @param p_old_struct Old struct pointer to constant
 * @return x
 */
int old_struct_get_x(p_const_old_struct_t p_old_struct);

#endif //C_INTEGRATION_OLD_STRUCT_H
