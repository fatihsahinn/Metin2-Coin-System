// Find

char * CPythonExchange::GetNameFromTarget()

// add at the end of the above function

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
void CPythonExchange::SetRedCoinToTarget(int redcoin)
{
	m_victim.redcoin = redcoin;
}

void CPythonExchange::SetRedCoinToSelf(int redcoin)
{
	m_self.redcoin = redcoin;
}

int CPythonExchange::GetRedCoinFromTarget()
{
	return m_victim.redcoin;
}

int CPythonExchange::GetRedCoinFromSelf()
{
	return m_self.redcoin;
}
#endif