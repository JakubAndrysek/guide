# Verzovací systém Git

# [Git](https://git-scm.com)
Git je v informatice distribuovaný systém správy verzí - [Wikipedia](https://cs.wikipedia.org/wiki/Git)


# [Github](https://github.com)
GitHub je webová služba podporující vývoj softwaru za pomoci verzovacího nástroje Git - [Wikipedia](https://cs.wikipedia.org/wiki/GitHub)

## Kompletní průvodce Gitem a Githubem (CZ)
**[Git-scm.com](https://git-scm.com/book/cs/v2)**

## Vytvoření repozitáře (projektu) z webu

- Stránka na vytvoření [nového repozitáře](https://github.com/new)
- Repository name -> název repozitáře
- Výběr dostupnosti: public nebo private
- Doporučené
   - README file -> popis projektu (úvodní Description)
   - .gitignore -> určuje které adresáře nebo soubory se neverzují
   - license -> výběr licence (moje oblíbená MIT License) viz [opensource.org](https://opensource.org/licenses)

## Nastavení SSH klíče (Linux)
- [Oficiální návod](https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh)
- Generování klíče
   - `$ ssh-keygen -t ed25519 -C "your_email@example.com"`
   - `> Enter a file in which to save the key (/home/you/.ssh/id_ed25519):` -> ENTER (výchozí lokace)
   - `> Enter passphrase (empty for no passphrase):` -> ENTER (není třeba zadávat)
   - `> Enter same passphrase again:` -> ENTER
   - `$ eval "$(ssh-agent -s)"` -> `Agent pid 59566`
   - `$ ssh-add ~/.ssh/id_ed25519`
- Přidání klíče do Github účtu
   - `$ sudo apt-get install xclip`
   - `$ $ xclip -selection clipboard < ~/.ssh/id_ed25519.pub` ->   veřejný klíč máme nakopírovaný ve schránce
   - [Přídání](https://github.com/settings/keys) klíče na Githubu
   - New SSH key
   - Název počítače
   - Key -> stačí zmáčknout `CTRL + V` pro vložení klíče ze schránky
- Otestování připojení
   - `$ ssh -T git@github.com`
   - `> The authenticity of host 'github.com (IP ADDRESS)' can't be established.`
    
        `> RSA key fingerprint is SHA256:nThbg6kXUpJWGl7E1IGOCspRomTxdCARLviKw6E5SY8.`

        `> Are you sure you want to continue connecting (yes/no)?`
   - Potvrdíme `yes`
   - **Nastaveno**

# Nastavení Gitu

- [Hezký popis příkazů](https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html)
- `$ git config --global user.name "Sam Smith"` -> nastavení jména
- `$ git config --global user.email sam@example.com` -> nastavení emailu

## Naklonování repozitáře

- Stránka s repozitářem / projektem
- Tlačítko `Code`
   - HTTPS -> jakékoliv zařízení (vhodné pro Windows)
   - SSH -> stažení na zařízeních s nastaveným SSH klíčem
- Jedna z možností -> nakopírovat do schránky
- `$ cd /misto/na/disku/` -> složka kam se repozitář naklonuje
- `$ git clone [obsah schránky]` příklad `git clone git@github.com:JakubAndrysek/guides.git`
- **Naklonováno**

# Práce s Gitem

## Základní příkazy
- `$ git add <nazev souboru>` -> připraví vybraný soubor k zaverzování
- `$ git add *` -> připraví všechny soubory, ve kterých byla provedena změna, k zaverzování
- `$ git commit` -> otevře okno pro napsání popisu změn (po uložení a zavření zaverzuje)
- `$ git commit -m "Popis zmen"` -> popis se dá přidat přímo v příkazu
- `$ git push` -> odešle všechny změny na server
- `$ git pull` -> stáhne všechny změny ze serveru
- `$ git status` -> zobrazí seznam změn

## Příklad použití
- `$ git clone git@github.com:JakubAndrysek/guide.git` -> naklonuje repozitář **JakubAndrysek / guide**
- Úprava repozitáře, přidání souborů
- `$ git add *` -> připraví všechny změny k zaverzování
- `$ git status` -> volitelné - zobrazí seznam změn v projektu
- `$ git commit -m "Nova kapitola o Gitu"` -> Zaverzování souborů s popisem
- `$ git push` -> odešle všechny provedené změny na server



# Zdroje
- https://git-scm.com/
- https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh
- https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html



