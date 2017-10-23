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
    "@dance",		// Plugin name
    SERVER_TYPE_MAP,// Which server types this plugin works with?
    "1.2",			// Plugin version
    HPM_VERSION,	// HPM Version (don't change, macro is automatically updated)
};



/*==========================================
 @dance X by Anarchist
 => Special effects with dance style
------------------------------------------
*/

ACMD(dance)
{

	if(!*message || atoi(message) < 1 || atoi(message) > 9)
	{
		clif->message(fd, "Usage: @dance 1-9");
		return -1;
	}
	
	switch(atoi(message)) 
	{
		case 1 :
			clif->specialeffect(&sd->bl,413,0);
			break;
		case 2 :
			clif->specialeffect(&sd->bl,414,0);
			break;
		case 3 :
			clif->specialeffect(&sd->bl,415,0);
			break;
		case 4 :
			clif->specialeffect(&sd->bl, 426,0);
			break;
		case 5 :
			clif->specialeffect(&sd->bl,458,0);
			break;
		case 6 :
			clif->specialeffect(&sd->bl,466,0);
			break;
		case 7 :
			clif->specialeffect(&sd->bl,501,0);
			break;
		case 8 :
			clif->specialeffect(&sd->bl,540,0);
			break;
		case 9 :
			clif->specialeffect(&sd->bl,550,0);
			break;
	}
	
	return 1;
}


/* Server Startup */
HPExport void plugin_init (void)
{
	addAtcommand("dance",dance);
}
