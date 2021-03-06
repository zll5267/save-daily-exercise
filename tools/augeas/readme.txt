Augeas is a configuration editing tool. It parses configuration files
in their native formats and transforms them into a tree.
Configuration changes are made by manipulating this tree
and saving it back into native config files.

http://augeas.net


Augeas is:

    An API provided by a C library
    A command line tool to manipulate configuration from the shell (and shell scripts)
    Language bindings to do the same from your favorite scripting language
    Canonical tree representations of common configuration files
    A domain-specific language to describe configuration file formats

Augeas goals:

    Manipulate configuration files safely, safer than the ad-hoc techniques generally used with grep, sed, awk
    and similar mechanisms in scripting languages
    Provide a local configuration API for Linux
    Make it easy to integrate new config files into the Augeas tree

