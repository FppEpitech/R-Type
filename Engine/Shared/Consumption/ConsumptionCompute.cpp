/*
** EPITECH PROJECT, 2024
** ConsumptionCompute.cpp
** File description:
** DESCRIPTION
*/

#include <iostream>

#include "ConsumptionCompute.hpp"

#ifdef _WIN32

ConsumptionCompute::ConsumptionCompute()
{
    SYSTEM_INFO sysInfo;
    FILETIME ftime, fsys, fuser;

    GetSystemInfo(&sysInfo);
    _numProcessors = sysInfo.dwNumberOfProcessors;

    // Initialize process handle
    _self = GetCurrentProcess();

    // Get the current time and process times
    GetSystemTimeAsFileTime(&ftime);
    std::memcpy(&_lastCPU, &ftime, sizeof(FILETIME));

    GetProcessTimes(_self, &ftime, &ftime, &fsys, &fuser);
    std::memcpy(&_lastSysCPU, &fsys, sizeof(FILETIME));
    std::memcpy(&_lastUserCPU, &fuser, sizeof(FILETIME));
}

ConsumptionCompute::~ConsumptionCompute()
{
    CloseHandle(_self);
}

double ConsumptionCompute::ComputeCPUInfo()
{
    FILETIME ftime, fsys, fuser;
    ULARGE_INTEGER now, sys, user;
    double percent;

    // Get the current time as a FILETIME
    GetSystemTimeAsFileTime(&ftime);
    std::memcpy(&now, &ftime, sizeof(FILETIME));

    // Get the current process times (system and user times)
    if (!GetProcessTimes(_self, &ftime, &ftime, &fsys, &fuser)) {
        std::cerr << "Failed to get process times." << std::endl;
        return 0.0;
    }
    std::memcpy(&sys, &fsys, sizeof(FILETIME));
    std::memcpy(&user, &fuser, sizeof(FILETIME));

    // Ensure no division by zero
    if ((now.QuadPart - _lastCPU.QuadPart) == 0) {
        return 0.0;  // Prevent division by zero
    }

    // Calculate CPU usage percentage
    percent = (sys.QuadPart - _lastSysCPU.QuadPart) +
              (user.QuadPart - _lastUserCPU.QuadPart);
    percent /= (now.QuadPart - _lastCPU.QuadPart);
    percent /= _numProcessors;

    // Update _last values
    _lastCPU = now;
    _lastUserCPU = user;
    _lastSysCPU = sys;

    return percent;
}

SIZE_T ConsumptionCompute::ComputeRAMInfo()
{
    PROCESS_MEMORY_COUNTERS_EX pmc;
    SIZE_T physMemUsedByMe;

    if (GetProcessMemoryInfo(_self, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc)))
        physMemUsedByMe = pmc.WorkingSetSize;  // Physical RAM used by current _self
    else
        std::cerr << "Error retrieving process memory information!" << std::endl;
    return physMemUsedByMe / (1024 * 1024);
}

#else

ConsumptionCompute::ConsumptionCompute()
{
    std::ifstream file("/proc/cpuinfo");
    struct tms timeSample;
    std::string line;

    _lastCPU = times(&timeSample);
    _lastSysCPU = timeSample.tms_stime;
    _lastUserCPU = timeSample.tms_utime;

    _numProcessors = 0;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.compare(0, 9, "processor") == 0) {
                _numProcessors++;
            }
        }
        file.close();
    }
}

double ConsumptionCompute::ComputeCPUInfo()
{
    struct tms timeSample;
    clock_t now;
    double percent;

    now = times(&timeSample);
    if (now <= _lastCPU || timeSample.tms_stime < _lastSysCPU ||
        timeSample.tms_utime < _lastUserCPU) {
        // Overflow detection. Just skip this value.
        percent = -1.0;
    } else {
        percent = (timeSample.tms_stime - _lastSysCPU) +
                  (timeSample.tms_utime - _lastUserCPU);
        percent /= (now - _lastCPU);
        percent /= _numProcessors;
        percent *= 100;
    }
    _lastCPU = now;
    _lastSysCPU = timeSample.tms_stime;
    _lastUserCPU = timeSample.tms_utime;
    return percent;
}

int ConsumptionCompute::_parseLine(const std::string& line)
{
    size_t i = line.find_first_of("0123456789");
    if (i == std::string::npos) return -1;
    std::string numStr = line.substr(i);
    numStr = numStr.substr(0, numStr.size() - 3);
    return std::stoi(numStr);
}

int ConsumptionCompute::ComputeRAMInfo()
{
    std::ifstream file("/proc/self/status");
    int result = -1;
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line))
            if (line.compare(0, 6, "VmRSS:") == 0) {
                result = _parseLine(line);
                break;
            }
        file.close();
    } else {
        std::cerr << "Unable to open /proc/self/status" << std::endl;
    }
    return result;
}
#endif
