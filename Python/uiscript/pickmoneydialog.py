import uiScriptLocale
import app

if app.ENABLE_FATIH_SAHIN_REDCOIN_SYSTEM:
	BOARD_WIDTH = 190
	BOARD_HEIGHT = 112
else:
	BOARD_WIDTH = 180
	BOARD_HEIGHT = 90

window = {
	"name" : "PickMoneyDialog",

	"x" : 100,
	"y" : 100,

	"style" : ("movable", "float",),

	"width" : BOARD_WIDTH,
	"height" : BOARD_HEIGHT,

	"children" :
	(
		{
			"name" : "board",
			"type" : "dragon_board_with_titlebar",

			"x" : 0,
			"y" : 0,

			"width" : BOARD_WIDTH,
			"height" : BOARD_HEIGHT,
			"title" : uiScriptLocale.PICK_MONEY_TITLE,

			"children" :
			(
				#Redcoin
				# {
					# "name" : "cheque_slot",
					# "type" : "image",

					# "x" : 20+15,
					# "y" : 34,

					# "image" : "d:/ymir work/ui/public/Parameter_Slot_02.sub",

					# "children" :
					# (

						# {
							# "name":"Cheque_Icon",
							# "type":"image",

							# "x":-22,
							# "y":2,

							# "image":"d:/ymir work/ui/game/windows/cheque_icon.sub",
						# },
						
						# {
							# "name" : "redcoin_value",
							# "type" : "editline",

							# "x" : 3,
							# "y" : 2,

							# "width" : 60,
							# "height" : 18,

							# "input_limit" : 2,
							# "only_number" : 1,

							# "text" : "0",
						# },
						# {
							# "name" : "redcoin_max_value",
							# "type" : "text",

							# "x" : 63,
							# "y" : 3,

							# "text" : "/ 99",
						# },
					# ),
				# },
				
				## Money Slot
				{
					"name" : "money_slot",
					"type" : "image",

					"x" : 20+15,
					"y" : 34, #RedCoin to 56

					"image" : "d:/ymir work/ui/public/Parameter_Slot_02.sub",

					"children" :
					(
						{
							"name":"Money_Icon",
							"type":"image",

							"x":-22,
							"y":2,

							"image":"d:/ymir work/ui/game/windows/money_icon.sub",
						},
						{
							"name" : "money_value",
							"type" : "editline",

							"x" : 3,
							"y" : 2,

							"width" : 60,
							"height" : 18,

							"input_limit" : 6,
							"only_number" : 1,

							"text" : "1",
						},
						{
							"name" : "max_value",
							"type" : "text",

							"x" : 63,
							"y" : 3,

							"text" : "/ 999999",
						},
					),
				},

				## Button
				{
					"name" : "accept_button",
					"type" : "button",

					"x" : BOARD_WIDTH/2 - 61 - 5,
					"y" : BOARD_HEIGHT - 32,

					"text" : uiScriptLocale.OK,

					"default_image" : "d:/ymir work/ui/public/middle_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/middle_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/middle_button_03.sub",
				},
				{
					"name" : "cancel_button",
					"type" : "button",

					"x" : BOARD_WIDTH/2 + 5,
					"y" : BOARD_HEIGHT - 32,

					"text" : uiScriptLocale.CANCEL,

					"default_image" : "d:/ymir work/ui/public/middle_button_01.sub",
					"over_image" : "d:/ymir work/ui/public/middle_button_02.sub",
					"down_image" : "d:/ymir work/ui/public/middle_button_03.sub",
				},
			),
		},
	),
}