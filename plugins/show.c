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
    "@show",		// Plugin name
    SERVER_TYPE_MAP,// Which server types this plugin works with?
    "1.2",			// Plugin version
    HPM_VERSION,	// HPM Version (don't change, macro is automatically updated)
};

/*==========================================
* @show by KarLaeda
* => Displays the point on minimap
*------------------------------------------*/
ACMD(show)
{
	int x = 0, y = 0;
	
	if(!*message || (sscanf(message, "%d %d", &x, &y) != 2))
	{
		clif->message(fd, "usage: @show <x> <y>");
		return -1;
	}
	
	clif->viewpoint(sd, 1, 1, x, y, 2, 0xFF0000);
	return 1;
}



/* Server Startup */
HPExport void plugin_init (void)
{
	addAtcommand("show",show);
}
