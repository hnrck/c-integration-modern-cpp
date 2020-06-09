/**
 * Old private implementation header
 */
#ifndef C_INTEGRATION_OLD_PIMPL_H
#define C_INTEGRATION_OLD_PIMPL_H

/**
 * Structure old private implementation
 */
struct old_pimpl;

typedef struct old_pimpl old_pimpl_t; /**< Private implementation type */
typedef old_pimpl_t *p_old_pimpl_t; /**< Private implementation pointer type */
typedef const old_pimpl_t *p_const_old_pimpl_t; /**< Private implementation pointer to constant type */

/**
 * Private implementation allocation
 * @return A private implementation pointer to allocated private implementation
 */
p_old_pimpl_t old_pimpl_new();

/**
 * Private implementation destructor
 * @param p_old_pimpl A private implementation pointer to structure to deallocate
 */
void old_pimpl_del(p_old_pimpl_t p_old_pimpl);

/**
 * Private implementation x setter
 * @param p_old_pimpl A private implementation pointer
 * @param x value to set
 */
void old_pimpl_set_x(p_old_pimpl_t p_old_pimpl, int x);

/**
 * Private implementation x getter
 * @param p_old_pimpl A private implementation pointer to constant
 * @return x
 */
int old_pimpl_get_x(p_const_old_pimpl_t p_old_pimpl);

#endif //C_INTEGRATION_OLD_PIMPL_H
