#include <iostream>
#include <vector>

#include "ffffff.h"
#include "debug_tools.h"

#include "classify.h"

class Bar {
    friend class fff::AsSingle<Bar>;
    
    Bar() = default;
public:
    Bar(const Bar&) = delete;
    Bar(Bar&&) = delete;
    Bar &operator=(const Bar&) = delete;
    Bar &operator=(Bar&&) = delete;
    
    void say_hello() const {
        std::cout << "Say, Hello!\n";
    }
};

class Foo {
    int a, b, c, d;
};

int main() {
    using fff::Package;
    
    Package f;
    
    auto g = f.pipeline(
        add<2>,
        add<4>,
        multiply<3>,
        add<4>
    );
    
    std::cout << g(5) << '\n';
    
    auto h = g >> multiply<3> >> add<7>;
    std::cout << h(5) << '\n';
    
    auto h2 = f.pipeline >> add<1> >> add<3> >> multiply<6>;
    std::cout << h2(5) << '\n';
    
    auto g1 = [f](int n) {
        return f.multi_return(n, n * n);
    };
    
    auto g2 = [](int a, int b) {
        return a + b;
    };
    
    auto g3 = f.pipeline >> g1 >> g2;
    std::cout << g3(4) << '\n';
    
    std::cout << sizeof(h2) << ' ' << sizeof(g3) << '\n';

    std::cout << fff::MyClass::created() << '\n';

    maybe_test();

    fff::Test<int> test(1);
    auto test2 = test.lift([](const int &n) {return n * 2;});
    std::cout << test2.data << '\n';

    fff::Test<ForwardingTester> test3((ForwardingTester()));
    auto test4 = test.lift(fff::copy);
    auto test5 = fff::Test<ForwardingTester>(ForwardingTester()).lift(fff::copy);
}
