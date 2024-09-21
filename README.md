# `logger.h`

`logger.h` provides a simple logging utility with different logging levels: DEBUG, INFO, and ERROR.

## Usage

1. Include the header:
    ```cpp
    #include "logger.h"
    ```

2. Log messages using macros:
    ```cpp
    LOG_DEBUG("Debug message");
    LOG_INFO("Info message");
    LOG_ERROR("Error message");
    ```

3. Set the log level:
    ```cpp
    Logger::getInstance().setLogLevel(LogLevel::INFO);
    ```
