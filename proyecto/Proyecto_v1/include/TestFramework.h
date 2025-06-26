#ifndef _TEST_FRAMEWORK_
#define _TEST_FRAMEWORK_

#include <vector>
#include <string>
#include <functional>
#include <stdexcept>

class TestFramework {
public:
    static TestFramework& getInstance() {
        static TestFramework instance;
        return instance;
    }
    
    void registerTest(const std::string& name, std::function<void()> testFunc) {
        tests.push_back({name, testFunc});
    }
    
    void runAllTests();
    
private:
    struct Test {
        std::string name;
        std::function<void()> func;
    };
    
    std::vector<Test> tests;
};

// Macro para registrar tests automaticamente
#define REGISTER_TEST(test_name) \
    namespace { \
        struct test_name##_registrar { \
            test_name##_registrar() { \
                TestFramework::getInstance().registerTest(#test_name, test_name); \
            } \
        }; \
        static test_name##_registrar test_name##_reg; \
    }

#endif