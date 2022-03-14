// Find here ussualy first line

void exchange_packet(LPCHARACTER ch, BYTE sub_header,

// Function contains add int pRdc

// For example my code

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
void exchange_packet(LPCHARACTER ch, BYTE sub_header, bool is_me, long long arg1, TItemPos arg2, DWORD arg3, BYTE dice, int pRdc, void * pvData = NULL);
#else
void exchange_packet(LPCHARACTER ch, BYTE sub_header, bool is_me, long long arg1, TItemPos arg2, DWORD arg3, BYTE dice, void * pvData = NULL);
#endif

// Find here ussualy second line
void exchange_packet(LPCHARACTER ch, BYTE sub_header,

//Change or add int pRdc

// For example my code

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
void exchange_packet(LPCHARACTER ch, BYTE sub_header, bool is_me, long long arg1, TItemPos arg2, DWORD arg3, BYTE dice, int pRdc, void * pvData)
#else
void exchange_packet(LPCHARACTER ch, BYTE sub_header, bool is_me, long long arg1, TItemPos arg2, DWORD arg3, BYTE dice, void * pvData)
#endif

// Note : note that arg1 is integer if you are not using max yang system. I am using it so my variable data type is long long.

// Find

pack_exchg.arg3		= arg3;

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	pack_exchg.pRdc		= pRdc;
#endif

// Find

bool CHARACTER::ExchangeStart(LPCHARACTER victim)

// İn Function Search

	if (GetExchange())
		return false;

	if (victim->GetExchange())
	{
// Add or Change Below
// if you are using dice system, do like me, if not, remove the dice value.

#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		exchange_packet(this, EXCHANGE_SUBHEADER_GC_ALREADY, 0, 0, NPOS, 0, dice, 0);
#else
		exchange_packet(this, EXCHANGE_SUBHEADER_GC_ALREADY, 0, 0, NPOS, 0, dice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		exchange_packet(this, EXCHANGE_SUBHEADER_GC_ALREADY, 0, 0, NPOS, 0, 0);
#else
		exchange_packet(this, EXCHANGE_SUBHEADER_GC_ALREADY, 0, 0, NPOS, 0);
#endif
#endif

// Find
	victim->GetExchange()->SetCompany(GetExchange());
	GetExchange()->SetCompany(victim->GetExchange());

	SetExchangeTime();
	victim->SetExchangeTime();
	
// Change Below
#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(victim, EXCHANGE_SUBHEADER_GC_START, 0, GetVID(), NPOS, 0, dice, 0);
#else
	exchange_packet(victim, EXCHANGE_SUBHEADER_GC_START, 0, GetVID(), NPOS, 0, dice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(victim, EXCHANGE_SUBHEADER_GC_START, 0, GetVID(), NPOS, 0, 0);
#else
	exchange_packet(victim, EXCHANGE_SUBHEADER_GC_START, 0, GetVID(), NPOS, 0);
#endif
#endif

#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(this, EXCHANGE_SUBHEADER_GC_START, 0, victim->GetVID(), NPOS, 0, dice, 0);
#else
	exchange_packet(this, EXCHANGE_SUBHEADER_GC_START, 0, victim->GetVID(), NPOS, 0, dice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(this, EXCHANGE_SUBHEADER_GC_START, 0, victim->GetVID(), NPOS, 0, 0);
#else
	exchange_packet(this, EXCHANGE_SUBHEADER_GC_START, 0, victim->GetVID(), NPOS, 0);
#endif
#endif

// Find
	for (int i = 0; i < EXCHANGE_ITEM_MAX_NUM; ++i)
	{
		m_apItems[i] = NULL;
		m_aItemPos[i] = NPOS;
		m_abItemDisplayPos[i] = 0;
	}

	m_lGold = 0;

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	m_lRedCoin = 0;
#endif

// Find
		exchange_packet(m_pOwner,
			EXCHANGE_SUBHEADER_GC_ITEM_ADD,
			true,
			item->GetVnum(),
			TItemPos(RESERVED_WINDOW, display_pos),
			item->GetCount(),
// Add Below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
			m_lRedCoin,
#endif
			item);

// There is a line similar to this again just below Find

		exchange_packet(GetCompany()->GetOwner(),
			EXCHANGE_SUBHEADER_GC_ITEM_ADD,
			false,
			item->GetVnum(),
			TItemPos(RESERVED_WINDOW, display_pos),
			item->GetCount(),
// Add Below
	#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
			m_lRedCoin,
#endif
			item);
			sys_log(0, "EXCHANGE AddItem success %s pos(%d, %d) %d", item->GetName(), item_pos.window_type, item_pos.cell, display_pos);

// Find
	TItemPos PosOfInventory = m_aItemPos[pos];
	m_apItems[pos]->SetExchanging(false);

	m_pGrid->Get(m_abItemDisplayPos[pos], 1, m_apItems[pos]->GetSize());

// Change below
#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetOwner(),	EXCHANGE_SUBHEADER_GC_ITEM_DEL, true, pos, NPOS, 0, m_lDice,0);
#else
	exchange_packet(GetOwner(),	EXCHANGE_SUBHEADER_GC_ITEM_DEL, true, pos, NPOS, 0, m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetOwner(),	EXCHANGE_SUBHEADER_GC_ITEM_DEL, true, pos, NPOS, 0, 0);
#else
	exchange_packet(GetOwner(),	EXCHANGE_SUBHEADER_GC_ITEM_DEL, true, pos, NPOS, 0);
#endif
#endif

#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_ITEM_DEL, false, pos, PosOfInventory, 0, m_lDice, 0);
#else
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_ITEM_DEL, false, pos, PosOfInventory, 0, m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_ITEM_DEL, false, pos, PosOfInventory, 0, 0);
#else
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_ITEM_DEL, false, pos, PosOfInventory, 0);
#endif
#endif

// Find with bool CExchange::AddGold(long gold) and Search
if (GetOwner()->GetGold() < gold)
	{
//Change below
if (GetOwner()->GetGold() < gold)
	{
		// °¡Áö°í ÀÖ´Â µ·ÀÌ ºÎÁ·.
#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_GOLD, 0, 0, NPOS, 0, m_lDice, 0);
#else
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_GOLD, 0, 0, NPOS, 0, m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_GOLD, 0, 0, NPOS, 0,0);
#else
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_GOLD, 0, 0, NPOS, 0);
#endif
#endif
		return false;
	}
// Find
	}

	Accept(false);
	GetCompany()->Accept(false);

	m_lGold = gold;
// Change Below
#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_GOLD_ADD, true, m_lGold, NPOS, 0, m_lDice, m_lRedCoin);
#else
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_GOLD_ADD, true, m_lGold, NPOS, 0, m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_GOLD_ADD, true, m_lGold, NPOS, 0, m_lRedCoin);
#else
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_GOLD_ADD, true, m_lGold, NPOS, 0);
#endif
#endif

#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_GOLD_ADD, false, m_lGold, NPOS, 0, m_lDice, m_lRedCoin);
#else
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_GOLD_ADD, false, m_lGold, NPOS, 0, m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_GOLD_ADD, false, m_lGold, NPOS, 0, m_lRedCoin);
#else
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_GOLD_ADD, false, m_lGold, NPOS, 0);
#endif
#endif

// Add this as a new function just below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
bool CExchange::AddRedCoin(int redcoin)
{
	if (redcoin <= 0)
		return false;

	if (GetOwner()->GetRedCoin() < redcoin)
	{
#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_REDCOIN, 0, 0, NPOS, 0, m_lDice, 0);
#else
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_REDCOIN, 0, 0, NPOS, 0, m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_REDCOIN, 0, 0, NPOS, 0,0);
#else
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_REDCOIN, 0, 0, NPOS, 0);
#endif
#endif
		return false;
	}

	LPCHARACTER	victim = GetCompany()->GetOwner();

	if(m_lRedCoin)
	{
		int vic_redcoin = victim->GetRedCoin() + m_lRedCoin;
		if(vic_redcoin > REDCOIN_MAX)
		{
#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
			exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_REDCOIN, 0, 0, NPOS, 0, m_lDice,0);
#else
			exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_REDCOIN, 0, 0, NPOS, 0, m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
			exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_REDCOIN, 0, 0, NPOS, 0, 0);
#else
			exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_REDCOIN, 0, 0, NPOS, 0);
#endif
#endif
			GetOwner()->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Bu kullanıcı bu kadar çok RedCoin kabul edemez."));
			return false;
		}
	}

	if ( LC_IsCanada() == true || LC_IsEurope() == true )
	{
		if ( m_lRedCoin > 0 )
		{
			return false;
		}
	}

	Accept(false);
	GetCompany()->Accept(false);

	m_lRedCoin = redcoin;

#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_REDCOIN_ADD, true, 0, NPOS, 0, m_lDice, m_lRedCoin);
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_REDCOIN_ADD, false, 0, NPOS, 0, m_lDice, m_lRedCoin);
#else
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_REDCOIN_ADD, true, m_lRedCoin, NPOS, 0,m_lDice);
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_REDCOIN_ADD, false, m_lRedCoin, NPOS, 0,m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_REDCOIN_ADD, true, 0, NPOS, 0,m_lRedCoin);
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_REDCOIN_ADD, false, 0, NPOS, 0,m_lRedCoin);
#else
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_REDCOIN_ADD, true, m_lRedCoin, NPOS, 0);
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_REDCOIN_ADD, false, m_lRedCoin, NPOS, 0);
#endif
#endif
	return true;
}
#endif

// Find
bool CExchange::Check(int * piItemCount)
{

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	if (GetOwner()->GetRedCoin() < m_lRedCoin)
		return false;
#endif

// Find

bool CExchange::Done()
{
	int		empty_pos, i;
	LPITEM	item;

	LPCHARACTER	victim = GetCompany()->GetOwner();
	
// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	if(m_lRedCoin)
	{
		int vic_redcoin = victim->GetRedCoin() + m_lRedCoin;
		if(vic_redcoin > REDCOIN_MAX)
		{
			GetOwner()->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RedCoin limit asimi hatasi"));
			return false;
		}
	}
#endif

// Find

	if (m_lGold)
	{
		GetOwner()->PointChange(POINT_GOLD, -m_lGold, true);
		victim->PointChange(POINT_GOLD, m_lGold, true);

		if (m_lGold > 1000)
		{
			char exchange_buf[51];
			snprintf(exchange_buf, sizeof(exchange_buf), "%u %s", GetOwner()->GetPlayerID(), GetOwner()->GetName());
			LogManager::instance().CharLog(victim, m_lGold, "EXCHANGE_GOLD_TAKE", exchange_buf);

			snprintf(exchange_buf, sizeof(exchange_buf), "%u %s", victim->GetPlayerID(), victim->GetName());
			LogManager::instance().CharLog(GetOwner(), m_lGold, "EXCHANGE_GOLD_GIVE", exchange_buf);
		}
	}

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	if (m_lRedCoin)
	{
		GetOwner()->PointChange(POINT_REDCOIN, -m_lRedCoin, true);
		victim->PointChange(POINT_REDCOIN, m_lRedCoin, true);

		if (m_lRedCoin > 1000)
		{
			char exchange_buf[51];
			snprintf(exchange_buf, sizeof(exchange_buf), "%u %s", GetOwner()->GetPlayerID(), GetOwner()->GetName());
			LogManager::instance().CharLog(victim, m_lRedCoin, "EXCHANGE_GOLD_TAKE", exchange_buf);

			snprintf(exchange_buf, sizeof(exchange_buf), "%u %s", victim->GetPlayerID(), victim->GetName());
			LogManager::instance().CharLog(GetOwner(), m_lRedCoin, "EXCHANGE_GOLD_GIVE", exchange_buf);
		}
	}
#endif

// Find
		{
			if (Done())
			{
				if (m_lGold) // µ·ÀÌ ÀÖÀ» ‹š¸¸ ÀúÀå
					GetOwner()->Save();
// Add Below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
				if (m_lRedCoin) // RedCoin
					GetOwner()->Save();
#endif

// Find
			if (GetCompany()->Done())
				{
					if (GetCompany()->m_lGold) // µ·ÀÌ ÀÖÀ» ¶§¸¸ ÀúÀå
						victim->Save();
						
//Add
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
					if (GetCompany()->m_lRedCoin) // RedCoin
						victim->Save();
#endif

// Find
EXCHANGE_END:
		Cancel();
		return false;
	}
	else
	{
// Change Below
#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_ACCEPT, true, m_bAccept, NPOS, 0, m_lDice,0);
#else
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_ACCEPT, true, m_bAccept, NPOS, 0, m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_ACCEPT, true, m_bAccept, NPOS, 0, 0);
#else
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_ACCEPT, true, m_bAccept, NPOS, 0);
#endif
#endif

#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_ACCEPT, false, m_bAccept, NPOS, 0, m_lDice,0);
#else
		exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_ACCEPT, false, m_bAccept, NPOS, 0, m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_ACCEPT, false, m_bAccept, NPOS, 0, 0);
#else
		exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_ACCEPT, false, m_bAccept, NPOS, 0);
#endif
#endif


//Find
void CExchange::Cancel()
{

// change below

#ifdef ENABLE_DICE_SYSTEM
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_END, 0, 0, NPOS, 0, m_lDice,0);
#else
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_END, 0, 0, NPOS, 0, m_lDice);
#endif
#else
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_END, 0, 0, NPOS, 0, 0);
#else
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_END, 0, 0, NPOS, 0);
#endif
#endif

 // end




