#include "PlatformUtil.h"

#include <f32file.h>
#include <BAUTILS.H>

static const TText* const KPlatformStringArray[] = 
	{
	_S("z:\\system\\install\\Series60v3.0.sis"),
	_S("z:\\system\\install\\Series60v3.1.sis"),
	_S("z:\\system\\install\\Series60v3.2.sis"),
	_S("z:\\system\\install\\Series60v5.0.sis"),
	_S("z:\\system\\install\\Series60v5.1.sis"),
	_S("z:\\system\\install\\Series60v5.2.sis"),
	};
	
const TInt KPlatformStringArrayLength = EPlatSeriesCount;

TDevicePlatform PlatformUtil::DevicePlatform(const RFs& aFs)
	{
	//default is the latest platform
	TDevicePlatform platform = (TDevicePlatform)(KPlatformStringArrayLength-1);
	for(TInt i=KPlatformStringArrayLength-1; i>=0; i--)
		{
		TPtrC platCheckStr(KPlatformStringArray[i]);		
		if(BaflUtils::FileExists(aFs, platCheckStr))
			{
			platform = (TDevicePlatform)i;
			break;
			}
		}
	return platform;
	}
