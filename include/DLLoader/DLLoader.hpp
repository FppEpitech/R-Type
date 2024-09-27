/*
** EPITECH PROJECT, 2024
** R-Type Server
** File description:
** DLLoader
*/

#pragma once

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#include <functional>
#include <iostream>
#include <memory>
#include <string>


/**
 * @brief Loader class of '.so' files.
 *
 */
template <class T>
class DLLoader {

    /**
     * @brief Return type of the Symbol function.
     *
     */
    typedef T* (*CreateComponentFunc)();

public:

    /**
     * @brief Load a .so file and get a symbol function.
     *
     * @param libSo Path of the file to load.
     * @param symbol Symbol of the function to call.
     * @return std::shared_ptr<T> Return value of the function symbol.
     */
    static std::shared_ptr<T> load(const std::string& lib, const std::string& symbol) {
#ifdef _WIN32
        std::string libName = lib;
                size_t pos = libName.find(".dll");
                if (pos != std::string::npos)
                    libName.replace(pos, 4, ".so");
                void* handle = LoadLibrary(libName.c_str());
                if (!handle) {
                    std::cerr << "Failed to load library: " << libName << "on Windows" << std::endl;
                    return nullptr;
                }
                CreateComponentFunc createComponent = (CreateComponentFunc) GetProcAddress(static_cast<HMODULE>(handle), symbol.c_str());

                if (!createComponent) {
                    std::cerr << "Cannot load symbol " << symbol << std::endl;
                    FreeLibrary(static_cast<HMODULE>(handle));
                    return nullptr;
                }
                return std::shared_ptr<T>(createComponent());
#else
        std::string libName = lib;
        size_t pos = libName.find(".dll");
        if (pos != std::string::npos)
            libName.replace(pos, 4, ".so");
        void* handle = dlopen(libName.c_str(), RTLD_LAZY);
        if (!handle) {
            std::cerr << "Failed to load library: " << libName << "on Linux" << std::endl;
            return nullptr;
        }
        CreateComponentFunc createComponent = (CreateComponentFunc) dlsym(handle, symbol.c_str());

        const char* dlsym_error = dlerror();
        if (dlsym_error) {
            std::cerr << "Cannot load symbol " << symbol << ": " << dlsym_error << std::endl;
            dlclose(handle);
            return nullptr;
        }
        return std::shared_ptr<T>(createComponent());
#endif
    }
};
