
INSTALL=/usr/local/sbin

aidentd: aidentd.c version.h
	gcc -O3 -o aidentd aidentd.c

dist: clean .version
	-mkdir aidentd-`cat .version`
	cp `ls [A-Z]* *.c fake.h| sed s/#.*$$//` aidentd-`cat .version`/
	find aidentd-`cat .version` -type f -exec chmod 664 {} \;
	tar zcf aidentd-`cat .version`.tar.gz aidentd-`cat .version`/
	rm -rf aidentd-`cat .version`

.version: README
	egrep "^Version" README | sed 's/Version //' > .version

version.h: .version
	echo "const char VERSION[] = \"`cat .version`\";" > version.h

clean: 
	rm -f .version version.h aidentd

install: aidentd
	rm -f $(INSTALL)/aidentd
	cp aidentd $(INSTALL)/aidentd
	chown root.root $(INSTALL)/aidentd
	chmod a-rw $(INSTALL)/aidentd
	chmod a+x $(INSTALL)/aidentd

