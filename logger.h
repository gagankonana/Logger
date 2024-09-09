#ifndef _LIBRARY_LOGGER_LOGGER_H
#define _LIBRARY_LOGGER_LOGGER_H

#include <string>
#include <iostream>
#include <chrono>
#include <ctime>

enum LogLevel {
    DEBUG,
    INFO,
    ERROR
};

class Logger {    
public:
    Logger() {}

    static Logger &getInstance() {
        static Logger instance;
        return instance;
    }

    void setLogLevel(LogLevel _log_level) { log_level = _log_level; std::cout << log_level << std::endl;}

    void logger(const std::string& msg, const std::string_view level) {
        std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string time_string = std::string(std::ctime(&time));
        time_string.pop_back();
        std::cout << time_string <<  " [ " << level << "] " << msg << std::endl;
    }

    void error(const std::string& msg) {
        if (log_level <= LogLevel::ERROR)
        logger(msg, "ERROR");
    }

    void info(const std::string& msg) {
        if (log_level <= LogLevel::INFO)
       logger(msg, "INFO ");
    }

    void debug(const std::string& msg) {
        std::cout << log_level << std::endl;
        if (log_level <= LogLevel::DEBUG)
       logger(msg, "DEBUG");
    }

    Logger operator<<(std::string msg) {
        debug(msg);
        return getInstance();
    }

private:
    LogLevel log_level;

};

#define LOG_DEBUG(msg) Logger::getInstance().debug(msg);
#define LOG_INFO(msg) Logger::getInstance().info(msg);
#define LOG_ERROR(msg) Logger::getInstance().error(msg);

#endif