import ui
import fRaC_Fa4AP3cA1
import app
import vGcV3aC1_xF5cac, uiCommon, uishop
import constInfo
import rRCvfR4c_fL4e
import Dr1vC_kQfStEqAvCx
if constInfo.PSM:
	import localeInfo as _localeInfo
	localeInfo = _localeInfo.localeInfo()
else:
	import localeInfo
from _weakref import proxy

import renderTarget

class myRedCoins(ui.ScriptWindow):
	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.__Initialize()
		self.__Load()
		self.lastRefreshRdc = 0
	def __del__(self):
		ui.ScriptWindow.__del__(self)
		print " -------------------------------------- DELETE GAME redcoins"

	def __Initialize(self):
		self.titleBar = 0

	def Destroy(self):
		self.ClearDictionary()
		self.board = None
		self.__Initialize()
		print " -------------------------------------- DESTROY redcoins"
	
	def __Load_LoadScript(self, fileName):
		try:
			pyScriptLoader = ui.PythonScriptLoader()
			pyScriptLoader.LoadScriptFile(self, fileName)
		except:
			import exception
			exception.Abort("OptionDialog.__Load_LoadScript")

	def __Load_BindObject(self):
		try:
			GetObject = self.GetChild
			self.titleBar = GetObject("titlebar")
			self.board = GetObject("board")
			
			self.wndRdc = GetObject("RdcCount")
			self.wndYang = GetObject("YangCount")
			self.wndTL = GetObject("TLCount")
			self.wndRedCoinKur = GetObject("RedCoinKuru")
			self.refeshButton = GetObject("refeshButton")

			self.yang_cekim = GetObject("yang_cekim")
			self.yang_cekim.Show()

			self.refeshButton.SetEvent(ui.__mem_func__(self.RefreshRdc))

		except:
			import exception
			exception.Abort("OptionDialog.__Load_BindObject")

	def LoadRdc(self):
		self.wndRdc.SetText(localeInfo.NumberToMoneyStringRedCoin(Dr1vC_kQfStEqAvCx.GetRedCoin()))
		self.wndRedCoinKur.SetText("Güncel RDC Kuru: |cFFc7b81f"+str(Dr1vC_kQfStEqAvCx.GetRedCoinKur())+"|r")
		self.wndYang.SetText(localeInfo.NumberToMoneyString(Dr1vC_kQfStEqAvCx.GetRedCoin()*Dr1vC_kQfStEqAvCx.GetRedCoinKur()))
		
		formatted_float = "|cFFc7b81f{:,.2f} |rTL".format((Dr1vC_kQfStEqAvCx.GetRedCoin()*Dr1vC_kQfStEqAvCx.GetRedCoinKur())/100000000)
		self.wndTL.SetText(formatted_float)

	def RefreshRdc(self):
		if app.GetTime() < self.lastRefreshRdc:
			rRCvfR4c_fL4e.AppendChat(rRCvfR4c_fL4e.CHAT_TYPE_INFO, "Yenilemek için 5 Saniye beklemen gerekli.")
			return

		self.wndRdc.SetText(str(localeInfo.NumberToMoneyStringRedCoin(Dr1vC_kQfStEqAvCx.GetRedCoin())))
		rRCvfR4c_fL4e.AppendChat(1,"Rdc baþarýyla yenilendi!")
		self.lastRefreshRdc = app.GetTime() + 5

	def __Load(self):
		self.__Load_LoadScript("uiscript/redcoins.py")

		self.__Load_BindObject()

		self.SetCenterPosition()
		
		self.LoadRdc()

		self.titleBar.SetCloseEvent(ui.__mem_func__(self.Close))

	def OnPressEscapeKey(self):
		self.Close()
		return True

	def Show(self):
		ui.ScriptWindow.Show(self)

	def Close(self):
		self.Hide()
		self.ClearDictinary()
		self.Destroy()
