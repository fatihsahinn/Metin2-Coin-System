// Find

ACMD(do_user_horse_feed);

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
ACMD(update_rdc_kur);
#endif

// Find

{ "user_horse_feed",	do_user_horse_feed,		0,		POS_FISHING,	GM_PLAYER	},

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	{ "rdc_kur_degistir",	update_rdc_kur,	0,		POS_DEAD,	GM_IMPLEMENTOR	},
#endif

