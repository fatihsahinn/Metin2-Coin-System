// Find function PyObject * playerSetStatus(PyObject* poSelf, PyObject* poArgs) and add to end

#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
PyObject* playerGetRedCoin(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CPythonPlayer::Instance().GetStatus(POINT_REDCOIN));
}
PyObject* playerGetRedCoinKur(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("f", CPythonPlayer::Instance().GetRedCoinKur());
}
#endif

// Find
{ "GetMoney",					playerGetElk,						METH_VARARGS },

// Add
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		{ "GetRedCoin",					playerGetRedCoin,					METH_VARARGS },
		{ "GetRedCoinKur",				playerGetRedCoinKur,				METH_VARARGS },
#endif

// Find
PyModule_AddIntConstant(poModule, "SKILL_GRADE_NORMAL",			CPythonPlayer::SKILL_NORMAL);

// Add top
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	PyModule_AddIntConstant(poModule, "REDCOIN", POINT_REDCOIN);
#endif

// Find
PyModule_AddIntConstant(poModule, "ITEM_MONEY",					-1);

// add
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
	PyModule_AddIntConstant(poModule, "ITEM_RDC",					-2);
#endif


