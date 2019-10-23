import sublime, sublime_plugin, datetime
 
class ZamenaundelineCommand(sublime_plugin.TextCommand):
	def run(self, edit):
		v = self.view

		VSelArr = v.sel();
		for i in range(len(VSelArr)):
			dec = v.substr(VSelArr[i])

			v.replace(edit, VSelArr[i], dec.replace(" ", "_"))