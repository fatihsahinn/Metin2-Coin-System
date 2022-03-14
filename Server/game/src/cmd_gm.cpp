// Find

set_fields[] = {
	{ "gold",		NUMBER	},
	{ "race",		BINARY, },
	{ "sex",		BINARY	},
	{ "exp",		NUMBER	},
	{ "max_hp",		NUMBER	},
	{ "max_sp",		NUMBER	},
	{ "skill",		NUMBER	},
	{ "alignment",	NUMBER	},
	{ "align",		NUMBER	},
	
// Add Below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	{ "redcoin",	NUMBER	},
#endif

// find

		case 8: // alignment
			{
				int	amount = 0;
				str_to_number(amount, arg3);
				tch->UpdateAlignment(amount - ch->GetRealAlignment());
			}
			break;

// Add below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		case 9:
			{
				int amount = 0;
				str_to_number(amount, arg3);
				tch->PointChange(POINT_REDCOIN, amount, true);
			}
			break;
#endif
