

commandes utiles a run avant lancement du programme:

$ sudo apt-get update

$ sudo apt-get build-essential

$ sudo apt-get install python-tk -y

//installer pip2

https://linuxize.com/post/how-to-install-pip-on-ubuntu-20.04/

$ pip2 install matplotlib

NOTE: il est nécessaire que l'environnement dans lequel matplotlib est utilisé soit en python 2.7


//ancien

mkdir -p ~/miniconda3
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O ~/miniconda3/miniconda.sh
bash ~/miniconda3/miniconda.sh -b -u -p ~/miniconda3
rm -rf ~/miniconda3/miniconda.sh
~/miniconda3/bin/conda init bash
~/miniconda3/bin/conda init zsh
restart shell
$ conda install matplotlib
$ sudo apt-get install python3-pip python-dev -y
$ pip3 install matplolib
