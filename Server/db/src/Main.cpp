// Find

#include <signal.h>

// Add Below

#include "../../common/service.h" // if not, add

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
#include "RedCoinManager.h"
#endif

// Find

CPrivManager PrivManager;

// add below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	CRedCoinManager RedCoinManager;
#endif

// find
	else
	{
		sys_err("SQL_COMMON not configured");
		return false;
	}

// Add Below

#if defined(ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM)
	if (CConfig::instance().GetValue("SQL_WEBCORE", line, 256))
	{
		sscanf(line, " %s %s %s %s %d ", szAddr, szDB, szUser, szPassword, &iPort);
		sys_log(0, "connecting to MySQL server (web_core)");

		int iRetry = 5;

		do
		{
			if (CDBManager::instance().Connect(SQL_WEBCORE, szAddr, iPort, szDB, szUser, szPassword))
			{
				sys_log(0, "   OK");
				break;
			}

			sys_log(0, "   failed, retrying in 5 seconds");
			fprintf(stderr, "   failed, retrying in 5 seconds");
			sleep(5);
		} while (iRetry--);
		fprintf(stderr, "Success WEBCORE\n");
	}
	else
	{
		sys_err("SQL_WEBCORE not configured");
		return false;
	}
#endif
