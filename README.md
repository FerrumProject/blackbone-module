# blackbone-module

A simple "wrapper" for blackbone in the form of a dynamic library

## Possibilities
+ Injecting bytes into a process 
```cpp
EXTERN_C NTSTATUS __declspec(dllexport) __stdcall inject(const wchar_t*, char*, size_t);
```
+ Getting process id
```cpp
EXTERN_C DWORD __declspec(dllexport) pid(const wchar_t*);
```

+ Getting module address by name
```
EXTERN_C DWORD __declspec(dllexport) module_address(const wchar_t*, const wchar_t*);
```

## Example
```cpp
#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>

typedef int (*f_func)(const wchar_t*, char*, size_t);

int main() {
    auto dll = LoadLibrary("blackbone-module.dll");

    if (!dll) {
        std::cout << "DLL not found!" << std::endl;
        return 0;
    }

    f_func func = (f_func)GetProcAddress(dll, "inject");

    std::ifstream file("Osiris.dll", std::ios::binary | std::ios::in);

    std::vector<char> content;

    if (file.is_open()) {
        std::copy(
            std::istreambuf_iterator<char>(file),
            std::istreambuf_iterator<char>(),
            std::back_inserter(content)
        );
    }

    file.close();

    std::cout << "Status: " << func(L"cs2.exe", content.data(), content.size()) << std::endl;

    return 0;
}
```