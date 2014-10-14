include $(HOME)/etc/pub.mk

#tcp/ip asyn 
TCPASYNGWLIB	=	-lpbbase

TCPASYNFUNCOBJS	= pbtcpasynfunc.o
PARSE = pbparse.o
TCPASYNCLIENTOBJS	=	 $(PARSE) $(TCPASYNFUNCOBJS) pbtcpasynclient.o
TCPASYNSERVEROBJS	=  $(PARSE) $(TCPASYNFUNCOBJS) pbtcpasynserver.o

TCPASYNCLIENT	=	$(PB_BINDIR)/pbtcpasynclient
TCPASYNSERVER	=	$(PB_BINDIR)/pbtcpasynserver

#tcp/ip
tcpip	:	$(TCPASYNCLIENT)	$(TCPASYNSERVER)


#all
all : $(TCPASYNCLIENT)	$(TCPASYNSERVER)


#tcp/ip
$(TCPASYNCLIENT)	:	$(TCPASYNCLIENTOBJS)
		@touch	pbtcpasynclient.c 
		@echo
		@echo 正在编译	$@
			-rm $(TCPASYNCLIENT)
		$(CC_BUILD)	$(TCPASYNCLIENTOBJS)	$(TCPASYNGWLIB)

$(TCPASYNSERVER)	:	$(TCPASYNSERVEROBJS)
		@touch	pbtcpasynserver.c 
		@echo
		@echo 正在编译	$@
			-rm $(TCPASYNSERVER)
		$(CC_BUILD)	$(TCPASYNSERVEROBJS)	$(TCPASYNGWLIB)


clean:
		@-rm -f *.c *.o *.lis 1>/dev/null 2>/dev/null
