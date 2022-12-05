#!/usr/bin/env python3

import sys
import os


EOC = "\033[0m"
GREEN = "\033[38;5;70m"
RED  = "\033[38;5;124m"

real_asm = "../../resources/vm_champs/asm"
our_asm = "../asm"

def	main():
	dir_cont = os.listdir(sys.argv[1])
	for file in dir_cont:
		if ".s" in file:
			s_file = "%s%s" % (sys.argv[1], file)
			os.system("%s %s" % (real_asm, s_file))
			cor_file = s_file.replace(".s", ".cor")
			cmd = "hexdump %s > %s" % (cor_file, file.replace(".s", "_org.hex"))
			os.system(cmd)
	for file in dir_cont:
		if ".s" in file:
			s_file = "%s%s" % (sys.argv[1], file)
			os.system("%s %s" % (our_asm, s_file))
			cor_file = s_file.replace(".s", ".cor")
			cmd = "hexdump %s > %s" % (cor_file, file.replace(".s", ".hex"))
			os.system(cmd)
	for file in dir_cont:
		if ".s" in file:
			cmd = "diff %s %s > %s" % (file.replace(".s", "_org.hex"), file.replace(".s", ".hex"), file.replace(".s", ".diff"))
			os.system(cmd)
	dir_cont = os.listdir()
	count = 0
	for file in dir_cont:
		if ".diff" in file:
			try:
				fd = open(file, "r")
				if os.stat(file).st_size == 0:
					print(str(count).rjust(3, ' '), end=" ")
					print(GREEN + "OK" + EOC)
					os.system("rm %s %s %s" % (file.replace(".diff", "_org.hex"), file.replace(".diff", ".hex"), file))
				else:
					print(str(count).rjust(3, ' '), end=" ")
					print(RED + "KO" + EOC)
				count += 1
			except OSError:
				print("Invalid file")
				sys.exit()
			fd.close()

if __name__ == "__main__":
	main()