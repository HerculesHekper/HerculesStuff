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
    "@emotion",		// Plugin name
    SERVER_TYPE_MAP,// Which server types this plugin works with?
    "1.2",			// Plugin version
    HPM_VERSION,	// HPM Version (don't change, macro is automatically updated)
};

/*==========================================
* @emotion X by Anarchist
* => Displays the emotions without delay
*------------------------------------------*/

int emotion_max = 81; // Set last available emotion number available for this command.
// Clients < 2013 support way less emotions.

ACMD(emotion)
{
	char err_msg[1024];
  	// Disabled emotions 34 = mute; [58 to 63] = dice particular sides
	int rEmoArray[] = {34, 58, 59, 60, 61, 62, 63};
	int rEmoArraySize = sizeof(rEmoArray) / sizeof(rEmoArray[0]);

	if(!*message || atoi(message) < 0 || atoi(message) > emotion_max)
	{
		sprintf(err_msg, "Usage: @emotion 0-%d", emotion_max);
		clif->message(fd, err_msg);
		return -1;
	}

	for (int i = 0; i < rEmoArraySize; i++)
	{
		if (rEmoArray[i] == atoi(message))
		{
			sprintf(err_msg, "This emotion is disabled.");
			clif->message(fd, err_msg);
			return -1;
		}
	}

	clif->emotion(&sd->bl,atoi(message));
	return 1;
}


/* Server Startup */
HPExport void plugin_init (void)
{
	addAtcommand("emotion",emotion);
}
