# GRUB

## Oprava GRUBu
- **`$ sudo grub-install /dev/[disk-partition] --target=x86_64-efi --efi-directory=/boot/efi/`**
- **`$ sudo update-grub`**
- **`$ sudo reboot now`**

## Oprava GRUBu - moje řešení
- **`$ sudo grub-install /dev/nvme0p1 --target=x86_64-efi --efi-directory=/boot/efi/`**
- **`$ sudo update-grub`**
- **`$ sudo reboot now`**

