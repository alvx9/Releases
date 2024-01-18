#include "pch.h"

DWORD isStackAddress;
uint8_t updateAppareancePacket[75];  // Variável global
char characterName[22];

void copyShapePacket(uint8_t* getShapePacketData) {
    const int packetSize = 75;
    for (int i = 0; i < packetSize; ++i) {
        updateAppareancePacket[i] = getShapePacketData[i + 0x1C];
    }
}

void getShapeCharacterName() {
    const int startIndex = 53;
    const int characterNameSize = sizeof(characterName);

    for (int i = 0; i < characterNameSize; ++i) {
        characterName[i] = updateAppareancePacket[startIndex + i];
    }
}

void isgetPacket() {
    uint8_t* getShapePacketData;
    _asm {
        mov eax, dword ptr ds : isStackAddress
        mov[getShapePacketData], eax
    }

    uint16_t wordValue = *reinterpret_cast<uint16_t*>(getShapePacketData + 0x1C);
    if (wordValue != 0x0303) {
        return;
    }

    copyShapePacket(getShapePacketData);

    return;
}

DWORD getAppaerancePacketReturn = 0x005F4429;
_declspec(naked) void getAppaerancePacket() {

    _asm {

        mov[isStackAddress], esp
        pushad
        call isgetPacket
        popad

        mov ecx, [esp + 0x1C]
        lea eax, [esp + 0x24]
        jmp getAppaerancePacketReturn

    }
}


DWORD isGetShapeNameReturn = 0x00593D0A;
_declspec(naked) void isGetShapeName() {
    _asm {

        cmp byte ptr ds : [eax] , 0
        jne originalcode
        pushad
        call getShapeCharacterName
        popad
        mov eax, offset characterName

        originalcode :
        mov ecx, esi
        sub ecx, eax
        lea edx, [ecx + 0x0000010C]

        jmp isGetShapeNameReturn


    }
}



void getAppaerancePacketMain() {
    Hook((PVOID)0x005F4421, getAppaerancePacket, 8);
    Hook((PVOID)0x00593D00, isGetShapeName, 5);
}