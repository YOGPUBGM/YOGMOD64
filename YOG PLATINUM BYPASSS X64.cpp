bool CryzerInD = true;//
bool EnableLog = true;//

void CryzerEg2032(unsigned int ret, char *name, ...)
{
    if (!CryzerInD) return;
    char dest[1024 * 16];
    va_list argptr;
    va_start(argptr, name);
    vsprintf(dest, name, argptr);
    va_end(argptr);

    if (ret > libanogsBase && ret < (libanogsBase + libanogsSize)) LOGI("%s |  ANO + %p", dest, ret - libanogsBase);
    else if (ret > libUE4Base && ret < (libUE4Base + libUE4Size)) LOGI("%s | UE4 + %p", dest, ret - libUE4Base);
    LOGI("%s | Memory + %p", dest, ret);
    return;
}

void CaseSize(unsigned int ret, char *name, ...)
{
    if (!EnableLog) return;
    char dest[1024 * 16];
    va_list argptr;
    va_start(argptr, name);
    vsprintf(dest, name, argptr);
    va_end(argptr);

    if (ret > libanogsBase && ret < (libanogsBase + libanogsSize)) LOGI("%s |  ANO + %p", dest, ret - libanogsBase);
    else if (ret > libUE4Base && ret < (libUE4Base + libUE4Size)) LOGI("%s | UE4 + %p", dest, ret - libUE4Base);
    else
        LOGI("%s | Memory + %p", dest, ret);
    return;
}
 
#define CryzerHookIndEg(RET, NAME, ARGS) \
  RET(*o##NAME) ARGS; \
  RET h##NAME ARGS

CryzerHookIndEg(__int64 __fastcall,  __strncpy_chk2, ())
{
    auto ret = reinterpret_cast<uintptr_t>(__builtin_return_address(0));
    CryzerEg2032(ret, "__strncpy_chk2");
    return 0;
}

__int64 __memcpy_chk()
{
	return 0LL;
}

size_t hook_strlen(const char *s)
{
    if (strstr(s, "eglswap"))
    {
        return 0;
    }
 
 if (strstr(s, "eglSwapBuffers"))
 {
  return 0;
 }
 
    return strlen(s);
}

__int64 __fastcall (*osub_1749A8)(__int64 a1, const char *a2, __int64 a3);
__int64 __fastcall sub_1749A8(__int64 a1, const char *a2, __int64 a3){
   
   if ( strstr(a2,"blur_exit") || /// @SOURCE_KA_ADDA
       strstr(a2,"vm_vap_ext") || // @SOURCE_KA_ADDA
       strstr(a2,"crash") || // @SOURCE_KA_ADDA
       strstr(a2,"crash_various_opcode") || // @SOURCE_KA_ADDA
       strstr(a2,"anti_root")){ // @SOURCE_KA_ADDA
       return 0;
}
    return osub_1749A8(a1,a2,a3);
}

size_t (*osub_8EA11D0)(const char *thread);
size_t hsub_8EA11D0(const char *thread)
{
    if (("eglSwapBuffers"))
    {
        return 0;
    }
    return osub_8EA11D0(thread);
}


__int64 __fastcall (*osub_FAE44)(unsigned int *a1);
__int64 __fastcall hsub_FAE44(unsigned int *a1)
{
  __int64 result; // x0
  result = *((_QWORD *)a1 + 2);
  if (result)
  {
      result = 0;
      return result;
  }
  return osub_FAE44(a1);
}

__int64 __fastcall (*osub_E599C)(__int64 a1);
__int64 __fastcall sub_E599C(__int64 a1)
{
  
      auto ret = reinterpret_cast<uintptr_t>(__builtin_return_address(0));  
    if ( (ret - libanogsBase) == 0xE599C) {return 0LL;}

    return 0;
  
}

char * (*oAnoSDKIoctl_0)(int a1, int a2);
char *__fastcall Hooked_AnoSDKIoctl_0(int a1, int a2)
{
    LOGI("AnoSDKIoctl_0 Calls %d", a1);
    switch ( a1 )
    {


        case 45:

            return oAnoSDKIoctl_0(0, a2);
            break;
        case 18:
            return oAnoSDKIoctl_0(0, a2);
            break;
        case 10:
            return oAnoSDKIoctl_0(0, a2);
            break;
    }
    return oAnoSDKIoctl_0(a1,a2);
}


int (*sub_1ECA70)(int a1, const char *a2);
int hsub_1ECA70(__int64 a1, const char *a2) {
 if (strstr(a2, ("egl")) ||
       strstr(a2, ("eglSwapBuffers")) ||
	   strstr(a2, ("unlocked")) ||
        strstr(a2, ("ro.")) ||
       strstr(a2, ("sys.oem_unlock_allowed")))
    {
        return 0LL;
    }
    return hsub_1ECA70(a1, a2);
}

__int64 (*osub_22C4F4)(__int64 a1, unsigned int a2, __int64 a3);
__int64 __fastcall hsub_22C4F4(__int64 a1, unsigned int a2, __int64 a3)
{
 if ( a2 && a2 < 0x10000 )
  {
      return 0LL;
  }
   return osub_22C4F4(a1, a2, a3);
}

__int64 __fastcall (*sub_18B4EC)(const char *a1, unsigned int a2);
__int64 __fastcall hsub_18B4EC(const char *a1, unsigned int a2)
{
while (true) {
sleep(1);
}
return sub_18B4EC(a1, a2);
}

__int64 (*sub_1672E8)(__int64 a1, unsigned __int8 *a2, size_t a3);
__int64 __fastcall hsub_1672E8(__int64 a1, unsigned __int8 *a2, size_t a3)
{
if ( a3 == string2Offset(OBFUSCATE("0x3E")))  {
 return 0LL; }
sub_1672E8(a1, a2, a3);
        }
		
__int64 __fastcall (*osub_5A2817C)(__int64 result, float a2);
__int64 __fastcall sub_5A2817C(__int64 result, float a2)
{
     auto Upload = (UBulletHitInfoUploadComponent*)result;
     Upload->bEnableTssSdkAntiData = false;
     Upload->bEnableTssSdkAntiDataFilter = false;
     Upload->bEnableTssSdkAntiDataFilterNew = false;
     Upload->bDisableDsTick = false;
     Upload->bDisableDsAntiDataReport = false;
     Upload->bEnableAddSPCShootData = false;
     Upload->NeedSendSimpleCharacterHitData = false;
   
   return osub_5A2817C(result, a2);
}

void* hook_dlopen(void *a1, const void *a2, size_t a3)
{
    if(a3 == 0x58u || a3 == 0x44u){
         LOGI("%p", a3);
         return (void*) hook_dlopen(0,0,0);
        // memcpy(a1, a2, 0);
    }
    return memcpy(a1,a2,a3);
}

void* hook_memcpy(char *dest, const char *src, size_t size)
{
    if ((DWORD)src >= libanogsBase && (DWORD)src <= (DWORD)(libanogsBase + libanogsSize))
    {
        Offset = (char *)(src - (char *)libanogsBase);
        NewBase = libanogsAlloc;
        src = &Offset[NewBase];
        return memcpy(dest, src, size);
    }
    
    return memcpy(dest, src, size);
}

const void* (__fastcall* sub_1676F8)(__int64 a1);
const void* __fastcall hsub_1676F8(__int64 a1)
{
    if (a1 < 1064) {
        
        return 0;
    }
    return sub_1676F8(a1);
}

__int64 __strncpy_chk2()
{
  return 0LL;
}


//BYPASS
HOOK_LIB_NO_ORIG("libanogs.so", "0xdf3f0", h__strncpy_chk2);//fixCrashGame
PATCH_LIB("libanogs.so", "0xdf0a0", "00 00 80 D2 C0 03 5F D6");//.__strncpy_chk
HOOK_LIB("libanogs.so","0x1749A8",sub_1749A8, osub_1749A8); // CASE 16 LOBBY CRASH FIX
HOOK_LIB_NO_ORIG("libUE4.so", "0xb0eca60", hook_memcpy);
HOOK_LIB("libanogs.so", "0x1676F8", hsub_1676F8, sub_1676F8);//C37
//HOOK_LIB_NO_ORIG("libanogs.so", "0xE00E0", hook_dlopen); //Offline fix
HOOK_LIB("libanogs.so", "0xE599C", sub_E599C, osub_E599C);
HOOK_LIB("libanogs.so", "0x3FEAD4", Hooked_AnoSDKIoctl_0,oAnoSDKIoctl_0);
HOOK_LIB("libgcloud.so",0xFAE44,hsub_FAE44,osub_FAE44);
HOOK_LIB_NO_ORIG("libUE4.so","0xb0eca40",hook_strlen);//EGLBLOCK
HOOK_LIB("libanogs.so", "0x1672E8", hsub_1672E8, sub_1672E8); // case 35
HOOK_LIB("libUE4.so", "0x5A2817C", sub_5A2817C, osub_5A2817C);// 1D fix
HOOK_LIB_NO_ORIG("libanogs.so", "0xDF3F0", __strncpy_chk2);
PATCH_LIB("libanogs.so","0x1f02c0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xdfc10","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0x1e86c0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so","0xdf850","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xb0ed5c0","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xb0ed600","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so","0xb0ed630","00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0xDFC40", "00 00 80 D2 C0 03 5F D6"); //.memcpy_chk
PATCH_LIB("libanogs.so", "0x1676F8", "00 00 80 D2 C0 03 5F D6"); //aGet3DP
PATCH_LIB("libanogs.so", "0xEE004", "00 00 80 D2 C0 03 5F D6"); //AnoSDKSetUserInfo
PATCH_LIB("libUE4.so", "0x9CC70D0", "C0 03 5F D6");//Termination
PATCH_LIB("libUE4.so", "0x952BD6C", "00 00 80 D2 C0 03 5F D6");//flag fix
PATCH_LIB("libroosterNN.so", "0x67EAC", "00 00 80 D3 C0 03 5F D6");
PATCH_LIB("libroosterNN.so", "0xBA9B8", "00 00 80 D3 C0 03 5F D6");
PATCH_LIB("libroosterNN.so", "0x105614", "00 00 80 D3 C0 03 5F D6");
PATCH_LIB("libroosterNN.so", "0x1E0050", "00 00 80 D3 C0 03 5F D6");
PATCH_LIB("libroosterNN.so", "0x1E006C", "00 00 80 D3 C0 03 5F D6");
PATCH_LIB("libRoosterNN.so","0x1B460C","00 00 80 D2 C0 03 5F D6");  //  Flag fix
PATCH_LIB("libRoosterNN.so","0x1B4668","00 00 80 D2 C0 03 5F D6");  //  Flag Fix
PATCH_LIB("libRoosterNN.so","0x1B4644","00 00 80 D2 C0 03 5F D6");  //   Flag Fix
PATCH_LIB("libRoosterNN.so","0x1B4630","00 00 80 D2 C0 03 5F D6");  //  Flag 
PATCH_LIB("libRoosterNN.so","0x1B462C","C0 03 5F D6"); //->  1Day fix
PATCH_LIB("libRoosterNN.so","0x1B4618","00 00 80 D2 C0 03 5F D6");  //  flag fix
PATCH_LIB("libRoosterNN.so","0x67EAC","00 00 80 D2 C0 03 5F D6");  //  Flag fix
PATCH_LIB("libRoosterNN.so","0xBA9B8","00 00 80 D2 C0 03 5F D6");  //  Flag fix
PATCH_LIB("libRoosterNN.so","0x105614","00 00 80 D2 C0 03 5F D6");  //  Flag fix
PATCH_LIB("libRoosterNN.so","0x1E0050","00 00 80 D2 C0 03 5F D6");  //  Flag fix
PATCH_LIB("libRoosterNN.so","0x1E006C","00 00 80 D2 C0 03 5F D6");  //  Flag fix
PATCH_LIB("libUE4.so", "0x5a28598", "1F 20 03 D5");//
PATCH_LIB("libUE4.so", "0x5ee13d8", "1F 20 03 D5");//
PATCH_LIB("libUE4.so", "0x50F4D18", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x50CD4AC", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x4FDA5D0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x5d33db4", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x5f78cc0", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x5ed93d8", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libUE4.so", "0x50F4D18", "00 00 80 D2 C0 03 5F D6");
PATCH_LIB("libanogs.so", "0xdf040", "00 00 80 D2 C0 03 5F D6");//.kill
PATCH_LIB("libTDataMaster.so","0x934EC","C0 03 5F D6");
PATCH_LIB("libTDataMaster.so","0x934F0","C0 03 5F D6");
PATCH_LIB("libTDataMaster.so","0x934F4","C0 03 5F D6");   
PATCH_LIB("libTDataMaster.so","0x934F8","C0 03 5F D6");        
PATCH_LIB("libTDataMaster.so","0x934FC","C0 03 5F D6");
PATCH_LIB("libTDataMaster.so","0x93500","C0 03 5F D6");
PATCH_LIB("libTDataMaster.so","0x93504","C0 03 5F D6");
PATCH_LIB("libTDataMaster.so","0x93508","C0 03 5F D6");
PATCH_LIB("libTDataMaster.so","0x9350C","C0 03 5F D6");
PATCH_LIB("libTDataMaster.so","0x93510","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x33B0150","1F 20 03 D5");
PATCH_LIB("libanogs.so","0x13E958","00 00 80 D2 C0 03 5F D6"); //cmd checking @X_Values
PATCH_LIB("libanogs.so","0x3C5393","00 00 80 D2 C0 03 5F D6"); //chks @X_Values
PATCH_LIB("libanogs.so","0x3C539C","00 00 80 D2 C0 03 5F D6"); //chks @X_Values
PATCH_LIB("libanogs.so","0x13E8E4","00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so","0x3C4E24","00 00 80 D2 C0 03 5F D6"); // Server V4 @X_Values
PATCH_LIB("libanogs.so","0x3C52FC","00 00 80 D2 C0 03 5F D6"); // 
PATCH_LIB("libanogs.so","0x1A8C14","00 00 80 D2 C0 03 5F D6"); //Reconnect to server @X_Values
PATCH_LIB("libanogs.so","0x1C2150","00 00 80 D2 C0 03 5F D6"); //Vor #2 @X_Values
PATCH_LIB("libanogs.so","0x108708","00 00 80 D2 C0 03 5F D6"); 
PATCH_LIB("libanogs.so","0x25AC6C","00 00 80 D2 C0 03 5F D6");  //10y
PATCH_LIB("libanogs.so","0x5446E8","00 00 80 D2 C0 03 5F D6");//5446E8
PATCH_LIB("libanogs.so","0x544A28","00 00 80 D2 C0 03 5F D6");//544A28
PATCH_LIB("libanogs.so","0x544B88","00 00 80 D2 C0 03 5F D6");//544B88
PATCH_LIB("libanogs.so","0x544BA8","00 00 80 D2 C0 03 5F D6");//544BA8
PATCH_LIB("libanogs.so","0x544CD8","00 00 80 D2 C0 03 5F D6");//544CD8
PATCH_LIB("libanogs.so","0x544D40","00 00 80 D2 C0 03 5F D6");//544D40
PATCH_LIB("libanogs.so","0x544F48","00 00 80 D2 C0 03 5F D6");//544F48
PATCH_LIB("libanogs.so","0x544FE8","00 00 80 D2 C0 03 5F D6");//544FE8
PATCH_LIB("libanogs.so","0x545008","00 00 80 D2 C0 03 5F D6");//545008
PATCH_LIB("libanogs.so","0x545248","00 00 80 D2 C0 03 5F D6");//545248
PATCH_LIB("libanogs.so","0x545268","00 00 80 D2 C0 03 5F D6");//545268
PATCH_LIB("libanogs.so","0x545288","00 00 80 D2 C0 03 5F D6");//545288
PATCH_LIB("libanogs.so","0x5452A8","00 00 80 D2 C0 03 5F D6");//5452A8
PATCH_LIB("libanogs.so","0x5452C8","00 00 80 D2 C0 03 5F D6");//5452C8
PATCH_LIB("libanogs.so","0x5452E8","00 00 80 D2 C0 03 5F D6");//5452E8
PATCH_LIB("libanogs.so","0x545308","00 00 80 D2 C0 03 5F D6");//545308
PATCH_LIB("libanogs.so","0x545328","00 00 80 D2 C0 03 5F D6");//545328
PATCH_LIB("libanogs.so","0x545348","00 00 80 D2 C0 03 5F D6");//545348
PATCH_LIB("libanogs.so","0x545368","00 00 80 D2 C0 03 5F D6");//545368
PATCH_LIB("libanogs.so","0x545388","00 00 80 D2 C0 03 5F D6");//545388
PATCH_LIB("libanogs.so","0x5453A8","00 00 80 D2 C0 03 5F D6");//5453A8
PATCH_LIB("libanogs.so","0x5453C8","00 00 80 D2 C0 03 5F D6");//5453C8
PATCH_LIB("libanogs.so","0x5453E8","00 00 80 D2 C0 03 5F D6");//5453E8
PATCH_LIB("libanogs.so","0x545408","00 00 80 D2 C0 03 5F D6");//545408
PATCH_LIB("libanogs.so","0x545428","00 00 80 D2 C0 03 5F D6");//545428
PATCH_LIB("libanogs.so","0x545D68","00 00 80 D2 C0 03 5F D6");//545D68
PATCH_LIB("libanogs.so","0x5461E0","00 00 80 D2 C0 03 5F D6");//5461E0
PATCH_LIB("libanogs.so","0x546220","00 00 80 D2 C0 03 5F D6");//546220
PATCH_LIB("libanogs.so","0x546260","00 00 80 D2 C0 03 5F D6");//546260
PATCH_LIB("libanogs.so","0x546308","00 00 80 D2 C0 03 5F D6");//546308
PATCH_LIB("libanogs.so","0x546478","00 00 80 D2 C0 03 5F D6");//546478
PATCH_LIB("libanogs.so","0x5464C0","00 00 80 D2 C0 03 5F D6");//5464C0
PATCH_LIB("libanogs.so","0x5469D8","00 00 80 D2 C0 03 5F D6");//5469D8
PATCH_LIB("libanogs.so","0x546B98","00 00 80 D2 C0 03 5F D6");//546B98
PATCH_LIB("libanogs.so","0x546CD8","00 00 80 D2 C0 03 5F D6");//546CD8
PATCH_LIB("libanogs.so","0x546D78","00 00 80 D2 C0 03 5F D6");//546D78
PATCH_LIB("libanogs.so","0x546E00","00 00 80 D2 C0 03 5F D6");//546E00
PATCH_LIB("libanogs.so","0x5473E8","00 00 80 D2 C0 03 5F D6");//5473E8
PATCH_LIB("libanogs.so","0x5475C0","00 00 80 D2 C0 03 5F D6");//5475C0
PATCH_LIB("libanogs.so","0x547608","00 00 80 D2 C0 03 5F D6");//547608
PATCH_LIB("libanogs.so","0x5476A8","00 00 80 D2 C0 03 5F D6");//5476A8
PATCH_LIB("libanogs.so","0x547970","00 00 80 D2 C0 03 5F D6");//547970
PATCH_LIB("libanogs.so","0x547A28","00 00 80 D2 C0 03 5F D6");//547A28
PATCH_LIB("libanogs.so","0x547A48","00 00 80 D2 C0 03 5F D6");//547A48
PATCH_LIB("libanogs.so","0x547AC0","00 00 80 D2 C0 03 5F D6");//547AC0
PATCH_LIB("libanogs.so","0x547AF8","00 00 80 D2 C0 03 5F D6");//547AF8
PATCH_LIB("libanogs.so","0x547C40","00 00 80 D2 C0 03 5F D6");//547C40
PATCH_LIB("libanogs.so","0x547C60","00 00 80 D2 C0 03 5F D6");//547C60
PATCH_LIB("libanogs.so","0x547D20","00 00 80 D2 C0 03 5F D6");//547D20
PATCH_LIB("libanogs.so","0x547FC8","00 00 80 D2 C0 03 5F D6");//547FC8
PATCH_LIB("libanogs.so","0x548030","00 00 80 D2 C0 03 5F D6");//548030
PATCH_LIB("libanogs.so","0x548260","00 00 80 D2 C0 03 5F D6");//548260
PATCH_LIB("libanogs.so","0x548430","00 00 80 D2 C0 03 5F D6");//548430
PATCH_LIB("libanogs.so","0x548780","00 00 80 D2 C0 03 5F D6");//548780
PATCH_LIB("libanogs.so","0x5487A0","00 00 80 D2 C0 03 5F D6");//5487A0
PATCH_LIB("libanogs.so","0x548958","00 00 80 D2 C0 03 5F D6");//548958
PATCH_LIB("libanogs.so","0x548A40","00 00 80 D2 C0 03 5F D6");//548A40
PATCH_LIB("libanogs.so","0x548C10","00 00 80 D2 C0 03 5F D6");//548C10
PATCH_LIB("libanogs.so","0x5491C0","00 00 80 D2 C0 03 5F D6");//5491C0
PATCH_LIB("libanogs.so","0x549248","00 00 80 D2 C0 03 5F D6");//549248
PATCH_LIB("libanogs.so","0x5492E0","00 00 80 D2 C0 03 5F D6");//5492E0
PATCH_LIB("libanogs.so","0x549670","00 00 80 D2 C0 03 5F D6");//549670
PATCH_LIB("libanogs.so","0x5499E0","00 00 80 D2 C0 03 5F D6");//5499E0
PATCH_LIB("libanogs.so","0x549A98","00 00 80 D2 C0 03 5F D6");//549A98
PATCH_LIB("libanogs.so","0x549B50","00 00 80 D2 C0 03 5F D6");//549B50
PATCH_LIB("libanogs.so","0x549B70","00 00 80 D2 C0 03 5F D6");//549B70
PATCH_LIB("libanogs.so","0x549D50","00 00 80 D2 C0 03 5F D6");//549D50
PATCH_LIB("libanogs.so","0x549DC0","00 00 80 D2 C0 03 5F D6");//549DC0
PATCH_LIB("libanogs.so","0x549E38","00 00 80 D2 C0 03 5F D6");//549E38
PATCH_LIB("libanogs.so","0x549E70","00 00 80 D2 C0 03 5F D6");//549E70
PATCH_LIB("libanogs.so","0x54A1E8","00 00 80 D2 C0 03 5F D6");//54A1E8
PATCH_LIB("libanogs.so","0x54A5F8","00 00 80 D2 C0 03 5F D6");//54A5F8
PATCH_LIB("libanogs.so","0x54A618","00 00 80 D2 C0 03 5F D6");//54A618
PATCH_LIB("libanogs.so","0x54A638","00 00 80 D2 C0 03 5F D6");//54A638
PATCH_LIB("libanogs.so","0x54A778","00 00 80 D2 C0 03 5F D6");//54A778
PATCH_LIB("libanogs.so","0x54AB20","00 00 80 D2 C0 03 5F D6");//54AB20
PATCH_LIB("libanogs.so","0x54AC78","00 00 80 D2 C0 03 5F D6");//54AC78
PATCH_LIB("libanogs.so","0x54AD18","00 00 80 D2 C0 03 5F D6");//54AD18
PATCH_LIB("libanogs.so","0x54ADC0","00 00 80 D2 C0 03 5F D6");//54ADC0
PATCH_LIB("libanogs.so","0x54ADE0","00 00 80 D2 C0 03 5F D6");//54ADE0
PATCH_LIB("libanogs.so","0x54AED0","00 00 80 D2 C0 03 5F D6");//54AED0
PATCH_LIB("libanogs.so","0x54AEF0","00 00 80 D2 C0 03 5F D6");//54AEF0
PATCH_LIB("libanogs.so","0x54AF58","00 00 80 D2 C0 03 5F D6");//54AF58
PATCH_LIB("libanogs.so","0x54B070","00 00 80 D2 C0 03 5F D6");//54B070
PATCH_LIB("libanogs.so","0x54B160","00 00 80 D2 C0 03 5F D6");//54B160
PATCH_LIB("libanogs.so","0x54B2F8","00 00 80 D2 C0 03 5F D6");//54B2F8
PATCH_LIB("libanogs.so","0x54B3A0","00 00 80 D2 C0 03 5F D6");//54B3A0
PATCH_LIB("libanogs.so","0x54B3F0","00 00 80 D2 C0 03 5F D6");//54B3F0
PATCH_LIB("libanogs.so","0x54B548","00 00 80 D2 C0 03 5F D6");//54B548
PATCH_LIB("libanogs.so","0x54B590","00 00 80 D2 C0 03 5F D6");//54B590
PATCH_LIB("libanogs.so","0x54B5B0","00 00 80 D2 C0 03 5F D6");//54B5B0
PATCH_LIB("libanogs.so","0x54B698","00 00 80 D2 C0 03 5F D6");//54B698
PATCH_LIB("libanogs.so","0x54B6B8","00 00 80 D2 C0 03 5F D6");//54B6B8
PATCH_LIB("libanogs.so","0x54B6F0","00 00 80 D2 C0 03 5F D6");//54B6F0
PATCH_LIB("libanogs.so","0x54B710","00 00 80 D2 C0 03 5F D6");//54B710
PATCH_LIB("libanogs.so","0x54B730","00 00 80 D2 C0 03 5F D6");//54B730
PATCH_LIB("libanogs.so","0x54B750","00 00 80 D2 C0 03 5F D6");//54B750
PATCH_LIB("libanogs.so","0x54BA68","00 00 80 D2 C0 03 5F D6");//54BA68
PATCH_LIB("libanogs.so","0x54BAD0","00 00 80 D2 C0 03 5F D6");//54BAD0
PATCH_LIB("libanogs.so","0x54BB38","00 00 80 D2 C0 03 5F D6");//54BB38
PATCH_LIB("libanogs.so","0x54BBA0","00 00 80 D2 C0 03 5F D6");//54BBA0
PATCH_LIB("libanogs.so","0x54BC08","00 00 80 D2 C0 03 5F D6");//54BC08
PATCH_LIB("libanogs.so","0x54BC70","00 00 80 D2 C0 03 5F D6");//54BC70
PATCH_LIB("libanogs.so","0x54BCD8","00 00 80 D2 C0 03 5F D6");//54BCD8
PATCH_LIB("libanogs.so","0x54BD40","00 00 80 D2 C0 03 5F D6");//54BD40
PATCH_LIB("libanogs.so","0x54BDA8","00 00 80 D2 C0 03 5F D6");//54BDA8
PATCH_LIB("libanogs.so","0x54BE10","00 00 80 D2 C0 03 5F D6");//54BE10
PATCH_LIB("libanogs.so","0x54BE78","00 00 80 D2 C0 03 5F D6");//54BE78
PATCH_LIB("libanogs.so","0x54C338","00 00 80 D2 C0 03 5F D6");//54C338
PATCH_LIB("libanogs.so","0x54C448","00 00 80 D2 C0 03 5F D6");//54C448
PATCH_LIB("libanogs.so","0x54C4B8","00 00 80 D2 C0 03 5F D6");//54C4B8
PATCH_LIB("libanogs.so","0x54C4D8","00 00 80 D2 C0 03 5F D6");//54C4D8
PATCH_LIB("libanogs.so","0x54C4F8","00 00 80 D2 C0 03 5F D6");//54C4F8
PATCH_LIB("libanogs.so","0x54C518","00 00 80 D2 C0 03 5F D6");//54C518
PATCH_LIB("libanogs.so","0x54C618","00 00 80 D2 C0 03 5F D6");//54C618
PATCH_LIB("libanogs.so","0x54C690","00 00 80 D2 C0 03 5F D6");//54C690
PATCH_LIB("libanogs.so","0x54C7C8","00 00 80 D2 C0 03 5F D6");//54C7C8
PATCH_LIB("libanogs.so","0x54C7E8","00 00 80 D2 C0 03 5F D6");//54C7E8
PATCH_LIB("libanogs.so","0x54C898","00 00 80 D2 C0 03 5F D6");//54C898
PATCH_LIB("libanogs.so","0x54C960","00 00 80 D2 C0 03 5F D6");//54C960
PATCH_LIB("libanogs.so","0x54CA08","00 00 80 D2 C0 03 5F D6");//54CA08
PATCH_LIB("libanogs.so","0x54CD20","00 00 80 D2 C0 03 5F D6");//54CD20
PATCH_LIB("libanogs.so","0x54CED0","00 00 80 D2 C0 03 5F D6");//54CED0
PATCH_LIB("libanogs.so","0x54CF10","00 00 80 D2 C0 03 5F D6");//54CF10
PATCH_LIB("libanogs.so","0x54CF30","00 00 80 D2 C0 03 5F D6");//54CF30
PATCH_LIB("libanogs.so","0x54D1E8","00 00 80 D2 C0 03 5F D6");//54D1E8
PATCH_LIB("libanogs.so","0x54D7F0","00 00 80 D2 C0 03 5F D6");//54D7F0
PATCH_LIB("libanogs.so","0x54D8E8","00 00 80 D2 C0 03 5F D6");//54D8E8
PATCH_LIB("libanogs.so","0x54D908","00 00 80 D2 C0 03 5F D6");//54D908
PATCH_LIB("libanogs.so","0x54D928","00 00 80 D2 C0 03 5F D6");//54D928
PATCH_LIB("libanogs.so","0x54DA60","00 00 80 D2 C0 03 5F D6");//54DA60
PATCH_LIB("libanogs.so","0x54DAE8","00 00 80 D2 C0 03 5F D6");//54DAE8
PATCH_LIB("libanogs.so","0x54DB70","00 00 80 D2 C0 03 5F D6");//54DB70
PATCH_LIB("libanogs.so","0x54DC00","00 00 80 D2 C0 03 5F D6");//54DC00
PATCH_LIB("libanogs.so","0x54DC78","00 00 80 D2 C0 03 5F D6");//54DC78
PATCH_LIB("libanogs.so","0x54DD78","00 00 80 D2 C0 03 5F D6");//54DD78
PATCH_LIB("libanogs.so","0x54DDB8","00 00 80 D2 C0 03 5F D6");//54DDB8
PATCH_LIB("libanogs.so","0x54DE00","00 00 80 D2 C0 03 5F D6");//54DE00
PATCH_LIB("libanogs.so","0x54DE20","00 00 80 D2 C0 03 5F D6");//54DE20
PATCH_LIB("libanogs.so","0x54E330","00 00 80 D2 C0 03 5F D6");//54E330
PATCH_LIB("libanogs.so","0x54E350","00 00 80 D2 C0 03 5F D6");//54E350
PATCH_LIB("libanogs.so","0x54E7C0","00 00 80 D2 C0 03 5F D6");//54E7C0
PATCH_LIB("libanogs.so","0x54E878","00 00 80 D2 C0 03 5F D6");//54E878
PATCH_LIB("libanogs.so","0x54E918","00 00 80 D2 C0 03 5F D6");//54E918
PATCH_LIB("libanogs.so","0x54E998","00 00 80 D2 C0 03 5F D6");//54E998
PATCH_LIB("libanogs.so","0x54EA18","00 00 80 D2 C0 03 5F D6");//54EA18
PATCH_LIB("libanogs.so","0x54EA90","00 00 80 D2 C0 03 5F D6");//54EA90
PATCH_LIB("libanogs.so","0x54EB08","00 00 80 D2 C0 03 5F D6");//54EB08
PATCH_LIB("libanogs.so","0x54EB78","00 00 80 D2 C0 03 5F D6");//54EB78
PATCH_LIB("libanogs.so","0x54EBF0","00 00 80 D2 C0 03 5F D6");//54EBF0
PATCH_LIB("libanogs.so","0x54EC80","00 00 80 D2 C0 03 5F D6");//54EC80
PATCH_LIB("libanogs.so","0x54ECC8","00 00 80 D2 C0 03 5F D6");//54ECC8
PATCH_LIB("libanogs.so","0x54ED08","00 00 80 D2 C0 03 5F D6");//54ED08
PATCH_LIB("libanogs.so","0x54ED80","00 00 80 D2 C0 03 5F D6");//54ED80
PATCH_LIB("libanogs.so","0x54EDF8","00 00 80 D2 C0 03 5F D6");//54EDF8
PATCH_LIB("libanogs.so","0x54EE68","00 00 80 D2 C0 03 5F D6");//54EE68
PATCH_LIB("libanogs.so","0x54EEE8","00 00 80 D2 C0 03 5F D6");//54EEE8
PATCH_LIB("libanogs.so","0x54EFE0","00 00 80 D2 C0 03 5F D6");//54EFE0
PATCH_LIB("libanogs.so","0x54F078","00 00 80 D2 C0 03 5F D6");//54F078
PATCH_LIB("libanogs.so","0x54F100","00 00 80 D2 C0 03 5F D6");//54F100
PATCH_LIB("libanogs.so","0x54F190","00 00 80 D2 C0 03 5F D6");//54F190
PATCH_LIB("libanogs.so","0x54F218","00 00 80 D2 C0 03 5F D6");//54F218
PATCH_LIB("libanogs.so","0x54F298","00 00 80 D2 C0 03 5F D6");//54F298
PATCH_LIB("libanogs.so","0x54F2D8","00 00 80 D2 C0 03 5F D6");//54F2D8
PATCH_LIB("libanogs.so","0x54F318","00 00 80 D2 C0 03 5F D6");//54F318
PATCH_LIB("libanogs.so","0x54F358","00 00 80 D2 C0 03 5F D6");//54F358
PATCH_LIB("libanogs.so","0x54F3A0","00 00 80 D2 C0 03 5F D6");//54F3A0
PATCH_LIB("libanogs.so","0x54F3E0","00 00 80 D2 C0 03 5F D6");//54F3E0
PATCH_LIB("libanogs.so","0x54F428","00 00 80 D2 C0 03 5F D6");//54F428
PATCH_LIB("libanogs.so","0x54F468","00 00 80 D2 C0 03 5F D6");//54F468
PATCH_LIB("libanogs.so","0x54F4B0","00 00 80 D2 C0 03 5F D6");//54F4B0
PATCH_LIB("libanogs.so","0x54F530","00 00 80 D2 C0 03 5F D6");//54F530
PATCH_LIB("libanogs.so","0x54F5C8","00 00 80 D2 C0 03 5F D6");//54F5C8
PATCH_LIB("libanogs.so","0x54F648","00 00 80 D2 C0 03 5F D6");//54F648
PATCH_LIB("libanogs.so","0x54F6E0","00 00 80 D2 C0 03 5F D6");//54F6E0
PATCH_LIB("libanogs.so","0x54F778","00 00 80 D2 C0 03 5F D6");//54F778
PATCH_LIB("libanogs.so","0x54F7B8","00 00 80 D2 C0 03 5F D6");//54F7B8
PATCH_LIB("libanogs.so","0x54F7F8","00 00 80 D2 C0 03 5F D6");//54F7F8
PATCH_LIB("libanogs.so","0x54F8E8","00 00 80 D2 C0 03 5F D6");//54F8E8
PATCH_LIB("libanogs.so","0x54F980","00 00 80 D2 C0 03 5F D6");//54F980
PATCH_LIB("libanogs.so","0x54F9C0","00 00 80 D2 C0 03 5F D6");//54F9C0
PATCH_LIB("libanogs.so","0x54FA08","00 00 80 D2 C0 03 5F D6");//54FA08
PATCH_LIB("libanogs.so","0x54FA90","00 00 80 D2 C0 03 5F D6");//54FA90
PATCH_LIB("libanogs.so","0x54FB10","00 00 80 D2 C0 03 5F D6");//54FB10
PATCH_LIB("libanogs.so","0x54FB98","00 00 80 D2 C0 03 5F D6");//54FB98
PATCH_LIB("libanogs.so","0x54FC18","00 00 80 D2 C0 03 5F D6");//54FC18
PATCH_LIB("libanogs.so","0x54FCA8","00 00 80 D2 C0 03 5F D6");//54FCA8
PATCH_LIB("libanogs.so","0x54FDA8","00 00 80 D2 C0 03 5F D6");//54FDA8
PATCH_LIB("libanogs.so","0x54FE28","00 00 80 D2 C0 03 5F D6");//54FE28
PATCH_LIB("libanogs.so","0x54FEA8","00 00 80 D2 C0 03 5F D6");//54FEA8
PATCH_LIB("libanogs.so","0x54FF30","00 00 80 D2 C0 03 5F D6");//54FF30
PATCH_LIB("libanogs.so","0x54FFB0","00 00 80 D2 C0 03 5F D6");//54FFB0
PATCH_LIB("libanogs.so","0x550038","00 00 80 D2 C0 03 5F D6");//550038
PATCH_LIB("libanogs.so","0x5500C0","00 00 80 D2 C0 03 5F D6");//5500C0
PATCH_LIB("libanogs.so","0x550140","00 00 80 D2 C0 03 5F D6");//550140
PATCH_LIB("libanogs.so","0x5501C8","00 00 80 D2 C0 03 5F D6");//5501C8
PATCH_LIB("libanogs.so","0x5502C8","00 00 80 D2 C0 03 5F D6");//5502C8
PATCH_LIB("libanogs.so","0x550350","00 00 80 D2 C0 03 5F D6");//550350
PATCH_LIB("libanogs.so","0x5503D8","00 00 80 D2 C0 03 5F D6");//5503D8
PATCH_LIB("libanogs.so","0x550478","00 00 80 D2 C0 03 5F D6");//550478
PATCH_LIB("libanogs.so","0x5504F0","00 00 80 D2 C0 03 5F D6");//5504F0
PATCH_LIB("libanogs.so","0x550568","00 00 80 D2 C0 03 5F D6");//550568
PATCH_LIB("libanogs.so","0x5505F8","00 00 80 D2 C0 03 5F D6");//5505F8
PATCH_LIB("libanogs.so","0x550680","00 00 80 D2 C0 03 5F D6");//550680
PATCH_LIB("libanogs.so","0x550700","00 00 80 D2 C0 03 5F D6");//550700
PATCH_LIB("libanogs.so","0x550788","00 00 80 D2 C0 03 5F D6");//550788
PATCH_LIB("libanogs.so","0x5510C8","00 00 80 D2 C0 03 5F D6");//5510C8
PATCH_LIB("libanogs.so","0x5511C8","00 00 80 D2 C0 03 5F D6");//5511C8
PATCH_LIB("libanogs.so","0x551238","00 00 80 D2 C0 03 5F D6");//551238
PATCH_LIB("libanogs.so","0x5512B0","00 00 80 D2 C0 03 5F D6");//5512B0
PATCH_LIB("libanogs.so","0x551328","00 00 80 D2 C0 03 5F D6");//551328
PATCH_LIB("libanogs.so","0x5513A0","00 00 80 D2 C0 03 5F D6");//5513A0
PATCH_LIB("libanogs.so","0x551498","00 00 80 D2 C0 03 5F D6");//551498
PATCH_LIB("libanogs.so","0x5515B8","00 00 80 D2 C0 03 5F D6");//5515B8
PATCH_LIB("libanogs.so","0x551658","00 00 80 D2 C0 03 5F D6");//551658
PATCH_LIB("libanogs.so","0x551698","00 00 80 D2 C0 03 5F D6");//551698
PATCH_LIB("libanogs.so","0x5516D8","00 00 80 D2 C0 03 5F D6");//5516D8
PATCH_LIB("libanogs.so","0x551718","00 00 80 D2 C0 03 5F D6");//551718
PATCH_LIB("libanogs.so","0x551758","00 00 80 D2 C0 03 5F D6");//551758
PATCH_LIB("libanogs.so","0x5517D8","00 00 80 D2 C0 03 5F D6");//5517D8
PATCH_LIB("libanogs.so","0x551858","00 00 80 D2 C0 03 5F D6");//551858
PATCH_LIB("libanogs.so","0x551A90","00 00 80 D2 C0 03 5F D6");//551A90
PATCH_LIB("libanogs.so","0x551B18","00 00 80 D2 C0 03 5F D6");//551B18
PATCH_LIB("libanogs.so","0x551BA0","00 00 80 D2 C0 03 5F D6");//551BA0
PATCH_LIB("libanogs.so","0x551CA8","00 00 80 D2 C0 03 5F D6");//551CA8
PATCH_LIB("libanogs.so","0x551D28","00 00 80 D2 C0 03 5F D6");//551D28
PATCH_LIB("libanogs.so","0x551DA8","00 00 80 D2 C0 03 5F D6");//551DA8
PATCH_LIB("libanogs.so","0x551E28","00 00 80 D2 C0 03 5F D6");//551E28
PATCH_LIB("libanogs.so","0x551F48","00 00 80 D2 C0 03 5F D6");//551F48
PATCH_LIB("libanogs.so","0x552008","00 00 80 D2 C0 03 5F D6");//552008
PATCH_LIB("libanogs.so","0x552088","00 00 80 D2 C0 03 5F D6");//552088
PATCH_LIB("libanogs.so","0x5520A8","00 00 80 D2 C0 03 5F D6");//5520A8
PATCH_LIB("libanogs.so","0x552130","00 00 80 D2 C0 03 5F D6");//552130
PATCH_LIB("libanogs.so","0x5521B0","00 00 80 D2 C0 03 5F D6");//5521B0
PATCH_LIB("libanogs.so","0x552360","00 00 80 D2 C0 03 5F D6");//552360
PATCH_LIB("libanogs.so","0x552380","00 00 80 D2 C0 03 5F D6");//552380
PATCH_LIB("libanogs.so","0x5523A0","00 00 80 D2 C0 03 5F D6");//5523A0
PATCH_LIB("libanogs.so","0x552410","00 00 80 D2 C0 03 5F D6");//552410
PATCH_LIB("libanogs.so","0x5524B8","00 00 80 D2 C0 03 5F D6");//5524B8
PATCH_LIB("libanogs.so","0x552A20","00 00 80 D2 C0 03 5F D6");//552A20
PATCH_LIB("libanogs.so","0x552A40","00 00 80 D2 C0 03 5F D6");//552A40
PATCH_LIB("libanogs.so","0x552AC0","00 00 80 D2 C0 03 5F D6");//552AC0
PATCH_LIB("libanogs.so","0x552BB0","00 00 80 D2 C0 03 5F D6");//552BB0
PATCH_LIB("libanogs.so","0x552C38","00 00 80 D2 C0 03 5F D6");//552C38
PATCH_LIB("libanogs.so","0x552DD0","00 00 80 D2 C0 03 5F D6");//552DD0
PATCH_LIB("libanogs.so","0x552DF0","00 00 80 D2 C0 03 5F D6");//552DF0
PATCH_LIB("libanogs.so","0x552EC8","00 00 80 D2 C0 03 5F D6");//552EC8
PATCH_LIB("libanogs.so","0x552EE8","00 00 80 D2 C0 03 5F D6");//552EE8
PATCH_LIB("libanogs.so","0x553008","00 00 80 D2 C0 03 5F D6");//553008
PATCH_LIB("libanogs.so","0x553028","00 00 80 D2 C0 03 5F D6");//553028
PATCH_LIB("libanogs.so","0x553048","00 00 80 D2 C0 03 5F D6");//553048
PATCH_LIB("libanogs.so","0x553090","00 00 80 D2 C0 03 5F D6");//553090
PATCH_LIB("libanogs.so","0x553528","00 00 80 D2 C0 03 5F D6");//553528
PATCH_LIB("libanogs.so","0x553548","00 00 80 D2 C0 03 5F D6");//553548
PATCH_LIB("libanogs.so","0x5535C8","00 00 80 D2 C0 03 5F D6");//5535C8
PATCH_LIB("libanogs.so","0x553760","00 00 80 D2 C0 03 5F D6");//553760
PATCH_LIB("libanogs.so","0x5537C8","00 00 80 D2 C0 03 5F D6");//5537C8
PATCH_LIB("libanogs.so","0x553828","00 00 80 D2 C0 03 5F D6");//553828
PATCH_LIB("libanogs.so","0x5538A8","00 00 80 D2 C0 03 5F D6");//5538A8
PATCH_LIB("libanogs.so","0x5538C8","00 00 80 D2 C0 03 5F D6");//5538C8
PATCH_LIB("libanogs.so","0x553D48","00 00 80 D2 C0 03 5F D6");//553D48
PATCH_LIB("libanogs.so","0x553D70","00 00 80 D2 C0 03 5F D6");//553D70
PATCH_LIB("libanogs.so","0x553DA8","00 00 80 D2 C0 03 5F D6");//553DA8
PATCH_LIB("libanogs.so","0x553E50","00 00 80 D2 C0 03 5F D6");//553E50
PATCH_LIB("libanogs.so","0x553ED0","00 00 80 D2 C0 03 5F D6");//553ED0
PATCH_LIB("libanogs.so","0x553EF0","00 00 80 D2 C0 03 5F D6");//553EF0
PATCH_LIB("libanogs.so","0x553F10","00 00 80 D2 C0 03 5F D6");//553F10
PATCH_LIB("libanogs.so","0x554008","00 00 80 D2 C0 03 5F D6");//554008
PATCH_LIB("libanogs.so","0x554028","00 00 80 D2 C0 03 5F D6");//554028
PATCH_LIB("libanogs.so","0x554080","00 00 80 D2 C0 03 5F D6");//554080
PATCH_LIB("libanogs.so","0x554128","00 00 80 D2 C0 03 5F D6");//554128
PATCH_LIB("libanogs.so","0x5541A8","00 00 80 D2 C0 03 5F D6");//5541A8
PATCH_LIB("libanogs.so","0x5541C8","00 00 80 D2 C0 03 5F D6");//5541C8
PATCH_LIB("libanogs.so","0x5541E8","00 00 80 D2 C0 03 5F D6");//5541E8
PATCH_LIB("libanogs.so","0x5542E0","00 00 80 D2 C0 03 5F D6");//5542E0
PATCH_LIB("libanogs.so","0x554300","00 00 80 D2 C0 03 5F D6");//554300
PATCH_LIB("libanogs.so","0x554358","00 00 80 D2 C0 03 5F D6");//554358
PATCH_LIB("libanogs.so","0x554378","00 00 80 D2 C0 03 5F D6");//554378
PATCH_LIB("libanogs.so","0x554398","00 00 80 D2 C0 03 5F D6");//554398
PATCH_LIB("libanogs.so","0x5543D0","00 00 80 D2 C0 03 5F D6");//5543D0
PATCH_LIB("libanogs.so","0x554478","00 00 80 D2 C0 03 5F D6");//554478
PATCH_LIB("libanogs.so","0x554498","00 00 80 D2 C0 03 5F D6");//554498
PATCH_LIB("libanogs.so","0x5544B8","00 00 80 D2 C0 03 5F D6");//5544B8
PATCH_LIB("libanogs.so","0x5544F0","00 00 80 D2 C0 03 5F D6");//5544F0
PATCH_LIB("libanogs.so","0x5546E0","00 00 80 D2 C0 03 5F D6");//5546E0
PATCH_LIB("libanogs.so","0x554768","00 00 80 D2 C0 03 5F D6");//554768
PATCH_LIB("libanogs.so","0x5547F0","00 00 80 D2 C0 03 5F D6");//5547F0
PATCH_LIB("libanogs.so","0x5549F0","00 00 80 D2 C0 03 5F D6");//5549F0
PATCH_LIB("libanogs.so","0x554A10","00 00 80 D2 C0 03 5F D6");//554A10
PATCH_LIB("libanogs.so","0x554A30","00 00 80 D2 C0 03 5F D6");//554A30
PATCH_LIB("libanogs.so","0x554B30","00 00 80 D2 C0 03 5F D6");//554B30
PATCH_LIB("libanogs.so","0x554B70","00 00 80 D2 C0 03 5F D6");//554B70
PATCH_LIB("libanogs.so","0x554C00","00 00 80 D2 C0 03 5F D6");//554C00
PATCH_LIB("libanogs.so","0x554C50","00 00 80 D2 C0 03 5F D6");//554C50
PATCH_LIB("libanogs.so","0x554EF0","00 00 80 D2 C0 03 5F D6");//554EF0
PATCH_LIB("libanogs.so","0x554FB0","00 00 80 D2 C0 03 5F D6");//554FB0
PATCH_LIB("libanogs.so","0x555078","00 00 80 D2 C0 03 5F D6");//555078
PATCH_LIB("libanogs.so","0x5550E0","00 00 80 D2 C0 03 5F D6");//5550E0
PATCH_LIB("libanogs.so","0x555178","00 00 80 D2 C0 03 5F D6");//555178
PATCH_LIB("libanogs.so","0x555280","00 00 80 D2 C0 03 5F D6");//555280
PATCH_LIB("libanogs.so","0x555378","00 00 80 D2 C0 03 5F D6");//555378
PATCH_LIB("libanogs.so","0x5553C0","00 00 80 D2 C0 03 5F D6");//5553C0
PATCH_LIB("libanogs.so","0x555420","00 00 80 D2 C0 03 5F D6");//555420
PATCH_LIB("libanogs.so","0x5554C8","00 00 80 D2 C0 03 5F D6");//5554C8
PATCH_LIB("libanogs.so","0x555530","00 00 80 D2 C0 03 5F D6");//555530
PATCH_LIB("libanogs.so","0x555550","00 00 80 D2 C0 03 5F D6");//555550
PATCH_LIB("libanogs.so","0x555570","00 00 80 D2 C0 03 5F D6");//555570
PATCH_LIB("libanogs.so","0x555758","00 00 80 D2 C0 03 5F D6");//555758
PATCH_LIB("libanogs.so","0x555860","00 00 80 D2 C0 03 5F D6");//555860
PATCH_LIB("libanogs.so","0x555B58","00 00 80 D2 C0 03 5F D6");//555B58
PATCH_LIB("libanogs.so","0x555BC8","00 00 80 D2 C0 03 5F D6");//555BC8
PATCH_LIB("libanogs.so","0x555C28","00 00 80 D2 C0 03 5F D6");//555C28
PATCH_LIB("libanogs.so","0x555C98","00 00 80 D2 C0 03 5F D6");//555C98
PATCH_LIB("libanogs.so","0x555CB8","00 00 80 D2 C0 03 5F D6");//555CB8
PATCH_LIB("libanogs.so","0x555D48","00 00 80 D2 C0 03 5F D6");//555D48
PATCH_LIB("libanogs.so","0x555E98","00 00 80 D2 C0 03 5F D6");//555E98
PATCH_LIB("libanogs.so","0x555EB8","00 00 80 D2 C0 03 5F D6");//555EB8
PATCH_LIB("libanogs.so","0x555ED8","00 00 80 D2 C0 03 5F D6");//555ED8
PATCH_LIB("libanogs.so","0x555F28","00 00 80 D2 C0 03 5F D6");//555F28
PATCH_LIB("libanogs.so","0x5561F0","00 00 80 D2 C0 03 5F D6");//5561F0
PATCH_LIB("libanogs.so","0x556210","00 00 80 D2 C0 03 5F D6");//556210
PATCH_LIB("libanogs.so","0x556270","00 00 80 D2 C0 03 5F D6");//556270
PATCH_LIB("libanogs.so","0x5565B8","00 00 80 D2 C0 03 5F D6");//5565B8
PATCH_LIB("libanogs.so","0x5565F0","00 00 80 D2 C0 03 5F D6");//5565F0
PATCH_LIB("libanogs.so","0x556640","00 00 80 D2 C0 03 5F D6");//556640
PATCH_LIB("libanogs.so","0x5567E8","00 00 80 D2 C0 03 5F D6");//5567E8
PATCH_LIB("libanogs.so","0x556950","00 00 80 D2 C0 03 5F D6");//556950
PATCH_LIB("libanogs.so","0x556970","00 00 80 D2 C0 03 5F D6");//556970
PATCH_LIB("libanogs.so","0x556A38","00 00 80 D2 C0 03 5F D6");//556A38
PATCH_LIB("libanogs.so","0x556A58","00 00 80 D2 C0 03 5F D6");//556A58
PATCH_LIB("libanogs.so","0x556AD0","00 00 80 D2 C0 03 5F D6");//556AD0
PATCH_LIB("libanogs.so","0x556C70","00 00 80 D2 C0 03 5F D6");//556C70
PATCH_LIB("libanogs.so","0x556C90","00 00 80 D2 C0 03 5F D6");//556C90
PATCH_LIB("libanogs.so","0x556CD0","00 00 80 D2 C0 03 5F D6");//556CD0
PATCH_LIB("libanogs.so","0x556CF0","00 00 80 D2 C0 03 5F D6");//556CF0
PATCH_LIB("libanogs.so","0x556D10","00 00 80 D2 C0 03 5F D6");//556D10
PATCH_LIB("libanogs.so","0x557180","00 00 80 D2 C0 03 5F D6");//557180
PATCH_LIB("libanogs.so","0x5571A0","00 00 80 D2 C0 03 5F D6");//5571A0
PATCH_LIB("libanogs.so","0x5573A0","00 00 80 D2 C0 03 5F D6");//5573A0
PATCH_LIB("libanogs.so","0x557488","00 00 80 D2 C0 03 5F D6");//557488
PATCH_LIB("libanogs.so","0x557680","00 00 80 D2 C0 03 5F D6");//557680
PATCH_LIB("libanogs.so","0x557900","00 00 80 D2 C0 03 5F D6");//557900
PATCH_LIB("libanogs.so","0x557A40","00 00 80 D2 C0 03 5F D6");//557A40
PATCH_LIB("libanogs.so","0x557B40","00 00 80 D2 C0 03 5F D6");//557B40
PATCH_LIB("libanogs.so","0x557B60","00 00 80 D2 C0 03 5F D6");//557B60
PATCH_LIB("libanogs.so","0x557BD0","00 00 80 D2 C0 03 5F D6");//557BD0
PATCH_LIB("libanogs.so","0x557D80","00 00 80 D2 C0 03 5F D6");//557D80
PATCH_LIB("libanogs.so","0x557DA0","00 00 80 D2 C0 03 5F D6");//557DA0
PATCH_LIB("libanogs.so","0x558110","00 00 80 D2 C0 03 5F D6");//558110
PATCH_LIB("libanogs.so","0x558398","00 00 80 D2 C0 03 5F D6");//558398
PATCH_LIB("libanogs.so","0x5583B8","00 00 80 D2 C0 03 5F D6");//5583B8
PATCH_LIB("libanogs.so","0x5583F8","00 00 80 D2 C0 03 5F D6");//5583F8
PATCH_LIB("libanogs.so","0x558540","00 00 80 D2 C0 03 5F D6");//558540
PATCH_LIB("libanogs.so","0x558560","00 00 80 D2 C0 03 5F D6");//558560
PATCH_LIB("libanogs.so","0x5586A0","00 00 80 D2 C0 03 5F D6");//5586A0
PATCH_LIB("libanogs.so","0x5586F0","00 00 80 D2 C0 03 5F D6");//5586F0
PATCH_LIB("libanogs.so","0x558738","00 00 80 D2 C0 03 5F D6");//558738
PATCH_LIB("libanogs.so","0x558A18","00 00 80 D2 C0 03 5F D6");//558A18
PATCH_LIB("libanogs.so","0x558C08","00 00 80 D2 C0 03 5F D6");//558C08
PATCH_LIB("libanogs.so","0x558D30","00 00 80 D2 C0 03 5F D6");//558D30
PATCH_LIB("libanogs.so","0x559138","00 00 80 D2 C0 03 5F D6");//559138
PATCH_LIB("libanogs.so","0x559278","00 00 80 D2 C0 03 5F D6");//559278
PATCH_LIB("libanogs.so","0x559298","00 00 80 D2 C0 03 5F D6");//559298
PATCH_LIB("libanogs.so","0x559350","00 00 80 D2 C0 03 5F D6");//559350
PATCH_LIB("libanogs.so","0x559370","00 00 80 D2 C0 03 5F D6");//559370
PATCH_LIB("libanogs.so","0x5593B0","00 00 80 D2 C0 03 5F D6");//5593B0
PATCH_LIB("libanogs.so","0x5593D0","00 00 80 D2 C0 03 5F D6");//5593D0
PATCH_LIB("libanogs.so","0x559488","00 00 80 D2 C0 03 5F D6");//559488
PATCH_LIB("libanogs.so","0x5597B8","00 00 80 D2 C0 03 5F D6");//5597B8
PATCH_LIB("libanogs.so","0x559EC8","00 00 80 D2 C0 03 5F D6");//559EC8
PATCH_LIB("libanogs.so","0x55A110","00 00 80 D2 C0 03 5F D6");//55A110
PATCH_LIB("libanogs.so","0x55B3C0","00 00 80 D2 C0 03 5F D6");//55B3C0
PATCH_LIB("libanogs.so","0x55B8B8","00 00 80 D2 C0 03 5F D6");//55B8B8
PATCH_LIB("libanogs.so","0x55BA10","00 00 80 D2 C0 03 5F D6");//55BA10
PATCH_LIB("libanogs.so","0x55BB78","00 00 80 D2 C0 03 5F D6");//55BB78
PATCH_LIB("libanogs.so","0x55C3B8","00 00 80 D2 C0 03 5F D6");//55C3B8
PATCH_LIB("libanogs.so","0x55C438","00 00 80 D2 C0 03 5F D6");//55C438
PATCH_LIB("libanogs.so","0x55C4B0","00 00 80 D2 C0 03 5F D6");//55C4B0
PATCH_LIB("libanogs.so","0x55C648","00 00 80 D2 C0 03 5F D6");//55C648
PATCH_LIB("libanogs.so","0x55C758","00 00 80 D2 C0 03 5F D6");//55C758
PATCH_LIB("libanogs.so","0x55C790","00 00 80 D2 C0 03 5F D6");//55C790
PATCH_LIB("libanogs.so","0x55C7B0","00 00 80 D2 C0 03 5F D6");//55C7B0
PATCH_LIB("libanogs.so","0x55C7D0","00 00 80 D2 C0 03 5F D6");//55C7D0
PATCH_LIB("libanogs.so","0x55CA18","00 00 80 D2 C0 03 5F D6");//55CA18
PATCH_LIB("libanogs.so","0x55CA50","00 00 80 D2 C0 03 5F D6");//55CA50
PATCH_LIB("libanogs.so","0x55CBF0","00 00 80 D2 C0 03 5F D6");//55CBF0
PATCH_LIB("libanogs.so","0x55CCB8","00 00 80 D2 C0 03 5F D6");//55CCB8
PATCH_LIB("libanogs.so","0x55CD30","00 00 80 D2 C0 03 5F D6");//55CD30
PATCH_LIB("libanogs.so","0x55D010","00 00 80 D2 C0 03 5F D6");//55D010
PATCH_LIB("libanogs.so","0x55D260","00 00 80 D2 C0 03 5F D6");//55D260
PATCH_LIB("libanogs.so","0x55D280","00 00 80 D2 C0 03 5F D6");//55D280
PATCH_LIB("libanogs.so","0x55D2A0","00 00 80 D2 C0 03 5F D6");//55D2A0
PATCH_LIB("libanogs.so","0x55D2C0","00 00 80 D2 C0 03 5F D6");//55D2C0
PATCH_LIB("libanogs.so","0x55D2E0","00 00 80 D2 C0 03 5F D6");//55D2E0
PATCH_LIB("libanogs.so","0x55D300","00 00 80 D2 C0 03 5F D6");//55D300
PATCH_LIB("libanogs.so","0x55D320","00 00 80 D2 C0 03 5F D6");//55D320
PATCH_LIB("libanogs.so","0x55D340","00 00 80 D2 C0 03 5F D6");//55D340
PATCH_LIB("libanogs.so","0x55D360","00 00 80 D2 C0 03 5F D6");//55D360
PATCH_LIB("libanogs.so","0x55D380","00 00 80 D2 C0 03 5F D6");//55D380
PATCH_LIB("libanogs.so","0x55D518","00 00 80 D2 C0 03 5F D6");//55D518
PATCH_LIB("libanogs.so","0x55D7E0","00 00 80 D2 C0 03 5F D6");//55D7E0
PATCH_LIB("libanogs.so","0x55D800","00 00 80 D2 C0 03 5F D6");//55D800
PATCH_LIB("libanogs.so","0x55D838","00 00 80 D2 C0 03 5F D6");//55D838
PATCH_LIB("libanogs.so","0x55D858","00 00 80 D2 C0 03 5F D6");//55D858
PATCH_LIB("libanogs.so","0x55D890","00 00 80 D2 C0 03 5F D6");//55D890
PATCH_LIB("libanogs.so","0x55D8B0","00 00 80 D2 C0 03 5F D6");//55D8B0
PATCH_LIB("libanogs.so","0x55D8D0","00 00 80 D2 C0 03 5F D6");//55D8D0
PATCH_LIB("libanogs.so","0x55D8F0","00 00 80 D2 C0 03 5F D6");//55D8F0
PATCH_LIB("libanogs.so","0x55D910","00 00 80 D2 C0 03 5F D6");//55D910
PATCH_LIB("libanogs.so","0x55D930","00 00 80 D2 C0 03 5F D6");//55D930
PATCH_LIB("libanogs.so","0x55D950","00 00 80 D2 C0 03 5F D6");//55D950
PATCH_LIB("libanogs.so","0x55D9D0","00 00 80 D2 C0 03 5F D6");//55D9D0
PATCH_LIB("libanogs.so","0x55DA38","00 00 80 D2 C0 03 5F D6");//55DA38
PATCH_LIB("libanogs.so","0x55DD70","00 00 80 D2 C0 03 5F D6");//55DD70
PATCH_LIB("libanogs.so","0x55E878","00 00 80 D2 C0 03 5F D6");//55E878
PATCH_LIB("libanogs.so","0x55EA40","00 00 80 D2 C0 03 5F D6");//55EA40
PATCH_LIB("libanogs.so","0x55F338","00 00 80 D2 C0 03 5F D6");//55F338
PATCH_LIB("libanogs.so","0x55F360","00 00 80 D2 C0 03 5F D6");//55F360
PATCH_LIB("libanogs.so","0x55F388","00 00 80 D2 C0 03 5F D6");//55F388
PATCH_LIB("libanogs.so","0x55F3B0","00 00 80 D2 C0 03 5F D6");//55F3B0
PATCH_LIB("libanogs.so","0x55F3D8","00 00 80 D2 C0 03 5F D6");//55F3D8
PATCH_LIB("libanogs.so","0x55F400","00 00 80 D2 C0 03 5F D6");//55F400
PATCH_LIB("libanogs.so","0x4863AC","20 00 20 3D");
PATCH_LIB("libUE4.so","0x4F5B864","D2 80 00 00");
PATCH_LIB("libUE4.so","0x4F5B868","D6 5F 03 C0");
PATCH_LIB("libUE4.so","0x4F98CF4","D2 80 00 00");
PATCH_LIB("libUE4.so","0x4F98CF8","D6 5F 03 C0");
PATCH_LIB("libUE4.so","0x58F83B4","D5 03 20 1F");
PATCH_LIB("libUE4.so","0x58F9F6C","D5 03 20 1F");
PATCH_LIB("libUE4.so","0x3FE0120","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0128","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0254","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0264","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0284","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE03B4","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0504","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE050C","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE074C","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE08B4","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0A64","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0B8C","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0B94","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0BBC","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0F48","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE0F50","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1440","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1448","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE14C8","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE14D8","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE14E0","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1510","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1518","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1568","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1570","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1578","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE15B0","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE15D8","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE15E0","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE19A8","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE19D8","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE19E0","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE19E8","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE19F0","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE19F8","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1A00","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1A08","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1A10","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1A98","C0 03 5F D6");
PATCH_LIB("libUE4.so","0x3FE1AA0","C0 03 5F D6");