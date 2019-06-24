#!/usr/bin/python3
import re

class Card(object):
	def __init__(self, number):
		self.number = number

	def __convertNumberToList(self, number,divider=2, multiplier=1):
		numbers = []
		rest = []
		for index, x in enumerate(str(number), start=1):
			#print(x)
			if not index % divider:
				numbers.append(int(x) * multiplier)
			else:
				rest.append(int(x))
		return numbers,rest

	def checkIfValid(self):
		SUM = 0
		nums, rest = self.__convertNumberToList(self.number, multiplier=2)
		for num in nums:
			if int(num) > 9:
				number, a = self.__convertNumberToList(num, divider=1)
				SUM += sum(number)
			else:
				SUM += int(num)

		#print(sum(self.__convertNumberToList(rest, divider=1)))
		SUM += sum(rest)
		if not SUM % 10:
			return True
		return False

	def getManufacturer(self):
		if str(self.number)[0] == 4:
			return "Visa"
		owners = {
			"American Express" : (34, 37),
			"MasterCard": (51, 52, 53, 54, 55),
		}
		for owner, start in owners.items():
			if int(str(self.number)[:2]) in start:
				return owner
		return None

	def check(self):
		valid = self.checkIfValid()
		if valid:
			manu = self.getManufacturer()
			print(manu)
			return
		print("INVALID")
		return
if __name__ == '__main__':
	while True:
		try:
			number = int(input("Number: "))
			break
		except ValueError:
			pass
	card = Card(number)
	card.check()

	