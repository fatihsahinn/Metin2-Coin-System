#find
class MoneyInputDialog(ui.ScriptWindow):
	def __init__(self):
		ui.ScriptWindow.__init__(self)

##Change below

	if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.moneyHeaderText = " Yang"
			self.RedCoinHeaderText = " RedCoin"
			self.__CreateDialog()
			self.SetMaxLength(15)
			self.SetMaxLengthRedCoin(9)
		else:
			self.moneyHeaderText = localeInfo.MONEY_INPUT_DIALOG_SELLPRICE
			self.__CreateDialog()
			if app.ENABLE_PRIVATE_SHOP_SEARCH_SYSTEM: ##look your pythonapplicationmodule.py
				self.SetMaxLength(15)
			else:
				self.SetMaxLength(15)
#find
		self.inputValue.SetNumberMode()
		self.inputValue.OnIMEUpdate = ui.__mem_func__(self.__OnValueUpdate)
		self.moneyText = getObject("MoneyValue")
#add
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.InputValue_RedCoin = getObject("InputValue_RedCoin")
			self.InputValue_RedCoin.SetNumberMode()
			self.InputValue_RedCoin.OnIMEUpdate = ui.__mem_func__(self.__OnValueUpdateRedCoin)
			self.RedCoinText = getObject("RedCoinValue")
#find
	def Open(self):
		self.inputValue.SetText("")
		self.inputValue.SetFocus()
		self.__OnValueUpdate()
##add
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.InputValue_RedCoin.SetText("")
			self.InputValue_RedCoin.SetFocus()
			self.__OnValueUpdateRedCoin()
		
##find
	def Close(self):
		self.ClearDictionary()
		self.board = None
		self.acceptButton = None
		self.cancelButton = None
		self.inputValue = None
##add
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.InputValue_RedCoin = None
#find
	def SetFocus(self):
		self.inputValue.SetFocus()
##add
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.InputValue_RedCoin.SetFocus()
#find function
	def SetMaxLength(self, length):
		if app.ENABLE_PRIVATE_SHOP_SEARCH_SYSTEM:
			length = min(15, length)
		else:
			length = min(15, length)
		
		self.inputValue.SetMax(length)
## add below new function
	if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
		def SetMaxLengthRedCoin(self, length):
			length = min(10, length)
			self.InputValue_RedCoin.SetMax(length)

## compare andd add your own functions
	def SetMoneyHeaderText(self, text):
		self.moneyHeaderText = text
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.RedCoinHeaderText = text

	def SetAcceptEvent(self, event):
		self.acceptButton.SetEvent(event)
		self.inputValue.OnIMEReturn = event
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.InputValue_RedCoin.OnIMEReturn = event

	def SetCancelEvent(self, event):
		self.board.SetCloseEvent(event)
		self.cancelButton.SetEvent(event)
		self.inputValue.OnPressEscapeKey = event
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			self.InputValue_RedCoin.OnPressEscapeKey = event

	def SetValue(self, value):
		value=str(value)
		self.inputValue.SetText(value)
		self.__OnValueUpdate()
		ime.SetCursorPosition(len(value))		

	if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
		def SetValueRedCoin(self, value):
			value=str(value)
			self.InputValue_RedCoin.SetText(value)
			self.__OnValueUpdateRedCoin()
			ime.SetCursorPosition(len(value))

	def GetText(self):
		return self.inputValue.GetText()
		if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
			return self.InputValue_RedCoin.GetText()

	def __OnValueUpdate(self):
		ui.EditLine.OnIMEUpdate(self.inputValue)

		text = self.inputValue.GetText()
		text2 = self.InputValue_RedCoin.GetText()

## add __OnValueUpdate function below new function
	if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
		def __OnValueUpdateRedCoin(self):
			ui.EditLine.OnIMEUpdate(self.InputValue_RedCoin)

			text = self.InputValue_RedCoin.GetText()

			redcoin = 0
			if text and text.isdigit():
				try:
					redcoin = int(text)
				except ValueError:
					redcoin = 0

			self.RedCoinText.SetText(localeInfo.NumberToMoneyStringRedCoin(redcoin) + self.RedCoinHeaderText)
