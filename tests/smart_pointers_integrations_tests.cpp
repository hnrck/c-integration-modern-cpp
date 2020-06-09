#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <smart_pointers_integrations.h>

TEST_CASE("Old c integration using smart pointers") {

    const auto MAGIC_NUMBER = static_cast<int>(random());

    SECTION("Checking old struct integration with shared pointers") {
        auto sp_os = std::make_shared<old_struct>();
        old_struct_set_x(sp_os.get(), MAGIC_NUMBER);
        const auto X = old_struct_get_x(sp_os.get());
        REQUIRE(X == MAGIC_NUMBER);
    }

    SECTION("Checking old struct integration with unique pointers") {
        auto up_os = std::make_unique<old_struct>();
        old_struct_set_x(up_os.get(), MAGIC_NUMBER);
        const auto X = old_struct_get_x(up_os.get());
        REQUIRE(X == MAGIC_NUMBER);
    }

    SECTION("Checking old private implementation integration with shared pointers") {
        auto sp_op = std::shared_ptr<old_pimpl>(old_pimpl_new(), old_pimpl_del);
        old_pimpl_set_x(sp_op.get(), MAGIC_NUMBER);
        const auto X = old_pimpl_get_x(sp_op.get());
        REQUIRE(X == MAGIC_NUMBER);
    }

    SECTION("Checking old private implementation integration with unique pointers") {
        auto up_op = UpOldPimpl(old_pimpl_new(), old_pimpl_del);
        old_pimpl_set_x(up_op.get(), MAGIC_NUMBER);
        const auto X = old_pimpl_get_x(up_op.get());
        REQUIRE(X == MAGIC_NUMBER);
    }
}
