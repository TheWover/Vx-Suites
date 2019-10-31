
//@S
HANDLE _SFC=0;

BOOL (WINAPI *_SfcIsFileProtected)(HANDLE rpc,LPCWSTR fname);
//@E

void InitSFC()
{
 _SFC = _GetModuleHandle("sfc.dll");
 if (/*@S==*/_SFC == NULL/*@E*/) _SFC = _LoadLibrary("sfc.dll");
 if (/*@S==*/_SFC == NULL/*@E*/) return; // no sfc.dll

 _SfcIsFileProtected = (DWORD *)_GetProcAddress(_SFC,"SfcIsFileProtected");
}
