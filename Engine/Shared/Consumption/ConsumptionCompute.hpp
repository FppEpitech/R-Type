/*
** EPITECH PROJECT, 2024
** ConsumptionCompute.hpp
** File description:
** DESCRIPTION
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

class ConsumptionCompute {
public:
    ConsumptionCompute();

    double ComputeCPUInfo();

    void ComputeGPUInfo();
#ifdef WIN32
    ~ConsumptionCompute();
    SIZE_T ComputeRAMInfo() const;
#else
    ~ConsumptionCompute() = default;
    int ComputeRAMInfo() const;
#endif
    void ComputeNETInfo();
private:
#ifdef _WIN32
    //ram
    static SIZE_T _physMemUsedByMe;
    //cpu
    ULARGE_INTEGER _lastCPU;
    ULARGE_INTEGER _lastSysCPU;
    ULARGE_INTEGER _lastUserCPU;
    int _numProcessors;
    HANDLE _self;
#else
    int _parseLine(const std::string& line);
    //cpu
    clock_t _lastCPU;
    clock_t _lastSysCPU;
    clock_t _lastUserCPU;
    int _numProcessors;
#endif

};
