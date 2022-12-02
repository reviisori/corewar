#!/usr/bin/env python3

import sys
import os.path
import os
from os import path


EOC = "\033[0m"
GREEN = "\033[38;5;70m"
RED  = "\033[38;5;124m"
YELLOW = "\033[38;5;220m"

real_asm = "./asm"
our_asm = "../asm"
no_diff = []

def	main():
	dir_cont = os.listdir(sys.argv[1])
	for file in dir_cont:
		if ".s" in file:
			s_file = "%s%s" % (sys.argv[1], file)
			os.system("%s %s" % (real_asm, s_file))
			cor_file = s_file.replace(".s", ".cor")
			cmd = "hexdump %s > %s" % (cor_file, file.replace(".s", "_org.hex"))
			os.system(cmd)
			os.system("rm %s" % (cor_file))
	err_nbr = 0
	err_count = 0
	for file in dir_cont:
		if ".s" in file:
			s_file = "%s%s" % (sys.argv[1], file)
			os.system("%s %s" % (our_asm, s_file))
			cor_file = s_file.replace(".s", ".cor")
			if not path.exists(cor_file):
				no_diff.append(err_nbr)
				err_count += 1
			cmd = "hexdump %s > %s" % (cor_file, file.replace(".s", ".hex"))
			os.system(cmd)
			os.system("rm %s" % (cor_file))
			err_nbr += 1
	for file in dir_cont:
		if ".s" in file:
			cmd = "diff %s %s > %s" % (file.replace(".s", "_org.hex"), file.replace(".s", ".hex"), file.replace(".s", ".diff"))
			os.system(cmd)

	dir_cont = os.listdir()
	count = 1
	for file in dir_cont:
		if ".diff" in file:
			try:
				fd = open(file, "r")
				if count in no_diff:
					print(str(count).rjust(3, ' '), end=" ")
					print(YELLOW + "Something went wrong with " + EOC, end="")
					print(file.replace(".diff", ".s"))
				elif os.stat(file).st_size == 0:
					print(str(count).rjust(3, ' '), end=" ")
					print(GREEN + "OK" + EOC)
					os.system("rm %s %s %s" % (file.replace(".diff", "_org.hex"), file.replace(".diff", ".hex"), file))
				else:
					print(str(count).rjust(3, ' '), end=" ")
					print(RED + "KO" + EOC)
					err_count += 1
				count += 1
			except OSError:
				print("Invalid file")
				sys.exit()
			fd.close()
	print(str(count - err_count - 1) + "/" + str(count))
	#print("/")
	#print(count)

if __name__ == "__main__":
	main()