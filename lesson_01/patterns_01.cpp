#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>

std::string GetCurDateTime()
{
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return std::string(buf);
}

class ILogger
{
public:
    virtual void __fastcall WriteToLog(const std::string& str) = 0;
    virtual void __fastcall WriteToLog(const std::string& str, int n) = 0;
    virtual void __fastcall WriteToLog(const std::string& str, double d) = 0;
};

// реализация паттерна Singleton
class FileLoggerSingleton : public ILogger
{
public:
    ~FileLoggerSingleton() {
        CloseLogFile();
    }

    static FileLoggerSingleton& GetInstance(const std::string& fileName) {
        static FileLoggerSingleton logger(fileName);
        return logger;
    }

    void __fastcall WriteToLog(const std::string& message) {
        if (logOut.is_open()) {
            logOut << GetCurDateTime() << " - " << message << std::endl;
        }
    }
    void __fastcall WriteToLog(const std::string& message, int number) {
        if (logOut.is_open()) {
            logOut << GetCurDateTime() << " - " << message << number << std::endl;
        }
    }
    void __fastcall WriteToLog(const std::string& message, double number) {
        if (logOut.is_open()) {
            logOut << GetCurDateTime() << " - " << message << number << std::endl;
        }
    }
    
private:
    // закрытый конструктор, отключенные конструктор копирования и оператор присваивания
    FileLoggerSingleton(const std::string& fileName) {
        OpenLogFile(fileName);
    }
    FileLoggerSingleton(const FileLoggerSingleton& other) = delete;
    FileLoggerSingleton& operator=(const FileLoggerSingleton&) = delete;
    
    // функции открытия / закрытия лог-файла, вызываются из конструктора и деструктора.
    void __fastcall OpenLogFile(const std::string& fileName) {
        logOut.open(fileName, std::ios_base::out);
    }
    
    void __fastcall CloseLogFile() {
        if (logOut.is_open()) {
            logOut.close();
        }
    }
    
    std::ofstream logOut;
};

// реализация паттерна "Заместитель"
class SingleLogger : public ILogger
{
public:
    static SingleLogger& GetInstance(ILogger& logger){
        static SingleLogger currentLogger(logger);
        return currentLogger;
    }

    void setLogger(ILogger& logger) {
        _logger = logger;
    }

    virtual void __fastcall WriteToLog(const std::string& str) {
        recordCount++;
        std::string data = std::to_string(recordCount) + ": " + str;
        _logger.WriteToLog(data);
    }
    virtual void __fastcall WriteToLog(const std::string& str, int n) {
        recordCount++;
        std::string data = std::to_string(recordCount) + ": " + str;
        _logger.WriteToLog(data, n);
    }
    virtual void __fastcall WriteToLog(const std::string& str, double d) {
        recordCount++;
        std::string data = std::to_string(recordCount) + ": " + str;
        _logger.WriteToLog(data, d);
    }
private:
    SingleLogger(ILogger& logger) : _logger(logger), recordCount(0) {}
    SingleLogger(const SingleLogger&) = delete;
    SingleLogger& operator=(const SingleLogger&) = delete;
    ILogger& _logger;
    int recordCount;
};

int main()
{
    FileLoggerSingleton& log = FileLoggerSingleton::GetInstance("log.txt");
    SingleLogger& proxyLog = SingleLogger::GetInstance(log);
    proxyLog.WriteToLog("message");
    proxyLog.WriteToLog("message", 42);
    proxyLog.WriteToLog("message", 3.14);



    return 0;
}