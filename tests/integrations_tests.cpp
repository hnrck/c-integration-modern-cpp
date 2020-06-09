#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include <random>

#include <integrations.h>

TEST_CASE("Old c smart pointers integration") {

    const auto MAGIC_NUMBER = static_cast<int>(random());

    SECTION("Checking old function integration") {
        const auto X = old_func(MAGIC_NUMBER);
        REQUIRE(X == MAGIC_NUMBER);
    }

    SECTION("Checking old struct integration") {
        auto os = old_struct();
        old_struct_set_x(&os, MAGIC_NUMBER);
        const auto X = old_struct_get_x(&os);
        REQUIRE(X == MAGIC_NUMBER);
    }

    SECTION("Checking old private implementation integration") {
        auto p_op = old_pimpl_new();
        old_pimpl_set_x(p_op, MAGIC_NUMBER);
        const auto X = old_pimpl_get_x(p_op);
        old_pimpl_del(p_op);
        REQUIRE(X == MAGIC_NUMBER);
    }
}
