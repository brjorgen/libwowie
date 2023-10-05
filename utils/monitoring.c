#include <signal.h>
#include <stdint.h>
#include "../mem/mem.h"

void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
	/* wowie_printf("Caught %d at address %p\n", si->si_value, si->si_addr); */
	/* uint32_t allocations = libwowie_allocations(); */
	/* emergency_cleanup(allocations); */
	/* exit(1); */
}

void	libwowie_safety_net(){
    struct sigaction sa;

    wowie_memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = segfault_sigaction;
    sa.sa_flags     = SA_SIGINFO;

    sigaction(SIGSEGV, &sa, NULL);
};
