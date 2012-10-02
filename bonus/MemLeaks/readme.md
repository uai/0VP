[MemLeaks example]
===================================

Ukazka detekovani memory leaku ve visual studiu VS 2012.
	
Info na msdn:
http://msdn.microsoft.com/en-us/library/e5ewb1h3%28v=vs.80%29.aspx

Postupujeme dle msdn a program spustime v debug modu (v release to nebude fungovat).
Po dokonceni programu se nam zobrazi v Output okne nasledujici:

Output:
Detected memory leaks!
Dumping objects ->
d:\coding\memleaks\memleaks\main.cpp(38) : {67} normal block at 0x00983930, 5 bytes long.
Data: <> 42 75 66 66 65 
d:\coding\memleaks\memleaks\main.cpp(35) : {66} normal block at 0x009838C8, 40 bytes long.
Data: <> 00 00 00 00 01 00 00 00 02 00 00 00 03 00 00 00 

Requirements
------------
Visual Studio 2012, main.c lze pouzit i v predchozich verzich VS.

Getting started
---------------
Otevreme ve VS a zkompilujeme v debug modu (kompilace a spusteni -> F5).


Note
---------------
This file is part of the 0VP course.
[0VP] (https://www.vutbr.cz/studium/ects-katalog/detail-predmetu?apid=126886&oid=8451).