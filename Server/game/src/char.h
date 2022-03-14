// Find
POINT_MELEE_MAGIC_ATT_BONUS_PER = 132,

// add below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM // More important enumaration with client side
	POINT_REDCOIN = 141,
#endif

// Find

BYTE			skill_group;

// add below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	int				redcoin;
#endif

// Find

void			GiveGold(

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		int			GetRedCoin() const		{ return m_points.redcoin;	}
		void			SetRedCoin(int redcoin)	{ m_points.redcoin = redcoin; }
		void			GiveRedCoin(int iAmount);
#endif