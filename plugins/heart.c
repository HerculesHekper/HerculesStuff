#include "common/hercules.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "common/HPMi.h"
#include "map/clif.h"
#include "map/atcommand.h"
#include "map/script.h"
#include "map/pc.h"
#include "common/nullpo.h"

#include "common/HPMDataCheck.h"

HPExport struct hplugin_info pinfo =
{
    "@heart",		// Plugin name
    SERVER_TYPE_MAP,// Which server types this plugin works with?
    "1.2",			// Plugin version
    HPM_VERSION,	// HPM Version (don't change, macro is automatically updated)
};

/*==========================================
 @heart X by Anarchist
 => Displays the heart special effect
------------------------------------------
*/

ACMD(heart)
{
	
	if(!*message || atoi(message) < 1 || atoi(message) > 2)
	{
		clif->message(fd, "usage: @heart 1 or 2");
		return -1;
	}
	
	if(atoi(message) == 1)
	{
		clif->specialeffect(&sd->bl,364,0);
	} 
	else if(atoi(message) == 2)
	{
		clif->specialeffect(&sd->bl,509,0);
	}
	
	return 1;
}


/* Server Startup */
HPExport void plugin_init (void)
{
	addAtcommand("heart",heart);
}
