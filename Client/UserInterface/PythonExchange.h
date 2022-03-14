// Find

BYTE					accept;

// Add below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
			int						redcoin;
#endif

//Find
char			*GetNameFromTarget();

// Add Below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		void			SetRedCoinToTarget(int redcoin);
		void			SetRedCoinToSelf(int redcoin);

		int				GetRedCoinFromTarget();
		int				GetRedCoinFromSelf();
#endif