#include "logger.h"

int main() {
    LOG_DEBUG("This is DEBUG");
    LOG_INFO("This is INFO");
    LOG_ERROR("This is ERROR");
    Logger::getInstance().setLogLevel(LogLevel::INFO);
    std::cout << LogLevel::INFO << std::endl;
    LOG_DEBUG("This is DEBUG");
    LOG_INFO("This is INFO");
    LOG_ERROR("This is ERROR");
    // Logger << "THIS IS OPERATOR OVERLOADING";
    return 1;
}