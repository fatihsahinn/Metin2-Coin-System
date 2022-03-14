#find
def DeattachObject(self):

#add top
	if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
		def IsAttachedRedCoin(self):
			if TRUE == self.isAttached():
				if Dr1vC_kQfStEqAvCx.ITEM_RDC == self.GetAttachedItemIndex():
					return TRUE
			return FALSE

		def GetAttachedRedCoinAmount(self):
			if TRUE == self.isAttached():
				if Dr1vC_kQfStEqAvCx.ITEM_RDC == self.GetAttachedItemIndex():
					return self.GetAttachedItemCount()
			return 0

		def AttachRedCoin(self, owner, type, count):
			self.LastAttachedSlotNumber = self.AttachedSlotNumber

			self.AttachedFlag = TRUE
			self.AttachedOwner = owner
			self.AttachedType = type
			self.AttachedSlotNumber = -2
			self.AttachedItemIndex = Dr1vC_kQfStEqAvCx.ITEM_RDC
			self.AttachedCount = count
			self.AttachedIconHandle = grpImage.Generate("icon/item/80020.tga")
			self.AttachedIconHalfWidth = grpImage.GetWidth(self.AttachedIconHandle) / 2
			self.AttachedIconHalfHeight = grpImage.GetHeight(self.AttachedIconHandle) / 2
			wndMgr.AttachIcon(self.AttachedType, self.AttachedItemIndex, self.AttachedSlotNumber, 1, 1)
			if count > 1:
				self.countNumberLine.SetNumber(str(count))
				self.countNumberLine.Show()