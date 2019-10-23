import sublime, sublime_plugin, datetime
 
class ReplacinglettersonlatinCommand(sublime_plugin.TextCommand):
	def run(self, edit):
		slovar = {
			'а':'a',
			'б':'b',
			'в':'v',
			'г':'g',
			'д':'d',
			'е':'e',
			'ё':'je',
			'ж':'zh',
			'з':'z',
			'и':'i',
			'й':'y',
			'к':'k',
			'л':'l',
			'м':'m',
			'н':'n',
			'о':'o',
			'п':'p',
			'р':'r',
			'с':'s',
			'т':'t',
			'у':'u',
			'ф':'f',
			'х':'kh',
			'ц':'c',
			'ч':'ch',
			'ш':'sh',
			'щ':'jsh',
			'ъ':'hh',
			'ы':'ih',
			'ь':'jh',
			'э':'eh',
			'ю':'ju',
			'я':'ja',

			'А':'A',
			'Б':'B',
			'В':'V',
			'Г':'G',
			'Д':'D',
			'Е':'E',
			'Ё':'JE',
			'Ж':'ZH',
			'З':'Z',
			'И':'I',
			'Й':'Y',
			'К':'K',
			'Л':'L',
			'М':'M',
			'Н':'N',
			'О':'O',
			'П':'P',
			'Р':'R',
			'С':'S',
			'Т':'T',
			'У':'U',
			'Ф':'F',
			'Х':'KH',
			'Ц':'C',
			'Ч':'CH',
			'Ш':'SH',
			'Щ':'JSH',
			'Ъ':'HH',
			'Ы':'IH',
			'Ь':'JH',
			'Э':'EH',
			'Ю':'JU',
			'Я':'JA'
		}
		v = self.view

		VSelArr = v.sel();
		for i in range(len(VSelArr)):
			dec = v.substr(VSelArr[i])

			for key in slovar:
			      dec = dec.replace(key, slovar[key])

			v.replace(edit, VSelArr[i], dec)