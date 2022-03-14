// Find

	item->SetProto(table);
	item->SetMaskVnum(dwMaskVnum);

	if (item->GetType() == ITEM_ELK)
		item->SetSkipSave(true);

// Add Below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	else if (item->GetType() == ITEM_RDC)
		item->SetSkipSave(true);
#endif

// Find
	if (item->GetType() == ITEM_ELK)
		;
// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	else if (item->GetType() == ITEM_RDC)
		;
#endif