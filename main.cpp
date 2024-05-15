#include "Proxy.cpp"
#include <fstream>
int main()
{
    Proxy *proxy = new Proxy();
    proxy->request();

    delete proxy;

    std::ofstream a("log.txt");
    a << "thingy thing";
    return 0;
}
