// Find

bool SendExchangeItemAddPacket(TItemPos ItemPos, BYTE byDisplayPos);

// Add
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		bool SendExchangeRedCoinAddPacket(int redcoin);
#endif