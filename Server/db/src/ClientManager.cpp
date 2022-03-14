// İf you don't have header file 
#include "../../common/service.h" or #include "../../common/CommonDefines.h"
// Please Add

// Find

#include "Cache.h"

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
#include "RedCoinManager.h"
#endif

// Find

bool CClientManager::Initialize()

// Add on top

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
static bool __InitializeRedCoinCoure()
{
	std::unique_ptr<SQLMsg> pMsg(CDBManager::instance().DirectQuery("SELECT rdc_Kur FROM svSettings", SQL_WEBCORE));
	if (pMsg->Get()->uiNumRows == 0)
	{
		printf("__InitializeRedCoinCoure failed rdc_Kur pMsg \n");
		return false;
	}

	MYSQL_ROW row = NULL;
	while ((row = mysql_fetch_row(pMsg->Get()->pSQLResult)))
	{
		CRedCoinManager::instance().AddCoinCoure(atof(row[0]));
		printf("REDCOIN_COURE: set rdc_coure(%f)\n", atof(row[0]));
	}

	return true;
}
#endif

// Find

//BOOT_LOCALIZATION
	if (!InitializeLocalization())

// Add Below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	if(!__InitializeRedCoinCoure())
	{
		fprintf(stderr, "Failed RedCoin Kuru Ayarlanmadi!\n");
	}
#endif

// Find

CPrivManager::instance().SendPrivOnSetup(peer);

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	CRedCoinManager::instance().SendRDCSetup(peer);
#endif


