// Find
PyObject* netSendExchangeStartPacket(PyObject* poSelf, PyObject* poArgs)
{
	int vid;
	if (!PyTuple_GetInteger(poArgs, 0, &vid))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendExchangeStartPacket(vid);
	return Py_BuildNone();
}

//Add Below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
PyObject* netSendExchangeRedCoinAddPacket(PyObject* poSelf, PyObject* poArgs)
{
	int redcoin;
	if (!PyTuple_GetInteger(poArgs, 0, &redcoin))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();
	rkNetStream.SendExchangeRedCoinAddPacket(redcoin);
	return Py_BuildNone();
}
#endif

// Find

{ "SendExchangeElkAddPacket",			netSendExchangeElkAddPacket,			METH_VARARGS }, 

//Add below
#ifdef ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM
		{ "SendExchangeRedCoinAddPacket",		netSendExchangeRedCoinAddPacket,		METH_VARARGS },
#endif
