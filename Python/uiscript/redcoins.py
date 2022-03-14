import uiScriptLocale,localeInfo
GOLD_COLOR	= 0xFFFEE3AE
BUTTON_ADRESS = "d:/ymir work/ui/game/myshop_deco/"

window = {
	"name" : "RedCoinVindow",
	"style" : ("movable", "float",),

	"x" : (SCREEN_WIDTH/2) - (190/2),
	"y" : (SCREEN_HEIGHT/2) - 100,	

	"width" : 314,
	"height" : 365+55,

	"children" :
	(
		{
			"name" : "board",
			"type" : "dragonboard",

			"x" : 0,
			"y" : 0,

			"width" : 314,
			"height" : 365+55,

			"children" :
			(
				## Title
				{
					"name" : "titlebar",
					"type" : "titlebar",
					"style" : ("attach",),

					"x" : 8,
					"y" : 7,

					"width" : 314-16,
					"color" : "gray",

					"children" :
					(
						{ "name":"titlename", "type":"text", "x":0, "y":3, 
						"text" : "RedCoin Hesap Bilgileriniz", 
						"horizontal_align":"center", "text_horizontal_align":"center" },
					),
				},
				{
					"name" : "header",
					"type" : "image",
					"x" : 5,
					"y" : 33,
					"image" : "d:/ymir work/freiswork/redcoins.png",
				},
				
				{ "name":"Bilgi", "type":"text", "x":314/2-154, "y":105, 
				"text" : "Red Coins Hesap Bilgilerim", 
				"horizontal_align":"center", "text_horizontal_align":"center" },
				
				{ "name":"RedCoinKuru", "type":"text", "x":314/2-154, "y":132, 
				"text" : "", 
				"horizontal_align":"center", "text_horizontal_align":"center" },
				
				{
					"name" : "refeshButton",
					"type" : "button",

					"x" : 25,
					"y" : 8,

					"tooltip_text" : "RDC Yenile",

					"default_image" : "d:/ymir work/ui/game/guild/Refresh_Button_01.sub",
					"over_image" : "d:/ymir work/ui/game/guild/Refresh_Button_02.sub",
					"down_image" : "d:/ymir work/ui/game/guild/Refresh_Button_03.sub",
				},
				
				# Red Egg Slot
				## Print
				{
					"name":"Rdc_Slot",
					"type":"button",

					"x":0,
					"y":270,

					"horizontal_align":"center",
					"vertical_align":"bottom",

					"default_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"over_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"down_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					
					"tooltip_text" : "Red Coins Miktarý",

					"children" :
					(
						{
							"name":"Rdc_Icon",
							"type":"image",

							"x":-22,
							"y":0,

							"image":"d:/ymir work/ui/ekenvanter/rdc.png",
						},

						{
							"name" : "RdcCount",
							"type" : "text",

							"x" : 3,
							"y" : 3,
							
							# "fontsize" : "MIDDLE",

							"horizontal_align" : "right",
							"text_horizontal_align" : "right",

							"text" : "123456789",
						},
					),
				},
				
				{
					"name" : "araimage21",
					"type" : "image",
					"x":314/2-65,
					"y" : 110,
					"image" : "d:/ymir work/freiswork/ok3.png",
				},
				{ "name":"Bilgi5", "type":"text", "x":314/2-165+5, "y":180, 
				"text" : "RDC TL Miktarý", 
				"horizontal_align":"center", "text_horizontal_align":"center" },
				
				## money
				
				## Print
				{
					"name":"Money_Slot",
					"type":"button",

					"x":0,
					"y":170,

					"horizontal_align":"center",
					"vertical_align":"bottom",

					"default_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"over_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"down_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					
					"tooltip_text" : "Red Coinsin Yang Miktarý",

					"children" :
					(
						{
							"name":"Yang_Icon",
							"type":"image",

							"x":-22,
							"y":0,

							"image":"d:/ymir work/ui/game/windows/money_icon.sub",
						},

						{
							"name" : "YangCount",
							"type" : "text",

							"x" : 3,
							"y" : 3,
							
							# "fontsize" : "MIDDLE",

							"horizontal_align" : "right",
							"text_horizontal_align" : "right",

							"text" : "123456789",
						},
					),
				},
				
				{
					"name" : "araimage2",
					"type" : "image",
					"x":314/2+50,
					"y" : 160,
					"image" : "d:/ymir work/freiswork/ok3.png",
				},
				{ "name":"Bilgi2", "type":"text", "x":314/2-154, "y":230, 
				"text" : "RDC Yang Miktarý", 
				"horizontal_align":"center", "text_horizontal_align":"center" },

				
				## Print
				{
					"name":"TL_Slot",
					"type":"button",

					"x":0,
					"y":220,

					"horizontal_align":"center",
					"vertical_align":"bottom",

					"default_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"over_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					"down_image" : "d:/ymir work/ui/public/parameter_slot_05.sub",
					
					"tooltip_text" : "Red Coinsin TL Miktarý",

					"children" :
					(
						{
							"name":"TL_Icon",
							"type":"image",

							"x":-22,
							"y":0,

							"image":"d:/ymir work/freiswork/tl.png",
						},

						{
							"name" : "TLCount",
							"type" : "text",

							"x" : 3,
							"y" : 3,
							
							# "fontsize" : "MIDDLE",

							"horizontal_align" : "right",
							"text_horizontal_align" : "right",

							"text" : "123456789",
						},
					),
				},
				
				{
					"name" : "BlackBoard1",
					"type" : "window",
					"x" : 10, "y" : 136, "width" : 190-(13*2), "height" : 248,
				},		
				
				{
					"name" : "yang_cekim", "type" : "button",
					"x" : 65, "y" : 290, "text": "RDC Yang Çekim Talebi Oluþtur",
					"text_height" : 6,
					"color" : GOLD_COLOR,

					"default_image" : "d:/ymir work/freiswork/button/xlarge1.png",
					"over_image" : "d:/ymir work/freiswork/button/xlarge2.png",
					"down_image" : "d:/ymir work/freiswork/button/xlarge3.png",
				},
				{
					"name" : "tl_cekim", "type" : "button",
					"x" : 65, "y" : 340, "text": "RDC TL Çekim Talebi Oluþtur",
					"text_height" : 6,
					"color" : GOLD_COLOR,

					"default_image" : "d:/ymir work/freiswork/button/xlarge1.png",
					"over_image" : "d:/ymir work/freiswork/button/xlarge2.png",
					"down_image" : "d:/ymir work/freiswork/button/xlarge3.png",
				},
			),
		},
	),
}
