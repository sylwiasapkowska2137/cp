#
# OI Makefile
# Autor: Tomasz Walen, Rafal Rusin, Adam Iwanicki
# Historia:
#  	1.06 : 2007.09.08 : AI - dodanie wsparcia dla Javy, raportu w formacie tabelki
#  	1.07 : 2007.09.08 : AI - wypluwanie bledu w przypadku braku ustawionych limitow
#  	1.08 : 2007.09.09 : AI - uzupelnienie raportu o jezyki w jakim sa zrodla
#   1.09 : 2007.09.09 : AI - dodanie sprawdzania nazw programow
#   1.10 : 2007.09.09 : AI - na zyczenie Jakuba Radoszewskiego weryfikator nie jest uruchamiany jesli program zakonczy sie beledem

VERSION = 1.10

include makefile.in

BIN_TIME = /usr/bin/time
TMP1     = .__tmp_1__~
TMP2     = .__tmp_2__~
TMP3     = .__tmp_3__~


INGEN    = $(shell if [ `find prog -name "$(ID)ingen.*" | wc -l` -gt 0 ] ; then echo 1 ; else echo 0 ; fi)
INWER    = $(shell if [ `find prog -name "$(ID)inwer.*" | wc -l` -gt 0 ] ; then echo 1 ; else echo 0 ; fi)
CHECKER  = $(shell if [ `find prog -name "$(ID)chk.*" | wc -l` -gt 0 ] ; then echo 1 ; else echo 0 ; fi)
PROGS_OPT= $(shell find prog -regex "prog/$(ID)[0-9]*\.\(c\|cpp\|pas\|ml\)" | sort -n -k 1.`echo "prog/$(ID)"| wc -c`)
PROGS_SLW= $(shell find prog -regex "prog/$(ID)s[0-9]*\.\(c\|cpp\|pas\|ml\)" | sort -n -k 1.`echo "prog/$(ID)s"| wc -c`)
PROGS_BAD= $(shell find prog -regex "prog/$(ID)b[0-9]*\.\(c\|cpp\|pas\|ml\)" | sort -n -k 1.`echo "prog/$(ID)b"| wc -c`)
PROGS_JAVA= $(shell find prog -regex "prog/$(ID)[0-9]*\.\(java\)" | sort -n -k 1.`echo "prog/$(ID)"| wc -c`)
TESTS   += $(shell find in -regex "in/$(ID)[0-9]*[a-z]?ocen.in" | sort -n -k 1.`echo "in/$(ID)"| wc -c` )
TESTS   += $(shell find in -regex "in/$(ID)[0-9]*[a-z]?.in" | sort -n -k 1.`echo "in/$(ID)"| wc -c` )

B_PROGS_WER= $(shell find prog -regex "prog/$(ID)[0-9]*wer[0-9]*\.\(c\|cpp\|pas\|ml\)" | sort -n -k 1.`echo "prog/$(ID)"| wc -c`)
B_PROGS_SLW= $(shell find prog -regex "prog/$(ID)[0-9]*s\.\(c\|cpp\|pas\|ml\)" | sort -n -k 1.`echo "prog/$(ID)"| wc -c`)
B_PROGS_BAD= $(shell find prog -regex "prog/$(ID)[0-9]*b\.\(c\|cpp\|pas\|ml\)" | sort -n -k 1.`echo "prog/$(ID)"| wc -c`)
.PHONY : clean clean-gen export verify tgz run inwer outgen verify_limits verify_names info

all:
	# Podaj konkretny cel #

export:
	## Przygotowanie paczki dla SInOl'a ##
	make -C doc
	make -C prog
	make clean-gen
	make clean
	tar cvzf $(SIG).tgz --exclude "$(ID)/$(SIG).tgz" ../$(ID)

run:
	## Uruchomienie rozwi±zania wzorcowego ##
	make _run_ver_n_$(ID).e

run_%:  
	make _run_ver_n_$(ID)$*.e

jrun_%:
	make _jrun_ver_n_$(ID)$*.e

verify: clean verify_$(MODE)

verify_red:
	## Automatyczna weryfikacja redacji ##
	make -s "_verify_doc_$(ID)zad.tex"
	make -s "_verify_in_$(ID)0.in"
	make -s "_verify_out_$(ID)0.out"
	make -C doc all

info:
	## Wersja makefile'a $(VERSION) ##
	## Informacje o procesorze ##
	@cat /proc/cpuinfo

verify_limits:
	## Automatyczna weryfikacja limitow ##
	##
	## TIMELIMIT:      $(TIMELIMIT)
	## SLOW_TIMELIMIT: $(SLOW_TIMELIMIT)
	## MEMLIMIT:       $(MEMLIMIT)
	##
	$(if $(TIMELIMIT),,$(error Brak ustawionego TIMELIMITu.))
	$(if $(SLOW_TIMELIMIT),,$(error Brak ustawionego SLOW_TIMELIMITu.))
	$(if $(MEMLIMIT),,$(error Brak ustawionego MEMLIMITu.))
	$(if $(shell if [ $(TIMELIMIT) -le 60 ]; then echo OK; fi),,$(error Za duzy TIMELIMIT: $(TIMELIMIT)))
	$(if $(shell if [ $(SLOW_TIMELIMIT) -le 120 ]; then echo OK; fi),,$(error Za duzy SLOW_TIMELIMIT: $(SLOW_TIMELIMIT)))
	$(if $(shell if [ $(MEMLIMIT) -le 512000 ]; then echo OK; fi),,$(error Za duzy MEMLIMIT: $(MEMLIMIT)))


verify_names:
	## Automatyczna weryfikacja nazw programow ##
	$(if $(B_PROGS_BAD), $(error Niewlasciwe nazwy programow blednych ($(B_PROGS_BAD)). Nazwy powinny sie zaczynac od $(ID)b),)
	$(if $(B_PROGS_SLW), $(error Niewlasciwe nazwy programow wolnych ($(B_PROGS_SLW)). Nazwy powinny sie zaczynac od $(ID)s),)
	$(if $(B_PROGS_WER), $(error Niewlasciwe nazwy programow weryfikujacych ($(B_PROGS_WER)). Prosze nadac im nazwy zgodnie z typem $(ID), $(ID)s lub $(ID)b),)


report:
	@printf "<html> \n\
		<head> \n\
		<title>$(ID) - Raport</title> \n\
		<style> \n\
		.OK { background-color: lightgreen } \n\
		.WRONG_ANSWER {background-color: red } \n\
		.TIMEOUT {background-color: yellow } \n\
		.RTE { background-color: blue } \n\
		.c {background-color: lightgreen} \n\
		.cpp {background-color: lightgreen} \n\
		.java {background-color: yellow} \n\
		.pas {background-color: lightblue} \n\
		TD {text-align: center} \n\
		</style> \n\
		<pre>\n" 
	@make -s -C prog >/dev/null 2>/dev/null
	@make -s ingen >/dev/null 2>/dev/null
	@make -s inwer >/dev/null 2>/dev/null
	@make -s outgen >/dev/null 2>/dev/null
	@echo "</pre>"
	@printf "<h1>Raport</h1> \n\
		<h3>Legenda</h3> \n\
		<ul><li>* - przy nazwie testu oznacza test typu ocen</li> \n\
		<li> kolor zielony oznacza poprawne zakonczenie programu</li> \n\
		<li> kolor zolty oznacza przekroczenie limitu czasu</li> \n\
		<li> kolor czerwony oznacza nieprawidlowa odpowiedz</li> \n\
		<li> kolor niebieski oznacza blad wykonania</ul>"
	@echo "<table><tr><th>lang</th><th>progname</th>"
	@for i in $(TESTS); do echo "<th>`echo -n $$i | sed -e 's/ocen/*/' -e 's/in\/$(ID)//' -e 's/.in//'`</th>"; done
	@echo "</tr>"
	@for i in $(PROGS_OPT); do j=`basename $$i`; if ! make -s _run_rep_o_$$j; then exit 1; fi; done
	@for i in $(PROGS_JAVA); do j=`basename $$i`; if ! make -s _jrun_rep_o_$$j; then exit 1; fi; done
	@for i in $(PROGS_SLW); do j=`basename $$i`; if ! make -s _run_rep_s_$$j; then exit 1; fi; done
	@for i in $(PROGS_BAD); do j=`basename $$i`; if ! make -s _run_rep_o_$$j; then exit 1; fi; done
	@for i in $(PROGS_WER); do j=`basename $$i`; if ! make -s _run_rep_o_$$j; then exit 1; fi; done
	@printf "</table>\n</body>\n</html>\n"

verify_opr: info verify_red verify_limits verify_names
	## Automatyczna weryfikacja opracowania ##
	make -s "_verify_doc_$(ID)opr.tex"
	make -C doc all
	make -C prog all
	make ingen
	make inwer
	make outgen
	@for i in `echo $(PROGS_OPT)`; do j="`basename $$i`"; j="`(echo $$j) | rev | cut -d. -f2- | rev`.e"; if ! make _run_ver_o_$$j; then exit 1; fi; done
	@for i in `echo $(PROGS_SLW)`; do j="`basename $$i`"; j="`(echo $$j) | rev | cut -d. -f2- | rev`.e"; if ! make _run_ver_s_$$j; then exit 1; fi; done
	make report

verify_wer: verify_opr
	## Automatyczna weryfikacja weryfikacji ##
	make -s "_verify_doc_$(ID)wer.tex"

_verify_in_%:
	@if [ ! -f "in/$*" ] ; then echo Brak pliku in/$* ; exit 1 ; fi

_verify_out_%:
	@if [ ! -f "out/$*" ] ; then echo Brak pliku out/$* ; exit 1 ; fi

_verify_prog_%:
	@if [ ! -f "prog/$*" ] ; then echo Brak pliku prog/$* ; exit 1 ; fi

_verify_doc_%:
	@if [ ! -f "doc/$*" ] ; then echo Brak pliku doc/$* ; exit 1 ; fi

clean:
	rm -f *~
	make -C doc clean
	make -C prog clean

######################################################################
# Usuniêcie testów genereowanych automatycznie
######################################################################
clean-gen:
	@if [ "$(INGEN)" -eq 1 ] ; then \
		if [ -e in/tmp ]; then rm -r in/tmp; fi ; \
		mkdir in/tmp ; \
		if [ -f prog/$(ID)ingen.sh ] ; then \
			cd in/tmp ; ../../prog/$(ID)ingen.sh ; \
		else \
			make -C prog $(ID)ingen.e ; \
			cd in/tmp ; ../../prog/$(ID)ingen.e ; \
		fi ; \
		INGEN_FILES="`echo *.in`"; \
		cd ../.. ; \
		rm -r in/tmp ; \
		for i in $$INGEN_FILES; do \
			j=`basename $$i .in`; \
			echo Kasuje in/$$j.in; rm -f in/$$j.in; \
			echo Kasuje out/$$j.out; rm -f out/$$j.out; \
		done ;\
	fi

mrproper:
	make -C doc mrproper
	make -C prog mrproper
	@if [ "$(INGEN)" -eq 1 ] ; then \
	    make clean-gen ; \
	fi
	@echo Usuwanie plikow OUT 
	rm -f out/*

############################################################################
# Przygotowanie danych wej¶ciowych generowanych automatycznie
############################################################################
ingen:
	@if [ "$(INGEN)" -eq 1 ] ; then \
		if [ -f prog/$(ID)ingen.sh ] ; then \
			cd in ; ../prog/$(ID)ingen.sh ; \
		else \
			make -C prog $(ID)ingen.e ; \
			cd in ; ../prog/$(ID)ingen.e ; \
		fi ; \
	fi

############################################################################
# Weryfikacja poprawno¶ci danych wej¶ciowych 
############################################################################
inwer:
	@if [ "$(INWER)" -eq 1 ] ; then \
		make -C prog $(ID)inwer.e ; \
		for i in $(TESTS) ; do \
			printf "%-11s ... " `basename $$i` ; \
			if ! prog/$(ID)inwer.e < $$i ;  then \
				echo "ZLE!!!" ; \
				exit 1 ; \
			fi ; \
		done ; \
	else \
		echo "Brak weryfikatora do testów" ; \
		exit 2 ; \
	fi 


############################################################################
# Wygenerowanie wzorcowych odpowiedzi dla bie¿±cego zestawu testów 
############################################################################
outgen:
	make -C prog $(ID).e
	@for i in $(TESTS) ; do \
	    printf "%-11s ... " `basename $$i` ; \
	    prog/$(ID).e < $$i > out/`basename $$i .in`.out ; \
	    echo OK ; \
	done 


############################################################################
# Uruchomienie programu prog/$(ID)%.e na bie¿±cym zestawie testów 
# Ustawienie zmiennej ACC_TERM na 1 powoduje, ze wywlaszczane testy
# sa uwazane za OK.
# Ustawienie STOP_ON_WRONG na 1 powoduje przerwanie po napotkaniu
# testu, ktorego program nie przechodzi
############################################################################
_run_ver_n_%:
	make -s -C prog $*
	@if [ "$(CHECKER)" -eq "1" ] ; then make -C prog $(ID)chk.e ; fi
	@ACC_TERM=0;\
	STOP_ON_WRONG=0;\
	T_LIMIT=$(TIMELIMIT);\
	for i in $(TESTS) ; do \
		j=out/`basename $$i .in`.out ; \
		\
		printf "%-11s " `basename $$i` ; \
		\
		rm -f $(TMP3);\
		rm -f $(TMP1);\
		(ulimit -v $(MEMLIMIT); ulimit -t $$T_LIMIT ; if $(BIN_TIME) -f "%U" -o $(TMP2) prog/$* < $$i > $(TMP1); then echo "OK" >$(TMP3); else echo "STOPPED" >$(TMP3); fi ); \
		if [ "`cat $(TMP3)`" = OK ]; then TERM=0; else TERM=1; fi;\
		rm -f $(TMP3);\
		TIME=`cat $(TMP2)` ; echo -n "$$TIME " ; \
		\
		if [ $$TERM -eq 0 ]; then \
			if [ "$(CHECKER)" -eq "1" ] ; then \
				prog/$(ID)chk.e $$i $(TMP1) $$j > $(TMP2) ; \
				RES=`head -n 1 $(TMP2)` ; \
				COMMENT=`head -n 2 $(TMP2) | tail -n 1` ; \
				if [ "$$RES" != "OK" ] ; then RES="WRONG_ANSWER" ; fi ; \
			else \
				if diff -q $$j $(TMP1) > /dev/null ; then \
					RES="OK" ; \
				else \
					RES="WRONG_ANSWER" ; \
				fi ; \
				COMMENT="" ; \
			fi ; \
		fi; \
		if [ $$TERM -eq 1 ]; then RES="WRONG (TIMEOUT)"; fi; \
		if [ $$TERM -eq 1 ] && [ "$$ACC_TERM" = 1 ]; then RES="OK"; fi; \
		echo $$RES $$COMMENT ; \
		rm -f $(TMP1) $(TMP2) ; \
		if [ "$$RES" != "OK" ] && [ "$$STOP_ON_WRONG" = 1 ]; then exit 1; fi;\
	done

_jrun_ver_n_%:
	make -s -C prog $*
	@if [ "$(CHECKER)" -eq "1" ] ; then make -C prog $(ID)chk.e ; fi
	@ACC_TERM=0;\
	STOP_ON_WRONG=0;\
	T_LIMIT=$(TIMELIMIT);\
	for i in $(TESTS) ; do \
		j=out/`basename $$i .in`.out ; \
		\
		printf "%-11s " `basename $$i` ; \
		\
		rm -f $(TMP3);\
		rm -f $(TMP1);\
		(if $(BIN_TIME) -f "%U" -o $(TMP2) prog/$* < $$i > $(TMP1); then echo "OK" >$(TMP3); else echo "STOPPED" >$(TMP3); fi ); \
		if [ "`cat $(TMP3)`" = OK ]; then TERM=0; else TERM=1; fi;\
		rm -f $(TMP3);\
		TIME=`cat $(TMP2)` ; echo -n "$$TIME " ; \
		\
		if [ $$TERM -eq 0 ]; then \
			if [ "$(CHECKER)" -eq "1" ] ; then \
				prog/$(ID)chk.e $$i $(TMP1) $$j > $(TMP2) ; \
				RES=`head -n 1 $(TMP2)` ; \
				COMMENT=`head -n 2 $(TMP2) | tail -n 1` ; \
				if [ "$$RES" != "OK" ] ; then RES="WRONG_ANSWER" ; fi ; \
			else \
				if diff -q $$j $(TMP1) > /dev/null ; then \
					RES="OK" ; \
				else \
					RES="WRONG_ANSWER" ; \
				fi ; \
				COMMENT="" ; \
			fi ; \
		fi; \
		if [ $$TERM -eq 1 ]; then RES="WRONG (TIMEOUT)"; fi; \
		if [ $$TERM -eq 1 ] && [ "$$ACC_TERM" = 1 ]; then RES="OK"; fi; \
		echo $$RES $$COMMENT ; \
		rm -f $(TMP1) $(TMP2) ; \
		if [ "$$RES" != "OK" ] && [ "$$STOP_ON_WRONG" = 1 ]; then exit 1; fi;\
	done

_run_ver_o_%:
	make -s -C prog $*
	@if [ "$(CHECKER)" -eq "1" ] ; then make -C prog $(ID)chk.e ; fi
	@ACC_TERM=0;\
	STOP_ON_WRONG=1;\
	T_LIMIT=$(TIMELIMIT);\
	for i in $(TESTS) ; do \
		j=out/`basename $$i .in`.out ; \
		\
		printf "%-11s " `basename $$i` ; \
		\
		rm -f $(TMP3);\
		rm -f $(TMP1);\
		(ulimit -v $(MEMLIMIT); ulimit -t $$T_LIMIT ; if $(BIN_TIME) -f "%U" -o $(TMP2) prog/$* < $$i > $(TMP1); then echo "OK" >$(TMP3); else echo "STOPPED" >$(TMP3); fi ); \
		if [ "`cat $(TMP3)`" = OK ]; then TERM=0; else TERM=1; fi;\
		rm -f $(TMP3);\
		TIME=`cat $(TMP2)` ; echo -n "$$TIME " ; \
		\
		if [ $$TERM -eq 0 ]; then \
			if [ "$(CHECKER)" -eq "1" ] ; then \
				prog/$(ID)chk.e $$i $(TMP1) $$j > $(TMP2) ; \
				RES=`head -n 1 $(TMP2)` ; \
				COMMENT=`head -n 2 $(TMP2) | tail -n 1` ; \
				if [ "$$RES" != "OK" ] ; then RES="WRONG_ANSWER" ; fi ; \
			else \
				if diff -q $$j $(TMP1) > /dev/null ; then \
					RES="OK" ; \
				else \
					RES="WRONG_ANSWER" ; \
				fi ; \
				COMMENT="" ; \
			fi ; \
		fi; \
		if [ $$TERM -eq 1 ]; then RES="WRONG (TIMEOUT)"; fi; \
		if [ $$TERM -eq 1 ] && [ "$$ACC_TERM" = 1 ]; then RES="OK"; fi; \
		echo $$RES $$COMMENT ; \
		rm -f $(TMP1) $(TMP2) ; \
		if [ "$$RES" != "OK" ] && [ "$$STOP_ON_WRONG" = 1 ]; then exit 1; fi;\
	done

_run_ver_s_%:
	make -s -C prog $*
	@if [ "$(CHECKER)" -eq "1" ] ; then make -C prog $(ID)chk.e ; fi
	@ACC_TERM=1;\
	STOP_ON_WRONG=1;\
	T_LIMIT=$(SLOW_TIMELIMIT);\
	for i in $(TESTS) ; do \
		j=out/`basename $$i .in`.out ; \
		\
		printf "%-11s " `basename $$i` ; \
		\
		rm -f $(TMP3);\
		rm -f $(TMP1);\
		(ulimit -v $(MEMLIMIT); ulimit -t $$T_LIMIT ; if $(BIN_TIME) -f "%U" -o $(TMP2) prog/$* < $$i > $(TMP1); then echo "OK" >$(TMP3); else echo "STOPPED" >$(TMP3); fi ); \
		if [ "`cat $(TMP3)`" = OK ]; then TERM=0; else TERM=1; fi;\
		rm -f $(TMP3);\
		TIME=`cat $(TMP2)` ; echo -n "$$TIME " ; \
		\
		if [ $$TERM -eq 0 ]; then \
			if [ "$(CHECKER)" -eq "1" ] ; then \
				prog/$(ID)chk.e $$i $(TMP1) $$j > $(TMP2) ; \
				RES=`head -n 1 $(TMP2)` ; \
				COMMENT=`head -n 2 $(TMP2) | tail -n 1` ; \
				if [ "$$RES" != "OK" ] ; then RES="WRONG_ANSWER" ; fi ; \
			else \
				if diff -q $$j $(TMP1) > /dev/null ; then \
					RES="OK" ; \
				else \
					RES="WRONG_ANSWER" ; \
				fi ; \
				COMMENT="" ; \
			fi ; \
		fi; \
		if [ $$TERM -eq 1 ]; then RES="WRONG (TIMEOUT)"; fi; \
		if [ $$TERM -eq 1 ] && [ "$$ACC_TERM" = 1 ]; then RES="OK"; fi; \
		echo $$RES $$COMMENT ; \
		rm -f $(TMP1) $(TMP2) ; \
		if [ "$$RES" != "OK" ] && [ "$$STOP_ON_WRONG" = 1 ]; then exit 1; fi;\
	done

define get_rep_result
  RES=`cat $(TMP3)`; \
	rm -f $(TMP3);\
	TIME=`cat $(TMP2)`; \
	\
	if [ "$$RES" == "0" ]; then \
		if [ "$(CHECKER)" -eq "1" ] ; then \
			prog/$(ID)chk.e $$i $(TMP1) $$j > $(TMP2) ; \
			RES=`head -n 1 $(TMP2)` ; \
			if [ "$$RES" != "OK" ] ; then RES="WRONG_ANSWER" ; fi ; \
		else \
			if diff -q $$j $(TMP1) > /dev/null ; then \
				RES="OK" ; \
			else \
				RES="WRONG_ANSWER" ; \
			fi ; \
		fi ; \
	elif [ "$$RES" == "9" ]; then \
		RES="TIMEOUT"; \
		TIME=$$T_LIMIT; \
	else \
	  RES="RTE"; \
		TIME=`tail -n 1 $(TMP2)`; \
	fi; \
	rm -f $(TMP1) $(TMP2) ; \
	\
	printf "<td class=\"%s\">%ss</td>\n" "$$RES" "$$TIME"
endef


_jrun_rep_o_%:
	PROG="`basename $* | rev | cut -d. -f2- | rev`.e"; \
		LANG="`basename $* | rev | cut -d. -f1 | rev`"; \
		T_LIMIT=$(TIMELIMIT);\
		echo "<tr><td class=\"$$LANG\">$$LANG</td><td>$$PROG</td>" ; \
		for i in $(TESTS) ; do \
			j=out/`basename $$i .in`.out ; \
			\
			rm -f $(TMP3) $(TMP1);\
			($(BIN_TIME) -f "%U" -o $(TMP2) prog/$$PROG < $$i > $(TMP1) 2>/dev/null; echo -n "$$?" >$(TMP3) ); \
			$(get_rep_result); \
		done

_run_rep_o_%:
	PROG="`basename $* | rev | cut -d. -f2- | rev`.e"; \
		LANG="`basename $* | rev | cut -d. -f1 | rev`"; \
		T_LIMIT=$(TIMELIMIT);\
		echo "<tr><td class=\"$$LANG\">$$LANG</td><td>$$PROG</td>" ; \
		for i in $(TESTS) ; do \
			j=out/`basename $$i .in`.out ; \
			\
			rm -f $(TMP3) $(TMP1) ;\
			(ulimit -v $(MEMLIMIT); ulimit -t $$T_LIMIT ; $(BIN_TIME) -f "%U" -o $(TMP2) prog/$$PROG < $$i > $(TMP1) 2>/dev/null; echo -n "$$?" >$(TMP3)  ); \
			$(get_rep_result); \
		done

_run_rep_s_%:
	PROG="`basename $* | rev | cut -d. -f2- | rev`.e"; \
		LANG="`basename $* | rev | cut -d. -f1 | rev`"; \
		T_LIMIT=$(SLOW_TIMELIMIT);\
		echo "<tr><td class=\"$$LANG\">$$LANG</td><td>$$PROG</td>" ; \
		for i in $(TESTS) ; do \
			j=out/`basename $$i .in`.out ; \
			\
			rm -f $(TMP3) $(TMP1);\
			(ulimit -v $(MEMLIMIT); ulimit -t $$T_LIMIT ; $(BIN_TIME) -f "%U" -o $(TMP2) prog/$$PROG < $$i > $(TMP1) 2>/dev/null; echo -n "$$?" >$(TMP3) ); \
			$(get_rep_result); \
		done
