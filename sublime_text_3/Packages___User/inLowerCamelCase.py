import sublime, sublime_plugin, datetime, re
 
class InlowercamelcaseCommand(sublime_plugin.TextCommand):
	def run(self, edit):
		v = self.view

		VSelArr = v.sel();
		for i in range(len(VSelArr)):
			dec = v.substr(VSelArr[i])

			# v.replace(edit, VSelArr[i], dec.replace(" ", "_"))
			callback = lambda pat: pat.group(1).upper()
			v.replace(edit, VSelArr[i], re.sub(' (.)', callback, dec))