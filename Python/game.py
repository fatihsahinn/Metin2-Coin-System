## Add Gui Function

##For example onPressKeyDict[app.DIK_F5]	= lambda : self.RedCoinsOpen()

	def RedCoinsOpen(self):
		import uiRedCoins
		self.redcoins = uiRedCoins.myRedCoins()
		self.redcoins.Show()

# Find Function // Dr1vC_kQfStEqAvCx look at README.md

def OnMouseLeftButtonUp(self):

# Search in function

			if Dr1vC_kQfStEqAvCx.ITEM_MONEY == attachedItemIndex:
				self.__PutMoney(attachedType, attachedItemCount, self.PickingCharacterIndex)
####### # Add Below
			if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
				if Dr1vC_kQfStEqAvCx.ITEM_RDC == attachedItemIndex:
					self.__PutRedCoin(attachedType, attachedItemCount, self.PickingCharacterIndex)

#Find Function
	def __PutMoney(self, attachedType, attachedMoney, dstChrID):

# Add Top
	if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
		def __PutRedCoin(self, attachedType, attachedRedCoin, dstChrID):
			if True == chr.HasInstance(dstChrID) and Dr1vC_kQfStEqAvCx.GetMainCharacterIndex() != dstChrID:
				fRaC_Fa4AP3cA1.SendExchangeStartPacket(dstChrID)
				fRaC_Fa4AP3cA1.SendExchangePsgAddPacket(attachedRedCoin)
			else:
				self.__DropRedCoin(attachedType, attachedRedCoin)
				
		def __DropRedCoin(self, attachedType, attachedRedCoin):
			pass

#Find
				if dropNumber == Dr1vC_kQfStEqAvCx.ITEM_MONEY:
					fRaC_Fa4AP3cA1.SendGoldDropPacketNew(dropCount)
					snd.PlaySound("sound/ui/money.wav")
## add below
				if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
					if dropNumber == Dr1vC_kQfStEqAvCx.ITEM_RDC:
						snd.PlaySound("sound/ui/money.wav")
						