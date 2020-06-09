#ifndef C_INTEGRATION_MODERN_CPP_SMART_POINTERS_INTEGRATION_H
#define C_INTEGRATION_MODERN_CPP_SMART_POINTERS_INTEGRATION_H

extern "C" {
#include <old_pimpl.h>
#include <old_struct.h>
}

using UpOldStruct = std::unique_ptr<old_struct>;

using UpOldPimpl = std::unique_ptr<old_pimpl_t, void (*)(p_old_pimpl_t)>;

#endif // C_INTEGRATION_MODERN_CPP_SMART_POINTERS_INTEGRATION_H
