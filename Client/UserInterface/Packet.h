// Find
EXCHANGE_SUBHEADER_CG_CANCEL,

// Add Below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	EXCHANGE_SUBHEADER_CG_REDCOIN_ADD,	/* arg1 == amount of redcoin */
#endif

//Find
typedef struct command_exchange

// Add container end
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	int			pRdc;
#endif

//Find
POINT_MIN_WEP = 200,

// Add Top
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	POINT_REDCOIN = 141,
#endif

// Find
} TPacketGCExchange;

// Add Top
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	int			pRdc;
#endif

//Find
EXCHANGE_SUBHEADER_GC_LESS_ELK,

// Add
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	EXCHANGE_SUBHEADER_GC_REDCOIN_ADD,
	EXCHANGE_SUBHEADER_GC_LESS_REDCOIN,
#endif




