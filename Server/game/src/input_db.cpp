// Add include file

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
#include "RedCoinManager.h"
#endif

// Find
void CInputDB::PartyCreate(const char* c_pData)

// Add Top
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
void CInputDB::ChangeRedCoinCoure(const char* c_pData)
{
	TPacketDGChangeRDCCoure* p = (TPacketDGChangeRDCCoure*) c_pData;

	CRedCoinManager::instance().SetRedCoinCoure(p->kur);
}
#endif

// Find

	case HEADER_DG_PARTY_CREATE:
		PartyCreate(c_pData);
		break;

// Add Top
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	case HEADER_DG_CHANGE_REDCOIN_COURE:
		ChangeRedCoinCoure(c_pData);
		break;
#endif


