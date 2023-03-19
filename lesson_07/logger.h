#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Logger
{
public:
    Logger(const std::string& file_name);
    ~Logger();
    void write_log(const std::string& str);
    void write_log(const std::string& str, int n);
    void write_log(const std::string& str, double d);
private:
    std::string get_current_date_time() const;
    std::ofstream log_file;
};