// Find

DWORD CItem::GetCount()
{
	if (GetType() == ITEM_ELK) return MIN(m_dwCount, INT_MAX);
	
// Add Below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	else if (GetType() == ITEM_RDC) return MIN(m_dwCount, INT_MAX);
#endif

// Find

bool CItem::SetCount(DWORD count)
{
	if (GetType() == ITEM_ELK)
	{
		m_dwCount = MIN(count, INT_MAX);
	}
	
// Add below

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	else if (GetType() == ITEM_RDC)
	{
		m_dwCount = MIN(count, INT_MAX);
	}
#endif