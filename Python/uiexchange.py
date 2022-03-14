##FİND
self.OwnerMoneyButton.SetEvent(ui.__mem_func__(self.OpenPickMoneyDialog))

##add
if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
	self.OwnerRedCoin = self.GetChild("Owner_RedCoin_Value")
	self.OwnerRedCoinButton = self.GetChild("Owner_RedCoin")
	self.OwnerRedCoinButton.SetEvent(ui.__mem_func__(self.OpenPickMoneyDialog))

#find
self.TargetMoney = self.GetChild("Target_Money_Value")

#add
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.TargetRedCoin = self.GetChild("Target_RedCoin_Value")
#find
		self.TargetAcceptLight = 0
		self.TitleName = 0
		self.AcceptButton = 0
		self.tooltipItem = 0
##add
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.OwnerRedCoin = 0
			self.OwnerRedCoinButton = 0
			self.TargetRedCoin = 0

#find function replace def OpenPickMoneyDialog(self):

	def OpenPickMoneyDialog(self):
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			if exchange.GetElkFromSelf() > 0 or exchange.GetRedCoinFromSelf() > 0:
				rRCvfR4c_fL4e.AppendChat(rRCvfR4c_fL4e.CHAT_TYPE_INFO, localeInfo.EXCHANGE_CANT_EDIT_MONEY)
				return
			self.dlgPickMoney.Open(Dr1vC_kQfStEqAvCx.GetElk(), Dr1vC_kQfStEqAvCx.GetRedCoin())
		else:
			if exchange.GetElkFromSelf() > 0:
				rRCvfR4c_fL4e.AppendChat(rRCvfR4c_fL4e.CHAT_TYPE_INFO, localeInfo.EXCHANGE_CANT_EDIT_MONEY)
				return

			self.dlgPickMoney.Open(Dr1vC_kQfStEqAvCx.GetElk())

#find and replace function OnPickMoney or customize it yourself

	if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
		def OnPickMoney(self, money, redcoin):
			fRaC_Fa4AP3cA1.SendWhisperPacket(exchange.GetNameFromTarget(), "#ticaret_add_money#"+str(money)+"#")
			fRaC_Fa4AP3cA1.SendWhisperPacket(exchange.GetNameFromTarget(), "#ticaret_add_redcoin#"+str(redcoin)+"#")
			constInfo.TICARET_LOG.insert(0, "#money_#"+str(money)+"#redcoin_#"+str(redcoin)+"#"+str(Dr1vC_kQfStEqAvCx.GetName())+"#")
			self.RefreshLogWithExchange()
			
			fRaC_Fa4AP3cA1.SendExchangeElkAddPacket(money)
			fRaC_Fa4AP3cA1.SendExchangeRedCoinAddPacket(redcoin)
	else:
		def OnPickMoney(self, money):
			fRaC_Fa4AP3cA1.SendWhisperPacket(exchange.GetNameFromTarget(), "#ticaret_add_money#"+str(money)+"#")
			constInfo.TICARET_LOG.insert(0, "#money_#"+str(money)+"#"+str(Dr1vC_kQfStEqAvCx.GetName())+"#")
			self.RefreshLogWithExchange()
			fRaC_Fa4AP3cA1.SendExchangeElkAddPacket(money)

#find
	def SelectOwnerEmptySlot(self, SlotIndex):

		if False == mouseModule.mouseController.isAttached():
			return

		if mouseModule.mouseController.IsAttachedMoney():
			fRaC_Fa4AP3cA1.SendExchangeElkAddPacket(mouseModule.mouseController.GetAttachedMoneyAmount())
##add
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			if mouseModule.mouseController.IsAttachedRedCoin():
				fRaC_Fa4AP3cA1.SendExchangeRedCoinAddPacket(mouseModule.mouseController.GetAttachedRedCoinAmount())
# find and compare your function

	def SelectOwnerItemSlot(self, SlotIndex):
		if Dr1vC_kQfStEqAvCx.ITEM_MONEY == mouseModule.mouseController.GetAttachedItemIndex():
			money = mouseModule.mouseController.GetAttachedItemCount()
			fRaC_Fa4AP3cA1.SendExchangeElkAddPacket(money)
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			if Dr1vC_kQfStEqAvCx.ITEM_RDC == mouseModule.mouseController.GetAttachedItemIndex():
				redcoin = mouseModule.mouseController.GetAttachedItemCount()
				fRaC_Fa4AP3cA1.SendExchangeRedCoinAddPacket(redcoin)
#find
	def Refresh(self):
		self.RefreshOwnerSlot()
		self.RefreshTargetSlot()
		if app.WJ_ENABLE_TRADABLE_ICON:
			self.RefreshLockedSlot()

		self.OwnerMoney.SetText(str(exchange.GetElkFromSelf()))
		self.TargetMoney.SetText(str(exchange.GetElkFromTarget()))
#add
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.OwnerRedCoin.SetText(str(localeInfo.NumberToMoneyStringRedCoin(exchange.GetRedCoinFromSelf())))
			self.TargetRedCoin.SetText(str(localeInfo.NumberToMoneyStringRedCoin(exchange.GetRedCoinFromTarget())))
#find OnUpdate function contains
		USE_EXCHANGE_LIMIT_RANGE = 1000
#add
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.OwnerRedCoin.SetText(str(localeInfo.NumberToMoneyStringRedCoin(exchange.GetRedCoinFromSelf())))
			self.TargetRedCoin.SetText(str(localeInfo.NumberToMoneyStringRedCoin(exchange.GetRedCoinFromTarget())))
