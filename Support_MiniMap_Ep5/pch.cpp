#include "pch.h"
#include <windows.h>
#include <fstream>

unsigned* g_SizeMap = (unsigned*)0x85D1D4;
void GetWordMap(uint16_t  nWord)
{
	switch (nWord)
	{
	case 3:
		*g_SizeMap = 480;
		break;
	case 04:
		*g_SizeMap = 234;
		break;
	case 5:
		*g_SizeMap = 304;
		break;
	case 6:
		*g_SizeMap = 360;
		break;
	case 7:
		*g_SizeMap = 376;
		break;
	case 8:
		*g_SizeMap = 360;
		break;
	case 9:
		*g_SizeMap = 848;
		break;
	case 10:
		*g_SizeMap = 648;
		break;
	case 11:
		*g_SizeMap = 568;
		break;
	case 12:
		*g_SizeMap = 496;
		break;
	case 13:
		*g_SizeMap = 512;
		break;
	case 14:
		*g_SizeMap = 672;
		break;
	case 15:
		*g_SizeMap = 328;
		break;
	case 16:
		*g_SizeMap = 472;
		break;
	case 17:
		*g_SizeMap = 720;
		break;
	case 21:
		*g_SizeMap = 536;
		break;
	case 23:
		*g_SizeMap = 432;
		break;
	case 24:
		*g_SizeMap = 544;
		break;
	case 26:
		*g_SizeMap = 720;
		break;
	case 27:
		*g_SizeMap = 1024;
		break;
	case 31:
		*g_SizeMap = 544;
		break;
	case 32:
		*g_SizeMap = 536;
		break;
	case 33:
		*g_SizeMap = 656;
		break;
	case 34:
		*g_SizeMap = 320;
		break;
	case 37:
		*g_SizeMap = 1024;
		break;
	case 38:
		*g_SizeMap = 598;
		break;
	case 39:
		*g_SizeMap = 168;
		break;
	case 40:
		*g_SizeMap = 192;
		break;
	case 41:
		*g_SizeMap = 96;
		break;
	case 42:
		*g_SizeMap = 128;
		break;
	case 48:
		*g_SizeMap = 1024;
		break;
	case 49:
		*g_SizeMap = 1024;
		break;
	case 55:
		*g_SizeMap = 264;
		break;
	case 56:
		*g_SizeMap = 264;
		break;
	case 57:
		*g_SizeMap = 199;
		break;
	case 58:
		*g_SizeMap = 120;
		break;
	case 59:
		*g_SizeMap = 656;
		break;
	case 60:
		*g_SizeMap = 376;
		break;
	case 61:
		*g_SizeMap = 552;
		break;
	case 64:
		*g_SizeMap = 1024;
		break;
	case 65:
		*g_SizeMap = 440;
		break;
	case 66:
		*g_SizeMap = 440;
		break;
	case 67:
		*g_SizeMap = 632;
		break;

	default:
		break;
	}
}
DWORD wSizeRet2 = 0x004C78B6;
DWORD wSizeRet = 0x004C23EF;
_declspec(naked) void wMapSize()
{
	_asm {
		pushad

		movzx eax, word ptr ds : [0x8666C4] // mapid 
		push eax
		call GetWordMap
		add esp, 0x04

		popad

		fild dword ptr ss : [0x85D1D4]

		jmp wSizeRet
	}
}


_declspec(naked) void wMapSize2()
{
	_asm {
		pushad

		movzx eax, word ptr ds : [0x8666C4] // mapid 
		push eax
		call GetWordMap
		add esp, 0x04

		popad

		fild dword ptr ss : [0x85D1D4]

		jmp wSizeRet2
	}
}



DWORD cLoadRet = 0x004C0D6F;
DWORD cLoadRet2 = 0x004C0FA2;
DWORD cLoadRet3 = 0x004C0FAF;





_declspec(naked) void cLoadMap()
{
	_asm {
		cmp dword ptr ds : [0x8666C4] , 3
		je wLoad03
		cmp dword ptr ds : [0x8666C4] , 4
		je wLoad04
		cmp dword ptr ds : [0x8666C4] , 5
		je wLoad05
		cmp dword ptr ds : [0x8666C4] , 6
		je wLoad06
		cmp dword ptr ds : [0x8666C4] , 7
		je wLoad07
		cmp dword ptr ds : [0x8666C4] , 8
		je wLoad08
		cmp dword ptr ds : [0x8666C4] , 9
		je wLoad09
		cmp dword ptr ds : [0x8666C4] , 10
		je wLoad10
		cmp dword ptr ds : [0x8666C4] , 11
		je wLoad11
		cmp dword ptr ds : [0x8666C4] , 12
		je wLoad12
		cmp dword ptr ds : [0x8666C4] , 13
		je wLoad13
		cmp dword ptr ds : [0x8666C4] , 14
		je wLoad14
		cmp dword ptr ds : [0x8666C4] , 15
		je wLoad15
		cmp dword ptr ds : [0x8666C4] , 16
		je wLoad16
		cmp dword ptr ds : [0x8666C4] , 17
		je wLoad17
		cmp dword ptr ds : [0x8666C4] , 21
		je wLoad21
		cmp dword ptr ds : [0x8666C4] , 23
		je wLoad23
		cmp dword ptr ds : [0x8666C4] , 24
		je wLoad24
		cmp dword ptr ds : [0x8666C4] , 26
		je wLoad26
		cmp dword ptr ds : [0x8666C4] , 27
		je wLoad27
		cmp dword ptr ds : [0x8666C4] , 31
		je wLoad31
		cmp dword ptr ds : [0x8666C4] , 32
		je wLoad32
		cmp dword ptr ds : [0x8666C4] , 33
		je wLoad33
		cmp dword ptr ds : [0x8666C4] , 34
		je wLoad34
		cmp dword ptr ds : [0x8666C4] , 37
		je wLoad37
		cmp dword ptr ds : [0x8666C4] , 38
		je wLoad38
		cmp dword ptr ds : [0x8666C4] , 39
		je wLoad39
		cmp dword ptr ds : [0x8666C4] , 40
		je wLoad40
		cmp dword ptr ds : [0x8666C4] , 41
		je wLoad41
		cmp dword ptr ds : [0x8666C4] , 42
		je wLoad42
		cmp dword ptr ds : [0x8666C4] , 48
		je wLoad48
		cmp dword ptr ds : [0x8666C4] , 49
		je wLoad49
		cmp dword ptr ds : [0x8666C4] , 55
		je wLoad55
		cmp dword ptr ds : [0x8666C4] , 56
		je wLoad56
		cmp dword ptr ds : [0x8666C4] , 57
		je wLoad57
		cmp dword ptr ds : [0x8666C4] , 58
		je wLoad58
		cmp dword ptr ds : [0x8666C4] , 59
		je wLoad59
		cmp dword ptr ds : [0x8666C4] , 60
		je wLoad60
		cmp dword ptr ds : [0x8666C4] , 64
		je wLoad64
		cmp dword ptr ds : [0x8666C4] , 65
		je wLoad65
		cmp dword ptr ds : [0x8666C4] , 66
		je wLoad66
		cmp dword ptr ds : [0x8666C4] , 67
		je wLoad67





		// originalcode
		movzx eax, byte ptr ds : [ebx + 0x4C1070]
		jmp cLoadRet

		wLoad03 :
		mov edx, dword ptr ds : [cLoad03]
			movzx ax, word ptr ds : [0x6C2654]
			mov[esp + 0x0C], edx
			mov[esp + 0x10], ax
			jmp cLoadRet3


			wLoad05 :
		mov edx, dword ptr ds : [cLoad05]
			movzx ax, word ptr ds : [0x6C2654]
			mov[esp + 0x0C], edx
			mov[esp + 0x10], ax
			jmp cLoadRet3


			wLoad06 :
		mov edx, dword ptr ds : [cLoad06]
			movzx ax, word ptr ds : [0x6C2654]
			mov[esp + 0x0C], edx
			mov[esp + 0x10], ax
			jmp cLoadRet3

			wLoad07 :
		mov edx, dword ptr ds : [cLoad07]
			movzx ax, word ptr ds : [0x6C2654]
			mov[esp + 0x0C], edx
			mov[esp + 0x10], ax
			jmp cLoadRet3

			wLoad08 :
		mov edx, dword ptr ds : [cLoad08]
			movzx ax, word ptr ds : [0x6C2654]
			mov[esp + 0x0C], edx
			mov[esp + 0x10], ax
			jmp cLoadRet3


			wLoad09 :
		mov edx, dword ptr ds : [cLoad09]
			movzx ax, word ptr ds : [0x6C2654]
			mov[esp + 0x0C], edx
			mov[esp + 0x10], ax
			jmp cLoadRet3

			wLoad10 :
		mov ecx, dword ptr ds : [cLoad10]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad11 :
		mov ecx, dword ptr ds : [cLoad11]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2


			wLoad12 :
		mov ecx, dword ptr ds : [cLoad12]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad13 :
		mov ecx, dword ptr ds : [cLoad13]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad14 :
		mov ecx, dword ptr ds : [cLoad14]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad15 :
		mov ecx, dword ptr ds : [cLoad15]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad16 :
		mov ecx, dword ptr ds : [cLoad16]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad17 :
		mov ecx, dword ptr ds : [cLoad17]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad21 :
		mov ecx, dword ptr ds : [cLoad21]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad23 :
		mov ecx, dword ptr ds : [cLoad23]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad24 :
		mov ecx, dword ptr ds : [cLoad24]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad26 :
		mov ecx, dword ptr ds : [cLoad26]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad27 :
		mov ecx, dword ptr ds : [cLoad27]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad31 :
		mov ecx, dword ptr ds : [cLoad31]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad32 :
		mov ecx, dword ptr ds : [cLoad32]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad33 :
		mov ecx, dword ptr ds : [cLoad33]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad34 :
		mov ecx, dword ptr ds : [cLoad34]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad37 :
		mov ecx, dword ptr ds : [cLoad37]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad38 :
		mov ecx, dword ptr ds : [cLoad38]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad40 :
		mov ecx, dword ptr ds : [cLoad40]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad41 :
		mov ecx, dword ptr ds : [cLoad41]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad48 :
		mov ecx, dword ptr ds : [cLoad48]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad49 :
		mov ecx, dword ptr ds : [cLoad49]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad55 :
		mov ecx, dword ptr ds : [cLoad55]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad56 :
		mov ecx, dword ptr ds : [cLoad56]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2


			wLoad57 :
		mov ecx, dword ptr ds : [cLoad57]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad58 :
		mov ecx, dword ptr ds : [cLoad58]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad59 :
		mov ecx, dword ptr ds : [cLoad59]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad60 :
		mov ecx, dword ptr ds : [cLoad60]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad61 :
		mov ecx, dword ptr ds : [cLoad61]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2


			wLoad65 :
		mov ecx, dword ptr ds : [cLoad65]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad66 :
		mov ecx, dword ptr ds : [cLoad66]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad67 :
		mov ecx, dword ptr ds : [cLoad67]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad39 :
		mov ecx, dword ptr ds : [cLoad39]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad42 :
		mov ecx, dword ptr ds : [cLoad42]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2

			wLoad04 :
		mov edx, dword ptr ds : [cLoad04]
			movzx ax, word ptr ds : [0x6C2654]
			mov[esp + 0x0C], edx
			mov[esp + 0x10], ax
			jmp cLoadRet3

			wLoad64 :
		mov ecx, dword ptr ds : [cLoad64]
			movzx dx, word ptr ds : [0x6C2604]
			movzx al, word ptr ds : [0x6C2606]
			jmp cLoadRet2
	}
}

DWORD dwFloat = 0;
float dw500 = 500.00;
DWORD wMapAjustRet = 0x004C2421;
_declspec(naked) void wMapSizeAjust()
{
	_asm {
		cmp word ptr ds : [0x8666C4] , 11
		jne originalcode
		push eax
		mov eax, dword ptr  ds : [dw500]
		mov[dwFloat], eax
		fmul dword ptr ds : [dwFloat]
		pop eax //396.00 kimu config

		jmp wMapAjustRet
		originalcode :

		fmul dword ptr ds : [0x6C11C8]
			jmp wMapAjustRet
	}
}

DWORD dwFld = 0;
float dw345 = 345.00;
DWORD wMapAjustRet2 = 0x004C2414;
_declspec(naked) void wMapSizeAjust2()
{
	_asm {
		cmp word ptr ds : [0x8666C4] , 11
		jne originalcode

		mov dword ptr ds : [dwFld] , 345
		fild dword ptr ds : [dwFld]
		jmp wMapAjustRet2

		originalcode :
		fild dword ptr ds : [0x0085D1D4]
			jmp wMapAjustRet2
	}
}

void Mini_Map_Suport_EP5(){
            Hook((void*)0x004C23E9, wMapSize, 6);
			Hook((void*)0x004C78B0, wMapSize2, 6);
			Hook((void*)0x004C241B, wMapSizeAjust, 6);
			Hook((void*)0x004C240E, wMapSizeAjust2, 6);}
        }
			
