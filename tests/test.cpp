#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../Proxy.cpp"

// Custom stdout capture class
class StdoutCapture {
private:
    std::stringstream buffer;
    std::streambuf* original;

public:
    StdoutCapture() : original(std::cout.rdbuf()) {
        std::cout.rdbuf(buffer.rdbuf());
    }

    ~StdoutCapture() {
        std::cout.rdbuf(original);
    }

    std::string getOutput() {
        return buffer.str();
    }
};

// Test fixture for RealSubject
class RealSubjectTest : public ::testing::Test {
protected:
    RealSubject realSubject;
};

// Test that RealSubject behaves as expected when making a request
TEST_F(RealSubjectTest, Request) {
    StdoutCapture capture;
    realSubject.request();
    std::string output = capture.getOutput();
    ASSERT_EQ(output, "Real Subject request\n");
}

// Test fixture for Proxy
class ProxyTest : public ::testing::Test {
protected:
    Proxy proxy;
};

// Test that Proxy forwards requests to RealSubject correctly
TEST_F(ProxyTest, Request) {
    StdoutCapture capture;
    proxy.request();
    std::string output = capture.getOutput();
    ASSERT_EQ(output, "Real Subject request\n");
}

// Test that Proxy correctly cleans up its resources upon destruction
TEST_F(ProxyTest, Destruction) {
    StdoutCapture capture;
    {
        Proxy proxy;
        proxy.request();
    } // Proxy is destroyed here

    std::string output = capture.getOutput();
    ASSERT_EQ(output, "created\nReal Subject request\nim deleted\nim deleted\n");
}
