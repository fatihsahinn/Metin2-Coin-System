// Find
HEADER_DG_CHANGE_CHARACTER_PRIV	= 127,

//Add below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	HEADER_DG_CHANGE_REDCOIN_COURE	= 128,
#endif

//Find
int		aiPremiumTimes[PREMIUM_MAX_NUM];

// Add below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	int	redcoin;
#endif

//Find
typedef struct SPacketMyshopPricelistHeader

// Add top

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
typedef struct TPacketDGChangeRDCCoure
{
	double kur;
} TPacketDGChangeRDCCoure;
#endif
