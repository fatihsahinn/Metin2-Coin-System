// Find

struct FMoneyDistributor
	{
		int		total;
		LPCHARACTER	c;
		int		x, y;
		int		iMoney;

		FMoneyDistributor(LPCHARACTER center, int iMoney) 
			: total(0), c(center), x(center->GetX()), y(center->GetY()), iMoney(iMoney) 
		{
		}

		void operator ()(LPCHARACTER ch)
		{
			if (ch!=c)
				if (DISTANCE_APPROX(ch->GetX() - x, ch->GetY() - y) <= PARTY_DEFAULT_RANGE)
				{
					ch->PointChange(POINT_GOLD, iMoney, true);

					if (iMoney > 1000) // Ãµ¿ø ÀÌ»ó¸¸ ±â·ÏÇÑ´Ù.
						LogManager::instance().CharLog(ch, iMoney, "GET_GOLD", "");
				}
		}
	};
	
// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	struct FRedCoinDistributor
	{
		int		total;
		LPCHARACTER	c;
		int		x, y;
		int	iRedCoin;

		FRedCoinDistributor(LPCHARACTER center, int iRedCoin) 
			: total(0), c(center), x(center->GetX()), y(center->GetY()), iRedCoin(iRedCoin) 
		{
		}

		void operator ()(LPCHARACTER ch)
		{
			if (ch!=c)
				if (DISTANCE_APPROX(ch->GetX() - x, ch->GetY() - y) <= PARTY_DEFAULT_RANGE)
				{
					ch->PointChange(POINT_REDCOIN, iRedCoin, true);

					if (iRedCoin > 1000) // ?? ??? ????.
						LogManager::instance().CharLog(ch, iRedCoin, "GET_REDCOIN", "");
				}
		}
	};
#endif

// Find

bool CHARACTER::PickupItem(DWORD dwVID)

// Add Top Of Function

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
void CHARACTER::GiveRedCoin(int redcoin)
{
	if (redcoin <= 0)
		return;

	if (GetParty())
	{
		LPPARTY pParty = GetParty();

		DWORD dwTotal = redcoin;
		DWORD dwMyAmount = dwTotal;

		NPartyPickupDistribute::FCountNearMember funcCountNearMember(this);
		pParty->ForEachOnlineMember(funcCountNearMember);

		if (funcCountNearMember.total > 1)
		{
			DWORD dwShare = dwTotal / funcCountNearMember.total;
			dwMyAmount -= dwShare * (funcCountNearMember.total - 1);

			NPartyPickupDistribute::FRedCoinDistributor funcRedCoinDist(this, dwShare);

			pParty->ForEachOnlineMember(funcRedCoinDist);
		}

		PointChange(POINT_REDCOIN, dwMyAmount, true);

		if (dwMyAmount > 1000) // ?? ??? ????.
			LogManager::instance().CharLog(this, dwMyAmount, "GET_REDCOIN", "");
	}
	else
	{
		PointChange(POINT_REDCOIN, redcoin, true);

		if (LC_IsBrazil() == true)
		{
			if (redcoin >= 213)
				LogManager::instance().CharLog(this, redcoin, "GET_REDCOIN", "");
		}
		else
		{
			if (redcoin > 1000) // ?? ??? ????.
				LogManager::instance().CharLog(this, redcoin, "GET_REDCOIN", "");
		}
	}
}
#endif

// Find

	if (item->IsOwnership(this))
		{

			if (item->GetType() == ITEM_ELK)
			{
				GiveGold(item->GetCount());
				item->RemoveFromGround();

				M2_DESTROY_ITEM(item);

				Save();
			}

// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
			else if (item->GetType() == ITEM_RDC)
			{
				GiveRedCoin(item->GetCount());
				item->RemoveFromGround();

				M2_DESTROY_ITEM(item);

				Save();
			}
#endif

