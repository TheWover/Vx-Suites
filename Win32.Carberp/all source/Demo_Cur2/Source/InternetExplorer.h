#include <windows.h>
#include <wininet.h>



//*********************************************************************
//  HookInternetExplorer - ������� ������ ���� �� Internet Explorer 
//  ������� ��������� � ����� �������� ��� ��������, ������� ������ 
//  ����, ������� ��� �������� ���������� � ������ ���� �� �������� ���
//*********************************************************************
bool HookInternetExplorer();

//*********************************************************************
//  HookInternetExplorerApi - ������� ������ ���� �� �������� API 
//  ������� ���������� �������� ��������� ��� �������� �������
//*********************************************************************
bool HookInternetExplorerApi();

//*********************************************************************
//  IEClearCache - ������� ������� ��� �������� ����������
//*********************************************************************
//void IEClearCache();

//*********************************************************************
//  IsInternetExplorer ������� ���������� ������ ���� ������ ������
//  �������� ��������� �������� ����������
//*********************************************************************
bool WINAPI IsInternetExplorer();