// Find

int pc_give_item_from_special_item_group(lua_State* L)

//add top

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	int pc_give_redcoin(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

		if (!lua_isnumber(L, 1))
		{
			sys_err("QUEST : wrong argument");
			return 0;
		}

		int iAmount = (int) lua_tonumber(L, 1);

		if (iAmount <= 0)
		{
			sys_err("QUEST : redcoin amount less then zero");
			return 0;
		}

		ch->PointChange(POINT_REDCOIN, iAmount, true);
		return 0;
	}
#endif

// Find

	int pc_get_money(lua_State * L)
	{ 
		lua_pushnumber(L, CQuestManager::instance().GetCurrentCharacterPtr()->GetGold());
		return 1;
	}
//add below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	int pc_get_redcoin(lua_State * L)
	{ 
		lua_pushnumber(L, CQuestManager::instance().GetCurrentCharacterPtr()->GetRedCoin());
		return 1;
	}
#endif

// Find

int pc_set_another_quest_flag(lua_State* L)

// Add end of function

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	int pc_change_redcoin(lua_State * L)
	{
		int redcoin = (int)lua_tonumber(L, -1);

		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

		if (redcoin + ch->GetRedCoin() < 0)
			sys_err("QUEST wrong ChangeRedCoin %d (now %d)", redcoin, ch->GetRedCoin());
		else
		{
			ch->PointChange(POINT_REDCOIN, redcoin, true);
		}

		return 0;
	}
#endif

// Find

{ "get_killee_drop_pct",	pc_get_killee_drop_pct	},

// add below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
			{ "get_redcoin",		pc_get_redcoin		},
			{ "change_redcoin",		pc_change_redcoin		},
			{ "give_redcoin",		pc_give_redcoin		},
#endif