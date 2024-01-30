#include "PIGSyscall.hpp"

static auto& syscall = pigsyscall::syscall::get_instance();

#define NtCurrentThread ((HANDLE)-2)
#define ThreadHideFromDebugger 0x11 


int main() {

    void* allocation = nullptr;
    SIZE_T size = 0x1000;

    NtStatus status =  syscall.CallSyscall(HASH("NtSetInformationThread"),
        NtCurrentThread,
        ThreadHideFromDebugger,
        NULL,
        0);
    printf("[*] status %d", status);

    getchar();

    return 0;
}
