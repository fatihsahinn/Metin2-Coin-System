// Find

tab.skill_group = m_points.skill_group;

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	tab.redcoin	= GetRedCoin();
#endif

// Find

pack.points[POINT_MAX_STAMINA] = GetMaxStamina();

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	pack.points[POINT_REDCOIN]	= GetRedCoin();
#endif

// Find

	SetLevel(t->level);
	SetExp(t->exp);
	SetGold(t->gold);
	
// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	SetRedCoin(t->redcoin);
#endif

// Find

long lSPRecovery = GetPoint(POINT_SP_RECOVERY);

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	long lRedCoin = GetRedCoin();
#endif

// Find

// PC_BANG_ITEM_ADD
	SetPoint(POINT_PC_BANG_EXP_BONUS, 0);
	SetPoint(POINT_PC_BANG_DROP_BONUS, 0);
// END_PC_BANG_ITEM_ADD
	
// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	SetPoint(POINT_REDCOIN, lRedCoin);
#endif

// Find

		case POINT_GOLD:
			{

// And end of case break; Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		case POINT_REDCOIN:
			{
				const int nTotalRedCoin = static_cast<int>(GetRedCoin()) + static_cast<int>(amount);
				if (REDCOIN_MAX <= nTotalRedCoin)
				{
					sys_err("[OVERFLOW_REDCOIN] OriRedCoin %d AddedRedCoin %d id %u Name %s ", GetRedCoin(), amount, GetPlayerID(), GetName());
					LogManager::instance().CharLog(this, GetRedCoin() + amount, "OVERFLOW_REDCOIN", "");
					return;
				}
				SetRedCoin(GetRedCoin() + static_cast<int>(amount));
				val = GetRedCoin();
			}
			break;
#endif

