# Server

## Setup server

### [Install Apache](https://www.raspberrypi.org/documentation/remote-access/web-server/apache.md)
1. `sudo apt update`
2. `sudo apt upgrade`
3. `sudo apt install apache2 -y`
4. get RPI IP adress `hostname -I`
5. test the web server `http://IP_ADRESS`
6. install PHP `sudo apt install php libapache2-mod-php -y`



### [Apache change root directory](https://askubuntu.com/questions/337874/change-apache-document-root-folder-to-secondary-hard-drive)
1. `cd /etc/apache2/sites-available`
2. `sudo nano 000-default.conf`
3. edit the `DocumentRoot /var/www/html` option -> `DocumentRoot /path/to/my_server`
4. `cd ..`
5. `sudo nano apache2.conf`
6. replace this
    ```
    <Directory />
        Options Indexes FollowSymLinks
        AllowOverride All
        Require all denied
    </Directory>
    ```
    by this
    ```
    <Directory />
        Options Indexes FollowSymLinks Includes ExecCGI
        AllowOverride All
        Require all granted
    </Directory>
    ```
7. restart apache `sudo service apache2 restart`
8. `cd /path/to/my_server`
9. add all permissions `sudo chmod -R 777 .`
10. Enable `.htaccess` files by `sudo a2enmod rewrite`

### [Install MySQL](https://pimylifeup.com/raspberry-pi-mysql/)
1. `sudo apt install mariadb-server`
2. for MySQL securing process `sudo mysql_secure_installation`
3. test it `sudo mysql -u root -p`

<!-- # https://charlieblog.eu/clanek-raspberry-pi-webserver-mysql -->

#### MySQL usage
1. log in `sudo mysql -u root -p`
2. create databse with name "mydb" `CREATE DATABASE mydb;`
3. add user - “exampleuser” `CREATE USER 'exampleuser'@'localhost' IDENTIFIED BY 'password';`
4. grant all permissions `GRANT ALL PRIVILEGES ON *.* TO 'exampleuser'@'localhost';`
5. Seve settings `FLUSH PRIVILEGES;`

### Instal [php MyAdmin](https://myhydropi.com/install-phpmyadmin-on-a-raspberry-pi)
1. `sudo apt install phpmyadmin`
2. in configuration choose `apache2`
3. than click `ok`
4. `sudo nano /etc/apache2/apache2.conf`
5. Scroll to the bottom of the file and add the following line `Include /etc/phpmyadmin/apache.conf`
6. Press Ctrl+X, Y and enter to save the changes
7. `sudo service apache2 restart`
8. login [http://<IP_ADRESS>/phpmyadmin](http://<IP_ADRESS>/phpmyadmin)

### Instal [Composer](https://getcomposer.org/)
1. `sudo apt-get install curl`
2. `sudo curl -s https://getcomposer.org/installer | php`
3. `sudo mv composer.phar /usr/local/bin/composer`
4. usage `composer`

##### Composer create Nette sandbox
1. `composer create-project nette/sandbox path/to/install`
2. `cd path/to/install`


### Install xdebug
1. `sudo apt install php-xdebug `
2. `sudo phpenmod xdebug`
3. Open `sudo nano /etc/php/7.4/mods-available/xdebug.ini`
4. Remove all and paste
    ```bash
    zend_extension="xdebug.so"
    xdebug.remote_enable = 1
    xdebug.remote_port = 9000
    xdebug.idekey = PHPSTORM
    xdebug.show_error_trace = 1
    xdebug.remote_autostart = 0

    ```
5. Press Ctrl+X, Y and enter to save the changes
6. Install browser [extension](https://www.jetbrains.com/help/phpstorm/browser-debugging-extensions.html)



### [Enable/disable Respberry PI GUI](https://www.digikey.com/en/maker/blogs/2018/how-to-boot-to-command-line-and-ssh-on-raspberry-pi)

### Remote connection VSCode - client
1. install VSCode extension [Remote - SSH](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh)
2. connect to server using SSH
3. chose folder to edit

### Custom index page
1. remove `index.html`
2. create `index.php`
3. insert into
   ```html
    <!doctype html>
    <html>
        <head>
        <meta http-equiv="content-type" content="text/html; charset=utf-8">
        <meta name="author" content="Kuba Andrysek">
        <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
        <link rel="icon" href="/favicon.ico" type="image/x-icon">
        <link rel="stylesheet" type="text/css" href="https://robotikabrno.cz/css/design2.css?v=files2019">
        <meta name="theme-color" content="#9cb036">
        <style>

            
            button{
            padding: 5px;
            margin: 3px 3px 3px 0px;
            }

            button.empty_dir{
            background-color: rgb(255,32,0);
            }

            #header{
                background-image: url('');
            }

            #logo_in_header div{
                background-image: url('https://avatars1.githubusercontent.com/u/33494544?s=500');
                
            }
        </style>
        </head>

        <body>
        <div id="main" class="home files">
        <!-- <div id="header" class="shadow"> -->
            <a href="/" id="logo_in_header">
            <div></div>
            </a>
        <!-- </div> -->
        <div id="main_menu">


        </div>

        <div id="content" class="without_menu shadow">
            <h1>Welcome to my PC - Kuba</h1>

            <?php
            $cache = explode('?', substr($_SERVER['REQUEST_URI'], 1));
            $cache = explode('#', $cache[0]);

            if(substr($cache[0], -1) == '/')
            $cache[0] = substr($cache[0], 0, -1);

            $cache[0] = rawurldecode($cache[0]);


            function size($path)
            {
            $size = filesize($path);
            if($size >= 1048576)
                return round(($size / 1048576), 1) . ' MB';
            else
                return round(($size / 1024), 1) . ' kB';
            }

            $id = 0;

            $levels = explode('/', $cache[0]);
            echo '<h2>Cesta: <a href="/">home</a>';
            $addr = '';
            foreach($levels as $level)
            {
            $addr .= '/' . $level;
            echo '/<a href="' . $addr . '">' . $level . '</a>';
            }
            echo '</h2>';

            $href_folder = '/' . $cache[0];
            if($cache[0] == '')
            unset($href_folder);
            scan('./' . $cache[0], $href_folder);
            function scan($folder = './', $href_folder = '')
            {
            echo '<ul id="' . $GLOBALS['id'] . '" style="display: none;">';
            $len = strlen($href_folder) + 2;
            foreach(glob('.' . $href_folder . "/*", GLOB_ONLYDIR) as $folder_2)
            {
                $foldername = substr($folder_2, $len);
                $counter = scandir($folder_2);
                if(count($counter) <= 2)
                $class = ' class="empty_dir"';
                else
                $class = '';
                echo '<li><a href="' . $href_folder . '/' . rawurlencode($foldername) . '"><button' . $class . '>' . $foldername . '</button></a></li>';
            }
            foreach(glob('.' . $href_folder . "/*.*") as $file)
            {
                $filename = substr($file, $len);
                echo '<li><a target="_blank" href="' . $href_folder . '/' . rawurlencode($filename) . '">' . $filename . ' (' . size($file) . ')</a></li>';
            }
            echo '</ul>';
            }


            ?>

            <script>
                document.getElementById('0').style.display = 'block';
            </script>
        </div>

        <a href="#header" id="up" class="shadow">nahoru</a>
        <p>Page copied and edited by <a href="https://robotikabrno.cz" target="_blank">Robotikabrno.cz</p>



        
        </div>
        </div>
        </body>
    </html>
    ```

