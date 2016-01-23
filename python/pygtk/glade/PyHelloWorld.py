#!/usr/bin/env python

import sys

#try:
import pygtk
pygtk.require("2.0")
#except:
#    print("wrong pygtk version")
#    pass

try:
    import gtk
    import gtk.glade
except:
    sys.exit(1)

class HelloWorldGTK:
    """"""
    def btnHelloWorld_clicked(self, widget):
        print("Hello World!")
    def __init__(self):
        self.gladefile = "PyHelloWorld.glade"

        #self.wTree = gtk.glade.XML(self.gladefile)
        #self.window = self.wTree.get_widget("MainWindow")

        self.wTree = gtk.Builder()
        self.wTree.add_from_file(self.gladefile)
        self.window = self.wTree.get_object("MainWindow")
        self.button = self.wTree.get_object("btnHelloWorld")
        self.button.connect("clicked", self.btnHelloWorld_clicked)

        if (self.window):
            self.window.connect("destroy", gtk.main_quit)
        self.window.show()



if __name__ == "__main__":
    hwg = HelloWorldGTK()
    gtk.main()
