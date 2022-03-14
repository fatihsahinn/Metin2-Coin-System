#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM", 0);
#endif