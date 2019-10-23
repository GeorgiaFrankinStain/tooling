import sublime, sublime_plugin, datetime
 
class PrintdateCommand(sublime_plugin.TextCommand):
	def run(self, edit):
		today = datetime.datetime.today()
		self.view.insert(edit, self.view.sel()[0].begin(),   today.strftime("%Y.%m.%d %H:%M:%S") )