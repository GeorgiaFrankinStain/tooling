import sublime, sublime_plugin, datetime
import random
import string

def random_string(size):
    return ''.join(random.choice(string.ascii_letters) for _ in range(size))

    

class RandomstringCommand(sublime_plugin.TextCommand):
	def run(self, edit):
		v = self.view

		VSelArr = v.sel();
		for i in range(len(VSelArr)):
			dec = v.substr(VSelArr[i])
			size = 5
			res_text = "11111"
		    # res_text += ''.join(random.choice(string.ascii_letters + string.digits) for _ in range(size))
			v.replace(edit, VSelArr[i], random_string(len(dec + "")))