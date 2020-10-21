#ifndef HARNESS_H
#define HARNESS_H

#include <iostream>
#include <string>

class Harness {
private:
    int total_run = 0;
    int total_passed = 0;
    std::string cur_context = "[no context]";
    std::string cur_test = "[no test]";

    std::ostream& report() {
        return std::cout << "test failed! " << cur_context << " " << cur_test << " - ";
    }
    template <typename T_A, typename T_B, typename F>
    void test(T_A a, T_B b, F lambda, std::string message, std::string test) {
        if (test.length()) cur_test = test;
        total_run++;
        if (lambda(a, b)) {
            total_passed++;
        } else {
            report() << "expected " << a << " " << message << " " << b << std::endl;
        }
    }

public:
    void results() {
        std::cout << "all tests run. " << total_passed << "/" << total_run << " passed." << std::endl;
    }

    void context(std::string ctx) {
        cur_context = ctx;
        std::cout << "running " << ctx << " tests..." << std::endl;
    }

    template <typename A, typename B>
    void eq(A a, B b, std::string name = "") {
        test(a, b, [](A a, B b) { return a == b; }, "==", name);
    }
    template <typename A, typename B>
    void lt(A a, B b, std::string name = "") {
        test(a, b, [](A a, B b) { return a < b; }, "<", name);
    }
    template <typename A, typename B>
    void gt(A a, B b, std::string name = "") {
        test(a, b, [](A a, B b) { return a > b; }, ">", name);
    }
};

#endif
