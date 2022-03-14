// Find

void	SendClickItemPacket(DWORD dwIID);

// Add
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		double	GetRedCoinKur();
		void	SetRedCoinKur(double amount);
#endif

//Find
BOOL					m_sysIsLevelLimit;

// Add

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		double					m_dwRedCoinKur;
#endif