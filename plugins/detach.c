#include "common/hercules.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common/HPMi.h"
#include "common/timer.h"
#include "common/nullpo.h"
#include "map/channel.h"
#include "map/script.h"
#include "map/pc.h"
#include "map/clif.h"
#include "map/chat.h"
#include "map/battle.h"
#include "map/status.h"
#include "common/HPMDataCheck.h"

HPExport struct hplugin_info pinfo =
{
    "@detach",		// Plugin name
    SERVER_TYPE_MAP,// Which server types this plugin works with?
    "1.1",			// Plugin version
    HPM_VERSION,	// HPM Version (don't change, macro is automatically updated)
};


/*==========================================
* @detach
*==========================================*/
ACMD(detach) 
{
	
	if( pc_isdead(sd) ) {
        clif->message(fd, "Cannot use @detach if you are dead.");
        return true;
    }
	
	
	if( map->list[sd->bl.m].flag.autotrade == battle->bc->autotrade_mapflag )
    {
        if(map->list[sd->bl.m].flag.pvp || map->list[sd->bl.m].flag.gvg){
            clif->message(fd, "You may not use @detach when you are on maps PVP or GVG.");
			return true;
        }
		
		sd->state.monster_ignore = 0;
		sd->state.autotrade = 1;
		chat->create_pc_chat(sd, "DETACH", "", 1, true);
		sd->sc.opt1 = OPT1_STONE;
		pc->setoption(sd, sd->sc.option);
		pc_setsit(sd);
		skill->sit(sd,1);
		clif->sitting(&sd->bl);
		channel->quit(sd);
		clif->authfail_fd(sd->fd, 15);
		return true;

	} 
	else
	{
		clif->message(fd, "@detach is not allowed on this map.");
		return true;
	}
}


/* Server Startup */
HPExport void plugin_init (void)
{
	addAtcommand("detach",detach);
}
