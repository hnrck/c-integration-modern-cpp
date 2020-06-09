#ifndef C_INTEGRATION_MODERN_CPP_WRAPPED_INTEGRATION_H
#define C_INTEGRATION_MODERN_CPP_WRAPPED_INTEGRATION_H

extern "C" {
#include <old_pimpl.h>
#include <old_struct.h>
}

/// Old struct wrapper
class OldStructWrapper final {
private:
    old_struct os; ///< Old struct composition
public:
    /// Old struct constructor
    OldStructWrapper() = default;

    /// Old struct destructor
    ~OldStructWrapper() = default;

    /// Old struct copy constructor
    OldStructWrapper(const OldStructWrapper &) = default;

    /// Old struct copy assignment
    /// \return Copy of other old struct wrapper
    OldStructWrapper &operator=(const OldStructWrapper &) = default;

    /// Old struct move constructor
    OldStructWrapper(OldStructWrapper &&) = default;

    /// Old struct move assignment
    /// \return Old struct wrapper
    OldStructWrapper &operator=(OldStructWrapper &&) = default;

    /// Property x setter
    /// \param x value to set
    void set_x(int x) {
        old_struct_set_x(&os, x);
    }

    /// Property x getter
    /// \return x value
    [[nodiscard]] auto get_x() const -> int {
        return old_struct_get_x(&os);
    }
};

/// Old private implementation wrapper
class OldPimplWrapper final {
private:
    p_old_pimpl_t p_op{nullptr}; ///< Pointer to old private implementation, null by default

public:
    /// Old private implementation constructor
    OldPimplWrapper() : p_op{old_pimpl_new()} {};

    /// Old private implementation destructor
    ~OldPimplWrapper() {
        old_pimpl_del(p_op);
    }

    /// Old private implementation copy constructor
    /// \param other Old private implementation wrapper to copy
    OldPimplWrapper(const OldPimplWrapper &other) : p_op{old_pimpl_new()} {
        set_x(other.get_x());
    }

    /// Old private implementation copy assignment
    /// \param other Old private implementation wrapper to copy
    /// \return Copy of other
    OldPimplWrapper &operator=(const OldPimplWrapper &other) {
        set_x(other.get_x());
        return *this;
    }

    /// Old private implementation move constructor
    /// \param other Old private implementation wrapper to move
    OldPimplWrapper(OldPimplWrapper &&other) noexcept: p_op{nullptr} {
        p_op = other.p_op;
        other.p_op = nullptr;
    }

    /// Old private implementation move assignment
    /// \param other old private implementation wrapper to move
    /// \return Other
    OldPimplWrapper &operator=(OldPimplWrapper &&other) noexcept {
        p_op = other.p_op;
        other.p_op = nullptr;
        return *this;
    }

    /// Property x setter
    /// \param x value to set
    void set_x(int x) {
        old_pimpl_set_x(p_op, x);
    }

    /// Property x getter
    /// \return x value
    [[nodiscard]] auto get_x() const -> int {
        return old_pimpl_get_x(p_op);
    }
};

#endif // C_INTEGRATION_MODERN_CPP_WRAPPED_INTEGRATION_H
