#pragma once

#include <map>
#include <fstream>

#define LOG         true
#define LOGFILE     "log.log"

class Logger {

    //  VARIABLES

    private:    bool            _log;
    public:     std::ofstream   _logFile;

    //  METHODS

    public:     Logger();
    public:     ~Logger();

    public:     void    log(int);
    public:     void    log(char);
    public:     void    log(bool);
    public:     void    log(float);
    public:     void    log(double);
    public:     void    log(std::string);
    public:     void    log(const char *);
};

extern Logger logger;