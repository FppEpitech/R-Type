/*
** EPITECH PROJECT, 2024
** ConsumptionCompute.hpp
** File description:
** @file ConsumptionCompute.hpp
** @brief Header file for the ConsumptionCompute class that handles CPU, RAM, and network consumption information.
*/

#pragma once

#ifdef _WIN32
#include "windows.h"
#include "psapi.h"
#include "TCHAR.h"
#include "pdh.h"
#else
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sys/times.h>
#include <fstream>
#endif

/**
 * @class ConsumptionCompute
 * @brief A class to compute system resource consumption, such as CPU, RAM, and Network usage.
 */
class ConsumptionCompute {
public:
    /**
     * @brief Constructor for ConsumptionCompute class.
     * Initializes internal state for CPU and memory computations.
     */
    ConsumptionCompute();

    /**
     * @brief Computes and returns CPU usage as a percentage.
     *
     * @return double The current CPU usage percentage.
     */
    double ComputeCPUInfo();

#ifdef WIN32
    /**
     * @brief Destructor for the ConsumptionCompute class.
     */
    ~ConsumptionCompute();

    /**
     * @brief Computes and returns RAM usage by the current process.
     *
     * @return SIZE_T The amount of physical memory used by the current process.
     */
    SIZE_T ComputeRAMInfo() const;
#else
    /**
     * @brief Destructor for the ConsumptionCompute class (on non-Windows platforms).
     * The default destructor is used.
     */
    ~ConsumptionCompute() = default;

    /**
     * @brief Computes and returns RAM usage in kilobytes (on non-Windows platforms).
     *
     * @return int The current RAM usage in kilobytes.
     */
    int ComputeRAMInfo();
#endif

private:
#ifdef _WIN32
    // RAM-related members
    /**
     * @brief The amount of physical memory used by the process.
     */
    static SIZE_T _physMemUsedByMe;

    // CPU-related members
    /**
     * @brief Stores the last CPU cycle time.
     */
    ULARGE_INTEGER _lastCPU;

    /**
     * @brief Stores the last system CPU cycle time.
     */
    ULARGE_INTEGER _lastSysCPU;

    /**
     * @brief Stores the last user CPU cycle time.
     */
    ULARGE_INTEGER _lastUserCPU;

    /**
     * @brief The number of processors available on the system.
     */
    int _numProcessors;

    /**
     * @brief Handle to the current process.
     */
    HANDLE _self;
#else
    // RAM-related methods
    /**
     * @brief Parses a line from the proc file to extract memory usage (on non-Windows platforms).
     *
     * @param line The string containing memory usage information.
     * @return int The parsed value from the line.
     */
    int _parseLine(const std::string& line);

    // CPU-related members
    /**
     * @brief Stores the last CPU cycle time.
     */
    clock_t _lastCPU;

    /**
     * @brief Stores the last system CPU cycle time.
     */
    clock_t _lastSysCPU;

    /**
     * @brief Stores the last user CPU cycle time.
     */
    clock_t _lastUserCPU;

    /**
     * @brief The number of processors available on the system.
     */
    int _numProcessors;
#endif

};
