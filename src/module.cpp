#include "module.hpp"

namespace Module {
    EXTERN_C NTSTATUS __declspec(dllexport) inject(const wchar_t *process, char *bytes_c, size_t size) {
        blackbone::Process proc;

        if (NTSTATUS p = proc.Attach(process); p == STATUS_SUCCESS) {
            auto bytes = std::span(bytes_c, size);

            return proc.mmap().MapImage(bytes.size(), bytes.data()).status;
        } else {
            return p;
        }
    }

    EXTERN_C DWORD __declspec(dllexport) pid(const wchar_t* process) {
        blackbone::Process proc;

        if (NTSTATUS p = proc.Attach(process); p == STATUS_SUCCESS) {
            return proc.pid();
        } else {
            return 0x0;
        }
    }

    EXTERN_C DWORD __declspec(dllexport) module_address(const wchar_t *process, const wchar_t *module) {
        blackbone::Process proc;

        if (NTSTATUS p = proc.Attach(process); p == STATUS_SUCCESS) {
            return proc.modules().GetModule(module).get()->baseAddress;
        } else {
            return 0x0;
        }
    }
}