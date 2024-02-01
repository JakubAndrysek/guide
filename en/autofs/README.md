# AutoFS Tutorial: Automounting a Samba Share

This tutorial will guide you through the process of setting up an automount for a Samba share using AutoFS on a Linux system. AutoFS is a service that automatically mounts and unmounts network shares based on access and inactivity, which is particularly useful for intermittently available network resources.

## Step 1: Install AutoFS

First, install AutoFS if it's not already installed on your system. On Debian-based systems like Ubuntu, use:

```bash
sudo apt-get update
sudo apt-get install autofs
```

## Step 2: Configure AutoFS

AutoFS uses a master configuration file (`/etc/auto.master`) and map files to control its behavior.

### Edit the Master Map File

Edit `/etc/auto.master`:

```bash
sudo nano /etc/auto.master
```

Add this line:

```
/mnt /etc/auto.samba --timeout=60 --ghost
```

This configuration tells AutoFS to use `/etc/auto.samba` for mounts under `/mnt`.

### Create the Samba Map File

Create a new file `/etc/auto.samba`:

```bash
sudo nano /etc/auto.samba
```

Add a line for your Samba share:

```
test-disk -fstype=cifs,rw,username=test,password=test,iocharset=utf8 ://192.168.0.42/test-disk
```

Replace `test-disk`, `test`, `test`, and the IP address with your specific Samba share details.

## Step 3: Restart AutoFS

Apply the configuration changes by restarting AutoFS:

```bash
sudo systemctl restart autofs
```

## Step 4: Access the Share

Your Samba share is now accessible at `/mnt/test-disk`. AutoFS will mount it when accessed and unmount it after 60 seconds of inactivity.

## Security Note: Using a Credentials File

Storing passwords in plaintext is not secure. Use a credentials file instead:

1. **Create a Credentials File:**

   ```bash
   sudo nano /etc/samba/credentials
   ```

2. **Add Your Credentials:**

   ```
   username=test
   password=test
   ```

3. **Secure the File:**

   ```bash
   sudo chmod 600 /etc/samba/credentials
   ```

4. **Update `/etc/auto.samba`:**

   ```
   test-disk -fstype=cifs,rw,credentials=/etc/samba/credentials,iocharset=utf8 ://192.168.0.40/test-disk
   ```

After these steps, your Samba share will be set up with AutoFS, providing a flexible and secure way to access network shares.


## Restart + info

```bash
sudo systemctl status autofs
sudo systemctl restart autofs
```


Sourced from:
- https://help.ubuntu.com/community/Autofs
- ChatGPT (everything works fine)