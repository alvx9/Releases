#include "pch.h"
DWORD isNotLocalRessAddr = 0x004D7410;
DWORD sendRessLocalAddr = 0x004D7351;
DWORD enable_local_ress_ultimate_mode_return = 0x004D7334;
_declspec(naked) void enable_local_ress_ultimate_mode() {
	_asm {
		test eax,eax
		je sendRessLocal

		cmp eax,01
		jne isNotLocalRess
		jmp enable_local_ress_ultimate_mode_return 

		isNotLocalRess:
		jmp isNotLocalRessAddr

		sendRessLocal:
		jmp sendRessLocalAddr
	}
}


void RessLeaderandLocal() {
	Hook((PVOID)0x004D732B, enable_local_ress_ultimate_mode, 9);
}
