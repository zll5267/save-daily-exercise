1. generate the private key.
    openssl genrsa -des3 -out server.key 1024
    the server.key is encrypted.
    remove the password:
    openssl rsa -in server.key -out server-nopasswd.key
2. generate the CSR
    openssl req -new -key server.key -out server.csr -config openssl.cnf #/etc/ssl/openssl.cnf

3. let's be CA
    openssl req -new -x509 -keyout ca.key -out ca.crt -config /openssl.cnf

    update the openssl.cnf, dir = current work directory
    manually create the directory tree of CA:
    mkdir demoCA
    mkdir demoCA/newcerts
    touch demoCA/index.txt
    echo "01" > demoCA/serial

4. sign the server.csr used the CA certificate from step 3
    openssl ca -in server.csr -out server.crt -cert ca.crt -keyfile ca.key -config openssl.cnf

