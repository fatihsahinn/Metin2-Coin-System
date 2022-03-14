// Find

EXCHANGE_SUBHEADER_CG_CANCEL,

// Add Below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	EXCHANGE_SUBHEADER_CG_REDCOIN_ADD,	/* arg1 == amount of won */
#endif

// Find

} TPacketCGExchange;

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	int		pRdc;
#endif

// Find
struct packet_exchange
{

// Add end struct

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	int			pRdc;
#endif

// Find
EXCHANGE_SUBHEADER_GC_LESS_GOLD,

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	EXCHANGE_SUBHEADER_GC_REDCOIN_ADD,	/* arg1 == redcoin */
	EXCHANGE_SUBHEADER_GC_LESS_REDCOIN,	/* arg1 == not used */
#endif