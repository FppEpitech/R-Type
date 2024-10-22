/*
** EPITECH PROJECT, 2024
** ConsumptionCompute.cpp
** File description:
** DESCRIPTION
*/

#include "ConsumptionCompute.hpp"

#ifdef _WIN32

ConsumptionCompute::ConsumptionCompute()
{
    HANDLE _self = GetCurrentProcess();
    SYSTEM_INFO sysInfo;
    FILETIME ftime;
    FILETIME fsys;
    FILETIME fuser;

    // Get the number of processors
    GetSystemInfo(&sysInfo);
    _numProcessors = sysInfo.dwNumberOfProcessors;

    // Get the current time as a FILETIME and store it in _lastCPU
    GetSystemTimeAsFileTime(&ftime);
    std::memcpy(&_lastCPU, &ftime, sizeof(FILETIME));

    // Get the current process handle
    self = GetCurrentProcess();

    // Get the process times (system and user times)
    GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
    std::memcpy(&lastSysCPU, &fsys, sizeof(FILETIME));
    std::memcpy(&lastUserCPU, &fuser, sizeof(FILETIME));
}

double ConsumptionCompute::ComputeCPUInfo() {
    FILETIME ftime, fsys, fuser;
    ULARGE_INTEGER now, sys, user;
    double percent;

    // Get the current time as a FILETIME
    GetSystemTimeAsFileTime(&ftime);
    std::memcpy(&now, &ftime, sizeof(FILETIME));

    // Get the current process times (system and user times)
    GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
    std::memcpy(&sys, &fsys, sizeof(FILETIME));
    std::memcpy(&user, &fuser, sizeof(FILETIME));

    // Calculate CPU usage percentage
    percent = (sys.QuadPart - _lastSysCPU.QuadPart) +
              (user.QuadPart - _lastUserCPU.QuadPart);
    percent /= (now.QuadPart - _lastCPU.QuadPart);
    percent /= _numProcessors;

    // Update _last values
    _lastCPU = now;
    _lastUserCPU = user;
    _lastSysCPU = sys;
    return percent * 100;
}

void ConsumptionCompute::ComputeRAMInfo() {
    PROCESS_MEMORY_COUNTERS_EX pmc;

    if (GetProcessMemoryInfo(_self, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
        SIZE_T physMemUsedByMe = pmc.WorkingSetSize;  // Physical RAM used by current _self
        SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;  // Virtual memory used by current _self

        std::cout << "Physical Memory Used by Current Process: " << physMemUsedByMe / (1024 * 1024) << " MB" << std::endl;
        std::cout << "Virtual Memory Used by Current Process: " << virtualMemUsedByMe / (1024 * 1024) << " MB" << std::endl;
    } else {
        std::cerr << "Error retrieving process memory information!" << std::endl;
    }

    CloseHandle(process);
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
