pkgdata_DATA = ru/LC_MESSAGES/number.mo
ru/LC_MESSAGES/number.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	number.pot ../src/number.c
	xgettext -k_ -c ../src/number.c -o messages.new.pot
	cp number.pot messages.pot
	msgmerge -U messages.pot messages.new.pot
