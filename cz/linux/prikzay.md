# Základní příkazy v Linuxu

Převzato z [wiki.ubuntu.cz](https://wiki.ubuntu.cz/základní_příkazy)

## Práce se soubory a adresáři
- **`pwd`** -> vypíše pracovní adresář
- **`cd [adresar]`** -> změní adresář
- **`cp [puvodni] [novy]`** -> vytvoří kopii
- **`mv [puvodni] [novy]`** -> přesune nebo přejmenuje soubor/adresář
- **`rm [nazev]`** -> smaze
- **`rm -r [nazev]`** -> smaze rekurzivně (i podsložky)
- **`find`** -> 
- **`locate`** -> 
- **`which [soubor/program]`** -> vyhledá umístění programu 
- **`whereis [soubor/program]`** -> vyhledá umístění programu (více nálezů)
- **`cat [soubor]`** -> vypíše obsah souboru
- **`cat [soubor] | less`** -> vypíše po stránkách (zavření pomocí klávesy `q`)
- **`diff [souborA] [souborB]`** -> porovnání dvou souborů
- **`man [příkaz/program]`** -> zobrazí manuál
- **`mkdir [nazev]`** -> vytvoří adresář 
- **`rmdir [nazev]`** -> smaže adresář 

## Získávání systémových informací
- **`top`** -> výpis procesů, obsazení paměti
- **`htop`** -> vylepšený `top`, správce úloh
- **`ifconfig`** -> informuje o síťových rozhraních 
- **`lspci`** -> vypíše info o PCI zařízeních.
- **`lsusb`** -> vypíše info o USB zařízeních.
- **`hostname`** -> vypíše jméno počítače
- **`echo $PATH`** -> vypíše systémové proměnné
- **`alias [prezdivka]='[prikaz]'`** -> nastaví přezdívku pro složitý příkaz
