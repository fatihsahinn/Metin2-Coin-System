// Find

		bool		Accept(bool bIsAccept = true);
		void		Cancel();

// Add below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		bool		AddRedCoin(int redcoin);
#endif

// Find
		TItemPos		m_aItemPos[EXCHANGE_ITEM_MAX_NUM];
		LPITEM		m_apItems[EXCHANGE_ITEM_MAX_NUM];
		BYTE		m_abItemDisplayPos[EXCHANGE_ITEM_MAX_NUM];

		bool 		m_bAccept;
// Add Below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		int		m_lRedCoin;
#endif