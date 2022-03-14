#add function

def NumberToMoneyStringRedCoin(number):
		if number <= 0:
			return "0 RDC"
		
		result = str(number)

		if len(result) == 1:
 			result = "0.000000000" + str(number)
		elif len(result) == 2:
			result = "0.00000000" + str(number)
		elif len(result) == 3:
			result = "0.0000000" + str(number)
		elif len(result) == 4:
			result = "0.000000" + str(number)
		elif len(result) == 5:
			result = "0.00000" + str(number)
		elif len(result) == 6:
			result = "0.0000" + str(number)
		elif len(result) == 7:
			result = "0.000" + str(number)
		elif len(result) == 8:
			result = "0.00" + str(number)
		elif len(result) == 9:
			result = "0.0" + str(number)
		elif len(result) == 10:
			result = "0." + str(number)

		result = result + "|cFFc7b81f RDC|r"

		return result