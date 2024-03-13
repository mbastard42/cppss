#include "../inc/logger.hpp"

Logger::Logger() {

    _logFile.open(LOGFILE);
    _log = (_logFile.is_open() && LOG) ? true : false;
}

Logger::~Logger() {

    if (_logFile.is_open())
        _logFile.close();
}

void Logger::log(int message) { if (_log) _logFile << message << std::endl; };
void Logger::log(char message) { if (_log) _logFile << message << std::endl; };
void Logger::log(bool message) { if (_log) _logFile << message << std::endl; };
void Logger::log(float message) { if (_log) _logFile << message << std::endl; };
void Logger::log(double message) { if (_log) _logFile << message << std::endl; };
void Logger::log(std::string message) { if (_log) _logFile << message << std::endl; };
void Logger::log(const char * message) { if (_log) _logFile << message << std::endl; };
