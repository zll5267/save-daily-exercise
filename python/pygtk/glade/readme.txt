sudo apt-get install glade

glade

    install glade for GTK+2
    install glade for GTK+3

the glade file has two formats, one for libglade which is deprecated,
using as below:
    https://glade.gnome.org/sources.html
        gladefile = "test-libglade.glade"
        wTree = gtk.glade.XML(gladefile)
        window = wTree.get_widget("MainWindow")

the other is GTKBuilder, using as below:
    https://glade.gnome.org/sources.html
        gladefile = "test-gtkbuilder.glade"
        wTree = gtk.Builder()
        wTree.add_from_file(gladefile)
        window = wTree.get_object("MainWindow")
