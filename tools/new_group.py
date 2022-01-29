#!/bin/python3

import sys, os


groupname = sys.argv[1]


G_C = "actors/%s.c" % groupname
G_G_C = "actors/%s_geo.c" % groupname
G_H = "actors/%s.h" % groupname



os.system("touch %s" % G_C)
os.system("touch %s" % G_G_C)
os.system("touch %s" % G_H)


