#include "pch.h"
DWORD isColorBackground = 0x282828; // https://htmlcolorcodes.com/ for check your color.
DWORD BackGroundColorAddr = 0x004345DA;
_declspec(naked) void BackGroundColor() {
	_asm {
		push 0x00
		push ecx // 0xFF
		fstp dword ptr[esp]
		push isColorBackground // color code
		push 0x03
		push 0x00
		push 0x00
		jmp BackGroundColorAddr
	}
}


DWORD BackGroundColorAddr2 = 0x00434718;
_declspec(naked) void BackGroundColor2() {
	_asm {
		push 0x00
		push ecx
		fstp dword ptr[esp]
		push isColorBackground
		push 0x03
		push 0x00
		push 0x00
		jmp BackGroundColorAddr2
	}
}

DWORD BackGroundColorAddr3 = 0x004349DA;
_declspec(naked) void BackGroundColor3() {
	_asm {
		push 0x00
		push ecx
		fstp dword ptr[esp]
		push isColorBackground
		push 0x03
		push 0x00
		push 0x00
		jmp BackGroundColorAddr3
	}
}

DWORD BackGroundColorAddr4 = 0x00434AC9;
_declspec(naked) void BackGroundColor4() {
	_asm {
		push 0x00
		push ecx
		fstp dword ptr[esp]
		push isColorBackground
		push 0x03
		push 0x00
		push 0x00
		jmp BackGroundColorAddr4
	}
}

void BackGround() {
	Hook((PVOID)0x004345CC, BackGroundColor, 6);
	Hook((PVOID)0x0043470A, BackGroundColor2, 6);
	Hook((PVOID)0x004349CC, BackGroundColor3, 6);
	Hook((PVOID)0x00434ABB, BackGroundColor4, 6);
}
