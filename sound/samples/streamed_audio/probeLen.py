import sys, os, glob, subprocess
fl = glob.glob("*.aiff")

for f in fl:
    print(f)
    PP = subprocess.Popen(["ffprobe", f], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    result = PP.communicate()[1].decode('ascii')
    result = [i for i in result.split("\n") if "Duration" in i]
    result = result[0].split("start")[0]
    print(result)
