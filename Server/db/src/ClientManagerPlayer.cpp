// Find

"horse_skill_point = %d, "

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		"redcoin = %d,"
#endif

// Find

pkTab->horse_skill_point,

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM 
		pkTab->redcoin,
#endif

// Find

"horse_skill_point, "

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
			"redcoin, "
#endif

// Find

str_to_number(pkTab->horse_skill_point, row[col++]);

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	str_to_number(pkTab->redcoin, row[col++]);
#endif