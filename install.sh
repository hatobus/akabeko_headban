# /usr/bin/bash
if [ -e /etc/systemd/system/headbanging.service ]; then
    sudo rm -rf /etc/systemd/system/headbanging.service
fi

if [ -e /opt/akabeko/connect_Raspi/comp.py]; then
    sudo rm -rf /opt/akabeko/connect_Raspi/comp.py
fi

sudo mkdir -p /opt/akabeko
sudo cp ./* /opt/akabeko/
sudo cp ./headbanging.service / etc/systemd/system/headbanging.service

sudo chmod 0755 /opt/akabeko/connect_Raspi/comp.py
sudo systemctl enable headbanging.service

