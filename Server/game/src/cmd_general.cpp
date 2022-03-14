// Find
#include "log.h"

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
#include "RedCoinManager.h"
#endif

// Find

ACMD(do_gift)

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
ACMD(update_rdc_kur)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));

	if (!*arg1)
		return;

	if(atof(arg1) <= 0)
		return;

	CRedCoinManager::instance().SetRedCoinCoure(atof(arg1));
	ch->ChatPacket(CHAT_TYPE_INFO, "<RedCoin>RDC kur güncel durumu <%f> olarak ayarlandı.",atof(arg1));
}
#endif