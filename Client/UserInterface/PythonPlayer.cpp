// Find

void CPythonPlayer::SetGameWindow(PyObject * ppyObject)
{
	m_ppyGameWindow = ppyObject;
}

// Add below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
double CPythonPlayer::GetRedCoinKur()
{
	return m_dwRedCoinKur;
}
void CPythonPlayer::SetRedCoinKur(double amount)
{
	m_dwRedCoinKur = amount;
}
#endif

