#include <iostream>
#include <vector>

#include "ffffff.h"
#include "debug_tools.h"

#include "classify.h"

struct foo {
    int a;
    char b;
    short c;
    long long d;
};

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

int main() {
    f220921<std::vector>();
    once_test();
    concat_test();
    
    auto count = fff::count([](int n) {return n * n;});
    
    std::cout << count(10) << ' ' << count(20) << ' ' << count(30) << ' ' << count.get_count() << '\n';
    
    int got =
            fff::pthrow(1) >> multiply<3> >> multiply<3>
                    >> multiply<3> >> multiply<3> >> fff::pcatch;
    
    auto f = fff::compose(
            [](int n) {return n * 2;},
            [](int n) {return n + 3;},
            [](int n) {return n * 4;}
    );
    
    std::cout << f(5) << '\n';
    std::cout << "The size of f is " << sizeof(f) << '\n';
}
