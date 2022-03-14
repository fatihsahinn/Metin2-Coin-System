// Add file includes
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
#include "RedCoinManager.h"
#endif

// Find

marriage::CManager::instance().Login(ch);

// Add below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	CRedCoinManager::instance().GetRedCoinCoureSelect(ch);
#endif