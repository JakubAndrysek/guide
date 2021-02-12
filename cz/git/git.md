# Verzovací systém Git

# [Git](https://git-scm.com)
Git je v informatice distribuovaný systém správy verzí - [Wikipedia](https://cs.wikipedia.org/wiki/Git)


# [Github](https://github.com)
GitHub je webová služba podporující vývoj softwaru za pomoci verzovacího nástroje Git - [Wikipedia](https://cs.wikipedia.org/wiki/GitHub)

## Vytvoření repozitáře (projektu) - Webové rozhraní

1. [Nový repozitář](https://github.com/new)
2. Repository name -> název repozitáře
3. Public nebo private
4. Doporučené
   1. README file -> popis projektu (úvodní Description)
   2. .gitignore -> neverzuje cachovací složky/soubory podle IDE (Visual Studio) nebo jazyka (C++)
   3. license -> výběr licence (moje oblíbená MIT License)

## Nastavení SSH klíče (Linux)
1. [Oficiální návod](https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh)
2. Generování klíče
   1. `$ ssh-keygen -t ed25519 -C "your_email@example.com"`
   2. `> Enter a file in which to save the key (/home/you/.ssh/id_ed25519):` -> ENTER
   3. `> Enter passphrase (empty for no passphrase):` -> ENTER
   4. `> Enter same passphrase again:` -> ENTER
   5. `$ eval "$(ssh-agent -s)"` -> `Agent pid 59566`
   6. `$ ssh-add ~/.ssh/id_ed25519`
3. Přídání klíče do Githubu
   1. `$ sudo apt-get install xclip`
   2. `$ $ xclip -selection clipboard < ~/.ssh/id_ed25519.pub` ->   veřejný klíč máme nakopírovaný ve schránce
   3. [Přídání](https://github.com/settings/keys) klíče na Githubu
   4. New SSH key
   5. Název počítače
   6. Key -> stačí zmáčknout `CTRL + V` pro vložení klíče ze schránky
4. Otestování připojení
   1. `$ ssh -T git@github.com`
   2. `> The authenticity of host 'github.com (IP ADDRESS)' can't be established.`
    
        `> RSA key fingerprint is SHA256:nThbg6kXUpJWGl7E1IGOCspRomTxdCARLviKw6E5SY8.`

        `> Are you sure you want to continue connecting (yes/no)?`
   3. Potvrdíme `yes`
   4. **Nastaveno**

# Nastavení Gitu

1. [Hezký popis příkazů](https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html)
2. `$ git config --global user.name "Sam Smith"` -> nastavení jména
2. `$ git config --global user.email sam@example.com` -> nastavení emailu

## Naklonování repozitáře

1. Stránka s repozitářem / projektem
2. Tpačítko `Code`
   1. HTTPS -> jakékoliv zařízení (vhodné pro Windows)
   2. SSH -> stažení na zařízeních s nastaveným SSH klíčem
3. Jedna z možností -> nakopírovat do schránky
4. `$ cd /zde/se/stahne/` -> složka kam se repozitář naklonuje
5. `$ git clone [obsah schránky]` příklad `git clone git@github.com:JakubAndrysek/guides.git`
6. **Naklonováno**

# Základní práce s Gitem
1. `$ git add <nazev souboru>` -> připraví vybraný soubor ka zaverzování
2. `$ git add *` -> připraví všechny soubory, ve kterých byla provedena změna, k zaverzování
3. `$ git commit` -> otevře okno pro napsání popisu změn (po uložení a zavření zaverzuje)
4. `$ git commit -m "Popis zmen"` -> Popis se dá přidat přímo v příkazu
5. `$ git push` -> odešle všechny změny na server
6. `$ git pull` -> stáhne všechny změny ze serveru
7. `$ git status` -> zobrazí seznam změn 



