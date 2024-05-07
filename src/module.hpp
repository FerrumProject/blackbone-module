#include <string>
#include <fstream>
#include <iostream>
#include <span>

#pragma comment(lib, "BlackBone.lib")
#include <blackbone/src/BlackBone/Process/Process.h>

namespace Module {
    EXTERN_C NTSTATUS __declspec(dllexport) __stdcall inject(const wchar_t*, char*, size_t);
    EXTERN_C DWORD __declspec(dllexport) pid(const wchar_t*);
    EXTERN_C DWORD __declspec(dllexport) module_address(const wchar_t*, const wchar_t*);
}