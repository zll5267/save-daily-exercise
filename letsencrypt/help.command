apt install socat curl

curl https://get.acme.sh | sh
================
./acme.sh --issue --force -d xxx.com -d *.xxx.com --dns --yes-I-know-dns-manual-mode-enough-go-ahead-please
#add the 'txt record' from DNS provider
./acme.sh --renew -d xxx.com -d *.xxx.com --dns --yes-I-know-dns-manual-mode-enough-go-ahead-please
#./acme.sh --forced --renew -d xxx.com -d *.xxx.com --dns --yes-I-know-dns-manual-mode-enough-go-ahead-please
===================================
openssl x509 -in xxxxx.cer -text -out certificate.der
