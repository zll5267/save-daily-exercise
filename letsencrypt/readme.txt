dev env:
cd letsencrypt
./bootstap/install-deps.sh
./bootstap/dev/venv.sh
source ./venv/bin/activate

deactivate
================
install virtualenv:
sudo pip install virtualenv
https://virtualenv.pypa.io/en/latest/userguide.html

prepare the ENV:
(pip, setuptools should be installed before)
virtual [--system-site-packages] ENV # ENV is a directoy to place the new virtual envionment.(ENV/lib[bin|include])
source	$ENV/bin/activate
deactivate


develop guide:
https://letsencrypt.readthedocs.org/en/latest/index.html

issues:
can not access https://golang.org
