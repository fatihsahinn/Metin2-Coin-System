// Find

			if (to_ch->IsPC())
				{
					if (quest::CQuestManager::instance().GiveItemToPC(ch->GetPlayerID(), to_ch))
					{
						sys_log(0, "Exchange canceled by quest %s %s", ch->GetName(), to_ch->GetName());
						return;
					}
				}
				
// Add Top

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
				if (ch->GetRedCoin() >= REDCOIN_MAX)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("RedCoin Sınırı asildi."));
					sys_err("[OVERFLOW_REDCOIN] START (%d) id %u name %s ", ch->GetRedCoin(), ch->GetPlayerID(), ch->GetName());
					return;
				}
#endif

// Find case case EXCHANGE_SUBHEADER_CG_ELK_ADD: with break add

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		case EXCHANGE_SUBHEADER_CG_REDCOIN_ADD:	// arg1 == amount of redcoin
			if (ch->GetExchange())
			{
				const int nTotalRedCoin = static_cast<int>(ch->GetExchange()->GetCompany()->GetOwner()->GetRedCoin()) + static_cast<int>(pinfo->pRdc);

				if (REDCOIN_MAX <= nTotalRedCoin)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Maximum Coin Sınırı Aşıldı!"));

					sys_err("[OVERFLOW_REDCOIN] REDCOIN_ADD (%d) id %u name %s ",
							ch->GetExchange()->GetCompany()->GetOwner()->GetRedCoin(),
							ch->GetExchange()->GetCompany()->GetOwner()->GetPlayerID(),
						   	ch->GetExchange()->GetCompany()->GetOwner()->GetName());

					return;
				}

				if (ch->GetExchange()->GetCompany()->GetAcceptStatus() != true)
					ch->GetExchange()->AddRedCoin(pinfo->pRdc);
			}
			break;
#endif