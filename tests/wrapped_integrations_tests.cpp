#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <wrapped_integrations.h>
#include <random>

TEST_CASE("Old c wrapped integration") {

    const auto MAGIC_NUMBER = static_cast<int>(random());

    SECTION("Checking old function integration") {
        auto os = OldStructWrapper();
        os.set_x(MAGIC_NUMBER);
        const auto X = os.get_x();
        REQUIRE(X == MAGIC_NUMBER);
    }

    SECTION("Checking old struct integration") {
        auto os = OldStructWrapper();
        os.set_x(MAGIC_NUMBER);
        const auto X = os.get_x();
        REQUIRE(X == MAGIC_NUMBER);
    }

    SECTION("Checking old struct copy") {
        OldStructWrapper os_cpy_1;
        OldStructWrapper os_cpy_2;

        {
            auto os = OldStructWrapper();
            os.set_x(MAGIC_NUMBER);
            os_cpy_1 = os; // Copy assignment
            os_cpy_2 = OldStructWrapper(os); // Copy constructor and move assignment
        }

        const auto OTHER_MAGIC_NUMBER = static_cast<int>(random());
        os_cpy_2.set_x(OTHER_MAGIC_NUMBER);

        const auto X_1 = os_cpy_1.get_x();
        const auto X_2 = os_cpy_2.get_x();

        REQUIRE(X_1 == MAGIC_NUMBER);
        REQUIRE(X_2 == OTHER_MAGIC_NUMBER);
    }

    SECTION("Checking old private implementation integration") {
        auto op = OldPimplWrapper();
        op.set_x(MAGIC_NUMBER);
        const auto X = op.get_x();
        REQUIRE(X == MAGIC_NUMBER);
    }

    SECTION("Checking old private implementation copy") {
        OldPimplWrapper op_cpy_1;
        OldPimplWrapper op_cpy_2;

        {
            auto op = OldPimplWrapper();
            op.set_x(MAGIC_NUMBER);
            op_cpy_1 = op; // Copy assignment
            op_cpy_2 = OldPimplWrapper(op); // Copy constructor and move assignment
        }

        const auto OTHER_MAGIC_NUMBER = static_cast<int>(random());

        op_cpy_2.set_x(OTHER_MAGIC_NUMBER);

        const auto X_1 = op_cpy_1.get_x();
        const auto X_2 = op_cpy_2.get_x();

        REQUIRE(X_1 == MAGIC_NUMBER);
        REQUIRE(X_2 == OTHER_MAGIC_NUMBER);
    }
}
