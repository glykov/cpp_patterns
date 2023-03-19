#include <ctime>
#include <cstring>
#include "logger.h"

// acquire resource 
Logger::Logger(const std::string& file_name)
{
    log_file.open(file_name, std::ios_base::out);
}

// free resource 
Logger::~Logger()
{
    if (log_file.is_open()) {
        log_file.close();
    }
}

std::string Logger::get_current_date_time() const
{
    time_t current_time = time(NULL);
    char buf[26];
    ctime_s(buf, sizeof(buf), &current_time);
    buf[strlen(buf) - 1] = '\0';                // removing endline symbol
    return std::string(buf);
}

void Logger::write_log(const std::string& str)
{
    if (log_file.is_open()) {
        log_file << get_current_date_time() << " - " << str << "\n";
    }
}

void Logger::write_log(const std::string& str, int n)
{
    if (log_file.is_open()) {
        log_file << get_current_date_time() << " - " << str << n << "\n";
    }
}

void Logger::write_log(const std::string& str, double d)
{
    if (log_file.is_open()) {
        log_file << get_current_date_time() << " - " << str << d << "\n";
    }
}